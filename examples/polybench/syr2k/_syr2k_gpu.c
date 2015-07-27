#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
#include <math.h>

#include <openacc.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))


int N = 1024;
int DIM;
int NI,NJ;
int DIM1;
int DIM2;
int DIM3;





void seq(float a[DIM1][DIM2], float b[DIM1][DIM2], float c[DIM1][DIM2]) {
int i,j,k, alpha=0, beta = 0;

   int N = N;
   int NI = N;
   int NJ = N;
    #pragma acc data copyinout(c[0:N*N]) copyin(alpha, a[0:N*N], b[0:N*N], N, NI, NJ) private(i,j,k)
    {
	for (i=0; i<NI; i++) {
		for (j=0; j<NI; j++) {
			c[i][j] *= beta;
			for (k=0; k<NJ; k++) {
				c[i][j] += alpha * a[i][k] * b[j][k];
				c[i][j] += alpha * b[i][k] * a[j][k];
			}
		}
	}
    }

}







void comp(float a[DIM1][DIM2], float b[DIM1][DIM2], float c[DIM1][DIM2]) {
int alpha=0, beta = 0;
int i,j,k;

   int N = N;
   int NI = N;
   int NJ = N;
   #pragma acc data copyinout(c[0:N*N]) copyin(alpha, a[0:N*N], b[0:N*N], N, NI, NJ) private(i,j,k)
   {
   #pragma acc kernels loop private(i,k,j)
     for (i=0; i<NI; i++) {
          #pragma acc loop
    		for (j=0; j<NI; j++) {
    			c[i][j] *= beta;
    			#pragma acc loop
      			for (k=0; k<NJ; k++) {
      				c[i][j] += alpha * a[i][k] * b[j][k];
      				c[i][j] += alpha * b[i][k] * a[j][k];
    			}
  		}
	}
    }

}


int main(int argc, char *argv[]) {

  // number of processors
  int tool_kind=1, num_proc=1;

  tool_kind = atoi(argv[1]);
  num_proc = atoi(argv[2]);

  if(argc > 3)
    N = atoi(argv[3]);

  NI = NJ = N;
  DIM = DIM1 = DIM2 = DIM3 = N+20;

  float (*A)[DIM2], (*B)[DIM2], (*C)[DIM2];

  A = (float (*)[DIM2])malloc(DIM1 * DIM2 * sizeof(float));
  B = (float (*)[DIM2])malloc(DIM1 * DIM2 * sizeof(float));
  C = (float (*)[DIM2])malloc(DIM1 * DIM2 * sizeof(float));


  //printf("Ilosc procesorow: %i \n\n", num_proc);
  omp_set_num_threads(num_proc);

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

   double start = omp_get_wtime();

  if(tool_kind == 1)
    seq(A,B,C);
  else if (tool_kind == 2)
    comp(A,B,C);
    else
      comp_pluto(A,B,C);


   double end = omp_get_wtime();

   printf("%.3f\n", end - start);

  // -----------------------------------
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


}









