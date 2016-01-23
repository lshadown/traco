#include <omp.h>
#include <math.h>
#include <stdio.h>
#include<stdlib.h>

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))




int N = 1024;

// This is 'seidel-2d', a 2D Seidel stencil computation
int main(int argc, char *argv[]) {

    int kind = atoi(argv[1]);
	int N = atoi(argv[2]);
	int cpus = atoi(argv[3]);

	omp_set_num_threads(cpus);

	int k,i,j,t;

	// Declare arrays on the stack
	float **path = new float*[N];
	for (i=0; i<N; i++)
	  path[i] = new float[N];

	// Set the input data
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			path[i][j] = ((float) i*i*(j+2) + 2) / N;
		}
	}

double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){


#pragma scop
  for (k = 0; k < N; k++)
  {
      for(i = 0; i < N; i++)
	    for (j = 0; j < N; j++)
	      path[i][j] = path[i][j] < path[i][k] + path[k][j] ? path[i][j] : path[i][k] + path[k][j];
  }
#pragma endscop
}
else{

    //traco
    int c0,c1,c2,c3,c4,c5,c6,c8,l;
    int UB1 = (N - 1) / 16;
    int UB = min(c0 + l / 16 - 1, -c0 + l / 16 + 1);

for(l=0; l < N ; l++){
  if (N >= l + 1 && l >= 34)
    for (c0 = 0; c0 <= min(3, N - l + 1); c0 += 1)
      if (c0 <= 2) {
        if (N >= l + c0)
#pragma omp parallel for
          for (c2 = 0; c2 <= UB; c2 += 1)
            if (c0 == 2) {
              for (c4 = l / 16 + 1; c4 <= (N - 1) / 16; c4 += 1)
                for (c6 = 16 * c2; c6 <= 16 * c2 + 15; c6 += 1)
                  for (c8 = 16 * c4; c8 <= min(N - 1, 16 * c4 + 15); c8 += 1)
                    path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
            } else if (c0 == 0) {
              for (c4 = 0; c4 < l / 16; c4 += 1)
                for (c6 = 16 * c2; c6 <= 16 * c2 + 15; c6 += 1)
                  for (c8 = 16 * c4; c8 <= 16 * c4 + 15; c8 += 1)
                    path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
            } else if (l >= 16 * c2 + 16) {
              for (c6 = 16 * c2; c6 <= 16 * c2 + 15; c6 += 1)
                for (c8 = -(l % 16) + l; c8 <= min(-(l % 16) + l + 15, N - 1); c8 += 1)
                  path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
            } else
              for (c4 = 0; c4 < l / 16; c4 += 1)
                for (c6 = 16 * c2; c6 <= min(N - 1, 16 * c2 + 15); c6 += 1)
                  for (c8 = 16 * c4; c8 <= 16 * c4 + 15; c8 += 1)
                    path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
        if (c0 == 2)
#pragma omp parallel for
          for (c2 = l / 16; c2 <= UB1; c2 += 1)
            if (16 * c2 >= l + 1) {
              for (c4 = 0; c4 < l / 16; c4 += 1)
                for (c6 = 16 * c2; c6 <= min(16 * c2 + 15, N - 1); c6 += 1)
                  for (c8 = 16 * c4; c8 <= 16 * c4 + 15; c8 += 1)
                    path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
            } else
              for (c6 = 16 * c2; c6 <= min(N - 1, 16 * c2 + 15); c6 += 1)
                for (c8 = 16 * c2; c8 <= min(N - 1, 16 * c2 + 15); c8 += 1)
                  path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
      } else
#pragma omp parallel for
        for (c2 = l / 16; c2 <= UB1; c2 += 1)
          if (16 * c2 >= l + 1) {
            for (c6 = 16 * c2; c6 <= min(N - 1, 16 * c2 + 15); c6 += 1)
              for (c8 = -(l % 16) + l; c8 <= -(l % 16) + l + 15; c8 += 1)
                path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
          } else
            for (c4 = c2 + 1; c4 <= (N - 1) / 16; c4 += 1)
              for (c6 = 16 * c2; c6 <= 16 * c2 + 15; c6 += 1)
                for (c8 = 16 * c4; c8 <= min(16 * c4 + 15, N - 1); c8 += 1)
                  path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
  if (l >= 34)
#pragma omp parallel for
    for (c2 = l / 16 + 1; c2 <= UB1; c2 += 1)
      for (c4 = l / 16 + 1; c4 <= (N - 1) / 16; c4 += 1)
        for (c6 = 16 * c2; c6 <= min(16 * c2 + 15, N - 1); c6 += 1)
          for (c8 = 16 * c4; c8 <= min(N - 1, 16 * c4 + 15); c8 += 1)
            path[c6][c8]=path[c6][c8]<path[c6][l]+path[l][c8]?path[c6][c8]:path[c6][l]+path[l][c8];
}


}

    double end = omp_get_wtime();
	printf("%.3f\n", end - start);

	#pragma endscop

	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
