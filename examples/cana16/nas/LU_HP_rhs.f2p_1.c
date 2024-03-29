#include<omp.h>
#include<stdlib.h>
#include<stdio.h>

#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

int N = 50;
int N1, N2, N3, N4, DIM;
int DIM1;
int DIM2;
int DIM3;

#define TILE_SIZE 5





void seq(float rsd[6][DIM1][DIM2][DIM3], float u[6][DIM1][DIM2][DIM3], float rho_i[DIM1][DIM2][DIM3], float qs[DIM1][DIM2][DIM3], float frct[6][DIM1][DIM2][DIM3]) {
int k, m, i, j,tmp;

   for(k = 1; k <= N1; k += 1)
      for(j = 1; j <= N2; j += 1)
         for(i = 1; i <= N3; i += 1) {
            for(m = 1; m <= 5; m += 1)
               rsd[m][i][j][k] = -frct[m][i][j][k];
            tmp = 1.0/u[1][i][j][k];
            rho_i[i][j][k] = tmp;
            qs[i][j][k] = 0.5*(u[2][i][j][k]*u[2][i][j][k]+u[3][i][j][k]*u[3][i][j][k]+u[4][i][j][k]*u[4][i][j][k])*tmp;
         }
}


void comp(float rsd[6][DIM1][DIM2][DIM3], float u[6][DIM1][DIM2][DIM3], float rho_i[DIM1][DIM2][DIM3], float qs[DIM1][DIM2][DIM3], float frct[6][DIM1][DIM2][DIM3]) {
int k, m, i, j,tmp;

#pragma omp parallel for private(k,i,j,m, tmp)
   for(k = 1; k <= N1; k += 1)
      for(j = 1; j <= N2; j += 1)
         for(i = 1; i <= N3; i += 1) {
            for(m = 1; m <= 5; m += 1)
               rsd[m][i][j][k] = -frct[m][i][j][k];
            tmp = 1.0/u[1][i][j][k];
            rho_i[i][j][k] = tmp;
            qs[i][j][k] = 0.5*(u[2][i][j][k]*u[2][i][j][k]+u[3][i][j][k]*u[3][i][j][k]+u[4][i][j][k]*u[4][i][j][k])*tmp;
         }
}


void comp_tile(float rsd[6][DIM1][DIM2][DIM3], float u[6][DIM1][DIM2][DIM3], float rho_i[DIM1][DIM2][DIM3], float qs[DIM1][DIM2][DIM3], float frct[6][DIM1][DIM2][DIM3]) {
int k, m, i, j,tmp,k_tile;

#pragma omp parallel for private(k,i,j,m, tmp)
   for(k_tile=0;k_tile<=(int)floord(N1,TILE_SIZE);k_tile++)
            for(j = 1; j <= N2; j += 1)
                  for(i = 1; i <= N3; i += 1) {
 for(k=max(1,k_tile* TILE_SIZE);k<=min(N1,TILE_SIZE*k_tile+TILE_SIZE-1);k++){
                        for(m = 1; m <= 5; m += 1)
               rsd[m][i][j][k] = -frct[m][i][j][k];
            tmp = 1.0/u[1][i][j][k];
            rho_i[i][j][k] = tmp;
            qs[i][j][k] = 0.5*(u[2][i][j][k]*u[2][i][j][k]+u[3][i][j][k]*u[3][i][j][k]+u[4][i][j][k]*u[4][i][j][k])*tmp;
         }
}

}





int main(int argc, char *argv[]) {

  // number of processors
  int num_proc=1;
  num_proc = atoi(argv[1]);

  if(argc > 2)
    N = atoi(argv[2]);

  N1 = N2 = N3 = N;
  DIM = DIM1 = DIM2 = DIM3 = N+2;

  float (*frct)[6][DIM2][DIM3], (*rsd)[6][DIM2][DIM3], (*u)[6][DIM2][DIM3], (*qs)[DIM2][DIM3], (*rho_i)[DIM2][DIM3];
  rho_i = (float (*)[DIM2][DIM3])malloc(DIM1 * DIM2 * DIM3 * sizeof(float));
  qs = (float (*)[DIM2][DIM3])malloc(DIM1 * DIM2 * DIM3 * sizeof(float));
  u = (float (*)[DIM1][DIM2][DIM3])malloc(DIM1 * DIM2 * DIM3 * 6 * sizeof(float));
  rsd = (float (*)[DIM1][DIM2][DIM3])malloc(DIM1 * DIM2 * DIM3 * 6 * sizeof(float));
  frct = (float (*)[DIM1][DIM2][DIM3])malloc(DIM1 * DIM2 * DIM3 * 6 * sizeof(float));

  // variables to meassure time
  struct timeval s1, f1;
  double  duration, duration1;

  printf("Ilosc procesorow: %i \n\n", num_proc);
  omp_set_num_threads(num_proc);

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // PETLA SEKWENCYJNA

  gettimeofday(&s1, NULL);

  if(num_proc == 1)
    comp_tile(rsd, u, rho_i, qs, frct);
  else
    comp(rsd, u, rho_i, qs, frct);

  gettimeofday(&f1, NULL);

  // -----------------------------------
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  duration = (double)f1.tv_sec + ((double)f1.tv_usec/1000000) - ((double)s1.tv_sec + ((double)s1.tv_usec/1000000));
  printf("Czas: %2.3f seconds\n", duration);

  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





}



