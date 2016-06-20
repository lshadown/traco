#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <omp.h> 
#include <assert.h>

#define N 2000
#define T 1000

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#pragma declarations
double a[N][N];
double b[N][N];
#pragma enddeclarations

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif



void init_array()
{
    int i, j;

    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            a[i][j] = ((double)j)/N;
        }
    }
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
#define __PLACE_TO_INSERT_FORWARD_DECLARATIONS

int main()
{
    int t, i, j;
    double t_start, t_end;

    init_array();
int t1, c3, c5, t3, t5;
    t_start = rtclock();



if (N >= 4)
  for (t1 = 0; t1 < T; t1 += 1) {
    if (t1 >= 1) {
      if (N >= 4 && T >= t1 + 1 && t1 >= 0) {
        if (t1 >= 1) {
          #pragma omp parallel for
          for (c3 = 2; c3 < N - 1; c3 += 1) {
            if (c3 == 2) {
              b[2][2]=0.2*(a[2][2]+a[2][2-1]+a[2][1+2]+a[1+2][2]+a[2-1][2]);
            }
            for (c5 = max(2, -2 * c3 + 7); c5 < N - 1; c5 += 1) {
              b[c3][c5]=0.2*(a[c3][c5]+a[c3][c5-1]+a[c3][1+c5]+a[1+c3][c5]+a[c3-1][c5]);
            }
          }
          if (N == 4) {
            b[2][2]=0.2*(a[2][2]+a[2][2-1]+a[2][1+2]+a[1+2][2]+a[2-1][2]);
          }
        } else
          b[2][2]=0.2*(a[2][2]+a[2][2-1]+a[2][1+2]+a[1+2][2]+a[2-1][2]);
      }
    } else
      for (t3 = 2; t3 < N - 1; t3 += 1)
        for (t5 = 2; t5 < N - 1; t5 += 1)
          if (T >= 1 && t5 >= 2 && N >= t5 + 2 && t3 >= 2 && N >= t3 + 2) {
            b[t3][t5]=0.2*(a[t3][t5]+a[t3][t5-1]+a[t3][1+t5]+a[1+t3][t5]+a[t3-1][t5]);
          }
    if (T >= t1 + 1 && t1 >= 0) {
      #pragma omp parallel for
      for (c3 = 2; c3 < N - 1; c3 += 1) {
        for (c5 = 2; c5 < N - 1; c5 += 1) {
          a[c3][c5]=b[c3][c5];
        }
      }
    }
  }


    t_end = rtclock();
    printf("%0.6lfs\n", t_end - t_start);


    return 0;
}
