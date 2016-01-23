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
	int z = 0;

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
	    for (j = 0; j < N; j++){
	      path[i][j] = path[i][j] < path[i][k] + path[k][j] ? path[i][j] : path[i][k] + path[k][j];
	      z++;
	      }

  }
#pragma endscop
}
else{

    //traco
    int c0,c1,c2,c3,c4,c5,c6,c8,l;
    int UB1 = (N - 1) / 16;
    int UB = c0 + l / 16;

for(l=0; l < N ; l++){
if (l >= 2 && N >= l + 2) {
  for (c0 = 0; c0 <= 1; c0 += 1)
#pragma omp parallel for
    for (c2 = 0; c2 < c0 + l / 2; c2 += 1) {
      if (c0 == 0) {
        for (c4 = 0; c4 < l / 2; c4 += 1)
          for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
            for (c8 = 2 * c4; c8 <= 2 * c4 + 1; c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      } else if (l >= 2 * c2 + 2) {
        for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
          for (c8 = -(l % 2) + l; c8 <= -(l % 2) + l + 1; c8 += 1)
            path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      } else
        for (c4 = 0; c4 < c2; c4 += 1)
          for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
            for (c8 = 2 * c4; c8 <= 2 * c4 + 1; c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

    }
  for (c0 = 2; c0 <= 4; c0 += 1) {
    if (c0 == 2)
      for (c2 = 0; c2 < floord(l, 2); c2 += 1)
        for (c4 = l / 2 + 1; c4 < floord(N + 1, 2); c4 += 1)
          for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
            for (c8 = 2 * c4; c8 <= min(N - 1, 2 * c4 + 1); c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

#pragma omp parallel for
    for (c2 = max(c0 + l / 2 - 3, l / 2); c2 < (N + 1) / 2; c2 += 1) {
      if (c0 == 4) {
        for (c4 = l / 2 + 1; c4 < (N + 1) / 2; c4 += 1)
          for (c6 = 2 * c2; c6 <= min(N - 1, 2 * c2 + 1); c6 += 1)
            for (c8 = 2 * c4; c8 <= min(N - 1, 2 * c4 + 1); c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      } else if (c0 == 2 && 2 * c2 >= l + 1) {
        for (c4 = 0; c4 < floord(l, 2); c4 += 1)
          for (c6 = 2 * c2; c6 <= min(N - 1, 2 * c2 + 1); c6 += 1)
            for (c8 = 2 * c4; c8 <= 2 * c4 + 1; c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      } else if (c0 == 3 && 2 * c2 >= l + 1) {
        for (c6 = 2 * c2; c6 <= min(N - 1, 2 * c2 + 1); c6 += 1)
          for (c8 = -(l % 2) + l; c8 <= -(l % 2) + l + 1; c8 += 1)
            path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      } else if (c0 == 3) {
        for (c4 = c2 + 1; c4 < (N + 1) / 2; c4 += 1)
          for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
            for (c8 = 2 * c4; c8 <= min(N - 1, 2 * c4 + 1); c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      } else
        for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
          for (c8 = 2 * c2; c8 <= 2 * c2 + 1; c8 += 1)
            path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

    }
  }
} else if (N >= 3 && l >= 0 && l <= 1) {
  for (c0 = 0; c0 <= 2; c0 += 1) {
    if (c0 >= 1) {
      for (c2 = c0 - 1; c2 < (N + 1) / 2; c2 += 1) {
        if (c0 == 2) {
          for (c4 = 1; c4 < (N + 1) / 2; c4 += 1)
            for (c6 = 2 * c2; c6 <= min(N - 1, 2 * c2 + 1); c6 += 1)
              for (c8 = 2 * c4; c8 <= min(N - 1, 2 * c4 + 1); c8 += 1)
                path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

        } else if (c2 >= 1) {
          for (c6 = 2 * c2; c6 <= min(N - 1, 2 * c2 + 1); c6 += 1)
            for (c8 = 0; c8 <= 1; c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

        } else
          for (c4 = 1; c4 < (N + 1) / 2; c4 += 1)
            for (c6 = 0; c6 <= 1; c6 += 1)
              for (c8 = 2 * c4; c8 <= min(N - 1, 2 * c4 + 1); c8 += 1)
                path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      }
    } else
      for (c6 = 0; c6 <= 1; c6 += 1)
        for (c8 = 0; c8 <= 1; c8 += 1)
          path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

  }
} else if (N >= 3 && l + 1 == N)
  for (c0 = 0; c0 <= 2; c0 += 1) {
    if (c0 <= 1) {
      for (c2 = 0; c2 < c0 + (N + 1) / 2 - 1; c2 += 1) {
        if (c0 == 0) {
          for (c4 = 0; c4 < (N + 1) / 2 - 1; c4 += 1)
            for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
              for (c8 = 2 * c4; c8 <= 2 * c4 + 1; c8 += 1)
                path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

        } else if (N >= 2 * c2 + 3) {
          for (c6 = 2 * c2; c6 <= 2 * c2 + 1; c6 += 1)
            for (c8 = -((N - 1) % 2) + N - 1; c8 < N; c8 += 1)
              path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

        } else
          for (c4 = 0; c4 < c2; c4 += 1)
            for (c6 = 2 * c2; c6 < N; c6 += 1)
              for (c8 = 2 * c4; c8 <= 2 * c4 + 1; c8 += 1)
                path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

      }
    } else
      for (c6 = -((N - 1) % 2) + N - 1; c6 < N; c6 += 1)
        for (c8 = -((N - 1) % 2) + N - 1; c8 < N; c8 += 1)
          path[c6][c8]=path[c6][c8]-path[c6][l]+path[l][c8]*path[c6][c8]/path[c6][l]+path[l][c8];

  }



}
}

    double end = omp_get_wtime();
	printf("%.3f\n", end - start);
	printf("%i\n", z);

	#pragma endscop

	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
