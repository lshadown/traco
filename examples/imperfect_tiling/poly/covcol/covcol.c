#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

#define my_sqrt_array(x,j) sqrt(x[j])

#ifndef TIME
#define TIME
#endif

#define N 1000
#define M 1000

double float_n = (float) N;
double eps = 0.005;
double stddev[M + 1];
double data[M + 1][N + 1];
double mean[M + 1];
double symmat[M + 1][M + 1];

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

void init_array()
{
    int i, j;
    int n = N;
    int m = M;

    for (i=0; i<=n; i++) {
      for (j=0; j<=m; j++) {
        data[i][j] = ((float) i*j)/N;
      }
    }
}

void print_array()
{
  int i, j;
  int n = N;
  int m = M;
  for (i=1; i<=m; i++) {
    for (j=1; j<=m; j++) {
      fprintf(stderr, "%0.2lf ", symmat[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
}

double rtclock()
{
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday (&Tp, &Tzp);
  if (stat != 0) printf("Error return from gettimeofday: %d",stat);
  return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

int main(int argc, char** argv)
{
  double t_start, t_end;
  int i, j, j1, j2;

  init_array();

  IF_TIME(t_start = rtclock());

  /* Determine mean of column vectors of input data matrix */
  for (j = 1; j <= M; j++) {
    mean[j] = 0.0;
    for (i = 1; i <= N; i++)
      mean[j] += data[i][j];
    mean[j] /= float_n;
  }

  /* Center the column vectors. */
  for (i = 1; i <= N; i++)
    for (j = 1; j <= M; j++)
      data[i][j] -= mean[j];

  for (j1 = 1; j1 <= M; j1++) {
    for (j2 = j1; j2 <= M; j2++) {
      symmat[j1][j2] = 0.0;
    }
  }

#pragma scop
  /* Calculate the m * m covariance matrix. */
  for (j1 = 1; j1 <= M; j1++) {
    for (j2 = j1; j2 <= M; j2++) {
      for (i = 1; i <= N; i++) {
        symmat[j1][j2] += data[i][j1] * data[i][j2];
      }
      symmat[j2][j1] = symmat[j1][j2];
    }
  }
#pragma endscop

  IF_TIME(t_end = rtclock());
  IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

  if (fopen(".test", "r"))  {
#ifdef MPI
      if (my_rank == 0) {
          print_array();
      }
#else
      print_array();
#endif
  }

  return 0;
}

if (N >= 1)
#pragma omp parallel for
  for (c0 = 0; c0 <= floord(M - 1, 16); c0 += 1)
    for (c1 = 0; c1 <= -c0 + (M - 1) / 16; c1 += 1)
      if (c1 >= 0 && c0 >= 0)
        for (c2 = 0; c2 <= floord(N - 1, 16); c2 += 1)
          for (c3 = 16 * c0 + 1; c3 <= min(16 * c0 + 16, M - 16 * c1); c3 += 1)
            for (c4 = 16 * c1 + c3; c4 <= min(M, 16 * c1 + c3 + 15); c4 += 1) {
              if (16 * c2 + 16 >= N)
                symmat[c4][c3]=symmat[c3][c4];
              if (c2 == 0)
                symmat[c3][c4]+=data[1][c3]*data[1][c4];
              for (c5 = max(16 * c2 + 1, 2); c5 <= min(16 * c2 + 16, N); c5 += 1)
                symmat[c3][c4]+=data[c5][c3]*data[c5][c4];
            }

