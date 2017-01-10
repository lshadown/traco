#include <omp.h>
#include <math.h>
#include <stdio.h>
#include<stdlib.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))


//
// This file is part of the Bones source-to-source compiler examples. The C-code
// is largely identical in terms of functionality and variable naming to the code
// found in PolyBench/C version 3.2. For more information on PolyBench/C or Bones
// please use the contact information below.
//
// == More information on PolyBench/C
// Contact............Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
// Web address........http://polybench.sourceforge.net/
//
// == More information on Bones
// Contact............Cedric Nugteren <c.nugteren@tue.nl>
// Web address........http://parse.ele.tue.nl/bones/
//
// == File information
// Filename...........benchmark/seidel-2d.c
// Author.............Cedric Nugteren
// Last modified on...05-April-2012
//


int N = 1024;

// This is 'seidel-2d', a 2D Seidel stencil computation
int main(int argc, char *argv[]) {

    int kind = atoi(argv[1]);
	int N = atoi(argv[2]);

	int k,l,i,j,t,loop=N,n=N;

	// Declare arrays on the stack
	long double ***b = new long double**[N+2];
	for (i=0; i<N+2; i++)
	  b[i] = new long double*[N+2];

for (j=0; j<N+2; j++)
for (i=0; i<N+2; i++)
	  b[i][j] = new long double[N+2];

/*	// Set the input data
	for (i=0; i<N+2; i++) {
		for (j=0; j<N+2; j++) {
			b[i][j] = ((long double) i*i*(j+2) + 2) / N;
		}
	}
*/
double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){


  for(i=0; i<=N; i++){
    for(j=0; j<=N; j++){
      b[i][j][i] = b[i+1][N-j][i];
    }
  }
}
// pluto
// -----------------------------------
else if(kind == 3){



}else{

    //traco

int c0,c1,c2,c3,c4,c5;

for (c0 = 0; c0 <= floord(N, 16); c0 += 1)
  for (c1 = 0; c1 <= N / 16; c1 += 1) {
    for (c3 = 16 * c1; c3 <= min(N, 16 * c1 + 15); c3 += 1)
      b[16*c0][c3][16*c0]=b[16*c0+1][N-c3][16*c0+1];
    for (c2 = 16 * c0 + 1; c2 <= min(N, 16 * c0 + 15); c2 += 1) {
      if (c2 == 16 * c0 + 1) {
        for (c3 = max(0, N - 16 * c1 - 15); c3 <= min(16 * c1 - 1, N - 16 * c1); c3 += 1)
          b[16*c0+1][c3][16*c0+1]=b[16*c0+1+1][N-c3][16*c0+2];
      } else
        for (c3 = max(0, N - 16 * c1 - 15); c3 <= min(16 * c1 - 1, N - 16 * c1); c3 += 1)
          b[c2][c3][c2]=b[c2+1][N-c3][c2+1];
      for (c3 = max(N - 16 * c1 - 15, 16 * c1); c3 <= min(N, 16 * c1 + 15); c3 += 1)
        b[c2][c3][c2]=b[c2+1][N-c3][c2+1];
    }
  }

}
    double end = omp_get_wtime();
	printf("%.3f\n", end - start);

	#pragma endscop

	// Clean-up and exit the function
	fflush(stdout);
	return 0;

}
