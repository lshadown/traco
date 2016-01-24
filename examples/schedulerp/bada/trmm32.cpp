#include <omp.h>
#include <math.h>
#include <stdio.h>
#include<stdlib.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))




int ni = 1024;

// This is 'seidel-2d', a 2D Seidel stencil computation
int main(int argc, char *argv[]) {

    int kind = atoi(argv[1]);
	int ni = atoi(argv[2]);
	int cpus = atoi(argv[3]);
	int z = 0;

	int N = ni;

	float alpha = 32412;

	omp_set_num_threads(cpus);

	int k,i,j,t;

	// Declare arrays on the stack
	float **A = new float*[N];
	for (i=0; i<N; i++)
	  A[i] = new float[N];

    float **A1 = new float*[N];
	for (i=0; i<N; i++)
	  A1[i] = new float[N];

    float **B = new float*[N];
	for (i=0; i<N; i++)
	  B[i] = new float[N];

    float **B1 = new float*[N];
	for (i=0; i<N; i++)
	  B1[i] = new float[N];

	// Set the input data
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			//path[i][j] = ((float) (N-j)*j*(j+2) + 2) / N;
			A[i][j] = rand()/N;
			A1[i][j] =  A[i][j]; //  ((float) (N-j)*j*(j+2) + 2) / N;
            B[i][j] = rand()/N;
			B1[i][j] =  B[i][j]; //
		}
	}

double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){


  for (i = 1; i < ni; i++)
    for (j = 0; j < ni; j++)
      for (k = 0; k < i; k++)
        B[i][j] += alpha * A[i][k] * B[j][k];

}
else if(kind == 3){


  int t1, t2, t3, t4, t5;

 register int lbv, ubv;


}
else{

    //traco
    int c0,c1,c2,c3,c4,c5,c6,c8,i;



for (i = 1; i < ni; i++)
{
  if (ni >= i + 1)
    for (c0 = 0; c0 <= floord(i - 1, 32); c0 += 1) {
      if (i >= 32) {
#pragma omp parallel for
        for (c2 = 0; c2 < i / 32; c2 += 1)
          for (c6 = 32 * c2; c6 <= 32 * c2 + 31; c6 += 1) {
            if (c0 >= 1) {
              for (c8 = 32 * c0; c8 <= min(i - 1, 32 * c0 + 31); c8 += 1)
                B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
            } else
              for (c8 = 0; c8 <= 31; c8 += 1)
                B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
          }
        if (i >= 33)
          for (c2 = i / 32 + 1; c2 <= floord(ni - 1, 32); c2 += 1)
            for (c6 = 32 * c2; c6 <= min(ni - 1, 32 * c2 + 31); c6 += 1) {
              if (c0 >= 1) {
                for (c8 = 32 * c0; c8 <= min(i - 1, 32 * c0 + 31); c8 += 1)
                  B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
              } else
                for (c8 = 0; c8 <= 31; c8 += 1)
                  B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
            }
      } else
#pragma omp parallel for
        for (c6 = 0; c6 < i; c6 += 1)
          for (c8 = 0; c8 < i; c8 += 1)
            B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
    }
#pragma omp parallel for
  for (c6 = i; c6 <= min(31, ni - 1); c6 += 1)
    for (c8 = 0; c8 < i; c8 += 1)
      B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
  if (ni >= i + 1)
    for (c0 = max(floord(i - 1, 32) + 1, -floord(i, 32) + floord(15 * i - 32 * floord(i, 32) + 31, 480) + 2); c0 <= min(floord(i - 1, 16) + 1, 2 * floord(i, 32) + 1); c0 += 1)
      for (c6 = -(i % 32) + i; c6 <= min(i, i - c0 + (i + 31) / 32 + i / 32 - 1); c6 += 1)
        for (c8 = ((i + 31) % 32) - i + 32 * c0 - 31; c8 <= min(i - 1, ((i + 31) % 32) - i + 32 * c0); c8 += 1)
          B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
  if (i >= 33 && i % 32 >= 1 && i >= 2 * (i % 32))
    for (c6 = i; c6 <= min(ni - 1, -((i - 1) % 32) + i + 30); c6 += 1) {
      if (c6 >= i + 1) {
        for (c8 = 0; c8 < i; c8 += 1)
          B[i][c6]+=alpha*A[i][c8]*B[c6][c8];
      } else
        for (c8 = -(i % 32) + i; c8 < i; c8 += 1)
          B[i][i]+=alpha*A[i][c8]*B[i][c8];
    }
}

}



    double end = omp_get_wtime();
	printf("%.3f\n", end - start);

    if(kind != 1){
      for (i = 1; i < ni; i++)
        for (j = 0; j < ni; j++)
          for (k = 0; k < i; k++)
            B[i][j] += alpha * A[i][k] * B[j][k];

        for (k = 0; k < N; k++)
        {
          for(i = 0; i < N; i++)
            for (j = 0; j < N; j++){
              if(A[i][j] != A1[i][j] || B[i][j] != B1[i][j])
                printf("Error!\n");
                exit(0);
              }
        }
    }


	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
