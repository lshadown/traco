#include <omp.h>
#include <math.h>
#include <stdio.h>
#include<stdlib.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))



int N = 1024;


int main(int argc, char *argv[]) {

    int kind = atoi(argv[1]);
	int N = atoi(argv[2]);
	int cpus = atoi(argv[3]);
    int z = 0;
	omp_set_num_threads(cpus);

	int k,l,i,j,t,loop=N,n=N;

	// Declare arrays on the stack
	double **B = new double*[N+1];
	double **B1 = new double*[N+1];
	double **L = new double*[N+1];


	for (i=0; i<N+1; i++){
	  B[i] = new double[N+1];
	  B1[i] = new double[N+1];
	  L[i] = new double[N+1];
    }


	// Set the input data
	for (i=0; i<N+1; i++) {
		for (j=0; j<N+1; j++) {
			B[i][j] = 0.001*(i+1)*j;
			B1[i][j] = 0.001*(i+1)*j;
			L[i][j] = 0.001*(i+1)*j;
		}
	}

double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){



    for (i=0;i<=N-1;i++) {
        for (j=0;j<=N-1;j++) {
            for (k=0;k<=j-1;k++) {
                B[j][i]=B[j][i]-L[j][k]*B[k][i];


            }
            B[j][i]=B[j][i]/L[j][j];

        }
    }

}

else{

    //traco

int c0,c1,c2,c3,c4,c5,c6,c7,c8,c10,c12,c9,c11;
int UB = floord(N - 1, 32);



#pragma omp parallel for
for (c0 = 0; c0 <= UB; c0 += 1)
  for (c2 = 0; c2 <= (N - 1) / 32; c2 += 1)
    for (c4 = max(c2 - 1, 0); c4 <= min(floord(N - 2, 32), c2); c4 += 1) {
      for (c6 = max(32 * c4 + 1, 32 * c2); c6 <= min(min(N - 1, 32 * c4 + 32), 32 * c2 + 31); c6 += 1) {
        if (c4 == c2)
          for (c8 = 32 * c0; c8 <= min(32 * c0 + 31, N - 1); c8 += 1)
            for (c10 = 32 * c2 + 1; c10 < c6; c10 += 1)
              B[c8][c10]=B[c8][c10]-L[c8][c6]*B[c6][c10];

        for (c8 = 32 * c0; c8 <= min(N - 1, 32 * c0 + 31); c8 += 1)
          B[c6][c8]=B[c6][c8]/L[c6][c6];

      }
      if (c4 == c2)
        for (c6 = 32 * c2 + 32; c6 < N; c6 += 1)
          for (c8 = 32 * c0; c8 <= min(N - 1, 32 * c0 + 31); c8 += 1)
            for (c10 = 32 * c2 + 1; c10 <= 32 * c2 + 31; c10 += 1)
              B[c8][c10]=B[c8][c10]-L[c8][c6]*B[c6][c10];

    }

}
    double end1 = omp_get_wtime();
	printf("%.3f\n", end1 - start);


    if(kind != 1){
    for (i=0;i<=N-1;i++) {
        for (j=0;j<=N-1;j++) {
            for (k=0;k<=j-1;k++) {
                B1[j][i]=B1[j][i]-L[j][k]*B1[k][i];

            }
            B1[j][i]=B1[j][i]/L[j][j];
        }
    }

    for (i=0;i<=N-1;i++) {
        for (j=0;j<=N-1;j++) {
              if(B[j][k] != B1[j][k]){
              printf("Error!\n %.f %.f\n", B[i][j], B1[i][j]);
                exit(0);
              }
              }
        }

    }

    printf("%i\n", z);

	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
