#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <math.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#define MAX(x,y)    ((x) > (y)? (x) : (y))

int N = 500;

int can_pair(int *input, int a, int b){
   return ((((input[a] + input[b]) == 3) && (a < b - 1))) ? 1 : 0;
}

int main(int argc, char *argv[])
{
    int num_proc=1;
    num_proc = atoi(argv[1]);
    int kind;

    if(argc > 2)
        N = atoi(argv[2]);

    int DIM = 2*N+2;

    if(argc > 3)
        kind = atoi(argv[3]);

    int i,j,k;
    double start, end;


    float (*S)[DIM];
    S = (float (*)[DIM])malloc(DIM * DIM * sizeof(float));
    int *RNA;
    RNA = (int (*))malloc(DIM * sizeof(float));


    start = omp_get_wtime();
/*
    for (i = N-1; i >= 0; i--) {
     for (j = i+1; j < N; j++) {
      for (k = 0; k < j-i; k++) {
         S[i][j] = MAX(S[i][k+i] + S[k+i+1][j], S[i][j]); // s0
      }
      S[i][j] = MAX(S[i][j], S[i+1][j-1] +can_pair(RNA, i, j));
     }
    }
*/
int c1,c3,c4,c7,c9,c10,c11,c5;
    for (c1 = 0; c1 <= floord(N - 1, 32); c1 += 1)
      for (c3 = 0; c3 <= min(c1, floord(N - 2, 32)); c3 += 1)
        for (c4 = 2; c4 <= 3; c4 += 1) {
          if (c4 == 3) {
            for (c7 = max(32 * c1, 32 * c3 + 1); c7 <= min(N - 1, 32 * c1 + 62); c7 += 1)
              for (c9 = max(N - 32 * c1 + 32 * c3 - 31, N + 32 * c3 - c7); c9 <= min(N - 1, N + 32 * c3 - c7 + 31); c9 += 1)
                for (c10 = max(2, N + 32 * c3 - c7 - c9 + 3); c10 <= min(3, c1 - (-c1 + c7 + 30) / 31 + 4); c10 += 1) {
                  if (c10 == 3) {
                    S[N-1-c7][c9]=MAX(S[N-1-c7][c9],S[N-c7][c9-1]+can_pair(RNA, i, j));
                  } else if (c7 >= 32 * c1 + 1) {
                    for (c11 = 0; c11 <= -N + c7 + c9; c11 += 1)
                      S[N-1-c7][c9]=MAX(S[N-1-c7][c11+N-c7-1]+S[c11+N-c7][c9],S[N-1-c7][c9]);
                  } else
                    for (c11 = 32 * c3 + 1; c11 <= -N + 32 * c1 + c9; c11 += 1)
                      S[N-1-32*c1][c9]=MAX(S[N-1-32*c1][c11+N-32*c1-1]+S[c11+N-32*c1][c9],S[N-1-32*c1][c9]);
                }
          } else
            for (c5 = 0; c5 <= c3; c5 += 1)
              for (c7 = max(32 * c1, 32 * c3 + 1); c7 <= min(N - 1, 32 * c1 + 31); c7 += 1)
                for (c11 = 32 * c5; c11 <= min(32 * c3, 32 * c5 + 31); c11 += 1)
                  S[N-1-c7][N+32*c3-c7]=MAX(S[N-1-c7][c11+N-c7-1]+S[c11+N-c7][N+32*c3-c7],S[N-1-c7][N+32*c3-c7]);
        }

    end = omp_get_wtime();
	printf("%.6f\n", end - start);

    return 0;


}

