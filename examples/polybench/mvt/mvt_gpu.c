#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
#include <math.h>

#include<openacc.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))


int N = 1024;
int DIM;
int NY, NX;
int DIM1;
int DIM2;
int DIM3;





void seq(float A[DIM1][DIM2], float x1[DIM1], float x2[DIM1], float y_1[DIM1], float y_2[DIM1]) {
int i,j,k, alpha=0;

#pragma acc data copyinout(x1[0:n],x2[0:n]) copyin(alpha, A[0:n*n], y_1[0:n], y_2[0:n],N,NX) private(i,j)
{

	for (i=0; i<NX; i++) {
		for (j=0; j<NX; j++) {
			x1[i] = x1[i] + A[i][j] * y_1[j];
		}
	}
	for (i=0; i<NX; i++) {
		for (j=0; j<NX; j++) {
			x2[i] = x2[i] + A[j][i] * y_2[j];
		}
	}
}

}







void comp(float A[DIM1][DIM2], float x1[DIM1], float x2[DIM1], float y_1[DIM1], float y_2[DIM1]) {

int i,j,k, alpha=0;

#pragma acc data copyinout(x1[0:n],x2[0:n]) copyin(A[0:n*n], y_1[0:n], y_2[0:n],N,NX)
{
    #pragama acc kernels loop private(i,j)
	for (i=0; i<NX; i++) {
	    #pragma acc loop
		for (j=0; j<NX; j++) {
			x1[i] = x1[i] + A[i][j] * y_1[j];
            x2[i] = x2[i] + A[j][i] * y_2[j];
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

  NY = NX = N;
  DIM = DIM1 = DIM2 = DIM3 = N+20;

  float (*A)[DIM2], *x1, *x2, *y_1, *y_2;

  A = (float (*)[DIM2])malloc(DIM1 * DIM2 * sizeof(float));
  x1 = (float (*))malloc(DIM1 * sizeof(float));
  x2 = (float (*))malloc(DIM1 * sizeof(float));
  y_1 = (float (*))malloc(DIM1 * sizeof(float));
  y_2 = (float (*))malloc(DIM1 * sizeof(float));



  printf("Ilosc procesorow: %i \n\n", tool_kind);
  omp_set_num_threads(tool_kind);

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

   double start = omp_get_wtime();

  if(tool_kind == 1)
    seq(A,x1,x2,y_1,y_2);
  else if (tool_kind == 2){
          comp(A,x1,x2,y_1,y_2);
   }
       else{
          comp_pluto(A,x1,x2,y_1,y_2);

   }

   double end = omp_get_wtime();

   printf("%.3f\n", end - start);

  // -----------------------------------
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}









