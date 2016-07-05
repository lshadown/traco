#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>

#include <omp.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#define N 200

#pragma declarations
double a[N+2][N+2];

//double v_a[32][35];
//double v_b[32][32];
//double v_c[32][33];
#pragma enddeclarations

#include <unistd.h>
#include <sys/time.h>
#include <math.h>

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

void init_array()
{
    int i, j, k;

    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            a[i][j] = i*j/N;
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

int main()
{
	int i, j, k,l;
    double t_start, t_end;
    int t1,t3,t5,c1,c3,c5;

    int n;
    int T,ub;
    n = T = N-1;

	init_array() ;

	t_start = rtclock();
int c = 0;

#pragma scop

if (N >= 6 && T >= 6)
  for (t1 = 0; t1 < T; t1 += 1)
    for (t3 = 1; t3 < N - 1; t3 += 1) {
      if (t1 >= 1 && N >= t3 + 4) {
        if (N >= 6 && T >= 6 && N >= t3 + 2 && t3 >= 1 && t1 >= 0) {
          #pragma omp parallel for
          for (c1 = t1; c1 < min(T, t1 + (N + 2 * t3 - 1) / 4); c1 += 1) {
            if (c1 == t1) {
              a[t3][N-2]=(a[t3-1][N-2-1]+a[t3-1][N-2]+a[t3-1][N-2+1]+a[t3][N-2-1]+a[t3][N-2]+a[t3][N-2+1]+a[t3+1][N-2-1]+a[t3+1][N-2]+a[t3+1][N-2+1])/9.0;
            }
            for (c3 = max(1, t3 + 2 * t1 - 2 * c1 + 1); c3 < min(N - 1, t3 + 2 * t1 - 2 * c1 + (N + 1) / 2 - 1); c3 += 1) {
              a[c3][N+2*t3+4*t1-4*c1-2*c3-2]=(a[c3-1][N+2*t3+4*t1-4*c1-2*c3-2-1]+a[c3-1][N+2*t3+4*t1-4*c1-2*c3-2]+a[c3-1][N+2*t3+4*t1-4*c1-2*c3-2+1]+a[c3][N+2*t3+4*t1-4*c1-2*c3-2-1]+a[c3][N+2*t3+4*t1-4*c1-2*c3-2]+a[c3][N+2*t3+4*t1-4*c1-2*c3-2+1]+a[c3+1][N+2*t3+4*t1-4*c1-2*c3-2-1]+a[c3+1][N+2*t3+4*t1-4*c1-2*c3-2]+a[c3+1][N+2*t3+4*t1-4*c1-2*c3-2+1])/9.0;
            }
          }
        }
      } else if (t1 >= 1 && t3 + 3 >= N) {
        for (t5 = N - 3; t5 < N - 1; t5 += 1)
          if (N >= 6 && T >= 6 && N >= t5 + 2 && t5 + 3 >= N && N >= t3 + 2 && t3 + 3 >= N && t1 >= 1) {
            #pragma omp parallel for
            for (c1 = t1; c1 < min(T, t1 + (t5 + 2 * t3 + 1) / 4); c1 += 1) {
              if (c1 >= t1 + 1) {
                for (c3 = max(1, -N + t5 + t3 + 2 * t1 - 2 * c1 + 3); c3 < min(N - 1, t3 + 2 * t1 - 2 * c1 + (t5 + 1) / 2); c3 += 1) {
                  a[c3][t5+2*t3+4*t1-4*c1-2*c3]=(a[c3-1][t5+2*t3+4*t1-4*c1-2*c3-1]+a[c3-1][t5+2*t3+4*t1-4*c1-2*c3]+a[c3-1][t5+2*t3+4*t1-4*c1-2*c3+1]+a[c3][t5+2*t3+4*t1-4*c1-2*c3-1]+a[c3][t5+2*t3+4*t1-4*c1-2*c3]+a[c3][t5+2*t3+4*t1-4*c1-2*c3+1]+a[c3+1][t5+2*t3+4*t1-4*c1-2*c3-1]+a[c3+1][t5+2*t3+4*t1-4*c1-2*c3]+a[c3+1][t5+2*t3+4*t1-4*c1-2*c3+1])/9.0;
                }
              } else
                for (c3 = t3; c3 < N - 1; c3 += 1) {
                  if (c3 == t3) {
                    a[t3][t5]=(a[t3-1][t5-1]+a[t3-1][t5]+a[t3-1][t5+1]+a[t3][t5-1]+a[t3][t5]+a[t3][t5+1]+a[t3+1][t5-1]+a[t3+1][t5]+a[t3+1][t5+1])/9.0;
                  } else
                    a[N-2][t5-2]=(a[N-2-1][t5-2-1]+a[N-2-1][t5-2]+a[N-2-1][t5-2+1]+a[N-2][t5-2-1]+a[N-2][t5-2]+a[N-2][t5-2+1]+a[N-2+1][t5-2-1]+a[N-2+1][t5-2]+a[N-2+1][t5-2+1])/9.0;
                }
            }
          } else if (N >= 6 && T >= 6 && t5 + 2 == N && N >= t3 + 4 && t3 >= 1 && t1 >= 1) {
            for (c1 = t1; c1 < min(T, t1 + (N + 2 * t3 - 1) / 4); c1 += 1) {
              if (c1 >= t1 + 1) {
                for (c3 = max(1, t3 + 2 * t1 - 2 * c1 + 1); c3 < min(N - 1, t3 + 2 * t1 - 2 * c1 + (N + 1) / 2 - 1); c3 += 1) {
                  a[c3][N+2*t3+4*t1-4*c1-2*c3-2]=(a[c3-1][N+2*t3+4*t1-4*c1-2*c3-2-1]+a[c3-1][N+2*t3+4*t1-4*c1-2*c3-2]+a[c3-1][N+2*t3+4*t1-4*c1-2*c3-2+1]+a[c3][N+2*t3+4*t1-4*c1-2*c3-2-1]+a[c3][N+2*t3+4*t1-4*c1-2*c3-2]+a[c3][N+2*t3+4*t1-4*c1-2*c3-2+1]+a[c3+1][N+2*t3+4*t1-4*c1-2*c3-2-1]+a[c3+1][N+2*t3+4*t1-4*c1-2*c3-2]+a[c3+1][N+2*t3+4*t1-4*c1-2*c3-2+1])/9.0;
                }
              } else
                for (c3 = t3; c3 < min(N - 1, t3 + (N + 1) / 2 - 1); c3 += 1) {
                  a[c3][N+2*t3-2*c3-2]=(a[c3-1][N+2*t3-2*c3-2-1]+a[c3-1][N+2*t3-2*c3-2]+a[c3-1][N+2*t3-2*c3-2+1]+a[c3][N+2*t3-2*c3-2-1]+a[c3][N+2*t3-2*c3-2]+a[c3][N+2*t3-2*c3-2+1]+a[c3+1][N+2*t3-2*c3-2-1]+a[c3+1][N+2*t3-2*c3-2]+a[c3+1][N+2*t3-2*c3-2+1])/9.0;
                }
            }
          } else if (N >= 6 && T >= 6 && N >= t5 + 2 && t5 + 3 >= N && t3 >= 2 && N >= t3 + 2 && t1 == 0) {
            for (c1 = 0; c1 < min(T, (t5 + 2 * t3 + 1) / 4); c1 += 1) {
              if (c1 >= 1) {
                for (c3 = max(1, -N + t5 + t3 - 2 * c1 + 3); c3 < min(N - 1, t3 - 2 * c1 + (t5 + 1) / 2); c3 += 1) {
                  a[c3][t5+2*t3-4*c1-2*c3]=(a[c3-1][t5+2*t3-4*c1-2*c3-1]+a[c3-1][t5+2*t3-4*c1-2*c3]+a[c3-1][t5+2*t3-4*c1-2*c3+1]+a[c3][t5+2*t3-4*c1-2*c3-1]+a[c3][t5+2*t3-4*c1-2*c3]+a[c3][t5+2*t3-4*c1-2*c3+1]+a[c3+1][t5+2*t3-4*c1-2*c3-1]+a[c3+1][t5+2*t3-4*c1-2*c3]+a[c3+1][t5+2*t3-4*c1-2*c3+1])/9.0;
                }
              } else
                for (c3 = t3; c3 < min(N - 1, t3 + (t5 + 1) / 2); c3 += 1) {
                  a[c3][t5+2*t3-2*c3]=(a[c3-1][t5+2*t3-2*c3-1]+a[c3-1][t5+2*t3-2*c3]+a[c3-1][t5+2*t3-2*c3+1]+a[c3][t5+2*t3-2*c3-1]+a[c3][t5+2*t3-2*c3]+a[c3][t5+2*t3-2*c3+1]+a[c3+1][t5+2*t3-2*c3-1]+a[c3+1][t5+2*t3-2*c3]+a[c3+1][t5+2*t3-2*c3+1])/9.0;
                }
            }
          } else if (N >= 6 && T >= 6 && N >= t5 + 2 && t3 == 1 && t1 == 0)
            #pragma omp parallel for
            for (c1 = 0; c1 <= min(T - 1, ((t5 - 1)/ 4)); c1 += 1) {
              for (c3 = 1; c3 <= -2 * c1 + (t5 + 1) / 2; c3 += 1) {
                if (c1 >= 1) {
                  a[c3][t5-4*c1-2*c3+2]=(a[c3-1][t5-4*c1-2*c3+2-1]+a[c3-1][t5-4*c1-2*c3+2]+a[c3-1][t5-4*c1-2*c3+2+1]+a[c3][t5-4*c1-2*c3+2-1]+a[c3][t5-4*c1-2*c3+2]+a[c3][t5-4*c1-2*c3+2+1]+a[c3+1][t5-4*c1-2*c3+2-1]+a[c3+1][t5-4*c1-2*c3+2]+a[c3+1][t5-4*c1-2*c3+2+1])/9.0;
                } else
                  a[c3][t5-2*c3+2]=(a[c3-1][t5-2*c3+2-1]+a[c3-1][t5-2*c3+2]+a[c3-1][t5-2*c3+2+1]+a[c3][t5-2*c3+2-1]+a[c3][t5-2*c3+2]+a[c3][t5-2*c3+2+1]+a[c3+1][t5-2*c3+2-1]+a[c3+1][t5-2*c3+2]+a[c3+1][t5-2*c3+2+1])/9.0;
              }
            }
      } else if (t3 >= 2) {
        for (t5 = N - 3; t5 < N - 1; t5 += 1)
          if (N >= 6 && T >= 6 && N >= t5 + 2 && t5 + 3 >= N && t3 >= 2 && N >= t3 + 2) {
            #pragma omp parallel for
            for (c1 = 0; c1 < min(T, (t5 + 2 * t3 + 1) / 4); c1 += 1) {
              if (c1 >= 1) {
                for (c3 = max(1, -N + t5 + t3 - 2 * c1 + 3); c3 < min(N - 1, t3 - 2 * c1 + (t5 + 1) / 2); c3 += 1) {
                  a[c3][t5+2*t3-4*c1-2*c3]=(a[c3-1][t5+2*t3-4*c1-2*c3-1]+a[c3-1][t5+2*t3-4*c1-2*c3]+a[c3-1][t5+2*t3-4*c1-2*c3+1]+a[c3][t5+2*t3-4*c1-2*c3-1]+a[c3][t5+2*t3-4*c1-2*c3]+a[c3][t5+2*t3-4*c1-2*c3+1]+a[c3+1][t5+2*t3-4*c1-2*c3-1]+a[c3+1][t5+2*t3-4*c1-2*c3]+a[c3+1][t5+2*t3-4*c1-2*c3+1])/9.0;
                }
              } else
                for (c3 = t3; c3 < min(N - 1, t3 + (t5 + 1) / 2); c3 += 1) {
                  a[c3][t5+2*t3-2*c3]=(a[c3-1][t5+2*t3-2*c3-1]+a[c3-1][t5+2*t3-2*c3]+a[c3-1][t5+2*t3-2*c3+1]+a[c3][t5+2*t3-2*c3-1]+a[c3][t5+2*t3-2*c3]+a[c3][t5+2*t3-2*c3+1]+a[c3+1][t5+2*t3-2*c3-1]+a[c3+1][t5+2*t3-2*c3]+a[c3+1][t5+2*t3-2*c3+1])/9.0;
                }
            }
          } else if (N >= 6 && T >= 6 && N >= t5 + 2 && t3 == 1)
            #pragma omp parallel for
            for (c1 = 0; c1 <= min(T - 1, ((t5 - 1)/ 4)); c1 += 1) {
              for (c3 = 1; c3 <= -2 * c1 + (t5 + 1) / 2; c3 += 1) {
                if (c1 >= 1) {
                  a[c3][t5-4*c1-2*c3+2]=(a[c3-1][t5-4*c1-2*c3+2-1]+a[c3-1][t5-4*c1-2*c3+2]+a[c3-1][t5-4*c1-2*c3+2+1]+a[c3][t5-4*c1-2*c3+2-1]+a[c3][t5-4*c1-2*c3+2]+a[c3][t5-4*c1-2*c3+2+1]+a[c3+1][t5-4*c1-2*c3+2-1]+a[c3+1][t5-4*c1-2*c3+2]+a[c3+1][t5-4*c1-2*c3+2+1])/9.0;
                } else
                  a[c3][t5-2*c3+2]=(a[c3-1][t5-2*c3+2-1]+a[c3-1][t5-2*c3+2]+a[c3-1][t5-2*c3+2+1]+a[c3][t5-2*c3+2-1]+a[c3][t5-2*c3+2]+a[c3][t5-2*c3+2+1]+a[c3+1][t5-2*c3+2-1]+a[c3+1][t5-2*c3+2]+a[c3+1][t5-2*c3+2+1])/9.0;
              }
            }
      } else
        for (t5 = 1; t5 < N - 1; t5 += 1)
          if (N >= 6 && T >= 6 && N >= t5 + 2) {
            #pragma omp parallel for
            for (c1 = 0; c1 <= min(T - 1, ((t5 - 1)/ 4)); c1 += 1) {
              for (c3 = 1; c3 <= -2 * c1 + (t5 + 1) / 2; c3 += 1) {
                if (c1 >= 1) {
                  a[c3][t5-4*c1-2*c3+2]=(a[c3-1][t5-4*c1-2*c3+2-1]+a[c3-1][t5-4*c1-2*c3+2]+a[c3-1][t5-4*c1-2*c3+2+1]+a[c3][t5-4*c1-2*c3+2-1]+a[c3][t5-4*c1-2*c3+2]+a[c3][t5-4*c1-2*c3+2+1]+a[c3+1][t5-4*c1-2*c3+2-1]+a[c3+1][t5-4*c1-2*c3+2]+a[c3+1][t5-4*c1-2*c3+2+1])/9.0;
                } else
                  a[c3][t5-2*c3+2]=(a[c3-1][t5-2*c3+2-1]+a[c3-1][t5-2*c3+2]+a[c3-1][t5-2*c3+2+1]+a[c3][t5-2*c3+2-1]+a[c3][t5-2*c3+2]+a[c3][t5-2*c3+2+1]+a[c3+1][t5-2*c3+2-1]+a[c3+1][t5-2*c3+2]+a[c3+1][t5-2*c3+2+1])/9.0;
              }
            }
          }
    }


#pragma endscop


	t_end = rtclock();
	printf("%0.6lfs  %i\n", t_end - t_start,c);


    return 0;
}
