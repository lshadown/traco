#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#ifndef TIME
#define TIME
#endif

#define my_sqrt_array(x,j) sqrt(x[j])

#define N 500
#define M 500

float float_n = (float) N;
float eps = 0.005;

#pragma declarations
float stddev[M + 1];
float data[M + 1][N + 1];
float mean[M + 1];
float symmat[M + 1][M + 1];
#pragma enddeclarations


#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

void init_array()
{
  int i, j;

  for (i=0; i<M; i++) {
    for (j=0; j<N; j++) {
      data[i][j] = ((float) i*j+1)/N;
    }
  }
}


void print_array()
{
  int i, j;
  for (i=0; i<M; i++) {
    for (j=0; j<M; j++) {
      fprintf(stderr, "%lf ", symmat[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
}

/**  Error handler  **************************************************/

void erhand(err_msg)
  char err_msg[];
  /* Error handler */
{
  fprintf(stderr,"Run-time error:\n");
  fprintf(stderr,"%s\n", err_msg);
  fprintf(stderr,"Exiting to system.\n");
  exit(1);
}


float *vector(n)
  int n;
  /* Allocates a float vector with range [1..n]. */
{

  float *v;

  v = (float *) malloc ((unsigned) n*sizeof(float));
  if (!v) erhand("Allocation failure in vector().");
  return v-1;

}

#ifdef TIME
double rtclock()
{
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday (&Tp, &Tzp);
  if (stat != 0) printf("Error return from gettimeofday: %d",stat);
  return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}
#endif

int main(int argc, char** argv)
{
  double t_start, t_end;
  int i, j, j1, j2;
  // float *mean, *stddev;

  init_array();

  IF_TIME(t_start = rtclock());

  /* Allocate storage for mean and std. dev. vectors */
  // mean = vector(m);
  // stddev = vector(m);

  /* Determine mean of column vectors of input data matrix */
  for (j = 1; j <= M; j++)
  {
    mean[j] = 0.0;
    for (i = 1; i <= N; i++)
      mean[j] += data[i][j];
    mean[j] /= float_n;
  }

  /* Determine standard deviations of column vectors of data matrix. */
  for (j = 1; j <= M; j++)
  {
    stddev[j] = 0.0;
    for (i = 1; i <= N; i++)
      stddev[j] += (data[i][j] - mean[j]) * (data[i][j] - mean[j]);
    stddev[j] /= float_n;
    stddev[j] = sqrt(stddev[j]);
    /* The following in an inelegant but usual way to handle
       near-zero std. dev. values, which below would cause a zero-
       divide. */
    stddev[j] = stddev[j] <= eps ? 1.0 : stddev[j];
  }

  /* Center and reduce the column vectors. */
  for (i = 1; i <= N; i++)
    for (j = 1; j <= M; j++)
    {
      data[i][j] -= mean[j];
      data[i][j] /= sqrt(float_n) * stddev[j];
    }






  int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;

 register int lbv, ubv;

/* Start of CLooG code */
if (M >= 2) {
  for (t2=0;t2<=floord(M-1,32);t2++) {
    for (t3=t2;t3<=floord(M,32);t3++) {
      for (t4=max(1,32*t2);t4<=min(min(M-1,32*t2+31),32*t3+30);t4++) {
        lbv=max(32*t3,t4+1);
        ubv=min(M,32*t3+31);
#pragma ivdep
#pragma vector always
        for (t11=lbv;t11<=ubv;t11++) {
          symmat[t4][t11]=0.0;;
        }
      }
    }
  }
  if (N >= 1) {
    for (t2=0;t2<=floord(M-1,32);t2++) {
      for (t3=t2;t3<=floord(M,32);t3++) {
        for (t4=0;t4<=floord(N,32);t4++) {
          for (t5=max(1,32*t2);t5<=min(min(M-1,32*t2+31),32*t3+30);t5++) {
            for (t6=max(1,32*t4);t6<=min(N,32*t4+31);t6++) {
              lbv=max(32*t3,t5+1);
              ubv=min(M,32*t3+31);
#pragma ivdep
#pragma vector always
              for (t11=lbv;t11<=ubv;t11++) {
                symmat[t5][t11]+=(data[t6][t5]*data[t6][t11]);;
              }
            }
          }
        }
      }
    }
  }
  for (t2=0;t2<=floord(M-1,32);t2++) {
    for (t3=t2;t3<=floord(M,32);t3++) {
      for (t4=max(1,32*t2);t4<=min(min(M-1,32*t2+31),32*t3+30);t4++) {
        lbv=max(32*t3,t4+1);
        ubv=min(M,32*t3+31);
#pragma ivdep
#pragma vector always
        for (t5=lbv;t5<=ubv;t5++) {
          symmat[t5][t4]=symmat[t4][t5];;
        }
      }
    }
  }
  lbv=1;
  ubv=M-1;
#pragma ivdep
#pragma vector always
  for (t2=lbv;t2<=ubv;t2++) {
    symmat[t2][t2]=1.0;;
  }
}
/* End of CLooG code */
  symmat[M][M] = 1.0;

  IF_TIME(t_end = rtclock());
  IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

  if (fopen(".test", "r")) {
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
