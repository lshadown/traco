#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define MAX(x,y)    ((x) > (y)? (x) : (y))


#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

int N = 20;

int can_pair(int *input, int a, int b){
   return ((((input[a] + input[b]) == 3) && (a < b - 1))) ? 1 : 0;
}

int main(int argc, char *argv[])
{
    int num_proc=1;
    num_proc = atoi(argv[1]);
    int kind;

    if(argc > 2)
        N = atoi(argv[2]);

    int DIM = 2*N+2;

    if(argc > 3)
        kind = atoi(argv[3]);

    int i,j,k,c0,c1;
    double start, end;


    float (*S)[DIM];
    S = (float (*)[DIM])malloc(DIM * DIM * sizeof(float));
    int *RNA;
    RNA = (int (*))malloc(DIM * sizeof(float));


    start = omp_get_wtime();

#pragma parallel shared(S,RNA)
{
#pragma omp for
  for (c0 = 0; c0 <= 498; c0 += 1)
    S[c0][c0+1] = MAX(S[c0][c0+1], S[c0+1][c0+1-1] + can_pair(RNA, c0, c0+1));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 497; c0 += 1)
    for (c1 = c0 + 2; c1 <= min(c0 + 3, 499); c1 += 1) {
      if (c1 == c0 + 2)
        S[c0][c0+2] = MAX(S[c0][0+c0] + S[0+c0+1][c0+2], S[c0][c0+2]);
      S[c0][c1] = MAX(S[c0][1+c0] + S[1+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 497; c0 += 1)
    S[c0][c0+2] = MAX(S[c0][c0+2], S[c0+1][c0+2-1] + can_pair(RNA, c0, c0+2));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 496; c0 += 1)
    for (c1 = c0 + 3; c1 <= min(c0 + 5, 499); c1 += 1) {
      if (c0 + 4 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-3+c0] + S[-c0+c1-3+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][2+c0] + S[2+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 496; c0 += 1)
    S[c0][c0+3] = MAX(S[c0][c0+3], S[c0+1][c0+3-1] + can_pair(RNA, c0, c0+3));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 495; c0 += 1)
    for (c1 = c0 + 4; c1 <= min(c0 + 7, 499); c1 += 1) {
      if (c0 + 6 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-4+c0] + S[-c0+c1-4+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][3+c0] + S[3+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 495; c0 += 1)
    S[c0][c0+4] = MAX(S[c0][c0+4], S[c0+1][c0+4-1] + can_pair(RNA, c0, c0+4));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 494; c0 += 1)
    for (c1 = c0 + 5; c1 <= min(c0 + 9, 499); c1 += 1) {
      if (c0 + 8 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-5+c0] + S[-c0+c1-5+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][4+c0] + S[4+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 494; c0 += 1)
    S[c0][c0+5] = MAX(S[c0][c0+5], S[c0+1][c0+5-1] + can_pair(RNA, c0, c0+5));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 493; c0 += 1)
    for (c1 = c0 + 6; c1 <= min(c0 + 11, 499); c1 += 1) {
      if (c0 + 10 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-6+c0] + S[-c0+c1-6+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][5+c0] + S[5+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 493; c0 += 1)
    S[c0][c0+6] = MAX(S[c0][c0+6], S[c0+1][c0+6-1] + can_pair(RNA, c0, c0+6));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 492; c0 += 1)
    for (c1 = c0 + 7; c1 <= min(c0 + 13, 499); c1 += 1) {
      if (c0 + 12 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-7+c0] + S[-c0+c1-7+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][6+c0] + S[6+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 492; c0 += 1)
    S[c0][c0+7] = MAX(S[c0][c0+7], S[c0+1][c0+7-1] + can_pair(RNA, c0, c0+7));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 491; c0 += 1)
    for (c1 = c0 + 8; c1 <= min(c0 + 15, 499); c1 += 1) {
      if (c0 + 14 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-8+c0] + S[-c0+c1-8+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][7+c0] + S[7+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 491; c0 += 1)
    S[c0][c0+8] = MAX(S[c0][c0+8], S[c0+1][c0+8-1] + can_pair(RNA, c0, c0+8));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 490; c0 += 1)
    for (c1 = c0 + 9; c1 <= min(c0 + 17, 499); c1 += 1) {
      if (c0 + 16 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-9+c0] + S[-c0+c1-9+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][8+c0] + S[8+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 490; c0 += 1)
    S[c0][c0+9] = MAX(S[c0][c0+9], S[c0+1][c0+9-1] + can_pair(RNA, c0, c0+9));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 489; c0 += 1)
    for (c1 = c0 + 10; c1 <= min(c0 + 19, 499); c1 += 1) {
      if (c0 + 18 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-10+c0] + S[-c0+c1-10+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][9+c0] + S[9+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 489; c0 += 1)
    S[c0][c0+10] = MAX(S[c0][c0+10], S[c0+1][c0+10-1] + can_pair(RNA, c0, c0+10));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 488; c0 += 1)
    for (c1 = c0 + 11; c1 <= min(c0 + 21, 499); c1 += 1) {
      if (c0 + 20 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-11+c0] + S[-c0+c1-11+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][10+c0] + S[10+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 488; c0 += 1)
    S[c0][c0+11] = MAX(S[c0][c0+11], S[c0+1][c0+11-1] + can_pair(RNA, c0, c0+11));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 487; c0 += 1)
    for (c1 = c0 + 12; c1 <= min(c0 + 23, 499); c1 += 1) {
      if (c0 + 22 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-12+c0] + S[-c0+c1-12+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][11+c0] + S[11+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 487; c0 += 1)
    S[c0][c0+12] = MAX(S[c0][c0+12], S[c0+1][c0+12-1] + can_pair(RNA, c0, c0+12));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 486; c0 += 1)
    for (c1 = c0 + 13; c1 <= min(c0 + 25, 499); c1 += 1) {
      if (c0 + 24 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-13+c0] + S[-c0+c1-13+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][12+c0] + S[12+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 486; c0 += 1)
    S[c0][c0+13] = MAX(S[c0][c0+13], S[c0+1][c0+13-1] + can_pair(RNA, c0, c0+13));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 485; c0 += 1)
    for (c1 = c0 + 14; c1 <= min(c0 + 27, 499); c1 += 1) {
      if (c0 + 26 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-14+c0] + S[-c0+c1-14+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][13+c0] + S[13+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 485; c0 += 1)
    S[c0][c0+14] = MAX(S[c0][c0+14], S[c0+1][c0+14-1] + can_pair(RNA, c0, c0+14));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 484; c0 += 1)
    for (c1 = c0 + 15; c1 <= min(c0 + 29, 499); c1 += 1) {
      if (c0 + 28 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-15+c0] + S[-c0+c1-15+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][14+c0] + S[14+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 484; c0 += 1)
    S[c0][c0+15] = MAX(S[c0][c0+15], S[c0+1][c0+15-1] + can_pair(RNA, c0, c0+15));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 483; c0 += 1)
    for (c1 = c0 + 16; c1 <= min(c0 + 31, 499); c1 += 1) {
      if (c0 + 30 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-16+c0] + S[-c0+c1-16+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][15+c0] + S[15+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 483; c0 += 1)
    S[c0][c0+16] = MAX(S[c0][c0+16], S[c0+1][c0+16-1] + can_pair(RNA, c0, c0+16));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 482; c0 += 1)
    for (c1 = c0 + 17; c1 <= min(c0 + 33, 499); c1 += 1) {
      if (c0 + 32 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-17+c0] + S[-c0+c1-17+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][16+c0] + S[16+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 482; c0 += 1)
    S[c0][c0+17] = MAX(S[c0][c0+17], S[c0+1][c0+17-1] + can_pair(RNA, c0, c0+17));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 481; c0 += 1)
    for (c1 = c0 + 18; c1 <= min(c0 + 35, 499); c1 += 1) {
      if (c0 + 34 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-18+c0] + S[-c0+c1-18+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][17+c0] + S[17+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 481; c0 += 1)
    S[c0][c0+18] = MAX(S[c0][c0+18], S[c0+1][c0+18-1] + can_pair(RNA, c0, c0+18));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 480; c0 += 1)
    for (c1 = c0 + 19; c1 <= min(c0 + 37, 499); c1 += 1) {
      if (c0 + 36 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-19+c0] + S[-c0+c1-19+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][18+c0] + S[18+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 480; c0 += 1)
    S[c0][c0+19] = MAX(S[c0][c0+19], S[c0+1][c0+19-1] + can_pair(RNA, c0, c0+19));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 479; c0 += 1)
    for (c1 = c0 + 20; c1 <= min(c0 + 39, 499); c1 += 1) {
      if (c0 + 38 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-20+c0] + S[-c0+c1-20+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][19+c0] + S[19+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 479; c0 += 1)
    S[c0][c0+20] = MAX(S[c0][c0+20], S[c0+1][c0+20-1] + can_pair(RNA, c0, c0+20));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 478; c0 += 1)
    for (c1 = c0 + 21; c1 <= min(c0 + 41, 499); c1 += 1) {
      if (c0 + 40 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-21+c0] + S[-c0+c1-21+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][20+c0] + S[20+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 478; c0 += 1)
    S[c0][c0+21] = MAX(S[c0][c0+21], S[c0+1][c0+21-1] + can_pair(RNA, c0, c0+21));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 477; c0 += 1)
    for (c1 = c0 + 22; c1 <= min(c0 + 43, 499); c1 += 1) {
      if (c0 + 42 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-22+c0] + S[-c0+c1-22+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][21+c0] + S[21+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 477; c0 += 1)
    S[c0][c0+22] = MAX(S[c0][c0+22], S[c0+1][c0+22-1] + can_pair(RNA, c0, c0+22));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 476; c0 += 1)
    for (c1 = c0 + 23; c1 <= min(c0 + 45, 499); c1 += 1) {
      if (c0 + 44 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-23+c0] + S[-c0+c1-23+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][22+c0] + S[22+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 476; c0 += 1)
    S[c0][c0+23] = MAX(S[c0][c0+23], S[c0+1][c0+23-1] + can_pair(RNA, c0, c0+23));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 475; c0 += 1)
    for (c1 = c0 + 24; c1 <= min(c0 + 47, 499); c1 += 1) {
      if (c0 + 46 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-24+c0] + S[-c0+c1-24+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][23+c0] + S[23+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 475; c0 += 1)
    S[c0][c0+24] = MAX(S[c0][c0+24], S[c0+1][c0+24-1] + can_pair(RNA, c0, c0+24));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 474; c0 += 1)
    for (c1 = c0 + 25; c1 <= min(c0 + 49, 499); c1 += 1) {
      if (c0 + 48 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-25+c0] + S[-c0+c1-25+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][24+c0] + S[24+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 474; c0 += 1)
    S[c0][c0+25] = MAX(S[c0][c0+25], S[c0+1][c0+25-1] + can_pair(RNA, c0, c0+25));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 473; c0 += 1)
    for (c1 = c0 + 26; c1 <= min(c0 + 51, 499); c1 += 1) {
      if (c0 + 50 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-26+c0] + S[-c0+c1-26+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][25+c0] + S[25+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 473; c0 += 1)
    S[c0][c0+26] = MAX(S[c0][c0+26], S[c0+1][c0+26-1] + can_pair(RNA, c0, c0+26));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 472; c0 += 1)
    for (c1 = c0 + 27; c1 <= min(c0 + 53, 499); c1 += 1) {
      if (c0 + 52 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-27+c0] + S[-c0+c1-27+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][26+c0] + S[26+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 472; c0 += 1)
    S[c0][c0+27] = MAX(S[c0][c0+27], S[c0+1][c0+27-1] + can_pair(RNA, c0, c0+27));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 471; c0 += 1)
    for (c1 = c0 + 28; c1 <= min(c0 + 55, 499); c1 += 1) {
      if (c0 + 54 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-28+c0] + S[-c0+c1-28+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][27+c0] + S[27+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 471; c0 += 1)
    S[c0][c0+28] = MAX(S[c0][c0+28], S[c0+1][c0+28-1] + can_pair(RNA, c0, c0+28));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 470; c0 += 1)
    for (c1 = c0 + 29; c1 <= min(c0 + 57, 499); c1 += 1) {
      if (c0 + 56 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-29+c0] + S[-c0+c1-29+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][28+c0] + S[28+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 470; c0 += 1)
    S[c0][c0+29] = MAX(S[c0][c0+29], S[c0+1][c0+29-1] + can_pair(RNA, c0, c0+29));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 469; c0 += 1)
    for (c1 = c0 + 30; c1 <= min(c0 + 59, 499); c1 += 1) {
      if (c0 + 58 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-30+c0] + S[-c0+c1-30+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][29+c0] + S[29+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 469; c0 += 1)
    S[c0][c0+30] = MAX(S[c0][c0+30], S[c0+1][c0+30-1] + can_pair(RNA, c0, c0+30));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 468; c0 += 1)
    for (c1 = c0 + 31; c1 <= min(c0 + 61, 499); c1 += 1) {
      if (c0 + 60 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-31+c0] + S[-c0+c1-31+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][30+c0] + S[30+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 468; c0 += 1)
    S[c0][c0+31] = MAX(S[c0][c0+31], S[c0+1][c0+31-1] + can_pair(RNA, c0, c0+31));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 467; c0 += 1)
    for (c1 = c0 + 32; c1 <= min(c0 + 63, 499); c1 += 1) {
      if (c0 + 62 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-32+c0] + S[-c0+c1-32+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][31+c0] + S[31+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 467; c0 += 1)
    S[c0][c0+32] = MAX(S[c0][c0+32], S[c0+1][c0+32-1] + can_pair(RNA, c0, c0+32));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 466; c0 += 1)
    for (c1 = c0 + 33; c1 <= min(c0 + 65, 499); c1 += 1) {
      if (c0 + 64 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-33+c0] + S[-c0+c1-33+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][32+c0] + S[32+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 466; c0 += 1)
    S[c0][c0+33] = MAX(S[c0][c0+33], S[c0+1][c0+33-1] + can_pair(RNA, c0, c0+33));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 465; c0 += 1)
    for (c1 = c0 + 34; c1 <= min(c0 + 67, 499); c1 += 1) {
      if (c0 + 66 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-34+c0] + S[-c0+c1-34+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][33+c0] + S[33+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 465; c0 += 1)
    S[c0][c0+34] = MAX(S[c0][c0+34], S[c0+1][c0+34-1] + can_pair(RNA, c0, c0+34));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 464; c0 += 1)
    for (c1 = c0 + 35; c1 <= min(c0 + 69, 499); c1 += 1) {
      if (c0 + 68 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-35+c0] + S[-c0+c1-35+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][34+c0] + S[34+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 464; c0 += 1)
    S[c0][c0+35] = MAX(S[c0][c0+35], S[c0+1][c0+35-1] + can_pair(RNA, c0, c0+35));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 463; c0 += 1)
    for (c1 = c0 + 36; c1 <= min(c0 + 71, 499); c1 += 1) {
      if (c0 + 70 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-36+c0] + S[-c0+c1-36+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][35+c0] + S[35+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 463; c0 += 1)
    S[c0][c0+36] = MAX(S[c0][c0+36], S[c0+1][c0+36-1] + can_pair(RNA, c0, c0+36));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 462; c0 += 1)
    for (c1 = c0 + 37; c1 <= min(c0 + 73, 499); c1 += 1) {
      if (c0 + 72 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-37+c0] + S[-c0+c1-37+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][36+c0] + S[36+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 462; c0 += 1)
    S[c0][c0+37] = MAX(S[c0][c0+37], S[c0+1][c0+37-1] + can_pair(RNA, c0, c0+37));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 461; c0 += 1)
    for (c1 = c0 + 38; c1 <= min(c0 + 75, 499); c1 += 1) {
      if (c0 + 74 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-38+c0] + S[-c0+c1-38+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][37+c0] + S[37+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 461; c0 += 1)
    S[c0][c0+38] = MAX(S[c0][c0+38], S[c0+1][c0+38-1] + can_pair(RNA, c0, c0+38));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 460; c0 += 1)
    for (c1 = c0 + 39; c1 <= min(c0 + 77, 499); c1 += 1) {
      if (c0 + 76 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-39+c0] + S[-c0+c1-39+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][38+c0] + S[38+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 460; c0 += 1)
    S[c0][c0+39] = MAX(S[c0][c0+39], S[c0+1][c0+39-1] + can_pair(RNA, c0, c0+39));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 459; c0 += 1)
    for (c1 = c0 + 40; c1 <= min(c0 + 79, 499); c1 += 1) {
      if (c0 + 78 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-40+c0] + S[-c0+c1-40+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][39+c0] + S[39+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 459; c0 += 1)
    S[c0][c0+40] = MAX(S[c0][c0+40], S[c0+1][c0+40-1] + can_pair(RNA, c0, c0+40));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 458; c0 += 1)
    for (c1 = c0 + 41; c1 <= min(c0 + 81, 499); c1 += 1) {
      if (c0 + 80 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-41+c0] + S[-c0+c1-41+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][40+c0] + S[40+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 458; c0 += 1)
    S[c0][c0+41] = MAX(S[c0][c0+41], S[c0+1][c0+41-1] + can_pair(RNA, c0, c0+41));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 457; c0 += 1)
    for (c1 = c0 + 42; c1 <= min(c0 + 83, 499); c1 += 1) {
      if (c0 + 82 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-42+c0] + S[-c0+c1-42+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][41+c0] + S[41+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 457; c0 += 1)
    S[c0][c0+42] = MAX(S[c0][c0+42], S[c0+1][c0+42-1] + can_pair(RNA, c0, c0+42));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 456; c0 += 1)
    for (c1 = c0 + 43; c1 <= min(c0 + 85, 499); c1 += 1) {
      if (c0 + 84 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-43+c0] + S[-c0+c1-43+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][42+c0] + S[42+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 456; c0 += 1)
    S[c0][c0+43] = MAX(S[c0][c0+43], S[c0+1][c0+43-1] + can_pair(RNA, c0, c0+43));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 455; c0 += 1)
    for (c1 = c0 + 44; c1 <= min(c0 + 87, 499); c1 += 1) {
      if (c0 + 86 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-44+c0] + S[-c0+c1-44+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][43+c0] + S[43+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 455; c0 += 1)
    S[c0][c0+44] = MAX(S[c0][c0+44], S[c0+1][c0+44-1] + can_pair(RNA, c0, c0+44));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 454; c0 += 1)
    for (c1 = c0 + 45; c1 <= min(c0 + 89, 499); c1 += 1) {
      if (c0 + 88 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-45+c0] + S[-c0+c1-45+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][44+c0] + S[44+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 454; c0 += 1)
    S[c0][c0+45] = MAX(S[c0][c0+45], S[c0+1][c0+45-1] + can_pair(RNA, c0, c0+45));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 453; c0 += 1)
    for (c1 = c0 + 46; c1 <= min(c0 + 91, 499); c1 += 1) {
      if (c0 + 90 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-46+c0] + S[-c0+c1-46+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][45+c0] + S[45+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 453; c0 += 1)
    S[c0][c0+46] = MAX(S[c0][c0+46], S[c0+1][c0+46-1] + can_pair(RNA, c0, c0+46));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 452; c0 += 1)
    for (c1 = c0 + 47; c1 <= min(c0 + 93, 499); c1 += 1) {
      if (c0 + 92 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-47+c0] + S[-c0+c1-47+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][46+c0] + S[46+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 452; c0 += 1)
    S[c0][c0+47] = MAX(S[c0][c0+47], S[c0+1][c0+47-1] + can_pair(RNA, c0, c0+47));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 451; c0 += 1)
    for (c1 = c0 + 48; c1 <= min(c0 + 95, 499); c1 += 1) {
      if (c0 + 94 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-48+c0] + S[-c0+c1-48+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][47+c0] + S[47+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 451; c0 += 1)
    S[c0][c0+48] = MAX(S[c0][c0+48], S[c0+1][c0+48-1] + can_pair(RNA, c0, c0+48));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 450; c0 += 1)
    for (c1 = c0 + 49; c1 <= min(c0 + 97, 499); c1 += 1) {
      if (c0 + 96 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-49+c0] + S[-c0+c1-49+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][48+c0] + S[48+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 450; c0 += 1)
    S[c0][c0+49] = MAX(S[c0][c0+49], S[c0+1][c0+49-1] + can_pair(RNA, c0, c0+49));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 449; c0 += 1)
    for (c1 = c0 + 50; c1 <= min(c0 + 99, 499); c1 += 1) {
      if (c0 + 98 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-50+c0] + S[-c0+c1-50+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][49+c0] + S[49+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 449; c0 += 1)
    S[c0][c0+50] = MAX(S[c0][c0+50], S[c0+1][c0+50-1] + can_pair(RNA, c0, c0+50));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 448; c0 += 1)
    for (c1 = c0 + 51; c1 <= min(c0 + 101, 499); c1 += 1) {
      if (c0 + 100 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-51+c0] + S[-c0+c1-51+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][50+c0] + S[50+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 448; c0 += 1)
    S[c0][c0+51] = MAX(S[c0][c0+51], S[c0+1][c0+51-1] + can_pair(RNA, c0, c0+51));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 447; c0 += 1)
    for (c1 = c0 + 52; c1 <= min(c0 + 103, 499); c1 += 1) {
      if (c0 + 102 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-52+c0] + S[-c0+c1-52+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][51+c0] + S[51+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 447; c0 += 1)
    S[c0][c0+52] = MAX(S[c0][c0+52], S[c0+1][c0+52-1] + can_pair(RNA, c0, c0+52));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 446; c0 += 1)
    for (c1 = c0 + 53; c1 <= min(c0 + 105, 499); c1 += 1) {
      if (c0 + 104 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-53+c0] + S[-c0+c1-53+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][52+c0] + S[52+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 446; c0 += 1)
    S[c0][c0+53] = MAX(S[c0][c0+53], S[c0+1][c0+53-1] + can_pair(RNA, c0, c0+53));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 445; c0 += 1)
    for (c1 = c0 + 54; c1 <= min(c0 + 107, 499); c1 += 1) {
      if (c0 + 106 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-54+c0] + S[-c0+c1-54+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][53+c0] + S[53+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 445; c0 += 1)
    S[c0][c0+54] = MAX(S[c0][c0+54], S[c0+1][c0+54-1] + can_pair(RNA, c0, c0+54));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 444; c0 += 1)
    for (c1 = c0 + 55; c1 <= min(c0 + 109, 499); c1 += 1) {
      if (c0 + 108 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-55+c0] + S[-c0+c1-55+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][54+c0] + S[54+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 444; c0 += 1)
    S[c0][c0+55] = MAX(S[c0][c0+55], S[c0+1][c0+55-1] + can_pair(RNA, c0, c0+55));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 443; c0 += 1)
    for (c1 = c0 + 56; c1 <= min(c0 + 111, 499); c1 += 1) {
      if (c0 + 110 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-56+c0] + S[-c0+c1-56+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][55+c0] + S[55+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 443; c0 += 1)
    S[c0][c0+56] = MAX(S[c0][c0+56], S[c0+1][c0+56-1] + can_pair(RNA, c0, c0+56));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 442; c0 += 1)
    for (c1 = c0 + 57; c1 <= min(c0 + 113, 499); c1 += 1) {
      if (c0 + 112 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-57+c0] + S[-c0+c1-57+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][56+c0] + S[56+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 442; c0 += 1)
    S[c0][c0+57] = MAX(S[c0][c0+57], S[c0+1][c0+57-1] + can_pair(RNA, c0, c0+57));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 441; c0 += 1)
    for (c1 = c0 + 58; c1 <= min(c0 + 115, 499); c1 += 1) {
      if (c0 + 114 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-58+c0] + S[-c0+c1-58+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][57+c0] + S[57+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 441; c0 += 1)
    S[c0][c0+58] = MAX(S[c0][c0+58], S[c0+1][c0+58-1] + can_pair(RNA, c0, c0+58));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 440; c0 += 1)
    for (c1 = c0 + 59; c1 <= min(c0 + 117, 499); c1 += 1) {
      if (c0 + 116 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-59+c0] + S[-c0+c1-59+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][58+c0] + S[58+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 440; c0 += 1)
    S[c0][c0+59] = MAX(S[c0][c0+59], S[c0+1][c0+59-1] + can_pair(RNA, c0, c0+59));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 439; c0 += 1)
    for (c1 = c0 + 60; c1 <= min(c0 + 119, 499); c1 += 1) {
      if (c0 + 118 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-60+c0] + S[-c0+c1-60+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][59+c0] + S[59+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 439; c0 += 1)
    S[c0][c0+60] = MAX(S[c0][c0+60], S[c0+1][c0+60-1] + can_pair(RNA, c0, c0+60));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 438; c0 += 1)
    for (c1 = c0 + 61; c1 <= min(c0 + 121, 499); c1 += 1) {
      if (c0 + 120 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-61+c0] + S[-c0+c1-61+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][60+c0] + S[60+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 438; c0 += 1)
    S[c0][c0+61] = MAX(S[c0][c0+61], S[c0+1][c0+61-1] + can_pair(RNA, c0, c0+61));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 437; c0 += 1)
    for (c1 = c0 + 62; c1 <= min(c0 + 123, 499); c1 += 1) {
      if (c0 + 122 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-62+c0] + S[-c0+c1-62+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][61+c0] + S[61+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 437; c0 += 1)
    S[c0][c0+62] = MAX(S[c0][c0+62], S[c0+1][c0+62-1] + can_pair(RNA, c0, c0+62));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 436; c0 += 1)
    for (c1 = c0 + 63; c1 <= min(c0 + 125, 499); c1 += 1) {
      if (c0 + 124 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-63+c0] + S[-c0+c1-63+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][62+c0] + S[62+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 436; c0 += 1)
    S[c0][c0+63] = MAX(S[c0][c0+63], S[c0+1][c0+63-1] + can_pair(RNA, c0, c0+63));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 435; c0 += 1)
    for (c1 = c0 + 64; c1 <= min(c0 + 127, 499); c1 += 1) {
      if (c0 + 126 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-64+c0] + S[-c0+c1-64+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][63+c0] + S[63+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 435; c0 += 1)
    S[c0][c0+64] = MAX(S[c0][c0+64], S[c0+1][c0+64-1] + can_pair(RNA, c0, c0+64));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 434; c0 += 1)
    for (c1 = c0 + 65; c1 <= min(c0 + 129, 499); c1 += 1) {
      if (c0 + 128 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-65+c0] + S[-c0+c1-65+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][64+c0] + S[64+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 434; c0 += 1)
    S[c0][c0+65] = MAX(S[c0][c0+65], S[c0+1][c0+65-1] + can_pair(RNA, c0, c0+65));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 433; c0 += 1)
    for (c1 = c0 + 66; c1 <= min(c0 + 131, 499); c1 += 1) {
      if (c0 + 130 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-66+c0] + S[-c0+c1-66+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][65+c0] + S[65+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 433; c0 += 1)
    S[c0][c0+66] = MAX(S[c0][c0+66], S[c0+1][c0+66-1] + can_pair(RNA, c0, c0+66));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 432; c0 += 1)
    for (c1 = c0 + 67; c1 <= min(c0 + 133, 499); c1 += 1) {
      if (c0 + 132 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-67+c0] + S[-c0+c1-67+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][66+c0] + S[66+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 432; c0 += 1)
    S[c0][c0+67] = MAX(S[c0][c0+67], S[c0+1][c0+67-1] + can_pair(RNA, c0, c0+67));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 431; c0 += 1)
    for (c1 = c0 + 68; c1 <= min(c0 + 135, 499); c1 += 1) {
      if (c0 + 134 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-68+c0] + S[-c0+c1-68+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][67+c0] + S[67+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 431; c0 += 1)
    S[c0][c0+68] = MAX(S[c0][c0+68], S[c0+1][c0+68-1] + can_pair(RNA, c0, c0+68));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 430; c0 += 1)
    for (c1 = c0 + 69; c1 <= min(c0 + 137, 499); c1 += 1) {
      if (c0 + 136 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-69+c0] + S[-c0+c1-69+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][68+c0] + S[68+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 430; c0 += 1)
    S[c0][c0+69] = MAX(S[c0][c0+69], S[c0+1][c0+69-1] + can_pair(RNA, c0, c0+69));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 429; c0 += 1)
    for (c1 = c0 + 70; c1 <= min(c0 + 139, 499); c1 += 1) {
      if (c0 + 138 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-70+c0] + S[-c0+c1-70+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][69+c0] + S[69+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 429; c0 += 1)
    S[c0][c0+70] = MAX(S[c0][c0+70], S[c0+1][c0+70-1] + can_pair(RNA, c0, c0+70));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 428; c0 += 1)
    for (c1 = c0 + 71; c1 <= min(c0 + 141, 499); c1 += 1) {
      if (c0 + 140 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-71+c0] + S[-c0+c1-71+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][70+c0] + S[70+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 428; c0 += 1)
    S[c0][c0+71] = MAX(S[c0][c0+71], S[c0+1][c0+71-1] + can_pair(RNA, c0, c0+71));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 427; c0 += 1)
    for (c1 = c0 + 72; c1 <= min(c0 + 143, 499); c1 += 1) {
      if (c0 + 142 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-72+c0] + S[-c0+c1-72+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][71+c0] + S[71+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 427; c0 += 1)
    S[c0][c0+72] = MAX(S[c0][c0+72], S[c0+1][c0+72-1] + can_pair(RNA, c0, c0+72));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 426; c0 += 1)
    for (c1 = c0 + 73; c1 <= min(c0 + 145, 499); c1 += 1) {
      if (c0 + 144 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-73+c0] + S[-c0+c1-73+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][72+c0] + S[72+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 426; c0 += 1)
    S[c0][c0+73] = MAX(S[c0][c0+73], S[c0+1][c0+73-1] + can_pair(RNA, c0, c0+73));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 425; c0 += 1)
    for (c1 = c0 + 74; c1 <= min(c0 + 147, 499); c1 += 1) {
      if (c0 + 146 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-74+c0] + S[-c0+c1-74+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][73+c0] + S[73+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 425; c0 += 1)
    S[c0][c0+74] = MAX(S[c0][c0+74], S[c0+1][c0+74-1] + can_pair(RNA, c0, c0+74));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 424; c0 += 1)
    for (c1 = c0 + 75; c1 <= min(c0 + 149, 499); c1 += 1) {
      if (c0 + 148 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-75+c0] + S[-c0+c1-75+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][74+c0] + S[74+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 424; c0 += 1)
    S[c0][c0+75] = MAX(S[c0][c0+75], S[c0+1][c0+75-1] + can_pair(RNA, c0, c0+75));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 423; c0 += 1)
    for (c1 = c0 + 76; c1 <= min(c0 + 151, 499); c1 += 1) {
      if (c0 + 150 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-76+c0] + S[-c0+c1-76+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][75+c0] + S[75+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 423; c0 += 1)
    S[c0][c0+76] = MAX(S[c0][c0+76], S[c0+1][c0+76-1] + can_pair(RNA, c0, c0+76));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 422; c0 += 1)
    for (c1 = c0 + 77; c1 <= min(c0 + 153, 499); c1 += 1) {
      if (c0 + 152 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-77+c0] + S[-c0+c1-77+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][76+c0] + S[76+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 422; c0 += 1)
    S[c0][c0+77] = MAX(S[c0][c0+77], S[c0+1][c0+77-1] + can_pair(RNA, c0, c0+77));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 421; c0 += 1)
    for (c1 = c0 + 78; c1 <= min(c0 + 155, 499); c1 += 1) {
      if (c0 + 154 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-78+c0] + S[-c0+c1-78+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][77+c0] + S[77+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 421; c0 += 1)
    S[c0][c0+78] = MAX(S[c0][c0+78], S[c0+1][c0+78-1] + can_pair(RNA, c0, c0+78));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 420; c0 += 1)
    for (c1 = c0 + 79; c1 <= min(c0 + 157, 499); c1 += 1) {
      if (c0 + 156 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-79+c0] + S[-c0+c1-79+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][78+c0] + S[78+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 420; c0 += 1)
    S[c0][c0+79] = MAX(S[c0][c0+79], S[c0+1][c0+79-1] + can_pair(RNA, c0, c0+79));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 419; c0 += 1)
    for (c1 = c0 + 80; c1 <= min(c0 + 159, 499); c1 += 1) {
      if (c0 + 158 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-80+c0] + S[-c0+c1-80+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][79+c0] + S[79+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 419; c0 += 1)
    S[c0][c0+80] = MAX(S[c0][c0+80], S[c0+1][c0+80-1] + can_pair(RNA, c0, c0+80));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 418; c0 += 1)
    for (c1 = c0 + 81; c1 <= min(c0 + 161, 499); c1 += 1) {
      if (c0 + 160 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-81+c0] + S[-c0+c1-81+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][80+c0] + S[80+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 418; c0 += 1)
    S[c0][c0+81] = MAX(S[c0][c0+81], S[c0+1][c0+81-1] + can_pair(RNA, c0, c0+81));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 417; c0 += 1)
    for (c1 = c0 + 82; c1 <= min(c0 + 163, 499); c1 += 1) {
      if (c0 + 162 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-82+c0] + S[-c0+c1-82+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][81+c0] + S[81+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 417; c0 += 1)
    S[c0][c0+82] = MAX(S[c0][c0+82], S[c0+1][c0+82-1] + can_pair(RNA, c0, c0+82));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 416; c0 += 1)
    for (c1 = c0 + 83; c1 <= min(c0 + 165, 499); c1 += 1) {
      if (c0 + 164 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-83+c0] + S[-c0+c1-83+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][82+c0] + S[82+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 416; c0 += 1)
    S[c0][c0+83] = MAX(S[c0][c0+83], S[c0+1][c0+83-1] + can_pair(RNA, c0, c0+83));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 415; c0 += 1)
    for (c1 = c0 + 84; c1 <= min(c0 + 167, 499); c1 += 1) {
      if (c0 + 166 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-84+c0] + S[-c0+c1-84+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][83+c0] + S[83+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 415; c0 += 1)
    S[c0][c0+84] = MAX(S[c0][c0+84], S[c0+1][c0+84-1] + can_pair(RNA, c0, c0+84));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 414; c0 += 1)
    for (c1 = c0 + 85; c1 <= min(c0 + 169, 499); c1 += 1) {
      if (c0 + 168 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-85+c0] + S[-c0+c1-85+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][84+c0] + S[84+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 414; c0 += 1)
    S[c0][c0+85] = MAX(S[c0][c0+85], S[c0+1][c0+85-1] + can_pair(RNA, c0, c0+85));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 413; c0 += 1)
    for (c1 = c0 + 86; c1 <= min(c0 + 171, 499); c1 += 1) {
      if (c0 + 170 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-86+c0] + S[-c0+c1-86+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][85+c0] + S[85+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 413; c0 += 1)
    S[c0][c0+86] = MAX(S[c0][c0+86], S[c0+1][c0+86-1] + can_pair(RNA, c0, c0+86));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 412; c0 += 1)
    for (c1 = c0 + 87; c1 <= min(c0 + 173, 499); c1 += 1) {
      if (c0 + 172 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-87+c0] + S[-c0+c1-87+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][86+c0] + S[86+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 412; c0 += 1)
    S[c0][c0+87] = MAX(S[c0][c0+87], S[c0+1][c0+87-1] + can_pair(RNA, c0, c0+87));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 411; c0 += 1)
    for (c1 = c0 + 88; c1 <= min(c0 + 175, 499); c1 += 1) {
      if (c0 + 174 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-88+c0] + S[-c0+c1-88+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][87+c0] + S[87+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 411; c0 += 1)
    S[c0][c0+88] = MAX(S[c0][c0+88], S[c0+1][c0+88-1] + can_pair(RNA, c0, c0+88));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 410; c0 += 1)
    for (c1 = c0 + 89; c1 <= min(c0 + 177, 499); c1 += 1) {
      if (c0 + 176 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-89+c0] + S[-c0+c1-89+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][88+c0] + S[88+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 410; c0 += 1)
    S[c0][c0+89] = MAX(S[c0][c0+89], S[c0+1][c0+89-1] + can_pair(RNA, c0, c0+89));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 409; c0 += 1)
    for (c1 = c0 + 90; c1 <= min(c0 + 179, 499); c1 += 1) {
      if (c0 + 178 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-90+c0] + S[-c0+c1-90+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][89+c0] + S[89+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 409; c0 += 1)
    S[c0][c0+90] = MAX(S[c0][c0+90], S[c0+1][c0+90-1] + can_pair(RNA, c0, c0+90));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 408; c0 += 1)
    for (c1 = c0 + 91; c1 <= min(c0 + 181, 499); c1 += 1) {
      if (c0 + 180 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-91+c0] + S[-c0+c1-91+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][90+c0] + S[90+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 408; c0 += 1)
    S[c0][c0+91] = MAX(S[c0][c0+91], S[c0+1][c0+91-1] + can_pair(RNA, c0, c0+91));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 407; c0 += 1)
    for (c1 = c0 + 92; c1 <= min(c0 + 183, 499); c1 += 1) {
      if (c0 + 182 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-92+c0] + S[-c0+c1-92+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][91+c0] + S[91+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 407; c0 += 1)
    S[c0][c0+92] = MAX(S[c0][c0+92], S[c0+1][c0+92-1] + can_pair(RNA, c0, c0+92));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 406; c0 += 1)
    for (c1 = c0 + 93; c1 <= min(c0 + 185, 499); c1 += 1) {
      if (c0 + 184 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-93+c0] + S[-c0+c1-93+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][92+c0] + S[92+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 406; c0 += 1)
    S[c0][c0+93] = MAX(S[c0][c0+93], S[c0+1][c0+93-1] + can_pair(RNA, c0, c0+93));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 405; c0 += 1)
    for (c1 = c0 + 94; c1 <= min(c0 + 187, 499); c1 += 1) {
      if (c0 + 186 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-94+c0] + S[-c0+c1-94+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][93+c0] + S[93+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 405; c0 += 1)
    S[c0][c0+94] = MAX(S[c0][c0+94], S[c0+1][c0+94-1] + can_pair(RNA, c0, c0+94));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 404; c0 += 1)
    for (c1 = c0 + 95; c1 <= min(c0 + 189, 499); c1 += 1) {
      if (c0 + 188 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-95+c0] + S[-c0+c1-95+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][94+c0] + S[94+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 404; c0 += 1)
    S[c0][c0+95] = MAX(S[c0][c0+95], S[c0+1][c0+95-1] + can_pair(RNA, c0, c0+95));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 403; c0 += 1)
    for (c1 = c0 + 96; c1 <= min(c0 + 191, 499); c1 += 1) {
      if (c0 + 190 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-96+c0] + S[-c0+c1-96+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][95+c0] + S[95+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 403; c0 += 1)
    S[c0][c0+96] = MAX(S[c0][c0+96], S[c0+1][c0+96-1] + can_pair(RNA, c0, c0+96));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 402; c0 += 1)
    for (c1 = c0 + 97; c1 <= min(c0 + 193, 499); c1 += 1) {
      if (c0 + 192 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-97+c0] + S[-c0+c1-97+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][96+c0] + S[96+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 402; c0 += 1)
    S[c0][c0+97] = MAX(S[c0][c0+97], S[c0+1][c0+97-1] + can_pair(RNA, c0, c0+97));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 401; c0 += 1)
    for (c1 = c0 + 98; c1 <= min(c0 + 195, 499); c1 += 1) {
      if (c0 + 194 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-98+c0] + S[-c0+c1-98+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][97+c0] + S[97+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 401; c0 += 1)
    S[c0][c0+98] = MAX(S[c0][c0+98], S[c0+1][c0+98-1] + can_pair(RNA, c0, c0+98));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 400; c0 += 1)
    for (c1 = c0 + 99; c1 <= min(c0 + 197, 499); c1 += 1) {
      if (c0 + 196 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-99+c0] + S[-c0+c1-99+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][98+c0] + S[98+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 400; c0 += 1)
    S[c0][c0+99] = MAX(S[c0][c0+99], S[c0+1][c0+99-1] + can_pair(RNA, c0, c0+99));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 399; c0 += 1)
    for (c1 = c0 + 100; c1 <= min(c0 + 199, 499); c1 += 1) {
      if (c0 + 198 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-100+c0] + S[-c0+c1-100+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][99+c0] + S[99+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 399; c0 += 1)
    S[c0][c0+100] = MAX(S[c0][c0+100], S[c0+1][c0+100-1] + can_pair(RNA, c0, c0+100));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 398; c0 += 1)
    for (c1 = c0 + 101; c1 <= min(c0 + 201, 499); c1 += 1) {
      if (c0 + 200 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-101+c0] + S[-c0+c1-101+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][100+c0] + S[100+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 398; c0 += 1)
    S[c0][c0+101] = MAX(S[c0][c0+101], S[c0+1][c0+101-1] + can_pair(RNA, c0, c0+101));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 397; c0 += 1)
    for (c1 = c0 + 102; c1 <= min(c0 + 203, 499); c1 += 1) {
      if (c0 + 202 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-102+c0] + S[-c0+c1-102+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][101+c0] + S[101+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 397; c0 += 1)
    S[c0][c0+102] = MAX(S[c0][c0+102], S[c0+1][c0+102-1] + can_pair(RNA, c0, c0+102));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 396; c0 += 1)
    for (c1 = c0 + 103; c1 <= min(c0 + 205, 499); c1 += 1) {
      if (c0 + 204 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-103+c0] + S[-c0+c1-103+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][102+c0] + S[102+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 396; c0 += 1)
    S[c0][c0+103] = MAX(S[c0][c0+103], S[c0+1][c0+103-1] + can_pair(RNA, c0, c0+103));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 395; c0 += 1)
    for (c1 = c0 + 104; c1 <= min(c0 + 207, 499); c1 += 1) {
      if (c0 + 206 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-104+c0] + S[-c0+c1-104+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][103+c0] + S[103+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 395; c0 += 1)
    S[c0][c0+104] = MAX(S[c0][c0+104], S[c0+1][c0+104-1] + can_pair(RNA, c0, c0+104));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 394; c0 += 1)
    for (c1 = c0 + 105; c1 <= min(c0 + 209, 499); c1 += 1) {
      if (c0 + 208 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-105+c0] + S[-c0+c1-105+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][104+c0] + S[104+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 394; c0 += 1)
    S[c0][c0+105] = MAX(S[c0][c0+105], S[c0+1][c0+105-1] + can_pair(RNA, c0, c0+105));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 393; c0 += 1)
    for (c1 = c0 + 106; c1 <= min(c0 + 211, 499); c1 += 1) {
      if (c0 + 210 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-106+c0] + S[-c0+c1-106+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][105+c0] + S[105+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 393; c0 += 1)
    S[c0][c0+106] = MAX(S[c0][c0+106], S[c0+1][c0+106-1] + can_pair(RNA, c0, c0+106));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 392; c0 += 1)
    for (c1 = c0 + 107; c1 <= min(c0 + 213, 499); c1 += 1) {
      if (c0 + 212 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-107+c0] + S[-c0+c1-107+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][106+c0] + S[106+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 392; c0 += 1)
    S[c0][c0+107] = MAX(S[c0][c0+107], S[c0+1][c0+107-1] + can_pair(RNA, c0, c0+107));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 391; c0 += 1)
    for (c1 = c0 + 108; c1 <= min(c0 + 215, 499); c1 += 1) {
      if (c0 + 214 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-108+c0] + S[-c0+c1-108+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][107+c0] + S[107+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 391; c0 += 1)
    S[c0][c0+108] = MAX(S[c0][c0+108], S[c0+1][c0+108-1] + can_pair(RNA, c0, c0+108));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 390; c0 += 1)
    for (c1 = c0 + 109; c1 <= min(c0 + 217, 499); c1 += 1) {
      if (c0 + 216 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-109+c0] + S[-c0+c1-109+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][108+c0] + S[108+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 390; c0 += 1)
    S[c0][c0+109] = MAX(S[c0][c0+109], S[c0+1][c0+109-1] + can_pair(RNA, c0, c0+109));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 389; c0 += 1)
    for (c1 = c0 + 110; c1 <= min(c0 + 219, 499); c1 += 1) {
      if (c0 + 218 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-110+c0] + S[-c0+c1-110+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][109+c0] + S[109+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 389; c0 += 1)
    S[c0][c0+110] = MAX(S[c0][c0+110], S[c0+1][c0+110-1] + can_pair(RNA, c0, c0+110));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 388; c0 += 1)
    for (c1 = c0 + 111; c1 <= min(c0 + 221, 499); c1 += 1) {
      if (c0 + 220 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-111+c0] + S[-c0+c1-111+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][110+c0] + S[110+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 388; c0 += 1)
    S[c0][c0+111] = MAX(S[c0][c0+111], S[c0+1][c0+111-1] + can_pair(RNA, c0, c0+111));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 387; c0 += 1)
    for (c1 = c0 + 112; c1 <= min(c0 + 223, 499); c1 += 1) {
      if (c0 + 222 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-112+c0] + S[-c0+c1-112+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][111+c0] + S[111+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 387; c0 += 1)
    S[c0][c0+112] = MAX(S[c0][c0+112], S[c0+1][c0+112-1] + can_pair(RNA, c0, c0+112));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 386; c0 += 1)
    for (c1 = c0 + 113; c1 <= min(c0 + 225, 499); c1 += 1) {
      if (c0 + 224 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-113+c0] + S[-c0+c1-113+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][112+c0] + S[112+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 386; c0 += 1)
    S[c0][c0+113] = MAX(S[c0][c0+113], S[c0+1][c0+113-1] + can_pair(RNA, c0, c0+113));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 385; c0 += 1)
    for (c1 = c0 + 114; c1 <= min(c0 + 227, 499); c1 += 1) {
      if (c0 + 226 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-114+c0] + S[-c0+c1-114+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][113+c0] + S[113+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 385; c0 += 1)
    S[c0][c0+114] = MAX(S[c0][c0+114], S[c0+1][c0+114-1] + can_pair(RNA, c0, c0+114));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 384; c0 += 1)
    for (c1 = c0 + 115; c1 <= min(c0 + 229, 499); c1 += 1) {
      if (c0 + 228 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-115+c0] + S[-c0+c1-115+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][114+c0] + S[114+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 384; c0 += 1)
    S[c0][c0+115] = MAX(S[c0][c0+115], S[c0+1][c0+115-1] + can_pair(RNA, c0, c0+115));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 383; c0 += 1)
    for (c1 = c0 + 116; c1 <= min(c0 + 231, 499); c1 += 1) {
      if (c0 + 230 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-116+c0] + S[-c0+c1-116+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][115+c0] + S[115+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 383; c0 += 1)
    S[c0][c0+116] = MAX(S[c0][c0+116], S[c0+1][c0+116-1] + can_pair(RNA, c0, c0+116));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 382; c0 += 1)
    for (c1 = c0 + 117; c1 <= min(c0 + 233, 499); c1 += 1) {
      if (c0 + 232 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-117+c0] + S[-c0+c1-117+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][116+c0] + S[116+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 382; c0 += 1)
    S[c0][c0+117] = MAX(S[c0][c0+117], S[c0+1][c0+117-1] + can_pair(RNA, c0, c0+117));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 381; c0 += 1)
    for (c1 = c0 + 118; c1 <= min(c0 + 235, 499); c1 += 1) {
      if (c0 + 234 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-118+c0] + S[-c0+c1-118+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][117+c0] + S[117+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 381; c0 += 1)
    S[c0][c0+118] = MAX(S[c0][c0+118], S[c0+1][c0+118-1] + can_pair(RNA, c0, c0+118));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 380; c0 += 1)
    for (c1 = c0 + 119; c1 <= min(c0 + 237, 499); c1 += 1) {
      if (c0 + 236 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-119+c0] + S[-c0+c1-119+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][118+c0] + S[118+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 380; c0 += 1)
    S[c0][c0+119] = MAX(S[c0][c0+119], S[c0+1][c0+119-1] + can_pair(RNA, c0, c0+119));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 379; c0 += 1)
    for (c1 = c0 + 120; c1 <= min(c0 + 239, 499); c1 += 1) {
      if (c0 + 238 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-120+c0] + S[-c0+c1-120+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][119+c0] + S[119+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 379; c0 += 1)
    S[c0][c0+120] = MAX(S[c0][c0+120], S[c0+1][c0+120-1] + can_pair(RNA, c0, c0+120));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 378; c0 += 1)
    for (c1 = c0 + 121; c1 <= min(c0 + 241, 499); c1 += 1) {
      if (c0 + 240 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-121+c0] + S[-c0+c1-121+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][120+c0] + S[120+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 378; c0 += 1)
    S[c0][c0+121] = MAX(S[c0][c0+121], S[c0+1][c0+121-1] + can_pair(RNA, c0, c0+121));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 377; c0 += 1)
    for (c1 = c0 + 122; c1 <= min(c0 + 243, 499); c1 += 1) {
      if (c0 + 242 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-122+c0] + S[-c0+c1-122+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][121+c0] + S[121+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 377; c0 += 1)
    S[c0][c0+122] = MAX(S[c0][c0+122], S[c0+1][c0+122-1] + can_pair(RNA, c0, c0+122));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 376; c0 += 1)
    for (c1 = c0 + 123; c1 <= min(c0 + 245, 499); c1 += 1) {
      if (c0 + 244 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-123+c0] + S[-c0+c1-123+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][122+c0] + S[122+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 376; c0 += 1)
    S[c0][c0+123] = MAX(S[c0][c0+123], S[c0+1][c0+123-1] + can_pair(RNA, c0, c0+123));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 375; c0 += 1)
    for (c1 = c0 + 124; c1 <= min(c0 + 247, 499); c1 += 1) {
      if (c0 + 246 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-124+c0] + S[-c0+c1-124+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][123+c0] + S[123+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 375; c0 += 1)
    S[c0][c0+124] = MAX(S[c0][c0+124], S[c0+1][c0+124-1] + can_pair(RNA, c0, c0+124));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 374; c0 += 1)
    for (c1 = c0 + 125; c1 <= min(c0 + 249, 499); c1 += 1) {
      if (c0 + 248 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-125+c0] + S[-c0+c1-125+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][124+c0] + S[124+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 374; c0 += 1)
    S[c0][c0+125] = MAX(S[c0][c0+125], S[c0+1][c0+125-1] + can_pair(RNA, c0, c0+125));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 373; c0 += 1)
    for (c1 = c0 + 126; c1 <= min(c0 + 251, 499); c1 += 1) {
      if (c0 + 250 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-126+c0] + S[-c0+c1-126+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][125+c0] + S[125+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 373; c0 += 1)
    S[c0][c0+126] = MAX(S[c0][c0+126], S[c0+1][c0+126-1] + can_pair(RNA, c0, c0+126));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 372; c0 += 1)
    for (c1 = c0 + 127; c1 <= min(c0 + 253, 499); c1 += 1) {
      if (c0 + 252 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-127+c0] + S[-c0+c1-127+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][126+c0] + S[126+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 372; c0 += 1)
    S[c0][c0+127] = MAX(S[c0][c0+127], S[c0+1][c0+127-1] + can_pair(RNA, c0, c0+127));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 371; c0 += 1)
    for (c1 = c0 + 128; c1 <= min(c0 + 255, 499); c1 += 1) {
      if (c0 + 254 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-128+c0] + S[-c0+c1-128+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][127+c0] + S[127+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 371; c0 += 1)
    S[c0][c0+128] = MAX(S[c0][c0+128], S[c0+1][c0+128-1] + can_pair(RNA, c0, c0+128));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 370; c0 += 1)
    for (c1 = c0 + 129; c1 <= min(c0 + 257, 499); c1 += 1) {
      if (c0 + 256 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-129+c0] + S[-c0+c1-129+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][128+c0] + S[128+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 370; c0 += 1)
    S[c0][c0+129] = MAX(S[c0][c0+129], S[c0+1][c0+129-1] + can_pair(RNA, c0, c0+129));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 369; c0 += 1)
    for (c1 = c0 + 130; c1 <= min(c0 + 259, 499); c1 += 1) {
      if (c0 + 258 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-130+c0] + S[-c0+c1-130+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][129+c0] + S[129+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 369; c0 += 1)
    S[c0][c0+130] = MAX(S[c0][c0+130], S[c0+1][c0+130-1] + can_pair(RNA, c0, c0+130));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 368; c0 += 1)
    for (c1 = c0 + 131; c1 <= min(c0 + 261, 499); c1 += 1) {
      if (c0 + 260 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-131+c0] + S[-c0+c1-131+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][130+c0] + S[130+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 368; c0 += 1)
    S[c0][c0+131] = MAX(S[c0][c0+131], S[c0+1][c0+131-1] + can_pair(RNA, c0, c0+131));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 367; c0 += 1)
    for (c1 = c0 + 132; c1 <= min(c0 + 263, 499); c1 += 1) {
      if (c0 + 262 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-132+c0] + S[-c0+c1-132+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][131+c0] + S[131+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 367; c0 += 1)
    S[c0][c0+132] = MAX(S[c0][c0+132], S[c0+1][c0+132-1] + can_pair(RNA, c0, c0+132));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 366; c0 += 1)
    for (c1 = c0 + 133; c1 <= min(c0 + 265, 499); c1 += 1) {
      if (c0 + 264 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-133+c0] + S[-c0+c1-133+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][132+c0] + S[132+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 366; c0 += 1)
    S[c0][c0+133] = MAX(S[c0][c0+133], S[c0+1][c0+133-1] + can_pair(RNA, c0, c0+133));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 365; c0 += 1)
    for (c1 = c0 + 134; c1 <= min(c0 + 267, 499); c1 += 1) {
      if (c0 + 266 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-134+c0] + S[-c0+c1-134+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][133+c0] + S[133+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 365; c0 += 1)
    S[c0][c0+134] = MAX(S[c0][c0+134], S[c0+1][c0+134-1] + can_pair(RNA, c0, c0+134));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 364; c0 += 1)
    for (c1 = c0 + 135; c1 <= min(c0 + 269, 499); c1 += 1) {
      if (c0 + 268 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-135+c0] + S[-c0+c1-135+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][134+c0] + S[134+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 364; c0 += 1)
    S[c0][c0+135] = MAX(S[c0][c0+135], S[c0+1][c0+135-1] + can_pair(RNA, c0, c0+135));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 363; c0 += 1)
    for (c1 = c0 + 136; c1 <= min(c0 + 271, 499); c1 += 1) {
      if (c0 + 270 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-136+c0] + S[-c0+c1-136+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][135+c0] + S[135+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 363; c0 += 1)
    S[c0][c0+136] = MAX(S[c0][c0+136], S[c0+1][c0+136-1] + can_pair(RNA, c0, c0+136));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 362; c0 += 1)
    for (c1 = c0 + 137; c1 <= min(c0 + 273, 499); c1 += 1) {
      if (c0 + 272 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-137+c0] + S[-c0+c1-137+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][136+c0] + S[136+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 362; c0 += 1)
    S[c0][c0+137] = MAX(S[c0][c0+137], S[c0+1][c0+137-1] + can_pair(RNA, c0, c0+137));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 361; c0 += 1)
    for (c1 = c0 + 138; c1 <= min(c0 + 275, 499); c1 += 1) {
      if (c0 + 274 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-138+c0] + S[-c0+c1-138+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][137+c0] + S[137+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 361; c0 += 1)
    S[c0][c0+138] = MAX(S[c0][c0+138], S[c0+1][c0+138-1] + can_pair(RNA, c0, c0+138));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 360; c0 += 1)
    for (c1 = c0 + 139; c1 <= min(c0 + 277, 499); c1 += 1) {
      if (c0 + 276 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-139+c0] + S[-c0+c1-139+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][138+c0] + S[138+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 360; c0 += 1)
    S[c0][c0+139] = MAX(S[c0][c0+139], S[c0+1][c0+139-1] + can_pair(RNA, c0, c0+139));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 359; c0 += 1)
    for (c1 = c0 + 140; c1 <= min(c0 + 279, 499); c1 += 1) {
      if (c0 + 278 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-140+c0] + S[-c0+c1-140+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][139+c0] + S[139+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 359; c0 += 1)
    S[c0][c0+140] = MAX(S[c0][c0+140], S[c0+1][c0+140-1] + can_pair(RNA, c0, c0+140));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 358; c0 += 1)
    for (c1 = c0 + 141; c1 <= min(c0 + 281, 499); c1 += 1) {
      if (c0 + 280 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-141+c0] + S[-c0+c1-141+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][140+c0] + S[140+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 358; c0 += 1)
    S[c0][c0+141] = MAX(S[c0][c0+141], S[c0+1][c0+141-1] + can_pair(RNA, c0, c0+141));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 357; c0 += 1)
    for (c1 = c0 + 142; c1 <= min(c0 + 283, 499); c1 += 1) {
      if (c0 + 282 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-142+c0] + S[-c0+c1-142+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][141+c0] + S[141+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 357; c0 += 1)
    S[c0][c0+142] = MAX(S[c0][c0+142], S[c0+1][c0+142-1] + can_pair(RNA, c0, c0+142));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 356; c0 += 1)
    for (c1 = c0 + 143; c1 <= min(c0 + 285, 499); c1 += 1) {
      if (c0 + 284 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-143+c0] + S[-c0+c1-143+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][142+c0] + S[142+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 356; c0 += 1)
    S[c0][c0+143] = MAX(S[c0][c0+143], S[c0+1][c0+143-1] + can_pair(RNA, c0, c0+143));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 355; c0 += 1)
    for (c1 = c0 + 144; c1 <= min(c0 + 287, 499); c1 += 1) {
      if (c0 + 286 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-144+c0] + S[-c0+c1-144+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][143+c0] + S[143+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 355; c0 += 1)
    S[c0][c0+144] = MAX(S[c0][c0+144], S[c0+1][c0+144-1] + can_pair(RNA, c0, c0+144));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 354; c0 += 1)
    for (c1 = c0 + 145; c1 <= min(c0 + 289, 499); c1 += 1) {
      if (c0 + 288 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-145+c0] + S[-c0+c1-145+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][144+c0] + S[144+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 354; c0 += 1)
    S[c0][c0+145] = MAX(S[c0][c0+145], S[c0+1][c0+145-1] + can_pair(RNA, c0, c0+145));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 353; c0 += 1)
    for (c1 = c0 + 146; c1 <= min(c0 + 291, 499); c1 += 1) {
      if (c0 + 290 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-146+c0] + S[-c0+c1-146+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][145+c0] + S[145+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 353; c0 += 1)
    S[c0][c0+146] = MAX(S[c0][c0+146], S[c0+1][c0+146-1] + can_pair(RNA, c0, c0+146));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 352; c0 += 1)
    for (c1 = c0 + 147; c1 <= min(c0 + 293, 499); c1 += 1) {
      if (c0 + 292 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-147+c0] + S[-c0+c1-147+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][146+c0] + S[146+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 352; c0 += 1)
    S[c0][c0+147] = MAX(S[c0][c0+147], S[c0+1][c0+147-1] + can_pair(RNA, c0, c0+147));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 351; c0 += 1)
    for (c1 = c0 + 148; c1 <= min(c0 + 295, 499); c1 += 1) {
      if (c0 + 294 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-148+c0] + S[-c0+c1-148+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][147+c0] + S[147+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 351; c0 += 1)
    S[c0][c0+148] = MAX(S[c0][c0+148], S[c0+1][c0+148-1] + can_pair(RNA, c0, c0+148));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 350; c0 += 1)
    for (c1 = c0 + 149; c1 <= min(c0 + 297, 499); c1 += 1) {
      if (c0 + 296 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-149+c0] + S[-c0+c1-149+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][148+c0] + S[148+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 350; c0 += 1)
    S[c0][c0+149] = MAX(S[c0][c0+149], S[c0+1][c0+149-1] + can_pair(RNA, c0, c0+149));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 349; c0 += 1)
    for (c1 = c0 + 150; c1 <= min(c0 + 299, 499); c1 += 1) {
      if (c0 + 298 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-150+c0] + S[-c0+c1-150+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][149+c0] + S[149+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 349; c0 += 1)
    S[c0][c0+150] = MAX(S[c0][c0+150], S[c0+1][c0+150-1] + can_pair(RNA, c0, c0+150));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 348; c0 += 1)
    for (c1 = c0 + 151; c1 <= min(c0 + 301, 499); c1 += 1) {
      if (c0 + 300 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-151+c0] + S[-c0+c1-151+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][150+c0] + S[150+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 348; c0 += 1)
    S[c0][c0+151] = MAX(S[c0][c0+151], S[c0+1][c0+151-1] + can_pair(RNA, c0, c0+151));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 347; c0 += 1)
    for (c1 = c0 + 152; c1 <= min(c0 + 303, 499); c1 += 1) {
      if (c0 + 302 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-152+c0] + S[-c0+c1-152+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][151+c0] + S[151+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 347; c0 += 1)
    S[c0][c0+152] = MAX(S[c0][c0+152], S[c0+1][c0+152-1] + can_pair(RNA, c0, c0+152));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 346; c0 += 1)
    for (c1 = c0 + 153; c1 <= min(c0 + 305, 499); c1 += 1) {
      if (c0 + 304 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-153+c0] + S[-c0+c1-153+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][152+c0] + S[152+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 346; c0 += 1)
    S[c0][c0+153] = MAX(S[c0][c0+153], S[c0+1][c0+153-1] + can_pair(RNA, c0, c0+153));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 345; c0 += 1)
    for (c1 = c0 + 154; c1 <= min(c0 + 307, 499); c1 += 1) {
      if (c0 + 306 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-154+c0] + S[-c0+c1-154+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][153+c0] + S[153+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 345; c0 += 1)
    S[c0][c0+154] = MAX(S[c0][c0+154], S[c0+1][c0+154-1] + can_pair(RNA, c0, c0+154));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 344; c0 += 1)
    for (c1 = c0 + 155; c1 <= min(c0 + 309, 499); c1 += 1) {
      if (c0 + 308 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-155+c0] + S[-c0+c1-155+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][154+c0] + S[154+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 344; c0 += 1)
    S[c0][c0+155] = MAX(S[c0][c0+155], S[c0+1][c0+155-1] + can_pair(RNA, c0, c0+155));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 343; c0 += 1)
    for (c1 = c0 + 156; c1 <= min(c0 + 311, 499); c1 += 1) {
      if (c0 + 310 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-156+c0] + S[-c0+c1-156+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][155+c0] + S[155+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 343; c0 += 1)
    S[c0][c0+156] = MAX(S[c0][c0+156], S[c0+1][c0+156-1] + can_pair(RNA, c0, c0+156));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 342; c0 += 1)
    for (c1 = c0 + 157; c1 <= min(c0 + 313, 499); c1 += 1) {
      if (c0 + 312 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-157+c0] + S[-c0+c1-157+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][156+c0] + S[156+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 342; c0 += 1)
    S[c0][c0+157] = MAX(S[c0][c0+157], S[c0+1][c0+157-1] + can_pair(RNA, c0, c0+157));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 341; c0 += 1)
    for (c1 = c0 + 158; c1 <= min(c0 + 315, 499); c1 += 1) {
      if (c0 + 314 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-158+c0] + S[-c0+c1-158+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][157+c0] + S[157+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 341; c0 += 1)
    S[c0][c0+158] = MAX(S[c0][c0+158], S[c0+1][c0+158-1] + can_pair(RNA, c0, c0+158));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 340; c0 += 1)
    for (c1 = c0 + 159; c1 <= min(c0 + 317, 499); c1 += 1) {
      if (c0 + 316 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-159+c0] + S[-c0+c1-159+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][158+c0] + S[158+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 340; c0 += 1)
    S[c0][c0+159] = MAX(S[c0][c0+159], S[c0+1][c0+159-1] + can_pair(RNA, c0, c0+159));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 339; c0 += 1)
    for (c1 = c0 + 160; c1 <= min(c0 + 319, 499); c1 += 1) {
      if (c0 + 318 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-160+c0] + S[-c0+c1-160+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][159+c0] + S[159+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 339; c0 += 1)
    S[c0][c0+160] = MAX(S[c0][c0+160], S[c0+1][c0+160-1] + can_pair(RNA, c0, c0+160));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 338; c0 += 1)
    for (c1 = c0 + 161; c1 <= min(c0 + 321, 499); c1 += 1) {
      if (c0 + 320 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-161+c0] + S[-c0+c1-161+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][160+c0] + S[160+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 338; c0 += 1)
    S[c0][c0+161] = MAX(S[c0][c0+161], S[c0+1][c0+161-1] + can_pair(RNA, c0, c0+161));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 337; c0 += 1)
    for (c1 = c0 + 162; c1 <= min(c0 + 323, 499); c1 += 1) {
      if (c0 + 322 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-162+c0] + S[-c0+c1-162+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][161+c0] + S[161+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 337; c0 += 1)
    S[c0][c0+162] = MAX(S[c0][c0+162], S[c0+1][c0+162-1] + can_pair(RNA, c0, c0+162));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 336; c0 += 1)
    for (c1 = c0 + 163; c1 <= min(c0 + 325, 499); c1 += 1) {
      if (c0 + 324 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-163+c0] + S[-c0+c1-163+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][162+c0] + S[162+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 336; c0 += 1)
    S[c0][c0+163] = MAX(S[c0][c0+163], S[c0+1][c0+163-1] + can_pair(RNA, c0, c0+163));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 335; c0 += 1)
    for (c1 = c0 + 164; c1 <= min(c0 + 327, 499); c1 += 1) {
      if (c0 + 326 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-164+c0] + S[-c0+c1-164+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][163+c0] + S[163+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 335; c0 += 1)
    S[c0][c0+164] = MAX(S[c0][c0+164], S[c0+1][c0+164-1] + can_pair(RNA, c0, c0+164));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 334; c0 += 1)
    for (c1 = c0 + 165; c1 <= min(c0 + 329, 499); c1 += 1) {
      if (c0 + 328 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-165+c0] + S[-c0+c1-165+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][164+c0] + S[164+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 334; c0 += 1)
    S[c0][c0+165] = MAX(S[c0][c0+165], S[c0+1][c0+165-1] + can_pair(RNA, c0, c0+165));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 333; c0 += 1)
    for (c1 = c0 + 166; c1 <= min(c0 + 331, 499); c1 += 1) {
      if (c0 + 330 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-166+c0] + S[-c0+c1-166+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][165+c0] + S[165+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 333; c0 += 1)
    S[c0][c0+166] = MAX(S[c0][c0+166], S[c0+1][c0+166-1] + can_pair(RNA, c0, c0+166));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 332; c0 += 1)
    for (c1 = c0 + 167; c1 <= min(c0 + 333, 499); c1 += 1) {
      if (c0 + 332 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-167+c0] + S[-c0+c1-167+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][166+c0] + S[166+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 332; c0 += 1)
    S[c0][c0+167] = MAX(S[c0][c0+167], S[c0+1][c0+167-1] + can_pair(RNA, c0, c0+167));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 331; c0 += 1)
    for (c1 = c0 + 168; c1 <= min(c0 + 335, 499); c1 += 1) {
      if (c0 + 334 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-168+c0] + S[-c0+c1-168+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][167+c0] + S[167+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 331; c0 += 1)
    S[c0][c0+168] = MAX(S[c0][c0+168], S[c0+1][c0+168-1] + can_pair(RNA, c0, c0+168));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 330; c0 += 1)
    for (c1 = c0 + 169; c1 <= min(c0 + 337, 499); c1 += 1) {
      if (c0 + 336 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-169+c0] + S[-c0+c1-169+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][168+c0] + S[168+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 330; c0 += 1)
    S[c0][c0+169] = MAX(S[c0][c0+169], S[c0+1][c0+169-1] + can_pair(RNA, c0, c0+169));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 329; c0 += 1)
    for (c1 = c0 + 170; c1 <= min(c0 + 339, 499); c1 += 1) {
      if (c0 + 338 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-170+c0] + S[-c0+c1-170+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][169+c0] + S[169+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 329; c0 += 1)
    S[c0][c0+170] = MAX(S[c0][c0+170], S[c0+1][c0+170-1] + can_pair(RNA, c0, c0+170));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 328; c0 += 1)
    for (c1 = c0 + 171; c1 <= min(c0 + 341, 499); c1 += 1) {
      if (c0 + 340 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-171+c0] + S[-c0+c1-171+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][170+c0] + S[170+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 328; c0 += 1)
    S[c0][c0+171] = MAX(S[c0][c0+171], S[c0+1][c0+171-1] + can_pair(RNA, c0, c0+171));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 327; c0 += 1)
    for (c1 = c0 + 172; c1 <= min(c0 + 343, 499); c1 += 1) {
      if (c0 + 342 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-172+c0] + S[-c0+c1-172+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][171+c0] + S[171+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 327; c0 += 1)
    S[c0][c0+172] = MAX(S[c0][c0+172], S[c0+1][c0+172-1] + can_pair(RNA, c0, c0+172));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 326; c0 += 1)
    for (c1 = c0 + 173; c1 <= min(c0 + 345, 499); c1 += 1) {
      if (c0 + 344 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-173+c0] + S[-c0+c1-173+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][172+c0] + S[172+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 326; c0 += 1)
    S[c0][c0+173] = MAX(S[c0][c0+173], S[c0+1][c0+173-1] + can_pair(RNA, c0, c0+173));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 325; c0 += 1)
    for (c1 = c0 + 174; c1 <= min(c0 + 347, 499); c1 += 1) {
      if (c0 + 346 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-174+c0] + S[-c0+c1-174+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][173+c0] + S[173+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 325; c0 += 1)
    S[c0][c0+174] = MAX(S[c0][c0+174], S[c0+1][c0+174-1] + can_pair(RNA, c0, c0+174));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 324; c0 += 1)
    for (c1 = c0 + 175; c1 <= min(c0 + 349, 499); c1 += 1) {
      if (c0 + 348 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-175+c0] + S[-c0+c1-175+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][174+c0] + S[174+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 324; c0 += 1)
    S[c0][c0+175] = MAX(S[c0][c0+175], S[c0+1][c0+175-1] + can_pair(RNA, c0, c0+175));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 323; c0 += 1)
    for (c1 = c0 + 176; c1 <= min(c0 + 351, 499); c1 += 1) {
      if (c0 + 350 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-176+c0] + S[-c0+c1-176+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][175+c0] + S[175+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 323; c0 += 1)
    S[c0][c0+176] = MAX(S[c0][c0+176], S[c0+1][c0+176-1] + can_pair(RNA, c0, c0+176));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 322; c0 += 1)
    for (c1 = c0 + 177; c1 <= min(c0 + 353, 499); c1 += 1) {
      if (c0 + 352 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-177+c0] + S[-c0+c1-177+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][176+c0] + S[176+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 322; c0 += 1)
    S[c0][c0+177] = MAX(S[c0][c0+177], S[c0+1][c0+177-1] + can_pair(RNA, c0, c0+177));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 321; c0 += 1)
    for (c1 = c0 + 178; c1 <= min(c0 + 355, 499); c1 += 1) {
      if (c0 + 354 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-178+c0] + S[-c0+c1-178+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][177+c0] + S[177+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 321; c0 += 1)
    S[c0][c0+178] = MAX(S[c0][c0+178], S[c0+1][c0+178-1] + can_pair(RNA, c0, c0+178));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 320; c0 += 1)
    for (c1 = c0 + 179; c1 <= min(c0 + 357, 499); c1 += 1) {
      if (c0 + 356 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-179+c0] + S[-c0+c1-179+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][178+c0] + S[178+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 320; c0 += 1)
    S[c0][c0+179] = MAX(S[c0][c0+179], S[c0+1][c0+179-1] + can_pair(RNA, c0, c0+179));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 319; c0 += 1)
    for (c1 = c0 + 180; c1 <= min(c0 + 359, 499); c1 += 1) {
      if (c0 + 358 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-180+c0] + S[-c0+c1-180+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][179+c0] + S[179+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 319; c0 += 1)
    S[c0][c0+180] = MAX(S[c0][c0+180], S[c0+1][c0+180-1] + can_pair(RNA, c0, c0+180));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 318; c0 += 1)
    for (c1 = c0 + 181; c1 <= min(c0 + 361, 499); c1 += 1) {
      if (c0 + 360 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-181+c0] + S[-c0+c1-181+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][180+c0] + S[180+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 318; c0 += 1)
    S[c0][c0+181] = MAX(S[c0][c0+181], S[c0+1][c0+181-1] + can_pair(RNA, c0, c0+181));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 317; c0 += 1)
    for (c1 = c0 + 182; c1 <= min(c0 + 363, 499); c1 += 1) {
      if (c0 + 362 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-182+c0] + S[-c0+c1-182+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][181+c0] + S[181+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 317; c0 += 1)
    S[c0][c0+182] = MAX(S[c0][c0+182], S[c0+1][c0+182-1] + can_pair(RNA, c0, c0+182));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 316; c0 += 1)
    for (c1 = c0 + 183; c1 <= min(c0 + 365, 499); c1 += 1) {
      if (c0 + 364 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-183+c0] + S[-c0+c1-183+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][182+c0] + S[182+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 316; c0 += 1)
    S[c0][c0+183] = MAX(S[c0][c0+183], S[c0+1][c0+183-1] + can_pair(RNA, c0, c0+183));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 315; c0 += 1)
    for (c1 = c0 + 184; c1 <= min(c0 + 367, 499); c1 += 1) {
      if (c0 + 366 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-184+c0] + S[-c0+c1-184+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][183+c0] + S[183+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 315; c0 += 1)
    S[c0][c0+184] = MAX(S[c0][c0+184], S[c0+1][c0+184-1] + can_pair(RNA, c0, c0+184));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 314; c0 += 1)
    for (c1 = c0 + 185; c1 <= min(c0 + 369, 499); c1 += 1) {
      if (c0 + 368 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-185+c0] + S[-c0+c1-185+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][184+c0] + S[184+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 314; c0 += 1)
    S[c0][c0+185] = MAX(S[c0][c0+185], S[c0+1][c0+185-1] + can_pair(RNA, c0, c0+185));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 313; c0 += 1)
    for (c1 = c0 + 186; c1 <= min(c0 + 371, 499); c1 += 1) {
      if (c0 + 370 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-186+c0] + S[-c0+c1-186+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][185+c0] + S[185+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 313; c0 += 1)
    S[c0][c0+186] = MAX(S[c0][c0+186], S[c0+1][c0+186-1] + can_pair(RNA, c0, c0+186));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 312; c0 += 1)
    for (c1 = c0 + 187; c1 <= min(c0 + 373, 499); c1 += 1) {
      if (c0 + 372 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-187+c0] + S[-c0+c1-187+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][186+c0] + S[186+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 312; c0 += 1)
    S[c0][c0+187] = MAX(S[c0][c0+187], S[c0+1][c0+187-1] + can_pair(RNA, c0, c0+187));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 311; c0 += 1)
    for (c1 = c0 + 188; c1 <= min(c0 + 375, 499); c1 += 1) {
      if (c0 + 374 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-188+c0] + S[-c0+c1-188+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][187+c0] + S[187+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 311; c0 += 1)
    S[c0][c0+188] = MAX(S[c0][c0+188], S[c0+1][c0+188-1] + can_pair(RNA, c0, c0+188));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 310; c0 += 1)
    for (c1 = c0 + 189; c1 <= min(c0 + 377, 499); c1 += 1) {
      if (c0 + 376 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-189+c0] + S[-c0+c1-189+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][188+c0] + S[188+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 310; c0 += 1)
    S[c0][c0+189] = MAX(S[c0][c0+189], S[c0+1][c0+189-1] + can_pair(RNA, c0, c0+189));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 309; c0 += 1)
    for (c1 = c0 + 190; c1 <= min(c0 + 379, 499); c1 += 1) {
      if (c0 + 378 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-190+c0] + S[-c0+c1-190+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][189+c0] + S[189+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 309; c0 += 1)
    S[c0][c0+190] = MAX(S[c0][c0+190], S[c0+1][c0+190-1] + can_pair(RNA, c0, c0+190));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 308; c0 += 1)
    for (c1 = c0 + 191; c1 <= min(c0 + 381, 499); c1 += 1) {
      if (c0 + 380 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-191+c0] + S[-c0+c1-191+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][190+c0] + S[190+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 308; c0 += 1)
    S[c0][c0+191] = MAX(S[c0][c0+191], S[c0+1][c0+191-1] + can_pair(RNA, c0, c0+191));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 307; c0 += 1)
    for (c1 = c0 + 192; c1 <= min(c0 + 383, 499); c1 += 1) {
      if (c0 + 382 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-192+c0] + S[-c0+c1-192+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][191+c0] + S[191+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 307; c0 += 1)
    S[c0][c0+192] = MAX(S[c0][c0+192], S[c0+1][c0+192-1] + can_pair(RNA, c0, c0+192));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 306; c0 += 1)
    for (c1 = c0 + 193; c1 <= min(c0 + 385, 499); c1 += 1) {
      if (c0 + 384 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-193+c0] + S[-c0+c1-193+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][192+c0] + S[192+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 306; c0 += 1)
    S[c0][c0+193] = MAX(S[c0][c0+193], S[c0+1][c0+193-1] + can_pair(RNA, c0, c0+193));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 305; c0 += 1)
    for (c1 = c0 + 194; c1 <= min(c0 + 387, 499); c1 += 1) {
      if (c0 + 386 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-194+c0] + S[-c0+c1-194+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][193+c0] + S[193+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 305; c0 += 1)
    S[c0][c0+194] = MAX(S[c0][c0+194], S[c0+1][c0+194-1] + can_pair(RNA, c0, c0+194));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 304; c0 += 1)
    for (c1 = c0 + 195; c1 <= min(c0 + 389, 499); c1 += 1) {
      if (c0 + 388 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-195+c0] + S[-c0+c1-195+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][194+c0] + S[194+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 304; c0 += 1)
    S[c0][c0+195] = MAX(S[c0][c0+195], S[c0+1][c0+195-1] + can_pair(RNA, c0, c0+195));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 303; c0 += 1)
    for (c1 = c0 + 196; c1 <= min(c0 + 391, 499); c1 += 1) {
      if (c0 + 390 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-196+c0] + S[-c0+c1-196+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][195+c0] + S[195+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 303; c0 += 1)
    S[c0][c0+196] = MAX(S[c0][c0+196], S[c0+1][c0+196-1] + can_pair(RNA, c0, c0+196));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 302; c0 += 1)
    for (c1 = c0 + 197; c1 <= min(c0 + 393, 499); c1 += 1) {
      if (c0 + 392 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-197+c0] + S[-c0+c1-197+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][196+c0] + S[196+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 302; c0 += 1)
    S[c0][c0+197] = MAX(S[c0][c0+197], S[c0+1][c0+197-1] + can_pair(RNA, c0, c0+197));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 301; c0 += 1)
    for (c1 = c0 + 198; c1 <= min(c0 + 395, 499); c1 += 1) {
      if (c0 + 394 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-198+c0] + S[-c0+c1-198+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][197+c0] + S[197+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 301; c0 += 1)
    S[c0][c0+198] = MAX(S[c0][c0+198], S[c0+1][c0+198-1] + can_pair(RNA, c0, c0+198));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 300; c0 += 1)
    for (c1 = c0 + 199; c1 <= min(c0 + 397, 499); c1 += 1) {
      if (c0 + 396 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-199+c0] + S[-c0+c1-199+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][198+c0] + S[198+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 300; c0 += 1)
    S[c0][c0+199] = MAX(S[c0][c0+199], S[c0+1][c0+199-1] + can_pair(RNA, c0, c0+199));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 299; c0 += 1)
    for (c1 = c0 + 200; c1 <= min(c0 + 399, 499); c1 += 1) {
      if (c0 + 398 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-200+c0] + S[-c0+c1-200+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][199+c0] + S[199+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 299; c0 += 1)
    S[c0][c0+200] = MAX(S[c0][c0+200], S[c0+1][c0+200-1] + can_pair(RNA, c0, c0+200));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 298; c0 += 1)
    for (c1 = c0 + 201; c1 <= min(c0 + 401, 499); c1 += 1) {
      if (c0 + 400 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-201+c0] + S[-c0+c1-201+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][200+c0] + S[200+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 298; c0 += 1)
    S[c0][c0+201] = MAX(S[c0][c0+201], S[c0+1][c0+201-1] + can_pair(RNA, c0, c0+201));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 297; c0 += 1)
    for (c1 = c0 + 202; c1 <= min(c0 + 403, 499); c1 += 1) {
      if (c0 + 402 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-202+c0] + S[-c0+c1-202+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][201+c0] + S[201+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 297; c0 += 1)
    S[c0][c0+202] = MAX(S[c0][c0+202], S[c0+1][c0+202-1] + can_pair(RNA, c0, c0+202));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 296; c0 += 1)
    for (c1 = c0 + 203; c1 <= min(c0 + 405, 499); c1 += 1) {
      if (c0 + 404 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-203+c0] + S[-c0+c1-203+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][202+c0] + S[202+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 296; c0 += 1)
    S[c0][c0+203] = MAX(S[c0][c0+203], S[c0+1][c0+203-1] + can_pair(RNA, c0, c0+203));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 295; c0 += 1)
    for (c1 = c0 + 204; c1 <= min(c0 + 407, 499); c1 += 1) {
      if (c0 + 406 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-204+c0] + S[-c0+c1-204+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][203+c0] + S[203+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 295; c0 += 1)
    S[c0][c0+204] = MAX(S[c0][c0+204], S[c0+1][c0+204-1] + can_pair(RNA, c0, c0+204));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 294; c0 += 1)
    for (c1 = c0 + 205; c1 <= min(c0 + 409, 499); c1 += 1) {
      if (c0 + 408 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-205+c0] + S[-c0+c1-205+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][204+c0] + S[204+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 294; c0 += 1)
    S[c0][c0+205] = MAX(S[c0][c0+205], S[c0+1][c0+205-1] + can_pair(RNA, c0, c0+205));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 293; c0 += 1)
    for (c1 = c0 + 206; c1 <= min(c0 + 411, 499); c1 += 1) {
      if (c0 + 410 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-206+c0] + S[-c0+c1-206+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][205+c0] + S[205+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 293; c0 += 1)
    S[c0][c0+206] = MAX(S[c0][c0+206], S[c0+1][c0+206-1] + can_pair(RNA, c0, c0+206));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 292; c0 += 1)
    for (c1 = c0 + 207; c1 <= min(c0 + 413, 499); c1 += 1) {
      if (c0 + 412 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-207+c0] + S[-c0+c1-207+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][206+c0] + S[206+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 292; c0 += 1)
    S[c0][c0+207] = MAX(S[c0][c0+207], S[c0+1][c0+207-1] + can_pair(RNA, c0, c0+207));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 291; c0 += 1)
    for (c1 = c0 + 208; c1 <= min(c0 + 415, 499); c1 += 1) {
      if (c0 + 414 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-208+c0] + S[-c0+c1-208+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][207+c0] + S[207+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 291; c0 += 1)
    S[c0][c0+208] = MAX(S[c0][c0+208], S[c0+1][c0+208-1] + can_pair(RNA, c0, c0+208));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 290; c0 += 1)
    for (c1 = c0 + 209; c1 <= min(c0 + 417, 499); c1 += 1) {
      if (c0 + 416 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-209+c0] + S[-c0+c1-209+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][208+c0] + S[208+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 290; c0 += 1)
    S[c0][c0+209] = MAX(S[c0][c0+209], S[c0+1][c0+209-1] + can_pair(RNA, c0, c0+209));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 289; c0 += 1)
    for (c1 = c0 + 210; c1 <= min(c0 + 419, 499); c1 += 1) {
      if (c0 + 418 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-210+c0] + S[-c0+c1-210+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][209+c0] + S[209+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 289; c0 += 1)
    S[c0][c0+210] = MAX(S[c0][c0+210], S[c0+1][c0+210-1] + can_pair(RNA, c0, c0+210));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 288; c0 += 1)
    for (c1 = c0 + 211; c1 <= min(c0 + 421, 499); c1 += 1) {
      if (c0 + 420 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-211+c0] + S[-c0+c1-211+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][210+c0] + S[210+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 288; c0 += 1)
    S[c0][c0+211] = MAX(S[c0][c0+211], S[c0+1][c0+211-1] + can_pair(RNA, c0, c0+211));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 287; c0 += 1)
    for (c1 = c0 + 212; c1 <= min(c0 + 423, 499); c1 += 1) {
      if (c0 + 422 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-212+c0] + S[-c0+c1-212+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][211+c0] + S[211+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 287; c0 += 1)
    S[c0][c0+212] = MAX(S[c0][c0+212], S[c0+1][c0+212-1] + can_pair(RNA, c0, c0+212));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 286; c0 += 1)
    for (c1 = c0 + 213; c1 <= min(c0 + 425, 499); c1 += 1) {
      if (c0 + 424 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-213+c0] + S[-c0+c1-213+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][212+c0] + S[212+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 286; c0 += 1)
    S[c0][c0+213] = MAX(S[c0][c0+213], S[c0+1][c0+213-1] + can_pair(RNA, c0, c0+213));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 285; c0 += 1)
    for (c1 = c0 + 214; c1 <= min(c0 + 427, 499); c1 += 1) {
      if (c0 + 426 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-214+c0] + S[-c0+c1-214+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][213+c0] + S[213+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 285; c0 += 1)
    S[c0][c0+214] = MAX(S[c0][c0+214], S[c0+1][c0+214-1] + can_pair(RNA, c0, c0+214));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 284; c0 += 1)
    for (c1 = c0 + 215; c1 <= min(c0 + 429, 499); c1 += 1) {
      if (c0 + 428 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-215+c0] + S[-c0+c1-215+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][214+c0] + S[214+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 284; c0 += 1)
    S[c0][c0+215] = MAX(S[c0][c0+215], S[c0+1][c0+215-1] + can_pair(RNA, c0, c0+215));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 283; c0 += 1)
    for (c1 = c0 + 216; c1 <= min(c0 + 431, 499); c1 += 1) {
      if (c0 + 430 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-216+c0] + S[-c0+c1-216+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][215+c0] + S[215+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 283; c0 += 1)
    S[c0][c0+216] = MAX(S[c0][c0+216], S[c0+1][c0+216-1] + can_pair(RNA, c0, c0+216));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 282; c0 += 1)
    for (c1 = c0 + 217; c1 <= min(c0 + 433, 499); c1 += 1) {
      if (c0 + 432 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-217+c0] + S[-c0+c1-217+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][216+c0] + S[216+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 282; c0 += 1)
    S[c0][c0+217] = MAX(S[c0][c0+217], S[c0+1][c0+217-1] + can_pair(RNA, c0, c0+217));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 281; c0 += 1)
    for (c1 = c0 + 218; c1 <= min(c0 + 435, 499); c1 += 1) {
      if (c0 + 434 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-218+c0] + S[-c0+c1-218+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][217+c0] + S[217+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 281; c0 += 1)
    S[c0][c0+218] = MAX(S[c0][c0+218], S[c0+1][c0+218-1] + can_pair(RNA, c0, c0+218));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 280; c0 += 1)
    for (c1 = c0 + 219; c1 <= min(c0 + 437, 499); c1 += 1) {
      if (c0 + 436 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-219+c0] + S[-c0+c1-219+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][218+c0] + S[218+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 280; c0 += 1)
    S[c0][c0+219] = MAX(S[c0][c0+219], S[c0+1][c0+219-1] + can_pair(RNA, c0, c0+219));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 279; c0 += 1)
    for (c1 = c0 + 220; c1 <= min(c0 + 439, 499); c1 += 1) {
      if (c0 + 438 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-220+c0] + S[-c0+c1-220+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][219+c0] + S[219+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 279; c0 += 1)
    S[c0][c0+220] = MAX(S[c0][c0+220], S[c0+1][c0+220-1] + can_pair(RNA, c0, c0+220));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 278; c0 += 1)
    for (c1 = c0 + 221; c1 <= min(c0 + 441, 499); c1 += 1) {
      if (c0 + 440 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-221+c0] + S[-c0+c1-221+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][220+c0] + S[220+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 278; c0 += 1)
    S[c0][c0+221] = MAX(S[c0][c0+221], S[c0+1][c0+221-1] + can_pair(RNA, c0, c0+221));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 277; c0 += 1)
    for (c1 = c0 + 222; c1 <= min(c0 + 443, 499); c1 += 1) {
      if (c0 + 442 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-222+c0] + S[-c0+c1-222+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][221+c0] + S[221+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 277; c0 += 1)
    S[c0][c0+222] = MAX(S[c0][c0+222], S[c0+1][c0+222-1] + can_pair(RNA, c0, c0+222));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 276; c0 += 1)
    for (c1 = c0 + 223; c1 <= min(c0 + 445, 499); c1 += 1) {
      if (c0 + 444 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-223+c0] + S[-c0+c1-223+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][222+c0] + S[222+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 276; c0 += 1)
    S[c0][c0+223] = MAX(S[c0][c0+223], S[c0+1][c0+223-1] + can_pair(RNA, c0, c0+223));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 275; c0 += 1)
    for (c1 = c0 + 224; c1 <= min(c0 + 447, 499); c1 += 1) {
      if (c0 + 446 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-224+c0] + S[-c0+c1-224+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][223+c0] + S[223+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 275; c0 += 1)
    S[c0][c0+224] = MAX(S[c0][c0+224], S[c0+1][c0+224-1] + can_pair(RNA, c0, c0+224));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 274; c0 += 1)
    for (c1 = c0 + 225; c1 <= min(c0 + 449, 499); c1 += 1) {
      if (c0 + 448 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-225+c0] + S[-c0+c1-225+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][224+c0] + S[224+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 274; c0 += 1)
    S[c0][c0+225] = MAX(S[c0][c0+225], S[c0+1][c0+225-1] + can_pair(RNA, c0, c0+225));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 273; c0 += 1)
    for (c1 = c0 + 226; c1 <= min(c0 + 451, 499); c1 += 1) {
      if (c0 + 450 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-226+c0] + S[-c0+c1-226+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][225+c0] + S[225+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 273; c0 += 1)
    S[c0][c0+226] = MAX(S[c0][c0+226], S[c0+1][c0+226-1] + can_pair(RNA, c0, c0+226));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 272; c0 += 1)
    for (c1 = c0 + 227; c1 <= min(c0 + 453, 499); c1 += 1) {
      if (c0 + 452 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-227+c0] + S[-c0+c1-227+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][226+c0] + S[226+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 272; c0 += 1)
    S[c0][c0+227] = MAX(S[c0][c0+227], S[c0+1][c0+227-1] + can_pair(RNA, c0, c0+227));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 271; c0 += 1)
    for (c1 = c0 + 228; c1 <= min(c0 + 455, 499); c1 += 1) {
      if (c0 + 454 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-228+c0] + S[-c0+c1-228+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][227+c0] + S[227+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 271; c0 += 1)
    S[c0][c0+228] = MAX(S[c0][c0+228], S[c0+1][c0+228-1] + can_pair(RNA, c0, c0+228));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 270; c0 += 1)
    for (c1 = c0 + 229; c1 <= min(c0 + 457, 499); c1 += 1) {
      if (c0 + 456 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-229+c0] + S[-c0+c1-229+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][228+c0] + S[228+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 270; c0 += 1)
    S[c0][c0+229] = MAX(S[c0][c0+229], S[c0+1][c0+229-1] + can_pair(RNA, c0, c0+229));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 269; c0 += 1)
    for (c1 = c0 + 230; c1 <= min(c0 + 459, 499); c1 += 1) {
      if (c0 + 458 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-230+c0] + S[-c0+c1-230+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][229+c0] + S[229+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 269; c0 += 1)
    S[c0][c0+230] = MAX(S[c0][c0+230], S[c0+1][c0+230-1] + can_pair(RNA, c0, c0+230));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 268; c0 += 1)
    for (c1 = c0 + 231; c1 <= min(c0 + 461, 499); c1 += 1) {
      if (c0 + 460 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-231+c0] + S[-c0+c1-231+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][230+c0] + S[230+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 268; c0 += 1)
    S[c0][c0+231] = MAX(S[c0][c0+231], S[c0+1][c0+231-1] + can_pair(RNA, c0, c0+231));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 267; c0 += 1)
    for (c1 = c0 + 232; c1 <= min(c0 + 463, 499); c1 += 1) {
      if (c0 + 462 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-232+c0] + S[-c0+c1-232+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][231+c0] + S[231+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 267; c0 += 1)
    S[c0][c0+232] = MAX(S[c0][c0+232], S[c0+1][c0+232-1] + can_pair(RNA, c0, c0+232));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 266; c0 += 1)
    for (c1 = c0 + 233; c1 <= min(c0 + 465, 499); c1 += 1) {
      if (c0 + 464 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-233+c0] + S[-c0+c1-233+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][232+c0] + S[232+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 266; c0 += 1)
    S[c0][c0+233] = MAX(S[c0][c0+233], S[c0+1][c0+233-1] + can_pair(RNA, c0, c0+233));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 265; c0 += 1)
    for (c1 = c0 + 234; c1 <= min(c0 + 467, 499); c1 += 1) {
      if (c0 + 466 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-234+c0] + S[-c0+c1-234+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][233+c0] + S[233+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 265; c0 += 1)
    S[c0][c0+234] = MAX(S[c0][c0+234], S[c0+1][c0+234-1] + can_pair(RNA, c0, c0+234));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 264; c0 += 1)
    for (c1 = c0 + 235; c1 <= min(c0 + 469, 499); c1 += 1) {
      if (c0 + 468 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-235+c0] + S[-c0+c1-235+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][234+c0] + S[234+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 264; c0 += 1)
    S[c0][c0+235] = MAX(S[c0][c0+235], S[c0+1][c0+235-1] + can_pair(RNA, c0, c0+235));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 263; c0 += 1)
    for (c1 = c0 + 236; c1 <= min(c0 + 471, 499); c1 += 1) {
      if (c0 + 470 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-236+c0] + S[-c0+c1-236+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][235+c0] + S[235+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 263; c0 += 1)
    S[c0][c0+236] = MAX(S[c0][c0+236], S[c0+1][c0+236-1] + can_pair(RNA, c0, c0+236));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 262; c0 += 1)
    for (c1 = c0 + 237; c1 <= min(c0 + 473, 499); c1 += 1) {
      if (c0 + 472 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-237+c0] + S[-c0+c1-237+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][236+c0] + S[236+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 262; c0 += 1)
    S[c0][c0+237] = MAX(S[c0][c0+237], S[c0+1][c0+237-1] + can_pair(RNA, c0, c0+237));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 261; c0 += 1)
    for (c1 = c0 + 238; c1 <= min(c0 + 475, 499); c1 += 1) {
      if (c0 + 474 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-238+c0] + S[-c0+c1-238+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][237+c0] + S[237+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 261; c0 += 1)
    S[c0][c0+238] = MAX(S[c0][c0+238], S[c0+1][c0+238-1] + can_pair(RNA, c0, c0+238));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 260; c0 += 1)
    for (c1 = c0 + 239; c1 <= min(c0 + 477, 499); c1 += 1) {
      if (c0 + 476 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-239+c0] + S[-c0+c1-239+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][238+c0] + S[238+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 260; c0 += 1)
    S[c0][c0+239] = MAX(S[c0][c0+239], S[c0+1][c0+239-1] + can_pair(RNA, c0, c0+239));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 259; c0 += 1)
    for (c1 = c0 + 240; c1 <= min(c0 + 479, 499); c1 += 1) {
      if (c0 + 478 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-240+c0] + S[-c0+c1-240+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][239+c0] + S[239+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 259; c0 += 1)
    S[c0][c0+240] = MAX(S[c0][c0+240], S[c0+1][c0+240-1] + can_pair(RNA, c0, c0+240));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 258; c0 += 1)
    for (c1 = c0 + 241; c1 <= min(c0 + 481, 499); c1 += 1) {
      if (c0 + 480 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-241+c0] + S[-c0+c1-241+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][240+c0] + S[240+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 258; c0 += 1)
    S[c0][c0+241] = MAX(S[c0][c0+241], S[c0+1][c0+241-1] + can_pair(RNA, c0, c0+241));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 257; c0 += 1)
    for (c1 = c0 + 242; c1 <= min(c0 + 483, 499); c1 += 1) {
      if (c0 + 482 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-242+c0] + S[-c0+c1-242+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][241+c0] + S[241+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 257; c0 += 1)
    S[c0][c0+242] = MAX(S[c0][c0+242], S[c0+1][c0+242-1] + can_pair(RNA, c0, c0+242));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 256; c0 += 1)
    for (c1 = c0 + 243; c1 <= min(c0 + 485, 499); c1 += 1) {
      if (c0 + 484 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-243+c0] + S[-c0+c1-243+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][242+c0] + S[242+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 256; c0 += 1)
    S[c0][c0+243] = MAX(S[c0][c0+243], S[c0+1][c0+243-1] + can_pair(RNA, c0, c0+243));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 255; c0 += 1)
    for (c1 = c0 + 244; c1 <= min(c0 + 487, 499); c1 += 1) {
      if (c0 + 486 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-244+c0] + S[-c0+c1-244+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][243+c0] + S[243+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 255; c0 += 1)
    S[c0][c0+244] = MAX(S[c0][c0+244], S[c0+1][c0+244-1] + can_pair(RNA, c0, c0+244));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 254; c0 += 1)
    for (c1 = c0 + 245; c1 <= min(c0 + 489, 499); c1 += 1) {
      if (c0 + 488 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-245+c0] + S[-c0+c1-245+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][244+c0] + S[244+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 254; c0 += 1)
    S[c0][c0+245] = MAX(S[c0][c0+245], S[c0+1][c0+245-1] + can_pair(RNA, c0, c0+245));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 253; c0 += 1)
    for (c1 = c0 + 246; c1 <= min(c0 + 491, 499); c1 += 1) {
      if (c0 + 490 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-246+c0] + S[-c0+c1-246+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][245+c0] + S[245+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 253; c0 += 1)
    S[c0][c0+246] = MAX(S[c0][c0+246], S[c0+1][c0+246-1] + can_pair(RNA, c0, c0+246));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 252; c0 += 1)
    for (c1 = c0 + 247; c1 <= min(c0 + 493, 499); c1 += 1) {
      if (c0 + 492 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-247+c0] + S[-c0+c1-247+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][246+c0] + S[246+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 252; c0 += 1)
    S[c0][c0+247] = MAX(S[c0][c0+247], S[c0+1][c0+247-1] + can_pair(RNA, c0, c0+247));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 251; c0 += 1)
    for (c1 = c0 + 248; c1 <= min(c0 + 495, 499); c1 += 1) {
      if (c0 + 494 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-248+c0] + S[-c0+c1-248+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][247+c0] + S[247+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 251; c0 += 1)
    S[c0][c0+248] = MAX(S[c0][c0+248], S[c0+1][c0+248-1] + can_pair(RNA, c0, c0+248));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 250; c0 += 1)
    for (c1 = c0 + 249; c1 <= min(c0 + 497, 499); c1 += 1) {
      if (c0 + 496 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-249+c0] + S[-c0+c1-249+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][248+c0] + S[248+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 250; c0 += 1)
    S[c0][c0+249] = MAX(S[c0][c0+249], S[c0+1][c0+249-1] + can_pair(RNA, c0, c0+249));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 249; c0 += 1)
    for (c1 = c0 + 250; c1 <= 499; c1 += 1) {
      if (c0 + 498 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-250+c0] + S[-c0+c1-250+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][249+c0] + S[249+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 249; c0 += 1)
    S[c0][c0+250] = MAX(S[c0][c0+250], S[c0+1][c0+250-1] + can_pair(RNA, c0, c0+250));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 248; c0 += 1)
    for (c1 = c0 + 251; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-251+c0] + S[-c0+c1-251+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][250+c0] + S[250+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 248; c0 += 1)
    S[c0][c0+251] = MAX(S[c0][c0+251], S[c0+1][c0+251-1] + can_pair(RNA, c0, c0+251));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 247; c0 += 1)
    for (c1 = c0 + 252; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-252+c0] + S[-c0+c1-252+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][251+c0] + S[251+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 247; c0 += 1)
    S[c0][c0+252] = MAX(S[c0][c0+252], S[c0+1][c0+252-1] + can_pair(RNA, c0, c0+252));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 246; c0 += 1)
    for (c1 = c0 + 253; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-253+c0] + S[-c0+c1-253+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][252+c0] + S[252+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 246; c0 += 1)
    S[c0][c0+253] = MAX(S[c0][c0+253], S[c0+1][c0+253-1] + can_pair(RNA, c0, c0+253));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 245; c0 += 1)
    for (c1 = c0 + 254; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-254+c0] + S[-c0+c1-254+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][253+c0] + S[253+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 245; c0 += 1)
    S[c0][c0+254] = MAX(S[c0][c0+254], S[c0+1][c0+254-1] + can_pair(RNA, c0, c0+254));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 244; c0 += 1)
    for (c1 = c0 + 255; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-255+c0] + S[-c0+c1-255+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][254+c0] + S[254+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 244; c0 += 1)
    S[c0][c0+255] = MAX(S[c0][c0+255], S[c0+1][c0+255-1] + can_pair(RNA, c0, c0+255));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 243; c0 += 1)
    for (c1 = c0 + 256; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-256+c0] + S[-c0+c1-256+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][255+c0] + S[255+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 243; c0 += 1)
    S[c0][c0+256] = MAX(S[c0][c0+256], S[c0+1][c0+256-1] + can_pair(RNA, c0, c0+256));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 242; c0 += 1)
    for (c1 = c0 + 257; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-257+c0] + S[-c0+c1-257+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][256+c0] + S[256+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 242; c0 += 1)
    S[c0][c0+257] = MAX(S[c0][c0+257], S[c0+1][c0+257-1] + can_pair(RNA, c0, c0+257));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 241; c0 += 1)
    for (c1 = c0 + 258; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-258+c0] + S[-c0+c1-258+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][257+c0] + S[257+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 241; c0 += 1)
    S[c0][c0+258] = MAX(S[c0][c0+258], S[c0+1][c0+258-1] + can_pair(RNA, c0, c0+258));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 240; c0 += 1)
    for (c1 = c0 + 259; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-259+c0] + S[-c0+c1-259+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][258+c0] + S[258+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 240; c0 += 1)
    S[c0][c0+259] = MAX(S[c0][c0+259], S[c0+1][c0+259-1] + can_pair(RNA, c0, c0+259));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 239; c0 += 1)
    for (c1 = c0 + 260; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-260+c0] + S[-c0+c1-260+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][259+c0] + S[259+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 239; c0 += 1)
    S[c0][c0+260] = MAX(S[c0][c0+260], S[c0+1][c0+260-1] + can_pair(RNA, c0, c0+260));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 238; c0 += 1)
    for (c1 = c0 + 261; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-261+c0] + S[-c0+c1-261+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][260+c0] + S[260+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 238; c0 += 1)
    S[c0][c0+261] = MAX(S[c0][c0+261], S[c0+1][c0+261-1] + can_pair(RNA, c0, c0+261));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 237; c0 += 1)
    for (c1 = c0 + 262; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-262+c0] + S[-c0+c1-262+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][261+c0] + S[261+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 237; c0 += 1)
    S[c0][c0+262] = MAX(S[c0][c0+262], S[c0+1][c0+262-1] + can_pair(RNA, c0, c0+262));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 236; c0 += 1)
    for (c1 = c0 + 263; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-263+c0] + S[-c0+c1-263+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][262+c0] + S[262+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 236; c0 += 1)
    S[c0][c0+263] = MAX(S[c0][c0+263], S[c0+1][c0+263-1] + can_pair(RNA, c0, c0+263));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 235; c0 += 1)
    for (c1 = c0 + 264; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-264+c0] + S[-c0+c1-264+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][263+c0] + S[263+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 235; c0 += 1)
    S[c0][c0+264] = MAX(S[c0][c0+264], S[c0+1][c0+264-1] + can_pair(RNA, c0, c0+264));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 234; c0 += 1)
    for (c1 = c0 + 265; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-265+c0] + S[-c0+c1-265+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][264+c0] + S[264+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 234; c0 += 1)
    S[c0][c0+265] = MAX(S[c0][c0+265], S[c0+1][c0+265-1] + can_pair(RNA, c0, c0+265));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 233; c0 += 1)
    for (c1 = c0 + 266; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-266+c0] + S[-c0+c1-266+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][265+c0] + S[265+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 233; c0 += 1)
    S[c0][c0+266] = MAX(S[c0][c0+266], S[c0+1][c0+266-1] + can_pair(RNA, c0, c0+266));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 232; c0 += 1)
    for (c1 = c0 + 267; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-267+c0] + S[-c0+c1-267+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][266+c0] + S[266+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 232; c0 += 1)
    S[c0][c0+267] = MAX(S[c0][c0+267], S[c0+1][c0+267-1] + can_pair(RNA, c0, c0+267));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 231; c0 += 1)
    for (c1 = c0 + 268; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-268+c0] + S[-c0+c1-268+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][267+c0] + S[267+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 231; c0 += 1)
    S[c0][c0+268] = MAX(S[c0][c0+268], S[c0+1][c0+268-1] + can_pair(RNA, c0, c0+268));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 230; c0 += 1)
    for (c1 = c0 + 269; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-269+c0] + S[-c0+c1-269+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][268+c0] + S[268+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 230; c0 += 1)
    S[c0][c0+269] = MAX(S[c0][c0+269], S[c0+1][c0+269-1] + can_pair(RNA, c0, c0+269));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 229; c0 += 1)
    for (c1 = c0 + 270; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-270+c0] + S[-c0+c1-270+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][269+c0] + S[269+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 229; c0 += 1)
    S[c0][c0+270] = MAX(S[c0][c0+270], S[c0+1][c0+270-1] + can_pair(RNA, c0, c0+270));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 228; c0 += 1)
    for (c1 = c0 + 271; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-271+c0] + S[-c0+c1-271+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][270+c0] + S[270+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 228; c0 += 1)
    S[c0][c0+271] = MAX(S[c0][c0+271], S[c0+1][c0+271-1] + can_pair(RNA, c0, c0+271));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 227; c0 += 1)
    for (c1 = c0 + 272; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-272+c0] + S[-c0+c1-272+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][271+c0] + S[271+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 227; c0 += 1)
    S[c0][c0+272] = MAX(S[c0][c0+272], S[c0+1][c0+272-1] + can_pair(RNA, c0, c0+272));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 226; c0 += 1)
    for (c1 = c0 + 273; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-273+c0] + S[-c0+c1-273+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][272+c0] + S[272+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 226; c0 += 1)
    S[c0][c0+273] = MAX(S[c0][c0+273], S[c0+1][c0+273-1] + can_pair(RNA, c0, c0+273));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 225; c0 += 1)
    for (c1 = c0 + 274; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-274+c0] + S[-c0+c1-274+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][273+c0] + S[273+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 225; c0 += 1)
    S[c0][c0+274] = MAX(S[c0][c0+274], S[c0+1][c0+274-1] + can_pair(RNA, c0, c0+274));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 224; c0 += 1)
    for (c1 = c0 + 275; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-275+c0] + S[-c0+c1-275+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][274+c0] + S[274+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 224; c0 += 1)
    S[c0][c0+275] = MAX(S[c0][c0+275], S[c0+1][c0+275-1] + can_pair(RNA, c0, c0+275));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 223; c0 += 1)
    for (c1 = c0 + 276; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-276+c0] + S[-c0+c1-276+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][275+c0] + S[275+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 223; c0 += 1)
    S[c0][c0+276] = MAX(S[c0][c0+276], S[c0+1][c0+276-1] + can_pair(RNA, c0, c0+276));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 222; c0 += 1)
    for (c1 = c0 + 277; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-277+c0] + S[-c0+c1-277+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][276+c0] + S[276+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 222; c0 += 1)
    S[c0][c0+277] = MAX(S[c0][c0+277], S[c0+1][c0+277-1] + can_pair(RNA, c0, c0+277));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 221; c0 += 1)
    for (c1 = c0 + 278; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-278+c0] + S[-c0+c1-278+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][277+c0] + S[277+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 221; c0 += 1)
    S[c0][c0+278] = MAX(S[c0][c0+278], S[c0+1][c0+278-1] + can_pair(RNA, c0, c0+278));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 220; c0 += 1)
    for (c1 = c0 + 279; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-279+c0] + S[-c0+c1-279+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][278+c0] + S[278+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 220; c0 += 1)
    S[c0][c0+279] = MAX(S[c0][c0+279], S[c0+1][c0+279-1] + can_pair(RNA, c0, c0+279));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 219; c0 += 1)
    for (c1 = c0 + 280; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-280+c0] + S[-c0+c1-280+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][279+c0] + S[279+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 219; c0 += 1)
    S[c0][c0+280] = MAX(S[c0][c0+280], S[c0+1][c0+280-1] + can_pair(RNA, c0, c0+280));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 218; c0 += 1)
    for (c1 = c0 + 281; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-281+c0] + S[-c0+c1-281+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][280+c0] + S[280+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 218; c0 += 1)
    S[c0][c0+281] = MAX(S[c0][c0+281], S[c0+1][c0+281-1] + can_pair(RNA, c0, c0+281));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 217; c0 += 1)
    for (c1 = c0 + 282; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-282+c0] + S[-c0+c1-282+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][281+c0] + S[281+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 217; c0 += 1)
    S[c0][c0+282] = MAX(S[c0][c0+282], S[c0+1][c0+282-1] + can_pair(RNA, c0, c0+282));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 216; c0 += 1)
    for (c1 = c0 + 283; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-283+c0] + S[-c0+c1-283+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][282+c0] + S[282+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 216; c0 += 1)
    S[c0][c0+283] = MAX(S[c0][c0+283], S[c0+1][c0+283-1] + can_pair(RNA, c0, c0+283));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 215; c0 += 1)
    for (c1 = c0 + 284; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-284+c0] + S[-c0+c1-284+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][283+c0] + S[283+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 215; c0 += 1)
    S[c0][c0+284] = MAX(S[c0][c0+284], S[c0+1][c0+284-1] + can_pair(RNA, c0, c0+284));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 214; c0 += 1)
    for (c1 = c0 + 285; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-285+c0] + S[-c0+c1-285+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][284+c0] + S[284+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 214; c0 += 1)
    S[c0][c0+285] = MAX(S[c0][c0+285], S[c0+1][c0+285-1] + can_pair(RNA, c0, c0+285));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 213; c0 += 1)
    for (c1 = c0 + 286; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-286+c0] + S[-c0+c1-286+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][285+c0] + S[285+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 213; c0 += 1)
    S[c0][c0+286] = MAX(S[c0][c0+286], S[c0+1][c0+286-1] + can_pair(RNA, c0, c0+286));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 212; c0 += 1)
    for (c1 = c0 + 287; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-287+c0] + S[-c0+c1-287+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][286+c0] + S[286+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 212; c0 += 1)
    S[c0][c0+287] = MAX(S[c0][c0+287], S[c0+1][c0+287-1] + can_pair(RNA, c0, c0+287));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 211; c0 += 1)
    for (c1 = c0 + 288; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-288+c0] + S[-c0+c1-288+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][287+c0] + S[287+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 211; c0 += 1)
    S[c0][c0+288] = MAX(S[c0][c0+288], S[c0+1][c0+288-1] + can_pair(RNA, c0, c0+288));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 210; c0 += 1)
    for (c1 = c0 + 289; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-289+c0] + S[-c0+c1-289+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][288+c0] + S[288+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 210; c0 += 1)
    S[c0][c0+289] = MAX(S[c0][c0+289], S[c0+1][c0+289-1] + can_pair(RNA, c0, c0+289));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 209; c0 += 1)
    for (c1 = c0 + 290; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-290+c0] + S[-c0+c1-290+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][289+c0] + S[289+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 209; c0 += 1)
    S[c0][c0+290] = MAX(S[c0][c0+290], S[c0+1][c0+290-1] + can_pair(RNA, c0, c0+290));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 208; c0 += 1)
    for (c1 = c0 + 291; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-291+c0] + S[-c0+c1-291+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][290+c0] + S[290+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 208; c0 += 1)
    S[c0][c0+291] = MAX(S[c0][c0+291], S[c0+1][c0+291-1] + can_pair(RNA, c0, c0+291));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 207; c0 += 1)
    for (c1 = c0 + 292; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-292+c0] + S[-c0+c1-292+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][291+c0] + S[291+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 207; c0 += 1)
    S[c0][c0+292] = MAX(S[c0][c0+292], S[c0+1][c0+292-1] + can_pair(RNA, c0, c0+292));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 206; c0 += 1)
    for (c1 = c0 + 293; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-293+c0] + S[-c0+c1-293+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][292+c0] + S[292+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 206; c0 += 1)
    S[c0][c0+293] = MAX(S[c0][c0+293], S[c0+1][c0+293-1] + can_pair(RNA, c0, c0+293));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 205; c0 += 1)
    for (c1 = c0 + 294; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-294+c0] + S[-c0+c1-294+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][293+c0] + S[293+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 205; c0 += 1)
    S[c0][c0+294] = MAX(S[c0][c0+294], S[c0+1][c0+294-1] + can_pair(RNA, c0, c0+294));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 204; c0 += 1)
    for (c1 = c0 + 295; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-295+c0] + S[-c0+c1-295+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][294+c0] + S[294+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 204; c0 += 1)
    S[c0][c0+295] = MAX(S[c0][c0+295], S[c0+1][c0+295-1] + can_pair(RNA, c0, c0+295));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 203; c0 += 1)
    for (c1 = c0 + 296; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-296+c0] + S[-c0+c1-296+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][295+c0] + S[295+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 203; c0 += 1)
    S[c0][c0+296] = MAX(S[c0][c0+296], S[c0+1][c0+296-1] + can_pair(RNA, c0, c0+296));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 202; c0 += 1)
    for (c1 = c0 + 297; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-297+c0] + S[-c0+c1-297+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][296+c0] + S[296+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 202; c0 += 1)
    S[c0][c0+297] = MAX(S[c0][c0+297], S[c0+1][c0+297-1] + can_pair(RNA, c0, c0+297));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 201; c0 += 1)
    for (c1 = c0 + 298; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-298+c0] + S[-c0+c1-298+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][297+c0] + S[297+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 201; c0 += 1)
    S[c0][c0+298] = MAX(S[c0][c0+298], S[c0+1][c0+298-1] + can_pair(RNA, c0, c0+298));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 200; c0 += 1)
    for (c1 = c0 + 299; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-299+c0] + S[-c0+c1-299+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][298+c0] + S[298+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 200; c0 += 1)
    S[c0][c0+299] = MAX(S[c0][c0+299], S[c0+1][c0+299-1] + can_pair(RNA, c0, c0+299));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 199; c0 += 1)
    for (c1 = c0 + 300; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-300+c0] + S[-c0+c1-300+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][299+c0] + S[299+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 199; c0 += 1)
    S[c0][c0+300] = MAX(S[c0][c0+300], S[c0+1][c0+300-1] + can_pair(RNA, c0, c0+300));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 198; c0 += 1)
    for (c1 = c0 + 301; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-301+c0] + S[-c0+c1-301+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][300+c0] + S[300+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 198; c0 += 1)
    S[c0][c0+301] = MAX(S[c0][c0+301], S[c0+1][c0+301-1] + can_pair(RNA, c0, c0+301));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 197; c0 += 1)
    for (c1 = c0 + 302; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-302+c0] + S[-c0+c1-302+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][301+c0] + S[301+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 197; c0 += 1)
    S[c0][c0+302] = MAX(S[c0][c0+302], S[c0+1][c0+302-1] + can_pair(RNA, c0, c0+302));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 196; c0 += 1)
    for (c1 = c0 + 303; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-303+c0] + S[-c0+c1-303+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][302+c0] + S[302+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 196; c0 += 1)
    S[c0][c0+303] = MAX(S[c0][c0+303], S[c0+1][c0+303-1] + can_pair(RNA, c0, c0+303));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 195; c0 += 1)
    for (c1 = c0 + 304; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-304+c0] + S[-c0+c1-304+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][303+c0] + S[303+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 195; c0 += 1)
    S[c0][c0+304] = MAX(S[c0][c0+304], S[c0+1][c0+304-1] + can_pair(RNA, c0, c0+304));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 194; c0 += 1)
    for (c1 = c0 + 305; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-305+c0] + S[-c0+c1-305+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][304+c0] + S[304+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 194; c0 += 1)
    S[c0][c0+305] = MAX(S[c0][c0+305], S[c0+1][c0+305-1] + can_pair(RNA, c0, c0+305));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 193; c0 += 1)
    for (c1 = c0 + 306; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-306+c0] + S[-c0+c1-306+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][305+c0] + S[305+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 193; c0 += 1)
    S[c0][c0+306] = MAX(S[c0][c0+306], S[c0+1][c0+306-1] + can_pair(RNA, c0, c0+306));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 192; c0 += 1)
    for (c1 = c0 + 307; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-307+c0] + S[-c0+c1-307+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][306+c0] + S[306+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 192; c0 += 1)
    S[c0][c0+307] = MAX(S[c0][c0+307], S[c0+1][c0+307-1] + can_pair(RNA, c0, c0+307));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 191; c0 += 1)
    for (c1 = c0 + 308; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-308+c0] + S[-c0+c1-308+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][307+c0] + S[307+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 191; c0 += 1)
    S[c0][c0+308] = MAX(S[c0][c0+308], S[c0+1][c0+308-1] + can_pair(RNA, c0, c0+308));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 190; c0 += 1)
    for (c1 = c0 + 309; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-309+c0] + S[-c0+c1-309+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][308+c0] + S[308+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 190; c0 += 1)
    S[c0][c0+309] = MAX(S[c0][c0+309], S[c0+1][c0+309-1] + can_pair(RNA, c0, c0+309));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 189; c0 += 1)
    for (c1 = c0 + 310; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-310+c0] + S[-c0+c1-310+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][309+c0] + S[309+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 189; c0 += 1)
    S[c0][c0+310] = MAX(S[c0][c0+310], S[c0+1][c0+310-1] + can_pair(RNA, c0, c0+310));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 188; c0 += 1)
    for (c1 = c0 + 311; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-311+c0] + S[-c0+c1-311+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][310+c0] + S[310+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 188; c0 += 1)
    S[c0][c0+311] = MAX(S[c0][c0+311], S[c0+1][c0+311-1] + can_pair(RNA, c0, c0+311));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 187; c0 += 1)
    for (c1 = c0 + 312; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-312+c0] + S[-c0+c1-312+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][311+c0] + S[311+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 187; c0 += 1)
    S[c0][c0+312] = MAX(S[c0][c0+312], S[c0+1][c0+312-1] + can_pair(RNA, c0, c0+312));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 186; c0 += 1)
    for (c1 = c0 + 313; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-313+c0] + S[-c0+c1-313+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][312+c0] + S[312+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 186; c0 += 1)
    S[c0][c0+313] = MAX(S[c0][c0+313], S[c0+1][c0+313-1] + can_pair(RNA, c0, c0+313));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 185; c0 += 1)
    for (c1 = c0 + 314; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-314+c0] + S[-c0+c1-314+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][313+c0] + S[313+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 185; c0 += 1)
    S[c0][c0+314] = MAX(S[c0][c0+314], S[c0+1][c0+314-1] + can_pair(RNA, c0, c0+314));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 184; c0 += 1)
    for (c1 = c0 + 315; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-315+c0] + S[-c0+c1-315+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][314+c0] + S[314+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 184; c0 += 1)
    S[c0][c0+315] = MAX(S[c0][c0+315], S[c0+1][c0+315-1] + can_pair(RNA, c0, c0+315));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 183; c0 += 1)
    for (c1 = c0 + 316; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-316+c0] + S[-c0+c1-316+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][315+c0] + S[315+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 183; c0 += 1)
    S[c0][c0+316] = MAX(S[c0][c0+316], S[c0+1][c0+316-1] + can_pair(RNA, c0, c0+316));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 182; c0 += 1)
    for (c1 = c0 + 317; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-317+c0] + S[-c0+c1-317+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][316+c0] + S[316+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 182; c0 += 1)
    S[c0][c0+317] = MAX(S[c0][c0+317], S[c0+1][c0+317-1] + can_pair(RNA, c0, c0+317));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 181; c0 += 1)
    for (c1 = c0 + 318; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-318+c0] + S[-c0+c1-318+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][317+c0] + S[317+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 181; c0 += 1)
    S[c0][c0+318] = MAX(S[c0][c0+318], S[c0+1][c0+318-1] + can_pair(RNA, c0, c0+318));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 180; c0 += 1)
    for (c1 = c0 + 319; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-319+c0] + S[-c0+c1-319+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][318+c0] + S[318+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 180; c0 += 1)
    S[c0][c0+319] = MAX(S[c0][c0+319], S[c0+1][c0+319-1] + can_pair(RNA, c0, c0+319));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 179; c0 += 1)
    for (c1 = c0 + 320; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-320+c0] + S[-c0+c1-320+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][319+c0] + S[319+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 179; c0 += 1)
    S[c0][c0+320] = MAX(S[c0][c0+320], S[c0+1][c0+320-1] + can_pair(RNA, c0, c0+320));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 178; c0 += 1)
    for (c1 = c0 + 321; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-321+c0] + S[-c0+c1-321+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][320+c0] + S[320+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 178; c0 += 1)
    S[c0][c0+321] = MAX(S[c0][c0+321], S[c0+1][c0+321-1] + can_pair(RNA, c0, c0+321));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 177; c0 += 1)
    for (c1 = c0 + 322; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-322+c0] + S[-c0+c1-322+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][321+c0] + S[321+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 177; c0 += 1)
    S[c0][c0+322] = MAX(S[c0][c0+322], S[c0+1][c0+322-1] + can_pair(RNA, c0, c0+322));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 176; c0 += 1)
    for (c1 = c0 + 323; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-323+c0] + S[-c0+c1-323+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][322+c0] + S[322+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 176; c0 += 1)
    S[c0][c0+323] = MAX(S[c0][c0+323], S[c0+1][c0+323-1] + can_pair(RNA, c0, c0+323));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 175; c0 += 1)
    for (c1 = c0 + 324; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-324+c0] + S[-c0+c1-324+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][323+c0] + S[323+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 175; c0 += 1)
    S[c0][c0+324] = MAX(S[c0][c0+324], S[c0+1][c0+324-1] + can_pair(RNA, c0, c0+324));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 174; c0 += 1)
    for (c1 = c0 + 325; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-325+c0] + S[-c0+c1-325+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][324+c0] + S[324+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 174; c0 += 1)
    S[c0][c0+325] = MAX(S[c0][c0+325], S[c0+1][c0+325-1] + can_pair(RNA, c0, c0+325));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 173; c0 += 1)
    for (c1 = c0 + 326; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-326+c0] + S[-c0+c1-326+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][325+c0] + S[325+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 173; c0 += 1)
    S[c0][c0+326] = MAX(S[c0][c0+326], S[c0+1][c0+326-1] + can_pair(RNA, c0, c0+326));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 172; c0 += 1)
    for (c1 = c0 + 327; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-327+c0] + S[-c0+c1-327+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][326+c0] + S[326+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 172; c0 += 1)
    S[c0][c0+327] = MAX(S[c0][c0+327], S[c0+1][c0+327-1] + can_pair(RNA, c0, c0+327));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 171; c0 += 1)
    for (c1 = c0 + 328; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-328+c0] + S[-c0+c1-328+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][327+c0] + S[327+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 171; c0 += 1)
    S[c0][c0+328] = MAX(S[c0][c0+328], S[c0+1][c0+328-1] + can_pair(RNA, c0, c0+328));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 170; c0 += 1)
    for (c1 = c0 + 329; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-329+c0] + S[-c0+c1-329+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][328+c0] + S[328+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 170; c0 += 1)
    S[c0][c0+329] = MAX(S[c0][c0+329], S[c0+1][c0+329-1] + can_pair(RNA, c0, c0+329));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 169; c0 += 1)
    for (c1 = c0 + 330; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-330+c0] + S[-c0+c1-330+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][329+c0] + S[329+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 169; c0 += 1)
    S[c0][c0+330] = MAX(S[c0][c0+330], S[c0+1][c0+330-1] + can_pair(RNA, c0, c0+330));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 168; c0 += 1)
    for (c1 = c0 + 331; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-331+c0] + S[-c0+c1-331+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][330+c0] + S[330+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 168; c0 += 1)
    S[c0][c0+331] = MAX(S[c0][c0+331], S[c0+1][c0+331-1] + can_pair(RNA, c0, c0+331));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 167; c0 += 1)
    for (c1 = c0 + 332; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-332+c0] + S[-c0+c1-332+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][331+c0] + S[331+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 167; c0 += 1)
    S[c0][c0+332] = MAX(S[c0][c0+332], S[c0+1][c0+332-1] + can_pair(RNA, c0, c0+332));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 166; c0 += 1)
    for (c1 = c0 + 333; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-333+c0] + S[-c0+c1-333+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][332+c0] + S[332+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 166; c0 += 1)
    S[c0][c0+333] = MAX(S[c0][c0+333], S[c0+1][c0+333-1] + can_pair(RNA, c0, c0+333));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 165; c0 += 1)
    for (c1 = c0 + 334; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-334+c0] + S[-c0+c1-334+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][333+c0] + S[333+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 165; c0 += 1)
    S[c0][c0+334] = MAX(S[c0][c0+334], S[c0+1][c0+334-1] + can_pair(RNA, c0, c0+334));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 164; c0 += 1)
    for (c1 = c0 + 335; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-335+c0] + S[-c0+c1-335+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][334+c0] + S[334+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 164; c0 += 1)
    S[c0][c0+335] = MAX(S[c0][c0+335], S[c0+1][c0+335-1] + can_pair(RNA, c0, c0+335));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 163; c0 += 1)
    for (c1 = c0 + 336; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-336+c0] + S[-c0+c1-336+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][335+c0] + S[335+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 163; c0 += 1)
    S[c0][c0+336] = MAX(S[c0][c0+336], S[c0+1][c0+336-1] + can_pair(RNA, c0, c0+336));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 162; c0 += 1)
    for (c1 = c0 + 337; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-337+c0] + S[-c0+c1-337+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][336+c0] + S[336+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 162; c0 += 1)
    S[c0][c0+337] = MAX(S[c0][c0+337], S[c0+1][c0+337-1] + can_pair(RNA, c0, c0+337));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 161; c0 += 1)
    for (c1 = c0 + 338; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-338+c0] + S[-c0+c1-338+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][337+c0] + S[337+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 161; c0 += 1)
    S[c0][c0+338] = MAX(S[c0][c0+338], S[c0+1][c0+338-1] + can_pair(RNA, c0, c0+338));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 160; c0 += 1)
    for (c1 = c0 + 339; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-339+c0] + S[-c0+c1-339+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][338+c0] + S[338+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 160; c0 += 1)
    S[c0][c0+339] = MAX(S[c0][c0+339], S[c0+1][c0+339-1] + can_pair(RNA, c0, c0+339));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 159; c0 += 1)
    for (c1 = c0 + 340; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-340+c0] + S[-c0+c1-340+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][339+c0] + S[339+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 159; c0 += 1)
    S[c0][c0+340] = MAX(S[c0][c0+340], S[c0+1][c0+340-1] + can_pair(RNA, c0, c0+340));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 158; c0 += 1)
    for (c1 = c0 + 341; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-341+c0] + S[-c0+c1-341+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][340+c0] + S[340+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 158; c0 += 1)
    S[c0][c0+341] = MAX(S[c0][c0+341], S[c0+1][c0+341-1] + can_pair(RNA, c0, c0+341));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 157; c0 += 1)
    for (c1 = c0 + 342; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-342+c0] + S[-c0+c1-342+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][341+c0] + S[341+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 157; c0 += 1)
    S[c0][c0+342] = MAX(S[c0][c0+342], S[c0+1][c0+342-1] + can_pair(RNA, c0, c0+342));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 156; c0 += 1)
    for (c1 = c0 + 343; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-343+c0] + S[-c0+c1-343+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][342+c0] + S[342+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 156; c0 += 1)
    S[c0][c0+343] = MAX(S[c0][c0+343], S[c0+1][c0+343-1] + can_pair(RNA, c0, c0+343));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 155; c0 += 1)
    for (c1 = c0 + 344; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-344+c0] + S[-c0+c1-344+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][343+c0] + S[343+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 155; c0 += 1)
    S[c0][c0+344] = MAX(S[c0][c0+344], S[c0+1][c0+344-1] + can_pair(RNA, c0, c0+344));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 154; c0 += 1)
    for (c1 = c0 + 345; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-345+c0] + S[-c0+c1-345+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][344+c0] + S[344+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 154; c0 += 1)
    S[c0][c0+345] = MAX(S[c0][c0+345], S[c0+1][c0+345-1] + can_pair(RNA, c0, c0+345));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 153; c0 += 1)
    for (c1 = c0 + 346; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-346+c0] + S[-c0+c1-346+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][345+c0] + S[345+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 153; c0 += 1)
    S[c0][c0+346] = MAX(S[c0][c0+346], S[c0+1][c0+346-1] + can_pair(RNA, c0, c0+346));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 152; c0 += 1)
    for (c1 = c0 + 347; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-347+c0] + S[-c0+c1-347+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][346+c0] + S[346+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 152; c0 += 1)
    S[c0][c0+347] = MAX(S[c0][c0+347], S[c0+1][c0+347-1] + can_pair(RNA, c0, c0+347));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 151; c0 += 1)
    for (c1 = c0 + 348; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-348+c0] + S[-c0+c1-348+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][347+c0] + S[347+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 151; c0 += 1)
    S[c0][c0+348] = MAX(S[c0][c0+348], S[c0+1][c0+348-1] + can_pair(RNA, c0, c0+348));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 150; c0 += 1)
    for (c1 = c0 + 349; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-349+c0] + S[-c0+c1-349+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][348+c0] + S[348+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 150; c0 += 1)
    S[c0][c0+349] = MAX(S[c0][c0+349], S[c0+1][c0+349-1] + can_pair(RNA, c0, c0+349));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 149; c0 += 1)
    for (c1 = c0 + 350; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-350+c0] + S[-c0+c1-350+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][349+c0] + S[349+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 149; c0 += 1)
    S[c0][c0+350] = MAX(S[c0][c0+350], S[c0+1][c0+350-1] + can_pair(RNA, c0, c0+350));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 148; c0 += 1)
    for (c1 = c0 + 351; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-351+c0] + S[-c0+c1-351+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][350+c0] + S[350+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 148; c0 += 1)
    S[c0][c0+351] = MAX(S[c0][c0+351], S[c0+1][c0+351-1] + can_pair(RNA, c0, c0+351));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 147; c0 += 1)
    for (c1 = c0 + 352; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-352+c0] + S[-c0+c1-352+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][351+c0] + S[351+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 147; c0 += 1)
    S[c0][c0+352] = MAX(S[c0][c0+352], S[c0+1][c0+352-1] + can_pair(RNA, c0, c0+352));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 146; c0 += 1)
    for (c1 = c0 + 353; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-353+c0] + S[-c0+c1-353+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][352+c0] + S[352+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 146; c0 += 1)
    S[c0][c0+353] = MAX(S[c0][c0+353], S[c0+1][c0+353-1] + can_pair(RNA, c0, c0+353));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 145; c0 += 1)
    for (c1 = c0 + 354; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-354+c0] + S[-c0+c1-354+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][353+c0] + S[353+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 145; c0 += 1)
    S[c0][c0+354] = MAX(S[c0][c0+354], S[c0+1][c0+354-1] + can_pair(RNA, c0, c0+354));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 144; c0 += 1)
    for (c1 = c0 + 355; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-355+c0] + S[-c0+c1-355+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][354+c0] + S[354+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 144; c0 += 1)
    S[c0][c0+355] = MAX(S[c0][c0+355], S[c0+1][c0+355-1] + can_pair(RNA, c0, c0+355));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 143; c0 += 1)
    for (c1 = c0 + 356; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-356+c0] + S[-c0+c1-356+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][355+c0] + S[355+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 143; c0 += 1)
    S[c0][c0+356] = MAX(S[c0][c0+356], S[c0+1][c0+356-1] + can_pair(RNA, c0, c0+356));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 142; c0 += 1)
    for (c1 = c0 + 357; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-357+c0] + S[-c0+c1-357+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][356+c0] + S[356+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 142; c0 += 1)
    S[c0][c0+357] = MAX(S[c0][c0+357], S[c0+1][c0+357-1] + can_pair(RNA, c0, c0+357));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 141; c0 += 1)
    for (c1 = c0 + 358; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-358+c0] + S[-c0+c1-358+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][357+c0] + S[357+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 141; c0 += 1)
    S[c0][c0+358] = MAX(S[c0][c0+358], S[c0+1][c0+358-1] + can_pair(RNA, c0, c0+358));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 140; c0 += 1)
    for (c1 = c0 + 359; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-359+c0] + S[-c0+c1-359+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][358+c0] + S[358+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 140; c0 += 1)
    S[c0][c0+359] = MAX(S[c0][c0+359], S[c0+1][c0+359-1] + can_pair(RNA, c0, c0+359));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 139; c0 += 1)
    for (c1 = c0 + 360; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-360+c0] + S[-c0+c1-360+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][359+c0] + S[359+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 139; c0 += 1)
    S[c0][c0+360] = MAX(S[c0][c0+360], S[c0+1][c0+360-1] + can_pair(RNA, c0, c0+360));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 138; c0 += 1)
    for (c1 = c0 + 361; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-361+c0] + S[-c0+c1-361+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][360+c0] + S[360+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 138; c0 += 1)
    S[c0][c0+361] = MAX(S[c0][c0+361], S[c0+1][c0+361-1] + can_pair(RNA, c0, c0+361));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 137; c0 += 1)
    for (c1 = c0 + 362; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-362+c0] + S[-c0+c1-362+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][361+c0] + S[361+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 137; c0 += 1)
    S[c0][c0+362] = MAX(S[c0][c0+362], S[c0+1][c0+362-1] + can_pair(RNA, c0, c0+362));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 136; c0 += 1)
    for (c1 = c0 + 363; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-363+c0] + S[-c0+c1-363+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][362+c0] + S[362+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 136; c0 += 1)
    S[c0][c0+363] = MAX(S[c0][c0+363], S[c0+1][c0+363-1] + can_pair(RNA, c0, c0+363));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 135; c0 += 1)
    for (c1 = c0 + 364; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-364+c0] + S[-c0+c1-364+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][363+c0] + S[363+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 135; c0 += 1)
    S[c0][c0+364] = MAX(S[c0][c0+364], S[c0+1][c0+364-1] + can_pair(RNA, c0, c0+364));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 134; c0 += 1)
    for (c1 = c0 + 365; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-365+c0] + S[-c0+c1-365+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][364+c0] + S[364+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 134; c0 += 1)
    S[c0][c0+365] = MAX(S[c0][c0+365], S[c0+1][c0+365-1] + can_pair(RNA, c0, c0+365));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 133; c0 += 1)
    for (c1 = c0 + 366; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-366+c0] + S[-c0+c1-366+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][365+c0] + S[365+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 133; c0 += 1)
    S[c0][c0+366] = MAX(S[c0][c0+366], S[c0+1][c0+366-1] + can_pair(RNA, c0, c0+366));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 132; c0 += 1)
    for (c1 = c0 + 367; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-367+c0] + S[-c0+c1-367+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][366+c0] + S[366+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 132; c0 += 1)
    S[c0][c0+367] = MAX(S[c0][c0+367], S[c0+1][c0+367-1] + can_pair(RNA, c0, c0+367));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 131; c0 += 1)
    for (c1 = c0 + 368; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-368+c0] + S[-c0+c1-368+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][367+c0] + S[367+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 131; c0 += 1)
    S[c0][c0+368] = MAX(S[c0][c0+368], S[c0+1][c0+368-1] + can_pair(RNA, c0, c0+368));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 130; c0 += 1)
    for (c1 = c0 + 369; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-369+c0] + S[-c0+c1-369+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][368+c0] + S[368+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 130; c0 += 1)
    S[c0][c0+369] = MAX(S[c0][c0+369], S[c0+1][c0+369-1] + can_pair(RNA, c0, c0+369));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 129; c0 += 1)
    for (c1 = c0 + 370; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-370+c0] + S[-c0+c1-370+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][369+c0] + S[369+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 129; c0 += 1)
    S[c0][c0+370] = MAX(S[c0][c0+370], S[c0+1][c0+370-1] + can_pair(RNA, c0, c0+370));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 128; c0 += 1)
    for (c1 = c0 + 371; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-371+c0] + S[-c0+c1-371+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][370+c0] + S[370+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 128; c0 += 1)
    S[c0][c0+371] = MAX(S[c0][c0+371], S[c0+1][c0+371-1] + can_pair(RNA, c0, c0+371));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 127; c0 += 1)
    for (c1 = c0 + 372; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-372+c0] + S[-c0+c1-372+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][371+c0] + S[371+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 127; c0 += 1)
    S[c0][c0+372] = MAX(S[c0][c0+372], S[c0+1][c0+372-1] + can_pair(RNA, c0, c0+372));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 126; c0 += 1)
    for (c1 = c0 + 373; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-373+c0] + S[-c0+c1-373+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][372+c0] + S[372+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 126; c0 += 1)
    S[c0][c0+373] = MAX(S[c0][c0+373], S[c0+1][c0+373-1] + can_pair(RNA, c0, c0+373));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 125; c0 += 1)
    for (c1 = c0 + 374; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-374+c0] + S[-c0+c1-374+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][373+c0] + S[373+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 125; c0 += 1)
    S[c0][c0+374] = MAX(S[c0][c0+374], S[c0+1][c0+374-1] + can_pair(RNA, c0, c0+374));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 124; c0 += 1)
    for (c1 = c0 + 375; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-375+c0] + S[-c0+c1-375+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][374+c0] + S[374+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 124; c0 += 1)
    S[c0][c0+375] = MAX(S[c0][c0+375], S[c0+1][c0+375-1] + can_pair(RNA, c0, c0+375));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 123; c0 += 1)
    for (c1 = c0 + 376; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-376+c0] + S[-c0+c1-376+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][375+c0] + S[375+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 123; c0 += 1)
    S[c0][c0+376] = MAX(S[c0][c0+376], S[c0+1][c0+376-1] + can_pair(RNA, c0, c0+376));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 122; c0 += 1)
    for (c1 = c0 + 377; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-377+c0] + S[-c0+c1-377+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][376+c0] + S[376+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 122; c0 += 1)
    S[c0][c0+377] = MAX(S[c0][c0+377], S[c0+1][c0+377-1] + can_pair(RNA, c0, c0+377));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 121; c0 += 1)
    for (c1 = c0 + 378; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-378+c0] + S[-c0+c1-378+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][377+c0] + S[377+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 121; c0 += 1)
    S[c0][c0+378] = MAX(S[c0][c0+378], S[c0+1][c0+378-1] + can_pair(RNA, c0, c0+378));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 120; c0 += 1)
    for (c1 = c0 + 379; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-379+c0] + S[-c0+c1-379+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][378+c0] + S[378+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 120; c0 += 1)
    S[c0][c0+379] = MAX(S[c0][c0+379], S[c0+1][c0+379-1] + can_pair(RNA, c0, c0+379));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 119; c0 += 1)
    for (c1 = c0 + 380; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-380+c0] + S[-c0+c1-380+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][379+c0] + S[379+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 119; c0 += 1)
    S[c0][c0+380] = MAX(S[c0][c0+380], S[c0+1][c0+380-1] + can_pair(RNA, c0, c0+380));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 118; c0 += 1)
    for (c1 = c0 + 381; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-381+c0] + S[-c0+c1-381+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][380+c0] + S[380+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 118; c0 += 1)
    S[c0][c0+381] = MAX(S[c0][c0+381], S[c0+1][c0+381-1] + can_pair(RNA, c0, c0+381));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 117; c0 += 1)
    for (c1 = c0 + 382; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-382+c0] + S[-c0+c1-382+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][381+c0] + S[381+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 117; c0 += 1)
    S[c0][c0+382] = MAX(S[c0][c0+382], S[c0+1][c0+382-1] + can_pair(RNA, c0, c0+382));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 116; c0 += 1)
    for (c1 = c0 + 383; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-383+c0] + S[-c0+c1-383+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][382+c0] + S[382+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 116; c0 += 1)
    S[c0][c0+383] = MAX(S[c0][c0+383], S[c0+1][c0+383-1] + can_pair(RNA, c0, c0+383));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 115; c0 += 1)
    for (c1 = c0 + 384; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-384+c0] + S[-c0+c1-384+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][383+c0] + S[383+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 115; c0 += 1)
    S[c0][c0+384] = MAX(S[c0][c0+384], S[c0+1][c0+384-1] + can_pair(RNA, c0, c0+384));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 114; c0 += 1)
    for (c1 = c0 + 385; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-385+c0] + S[-c0+c1-385+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][384+c0] + S[384+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 114; c0 += 1)
    S[c0][c0+385] = MAX(S[c0][c0+385], S[c0+1][c0+385-1] + can_pair(RNA, c0, c0+385));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 113; c0 += 1)
    for (c1 = c0 + 386; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-386+c0] + S[-c0+c1-386+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][385+c0] + S[385+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 113; c0 += 1)
    S[c0][c0+386] = MAX(S[c0][c0+386], S[c0+1][c0+386-1] + can_pair(RNA, c0, c0+386));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 112; c0 += 1)
    for (c1 = c0 + 387; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-387+c0] + S[-c0+c1-387+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][386+c0] + S[386+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 112; c0 += 1)
    S[c0][c0+387] = MAX(S[c0][c0+387], S[c0+1][c0+387-1] + can_pair(RNA, c0, c0+387));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 111; c0 += 1)
    for (c1 = c0 + 388; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-388+c0] + S[-c0+c1-388+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][387+c0] + S[387+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 111; c0 += 1)
    S[c0][c0+388] = MAX(S[c0][c0+388], S[c0+1][c0+388-1] + can_pair(RNA, c0, c0+388));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 110; c0 += 1)
    for (c1 = c0 + 389; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-389+c0] + S[-c0+c1-389+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][388+c0] + S[388+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 110; c0 += 1)
    S[c0][c0+389] = MAX(S[c0][c0+389], S[c0+1][c0+389-1] + can_pair(RNA, c0, c0+389));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 109; c0 += 1)
    for (c1 = c0 + 390; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-390+c0] + S[-c0+c1-390+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][389+c0] + S[389+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 109; c0 += 1)
    S[c0][c0+390] = MAX(S[c0][c0+390], S[c0+1][c0+390-1] + can_pair(RNA, c0, c0+390));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 108; c0 += 1)
    for (c1 = c0 + 391; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-391+c0] + S[-c0+c1-391+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][390+c0] + S[390+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 108; c0 += 1)
    S[c0][c0+391] = MAX(S[c0][c0+391], S[c0+1][c0+391-1] + can_pair(RNA, c0, c0+391));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 107; c0 += 1)
    for (c1 = c0 + 392; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-392+c0] + S[-c0+c1-392+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][391+c0] + S[391+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 107; c0 += 1)
    S[c0][c0+392] = MAX(S[c0][c0+392], S[c0+1][c0+392-1] + can_pair(RNA, c0, c0+392));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 106; c0 += 1)
    for (c1 = c0 + 393; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-393+c0] + S[-c0+c1-393+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][392+c0] + S[392+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 106; c0 += 1)
    S[c0][c0+393] = MAX(S[c0][c0+393], S[c0+1][c0+393-1] + can_pair(RNA, c0, c0+393));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 105; c0 += 1)
    for (c1 = c0 + 394; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-394+c0] + S[-c0+c1-394+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][393+c0] + S[393+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 105; c0 += 1)
    S[c0][c0+394] = MAX(S[c0][c0+394], S[c0+1][c0+394-1] + can_pair(RNA, c0, c0+394));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 104; c0 += 1)
    for (c1 = c0 + 395; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-395+c0] + S[-c0+c1-395+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][394+c0] + S[394+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 104; c0 += 1)
    S[c0][c0+395] = MAX(S[c0][c0+395], S[c0+1][c0+395-1] + can_pair(RNA, c0, c0+395));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 103; c0 += 1)
    for (c1 = c0 + 396; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-396+c0] + S[-c0+c1-396+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][395+c0] + S[395+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 103; c0 += 1)
    S[c0][c0+396] = MAX(S[c0][c0+396], S[c0+1][c0+396-1] + can_pair(RNA, c0, c0+396));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 102; c0 += 1)
    for (c1 = c0 + 397; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-397+c0] + S[-c0+c1-397+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][396+c0] + S[396+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 102; c0 += 1)
    S[c0][c0+397] = MAX(S[c0][c0+397], S[c0+1][c0+397-1] + can_pair(RNA, c0, c0+397));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 101; c0 += 1)
    for (c1 = c0 + 398; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-398+c0] + S[-c0+c1-398+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][397+c0] + S[397+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 101; c0 += 1)
    S[c0][c0+398] = MAX(S[c0][c0+398], S[c0+1][c0+398-1] + can_pair(RNA, c0, c0+398));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 100; c0 += 1)
    for (c1 = c0 + 399; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-399+c0] + S[-c0+c1-399+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][398+c0] + S[398+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 100; c0 += 1)
    S[c0][c0+399] = MAX(S[c0][c0+399], S[c0+1][c0+399-1] + can_pair(RNA, c0, c0+399));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 99; c0 += 1)
    for (c1 = c0 + 400; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-400+c0] + S[-c0+c1-400+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][399+c0] + S[399+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 99; c0 += 1)
    S[c0][c0+400] = MAX(S[c0][c0+400], S[c0+1][c0+400-1] + can_pair(RNA, c0, c0+400));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 98; c0 += 1)
    for (c1 = c0 + 401; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-401+c0] + S[-c0+c1-401+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][400+c0] + S[400+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 98; c0 += 1)
    S[c0][c0+401] = MAX(S[c0][c0+401], S[c0+1][c0+401-1] + can_pair(RNA, c0, c0+401));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 97; c0 += 1)
    for (c1 = c0 + 402; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-402+c0] + S[-c0+c1-402+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][401+c0] + S[401+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 97; c0 += 1)
    S[c0][c0+402] = MAX(S[c0][c0+402], S[c0+1][c0+402-1] + can_pair(RNA, c0, c0+402));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 96; c0 += 1)
    for (c1 = c0 + 403; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-403+c0] + S[-c0+c1-403+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][402+c0] + S[402+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 96; c0 += 1)
    S[c0][c0+403] = MAX(S[c0][c0+403], S[c0+1][c0+403-1] + can_pair(RNA, c0, c0+403));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 95; c0 += 1)
    for (c1 = c0 + 404; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-404+c0] + S[-c0+c1-404+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][403+c0] + S[403+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 95; c0 += 1)
    S[c0][c0+404] = MAX(S[c0][c0+404], S[c0+1][c0+404-1] + can_pair(RNA, c0, c0+404));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 94; c0 += 1)
    for (c1 = c0 + 405; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-405+c0] + S[-c0+c1-405+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][404+c0] + S[404+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 94; c0 += 1)
    S[c0][c0+405] = MAX(S[c0][c0+405], S[c0+1][c0+405-1] + can_pair(RNA, c0, c0+405));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 93; c0 += 1)
    for (c1 = c0 + 406; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-406+c0] + S[-c0+c1-406+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][405+c0] + S[405+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 93; c0 += 1)
    S[c0][c0+406] = MAX(S[c0][c0+406], S[c0+1][c0+406-1] + can_pair(RNA, c0, c0+406));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 92; c0 += 1)
    for (c1 = c0 + 407; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-407+c0] + S[-c0+c1-407+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][406+c0] + S[406+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 92; c0 += 1)
    S[c0][c0+407] = MAX(S[c0][c0+407], S[c0+1][c0+407-1] + can_pair(RNA, c0, c0+407));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 91; c0 += 1)
    for (c1 = c0 + 408; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-408+c0] + S[-c0+c1-408+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][407+c0] + S[407+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 91; c0 += 1)
    S[c0][c0+408] = MAX(S[c0][c0+408], S[c0+1][c0+408-1] + can_pair(RNA, c0, c0+408));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 90; c0 += 1)
    for (c1 = c0 + 409; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-409+c0] + S[-c0+c1-409+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][408+c0] + S[408+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 90; c0 += 1)
    S[c0][c0+409] = MAX(S[c0][c0+409], S[c0+1][c0+409-1] + can_pair(RNA, c0, c0+409));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 89; c0 += 1)
    for (c1 = c0 + 410; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-410+c0] + S[-c0+c1-410+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][409+c0] + S[409+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 89; c0 += 1)
    S[c0][c0+410] = MAX(S[c0][c0+410], S[c0+1][c0+410-1] + can_pair(RNA, c0, c0+410));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 88; c0 += 1)
    for (c1 = c0 + 411; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-411+c0] + S[-c0+c1-411+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][410+c0] + S[410+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 88; c0 += 1)
    S[c0][c0+411] = MAX(S[c0][c0+411], S[c0+1][c0+411-1] + can_pair(RNA, c0, c0+411));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 87; c0 += 1)
    for (c1 = c0 + 412; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-412+c0] + S[-c0+c1-412+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][411+c0] + S[411+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 87; c0 += 1)
    S[c0][c0+412] = MAX(S[c0][c0+412], S[c0+1][c0+412-1] + can_pair(RNA, c0, c0+412));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 86; c0 += 1)
    for (c1 = c0 + 413; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-413+c0] + S[-c0+c1-413+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][412+c0] + S[412+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 86; c0 += 1)
    S[c0][c0+413] = MAX(S[c0][c0+413], S[c0+1][c0+413-1] + can_pair(RNA, c0, c0+413));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 85; c0 += 1)
    for (c1 = c0 + 414; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-414+c0] + S[-c0+c1-414+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][413+c0] + S[413+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 85; c0 += 1)
    S[c0][c0+414] = MAX(S[c0][c0+414], S[c0+1][c0+414-1] + can_pair(RNA, c0, c0+414));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 84; c0 += 1)
    for (c1 = c0 + 415; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-415+c0] + S[-c0+c1-415+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][414+c0] + S[414+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 84; c0 += 1)
    S[c0][c0+415] = MAX(S[c0][c0+415], S[c0+1][c0+415-1] + can_pair(RNA, c0, c0+415));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 83; c0 += 1)
    for (c1 = c0 + 416; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-416+c0] + S[-c0+c1-416+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][415+c0] + S[415+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 83; c0 += 1)
    S[c0][c0+416] = MAX(S[c0][c0+416], S[c0+1][c0+416-1] + can_pair(RNA, c0, c0+416));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 82; c0 += 1)
    for (c1 = c0 + 417; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-417+c0] + S[-c0+c1-417+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][416+c0] + S[416+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 82; c0 += 1)
    S[c0][c0+417] = MAX(S[c0][c0+417], S[c0+1][c0+417-1] + can_pair(RNA, c0, c0+417));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 81; c0 += 1)
    for (c1 = c0 + 418; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-418+c0] + S[-c0+c1-418+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][417+c0] + S[417+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 81; c0 += 1)
    S[c0][c0+418] = MAX(S[c0][c0+418], S[c0+1][c0+418-1] + can_pair(RNA, c0, c0+418));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 80; c0 += 1)
    for (c1 = c0 + 419; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-419+c0] + S[-c0+c1-419+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][418+c0] + S[418+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 80; c0 += 1)
    S[c0][c0+419] = MAX(S[c0][c0+419], S[c0+1][c0+419-1] + can_pair(RNA, c0, c0+419));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 79; c0 += 1)
    for (c1 = c0 + 420; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-420+c0] + S[-c0+c1-420+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][419+c0] + S[419+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 79; c0 += 1)
    S[c0][c0+420] = MAX(S[c0][c0+420], S[c0+1][c0+420-1] + can_pair(RNA, c0, c0+420));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 78; c0 += 1)
    for (c1 = c0 + 421; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-421+c0] + S[-c0+c1-421+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][420+c0] + S[420+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 78; c0 += 1)
    S[c0][c0+421] = MAX(S[c0][c0+421], S[c0+1][c0+421-1] + can_pair(RNA, c0, c0+421));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 77; c0 += 1)
    for (c1 = c0 + 422; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-422+c0] + S[-c0+c1-422+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][421+c0] + S[421+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 77; c0 += 1)
    S[c0][c0+422] = MAX(S[c0][c0+422], S[c0+1][c0+422-1] + can_pair(RNA, c0, c0+422));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 76; c0 += 1)
    for (c1 = c0 + 423; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-423+c0] + S[-c0+c1-423+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][422+c0] + S[422+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 76; c0 += 1)
    S[c0][c0+423] = MAX(S[c0][c0+423], S[c0+1][c0+423-1] + can_pair(RNA, c0, c0+423));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 75; c0 += 1)
    for (c1 = c0 + 424; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-424+c0] + S[-c0+c1-424+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][423+c0] + S[423+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 75; c0 += 1)
    S[c0][c0+424] = MAX(S[c0][c0+424], S[c0+1][c0+424-1] + can_pair(RNA, c0, c0+424));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 74; c0 += 1)
    for (c1 = c0 + 425; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-425+c0] + S[-c0+c1-425+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][424+c0] + S[424+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 74; c0 += 1)
    S[c0][c0+425] = MAX(S[c0][c0+425], S[c0+1][c0+425-1] + can_pair(RNA, c0, c0+425));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 73; c0 += 1)
    for (c1 = c0 + 426; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-426+c0] + S[-c0+c1-426+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][425+c0] + S[425+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 73; c0 += 1)
    S[c0][c0+426] = MAX(S[c0][c0+426], S[c0+1][c0+426-1] + can_pair(RNA, c0, c0+426));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 72; c0 += 1)
    for (c1 = c0 + 427; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-427+c0] + S[-c0+c1-427+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][426+c0] + S[426+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 72; c0 += 1)
    S[c0][c0+427] = MAX(S[c0][c0+427], S[c0+1][c0+427-1] + can_pair(RNA, c0, c0+427));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 71; c0 += 1)
    for (c1 = c0 + 428; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-428+c0] + S[-c0+c1-428+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][427+c0] + S[427+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 71; c0 += 1)
    S[c0][c0+428] = MAX(S[c0][c0+428], S[c0+1][c0+428-1] + can_pair(RNA, c0, c0+428));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 70; c0 += 1)
    for (c1 = c0 + 429; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-429+c0] + S[-c0+c1-429+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][428+c0] + S[428+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 70; c0 += 1)
    S[c0][c0+429] = MAX(S[c0][c0+429], S[c0+1][c0+429-1] + can_pair(RNA, c0, c0+429));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 69; c0 += 1)
    for (c1 = c0 + 430; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-430+c0] + S[-c0+c1-430+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][429+c0] + S[429+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 69; c0 += 1)
    S[c0][c0+430] = MAX(S[c0][c0+430], S[c0+1][c0+430-1] + can_pair(RNA, c0, c0+430));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 68; c0 += 1)
    for (c1 = c0 + 431; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-431+c0] + S[-c0+c1-431+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][430+c0] + S[430+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 68; c0 += 1)
    S[c0][c0+431] = MAX(S[c0][c0+431], S[c0+1][c0+431-1] + can_pair(RNA, c0, c0+431));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 67; c0 += 1)
    for (c1 = c0 + 432; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-432+c0] + S[-c0+c1-432+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][431+c0] + S[431+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 67; c0 += 1)
    S[c0][c0+432] = MAX(S[c0][c0+432], S[c0+1][c0+432-1] + can_pair(RNA, c0, c0+432));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 66; c0 += 1)
    for (c1 = c0 + 433; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-433+c0] + S[-c0+c1-433+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][432+c0] + S[432+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 66; c0 += 1)
    S[c0][c0+433] = MAX(S[c0][c0+433], S[c0+1][c0+433-1] + can_pair(RNA, c0, c0+433));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 65; c0 += 1)
    for (c1 = c0 + 434; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-434+c0] + S[-c0+c1-434+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][433+c0] + S[433+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 65; c0 += 1)
    S[c0][c0+434] = MAX(S[c0][c0+434], S[c0+1][c0+434-1] + can_pair(RNA, c0, c0+434));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 64; c0 += 1)
    for (c1 = c0 + 435; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-435+c0] + S[-c0+c1-435+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][434+c0] + S[434+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 64; c0 += 1)
    S[c0][c0+435] = MAX(S[c0][c0+435], S[c0+1][c0+435-1] + can_pair(RNA, c0, c0+435));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 63; c0 += 1)
    for (c1 = c0 + 436; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-436+c0] + S[-c0+c1-436+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][435+c0] + S[435+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 63; c0 += 1)
    S[c0][c0+436] = MAX(S[c0][c0+436], S[c0+1][c0+436-1] + can_pair(RNA, c0, c0+436));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 62; c0 += 1)
    for (c1 = c0 + 437; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-437+c0] + S[-c0+c1-437+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][436+c0] + S[436+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 62; c0 += 1)
    S[c0][c0+437] = MAX(S[c0][c0+437], S[c0+1][c0+437-1] + can_pair(RNA, c0, c0+437));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 61; c0 += 1)
    for (c1 = c0 + 438; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-438+c0] + S[-c0+c1-438+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][437+c0] + S[437+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 61; c0 += 1)
    S[c0][c0+438] = MAX(S[c0][c0+438], S[c0+1][c0+438-1] + can_pair(RNA, c0, c0+438));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 60; c0 += 1)
    for (c1 = c0 + 439; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-439+c0] + S[-c0+c1-439+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][438+c0] + S[438+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 60; c0 += 1)
    S[c0][c0+439] = MAX(S[c0][c0+439], S[c0+1][c0+439-1] + can_pair(RNA, c0, c0+439));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 59; c0 += 1)
    for (c1 = c0 + 440; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-440+c0] + S[-c0+c1-440+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][439+c0] + S[439+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 59; c0 += 1)
    S[c0][c0+440] = MAX(S[c0][c0+440], S[c0+1][c0+440-1] + can_pair(RNA, c0, c0+440));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 58; c0 += 1)
    for (c1 = c0 + 441; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-441+c0] + S[-c0+c1-441+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][440+c0] + S[440+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 58; c0 += 1)
    S[c0][c0+441] = MAX(S[c0][c0+441], S[c0+1][c0+441-1] + can_pair(RNA, c0, c0+441));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 57; c0 += 1)
    for (c1 = c0 + 442; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-442+c0] + S[-c0+c1-442+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][441+c0] + S[441+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 57; c0 += 1)
    S[c0][c0+442] = MAX(S[c0][c0+442], S[c0+1][c0+442-1] + can_pair(RNA, c0, c0+442));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 56; c0 += 1)
    for (c1 = c0 + 443; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-443+c0] + S[-c0+c1-443+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][442+c0] + S[442+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 56; c0 += 1)
    S[c0][c0+443] = MAX(S[c0][c0+443], S[c0+1][c0+443-1] + can_pair(RNA, c0, c0+443));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 55; c0 += 1)
    for (c1 = c0 + 444; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-444+c0] + S[-c0+c1-444+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][443+c0] + S[443+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 55; c0 += 1)
    S[c0][c0+444] = MAX(S[c0][c0+444], S[c0+1][c0+444-1] + can_pair(RNA, c0, c0+444));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 54; c0 += 1)
    for (c1 = c0 + 445; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-445+c0] + S[-c0+c1-445+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][444+c0] + S[444+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 54; c0 += 1)
    S[c0][c0+445] = MAX(S[c0][c0+445], S[c0+1][c0+445-1] + can_pair(RNA, c0, c0+445));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 53; c0 += 1)
    for (c1 = c0 + 446; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-446+c0] + S[-c0+c1-446+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][445+c0] + S[445+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 53; c0 += 1)
    S[c0][c0+446] = MAX(S[c0][c0+446], S[c0+1][c0+446-1] + can_pair(RNA, c0, c0+446));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 52; c0 += 1)
    for (c1 = c0 + 447; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-447+c0] + S[-c0+c1-447+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][446+c0] + S[446+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 52; c0 += 1)
    S[c0][c0+447] = MAX(S[c0][c0+447], S[c0+1][c0+447-1] + can_pair(RNA, c0, c0+447));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 51; c0 += 1)
    for (c1 = c0 + 448; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-448+c0] + S[-c0+c1-448+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][447+c0] + S[447+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 51; c0 += 1)
    S[c0][c0+448] = MAX(S[c0][c0+448], S[c0+1][c0+448-1] + can_pair(RNA, c0, c0+448));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 50; c0 += 1)
    for (c1 = c0 + 449; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-449+c0] + S[-c0+c1-449+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][448+c0] + S[448+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 50; c0 += 1)
    S[c0][c0+449] = MAX(S[c0][c0+449], S[c0+1][c0+449-1] + can_pair(RNA, c0, c0+449));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 49; c0 += 1)
    for (c1 = c0 + 450; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-450+c0] + S[-c0+c1-450+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][449+c0] + S[449+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 49; c0 += 1)
    S[c0][c0+450] = MAX(S[c0][c0+450], S[c0+1][c0+450-1] + can_pair(RNA, c0, c0+450));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 48; c0 += 1)
    for (c1 = c0 + 451; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-451+c0] + S[-c0+c1-451+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][450+c0] + S[450+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 48; c0 += 1)
    S[c0][c0+451] = MAX(S[c0][c0+451], S[c0+1][c0+451-1] + can_pair(RNA, c0, c0+451));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 47; c0 += 1)
    for (c1 = c0 + 452; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-452+c0] + S[-c0+c1-452+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][451+c0] + S[451+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 47; c0 += 1)
    S[c0][c0+452] = MAX(S[c0][c0+452], S[c0+1][c0+452-1] + can_pair(RNA, c0, c0+452));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 46; c0 += 1)
    for (c1 = c0 + 453; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-453+c0] + S[-c0+c1-453+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][452+c0] + S[452+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 46; c0 += 1)
    S[c0][c0+453] = MAX(S[c0][c0+453], S[c0+1][c0+453-1] + can_pair(RNA, c0, c0+453));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 45; c0 += 1)
    for (c1 = c0 + 454; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-454+c0] + S[-c0+c1-454+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][453+c0] + S[453+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 45; c0 += 1)
    S[c0][c0+454] = MAX(S[c0][c0+454], S[c0+1][c0+454-1] + can_pair(RNA, c0, c0+454));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 44; c0 += 1)
    for (c1 = c0 + 455; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-455+c0] + S[-c0+c1-455+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][454+c0] + S[454+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 44; c0 += 1)
    S[c0][c0+455] = MAX(S[c0][c0+455], S[c0+1][c0+455-1] + can_pair(RNA, c0, c0+455));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 43; c0 += 1)
    for (c1 = c0 + 456; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-456+c0] + S[-c0+c1-456+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][455+c0] + S[455+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 43; c0 += 1)
    S[c0][c0+456] = MAX(S[c0][c0+456], S[c0+1][c0+456-1] + can_pair(RNA, c0, c0+456));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 42; c0 += 1)
    for (c1 = c0 + 457; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-457+c0] + S[-c0+c1-457+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][456+c0] + S[456+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 42; c0 += 1)
    S[c0][c0+457] = MAX(S[c0][c0+457], S[c0+1][c0+457-1] + can_pair(RNA, c0, c0+457));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 41; c0 += 1)
    for (c1 = c0 + 458; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-458+c0] + S[-c0+c1-458+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][457+c0] + S[457+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 41; c0 += 1)
    S[c0][c0+458] = MAX(S[c0][c0+458], S[c0+1][c0+458-1] + can_pair(RNA, c0, c0+458));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 40; c0 += 1)
    for (c1 = c0 + 459; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-459+c0] + S[-c0+c1-459+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][458+c0] + S[458+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 40; c0 += 1)
    S[c0][c0+459] = MAX(S[c0][c0+459], S[c0+1][c0+459-1] + can_pair(RNA, c0, c0+459));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 39; c0 += 1)
    for (c1 = c0 + 460; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-460+c0] + S[-c0+c1-460+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][459+c0] + S[459+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 39; c0 += 1)
    S[c0][c0+460] = MAX(S[c0][c0+460], S[c0+1][c0+460-1] + can_pair(RNA, c0, c0+460));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 38; c0 += 1)
    for (c1 = c0 + 461; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-461+c0] + S[-c0+c1-461+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][460+c0] + S[460+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 38; c0 += 1)
    S[c0][c0+461] = MAX(S[c0][c0+461], S[c0+1][c0+461-1] + can_pair(RNA, c0, c0+461));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 37; c0 += 1)
    for (c1 = c0 + 462; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-462+c0] + S[-c0+c1-462+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][461+c0] + S[461+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 37; c0 += 1)
    S[c0][c0+462] = MAX(S[c0][c0+462], S[c0+1][c0+462-1] + can_pair(RNA, c0, c0+462));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 36; c0 += 1)
    for (c1 = c0 + 463; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-463+c0] + S[-c0+c1-463+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][462+c0] + S[462+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 36; c0 += 1)
    S[c0][c0+463] = MAX(S[c0][c0+463], S[c0+1][c0+463-1] + can_pair(RNA, c0, c0+463));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 35; c0 += 1)
    for (c1 = c0 + 464; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-464+c0] + S[-c0+c1-464+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][463+c0] + S[463+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 35; c0 += 1)
    S[c0][c0+464] = MAX(S[c0][c0+464], S[c0+1][c0+464-1] + can_pair(RNA, c0, c0+464));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 34; c0 += 1)
    for (c1 = c0 + 465; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-465+c0] + S[-c0+c1-465+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][464+c0] + S[464+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 34; c0 += 1)
    S[c0][c0+465] = MAX(S[c0][c0+465], S[c0+1][c0+465-1] + can_pair(RNA, c0, c0+465));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 33; c0 += 1)
    for (c1 = c0 + 466; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-466+c0] + S[-c0+c1-466+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][465+c0] + S[465+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 33; c0 += 1)
    S[c0][c0+466] = MAX(S[c0][c0+466], S[c0+1][c0+466-1] + can_pair(RNA, c0, c0+466));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 32; c0 += 1)
    for (c1 = c0 + 467; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-467+c0] + S[-c0+c1-467+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][466+c0] + S[466+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 32; c0 += 1)
    S[c0][c0+467] = MAX(S[c0][c0+467], S[c0+1][c0+467-1] + can_pair(RNA, c0, c0+467));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 31; c0 += 1)
    for (c1 = c0 + 468; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-468+c0] + S[-c0+c1-468+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][467+c0] + S[467+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 31; c0 += 1)
    S[c0][c0+468] = MAX(S[c0][c0+468], S[c0+1][c0+468-1] + can_pair(RNA, c0, c0+468));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 30; c0 += 1)
    for (c1 = c0 + 469; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-469+c0] + S[-c0+c1-469+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][468+c0] + S[468+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 30; c0 += 1)
    S[c0][c0+469] = MAX(S[c0][c0+469], S[c0+1][c0+469-1] + can_pair(RNA, c0, c0+469));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 29; c0 += 1)
    for (c1 = c0 + 470; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-470+c0] + S[-c0+c1-470+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][469+c0] + S[469+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 29; c0 += 1)
    S[c0][c0+470] = MAX(S[c0][c0+470], S[c0+1][c0+470-1] + can_pair(RNA, c0, c0+470));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 28; c0 += 1)
    for (c1 = c0 + 471; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-471+c0] + S[-c0+c1-471+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][470+c0] + S[470+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 28; c0 += 1)
    S[c0][c0+471] = MAX(S[c0][c0+471], S[c0+1][c0+471-1] + can_pair(RNA, c0, c0+471));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 27; c0 += 1)
    for (c1 = c0 + 472; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-472+c0] + S[-c0+c1-472+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][471+c0] + S[471+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 27; c0 += 1)
    S[c0][c0+472] = MAX(S[c0][c0+472], S[c0+1][c0+472-1] + can_pair(RNA, c0, c0+472));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 26; c0 += 1)
    for (c1 = c0 + 473; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-473+c0] + S[-c0+c1-473+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][472+c0] + S[472+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 26; c0 += 1)
    S[c0][c0+473] = MAX(S[c0][c0+473], S[c0+1][c0+473-1] + can_pair(RNA, c0, c0+473));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 25; c0 += 1)
    for (c1 = c0 + 474; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-474+c0] + S[-c0+c1-474+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][473+c0] + S[473+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 25; c0 += 1)
    S[c0][c0+474] = MAX(S[c0][c0+474], S[c0+1][c0+474-1] + can_pair(RNA, c0, c0+474));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 24; c0 += 1)
    for (c1 = c0 + 475; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-475+c0] + S[-c0+c1-475+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][474+c0] + S[474+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 24; c0 += 1)
    S[c0][c0+475] = MAX(S[c0][c0+475], S[c0+1][c0+475-1] + can_pair(RNA, c0, c0+475));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 23; c0 += 1)
    for (c1 = c0 + 476; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-476+c0] + S[-c0+c1-476+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][475+c0] + S[475+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 23; c0 += 1)
    S[c0][c0+476] = MAX(S[c0][c0+476], S[c0+1][c0+476-1] + can_pair(RNA, c0, c0+476));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 22; c0 += 1)
    for (c1 = c0 + 477; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-477+c0] + S[-c0+c1-477+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][476+c0] + S[476+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 22; c0 += 1)
    S[c0][c0+477] = MAX(S[c0][c0+477], S[c0+1][c0+477-1] + can_pair(RNA, c0, c0+477));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 21; c0 += 1)
    for (c1 = c0 + 478; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-478+c0] + S[-c0+c1-478+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][477+c0] + S[477+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 21; c0 += 1)
    S[c0][c0+478] = MAX(S[c0][c0+478], S[c0+1][c0+478-1] + can_pair(RNA, c0, c0+478));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 20; c0 += 1)
    for (c1 = c0 + 479; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-479+c0] + S[-c0+c1-479+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][478+c0] + S[478+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 20; c0 += 1)
    S[c0][c0+479] = MAX(S[c0][c0+479], S[c0+1][c0+479-1] + can_pair(RNA, c0, c0+479));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 19; c0 += 1)
    for (c1 = c0 + 480; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-480+c0] + S[-c0+c1-480+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][479+c0] + S[479+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 19; c0 += 1)
    S[c0][c0+480] = MAX(S[c0][c0+480], S[c0+1][c0+480-1] + can_pair(RNA, c0, c0+480));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 18; c0 += 1)
    for (c1 = c0 + 481; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-481+c0] + S[-c0+c1-481+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][480+c0] + S[480+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 18; c0 += 1)
    S[c0][c0+481] = MAX(S[c0][c0+481], S[c0+1][c0+481-1] + can_pair(RNA, c0, c0+481));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 17; c0 += 1)
    for (c1 = c0 + 482; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-482+c0] + S[-c0+c1-482+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][481+c0] + S[481+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 17; c0 += 1)
    S[c0][c0+482] = MAX(S[c0][c0+482], S[c0+1][c0+482-1] + can_pair(RNA, c0, c0+482));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 16; c0 += 1)
    for (c1 = c0 + 483; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-483+c0] + S[-c0+c1-483+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][482+c0] + S[482+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 16; c0 += 1)
    S[c0][c0+483] = MAX(S[c0][c0+483], S[c0+1][c0+483-1] + can_pair(RNA, c0, c0+483));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 15; c0 += 1)
    for (c1 = c0 + 484; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-484+c0] + S[-c0+c1-484+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][483+c0] + S[483+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 15; c0 += 1)
    S[c0][c0+484] = MAX(S[c0][c0+484], S[c0+1][c0+484-1] + can_pair(RNA, c0, c0+484));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 14; c0 += 1)
    for (c1 = c0 + 485; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-485+c0] + S[-c0+c1-485+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][484+c0] + S[484+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 14; c0 += 1)
    S[c0][c0+485] = MAX(S[c0][c0+485], S[c0+1][c0+485-1] + can_pair(RNA, c0, c0+485));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 13; c0 += 1)
    for (c1 = c0 + 486; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-486+c0] + S[-c0+c1-486+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][485+c0] + S[485+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 13; c0 += 1)
    S[c0][c0+486] = MAX(S[c0][c0+486], S[c0+1][c0+486-1] + can_pair(RNA, c0, c0+486));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 12; c0 += 1)
    for (c1 = c0 + 487; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-487+c0] + S[-c0+c1-487+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][486+c0] + S[486+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 12; c0 += 1)
    S[c0][c0+487] = MAX(S[c0][c0+487], S[c0+1][c0+487-1] + can_pair(RNA, c0, c0+487));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 11; c0 += 1)
    for (c1 = c0 + 488; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-488+c0] + S[-c0+c1-488+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][487+c0] + S[487+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 11; c0 += 1)
    S[c0][c0+488] = MAX(S[c0][c0+488], S[c0+1][c0+488-1] + can_pair(RNA, c0, c0+488));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 10; c0 += 1)
    for (c1 = c0 + 489; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-489+c0] + S[-c0+c1-489+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][488+c0] + S[488+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 10; c0 += 1)
    S[c0][c0+489] = MAX(S[c0][c0+489], S[c0+1][c0+489-1] + can_pair(RNA, c0, c0+489));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 9; c0 += 1)
    for (c1 = c0 + 490; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-490+c0] + S[-c0+c1-490+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][489+c0] + S[489+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 9; c0 += 1)
    S[c0][c0+490] = MAX(S[c0][c0+490], S[c0+1][c0+490-1] + can_pair(RNA, c0, c0+490));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 8; c0 += 1)
    for (c1 = c0 + 491; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-491+c0] + S[-c0+c1-491+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][490+c0] + S[490+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 8; c0 += 1)
    S[c0][c0+491] = MAX(S[c0][c0+491], S[c0+1][c0+491-1] + can_pair(RNA, c0, c0+491));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 7; c0 += 1)
    for (c1 = c0 + 492; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-492+c0] + S[-c0+c1-492+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][491+c0] + S[491+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 7; c0 += 1)
    S[c0][c0+492] = MAX(S[c0][c0+492], S[c0+1][c0+492-1] + can_pair(RNA, c0, c0+492));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 6; c0 += 1)
    for (c1 = c0 + 493; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-493+c0] + S[-c0+c1-493+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][492+c0] + S[492+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 6; c0 += 1)
    S[c0][c0+493] = MAX(S[c0][c0+493], S[c0+1][c0+493-1] + can_pair(RNA, c0, c0+493));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 5; c0 += 1)
    for (c1 = c0 + 494; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-494+c0] + S[-c0+c1-494+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][493+c0] + S[493+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 5; c0 += 1)
    S[c0][c0+494] = MAX(S[c0][c0+494], S[c0+1][c0+494-1] + can_pair(RNA, c0, c0+494));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 4; c0 += 1)
    for (c1 = c0 + 495; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-495+c0] + S[-c0+c1-495+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][494+c0] + S[494+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 4; c0 += 1)
    S[c0][c0+495] = MAX(S[c0][c0+495], S[c0+1][c0+495-1] + can_pair(RNA, c0, c0+495));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 3; c0 += 1)
    for (c1 = c0 + 496; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-496+c0] + S[-c0+c1-496+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][495+c0] + S[495+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 3; c0 += 1)
    S[c0][c0+496] = MAX(S[c0][c0+496], S[c0+1][c0+496-1] + can_pair(RNA, c0, c0+496));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 2; c0 += 1)
    for (c1 = c0 + 497; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-497+c0] + S[-c0+c1-497+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][496+c0] + S[496+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 2; c0 += 1)
    S[c0][c0+497] = MAX(S[c0][c0+497], S[c0+1][c0+497-1] + can_pair(RNA, c0, c0+497));
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 1; c0 += 1)
    for (c1 = c0 + 498; c1 <= 499; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-498+c0] + S[-c0+c1-498+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][497+c0] + S[497+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp for
  for (c0 = 0; c0 <= 1; c0 += 1)
    if (c0 == 1) {
      S[1][499] = MAX(S[1][499], S[1+1][499-1] + can_pair(RNA, 1, 499));
    } else
      S[0][498] = MAX(S[0][498], S[0+1][498-1] + can_pair(RNA, 0, 498));
// --------------
if (N == 500) {
  S[0][499] = MAX(S[0][0+0] + S[0+0+1][499], S[0][499]);
  S[0][499] = MAX(S[0][498+0] + S[498+0+1][499], S[0][499]);
}
// --------------
  S[0][499] = MAX(S[0][499], S[0+1][499-1] + can_pair(RNA, 0, 499));
// --------------

}


    end = omp_get_wtime();
	printf("%.6f\n", end - start);

    return 0;


}

