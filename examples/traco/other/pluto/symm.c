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
// Filename...........benchmark/symm.c
// Author.............Cedric Nugteren
// Last modified on...23-May-2012
//

#include "common.h"
#include "looplib_a.h"


// This is 'symm', a symmetric matrix multiplication kernel
int main(void) {
	int i,j,k;
	float acc[100];
	float bij;

	// Declare arrays on the stack
	float **A = ReserveMemoryandClear(NJ, NJ);
	float **B = ReserveMemoryandClear(NI, NJ);
	float **C = ReserveMemoryandClear(NI, NJ);

	// Set the constants
	float alpha = 32412;
	float beta = 2123;

	// Set the input data
	for (i=0; i<NI; i++) {
		for (j=0; j<NJ; j++) {
			C[i][j] = ((float) i*j) / NI;
			B[i][j] = ((float) i*j) / NI;
		}
	}
	for (i=0; i<NJ; i++) {
		for (j=0; j<NJ; j++) {
			A[i][j] = ((float) i*j) / NI;
		}
	}



#pragma scop
	for (j=0; j<NJ; j++) {
		for (i=0; i<NI; i++) {
			acc[j] = 0;
			bij = B[i][j];
			for (k=0; k<j-1; k++) {
				C[k][j] += alpha*A[k][i] * bij;
			}
			for (k=0; k<j-1; k++) {
				acc[j] += B[k][j] * A[k][i];
			}
			C[i][j] = beta*C[i][j] + alpha*A[i][i]*bij + alpha*acc[j];
		}
	}
#pragma endscop

	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}

