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

	omp_set_num_threads(cpus);

	int k,l,i,j,t,loop=N,n=N;

	// Declare arrays on the stack
	double **za = new double*[N+1];
	double **za1 = new double*[N+1];
	double **zb = new double*[N+1];
	double **zr = new double*[N+1];
	double **zu = new double*[N+1];
	double **zv = new double*[N+1];
	double **zz = new double*[N+1];

	for (i=0; i<N+1; i++){
	  za[i] = new double[N+1];
	  za1[i] = new double[N+1];
	  zb[i] = new double[N+1];
	  zr[i] = new double[N+1];
	  zu[i] = new double[N+1];
	  zv[i] = new double[N+1];
	  zz[i] = new double[N+1];


    }
    double *w = new double[N];

	// Set the input data
	for (i=0; i<N+1; i++) {
		for (j=0; j<N+1; j++) {
			za[i][j] = 0.001;
			za1[i][j] = 0.001;
			zb[i][j] = 0.002;
			zr[i][j] = 0.003;
			zv[i][j] = 0.005;
			zu[i][j] = 0.002;
			zz[i][j] = 0.001;
		}
	}

double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){


#pragma scop
    for (i=0;i<=N-1;i++) {
        for (j=0;j<=N-1;j++) {
            for (k=0;k<=j-1;k++) {
                B[j][i]=B[j][i]-L[j][k]*B[k][i];

            }
            B[j][i]=B[j][i]/L[j][j];
        }
    }
#pragma endscop
}


}else{

    //traco

int c0,c1,c2,c3,c4,c5c6,c7,c8,c10,c12;

#pragma omp parallel for
for (c1 = 0; c1 <= floord(N - 1, 16) + 1; c1 += 1)
  for (c3 = 0; c3 <= floord(N - 1, 16); c3 += 1) {
    for (c5 = c3; c5 <= min(c3 + 1, (N + 14) / 16); c5 += 1)
      for (c7 = max(16 * c3, 16 * c5 - 15); c7 <= min(min(N - 1, 16 * c3 + 15), 16 * c5); c7 += 1)
        for (c11 = 16 * c1; c11 <= min(N + 15, 16 * c1 + 15); c11 += 1)
          B[c7][c11]=B[c7][c11]/L[c7][c7];
    if (N >= 16 * c1 + 2)
      for (c5 = c1; c5 <= c3; c5 += 1) {
        for (c9 = max(16 * c1 + 1, 16 * c5); c9 <= min(N - 1, 16 * c5 + 15); c9 += 1)
          for (c11 = 16 * c1; c11 <= min(16 * c1 + 15, c9 - 1); c11 += 1)
            B[16*c3][c11]=B[16*c3][c11]-L[16*c3][c9]*B[c9][c11];
        if (N >= 16 * c3 + 2 && c5 == c3)
          for (c9 = 16 * c1 + 1; c9 < 16 * c3; c9 += 1)
            for (c11 = 16 * c1; c11 <= min(16 * c1 + 15, c9 - 1); c11 += 1)
              B[16*c3+1][c11]=B[16*c3+1][c11]-L[16*c3+1][c9]*B[c9][c11];
      }
  }





}
    double end = omp_get_wtime();
	printf("%.3f\n", end - start);


    if(kind != 1){
    for ( l=1 ; l<=loop ; l++ ) {
        for ( j=1 ; j<6 ; j++ ) {
            for ( k=1 ; k<n ; k++ ) {
                za1[j][k] = za1[j][k] + 0.175*( za1[j+1][k]*zr[j][k] + za1[j-1][k]*zb[j][k] + za1[j][k+1]*zu[j][k] + za1[j][k-1]*zv[j][k] + zz[j][k] - za1[j][k] );
            }
        }
    }

    for ( l=1 ; l<=loop ; l++ ) {
        for ( j=1 ; j<6 ; j++ ) {
            for ( k=1 ; k<n ; k++ ) {
              if(za[j][k] != za1[j][k])
                printf("Error!\n %.f %.f\n", za[j][k], za1[j][k]);
                exit(0);
              }
        }
    }
    }



	#pragma endscop

	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
