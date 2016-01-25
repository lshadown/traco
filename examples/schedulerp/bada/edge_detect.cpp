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

    float **path1 = new float*[N];
	for (i=0; i<N; i++)
	  path1[i] = new float[N];

	// Set the input data
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			//path[i][j] = ((float) (N-j)*j*(j+2) + 2) / N;
			path[i][j] = rand()/N;
			path1[i][j] =  path[i][j]; //  ((float) (N-j)*j*(j+2) + 2) / N;
		}
	}

double start = omp_get_wtime();
// -- sekw.
// -----------------------------------
if(kind == 1){

  for (r = 0; r < N - K + 1; r++) {
    for (c = 0; c < N - K + 1; c++) {
      sum[r][c] = 0;
      for (i = 0; i < K; i++) {
        for (j = 0; j < K; j++) {
          sum[r][c] += input_image[r+i][c+j] * kernel[i][j];
        }
      }
      output_image[r+dead_rows][c+dead_cols] = (sum[r][c] / normal_factor);
    }
  }
}
}
else if(kind == 3){


  int t1, t2, t3, t4, t5;

 register int lbv, ubv;

/* Start of CLooG code */
if (N >= 1) {
  for (t1=0;t1<=N-1;t1++) {
    for (t2=0;t2<=floord(N-1,32);t2++) {
      for (t3=0;t3<=floord(N-1,32);t3++) {
        for (t4=32*t2;t4<=min(N-1,32*t2+31);t4++) {
          for (t5=32*t3;t5<=min(N-1,32*t3+31);t5++) {
            path[t4][t5] = path[t4][t5] < path[t4][t1] + path[t1][t5] ? path[t4][t5] : path[t4][t1] + path[t1][t5];;
          }
        }
      }
    }
  }
}
}
else{

    //traco
    int c0,c1,c2,c3,c4,c5,c6,c8,c7.c9.c11,c13,c15
    ;

#pragma omp parallel for
for (c1 = 0; c1 <= floord(N - K, 16); c1 += 1)
  for (c3 = 0; c3 <= (N - K) / 16; c3 += 1) {
    if (K >= 1) {
      if (K >= 17)
        for (c9 = 16 * c1; c9 <= min(N - K, 16 * c1 + 15); c9 += 1)
          for (c11 = 16 * c3; c11 <= min(N - K, 16 * c3 + 15); c11 += 1)
            sum[c9][c11]=0;
      for (c9 = 16 * c1; c9 <= min(N - K, 16 * c1 + 15); c9 += 1)
        for (c11 = 16 * c3; c11 <= min(N - K, 16 * c3 + 15); c11 += 1) {
          if (K <= 16)
            sum[c9][c11]=0;
          output_image[c9+dead_rows][c11+dead_cols]=(sum[c9][c11]/normal_factor];
        }
    } else
      for (c9 = 16 * c1; c9 <= min(N - K, 16 * c1 + 15); c9 += 1)
        for (c11 = 16 * c3; c11 <= min(N - K, 16 * c3 + 15); c11 += 1)
          sum[c9][c11]=0;
    for (c5 = 0; c5 <= floord(K - 1, 16); c5 += 1)
      for (c7 = 0; c7 <= (K - 1) / 16; c7 += 1)
        for (c9 = 16 * c1; c9 <= min(N - K, 16 * c1 + 15); c9 += 1)
          for (c11 = 16 * c3; c11 <= min(N - K, 16 * c3 + 15); c11 += 1) {
            if (K >= 16 * c7 + 17) {
              for (c15 = 16 * c7; c15 <= 16 * c7 + 15; c15 += 1)
                sum[c9][c11]+=input_image[c9+16*c5][c11+c15]*kernel[16*c5][c15];
            } else
              for (c13 = 16 * c5; c13 <= min(K - 1, 16 * c5 + 15); c13 += 1) {
                if (c13 >= 16 * c5 + 1)
                  for (c15 = 0; c15 < 16 * c7; c15 += 1)
                    sum[c9][c11]+=input_image[c9+c13][c11+c15]*kernel[c13][c15];
                for (c15 = 16 * c7; c15 < K; c15 += 1)
                  sum[c9][c11]+=input_image[c9+c13][c11+c15]*kernel[c13][c15];
              }
          }
  }



}



    double end = omp_get_wtime();
	printf("%.3f\n", end - start);
	printf("%i\n", z);

    if(kind != 1){
        for (k = 0; k < N; k++)
        {
          for(i = 0; i < N; i++)
            for (j = 0; j < N; j++){
              path1[i][j] = path1[i][j] < path1[i][k] + path1[k][j] ? path1[i][j] : path1[i][k] + path1[k][j];

              }
        }

        for (k = 0; k < N; k++)
        {
          for(i = 0; i < N; i++)
            for (j = 0; j < N; j++){
              if(path1[i][j] != path[i][j])
                printf("Error!\n");
                exit(0);
              }
        }
    }


	// Clean-up and exit the function
	fflush(stdout);
	return 0;
}
