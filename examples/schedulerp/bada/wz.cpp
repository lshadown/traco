#include <omp.h>
#include <math.h>
#include <stdio.h>
#include<stdlib.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))




int N = 1024;
int b,n;

// This is 'seidel-2d', a 2D Seidel stencil computation
int main(int argc, char *argv[]) {

    int kind = atoi(argv[1]);
	int N = atoi(argv[2]);
	int cpus = atoi(argv[3]);
	int z = 0;
	float det=0;
	b=n=N;

	omp_set_num_threads(cpus);

	int k,i,j,t;

	// Declare arrays on the stack
	float **w = new float*[2*N];
	float **w1 = new float*[2*N];
	float **a = new float*[2*N];
	float **a1 = new float*[2*N];

	for (i=0; i<2*N; i++) { w[i] = new float[2*N]; }
    for (i=0; i<2*N; i++) { w1[i] = new float[2*N]; }
	for (i=0; i<2*N; i++) { a[i] = new float[2*N]; }
	for (i=0; i<2*N; i++) { a1[i] = new float[2*N]; }

	// Set the input data
	for (i=0; i<2*N; i++) {
		for (j=0; j<2*N; j++) {
			//path[i][j] = ((float) (N-j)*j*(j+2) + 2) / N;
			w[i][j] = 000000.1;
			w[i][j] = w1[i][j]; //  ((float) (N-j)*j*(j+2) + 2) / N;
			a[i][j] = 000000.5;
			a[i][j] = a1[i][j]; //  ((float) (N-j)*j*(j+2) + 2) / N;
		}
	}

double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){

    for(k=1; k<=b; k++){
      det = a[k][k]*a[n-k+1][n-k+1] - a[n-k+1][k]*a[k][n-k+1];
      for(i=k+1; i<=n-k; i++){
        w[i][k] = a[n-k+1][n-k+1]*a[i][k] - a[n-k+1][k]*a[i][n-k+1]/det;
        w[i][n-k+1] = a[k][k]*a[i][n-k+1] - a[k][n-k+1]*a[i][k] / det;

        for(j=k+1; j<=n-k; j++){
          a[i][j] = a[i][j] - w[i][k]*a[k][j] - w[i][n-k+1]*a[n-k+1][j];
      }
     }
   }
}

else if(kind == 3){


  int t1, t2, t3, t4, t5;

 register int lbv, ubv;


}
else{

    //traco
    int c0,c1,c2,c3,c4,c5,c6,c8,l,c9,c11;

for (c1 = 0; c1 < b; c1 += 1) {
  det=a[c1+1][c1+1]*a[n-c1+1+1][n-c1+1+1]-a[n-c1+1+1][c1+1]*a[c1+1][n-c1+1+1];
  register int ub = floord(n - c1 - 1, 32);
  #pragma omp parallel for
  for (c3 = (c1 + 2) / 32; c3 <= ub; c3 += 1)
    for (c4 = 4; c4 <= 5; c4 += 1) {
      if (c4 == 5) {
        for (c5 = (c1 + 2) / 32; c5 <= (n - c1 - 1) / 32; c5 += 1)
          for (c9 = max(c1 + 2, 32 * c3); c9 <= min(n - c1 - 1, 32 * c3 + 31); c9 += 1)
            for (c11 = max(c1 + 2, 32 * c5); c11 <= min(n - c1 - 1, 32 * c5 + 31); c11 += 1)
              a[c9][c11]=a[c9][c11]-w[c9][c1+1]*a[c1+1][c11]-w[c9][n-c1+1+1]*a[n-c1+1+1][c11];
      } else
        for (c9 = max(c1 + 2, 32 * c3); c9 <= min(n - c1 - 1, 32 * c3 + 31); c9 += 1) {
          w[c9][c1+1]=a[n-c1+1+1][n-c1+1+1]*a[c9][c1+1]-a[n-c1+1+1][c1+1]*a[c9][n-c1+1+1]/det;
          w[c9][n-c1+1+1]=a[c1+1][c1+1]*a[c9][n-c1+1+1]-a[c1+1][n-c1+1+1]*a[c9][c1+1]/det;
        }
    }
}

}



    double end = omp_get_wtime();
	printf("%.3f\n", end - start);
	printf("%i\n", z);

    if(kind != 1){


    for(k=1; k<=b; k++){
      det = a1[k][k]*a1[n-k+1][n-k+1] - a1[n-k+1][k]*a1[k][n-k+1];
      for(i=k+1; i<=n-k; i++){
        w1[i][k] = a1[n-k+1][n-k+1]*a1[i][k] - a1[n-k+1][k]*a1[i][n-k+1]/det;
        w1[i][n-k+1] = a1[k][k]*a1[i][n-k+1] - a1[k][n-k+1]*a1[i][k] / det;

        for(j=k+1; j<=n-k; j++){
          a1[i][j] = a1[i][j] - w1[i][k]*a1[k][j] - w1[i][n-k+1]*a1[n-k+1][j];
      }
      }
     }

printf("Checking...");

          for(i = 0; i < 2*N; i++)
            for (j = 0; j < 2*N; j++){
              if(a[i][j] != a1[i][j] || w[i][j] != w1[i][j]){

                if(a[i][j] != a1[i][j])
                    printf("Error a!\n");

                if(w[i][j] != w1[i][j])
                    printf("Error w!\n");


                printf("%.8f %.8f %.8f %.8f\n",a[i][j],a1[i][j],w[i][j],w1[i][j]);
                exit(0);
                }

              }

    }


	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
