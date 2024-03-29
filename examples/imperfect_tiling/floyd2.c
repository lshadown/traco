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

	int k,i,j,t;

	// Declare arrays on the stack
	float **D = new float*[N+2];
	float **C = new float*[N+2];
	float **R = new float*[N+2];

	for (i=0; i<N+2; i++){
	  D[i] = new float[N+2];
	  R[i] = new float[N+2];
	  C[i] = new float[N+2];
	}

	// Declare arrays on the stack
	float **D1 = new float*[N+2];
	float **C1 = new float*[N+2];
	float **R1 = new float*[N+2];

	for (i=0; i<N+2; i++){
	  D1[i] = new float[N+2];
	  R1[i] = new float[N+2];
	  C1[i] = new float[N+2];
	}

	// Set the input data
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			D[i][j] = ((float) i*i*(j+2) + 2) / N;
			C[i][j] = ((float) i*i*(j+2) + 2) / N;
			R[i][j] = ((float) i*i*(j+2) + 2) / N;
			D1[i][j] = ((float) i*i*(j+2) + 2) / N;
			C1[i][j] = ((float) i*i*(j+2) + 2) / N;
			R1[i][j] = ((float) i*i*(j+2) + 2) / N;
		}
	}

double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){

#pragma scop
for(k=0; k<N;k++) {
   for(i=0; i<N; i++) {
     for(j=0; j<N; j++) {
       D[i][j]=C[k][i] +R[k][j] + D[i][j];
       if(i == k+1)
          R[k+1][j]=D[i][j];
       if (j == k+1)
           C[k+1][i]=D[i][j];
      }
    }
   }
#pragma endscop

}
// pluto
// -----------------------------------
else if(kind == 3){

// pluto


}else{



for(k=0; k<N;k++) {
   for(i=0; i<N; i++) {
     for(j=0; j<N; j++) {
       D1[i][j]=C1[k][i] +R1[k][j] + D1[i][j];
       if(i == k+1)
          R1[k+1][j]=D1[i][j];
       if (j == k+1)
           C1[k+1][i]=D1[i][j];
      }
    }
   }




    //traco
int c0,c1,c2,c3,c4,c5;


for (c0 = 0; c0 <= floord(N - 1, 16); c0 += 1)
  for (c1 = 0; c1 <= (N - 1) / 16; c1 += 1)
    for (c2 = 0; c2 <= (N - 1) / 16; c2 += 1)
      for (c3 = 16 * c0; c3 <= min(16 * c0 + 15, N - 1); c3 += 1)
        for (c4 = 16 * c1; c4 <= min(N - 1, 16 * c1 + 15); c4 += 1) {
          if (c2 == c0 && c3 >= 16 * c0 + 1)
            for (c5 = 0; c5 < 16 * c0; c5 += 1) {
              D[c4][c5]=C[c3][c4]+R[c3][c5]+D[c4][c5];
              if (c4 == c3 + 1)
                R[c3+1][c5]=D[c3+1][c5];
            }
          for (c5 = 16 * c2; c5 <= min(N - 1, 16 * c2 + 15); c5 += 1) {
            if (c3 == 16 * c0 && c0 >= c2 + 1) {
              D[c4][c5]=C[16*c0][c4]+R[16*c0][c5]+D[c4][c5];
              if (c4 == 16 * c0 + 1 && c1 == c0)
                R[16*c0+1][c5]=D[16*c0+1][c5];
            } else if (16 * c2 + 15 >= c3) {
              D[c4][c5]=C[c3][c4]+R[c3][c5]+D[c4][c5];
              if (c4 == c3 + 1)
                R[c3+1][c5]=D[c3+1][c5];
            }
            if (c4 >= c3 + 2) {
              R[c3+1][c5]=D[c4][c5];
            } else if (c3 >= c4)
              R[c3+1][c5]=D[c4][c5];
            C[c3+1][c4]=D[c4][c5];
          }
        }

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
	         if(D[i][j] != D1[i][j]) 
                   {
                        printf("error %i %i %f %f \n ", i,j, D[i][j], D1[i][j]); 
                        exit(0);
                   }
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
