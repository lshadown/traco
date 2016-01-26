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
                z++;

            }
            B[j][i]=B[j][i]/L[j][j];
            z++;
        }
    }

}

else{

    //traco

int c0,c1,c2,c3,c4,c5,c6,c7,c8,c10,c12,c9,c11;
int UB = floord(N - 1, 16);


#pragma omp parallel for
for (c1 = 0; c1 <= UB + 1; c1 += 1)
  for (c3 = 0; c3 <= floord(N - 1, 16); c3 += 1) {
    for (c5 = c3; c5 <= min(c3 + 1, (N + 14) / 16); c5 += 1)
      for (c7 = max(16 * c3, 16 * c5 - 15); c7 <= min(min(N - 1, 16 * c3 + 15), 16 * c5); c7 += 1)
        for (c11 = 16 * c1; c11 <= min(N + 15, 16 * c1 + 15); c11 += 1)
          //B[c7][c11]=B[c7][c11]/L[c7][c7];
          z++;
    if (N >= 16 * c1 + 2)
      for (c5 = c1; c5 <= c3; c5 += 1) {
        for (c9 = max(16 * c1 + 1, 16 * c5); c9 <= min(N - 1, 16 * c5 + 15); c9 += 1)
          for (c11 = 16 * c1; c11 <= min(16 * c1 + 15, c9 - 1); c11 += 1)
          //  B[16*c3][c11]=B[16*c3][c11]-L[16*c3][c9]*B[c9][c11];
          z++;
        if (N >= 16 * c3 + 2 && c5 == c3)
          for (c9 = 16 * c1 + 1; c9 < 16 * c3; c9 += 1)
            for (c11 = 16 * c1; c11 <= min(16 * c1 + 15, c9 - 1); c11 += 1)
            //  B[16*c3+1][c11]=B[16*c3+1][c11]-L[16*c3+1][c9]*B[c9][c11];
            z++;
      }
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
              if(B[j][k] != B1[j][k])
                printf("Error!\n %.f %.f\n", B[i][j], B1[i][j]);
             //   exit(0);
              }
        }

    }

    printf("%i\n", z);

	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
