#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define MAX(x,y)    ((x) > (y)? (x) : (y))
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

int N = 1000;

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

    omp_set_num_threads(num_proc);

    start = omp_get_wtime();

#pragma omp parallel shared(S,RNA)
{
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1998; c0 += 1)
    S[c0][c0+1] = MAX(S[c0][c0+1], S[c0+1][c0+1-1] + can_pair(RNA, c0, c0+1));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1997; c0 += 1)
    for (c1 = c0 + 2; c1 <= min(c0 + 3, 1999); c1 += 1) {
      if (c1 == c0 + 2)
        S[c0][c0+2] = MAX(S[c0][0+c0] + S[0+c0+1][c0+2], S[c0][c0+2]);
      S[c0][c1] = MAX(S[c0][1+c0] + S[1+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1997; c0 += 1)
    S[c0][c0+2] = MAX(S[c0][c0+2], S[c0+1][c0+2-1] + can_pair(RNA, c0, c0+2));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1996; c0 += 1)
    for (c1 = c0 + 3; c1 <= min(c0 + 5, 1999); c1 += 1) {
      if (c0 + 4 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-3+c0] + S[-c0+c1-3+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][2+c0] + S[2+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1996; c0 += 1)
    S[c0][c0+3] = MAX(S[c0][c0+3], S[c0+1][c0+3-1] + can_pair(RNA, c0, c0+3));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1995; c0 += 1)
    for (c1 = c0 + 4; c1 <= min(c0 + 7, 1999); c1 += 1) {
      if (c0 + 6 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-4+c0] + S[-c0+c1-4+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][3+c0] + S[3+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1995; c0 += 1)
    S[c0][c0+4] = MAX(S[c0][c0+4], S[c0+1][c0+4-1] + can_pair(RNA, c0, c0+4));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1994; c0 += 1)
    for (c1 = c0 + 5; c1 <= min(c0 + 9, 1999); c1 += 1) {
      if (c0 + 8 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-5+c0] + S[-c0+c1-5+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][4+c0] + S[4+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1994; c0 += 1)
    S[c0][c0+5] = MAX(S[c0][c0+5], S[c0+1][c0+5-1] + can_pair(RNA, c0, c0+5));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1993; c0 += 1)
    for (c1 = c0 + 6; c1 <= min(c0 + 11, 1999); c1 += 1) {
      if (c0 + 10 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-6+c0] + S[-c0+c1-6+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][5+c0] + S[5+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1993; c0 += 1)
    S[c0][c0+6] = MAX(S[c0][c0+6], S[c0+1][c0+6-1] + can_pair(RNA, c0, c0+6));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1992; c0 += 1)
    for (c1 = c0 + 7; c1 <= min(c0 + 13, 1999); c1 += 1) {
      if (c0 + 12 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-7+c0] + S[-c0+c1-7+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][6+c0] + S[6+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1992; c0 += 1)
    S[c0][c0+7] = MAX(S[c0][c0+7], S[c0+1][c0+7-1] + can_pair(RNA, c0, c0+7));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1991; c0 += 1)
    for (c1 = c0 + 8; c1 <= min(c0 + 15, 1999); c1 += 1) {
      if (c0 + 14 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-8+c0] + S[-c0+c1-8+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][7+c0] + S[7+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1991; c0 += 1)
    S[c0][c0+8] = MAX(S[c0][c0+8], S[c0+1][c0+8-1] + can_pair(RNA, c0, c0+8));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1990; c0 += 1)
    for (c1 = c0 + 9; c1 <= min(c0 + 17, 1999); c1 += 1) {
      if (c0 + 16 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-9+c0] + S[-c0+c1-9+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][8+c0] + S[8+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1990; c0 += 1)
    S[c0][c0+9] = MAX(S[c0][c0+9], S[c0+1][c0+9-1] + can_pair(RNA, c0, c0+9));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1989; c0 += 1)
    for (c1 = c0 + 10; c1 <= min(c0 + 19, 1999); c1 += 1) {
      if (c0 + 18 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-10+c0] + S[-c0+c1-10+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][9+c0] + S[9+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1989; c0 += 1)
    S[c0][c0+10] = MAX(S[c0][c0+10], S[c0+1][c0+10-1] + can_pair(RNA, c0, c0+10));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1988; c0 += 1)
    for (c1 = c0 + 11; c1 <= min(c0 + 21, 1999); c1 += 1) {
      if (c0 + 20 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-11+c0] + S[-c0+c1-11+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][10+c0] + S[10+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1988; c0 += 1)
    S[c0][c0+11] = MAX(S[c0][c0+11], S[c0+1][c0+11-1] + can_pair(RNA, c0, c0+11));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1987; c0 += 1)
    for (c1 = c0 + 12; c1 <= min(c0 + 23, 1999); c1 += 1) {
      if (c0 + 22 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-12+c0] + S[-c0+c1-12+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][11+c0] + S[11+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1987; c0 += 1)
    S[c0][c0+12] = MAX(S[c0][c0+12], S[c0+1][c0+12-1] + can_pair(RNA, c0, c0+12));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1986; c0 += 1)
    for (c1 = c0 + 13; c1 <= min(c0 + 25, 1999); c1 += 1) {
      if (c0 + 24 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-13+c0] + S[-c0+c1-13+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][12+c0] + S[12+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1986; c0 += 1)
    S[c0][c0+13] = MAX(S[c0][c0+13], S[c0+1][c0+13-1] + can_pair(RNA, c0, c0+13));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1985; c0 += 1)
    for (c1 = c0 + 14; c1 <= min(c0 + 27, 1999); c1 += 1) {
      if (c0 + 26 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-14+c0] + S[-c0+c1-14+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][13+c0] + S[13+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1985; c0 += 1)
    S[c0][c0+14] = MAX(S[c0][c0+14], S[c0+1][c0+14-1] + can_pair(RNA, c0, c0+14));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1984; c0 += 1)
    for (c1 = c0 + 15; c1 <= min(c0 + 29, 1999); c1 += 1) {
      if (c0 + 28 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-15+c0] + S[-c0+c1-15+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][14+c0] + S[14+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1984; c0 += 1)
    S[c0][c0+15] = MAX(S[c0][c0+15], S[c0+1][c0+15-1] + can_pair(RNA, c0, c0+15));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1983; c0 += 1)
    for (c1 = c0 + 16; c1 <= min(c0 + 31, 1999); c1 += 1) {
      if (c0 + 30 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-16+c0] + S[-c0+c1-16+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][15+c0] + S[15+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1983; c0 += 1)
    S[c0][c0+16] = MAX(S[c0][c0+16], S[c0+1][c0+16-1] + can_pair(RNA, c0, c0+16));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1982; c0 += 1)
    for (c1 = c0 + 17; c1 <= min(c0 + 33, 1999); c1 += 1) {
      if (c0 + 32 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-17+c0] + S[-c0+c1-17+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][16+c0] + S[16+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1982; c0 += 1)
    S[c0][c0+17] = MAX(S[c0][c0+17], S[c0+1][c0+17-1] + can_pair(RNA, c0, c0+17));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1981; c0 += 1)
    for (c1 = c0 + 18; c1 <= min(c0 + 35, 1999); c1 += 1) {
      if (c0 + 34 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-18+c0] + S[-c0+c1-18+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][17+c0] + S[17+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1981; c0 += 1)
    S[c0][c0+18] = MAX(S[c0][c0+18], S[c0+1][c0+18-1] + can_pair(RNA, c0, c0+18));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1980; c0 += 1)
    for (c1 = c0 + 19; c1 <= min(c0 + 37, 1999); c1 += 1) {
      if (c0 + 36 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-19+c0] + S[-c0+c1-19+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][18+c0] + S[18+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1980; c0 += 1)
    S[c0][c0+19] = MAX(S[c0][c0+19], S[c0+1][c0+19-1] + can_pair(RNA, c0, c0+19));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1979; c0 += 1)
    for (c1 = c0 + 20; c1 <= min(c0 + 39, 1999); c1 += 1) {
      if (c0 + 38 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-20+c0] + S[-c0+c1-20+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][19+c0] + S[19+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1979; c0 += 1)
    S[c0][c0+20] = MAX(S[c0][c0+20], S[c0+1][c0+20-1] + can_pair(RNA, c0, c0+20));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1978; c0 += 1)
    for (c1 = c0 + 21; c1 <= min(c0 + 41, 1999); c1 += 1) {
      if (c0 + 40 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-21+c0] + S[-c0+c1-21+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][20+c0] + S[20+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1978; c0 += 1)
    S[c0][c0+21] = MAX(S[c0][c0+21], S[c0+1][c0+21-1] + can_pair(RNA, c0, c0+21));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1977; c0 += 1)
    for (c1 = c0 + 22; c1 <= min(c0 + 43, 1999); c1 += 1) {
      if (c0 + 42 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-22+c0] + S[-c0+c1-22+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][21+c0] + S[21+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1977; c0 += 1)
    S[c0][c0+22] = MAX(S[c0][c0+22], S[c0+1][c0+22-1] + can_pair(RNA, c0, c0+22));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1976; c0 += 1)
    for (c1 = c0 + 23; c1 <= min(c0 + 45, 1999); c1 += 1) {
      if (c0 + 44 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-23+c0] + S[-c0+c1-23+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][22+c0] + S[22+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1976; c0 += 1)
    S[c0][c0+23] = MAX(S[c0][c0+23], S[c0+1][c0+23-1] + can_pair(RNA, c0, c0+23));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1975; c0 += 1)
    for (c1 = c0 + 24; c1 <= min(c0 + 47, 1999); c1 += 1) {
      if (c0 + 46 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-24+c0] + S[-c0+c1-24+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][23+c0] + S[23+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1975; c0 += 1)
    S[c0][c0+24] = MAX(S[c0][c0+24], S[c0+1][c0+24-1] + can_pair(RNA, c0, c0+24));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1974; c0 += 1)
    for (c1 = c0 + 25; c1 <= min(c0 + 49, 1999); c1 += 1) {
      if (c0 + 48 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-25+c0] + S[-c0+c1-25+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][24+c0] + S[24+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1974; c0 += 1)
    S[c0][c0+25] = MAX(S[c0][c0+25], S[c0+1][c0+25-1] + can_pair(RNA, c0, c0+25));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1973; c0 += 1)
    for (c1 = c0 + 26; c1 <= min(c0 + 51, 1999); c1 += 1) {
      if (c0 + 50 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-26+c0] + S[-c0+c1-26+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][25+c0] + S[25+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1973; c0 += 1)
    S[c0][c0+26] = MAX(S[c0][c0+26], S[c0+1][c0+26-1] + can_pair(RNA, c0, c0+26));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1972; c0 += 1)
    for (c1 = c0 + 27; c1 <= min(c0 + 53, 1999); c1 += 1) {
      if (c0 + 52 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-27+c0] + S[-c0+c1-27+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][26+c0] + S[26+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1972; c0 += 1)
    S[c0][c0+27] = MAX(S[c0][c0+27], S[c0+1][c0+27-1] + can_pair(RNA, c0, c0+27));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1971; c0 += 1)
    for (c1 = c0 + 28; c1 <= min(c0 + 55, 1999); c1 += 1) {
      if (c0 + 54 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-28+c0] + S[-c0+c1-28+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][27+c0] + S[27+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1971; c0 += 1)
    S[c0][c0+28] = MAX(S[c0][c0+28], S[c0+1][c0+28-1] + can_pair(RNA, c0, c0+28));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1970; c0 += 1)
    for (c1 = c0 + 29; c1 <= min(c0 + 57, 1999); c1 += 1) {
      if (c0 + 56 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-29+c0] + S[-c0+c1-29+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][28+c0] + S[28+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1970; c0 += 1)
    S[c0][c0+29] = MAX(S[c0][c0+29], S[c0+1][c0+29-1] + can_pair(RNA, c0, c0+29));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1969; c0 += 1)
    for (c1 = c0 + 30; c1 <= min(c0 + 59, 1999); c1 += 1) {
      if (c0 + 58 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-30+c0] + S[-c0+c1-30+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][29+c0] + S[29+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1969; c0 += 1)
    S[c0][c0+30] = MAX(S[c0][c0+30], S[c0+1][c0+30-1] + can_pair(RNA, c0, c0+30));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1968; c0 += 1)
    for (c1 = c0 + 31; c1 <= min(c0 + 61, 1999); c1 += 1) {
      if (c0 + 60 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-31+c0] + S[-c0+c1-31+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][30+c0] + S[30+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1968; c0 += 1)
    S[c0][c0+31] = MAX(S[c0][c0+31], S[c0+1][c0+31-1] + can_pair(RNA, c0, c0+31));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1967; c0 += 1)
    for (c1 = c0 + 32; c1 <= min(c0 + 63, 1999); c1 += 1) {
      if (c0 + 62 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-32+c0] + S[-c0+c1-32+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][31+c0] + S[31+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1967; c0 += 1)
    S[c0][c0+32] = MAX(S[c0][c0+32], S[c0+1][c0+32-1] + can_pair(RNA, c0, c0+32));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1966; c0 += 1)
    for (c1 = c0 + 33; c1 <= min(c0 + 65, 1999); c1 += 1) {
      if (c0 + 64 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-33+c0] + S[-c0+c1-33+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][32+c0] + S[32+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1966; c0 += 1)
    S[c0][c0+33] = MAX(S[c0][c0+33], S[c0+1][c0+33-1] + can_pair(RNA, c0, c0+33));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1965; c0 += 1)
    for (c1 = c0 + 34; c1 <= min(c0 + 67, 1999); c1 += 1) {
      if (c0 + 66 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-34+c0] + S[-c0+c1-34+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][33+c0] + S[33+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1965; c0 += 1)
    S[c0][c0+34] = MAX(S[c0][c0+34], S[c0+1][c0+34-1] + can_pair(RNA, c0, c0+34));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1964; c0 += 1)
    for (c1 = c0 + 35; c1 <= min(c0 + 69, 1999); c1 += 1) {
      if (c0 + 68 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-35+c0] + S[-c0+c1-35+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][34+c0] + S[34+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1964; c0 += 1)
    S[c0][c0+35] = MAX(S[c0][c0+35], S[c0+1][c0+35-1] + can_pair(RNA, c0, c0+35));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1963; c0 += 1)
    for (c1 = c0 + 36; c1 <= min(c0 + 71, 1999); c1 += 1) {
      if (c0 + 70 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-36+c0] + S[-c0+c1-36+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][35+c0] + S[35+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1963; c0 += 1)
    S[c0][c0+36] = MAX(S[c0][c0+36], S[c0+1][c0+36-1] + can_pair(RNA, c0, c0+36));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1962; c0 += 1)
    for (c1 = c0 + 37; c1 <= min(c0 + 73, 1999); c1 += 1) {
      if (c0 + 72 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-37+c0] + S[-c0+c1-37+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][36+c0] + S[36+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1962; c0 += 1)
    S[c0][c0+37] = MAX(S[c0][c0+37], S[c0+1][c0+37-1] + can_pair(RNA, c0, c0+37));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1961; c0 += 1)
    for (c1 = c0 + 38; c1 <= min(c0 + 75, 1999); c1 += 1) {
      if (c0 + 74 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-38+c0] + S[-c0+c1-38+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][37+c0] + S[37+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1961; c0 += 1)
    S[c0][c0+38] = MAX(S[c0][c0+38], S[c0+1][c0+38-1] + can_pair(RNA, c0, c0+38));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1960; c0 += 1)
    for (c1 = c0 + 39; c1 <= min(c0 + 77, 1999); c1 += 1) {
      if (c0 + 76 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-39+c0] + S[-c0+c1-39+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][38+c0] + S[38+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1960; c0 += 1)
    S[c0][c0+39] = MAX(S[c0][c0+39], S[c0+1][c0+39-1] + can_pair(RNA, c0, c0+39));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1959; c0 += 1)
    for (c1 = c0 + 40; c1 <= min(c0 + 79, 1999); c1 += 1) {
      if (c0 + 78 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-40+c0] + S[-c0+c1-40+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][39+c0] + S[39+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1959; c0 += 1)
    S[c0][c0+40] = MAX(S[c0][c0+40], S[c0+1][c0+40-1] + can_pair(RNA, c0, c0+40));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1958; c0 += 1)
    for (c1 = c0 + 41; c1 <= min(c0 + 81, 1999); c1 += 1) {
      if (c0 + 80 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-41+c0] + S[-c0+c1-41+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][40+c0] + S[40+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1958; c0 += 1)
    S[c0][c0+41] = MAX(S[c0][c0+41], S[c0+1][c0+41-1] + can_pair(RNA, c0, c0+41));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1957; c0 += 1)
    for (c1 = c0 + 42; c1 <= min(c0 + 83, 1999); c1 += 1) {
      if (c0 + 82 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-42+c0] + S[-c0+c1-42+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][41+c0] + S[41+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1957; c0 += 1)
    S[c0][c0+42] = MAX(S[c0][c0+42], S[c0+1][c0+42-1] + can_pair(RNA, c0, c0+42));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1956; c0 += 1)
    for (c1 = c0 + 43; c1 <= min(c0 + 85, 1999); c1 += 1) {
      if (c0 + 84 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-43+c0] + S[-c0+c1-43+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][42+c0] + S[42+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1956; c0 += 1)
    S[c0][c0+43] = MAX(S[c0][c0+43], S[c0+1][c0+43-1] + can_pair(RNA, c0, c0+43));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1955; c0 += 1)
    for (c1 = c0 + 44; c1 <= min(c0 + 87, 1999); c1 += 1) {
      if (c0 + 86 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-44+c0] + S[-c0+c1-44+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][43+c0] + S[43+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1955; c0 += 1)
    S[c0][c0+44] = MAX(S[c0][c0+44], S[c0+1][c0+44-1] + can_pair(RNA, c0, c0+44));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1954; c0 += 1)
    for (c1 = c0 + 45; c1 <= min(c0 + 89, 1999); c1 += 1) {
      if (c0 + 88 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-45+c0] + S[-c0+c1-45+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][44+c0] + S[44+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1954; c0 += 1)
    S[c0][c0+45] = MAX(S[c0][c0+45], S[c0+1][c0+45-1] + can_pair(RNA, c0, c0+45));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1953; c0 += 1)
    for (c1 = c0 + 46; c1 <= min(c0 + 91, 1999); c1 += 1) {
      if (c0 + 90 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-46+c0] + S[-c0+c1-46+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][45+c0] + S[45+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1953; c0 += 1)
    S[c0][c0+46] = MAX(S[c0][c0+46], S[c0+1][c0+46-1] + can_pair(RNA, c0, c0+46));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1952; c0 += 1)
    for (c1 = c0 + 47; c1 <= min(c0 + 93, 1999); c1 += 1) {
      if (c0 + 92 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-47+c0] + S[-c0+c1-47+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][46+c0] + S[46+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1952; c0 += 1)
    S[c0][c0+47] = MAX(S[c0][c0+47], S[c0+1][c0+47-1] + can_pair(RNA, c0, c0+47));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1951; c0 += 1)
    for (c1 = c0 + 48; c1 <= min(c0 + 95, 1999); c1 += 1) {
      if (c0 + 94 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-48+c0] + S[-c0+c1-48+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][47+c0] + S[47+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1951; c0 += 1)
    S[c0][c0+48] = MAX(S[c0][c0+48], S[c0+1][c0+48-1] + can_pair(RNA, c0, c0+48));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1950; c0 += 1)
    for (c1 = c0 + 49; c1 <= min(c0 + 97, 1999); c1 += 1) {
      if (c0 + 96 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-49+c0] + S[-c0+c1-49+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][48+c0] + S[48+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1950; c0 += 1)
    S[c0][c0+49] = MAX(S[c0][c0+49], S[c0+1][c0+49-1] + can_pair(RNA, c0, c0+49));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1949; c0 += 1)
    for (c1 = c0 + 50; c1 <= min(c0 + 99, 1999); c1 += 1) {
      if (c0 + 98 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-50+c0] + S[-c0+c1-50+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][49+c0] + S[49+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1949; c0 += 1)
    S[c0][c0+50] = MAX(S[c0][c0+50], S[c0+1][c0+50-1] + can_pair(RNA, c0, c0+50));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1948; c0 += 1)
    for (c1 = c0 + 51; c1 <= min(c0 + 101, 1999); c1 += 1) {
      if (c0 + 100 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-51+c0] + S[-c0+c1-51+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][50+c0] + S[50+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1948; c0 += 1)
    S[c0][c0+51] = MAX(S[c0][c0+51], S[c0+1][c0+51-1] + can_pair(RNA, c0, c0+51));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1947; c0 += 1)
    for (c1 = c0 + 52; c1 <= min(c0 + 103, 1999); c1 += 1) {
      if (c0 + 102 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-52+c0] + S[-c0+c1-52+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][51+c0] + S[51+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1947; c0 += 1)
    S[c0][c0+52] = MAX(S[c0][c0+52], S[c0+1][c0+52-1] + can_pair(RNA, c0, c0+52));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1946; c0 += 1)
    for (c1 = c0 + 53; c1 <= min(c0 + 105, 1999); c1 += 1) {
      if (c0 + 104 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-53+c0] + S[-c0+c1-53+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][52+c0] + S[52+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1946; c0 += 1)
    S[c0][c0+53] = MAX(S[c0][c0+53], S[c0+1][c0+53-1] + can_pair(RNA, c0, c0+53));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1945; c0 += 1)
    for (c1 = c0 + 54; c1 <= min(c0 + 107, 1999); c1 += 1) {
      if (c0 + 106 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-54+c0] + S[-c0+c1-54+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][53+c0] + S[53+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1945; c0 += 1)
    S[c0][c0+54] = MAX(S[c0][c0+54], S[c0+1][c0+54-1] + can_pair(RNA, c0, c0+54));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1944; c0 += 1)
    for (c1 = c0 + 55; c1 <= min(c0 + 109, 1999); c1 += 1) {
      if (c0 + 108 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-55+c0] + S[-c0+c1-55+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][54+c0] + S[54+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1944; c0 += 1)
    S[c0][c0+55] = MAX(S[c0][c0+55], S[c0+1][c0+55-1] + can_pair(RNA, c0, c0+55));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1943; c0 += 1)
    for (c1 = c0 + 56; c1 <= min(c0 + 111, 1999); c1 += 1) {
      if (c0 + 110 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-56+c0] + S[-c0+c1-56+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][55+c0] + S[55+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1943; c0 += 1)
    S[c0][c0+56] = MAX(S[c0][c0+56], S[c0+1][c0+56-1] + can_pair(RNA, c0, c0+56));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1942; c0 += 1)
    for (c1 = c0 + 57; c1 <= min(c0 + 113, 1999); c1 += 1) {
      if (c0 + 112 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-57+c0] + S[-c0+c1-57+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][56+c0] + S[56+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1942; c0 += 1)
    S[c0][c0+57] = MAX(S[c0][c0+57], S[c0+1][c0+57-1] + can_pair(RNA, c0, c0+57));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1941; c0 += 1)
    for (c1 = c0 + 58; c1 <= min(c0 + 115, 1999); c1 += 1) {
      if (c0 + 114 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-58+c0] + S[-c0+c1-58+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][57+c0] + S[57+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1941; c0 += 1)
    S[c0][c0+58] = MAX(S[c0][c0+58], S[c0+1][c0+58-1] + can_pair(RNA, c0, c0+58));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1940; c0 += 1)
    for (c1 = c0 + 59; c1 <= min(c0 + 117, 1999); c1 += 1) {
      if (c0 + 116 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-59+c0] + S[-c0+c1-59+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][58+c0] + S[58+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1940; c0 += 1)
    S[c0][c0+59] = MAX(S[c0][c0+59], S[c0+1][c0+59-1] + can_pair(RNA, c0, c0+59));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1939; c0 += 1)
    for (c1 = c0 + 60; c1 <= min(c0 + 119, 1999); c1 += 1) {
      if (c0 + 118 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-60+c0] + S[-c0+c1-60+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][59+c0] + S[59+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1939; c0 += 1)
    S[c0][c0+60] = MAX(S[c0][c0+60], S[c0+1][c0+60-1] + can_pair(RNA, c0, c0+60));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1938; c0 += 1)
    for (c1 = c0 + 61; c1 <= min(c0 + 121, 1999); c1 += 1) {
      if (c0 + 120 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-61+c0] + S[-c0+c1-61+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][60+c0] + S[60+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1938; c0 += 1)
    S[c0][c0+61] = MAX(S[c0][c0+61], S[c0+1][c0+61-1] + can_pair(RNA, c0, c0+61));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1937; c0 += 1)
    for (c1 = c0 + 62; c1 <= min(c0 + 123, 1999); c1 += 1) {
      if (c0 + 122 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-62+c0] + S[-c0+c1-62+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][61+c0] + S[61+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1937; c0 += 1)
    S[c0][c0+62] = MAX(S[c0][c0+62], S[c0+1][c0+62-1] + can_pair(RNA, c0, c0+62));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1936; c0 += 1)
    for (c1 = c0 + 63; c1 <= min(c0 + 125, 1999); c1 += 1) {
      if (c0 + 124 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-63+c0] + S[-c0+c1-63+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][62+c0] + S[62+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1936; c0 += 1)
    S[c0][c0+63] = MAX(S[c0][c0+63], S[c0+1][c0+63-1] + can_pair(RNA, c0, c0+63));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1935; c0 += 1)
    for (c1 = c0 + 64; c1 <= min(c0 + 127, 1999); c1 += 1) {
      if (c0 + 126 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-64+c0] + S[-c0+c1-64+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][63+c0] + S[63+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1935; c0 += 1)
    S[c0][c0+64] = MAX(S[c0][c0+64], S[c0+1][c0+64-1] + can_pair(RNA, c0, c0+64));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1934; c0 += 1)
    for (c1 = c0 + 65; c1 <= min(c0 + 129, 1999); c1 += 1) {
      if (c0 + 128 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-65+c0] + S[-c0+c1-65+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][64+c0] + S[64+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1934; c0 += 1)
    S[c0][c0+65] = MAX(S[c0][c0+65], S[c0+1][c0+65-1] + can_pair(RNA, c0, c0+65));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1933; c0 += 1)
    for (c1 = c0 + 66; c1 <= min(c0 + 131, 1999); c1 += 1) {
      if (c0 + 130 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-66+c0] + S[-c0+c1-66+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][65+c0] + S[65+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1933; c0 += 1)
    S[c0][c0+66] = MAX(S[c0][c0+66], S[c0+1][c0+66-1] + can_pair(RNA, c0, c0+66));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1932; c0 += 1)
    for (c1 = c0 + 67; c1 <= min(c0 + 133, 1999); c1 += 1) {
      if (c0 + 132 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-67+c0] + S[-c0+c1-67+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][66+c0] + S[66+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1932; c0 += 1)
    S[c0][c0+67] = MAX(S[c0][c0+67], S[c0+1][c0+67-1] + can_pair(RNA, c0, c0+67));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1931; c0 += 1)
    for (c1 = c0 + 68; c1 <= min(c0 + 135, 1999); c1 += 1) {
      if (c0 + 134 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-68+c0] + S[-c0+c1-68+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][67+c0] + S[67+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1931; c0 += 1)
    S[c0][c0+68] = MAX(S[c0][c0+68], S[c0+1][c0+68-1] + can_pair(RNA, c0, c0+68));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1930; c0 += 1)
    for (c1 = c0 + 69; c1 <= min(c0 + 137, 1999); c1 += 1) {
      if (c0 + 136 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-69+c0] + S[-c0+c1-69+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][68+c0] + S[68+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1930; c0 += 1)
    S[c0][c0+69] = MAX(S[c0][c0+69], S[c0+1][c0+69-1] + can_pair(RNA, c0, c0+69));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1929; c0 += 1)
    for (c1 = c0 + 70; c1 <= min(c0 + 139, 1999); c1 += 1) {
      if (c0 + 138 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-70+c0] + S[-c0+c1-70+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][69+c0] + S[69+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1929; c0 += 1)
    S[c0][c0+70] = MAX(S[c0][c0+70], S[c0+1][c0+70-1] + can_pair(RNA, c0, c0+70));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1928; c0 += 1)
    for (c1 = c0 + 71; c1 <= min(c0 + 141, 1999); c1 += 1) {
      if (c0 + 140 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-71+c0] + S[-c0+c1-71+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][70+c0] + S[70+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1928; c0 += 1)
    S[c0][c0+71] = MAX(S[c0][c0+71], S[c0+1][c0+71-1] + can_pair(RNA, c0, c0+71));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1927; c0 += 1)
    for (c1 = c0 + 72; c1 <= min(c0 + 143, 1999); c1 += 1) {
      if (c0 + 142 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-72+c0] + S[-c0+c1-72+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][71+c0] + S[71+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1927; c0 += 1)
    S[c0][c0+72] = MAX(S[c0][c0+72], S[c0+1][c0+72-1] + can_pair(RNA, c0, c0+72));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1926; c0 += 1)
    for (c1 = c0 + 73; c1 <= min(c0 + 145, 1999); c1 += 1) {
      if (c0 + 144 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-73+c0] + S[-c0+c1-73+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][72+c0] + S[72+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1926; c0 += 1)
    S[c0][c0+73] = MAX(S[c0][c0+73], S[c0+1][c0+73-1] + can_pair(RNA, c0, c0+73));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1925; c0 += 1)
    for (c1 = c0 + 74; c1 <= min(c0 + 147, 1999); c1 += 1) {
      if (c0 + 146 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-74+c0] + S[-c0+c1-74+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][73+c0] + S[73+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1925; c0 += 1)
    S[c0][c0+74] = MAX(S[c0][c0+74], S[c0+1][c0+74-1] + can_pair(RNA, c0, c0+74));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1924; c0 += 1)
    for (c1 = c0 + 75; c1 <= min(c0 + 149, 1999); c1 += 1) {
      if (c0 + 148 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-75+c0] + S[-c0+c1-75+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][74+c0] + S[74+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1924; c0 += 1)
    S[c0][c0+75] = MAX(S[c0][c0+75], S[c0+1][c0+75-1] + can_pair(RNA, c0, c0+75));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1923; c0 += 1)
    for (c1 = c0 + 76; c1 <= min(c0 + 151, 1999); c1 += 1) {
      if (c0 + 150 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-76+c0] + S[-c0+c1-76+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][75+c0] + S[75+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1923; c0 += 1)
    S[c0][c0+76] = MAX(S[c0][c0+76], S[c0+1][c0+76-1] + can_pair(RNA, c0, c0+76));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1922; c0 += 1)
    for (c1 = c0 + 77; c1 <= min(c0 + 153, 1999); c1 += 1) {
      if (c0 + 152 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-77+c0] + S[-c0+c1-77+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][76+c0] + S[76+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1922; c0 += 1)
    S[c0][c0+77] = MAX(S[c0][c0+77], S[c0+1][c0+77-1] + can_pair(RNA, c0, c0+77));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1921; c0 += 1)
    for (c1 = c0 + 78; c1 <= min(c0 + 155, 1999); c1 += 1) {
      if (c0 + 154 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-78+c0] + S[-c0+c1-78+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][77+c0] + S[77+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1921; c0 += 1)
    S[c0][c0+78] = MAX(S[c0][c0+78], S[c0+1][c0+78-1] + can_pair(RNA, c0, c0+78));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1920; c0 += 1)
    for (c1 = c0 + 79; c1 <= min(c0 + 157, 1999); c1 += 1) {
      if (c0 + 156 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-79+c0] + S[-c0+c1-79+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][78+c0] + S[78+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1920; c0 += 1)
    S[c0][c0+79] = MAX(S[c0][c0+79], S[c0+1][c0+79-1] + can_pair(RNA, c0, c0+79));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1919; c0 += 1)
    for (c1 = c0 + 80; c1 <= min(c0 + 159, 1999); c1 += 1) {
      if (c0 + 158 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-80+c0] + S[-c0+c1-80+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][79+c0] + S[79+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1919; c0 += 1)
    S[c0][c0+80] = MAX(S[c0][c0+80], S[c0+1][c0+80-1] + can_pair(RNA, c0, c0+80));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1918; c0 += 1)
    for (c1 = c0 + 81; c1 <= min(c0 + 161, 1999); c1 += 1) {
      if (c0 + 160 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-81+c0] + S[-c0+c1-81+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][80+c0] + S[80+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1918; c0 += 1)
    S[c0][c0+81] = MAX(S[c0][c0+81], S[c0+1][c0+81-1] + can_pair(RNA, c0, c0+81));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1917; c0 += 1)
    for (c1 = c0 + 82; c1 <= min(c0 + 163, 1999); c1 += 1) {
      if (c0 + 162 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-82+c0] + S[-c0+c1-82+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][81+c0] + S[81+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1917; c0 += 1)
    S[c0][c0+82] = MAX(S[c0][c0+82], S[c0+1][c0+82-1] + can_pair(RNA, c0, c0+82));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1916; c0 += 1)
    for (c1 = c0 + 83; c1 <= min(c0 + 165, 1999); c1 += 1) {
      if (c0 + 164 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-83+c0] + S[-c0+c1-83+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][82+c0] + S[82+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1916; c0 += 1)
    S[c0][c0+83] = MAX(S[c0][c0+83], S[c0+1][c0+83-1] + can_pair(RNA, c0, c0+83));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1915; c0 += 1)
    for (c1 = c0 + 84; c1 <= min(c0 + 167, 1999); c1 += 1) {
      if (c0 + 166 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-84+c0] + S[-c0+c1-84+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][83+c0] + S[83+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1915; c0 += 1)
    S[c0][c0+84] = MAX(S[c0][c0+84], S[c0+1][c0+84-1] + can_pair(RNA, c0, c0+84));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1914; c0 += 1)
    for (c1 = c0 + 85; c1 <= min(c0 + 169, 1999); c1 += 1) {
      if (c0 + 168 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-85+c0] + S[-c0+c1-85+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][84+c0] + S[84+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1914; c0 += 1)
    S[c0][c0+85] = MAX(S[c0][c0+85], S[c0+1][c0+85-1] + can_pair(RNA, c0, c0+85));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1913; c0 += 1)
    for (c1 = c0 + 86; c1 <= min(c0 + 171, 1999); c1 += 1) {
      if (c0 + 170 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-86+c0] + S[-c0+c1-86+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][85+c0] + S[85+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1913; c0 += 1)
    S[c0][c0+86] = MAX(S[c0][c0+86], S[c0+1][c0+86-1] + can_pair(RNA, c0, c0+86));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1912; c0 += 1)
    for (c1 = c0 + 87; c1 <= min(c0 + 173, 1999); c1 += 1) {
      if (c0 + 172 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-87+c0] + S[-c0+c1-87+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][86+c0] + S[86+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1912; c0 += 1)
    S[c0][c0+87] = MAX(S[c0][c0+87], S[c0+1][c0+87-1] + can_pair(RNA, c0, c0+87));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1911; c0 += 1)
    for (c1 = c0 + 88; c1 <= min(c0 + 175, 1999); c1 += 1) {
      if (c0 + 174 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-88+c0] + S[-c0+c1-88+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][87+c0] + S[87+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1911; c0 += 1)
    S[c0][c0+88] = MAX(S[c0][c0+88], S[c0+1][c0+88-1] + can_pair(RNA, c0, c0+88));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1910; c0 += 1)
    for (c1 = c0 + 89; c1 <= min(c0 + 177, 1999); c1 += 1) {
      if (c0 + 176 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-89+c0] + S[-c0+c1-89+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][88+c0] + S[88+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1910; c0 += 1)
    S[c0][c0+89] = MAX(S[c0][c0+89], S[c0+1][c0+89-1] + can_pair(RNA, c0, c0+89));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1909; c0 += 1)
    for (c1 = c0 + 90; c1 <= min(c0 + 179, 1999); c1 += 1) {
      if (c0 + 178 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-90+c0] + S[-c0+c1-90+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][89+c0] + S[89+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1909; c0 += 1)
    S[c0][c0+90] = MAX(S[c0][c0+90], S[c0+1][c0+90-1] + can_pair(RNA, c0, c0+90));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1908; c0 += 1)
    for (c1 = c0 + 91; c1 <= min(c0 + 181, 1999); c1 += 1) {
      if (c0 + 180 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-91+c0] + S[-c0+c1-91+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][90+c0] + S[90+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1908; c0 += 1)
    S[c0][c0+91] = MAX(S[c0][c0+91], S[c0+1][c0+91-1] + can_pair(RNA, c0, c0+91));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1907; c0 += 1)
    for (c1 = c0 + 92; c1 <= min(c0 + 183, 1999); c1 += 1) {
      if (c0 + 182 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-92+c0] + S[-c0+c1-92+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][91+c0] + S[91+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1907; c0 += 1)
    S[c0][c0+92] = MAX(S[c0][c0+92], S[c0+1][c0+92-1] + can_pair(RNA, c0, c0+92));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1906; c0 += 1)
    for (c1 = c0 + 93; c1 <= min(c0 + 185, 1999); c1 += 1) {
      if (c0 + 184 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-93+c0] + S[-c0+c1-93+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][92+c0] + S[92+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1906; c0 += 1)
    S[c0][c0+93] = MAX(S[c0][c0+93], S[c0+1][c0+93-1] + can_pair(RNA, c0, c0+93));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1905; c0 += 1)
    for (c1 = c0 + 94; c1 <= min(c0 + 187, 1999); c1 += 1) {
      if (c0 + 186 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-94+c0] + S[-c0+c1-94+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][93+c0] + S[93+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1905; c0 += 1)
    S[c0][c0+94] = MAX(S[c0][c0+94], S[c0+1][c0+94-1] + can_pair(RNA, c0, c0+94));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1904; c0 += 1)
    for (c1 = c0 + 95; c1 <= min(c0 + 189, 1999); c1 += 1) {
      if (c0 + 188 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-95+c0] + S[-c0+c1-95+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][94+c0] + S[94+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1904; c0 += 1)
    S[c0][c0+95] = MAX(S[c0][c0+95], S[c0+1][c0+95-1] + can_pair(RNA, c0, c0+95));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1903; c0 += 1)
    for (c1 = c0 + 96; c1 <= min(c0 + 191, 1999); c1 += 1) {
      if (c0 + 190 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-96+c0] + S[-c0+c1-96+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][95+c0] + S[95+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1903; c0 += 1)
    S[c0][c0+96] = MAX(S[c0][c0+96], S[c0+1][c0+96-1] + can_pair(RNA, c0, c0+96));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1902; c0 += 1)
    for (c1 = c0 + 97; c1 <= min(c0 + 193, 1999); c1 += 1) {
      if (c0 + 192 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-97+c0] + S[-c0+c1-97+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][96+c0] + S[96+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1902; c0 += 1)
    S[c0][c0+97] = MAX(S[c0][c0+97], S[c0+1][c0+97-1] + can_pair(RNA, c0, c0+97));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1901; c0 += 1)
    for (c1 = c0 + 98; c1 <= min(c0 + 195, 1999); c1 += 1) {
      if (c0 + 194 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-98+c0] + S[-c0+c1-98+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][97+c0] + S[97+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1901; c0 += 1)
    S[c0][c0+98] = MAX(S[c0][c0+98], S[c0+1][c0+98-1] + can_pair(RNA, c0, c0+98));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1900; c0 += 1)
    for (c1 = c0 + 99; c1 <= min(c0 + 197, 1999); c1 += 1) {
      if (c0 + 196 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-99+c0] + S[-c0+c1-99+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][98+c0] + S[98+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1900; c0 += 1)
    S[c0][c0+99] = MAX(S[c0][c0+99], S[c0+1][c0+99-1] + can_pair(RNA, c0, c0+99));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1899; c0 += 1)
    for (c1 = c0 + 100; c1 <= min(c0 + 199, 1999); c1 += 1) {
      if (c0 + 198 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-100+c0] + S[-c0+c1-100+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][99+c0] + S[99+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1899; c0 += 1)
    S[c0][c0+100] = MAX(S[c0][c0+100], S[c0+1][c0+100-1] + can_pair(RNA, c0, c0+100));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1898; c0 += 1)
    for (c1 = c0 + 101; c1 <= min(c0 + 201, 1999); c1 += 1) {
      if (c0 + 200 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-101+c0] + S[-c0+c1-101+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][100+c0] + S[100+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1898; c0 += 1)
    S[c0][c0+101] = MAX(S[c0][c0+101], S[c0+1][c0+101-1] + can_pair(RNA, c0, c0+101));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1897; c0 += 1)
    for (c1 = c0 + 102; c1 <= min(c0 + 203, 1999); c1 += 1) {
      if (c0 + 202 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-102+c0] + S[-c0+c1-102+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][101+c0] + S[101+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1897; c0 += 1)
    S[c0][c0+102] = MAX(S[c0][c0+102], S[c0+1][c0+102-1] + can_pair(RNA, c0, c0+102));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1896; c0 += 1)
    for (c1 = c0 + 103; c1 <= min(c0 + 205, 1999); c1 += 1) {
      if (c0 + 204 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-103+c0] + S[-c0+c1-103+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][102+c0] + S[102+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1896; c0 += 1)
    S[c0][c0+103] = MAX(S[c0][c0+103], S[c0+1][c0+103-1] + can_pair(RNA, c0, c0+103));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1895; c0 += 1)
    for (c1 = c0 + 104; c1 <= min(c0 + 207, 1999); c1 += 1) {
      if (c0 + 206 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-104+c0] + S[-c0+c1-104+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][103+c0] + S[103+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1895; c0 += 1)
    S[c0][c0+104] = MAX(S[c0][c0+104], S[c0+1][c0+104-1] + can_pair(RNA, c0, c0+104));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1894; c0 += 1)
    for (c1 = c0 + 105; c1 <= min(c0 + 209, 1999); c1 += 1) {
      if (c0 + 208 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-105+c0] + S[-c0+c1-105+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][104+c0] + S[104+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1894; c0 += 1)
    S[c0][c0+105] = MAX(S[c0][c0+105], S[c0+1][c0+105-1] + can_pair(RNA, c0, c0+105));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1893; c0 += 1)
    for (c1 = c0 + 106; c1 <= min(c0 + 211, 1999); c1 += 1) {
      if (c0 + 210 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-106+c0] + S[-c0+c1-106+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][105+c0] + S[105+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1893; c0 += 1)
    S[c0][c0+106] = MAX(S[c0][c0+106], S[c0+1][c0+106-1] + can_pair(RNA, c0, c0+106));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1892; c0 += 1)
    for (c1 = c0 + 107; c1 <= min(c0 + 213, 1999); c1 += 1) {
      if (c0 + 212 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-107+c0] + S[-c0+c1-107+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][106+c0] + S[106+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1892; c0 += 1)
    S[c0][c0+107] = MAX(S[c0][c0+107], S[c0+1][c0+107-1] + can_pair(RNA, c0, c0+107));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1891; c0 += 1)
    for (c1 = c0 + 108; c1 <= min(c0 + 215, 1999); c1 += 1) {
      if (c0 + 214 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-108+c0] + S[-c0+c1-108+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][107+c0] + S[107+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1891; c0 += 1)
    S[c0][c0+108] = MAX(S[c0][c0+108], S[c0+1][c0+108-1] + can_pair(RNA, c0, c0+108));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1890; c0 += 1)
    for (c1 = c0 + 109; c1 <= min(c0 + 217, 1999); c1 += 1) {
      if (c0 + 216 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-109+c0] + S[-c0+c1-109+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][108+c0] + S[108+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1890; c0 += 1)
    S[c0][c0+109] = MAX(S[c0][c0+109], S[c0+1][c0+109-1] + can_pair(RNA, c0, c0+109));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1889; c0 += 1)
    for (c1 = c0 + 110; c1 <= min(c0 + 219, 1999); c1 += 1) {
      if (c0 + 218 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-110+c0] + S[-c0+c1-110+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][109+c0] + S[109+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1889; c0 += 1)
    S[c0][c0+110] = MAX(S[c0][c0+110], S[c0+1][c0+110-1] + can_pair(RNA, c0, c0+110));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1888; c0 += 1)
    for (c1 = c0 + 111; c1 <= min(c0 + 221, 1999); c1 += 1) {
      if (c0 + 220 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-111+c0] + S[-c0+c1-111+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][110+c0] + S[110+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1888; c0 += 1)
    S[c0][c0+111] = MAX(S[c0][c0+111], S[c0+1][c0+111-1] + can_pair(RNA, c0, c0+111));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1887; c0 += 1)
    for (c1 = c0 + 112; c1 <= min(c0 + 223, 1999); c1 += 1) {
      if (c0 + 222 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-112+c0] + S[-c0+c1-112+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][111+c0] + S[111+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1887; c0 += 1)
    S[c0][c0+112] = MAX(S[c0][c0+112], S[c0+1][c0+112-1] + can_pair(RNA, c0, c0+112));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1886; c0 += 1)
    for (c1 = c0 + 113; c1 <= min(c0 + 225, 1999); c1 += 1) {
      if (c0 + 224 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-113+c0] + S[-c0+c1-113+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][112+c0] + S[112+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1886; c0 += 1)
    S[c0][c0+113] = MAX(S[c0][c0+113], S[c0+1][c0+113-1] + can_pair(RNA, c0, c0+113));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1885; c0 += 1)
    for (c1 = c0 + 114; c1 <= min(c0 + 227, 1999); c1 += 1) {
      if (c0 + 226 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-114+c0] + S[-c0+c1-114+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][113+c0] + S[113+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1885; c0 += 1)
    S[c0][c0+114] = MAX(S[c0][c0+114], S[c0+1][c0+114-1] + can_pair(RNA, c0, c0+114));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1884; c0 += 1)
    for (c1 = c0 + 115; c1 <= min(c0 + 229, 1999); c1 += 1) {
      if (c0 + 228 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-115+c0] + S[-c0+c1-115+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][114+c0] + S[114+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1884; c0 += 1)
    S[c0][c0+115] = MAX(S[c0][c0+115], S[c0+1][c0+115-1] + can_pair(RNA, c0, c0+115));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1883; c0 += 1)
    for (c1 = c0 + 116; c1 <= min(c0 + 231, 1999); c1 += 1) {
      if (c0 + 230 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-116+c0] + S[-c0+c1-116+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][115+c0] + S[115+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1883; c0 += 1)
    S[c0][c0+116] = MAX(S[c0][c0+116], S[c0+1][c0+116-1] + can_pair(RNA, c0, c0+116));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1882; c0 += 1)
    for (c1 = c0 + 117; c1 <= min(c0 + 233, 1999); c1 += 1) {
      if (c0 + 232 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-117+c0] + S[-c0+c1-117+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][116+c0] + S[116+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1882; c0 += 1)
    S[c0][c0+117] = MAX(S[c0][c0+117], S[c0+1][c0+117-1] + can_pair(RNA, c0, c0+117));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1881; c0 += 1)
    for (c1 = c0 + 118; c1 <= min(c0 + 235, 1999); c1 += 1) {
      if (c0 + 234 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-118+c0] + S[-c0+c1-118+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][117+c0] + S[117+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1881; c0 += 1)
    S[c0][c0+118] = MAX(S[c0][c0+118], S[c0+1][c0+118-1] + can_pair(RNA, c0, c0+118));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1880; c0 += 1)
    for (c1 = c0 + 119; c1 <= min(c0 + 237, 1999); c1 += 1) {
      if (c0 + 236 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-119+c0] + S[-c0+c1-119+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][118+c0] + S[118+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1880; c0 += 1)
    S[c0][c0+119] = MAX(S[c0][c0+119], S[c0+1][c0+119-1] + can_pair(RNA, c0, c0+119));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1879; c0 += 1)
    for (c1 = c0 + 120; c1 <= min(c0 + 239, 1999); c1 += 1) {
      if (c0 + 238 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-120+c0] + S[-c0+c1-120+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][119+c0] + S[119+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1879; c0 += 1)
    S[c0][c0+120] = MAX(S[c0][c0+120], S[c0+1][c0+120-1] + can_pair(RNA, c0, c0+120));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1878; c0 += 1)
    for (c1 = c0 + 121; c1 <= min(c0 + 241, 1999); c1 += 1) {
      if (c0 + 240 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-121+c0] + S[-c0+c1-121+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][120+c0] + S[120+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1878; c0 += 1)
    S[c0][c0+121] = MAX(S[c0][c0+121], S[c0+1][c0+121-1] + can_pair(RNA, c0, c0+121));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1877; c0 += 1)
    for (c1 = c0 + 122; c1 <= min(c0 + 243, 1999); c1 += 1) {
      if (c0 + 242 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-122+c0] + S[-c0+c1-122+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][121+c0] + S[121+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1877; c0 += 1)
    S[c0][c0+122] = MAX(S[c0][c0+122], S[c0+1][c0+122-1] + can_pair(RNA, c0, c0+122));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1876; c0 += 1)
    for (c1 = c0 + 123; c1 <= min(c0 + 245, 1999); c1 += 1) {
      if (c0 + 244 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-123+c0] + S[-c0+c1-123+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][122+c0] + S[122+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1876; c0 += 1)
    S[c0][c0+123] = MAX(S[c0][c0+123], S[c0+1][c0+123-1] + can_pair(RNA, c0, c0+123));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1875; c0 += 1)
    for (c1 = c0 + 124; c1 <= min(c0 + 247, 1999); c1 += 1) {
      if (c0 + 246 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-124+c0] + S[-c0+c1-124+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][123+c0] + S[123+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1875; c0 += 1)
    S[c0][c0+124] = MAX(S[c0][c0+124], S[c0+1][c0+124-1] + can_pair(RNA, c0, c0+124));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1874; c0 += 1)
    for (c1 = c0 + 125; c1 <= min(c0 + 249, 1999); c1 += 1) {
      if (c0 + 248 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-125+c0] + S[-c0+c1-125+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][124+c0] + S[124+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1874; c0 += 1)
    S[c0][c0+125] = MAX(S[c0][c0+125], S[c0+1][c0+125-1] + can_pair(RNA, c0, c0+125));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1873; c0 += 1)
    for (c1 = c0 + 126; c1 <= min(c0 + 251, 1999); c1 += 1) {
      if (c0 + 250 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-126+c0] + S[-c0+c1-126+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][125+c0] + S[125+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1873; c0 += 1)
    S[c0][c0+126] = MAX(S[c0][c0+126], S[c0+1][c0+126-1] + can_pair(RNA, c0, c0+126));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1872; c0 += 1)
    for (c1 = c0 + 127; c1 <= min(c0 + 253, 1999); c1 += 1) {
      if (c0 + 252 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-127+c0] + S[-c0+c1-127+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][126+c0] + S[126+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1872; c0 += 1)
    S[c0][c0+127] = MAX(S[c0][c0+127], S[c0+1][c0+127-1] + can_pair(RNA, c0, c0+127));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1871; c0 += 1)
    for (c1 = c0 + 128; c1 <= min(c0 + 255, 1999); c1 += 1) {
      if (c0 + 254 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-128+c0] + S[-c0+c1-128+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][127+c0] + S[127+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1871; c0 += 1)
    S[c0][c0+128] = MAX(S[c0][c0+128], S[c0+1][c0+128-1] + can_pair(RNA, c0, c0+128));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1870; c0 += 1)
    for (c1 = c0 + 129; c1 <= min(c0 + 257, 1999); c1 += 1) {
      if (c0 + 256 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-129+c0] + S[-c0+c1-129+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][128+c0] + S[128+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1870; c0 += 1)
    S[c0][c0+129] = MAX(S[c0][c0+129], S[c0+1][c0+129-1] + can_pair(RNA, c0, c0+129));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1869; c0 += 1)
    for (c1 = c0 + 130; c1 <= min(c0 + 259, 1999); c1 += 1) {
      if (c0 + 258 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-130+c0] + S[-c0+c1-130+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][129+c0] + S[129+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1869; c0 += 1)
    S[c0][c0+130] = MAX(S[c0][c0+130], S[c0+1][c0+130-1] + can_pair(RNA, c0, c0+130));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1868; c0 += 1)
    for (c1 = c0 + 131; c1 <= min(c0 + 261, 1999); c1 += 1) {
      if (c0 + 260 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-131+c0] + S[-c0+c1-131+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][130+c0] + S[130+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1868; c0 += 1)
    S[c0][c0+131] = MAX(S[c0][c0+131], S[c0+1][c0+131-1] + can_pair(RNA, c0, c0+131));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1867; c0 += 1)
    for (c1 = c0 + 132; c1 <= min(c0 + 263, 1999); c1 += 1) {
      if (c0 + 262 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-132+c0] + S[-c0+c1-132+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][131+c0] + S[131+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1867; c0 += 1)
    S[c0][c0+132] = MAX(S[c0][c0+132], S[c0+1][c0+132-1] + can_pair(RNA, c0, c0+132));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1866; c0 += 1)
    for (c1 = c0 + 133; c1 <= min(c0 + 265, 1999); c1 += 1) {
      if (c0 + 264 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-133+c0] + S[-c0+c1-133+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][132+c0] + S[132+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1866; c0 += 1)
    S[c0][c0+133] = MAX(S[c0][c0+133], S[c0+1][c0+133-1] + can_pair(RNA, c0, c0+133));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1865; c0 += 1)
    for (c1 = c0 + 134; c1 <= min(c0 + 267, 1999); c1 += 1) {
      if (c0 + 266 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-134+c0] + S[-c0+c1-134+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][133+c0] + S[133+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1865; c0 += 1)
    S[c0][c0+134] = MAX(S[c0][c0+134], S[c0+1][c0+134-1] + can_pair(RNA, c0, c0+134));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1864; c0 += 1)
    for (c1 = c0 + 135; c1 <= min(c0 + 269, 1999); c1 += 1) {
      if (c0 + 268 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-135+c0] + S[-c0+c1-135+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][134+c0] + S[134+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1864; c0 += 1)
    S[c0][c0+135] = MAX(S[c0][c0+135], S[c0+1][c0+135-1] + can_pair(RNA, c0, c0+135));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1863; c0 += 1)
    for (c1 = c0 + 136; c1 <= min(c0 + 271, 1999); c1 += 1) {
      if (c0 + 270 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-136+c0] + S[-c0+c1-136+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][135+c0] + S[135+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1863; c0 += 1)
    S[c0][c0+136] = MAX(S[c0][c0+136], S[c0+1][c0+136-1] + can_pair(RNA, c0, c0+136));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1862; c0 += 1)
    for (c1 = c0 + 137; c1 <= min(c0 + 273, 1999); c1 += 1) {
      if (c0 + 272 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-137+c0] + S[-c0+c1-137+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][136+c0] + S[136+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1862; c0 += 1)
    S[c0][c0+137] = MAX(S[c0][c0+137], S[c0+1][c0+137-1] + can_pair(RNA, c0, c0+137));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1861; c0 += 1)
    for (c1 = c0 + 138; c1 <= min(c0 + 275, 1999); c1 += 1) {
      if (c0 + 274 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-138+c0] + S[-c0+c1-138+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][137+c0] + S[137+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1861; c0 += 1)
    S[c0][c0+138] = MAX(S[c0][c0+138], S[c0+1][c0+138-1] + can_pair(RNA, c0, c0+138));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1860; c0 += 1)
    for (c1 = c0 + 139; c1 <= min(c0 + 277, 1999); c1 += 1) {
      if (c0 + 276 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-139+c0] + S[-c0+c1-139+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][138+c0] + S[138+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1860; c0 += 1)
    S[c0][c0+139] = MAX(S[c0][c0+139], S[c0+1][c0+139-1] + can_pair(RNA, c0, c0+139));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1859; c0 += 1)
    for (c1 = c0 + 140; c1 <= min(c0 + 279, 1999); c1 += 1) {
      if (c0 + 278 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-140+c0] + S[-c0+c1-140+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][139+c0] + S[139+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1859; c0 += 1)
    S[c0][c0+140] = MAX(S[c0][c0+140], S[c0+1][c0+140-1] + can_pair(RNA, c0, c0+140));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1858; c0 += 1)
    for (c1 = c0 + 141; c1 <= min(c0 + 281, 1999); c1 += 1) {
      if (c0 + 280 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-141+c0] + S[-c0+c1-141+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][140+c0] + S[140+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1858; c0 += 1)
    S[c0][c0+141] = MAX(S[c0][c0+141], S[c0+1][c0+141-1] + can_pair(RNA, c0, c0+141));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1857; c0 += 1)
    for (c1 = c0 + 142; c1 <= min(c0 + 283, 1999); c1 += 1) {
      if (c0 + 282 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-142+c0] + S[-c0+c1-142+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][141+c0] + S[141+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1857; c0 += 1)
    S[c0][c0+142] = MAX(S[c0][c0+142], S[c0+1][c0+142-1] + can_pair(RNA, c0, c0+142));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1856; c0 += 1)
    for (c1 = c0 + 143; c1 <= min(c0 + 285, 1999); c1 += 1) {
      if (c0 + 284 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-143+c0] + S[-c0+c1-143+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][142+c0] + S[142+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1856; c0 += 1)
    S[c0][c0+143] = MAX(S[c0][c0+143], S[c0+1][c0+143-1] + can_pair(RNA, c0, c0+143));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1855; c0 += 1)
    for (c1 = c0 + 144; c1 <= min(c0 + 287, 1999); c1 += 1) {
      if (c0 + 286 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-144+c0] + S[-c0+c1-144+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][143+c0] + S[143+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1855; c0 += 1)
    S[c0][c0+144] = MAX(S[c0][c0+144], S[c0+1][c0+144-1] + can_pair(RNA, c0, c0+144));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1854; c0 += 1)
    for (c1 = c0 + 145; c1 <= min(c0 + 289, 1999); c1 += 1) {
      if (c0 + 288 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-145+c0] + S[-c0+c1-145+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][144+c0] + S[144+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1854; c0 += 1)
    S[c0][c0+145] = MAX(S[c0][c0+145], S[c0+1][c0+145-1] + can_pair(RNA, c0, c0+145));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1853; c0 += 1)
    for (c1 = c0 + 146; c1 <= min(c0 + 291, 1999); c1 += 1) {
      if (c0 + 290 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-146+c0] + S[-c0+c1-146+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][145+c0] + S[145+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1853; c0 += 1)
    S[c0][c0+146] = MAX(S[c0][c0+146], S[c0+1][c0+146-1] + can_pair(RNA, c0, c0+146));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1852; c0 += 1)
    for (c1 = c0 + 147; c1 <= min(c0 + 293, 1999); c1 += 1) {
      if (c0 + 292 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-147+c0] + S[-c0+c1-147+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][146+c0] + S[146+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1852; c0 += 1)
    S[c0][c0+147] = MAX(S[c0][c0+147], S[c0+1][c0+147-1] + can_pair(RNA, c0, c0+147));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1851; c0 += 1)
    for (c1 = c0 + 148; c1 <= min(c0 + 295, 1999); c1 += 1) {
      if (c0 + 294 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-148+c0] + S[-c0+c1-148+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][147+c0] + S[147+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1851; c0 += 1)
    S[c0][c0+148] = MAX(S[c0][c0+148], S[c0+1][c0+148-1] + can_pair(RNA, c0, c0+148));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1850; c0 += 1)
    for (c1 = c0 + 149; c1 <= min(c0 + 297, 1999); c1 += 1) {
      if (c0 + 296 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-149+c0] + S[-c0+c1-149+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][148+c0] + S[148+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1850; c0 += 1)
    S[c0][c0+149] = MAX(S[c0][c0+149], S[c0+1][c0+149-1] + can_pair(RNA, c0, c0+149));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1849; c0 += 1)
    for (c1 = c0 + 150; c1 <= min(c0 + 299, 1999); c1 += 1) {
      if (c0 + 298 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-150+c0] + S[-c0+c1-150+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][149+c0] + S[149+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1849; c0 += 1)
    S[c0][c0+150] = MAX(S[c0][c0+150], S[c0+1][c0+150-1] + can_pair(RNA, c0, c0+150));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1848; c0 += 1)
    for (c1 = c0 + 151; c1 <= min(c0 + 301, 1999); c1 += 1) {
      if (c0 + 300 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-151+c0] + S[-c0+c1-151+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][150+c0] + S[150+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1848; c0 += 1)
    S[c0][c0+151] = MAX(S[c0][c0+151], S[c0+1][c0+151-1] + can_pair(RNA, c0, c0+151));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1847; c0 += 1)
    for (c1 = c0 + 152; c1 <= min(c0 + 303, 1999); c1 += 1) {
      if (c0 + 302 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-152+c0] + S[-c0+c1-152+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][151+c0] + S[151+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1847; c0 += 1)
    S[c0][c0+152] = MAX(S[c0][c0+152], S[c0+1][c0+152-1] + can_pair(RNA, c0, c0+152));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1846; c0 += 1)
    for (c1 = c0 + 153; c1 <= min(c0 + 305, 1999); c1 += 1) {
      if (c0 + 304 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-153+c0] + S[-c0+c1-153+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][152+c0] + S[152+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1846; c0 += 1)
    S[c0][c0+153] = MAX(S[c0][c0+153], S[c0+1][c0+153-1] + can_pair(RNA, c0, c0+153));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1845; c0 += 1)
    for (c1 = c0 + 154; c1 <= min(c0 + 307, 1999); c1 += 1) {
      if (c0 + 306 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-154+c0] + S[-c0+c1-154+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][153+c0] + S[153+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1845; c0 += 1)
    S[c0][c0+154] = MAX(S[c0][c0+154], S[c0+1][c0+154-1] + can_pair(RNA, c0, c0+154));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1844; c0 += 1)
    for (c1 = c0 + 155; c1 <= min(c0 + 309, 1999); c1 += 1) {
      if (c0 + 308 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-155+c0] + S[-c0+c1-155+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][154+c0] + S[154+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1844; c0 += 1)
    S[c0][c0+155] = MAX(S[c0][c0+155], S[c0+1][c0+155-1] + can_pair(RNA, c0, c0+155));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1843; c0 += 1)
    for (c1 = c0 + 156; c1 <= min(c0 + 311, 1999); c1 += 1) {
      if (c0 + 310 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-156+c0] + S[-c0+c1-156+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][155+c0] + S[155+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1843; c0 += 1)
    S[c0][c0+156] = MAX(S[c0][c0+156], S[c0+1][c0+156-1] + can_pair(RNA, c0, c0+156));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1842; c0 += 1)
    for (c1 = c0 + 157; c1 <= min(c0 + 313, 1999); c1 += 1) {
      if (c0 + 312 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-157+c0] + S[-c0+c1-157+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][156+c0] + S[156+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1842; c0 += 1)
    S[c0][c0+157] = MAX(S[c0][c0+157], S[c0+1][c0+157-1] + can_pair(RNA, c0, c0+157));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1841; c0 += 1)
    for (c1 = c0 + 158; c1 <= min(c0 + 315, 1999); c1 += 1) {
      if (c0 + 314 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-158+c0] + S[-c0+c1-158+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][157+c0] + S[157+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1841; c0 += 1)
    S[c0][c0+158] = MAX(S[c0][c0+158], S[c0+1][c0+158-1] + can_pair(RNA, c0, c0+158));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1840; c0 += 1)
    for (c1 = c0 + 159; c1 <= min(c0 + 317, 1999); c1 += 1) {
      if (c0 + 316 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-159+c0] + S[-c0+c1-159+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][158+c0] + S[158+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1840; c0 += 1)
    S[c0][c0+159] = MAX(S[c0][c0+159], S[c0+1][c0+159-1] + can_pair(RNA, c0, c0+159));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1839; c0 += 1)
    for (c1 = c0 + 160; c1 <= min(c0 + 319, 1999); c1 += 1) {
      if (c0 + 318 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-160+c0] + S[-c0+c1-160+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][159+c0] + S[159+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1839; c0 += 1)
    S[c0][c0+160] = MAX(S[c0][c0+160], S[c0+1][c0+160-1] + can_pair(RNA, c0, c0+160));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1838; c0 += 1)
    for (c1 = c0 + 161; c1 <= min(c0 + 321, 1999); c1 += 1) {
      if (c0 + 320 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-161+c0] + S[-c0+c1-161+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][160+c0] + S[160+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1838; c0 += 1)
    S[c0][c0+161] = MAX(S[c0][c0+161], S[c0+1][c0+161-1] + can_pair(RNA, c0, c0+161));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1837; c0 += 1)
    for (c1 = c0 + 162; c1 <= min(c0 + 323, 1999); c1 += 1) {
      if (c0 + 322 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-162+c0] + S[-c0+c1-162+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][161+c0] + S[161+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1837; c0 += 1)
    S[c0][c0+162] = MAX(S[c0][c0+162], S[c0+1][c0+162-1] + can_pair(RNA, c0, c0+162));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1836; c0 += 1)
    for (c1 = c0 + 163; c1 <= min(c0 + 325, 1999); c1 += 1) {
      if (c0 + 324 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-163+c0] + S[-c0+c1-163+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][162+c0] + S[162+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1836; c0 += 1)
    S[c0][c0+163] = MAX(S[c0][c0+163], S[c0+1][c0+163-1] + can_pair(RNA, c0, c0+163));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1835; c0 += 1)
    for (c1 = c0 + 164; c1 <= min(c0 + 327, 1999); c1 += 1) {
      if (c0 + 326 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-164+c0] + S[-c0+c1-164+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][163+c0] + S[163+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1835; c0 += 1)
    S[c0][c0+164] = MAX(S[c0][c0+164], S[c0+1][c0+164-1] + can_pair(RNA, c0, c0+164));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1834; c0 += 1)
    for (c1 = c0 + 165; c1 <= min(c0 + 329, 1999); c1 += 1) {
      if (c0 + 328 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-165+c0] + S[-c0+c1-165+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][164+c0] + S[164+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1834; c0 += 1)
    S[c0][c0+165] = MAX(S[c0][c0+165], S[c0+1][c0+165-1] + can_pair(RNA, c0, c0+165));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1833; c0 += 1)
    for (c1 = c0 + 166; c1 <= min(c0 + 331, 1999); c1 += 1) {
      if (c0 + 330 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-166+c0] + S[-c0+c1-166+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][165+c0] + S[165+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1833; c0 += 1)
    S[c0][c0+166] = MAX(S[c0][c0+166], S[c0+1][c0+166-1] + can_pair(RNA, c0, c0+166));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1832; c0 += 1)
    for (c1 = c0 + 167; c1 <= min(c0 + 333, 1999); c1 += 1) {
      if (c0 + 332 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-167+c0] + S[-c0+c1-167+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][166+c0] + S[166+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1832; c0 += 1)
    S[c0][c0+167] = MAX(S[c0][c0+167], S[c0+1][c0+167-1] + can_pair(RNA, c0, c0+167));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1831; c0 += 1)
    for (c1 = c0 + 168; c1 <= min(c0 + 335, 1999); c1 += 1) {
      if (c0 + 334 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-168+c0] + S[-c0+c1-168+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][167+c0] + S[167+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1831; c0 += 1)
    S[c0][c0+168] = MAX(S[c0][c0+168], S[c0+1][c0+168-1] + can_pair(RNA, c0, c0+168));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1830; c0 += 1)
    for (c1 = c0 + 169; c1 <= min(c0 + 337, 1999); c1 += 1) {
      if (c0 + 336 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-169+c0] + S[-c0+c1-169+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][168+c0] + S[168+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1830; c0 += 1)
    S[c0][c0+169] = MAX(S[c0][c0+169], S[c0+1][c0+169-1] + can_pair(RNA, c0, c0+169));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1829; c0 += 1)
    for (c1 = c0 + 170; c1 <= min(c0 + 339, 1999); c1 += 1) {
      if (c0 + 338 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-170+c0] + S[-c0+c1-170+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][169+c0] + S[169+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1829; c0 += 1)
    S[c0][c0+170] = MAX(S[c0][c0+170], S[c0+1][c0+170-1] + can_pair(RNA, c0, c0+170));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1828; c0 += 1)
    for (c1 = c0 + 171; c1 <= min(c0 + 341, 1999); c1 += 1) {
      if (c0 + 340 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-171+c0] + S[-c0+c1-171+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][170+c0] + S[170+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1828; c0 += 1)
    S[c0][c0+171] = MAX(S[c0][c0+171], S[c0+1][c0+171-1] + can_pair(RNA, c0, c0+171));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1827; c0 += 1)
    for (c1 = c0 + 172; c1 <= min(c0 + 343, 1999); c1 += 1) {
      if (c0 + 342 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-172+c0] + S[-c0+c1-172+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][171+c0] + S[171+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1827; c0 += 1)
    S[c0][c0+172] = MAX(S[c0][c0+172], S[c0+1][c0+172-1] + can_pair(RNA, c0, c0+172));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1826; c0 += 1)
    for (c1 = c0 + 173; c1 <= min(c0 + 345, 1999); c1 += 1) {
      if (c0 + 344 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-173+c0] + S[-c0+c1-173+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][172+c0] + S[172+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1826; c0 += 1)
    S[c0][c0+173] = MAX(S[c0][c0+173], S[c0+1][c0+173-1] + can_pair(RNA, c0, c0+173));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1825; c0 += 1)
    for (c1 = c0 + 174; c1 <= min(c0 + 347, 1999); c1 += 1) {
      if (c0 + 346 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-174+c0] + S[-c0+c1-174+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][173+c0] + S[173+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1825; c0 += 1)
    S[c0][c0+174] = MAX(S[c0][c0+174], S[c0+1][c0+174-1] + can_pair(RNA, c0, c0+174));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1824; c0 += 1)
    for (c1 = c0 + 175; c1 <= min(c0 + 349, 1999); c1 += 1) {
      if (c0 + 348 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-175+c0] + S[-c0+c1-175+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][174+c0] + S[174+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1824; c0 += 1)
    S[c0][c0+175] = MAX(S[c0][c0+175], S[c0+1][c0+175-1] + can_pair(RNA, c0, c0+175));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1823; c0 += 1)
    for (c1 = c0 + 176; c1 <= min(c0 + 351, 1999); c1 += 1) {
      if (c0 + 350 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-176+c0] + S[-c0+c1-176+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][175+c0] + S[175+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1823; c0 += 1)
    S[c0][c0+176] = MAX(S[c0][c0+176], S[c0+1][c0+176-1] + can_pair(RNA, c0, c0+176));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1822; c0 += 1)
    for (c1 = c0 + 177; c1 <= min(c0 + 353, 1999); c1 += 1) {
      if (c0 + 352 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-177+c0] + S[-c0+c1-177+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][176+c0] + S[176+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1822; c0 += 1)
    S[c0][c0+177] = MAX(S[c0][c0+177], S[c0+1][c0+177-1] + can_pair(RNA, c0, c0+177));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1821; c0 += 1)
    for (c1 = c0 + 178; c1 <= min(c0 + 355, 1999); c1 += 1) {
      if (c0 + 354 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-178+c0] + S[-c0+c1-178+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][177+c0] + S[177+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1821; c0 += 1)
    S[c0][c0+178] = MAX(S[c0][c0+178], S[c0+1][c0+178-1] + can_pair(RNA, c0, c0+178));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1820; c0 += 1)
    for (c1 = c0 + 179; c1 <= min(c0 + 357, 1999); c1 += 1) {
      if (c0 + 356 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-179+c0] + S[-c0+c1-179+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][178+c0] + S[178+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1820; c0 += 1)
    S[c0][c0+179] = MAX(S[c0][c0+179], S[c0+1][c0+179-1] + can_pair(RNA, c0, c0+179));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1819; c0 += 1)
    for (c1 = c0 + 180; c1 <= min(c0 + 359, 1999); c1 += 1) {
      if (c0 + 358 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-180+c0] + S[-c0+c1-180+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][179+c0] + S[179+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1819; c0 += 1)
    S[c0][c0+180] = MAX(S[c0][c0+180], S[c0+1][c0+180-1] + can_pair(RNA, c0, c0+180));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1818; c0 += 1)
    for (c1 = c0 + 181; c1 <= min(c0 + 361, 1999); c1 += 1) {
      if (c0 + 360 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-181+c0] + S[-c0+c1-181+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][180+c0] + S[180+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1818; c0 += 1)
    S[c0][c0+181] = MAX(S[c0][c0+181], S[c0+1][c0+181-1] + can_pair(RNA, c0, c0+181));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1817; c0 += 1)
    for (c1 = c0 + 182; c1 <= min(c0 + 363, 1999); c1 += 1) {
      if (c0 + 362 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-182+c0] + S[-c0+c1-182+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][181+c0] + S[181+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1817; c0 += 1)
    S[c0][c0+182] = MAX(S[c0][c0+182], S[c0+1][c0+182-1] + can_pair(RNA, c0, c0+182));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1816; c0 += 1)
    for (c1 = c0 + 183; c1 <= min(c0 + 365, 1999); c1 += 1) {
      if (c0 + 364 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-183+c0] + S[-c0+c1-183+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][182+c0] + S[182+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1816; c0 += 1)
    S[c0][c0+183] = MAX(S[c0][c0+183], S[c0+1][c0+183-1] + can_pair(RNA, c0, c0+183));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1815; c0 += 1)
    for (c1 = c0 + 184; c1 <= min(c0 + 367, 1999); c1 += 1) {
      if (c0 + 366 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-184+c0] + S[-c0+c1-184+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][183+c0] + S[183+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1815; c0 += 1)
    S[c0][c0+184] = MAX(S[c0][c0+184], S[c0+1][c0+184-1] + can_pair(RNA, c0, c0+184));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1814; c0 += 1)
    for (c1 = c0 + 185; c1 <= min(c0 + 369, 1999); c1 += 1) {
      if (c0 + 368 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-185+c0] + S[-c0+c1-185+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][184+c0] + S[184+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1814; c0 += 1)
    S[c0][c0+185] = MAX(S[c0][c0+185], S[c0+1][c0+185-1] + can_pair(RNA, c0, c0+185));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1813; c0 += 1)
    for (c1 = c0 + 186; c1 <= min(c0 + 371, 1999); c1 += 1) {
      if (c0 + 370 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-186+c0] + S[-c0+c1-186+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][185+c0] + S[185+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1813; c0 += 1)
    S[c0][c0+186] = MAX(S[c0][c0+186], S[c0+1][c0+186-1] + can_pair(RNA, c0, c0+186));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1812; c0 += 1)
    for (c1 = c0 + 187; c1 <= min(c0 + 373, 1999); c1 += 1) {
      if (c0 + 372 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-187+c0] + S[-c0+c1-187+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][186+c0] + S[186+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1812; c0 += 1)
    S[c0][c0+187] = MAX(S[c0][c0+187], S[c0+1][c0+187-1] + can_pair(RNA, c0, c0+187));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1811; c0 += 1)
    for (c1 = c0 + 188; c1 <= min(c0 + 375, 1999); c1 += 1) {
      if (c0 + 374 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-188+c0] + S[-c0+c1-188+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][187+c0] + S[187+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1811; c0 += 1)
    S[c0][c0+188] = MAX(S[c0][c0+188], S[c0+1][c0+188-1] + can_pair(RNA, c0, c0+188));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1810; c0 += 1)
    for (c1 = c0 + 189; c1 <= min(c0 + 377, 1999); c1 += 1) {
      if (c0 + 376 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-189+c0] + S[-c0+c1-189+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][188+c0] + S[188+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1810; c0 += 1)
    S[c0][c0+189] = MAX(S[c0][c0+189], S[c0+1][c0+189-1] + can_pair(RNA, c0, c0+189));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1809; c0 += 1)
    for (c1 = c0 + 190; c1 <= min(c0 + 379, 1999); c1 += 1) {
      if (c0 + 378 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-190+c0] + S[-c0+c1-190+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][189+c0] + S[189+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1809; c0 += 1)
    S[c0][c0+190] = MAX(S[c0][c0+190], S[c0+1][c0+190-1] + can_pair(RNA, c0, c0+190));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1808; c0 += 1)
    for (c1 = c0 + 191; c1 <= min(c0 + 381, 1999); c1 += 1) {
      if (c0 + 380 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-191+c0] + S[-c0+c1-191+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][190+c0] + S[190+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1808; c0 += 1)
    S[c0][c0+191] = MAX(S[c0][c0+191], S[c0+1][c0+191-1] + can_pair(RNA, c0, c0+191));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1807; c0 += 1)
    for (c1 = c0 + 192; c1 <= min(c0 + 383, 1999); c1 += 1) {
      if (c0 + 382 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-192+c0] + S[-c0+c1-192+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][191+c0] + S[191+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1807; c0 += 1)
    S[c0][c0+192] = MAX(S[c0][c0+192], S[c0+1][c0+192-1] + can_pair(RNA, c0, c0+192));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1806; c0 += 1)
    for (c1 = c0 + 193; c1 <= min(c0 + 385, 1999); c1 += 1) {
      if (c0 + 384 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-193+c0] + S[-c0+c1-193+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][192+c0] + S[192+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1806; c0 += 1)
    S[c0][c0+193] = MAX(S[c0][c0+193], S[c0+1][c0+193-1] + can_pair(RNA, c0, c0+193));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1805; c0 += 1)
    for (c1 = c0 + 194; c1 <= min(c0 + 387, 1999); c1 += 1) {
      if (c0 + 386 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-194+c0] + S[-c0+c1-194+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][193+c0] + S[193+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1805; c0 += 1)
    S[c0][c0+194] = MAX(S[c0][c0+194], S[c0+1][c0+194-1] + can_pair(RNA, c0, c0+194));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1804; c0 += 1)
    for (c1 = c0 + 195; c1 <= min(c0 + 389, 1999); c1 += 1) {
      if (c0 + 388 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-195+c0] + S[-c0+c1-195+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][194+c0] + S[194+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1804; c0 += 1)
    S[c0][c0+195] = MAX(S[c0][c0+195], S[c0+1][c0+195-1] + can_pair(RNA, c0, c0+195));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1803; c0 += 1)
    for (c1 = c0 + 196; c1 <= min(c0 + 391, 1999); c1 += 1) {
      if (c0 + 390 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-196+c0] + S[-c0+c1-196+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][195+c0] + S[195+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1803; c0 += 1)
    S[c0][c0+196] = MAX(S[c0][c0+196], S[c0+1][c0+196-1] + can_pair(RNA, c0, c0+196));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1802; c0 += 1)
    for (c1 = c0 + 197; c1 <= min(c0 + 393, 1999); c1 += 1) {
      if (c0 + 392 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-197+c0] + S[-c0+c1-197+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][196+c0] + S[196+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1802; c0 += 1)
    S[c0][c0+197] = MAX(S[c0][c0+197], S[c0+1][c0+197-1] + can_pair(RNA, c0, c0+197));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1801; c0 += 1)
    for (c1 = c0 + 198; c1 <= min(c0 + 395, 1999); c1 += 1) {
      if (c0 + 394 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-198+c0] + S[-c0+c1-198+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][197+c0] + S[197+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1801; c0 += 1)
    S[c0][c0+198] = MAX(S[c0][c0+198], S[c0+1][c0+198-1] + can_pair(RNA, c0, c0+198));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1800; c0 += 1)
    for (c1 = c0 + 199; c1 <= min(c0 + 397, 1999); c1 += 1) {
      if (c0 + 396 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-199+c0] + S[-c0+c1-199+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][198+c0] + S[198+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1800; c0 += 1)
    S[c0][c0+199] = MAX(S[c0][c0+199], S[c0+1][c0+199-1] + can_pair(RNA, c0, c0+199));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1799; c0 += 1)
    for (c1 = c0 + 200; c1 <= min(c0 + 399, 1999); c1 += 1) {
      if (c0 + 398 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-200+c0] + S[-c0+c1-200+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][199+c0] + S[199+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1799; c0 += 1)
    S[c0][c0+200] = MAX(S[c0][c0+200], S[c0+1][c0+200-1] + can_pair(RNA, c0, c0+200));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1798; c0 += 1)
    for (c1 = c0 + 201; c1 <= min(c0 + 401, 1999); c1 += 1) {
      if (c0 + 400 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-201+c0] + S[-c0+c1-201+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][200+c0] + S[200+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1798; c0 += 1)
    S[c0][c0+201] = MAX(S[c0][c0+201], S[c0+1][c0+201-1] + can_pair(RNA, c0, c0+201));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1797; c0 += 1)
    for (c1 = c0 + 202; c1 <= min(c0 + 403, 1999); c1 += 1) {
      if (c0 + 402 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-202+c0] + S[-c0+c1-202+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][201+c0] + S[201+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1797; c0 += 1)
    S[c0][c0+202] = MAX(S[c0][c0+202], S[c0+1][c0+202-1] + can_pair(RNA, c0, c0+202));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1796; c0 += 1)
    for (c1 = c0 + 203; c1 <= min(c0 + 405, 1999); c1 += 1) {
      if (c0 + 404 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-203+c0] + S[-c0+c1-203+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][202+c0] + S[202+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1796; c0 += 1)
    S[c0][c0+203] = MAX(S[c0][c0+203], S[c0+1][c0+203-1] + can_pair(RNA, c0, c0+203));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1795; c0 += 1)
    for (c1 = c0 + 204; c1 <= min(c0 + 407, 1999); c1 += 1) {
      if (c0 + 406 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-204+c0] + S[-c0+c1-204+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][203+c0] + S[203+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1795; c0 += 1)
    S[c0][c0+204] = MAX(S[c0][c0+204], S[c0+1][c0+204-1] + can_pair(RNA, c0, c0+204));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1794; c0 += 1)
    for (c1 = c0 + 205; c1 <= min(c0 + 409, 1999); c1 += 1) {
      if (c0 + 408 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-205+c0] + S[-c0+c1-205+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][204+c0] + S[204+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1794; c0 += 1)
    S[c0][c0+205] = MAX(S[c0][c0+205], S[c0+1][c0+205-1] + can_pair(RNA, c0, c0+205));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1793; c0 += 1)
    for (c1 = c0 + 206; c1 <= min(c0 + 411, 1999); c1 += 1) {
      if (c0 + 410 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-206+c0] + S[-c0+c1-206+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][205+c0] + S[205+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1793; c0 += 1)
    S[c0][c0+206] = MAX(S[c0][c0+206], S[c0+1][c0+206-1] + can_pair(RNA, c0, c0+206));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1792; c0 += 1)
    for (c1 = c0 + 207; c1 <= min(c0 + 413, 1999); c1 += 1) {
      if (c0 + 412 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-207+c0] + S[-c0+c1-207+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][206+c0] + S[206+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1792; c0 += 1)
    S[c0][c0+207] = MAX(S[c0][c0+207], S[c0+1][c0+207-1] + can_pair(RNA, c0, c0+207));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1791; c0 += 1)
    for (c1 = c0 + 208; c1 <= min(c0 + 415, 1999); c1 += 1) {
      if (c0 + 414 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-208+c0] + S[-c0+c1-208+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][207+c0] + S[207+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1791; c0 += 1)
    S[c0][c0+208] = MAX(S[c0][c0+208], S[c0+1][c0+208-1] + can_pair(RNA, c0, c0+208));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1790; c0 += 1)
    for (c1 = c0 + 209; c1 <= min(c0 + 417, 1999); c1 += 1) {
      if (c0 + 416 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-209+c0] + S[-c0+c1-209+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][208+c0] + S[208+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1790; c0 += 1)
    S[c0][c0+209] = MAX(S[c0][c0+209], S[c0+1][c0+209-1] + can_pair(RNA, c0, c0+209));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1789; c0 += 1)
    for (c1 = c0 + 210; c1 <= min(c0 + 419, 1999); c1 += 1) {
      if (c0 + 418 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-210+c0] + S[-c0+c1-210+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][209+c0] + S[209+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1789; c0 += 1)
    S[c0][c0+210] = MAX(S[c0][c0+210], S[c0+1][c0+210-1] + can_pair(RNA, c0, c0+210));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1788; c0 += 1)
    for (c1 = c0 + 211; c1 <= min(c0 + 421, 1999); c1 += 1) {
      if (c0 + 420 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-211+c0] + S[-c0+c1-211+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][210+c0] + S[210+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1788; c0 += 1)
    S[c0][c0+211] = MAX(S[c0][c0+211], S[c0+1][c0+211-1] + can_pair(RNA, c0, c0+211));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1787; c0 += 1)
    for (c1 = c0 + 212; c1 <= min(c0 + 423, 1999); c1 += 1) {
      if (c0 + 422 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-212+c0] + S[-c0+c1-212+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][211+c0] + S[211+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1787; c0 += 1)
    S[c0][c0+212] = MAX(S[c0][c0+212], S[c0+1][c0+212-1] + can_pair(RNA, c0, c0+212));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1786; c0 += 1)
    for (c1 = c0 + 213; c1 <= min(c0 + 425, 1999); c1 += 1) {
      if (c0 + 424 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-213+c0] + S[-c0+c1-213+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][212+c0] + S[212+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1786; c0 += 1)
    S[c0][c0+213] = MAX(S[c0][c0+213], S[c0+1][c0+213-1] + can_pair(RNA, c0, c0+213));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1785; c0 += 1)
    for (c1 = c0 + 214; c1 <= min(c0 + 427, 1999); c1 += 1) {
      if (c0 + 426 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-214+c0] + S[-c0+c1-214+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][213+c0] + S[213+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1785; c0 += 1)
    S[c0][c0+214] = MAX(S[c0][c0+214], S[c0+1][c0+214-1] + can_pair(RNA, c0, c0+214));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1784; c0 += 1)
    for (c1 = c0 + 215; c1 <= min(c0 + 429, 1999); c1 += 1) {
      if (c0 + 428 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-215+c0] + S[-c0+c1-215+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][214+c0] + S[214+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1784; c0 += 1)
    S[c0][c0+215] = MAX(S[c0][c0+215], S[c0+1][c0+215-1] + can_pair(RNA, c0, c0+215));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1783; c0 += 1)
    for (c1 = c0 + 216; c1 <= min(c0 + 431, 1999); c1 += 1) {
      if (c0 + 430 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-216+c0] + S[-c0+c1-216+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][215+c0] + S[215+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1783; c0 += 1)
    S[c0][c0+216] = MAX(S[c0][c0+216], S[c0+1][c0+216-1] + can_pair(RNA, c0, c0+216));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1782; c0 += 1)
    for (c1 = c0 + 217; c1 <= min(c0 + 433, 1999); c1 += 1) {
      if (c0 + 432 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-217+c0] + S[-c0+c1-217+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][216+c0] + S[216+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1782; c0 += 1)
    S[c0][c0+217] = MAX(S[c0][c0+217], S[c0+1][c0+217-1] + can_pair(RNA, c0, c0+217));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1781; c0 += 1)
    for (c1 = c0 + 218; c1 <= min(c0 + 435, 1999); c1 += 1) {
      if (c0 + 434 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-218+c0] + S[-c0+c1-218+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][217+c0] + S[217+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1781; c0 += 1)
    S[c0][c0+218] = MAX(S[c0][c0+218], S[c0+1][c0+218-1] + can_pair(RNA, c0, c0+218));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1780; c0 += 1)
    for (c1 = c0 + 219; c1 <= min(c0 + 437, 1999); c1 += 1) {
      if (c0 + 436 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-219+c0] + S[-c0+c1-219+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][218+c0] + S[218+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1780; c0 += 1)
    S[c0][c0+219] = MAX(S[c0][c0+219], S[c0+1][c0+219-1] + can_pair(RNA, c0, c0+219));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1779; c0 += 1)
    for (c1 = c0 + 220; c1 <= min(c0 + 439, 1999); c1 += 1) {
      if (c0 + 438 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-220+c0] + S[-c0+c1-220+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][219+c0] + S[219+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1779; c0 += 1)
    S[c0][c0+220] = MAX(S[c0][c0+220], S[c0+1][c0+220-1] + can_pair(RNA, c0, c0+220));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1778; c0 += 1)
    for (c1 = c0 + 221; c1 <= min(c0 + 441, 1999); c1 += 1) {
      if (c0 + 440 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-221+c0] + S[-c0+c1-221+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][220+c0] + S[220+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1778; c0 += 1)
    S[c0][c0+221] = MAX(S[c0][c0+221], S[c0+1][c0+221-1] + can_pair(RNA, c0, c0+221));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1777; c0 += 1)
    for (c1 = c0 + 222; c1 <= min(c0 + 443, 1999); c1 += 1) {
      if (c0 + 442 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-222+c0] + S[-c0+c1-222+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][221+c0] + S[221+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1777; c0 += 1)
    S[c0][c0+222] = MAX(S[c0][c0+222], S[c0+1][c0+222-1] + can_pair(RNA, c0, c0+222));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1776; c0 += 1)
    for (c1 = c0 + 223; c1 <= min(c0 + 445, 1999); c1 += 1) {
      if (c0 + 444 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-223+c0] + S[-c0+c1-223+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][222+c0] + S[222+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1776; c0 += 1)
    S[c0][c0+223] = MAX(S[c0][c0+223], S[c0+1][c0+223-1] + can_pair(RNA, c0, c0+223));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1775; c0 += 1)
    for (c1 = c0 + 224; c1 <= min(c0 + 447, 1999); c1 += 1) {
      if (c0 + 446 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-224+c0] + S[-c0+c1-224+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][223+c0] + S[223+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1775; c0 += 1)
    S[c0][c0+224] = MAX(S[c0][c0+224], S[c0+1][c0+224-1] + can_pair(RNA, c0, c0+224));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1774; c0 += 1)
    for (c1 = c0 + 225; c1 <= min(c0 + 449, 1999); c1 += 1) {
      if (c0 + 448 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-225+c0] + S[-c0+c1-225+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][224+c0] + S[224+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1774; c0 += 1)
    S[c0][c0+225] = MAX(S[c0][c0+225], S[c0+1][c0+225-1] + can_pair(RNA, c0, c0+225));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1773; c0 += 1)
    for (c1 = c0 + 226; c1 <= min(c0 + 451, 1999); c1 += 1) {
      if (c0 + 450 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-226+c0] + S[-c0+c1-226+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][225+c0] + S[225+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1773; c0 += 1)
    S[c0][c0+226] = MAX(S[c0][c0+226], S[c0+1][c0+226-1] + can_pair(RNA, c0, c0+226));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1772; c0 += 1)
    for (c1 = c0 + 227; c1 <= min(c0 + 453, 1999); c1 += 1) {
      if (c0 + 452 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-227+c0] + S[-c0+c1-227+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][226+c0] + S[226+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1772; c0 += 1)
    S[c0][c0+227] = MAX(S[c0][c0+227], S[c0+1][c0+227-1] + can_pair(RNA, c0, c0+227));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1771; c0 += 1)
    for (c1 = c0 + 228; c1 <= min(c0 + 455, 1999); c1 += 1) {
      if (c0 + 454 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-228+c0] + S[-c0+c1-228+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][227+c0] + S[227+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1771; c0 += 1)
    S[c0][c0+228] = MAX(S[c0][c0+228], S[c0+1][c0+228-1] + can_pair(RNA, c0, c0+228));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1770; c0 += 1)
    for (c1 = c0 + 229; c1 <= min(c0 + 457, 1999); c1 += 1) {
      if (c0 + 456 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-229+c0] + S[-c0+c1-229+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][228+c0] + S[228+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1770; c0 += 1)
    S[c0][c0+229] = MAX(S[c0][c0+229], S[c0+1][c0+229-1] + can_pair(RNA, c0, c0+229));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1769; c0 += 1)
    for (c1 = c0 + 230; c1 <= min(c0 + 459, 1999); c1 += 1) {
      if (c0 + 458 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-230+c0] + S[-c0+c1-230+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][229+c0] + S[229+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1769; c0 += 1)
    S[c0][c0+230] = MAX(S[c0][c0+230], S[c0+1][c0+230-1] + can_pair(RNA, c0, c0+230));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1768; c0 += 1)
    for (c1 = c0 + 231; c1 <= min(c0 + 461, 1999); c1 += 1) {
      if (c0 + 460 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-231+c0] + S[-c0+c1-231+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][230+c0] + S[230+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1768; c0 += 1)
    S[c0][c0+231] = MAX(S[c0][c0+231], S[c0+1][c0+231-1] + can_pair(RNA, c0, c0+231));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1767; c0 += 1)
    for (c1 = c0 + 232; c1 <= min(c0 + 463, 1999); c1 += 1) {
      if (c0 + 462 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-232+c0] + S[-c0+c1-232+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][231+c0] + S[231+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1767; c0 += 1)
    S[c0][c0+232] = MAX(S[c0][c0+232], S[c0+1][c0+232-1] + can_pair(RNA, c0, c0+232));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1766; c0 += 1)
    for (c1 = c0 + 233; c1 <= min(c0 + 465, 1999); c1 += 1) {
      if (c0 + 464 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-233+c0] + S[-c0+c1-233+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][232+c0] + S[232+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1766; c0 += 1)
    S[c0][c0+233] = MAX(S[c0][c0+233], S[c0+1][c0+233-1] + can_pair(RNA, c0, c0+233));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1765; c0 += 1)
    for (c1 = c0 + 234; c1 <= min(c0 + 467, 1999); c1 += 1) {
      if (c0 + 466 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-234+c0] + S[-c0+c1-234+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][233+c0] + S[233+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1765; c0 += 1)
    S[c0][c0+234] = MAX(S[c0][c0+234], S[c0+1][c0+234-1] + can_pair(RNA, c0, c0+234));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1764; c0 += 1)
    for (c1 = c0 + 235; c1 <= min(c0 + 469, 1999); c1 += 1) {
      if (c0 + 468 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-235+c0] + S[-c0+c1-235+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][234+c0] + S[234+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1764; c0 += 1)
    S[c0][c0+235] = MAX(S[c0][c0+235], S[c0+1][c0+235-1] + can_pair(RNA, c0, c0+235));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1763; c0 += 1)
    for (c1 = c0 + 236; c1 <= min(c0 + 471, 1999); c1 += 1) {
      if (c0 + 470 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-236+c0] + S[-c0+c1-236+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][235+c0] + S[235+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1763; c0 += 1)
    S[c0][c0+236] = MAX(S[c0][c0+236], S[c0+1][c0+236-1] + can_pair(RNA, c0, c0+236));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1762; c0 += 1)
    for (c1 = c0 + 237; c1 <= min(c0 + 473, 1999); c1 += 1) {
      if (c0 + 472 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-237+c0] + S[-c0+c1-237+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][236+c0] + S[236+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1762; c0 += 1)
    S[c0][c0+237] = MAX(S[c0][c0+237], S[c0+1][c0+237-1] + can_pair(RNA, c0, c0+237));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1761; c0 += 1)
    for (c1 = c0 + 238; c1 <= min(c0 + 475, 1999); c1 += 1) {
      if (c0 + 474 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-238+c0] + S[-c0+c1-238+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][237+c0] + S[237+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1761; c0 += 1)
    S[c0][c0+238] = MAX(S[c0][c0+238], S[c0+1][c0+238-1] + can_pair(RNA, c0, c0+238));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1760; c0 += 1)
    for (c1 = c0 + 239; c1 <= min(c0 + 477, 1999); c1 += 1) {
      if (c0 + 476 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-239+c0] + S[-c0+c1-239+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][238+c0] + S[238+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1760; c0 += 1)
    S[c0][c0+239] = MAX(S[c0][c0+239], S[c0+1][c0+239-1] + can_pair(RNA, c0, c0+239));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1759; c0 += 1)
    for (c1 = c0 + 240; c1 <= min(c0 + 479, 1999); c1 += 1) {
      if (c0 + 478 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-240+c0] + S[-c0+c1-240+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][239+c0] + S[239+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1759; c0 += 1)
    S[c0][c0+240] = MAX(S[c0][c0+240], S[c0+1][c0+240-1] + can_pair(RNA, c0, c0+240));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1758; c0 += 1)
    for (c1 = c0 + 241; c1 <= min(c0 + 481, 1999); c1 += 1) {
      if (c0 + 480 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-241+c0] + S[-c0+c1-241+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][240+c0] + S[240+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1758; c0 += 1)
    S[c0][c0+241] = MAX(S[c0][c0+241], S[c0+1][c0+241-1] + can_pair(RNA, c0, c0+241));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1757; c0 += 1)
    for (c1 = c0 + 242; c1 <= min(c0 + 483, 1999); c1 += 1) {
      if (c0 + 482 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-242+c0] + S[-c0+c1-242+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][241+c0] + S[241+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1757; c0 += 1)
    S[c0][c0+242] = MAX(S[c0][c0+242], S[c0+1][c0+242-1] + can_pair(RNA, c0, c0+242));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1756; c0 += 1)
    for (c1 = c0 + 243; c1 <= min(c0 + 485, 1999); c1 += 1) {
      if (c0 + 484 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-243+c0] + S[-c0+c1-243+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][242+c0] + S[242+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1756; c0 += 1)
    S[c0][c0+243] = MAX(S[c0][c0+243], S[c0+1][c0+243-1] + can_pair(RNA, c0, c0+243));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1755; c0 += 1)
    for (c1 = c0 + 244; c1 <= min(c0 + 487, 1999); c1 += 1) {
      if (c0 + 486 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-244+c0] + S[-c0+c1-244+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][243+c0] + S[243+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1755; c0 += 1)
    S[c0][c0+244] = MAX(S[c0][c0+244], S[c0+1][c0+244-1] + can_pair(RNA, c0, c0+244));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1754; c0 += 1)
    for (c1 = c0 + 245; c1 <= min(c0 + 489, 1999); c1 += 1) {
      if (c0 + 488 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-245+c0] + S[-c0+c1-245+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][244+c0] + S[244+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1754; c0 += 1)
    S[c0][c0+245] = MAX(S[c0][c0+245], S[c0+1][c0+245-1] + can_pair(RNA, c0, c0+245));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1753; c0 += 1)
    for (c1 = c0 + 246; c1 <= min(c0 + 491, 1999); c1 += 1) {
      if (c0 + 490 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-246+c0] + S[-c0+c1-246+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][245+c0] + S[245+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1753; c0 += 1)
    S[c0][c0+246] = MAX(S[c0][c0+246], S[c0+1][c0+246-1] + can_pair(RNA, c0, c0+246));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1752; c0 += 1)
    for (c1 = c0 + 247; c1 <= min(c0 + 493, 1999); c1 += 1) {
      if (c0 + 492 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-247+c0] + S[-c0+c1-247+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][246+c0] + S[246+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1752; c0 += 1)
    S[c0][c0+247] = MAX(S[c0][c0+247], S[c0+1][c0+247-1] + can_pair(RNA, c0, c0+247));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1751; c0 += 1)
    for (c1 = c0 + 248; c1 <= min(c0 + 495, 1999); c1 += 1) {
      if (c0 + 494 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-248+c0] + S[-c0+c1-248+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][247+c0] + S[247+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1751; c0 += 1)
    S[c0][c0+248] = MAX(S[c0][c0+248], S[c0+1][c0+248-1] + can_pair(RNA, c0, c0+248));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1750; c0 += 1)
    for (c1 = c0 + 249; c1 <= min(c0 + 497, 1999); c1 += 1) {
      if (c0 + 496 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-249+c0] + S[-c0+c1-249+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][248+c0] + S[248+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1750; c0 += 1)
    S[c0][c0+249] = MAX(S[c0][c0+249], S[c0+1][c0+249-1] + can_pair(RNA, c0, c0+249));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1749; c0 += 1)
    for (c1 = c0 + 250; c1 <= min(c0 + 499, 1999); c1 += 1) {
      if (c0 + 498 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-250+c0] + S[-c0+c1-250+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][249+c0] + S[249+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1749; c0 += 1)
    S[c0][c0+250] = MAX(S[c0][c0+250], S[c0+1][c0+250-1] + can_pair(RNA, c0, c0+250));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1748; c0 += 1)
    for (c1 = c0 + 251; c1 <= min(c0 + 501, 1999); c1 += 1) {
      if (c0 + 500 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-251+c0] + S[-c0+c1-251+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][250+c0] + S[250+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1748; c0 += 1)
    S[c0][c0+251] = MAX(S[c0][c0+251], S[c0+1][c0+251-1] + can_pair(RNA, c0, c0+251));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1747; c0 += 1)
    for (c1 = c0 + 252; c1 <= min(c0 + 503, 1999); c1 += 1) {
      if (c0 + 502 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-252+c0] + S[-c0+c1-252+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][251+c0] + S[251+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1747; c0 += 1)
    S[c0][c0+252] = MAX(S[c0][c0+252], S[c0+1][c0+252-1] + can_pair(RNA, c0, c0+252));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1746; c0 += 1)
    for (c1 = c0 + 253; c1 <= min(c0 + 505, 1999); c1 += 1) {
      if (c0 + 504 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-253+c0] + S[-c0+c1-253+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][252+c0] + S[252+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1746; c0 += 1)
    S[c0][c0+253] = MAX(S[c0][c0+253], S[c0+1][c0+253-1] + can_pair(RNA, c0, c0+253));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1745; c0 += 1)
    for (c1 = c0 + 254; c1 <= min(c0 + 507, 1999); c1 += 1) {
      if (c0 + 506 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-254+c0] + S[-c0+c1-254+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][253+c0] + S[253+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1745; c0 += 1)
    S[c0][c0+254] = MAX(S[c0][c0+254], S[c0+1][c0+254-1] + can_pair(RNA, c0, c0+254));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1744; c0 += 1)
    for (c1 = c0 + 255; c1 <= min(c0 + 509, 1999); c1 += 1) {
      if (c0 + 508 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-255+c0] + S[-c0+c1-255+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][254+c0] + S[254+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1744; c0 += 1)
    S[c0][c0+255] = MAX(S[c0][c0+255], S[c0+1][c0+255-1] + can_pair(RNA, c0, c0+255));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1743; c0 += 1)
    for (c1 = c0 + 256; c1 <= min(c0 + 511, 1999); c1 += 1) {
      if (c0 + 510 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-256+c0] + S[-c0+c1-256+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][255+c0] + S[255+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1743; c0 += 1)
    S[c0][c0+256] = MAX(S[c0][c0+256], S[c0+1][c0+256-1] + can_pair(RNA, c0, c0+256));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1742; c0 += 1)
    for (c1 = c0 + 257; c1 <= min(c0 + 513, 1999); c1 += 1) {
      if (c0 + 512 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-257+c0] + S[-c0+c1-257+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][256+c0] + S[256+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1742; c0 += 1)
    S[c0][c0+257] = MAX(S[c0][c0+257], S[c0+1][c0+257-1] + can_pair(RNA, c0, c0+257));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1741; c0 += 1)
    for (c1 = c0 + 258; c1 <= min(c0 + 515, 1999); c1 += 1) {
      if (c0 + 514 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-258+c0] + S[-c0+c1-258+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][257+c0] + S[257+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1741; c0 += 1)
    S[c0][c0+258] = MAX(S[c0][c0+258], S[c0+1][c0+258-1] + can_pair(RNA, c0, c0+258));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1740; c0 += 1)
    for (c1 = c0 + 259; c1 <= min(c0 + 517, 1999); c1 += 1) {
      if (c0 + 516 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-259+c0] + S[-c0+c1-259+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][258+c0] + S[258+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1740; c0 += 1)
    S[c0][c0+259] = MAX(S[c0][c0+259], S[c0+1][c0+259-1] + can_pair(RNA, c0, c0+259));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1739; c0 += 1)
    for (c1 = c0 + 260; c1 <= min(c0 + 519, 1999); c1 += 1) {
      if (c0 + 518 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-260+c0] + S[-c0+c1-260+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][259+c0] + S[259+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1739; c0 += 1)
    S[c0][c0+260] = MAX(S[c0][c0+260], S[c0+1][c0+260-1] + can_pair(RNA, c0, c0+260));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1738; c0 += 1)
    for (c1 = c0 + 261; c1 <= min(c0 + 521, 1999); c1 += 1) {
      if (c0 + 520 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-261+c0] + S[-c0+c1-261+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][260+c0] + S[260+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1738; c0 += 1)
    S[c0][c0+261] = MAX(S[c0][c0+261], S[c0+1][c0+261-1] + can_pair(RNA, c0, c0+261));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1737; c0 += 1)
    for (c1 = c0 + 262; c1 <= min(c0 + 523, 1999); c1 += 1) {
      if (c0 + 522 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-262+c0] + S[-c0+c1-262+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][261+c0] + S[261+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1737; c0 += 1)
    S[c0][c0+262] = MAX(S[c0][c0+262], S[c0+1][c0+262-1] + can_pair(RNA, c0, c0+262));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1736; c0 += 1)
    for (c1 = c0 + 263; c1 <= min(c0 + 525, 1999); c1 += 1) {
      if (c0 + 524 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-263+c0] + S[-c0+c1-263+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][262+c0] + S[262+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1736; c0 += 1)
    S[c0][c0+263] = MAX(S[c0][c0+263], S[c0+1][c0+263-1] + can_pair(RNA, c0, c0+263));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1735; c0 += 1)
    for (c1 = c0 + 264; c1 <= min(c0 + 527, 1999); c1 += 1) {
      if (c0 + 526 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-264+c0] + S[-c0+c1-264+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][263+c0] + S[263+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1735; c0 += 1)
    S[c0][c0+264] = MAX(S[c0][c0+264], S[c0+1][c0+264-1] + can_pair(RNA, c0, c0+264));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1734; c0 += 1)
    for (c1 = c0 + 265; c1 <= min(c0 + 529, 1999); c1 += 1) {
      if (c0 + 528 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-265+c0] + S[-c0+c1-265+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][264+c0] + S[264+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1734; c0 += 1)
    S[c0][c0+265] = MAX(S[c0][c0+265], S[c0+1][c0+265-1] + can_pair(RNA, c0, c0+265));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1733; c0 += 1)
    for (c1 = c0 + 266; c1 <= min(c0 + 531, 1999); c1 += 1) {
      if (c0 + 530 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-266+c0] + S[-c0+c1-266+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][265+c0] + S[265+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1733; c0 += 1)
    S[c0][c0+266] = MAX(S[c0][c0+266], S[c0+1][c0+266-1] + can_pair(RNA, c0, c0+266));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1732; c0 += 1)
    for (c1 = c0 + 267; c1 <= min(c0 + 533, 1999); c1 += 1) {
      if (c0 + 532 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-267+c0] + S[-c0+c1-267+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][266+c0] + S[266+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1732; c0 += 1)
    S[c0][c0+267] = MAX(S[c0][c0+267], S[c0+1][c0+267-1] + can_pair(RNA, c0, c0+267));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1731; c0 += 1)
    for (c1 = c0 + 268; c1 <= min(c0 + 535, 1999); c1 += 1) {
      if (c0 + 534 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-268+c0] + S[-c0+c1-268+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][267+c0] + S[267+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1731; c0 += 1)
    S[c0][c0+268] = MAX(S[c0][c0+268], S[c0+1][c0+268-1] + can_pair(RNA, c0, c0+268));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1730; c0 += 1)
    for (c1 = c0 + 269; c1 <= min(c0 + 537, 1999); c1 += 1) {
      if (c0 + 536 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-269+c0] + S[-c0+c1-269+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][268+c0] + S[268+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1730; c0 += 1)
    S[c0][c0+269] = MAX(S[c0][c0+269], S[c0+1][c0+269-1] + can_pair(RNA, c0, c0+269));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1729; c0 += 1)
    for (c1 = c0 + 270; c1 <= min(c0 + 539, 1999); c1 += 1) {
      if (c0 + 538 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-270+c0] + S[-c0+c1-270+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][269+c0] + S[269+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1729; c0 += 1)
    S[c0][c0+270] = MAX(S[c0][c0+270], S[c0+1][c0+270-1] + can_pair(RNA, c0, c0+270));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1728; c0 += 1)
    for (c1 = c0 + 271; c1 <= min(c0 + 541, 1999); c1 += 1) {
      if (c0 + 540 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-271+c0] + S[-c0+c1-271+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][270+c0] + S[270+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1728; c0 += 1)
    S[c0][c0+271] = MAX(S[c0][c0+271], S[c0+1][c0+271-1] + can_pair(RNA, c0, c0+271));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1727; c0 += 1)
    for (c1 = c0 + 272; c1 <= min(c0 + 543, 1999); c1 += 1) {
      if (c0 + 542 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-272+c0] + S[-c0+c1-272+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][271+c0] + S[271+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1727; c0 += 1)
    S[c0][c0+272] = MAX(S[c0][c0+272], S[c0+1][c0+272-1] + can_pair(RNA, c0, c0+272));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1726; c0 += 1)
    for (c1 = c0 + 273; c1 <= min(c0 + 545, 1999); c1 += 1) {
      if (c0 + 544 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-273+c0] + S[-c0+c1-273+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][272+c0] + S[272+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1726; c0 += 1)
    S[c0][c0+273] = MAX(S[c0][c0+273], S[c0+1][c0+273-1] + can_pair(RNA, c0, c0+273));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1725; c0 += 1)
    for (c1 = c0 + 274; c1 <= min(c0 + 547, 1999); c1 += 1) {
      if (c0 + 546 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-274+c0] + S[-c0+c1-274+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][273+c0] + S[273+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1725; c0 += 1)
    S[c0][c0+274] = MAX(S[c0][c0+274], S[c0+1][c0+274-1] + can_pair(RNA, c0, c0+274));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1724; c0 += 1)
    for (c1 = c0 + 275; c1 <= min(c0 + 549, 1999); c1 += 1) {
      if (c0 + 548 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-275+c0] + S[-c0+c1-275+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][274+c0] + S[274+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1724; c0 += 1)
    S[c0][c0+275] = MAX(S[c0][c0+275], S[c0+1][c0+275-1] + can_pair(RNA, c0, c0+275));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1723; c0 += 1)
    for (c1 = c0 + 276; c1 <= min(c0 + 551, 1999); c1 += 1) {
      if (c0 + 550 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-276+c0] + S[-c0+c1-276+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][275+c0] + S[275+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1723; c0 += 1)
    S[c0][c0+276] = MAX(S[c0][c0+276], S[c0+1][c0+276-1] + can_pair(RNA, c0, c0+276));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1722; c0 += 1)
    for (c1 = c0 + 277; c1 <= min(c0 + 553, 1999); c1 += 1) {
      if (c0 + 552 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-277+c0] + S[-c0+c1-277+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][276+c0] + S[276+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1722; c0 += 1)
    S[c0][c0+277] = MAX(S[c0][c0+277], S[c0+1][c0+277-1] + can_pair(RNA, c0, c0+277));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1721; c0 += 1)
    for (c1 = c0 + 278; c1 <= min(c0 + 555, 1999); c1 += 1) {
      if (c0 + 554 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-278+c0] + S[-c0+c1-278+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][277+c0] + S[277+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1721; c0 += 1)
    S[c0][c0+278] = MAX(S[c0][c0+278], S[c0+1][c0+278-1] + can_pair(RNA, c0, c0+278));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1720; c0 += 1)
    for (c1 = c0 + 279; c1 <= min(c0 + 557, 1999); c1 += 1) {
      if (c0 + 556 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-279+c0] + S[-c0+c1-279+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][278+c0] + S[278+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1720; c0 += 1)
    S[c0][c0+279] = MAX(S[c0][c0+279], S[c0+1][c0+279-1] + can_pair(RNA, c0, c0+279));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1719; c0 += 1)
    for (c1 = c0 + 280; c1 <= min(c0 + 559, 1999); c1 += 1) {
      if (c0 + 558 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-280+c0] + S[-c0+c1-280+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][279+c0] + S[279+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1719; c0 += 1)
    S[c0][c0+280] = MAX(S[c0][c0+280], S[c0+1][c0+280-1] + can_pair(RNA, c0, c0+280));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1718; c0 += 1)
    for (c1 = c0 + 281; c1 <= min(c0 + 561, 1999); c1 += 1) {
      if (c0 + 560 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-281+c0] + S[-c0+c1-281+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][280+c0] + S[280+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1718; c0 += 1)
    S[c0][c0+281] = MAX(S[c0][c0+281], S[c0+1][c0+281-1] + can_pair(RNA, c0, c0+281));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1717; c0 += 1)
    for (c1 = c0 + 282; c1 <= min(c0 + 563, 1999); c1 += 1) {
      if (c0 + 562 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-282+c0] + S[-c0+c1-282+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][281+c0] + S[281+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1717; c0 += 1)
    S[c0][c0+282] = MAX(S[c0][c0+282], S[c0+1][c0+282-1] + can_pair(RNA, c0, c0+282));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1716; c0 += 1)
    for (c1 = c0 + 283; c1 <= min(c0 + 565, 1999); c1 += 1) {
      if (c0 + 564 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-283+c0] + S[-c0+c1-283+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][282+c0] + S[282+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1716; c0 += 1)
    S[c0][c0+283] = MAX(S[c0][c0+283], S[c0+1][c0+283-1] + can_pair(RNA, c0, c0+283));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1715; c0 += 1)
    for (c1 = c0 + 284; c1 <= min(c0 + 567, 1999); c1 += 1) {
      if (c0 + 566 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-284+c0] + S[-c0+c1-284+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][283+c0] + S[283+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1715; c0 += 1)
    S[c0][c0+284] = MAX(S[c0][c0+284], S[c0+1][c0+284-1] + can_pair(RNA, c0, c0+284));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1714; c0 += 1)
    for (c1 = c0 + 285; c1 <= min(c0 + 569, 1999); c1 += 1) {
      if (c0 + 568 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-285+c0] + S[-c0+c1-285+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][284+c0] + S[284+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1714; c0 += 1)
    S[c0][c0+285] = MAX(S[c0][c0+285], S[c0+1][c0+285-1] + can_pair(RNA, c0, c0+285));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1713; c0 += 1)
    for (c1 = c0 + 286; c1 <= min(c0 + 571, 1999); c1 += 1) {
      if (c0 + 570 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-286+c0] + S[-c0+c1-286+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][285+c0] + S[285+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1713; c0 += 1)
    S[c0][c0+286] = MAX(S[c0][c0+286], S[c0+1][c0+286-1] + can_pair(RNA, c0, c0+286));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1712; c0 += 1)
    for (c1 = c0 + 287; c1 <= min(c0 + 573, 1999); c1 += 1) {
      if (c0 + 572 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-287+c0] + S[-c0+c1-287+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][286+c0] + S[286+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1712; c0 += 1)
    S[c0][c0+287] = MAX(S[c0][c0+287], S[c0+1][c0+287-1] + can_pair(RNA, c0, c0+287));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1711; c0 += 1)
    for (c1 = c0 + 288; c1 <= min(c0 + 575, 1999); c1 += 1) {
      if (c0 + 574 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-288+c0] + S[-c0+c1-288+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][287+c0] + S[287+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1711; c0 += 1)
    S[c0][c0+288] = MAX(S[c0][c0+288], S[c0+1][c0+288-1] + can_pair(RNA, c0, c0+288));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1710; c0 += 1)
    for (c1 = c0 + 289; c1 <= min(c0 + 577, 1999); c1 += 1) {
      if (c0 + 576 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-289+c0] + S[-c0+c1-289+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][288+c0] + S[288+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1710; c0 += 1)
    S[c0][c0+289] = MAX(S[c0][c0+289], S[c0+1][c0+289-1] + can_pair(RNA, c0, c0+289));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1709; c0 += 1)
    for (c1 = c0 + 290; c1 <= min(c0 + 579, 1999); c1 += 1) {
      if (c0 + 578 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-290+c0] + S[-c0+c1-290+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][289+c0] + S[289+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1709; c0 += 1)
    S[c0][c0+290] = MAX(S[c0][c0+290], S[c0+1][c0+290-1] + can_pair(RNA, c0, c0+290));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1708; c0 += 1)
    for (c1 = c0 + 291; c1 <= min(c0 + 581, 1999); c1 += 1) {
      if (c0 + 580 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-291+c0] + S[-c0+c1-291+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][290+c0] + S[290+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1708; c0 += 1)
    S[c0][c0+291] = MAX(S[c0][c0+291], S[c0+1][c0+291-1] + can_pair(RNA, c0, c0+291));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1707; c0 += 1)
    for (c1 = c0 + 292; c1 <= min(c0 + 583, 1999); c1 += 1) {
      if (c0 + 582 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-292+c0] + S[-c0+c1-292+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][291+c0] + S[291+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1707; c0 += 1)
    S[c0][c0+292] = MAX(S[c0][c0+292], S[c0+1][c0+292-1] + can_pair(RNA, c0, c0+292));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1706; c0 += 1)
    for (c1 = c0 + 293; c1 <= min(c0 + 585, 1999); c1 += 1) {
      if (c0 + 584 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-293+c0] + S[-c0+c1-293+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][292+c0] + S[292+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1706; c0 += 1)
    S[c0][c0+293] = MAX(S[c0][c0+293], S[c0+1][c0+293-1] + can_pair(RNA, c0, c0+293));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1705; c0 += 1)
    for (c1 = c0 + 294; c1 <= min(c0 + 587, 1999); c1 += 1) {
      if (c0 + 586 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-294+c0] + S[-c0+c1-294+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][293+c0] + S[293+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1705; c0 += 1)
    S[c0][c0+294] = MAX(S[c0][c0+294], S[c0+1][c0+294-1] + can_pair(RNA, c0, c0+294));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1704; c0 += 1)
    for (c1 = c0 + 295; c1 <= min(c0 + 589, 1999); c1 += 1) {
      if (c0 + 588 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-295+c0] + S[-c0+c1-295+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][294+c0] + S[294+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1704; c0 += 1)
    S[c0][c0+295] = MAX(S[c0][c0+295], S[c0+1][c0+295-1] + can_pair(RNA, c0, c0+295));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1703; c0 += 1)
    for (c1 = c0 + 296; c1 <= min(c0 + 591, 1999); c1 += 1) {
      if (c0 + 590 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-296+c0] + S[-c0+c1-296+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][295+c0] + S[295+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1703; c0 += 1)
    S[c0][c0+296] = MAX(S[c0][c0+296], S[c0+1][c0+296-1] + can_pair(RNA, c0, c0+296));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1702; c0 += 1)
    for (c1 = c0 + 297; c1 <= min(c0 + 593, 1999); c1 += 1) {
      if (c0 + 592 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-297+c0] + S[-c0+c1-297+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][296+c0] + S[296+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1702; c0 += 1)
    S[c0][c0+297] = MAX(S[c0][c0+297], S[c0+1][c0+297-1] + can_pair(RNA, c0, c0+297));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1701; c0 += 1)
    for (c1 = c0 + 298; c1 <= min(c0 + 595, 1999); c1 += 1) {
      if (c0 + 594 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-298+c0] + S[-c0+c1-298+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][297+c0] + S[297+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1701; c0 += 1)
    S[c0][c0+298] = MAX(S[c0][c0+298], S[c0+1][c0+298-1] + can_pair(RNA, c0, c0+298));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1700; c0 += 1)
    for (c1 = c0 + 299; c1 <= min(c0 + 597, 1999); c1 += 1) {
      if (c0 + 596 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-299+c0] + S[-c0+c1-299+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][298+c0] + S[298+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1700; c0 += 1)
    S[c0][c0+299] = MAX(S[c0][c0+299], S[c0+1][c0+299-1] + can_pair(RNA, c0, c0+299));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1699; c0 += 1)
    for (c1 = c0 + 300; c1 <= min(c0 + 599, 1999); c1 += 1) {
      if (c0 + 598 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-300+c0] + S[-c0+c1-300+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][299+c0] + S[299+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1699; c0 += 1)
    S[c0][c0+300] = MAX(S[c0][c0+300], S[c0+1][c0+300-1] + can_pair(RNA, c0, c0+300));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1698; c0 += 1)
    for (c1 = c0 + 301; c1 <= min(c0 + 601, 1999); c1 += 1) {
      if (c0 + 600 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-301+c0] + S[-c0+c1-301+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][300+c0] + S[300+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1698; c0 += 1)
    S[c0][c0+301] = MAX(S[c0][c0+301], S[c0+1][c0+301-1] + can_pair(RNA, c0, c0+301));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1697; c0 += 1)
    for (c1 = c0 + 302; c1 <= min(c0 + 603, 1999); c1 += 1) {
      if (c0 + 602 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-302+c0] + S[-c0+c1-302+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][301+c0] + S[301+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1697; c0 += 1)
    S[c0][c0+302] = MAX(S[c0][c0+302], S[c0+1][c0+302-1] + can_pair(RNA, c0, c0+302));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1696; c0 += 1)
    for (c1 = c0 + 303; c1 <= min(c0 + 605, 1999); c1 += 1) {
      if (c0 + 604 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-303+c0] + S[-c0+c1-303+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][302+c0] + S[302+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1696; c0 += 1)
    S[c0][c0+303] = MAX(S[c0][c0+303], S[c0+1][c0+303-1] + can_pair(RNA, c0, c0+303));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1695; c0 += 1)
    for (c1 = c0 + 304; c1 <= min(c0 + 607, 1999); c1 += 1) {
      if (c0 + 606 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-304+c0] + S[-c0+c1-304+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][303+c0] + S[303+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1695; c0 += 1)
    S[c0][c0+304] = MAX(S[c0][c0+304], S[c0+1][c0+304-1] + can_pair(RNA, c0, c0+304));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1694; c0 += 1)
    for (c1 = c0 + 305; c1 <= min(c0 + 609, 1999); c1 += 1) {
      if (c0 + 608 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-305+c0] + S[-c0+c1-305+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][304+c0] + S[304+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1694; c0 += 1)
    S[c0][c0+305] = MAX(S[c0][c0+305], S[c0+1][c0+305-1] + can_pair(RNA, c0, c0+305));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1693; c0 += 1)
    for (c1 = c0 + 306; c1 <= min(c0 + 611, 1999); c1 += 1) {
      if (c0 + 610 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-306+c0] + S[-c0+c1-306+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][305+c0] + S[305+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1693; c0 += 1)
    S[c0][c0+306] = MAX(S[c0][c0+306], S[c0+1][c0+306-1] + can_pair(RNA, c0, c0+306));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1692; c0 += 1)
    for (c1 = c0 + 307; c1 <= min(c0 + 613, 1999); c1 += 1) {
      if (c0 + 612 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-307+c0] + S[-c0+c1-307+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][306+c0] + S[306+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1692; c0 += 1)
    S[c0][c0+307] = MAX(S[c0][c0+307], S[c0+1][c0+307-1] + can_pair(RNA, c0, c0+307));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1691; c0 += 1)
    for (c1 = c0 + 308; c1 <= min(c0 + 615, 1999); c1 += 1) {
      if (c0 + 614 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-308+c0] + S[-c0+c1-308+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][307+c0] + S[307+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1691; c0 += 1)
    S[c0][c0+308] = MAX(S[c0][c0+308], S[c0+1][c0+308-1] + can_pair(RNA, c0, c0+308));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1690; c0 += 1)
    for (c1 = c0 + 309; c1 <= min(c0 + 617, 1999); c1 += 1) {
      if (c0 + 616 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-309+c0] + S[-c0+c1-309+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][308+c0] + S[308+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1690; c0 += 1)
    S[c0][c0+309] = MAX(S[c0][c0+309], S[c0+1][c0+309-1] + can_pair(RNA, c0, c0+309));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1689; c0 += 1)
    for (c1 = c0 + 310; c1 <= min(c0 + 619, 1999); c1 += 1) {
      if (c0 + 618 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-310+c0] + S[-c0+c1-310+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][309+c0] + S[309+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1689; c0 += 1)
    S[c0][c0+310] = MAX(S[c0][c0+310], S[c0+1][c0+310-1] + can_pair(RNA, c0, c0+310));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1688; c0 += 1)
    for (c1 = c0 + 311; c1 <= min(c0 + 621, 1999); c1 += 1) {
      if (c0 + 620 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-311+c0] + S[-c0+c1-311+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][310+c0] + S[310+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1688; c0 += 1)
    S[c0][c0+311] = MAX(S[c0][c0+311], S[c0+1][c0+311-1] + can_pair(RNA, c0, c0+311));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1687; c0 += 1)
    for (c1 = c0 + 312; c1 <= min(c0 + 623, 1999); c1 += 1) {
      if (c0 + 622 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-312+c0] + S[-c0+c1-312+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][311+c0] + S[311+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1687; c0 += 1)
    S[c0][c0+312] = MAX(S[c0][c0+312], S[c0+1][c0+312-1] + can_pair(RNA, c0, c0+312));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1686; c0 += 1)
    for (c1 = c0 + 313; c1 <= min(c0 + 625, 1999); c1 += 1) {
      if (c0 + 624 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-313+c0] + S[-c0+c1-313+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][312+c0] + S[312+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1686; c0 += 1)
    S[c0][c0+313] = MAX(S[c0][c0+313], S[c0+1][c0+313-1] + can_pair(RNA, c0, c0+313));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1685; c0 += 1)
    for (c1 = c0 + 314; c1 <= min(c0 + 627, 1999); c1 += 1) {
      if (c0 + 626 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-314+c0] + S[-c0+c1-314+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][313+c0] + S[313+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1685; c0 += 1)
    S[c0][c0+314] = MAX(S[c0][c0+314], S[c0+1][c0+314-1] + can_pair(RNA, c0, c0+314));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1684; c0 += 1)
    for (c1 = c0 + 315; c1 <= min(c0 + 629, 1999); c1 += 1) {
      if (c0 + 628 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-315+c0] + S[-c0+c1-315+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][314+c0] + S[314+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1684; c0 += 1)
    S[c0][c0+315] = MAX(S[c0][c0+315], S[c0+1][c0+315-1] + can_pair(RNA, c0, c0+315));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1683; c0 += 1)
    for (c1 = c0 + 316; c1 <= min(c0 + 631, 1999); c1 += 1) {
      if (c0 + 630 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-316+c0] + S[-c0+c1-316+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][315+c0] + S[315+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1683; c0 += 1)
    S[c0][c0+316] = MAX(S[c0][c0+316], S[c0+1][c0+316-1] + can_pair(RNA, c0, c0+316));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1682; c0 += 1)
    for (c1 = c0 + 317; c1 <= min(c0 + 633, 1999); c1 += 1) {
      if (c0 + 632 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-317+c0] + S[-c0+c1-317+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][316+c0] + S[316+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1682; c0 += 1)
    S[c0][c0+317] = MAX(S[c0][c0+317], S[c0+1][c0+317-1] + can_pair(RNA, c0, c0+317));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1681; c0 += 1)
    for (c1 = c0 + 318; c1 <= min(c0 + 635, 1999); c1 += 1) {
      if (c0 + 634 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-318+c0] + S[-c0+c1-318+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][317+c0] + S[317+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1681; c0 += 1)
    S[c0][c0+318] = MAX(S[c0][c0+318], S[c0+1][c0+318-1] + can_pair(RNA, c0, c0+318));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1680; c0 += 1)
    for (c1 = c0 + 319; c1 <= min(c0 + 637, 1999); c1 += 1) {
      if (c0 + 636 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-319+c0] + S[-c0+c1-319+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][318+c0] + S[318+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1680; c0 += 1)
    S[c0][c0+319] = MAX(S[c0][c0+319], S[c0+1][c0+319-1] + can_pair(RNA, c0, c0+319));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1679; c0 += 1)
    for (c1 = c0 + 320; c1 <= min(c0 + 639, 1999); c1 += 1) {
      if (c0 + 638 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-320+c0] + S[-c0+c1-320+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][319+c0] + S[319+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1679; c0 += 1)
    S[c0][c0+320] = MAX(S[c0][c0+320], S[c0+1][c0+320-1] + can_pair(RNA, c0, c0+320));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1678; c0 += 1)
    for (c1 = c0 + 321; c1 <= min(c0 + 641, 1999); c1 += 1) {
      if (c0 + 640 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-321+c0] + S[-c0+c1-321+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][320+c0] + S[320+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1678; c0 += 1)
    S[c0][c0+321] = MAX(S[c0][c0+321], S[c0+1][c0+321-1] + can_pair(RNA, c0, c0+321));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1677; c0 += 1)
    for (c1 = c0 + 322; c1 <= min(c0 + 643, 1999); c1 += 1) {
      if (c0 + 642 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-322+c0] + S[-c0+c1-322+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][321+c0] + S[321+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1677; c0 += 1)
    S[c0][c0+322] = MAX(S[c0][c0+322], S[c0+1][c0+322-1] + can_pair(RNA, c0, c0+322));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1676; c0 += 1)
    for (c1 = c0 + 323; c1 <= min(c0 + 645, 1999); c1 += 1) {
      if (c0 + 644 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-323+c0] + S[-c0+c1-323+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][322+c0] + S[322+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1676; c0 += 1)
    S[c0][c0+323] = MAX(S[c0][c0+323], S[c0+1][c0+323-1] + can_pair(RNA, c0, c0+323));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1675; c0 += 1)
    for (c1 = c0 + 324; c1 <= min(c0 + 647, 1999); c1 += 1) {
      if (c0 + 646 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-324+c0] + S[-c0+c1-324+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][323+c0] + S[323+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1675; c0 += 1)
    S[c0][c0+324] = MAX(S[c0][c0+324], S[c0+1][c0+324-1] + can_pair(RNA, c0, c0+324));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1674; c0 += 1)
    for (c1 = c0 + 325; c1 <= min(c0 + 649, 1999); c1 += 1) {
      if (c0 + 648 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-325+c0] + S[-c0+c1-325+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][324+c0] + S[324+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1674; c0 += 1)
    S[c0][c0+325] = MAX(S[c0][c0+325], S[c0+1][c0+325-1] + can_pair(RNA, c0, c0+325));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1673; c0 += 1)
    for (c1 = c0 + 326; c1 <= min(c0 + 651, 1999); c1 += 1) {
      if (c0 + 650 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-326+c0] + S[-c0+c1-326+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][325+c0] + S[325+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1673; c0 += 1)
    S[c0][c0+326] = MAX(S[c0][c0+326], S[c0+1][c0+326-1] + can_pair(RNA, c0, c0+326));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1672; c0 += 1)
    for (c1 = c0 + 327; c1 <= min(c0 + 653, 1999); c1 += 1) {
      if (c0 + 652 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-327+c0] + S[-c0+c1-327+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][326+c0] + S[326+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1672; c0 += 1)
    S[c0][c0+327] = MAX(S[c0][c0+327], S[c0+1][c0+327-1] + can_pair(RNA, c0, c0+327));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1671; c0 += 1)
    for (c1 = c0 + 328; c1 <= min(c0 + 655, 1999); c1 += 1) {
      if (c0 + 654 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-328+c0] + S[-c0+c1-328+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][327+c0] + S[327+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1671; c0 += 1)
    S[c0][c0+328] = MAX(S[c0][c0+328], S[c0+1][c0+328-1] + can_pair(RNA, c0, c0+328));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1670; c0 += 1)
    for (c1 = c0 + 329; c1 <= min(c0 + 657, 1999); c1 += 1) {
      if (c0 + 656 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-329+c0] + S[-c0+c1-329+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][328+c0] + S[328+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1670; c0 += 1)
    S[c0][c0+329] = MAX(S[c0][c0+329], S[c0+1][c0+329-1] + can_pair(RNA, c0, c0+329));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1669; c0 += 1)
    for (c1 = c0 + 330; c1 <= min(c0 + 659, 1999); c1 += 1) {
      if (c0 + 658 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-330+c0] + S[-c0+c1-330+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][329+c0] + S[329+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1669; c0 += 1)
    S[c0][c0+330] = MAX(S[c0][c0+330], S[c0+1][c0+330-1] + can_pair(RNA, c0, c0+330));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1668; c0 += 1)
    for (c1 = c0 + 331; c1 <= min(c0 + 661, 1999); c1 += 1) {
      if (c0 + 660 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-331+c0] + S[-c0+c1-331+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][330+c0] + S[330+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1668; c0 += 1)
    S[c0][c0+331] = MAX(S[c0][c0+331], S[c0+1][c0+331-1] + can_pair(RNA, c0, c0+331));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1667; c0 += 1)
    for (c1 = c0 + 332; c1 <= min(c0 + 663, 1999); c1 += 1) {
      if (c0 + 662 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-332+c0] + S[-c0+c1-332+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][331+c0] + S[331+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1667; c0 += 1)
    S[c0][c0+332] = MAX(S[c0][c0+332], S[c0+1][c0+332-1] + can_pair(RNA, c0, c0+332));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1666; c0 += 1)
    for (c1 = c0 + 333; c1 <= min(c0 + 665, 1999); c1 += 1) {
      if (c0 + 664 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-333+c0] + S[-c0+c1-333+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][332+c0] + S[332+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1666; c0 += 1)
    S[c0][c0+333] = MAX(S[c0][c0+333], S[c0+1][c0+333-1] + can_pair(RNA, c0, c0+333));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1665; c0 += 1)
    for (c1 = c0 + 334; c1 <= min(c0 + 667, 1999); c1 += 1) {
      if (c0 + 666 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-334+c0] + S[-c0+c1-334+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][333+c0] + S[333+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1665; c0 += 1)
    S[c0][c0+334] = MAX(S[c0][c0+334], S[c0+1][c0+334-1] + can_pair(RNA, c0, c0+334));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1664; c0 += 1)
    for (c1 = c0 + 335; c1 <= min(c0 + 669, 1999); c1 += 1) {
      if (c0 + 668 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-335+c0] + S[-c0+c1-335+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][334+c0] + S[334+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1664; c0 += 1)
    S[c0][c0+335] = MAX(S[c0][c0+335], S[c0+1][c0+335-1] + can_pair(RNA, c0, c0+335));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1663; c0 += 1)
    for (c1 = c0 + 336; c1 <= min(c0 + 671, 1999); c1 += 1) {
      if (c0 + 670 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-336+c0] + S[-c0+c1-336+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][335+c0] + S[335+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1663; c0 += 1)
    S[c0][c0+336] = MAX(S[c0][c0+336], S[c0+1][c0+336-1] + can_pair(RNA, c0, c0+336));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1662; c0 += 1)
    for (c1 = c0 + 337; c1 <= min(c0 + 673, 1999); c1 += 1) {
      if (c0 + 672 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-337+c0] + S[-c0+c1-337+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][336+c0] + S[336+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1662; c0 += 1)
    S[c0][c0+337] = MAX(S[c0][c0+337], S[c0+1][c0+337-1] + can_pair(RNA, c0, c0+337));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1661; c0 += 1)
    for (c1 = c0 + 338; c1 <= min(c0 + 675, 1999); c1 += 1) {
      if (c0 + 674 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-338+c0] + S[-c0+c1-338+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][337+c0] + S[337+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1661; c0 += 1)
    S[c0][c0+338] = MAX(S[c0][c0+338], S[c0+1][c0+338-1] + can_pair(RNA, c0, c0+338));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1660; c0 += 1)
    for (c1 = c0 + 339; c1 <= min(c0 + 677, 1999); c1 += 1) {
      if (c0 + 676 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-339+c0] + S[-c0+c1-339+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][338+c0] + S[338+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1660; c0 += 1)
    S[c0][c0+339] = MAX(S[c0][c0+339], S[c0+1][c0+339-1] + can_pair(RNA, c0, c0+339));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1659; c0 += 1)
    for (c1 = c0 + 340; c1 <= min(c0 + 679, 1999); c1 += 1) {
      if (c0 + 678 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-340+c0] + S[-c0+c1-340+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][339+c0] + S[339+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1659; c0 += 1)
    S[c0][c0+340] = MAX(S[c0][c0+340], S[c0+1][c0+340-1] + can_pair(RNA, c0, c0+340));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1658; c0 += 1)
    for (c1 = c0 + 341; c1 <= min(c0 + 681, 1999); c1 += 1) {
      if (c0 + 680 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-341+c0] + S[-c0+c1-341+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][340+c0] + S[340+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1658; c0 += 1)
    S[c0][c0+341] = MAX(S[c0][c0+341], S[c0+1][c0+341-1] + can_pair(RNA, c0, c0+341));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1657; c0 += 1)
    for (c1 = c0 + 342; c1 <= min(c0 + 683, 1999); c1 += 1) {
      if (c0 + 682 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-342+c0] + S[-c0+c1-342+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][341+c0] + S[341+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1657; c0 += 1)
    S[c0][c0+342] = MAX(S[c0][c0+342], S[c0+1][c0+342-1] + can_pair(RNA, c0, c0+342));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1656; c0 += 1)
    for (c1 = c0 + 343; c1 <= min(c0 + 685, 1999); c1 += 1) {
      if (c0 + 684 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-343+c0] + S[-c0+c1-343+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][342+c0] + S[342+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1656; c0 += 1)
    S[c0][c0+343] = MAX(S[c0][c0+343], S[c0+1][c0+343-1] + can_pair(RNA, c0, c0+343));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1655; c0 += 1)
    for (c1 = c0 + 344; c1 <= min(c0 + 687, 1999); c1 += 1) {
      if (c0 + 686 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-344+c0] + S[-c0+c1-344+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][343+c0] + S[343+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1655; c0 += 1)
    S[c0][c0+344] = MAX(S[c0][c0+344], S[c0+1][c0+344-1] + can_pair(RNA, c0, c0+344));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1654; c0 += 1)
    for (c1 = c0 + 345; c1 <= min(c0 + 689, 1999); c1 += 1) {
      if (c0 + 688 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-345+c0] + S[-c0+c1-345+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][344+c0] + S[344+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1654; c0 += 1)
    S[c0][c0+345] = MAX(S[c0][c0+345], S[c0+1][c0+345-1] + can_pair(RNA, c0, c0+345));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1653; c0 += 1)
    for (c1 = c0 + 346; c1 <= min(c0 + 691, 1999); c1 += 1) {
      if (c0 + 690 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-346+c0] + S[-c0+c1-346+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][345+c0] + S[345+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1653; c0 += 1)
    S[c0][c0+346] = MAX(S[c0][c0+346], S[c0+1][c0+346-1] + can_pair(RNA, c0, c0+346));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1652; c0 += 1)
    for (c1 = c0 + 347; c1 <= min(c0 + 693, 1999); c1 += 1) {
      if (c0 + 692 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-347+c0] + S[-c0+c1-347+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][346+c0] + S[346+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1652; c0 += 1)
    S[c0][c0+347] = MAX(S[c0][c0+347], S[c0+1][c0+347-1] + can_pair(RNA, c0, c0+347));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1651; c0 += 1)
    for (c1 = c0 + 348; c1 <= min(c0 + 695, 1999); c1 += 1) {
      if (c0 + 694 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-348+c0] + S[-c0+c1-348+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][347+c0] + S[347+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1651; c0 += 1)
    S[c0][c0+348] = MAX(S[c0][c0+348], S[c0+1][c0+348-1] + can_pair(RNA, c0, c0+348));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1650; c0 += 1)
    for (c1 = c0 + 349; c1 <= min(c0 + 697, 1999); c1 += 1) {
      if (c0 + 696 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-349+c0] + S[-c0+c1-349+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][348+c0] + S[348+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1650; c0 += 1)
    S[c0][c0+349] = MAX(S[c0][c0+349], S[c0+1][c0+349-1] + can_pair(RNA, c0, c0+349));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1649; c0 += 1)
    for (c1 = c0 + 350; c1 <= min(c0 + 699, 1999); c1 += 1) {
      if (c0 + 698 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-350+c0] + S[-c0+c1-350+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][349+c0] + S[349+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1649; c0 += 1)
    S[c0][c0+350] = MAX(S[c0][c0+350], S[c0+1][c0+350-1] + can_pair(RNA, c0, c0+350));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1648; c0 += 1)
    for (c1 = c0 + 351; c1 <= min(c0 + 701, 1999); c1 += 1) {
      if (c0 + 700 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-351+c0] + S[-c0+c1-351+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][350+c0] + S[350+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1648; c0 += 1)
    S[c0][c0+351] = MAX(S[c0][c0+351], S[c0+1][c0+351-1] + can_pair(RNA, c0, c0+351));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1647; c0 += 1)
    for (c1 = c0 + 352; c1 <= min(c0 + 703, 1999); c1 += 1) {
      if (c0 + 702 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-352+c0] + S[-c0+c1-352+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][351+c0] + S[351+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1647; c0 += 1)
    S[c0][c0+352] = MAX(S[c0][c0+352], S[c0+1][c0+352-1] + can_pair(RNA, c0, c0+352));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1646; c0 += 1)
    for (c1 = c0 + 353; c1 <= min(c0 + 705, 1999); c1 += 1) {
      if (c0 + 704 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-353+c0] + S[-c0+c1-353+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][352+c0] + S[352+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1646; c0 += 1)
    S[c0][c0+353] = MAX(S[c0][c0+353], S[c0+1][c0+353-1] + can_pair(RNA, c0, c0+353));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1645; c0 += 1)
    for (c1 = c0 + 354; c1 <= min(c0 + 707, 1999); c1 += 1) {
      if (c0 + 706 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-354+c0] + S[-c0+c1-354+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][353+c0] + S[353+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1645; c0 += 1)
    S[c0][c0+354] = MAX(S[c0][c0+354], S[c0+1][c0+354-1] + can_pair(RNA, c0, c0+354));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1644; c0 += 1)
    for (c1 = c0 + 355; c1 <= min(c0 + 709, 1999); c1 += 1) {
      if (c0 + 708 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-355+c0] + S[-c0+c1-355+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][354+c0] + S[354+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1644; c0 += 1)
    S[c0][c0+355] = MAX(S[c0][c0+355], S[c0+1][c0+355-1] + can_pair(RNA, c0, c0+355));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1643; c0 += 1)
    for (c1 = c0 + 356; c1 <= min(c0 + 711, 1999); c1 += 1) {
      if (c0 + 710 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-356+c0] + S[-c0+c1-356+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][355+c0] + S[355+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1643; c0 += 1)
    S[c0][c0+356] = MAX(S[c0][c0+356], S[c0+1][c0+356-1] + can_pair(RNA, c0, c0+356));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1642; c0 += 1)
    for (c1 = c0 + 357; c1 <= min(c0 + 713, 1999); c1 += 1) {
      if (c0 + 712 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-357+c0] + S[-c0+c1-357+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][356+c0] + S[356+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1642; c0 += 1)
    S[c0][c0+357] = MAX(S[c0][c0+357], S[c0+1][c0+357-1] + can_pair(RNA, c0, c0+357));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1641; c0 += 1)
    for (c1 = c0 + 358; c1 <= min(c0 + 715, 1999); c1 += 1) {
      if (c0 + 714 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-358+c0] + S[-c0+c1-358+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][357+c0] + S[357+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1641; c0 += 1)
    S[c0][c0+358] = MAX(S[c0][c0+358], S[c0+1][c0+358-1] + can_pair(RNA, c0, c0+358));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1640; c0 += 1)
    for (c1 = c0 + 359; c1 <= min(c0 + 717, 1999); c1 += 1) {
      if (c0 + 716 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-359+c0] + S[-c0+c1-359+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][358+c0] + S[358+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1640; c0 += 1)
    S[c0][c0+359] = MAX(S[c0][c0+359], S[c0+1][c0+359-1] + can_pair(RNA, c0, c0+359));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1639; c0 += 1)
    for (c1 = c0 + 360; c1 <= min(c0 + 719, 1999); c1 += 1) {
      if (c0 + 718 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-360+c0] + S[-c0+c1-360+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][359+c0] + S[359+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1639; c0 += 1)
    S[c0][c0+360] = MAX(S[c0][c0+360], S[c0+1][c0+360-1] + can_pair(RNA, c0, c0+360));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1638; c0 += 1)
    for (c1 = c0 + 361; c1 <= min(c0 + 721, 1999); c1 += 1) {
      if (c0 + 720 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-361+c0] + S[-c0+c1-361+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][360+c0] + S[360+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1638; c0 += 1)
    S[c0][c0+361] = MAX(S[c0][c0+361], S[c0+1][c0+361-1] + can_pair(RNA, c0, c0+361));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1637; c0 += 1)
    for (c1 = c0 + 362; c1 <= min(c0 + 723, 1999); c1 += 1) {
      if (c0 + 722 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-362+c0] + S[-c0+c1-362+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][361+c0] + S[361+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1637; c0 += 1)
    S[c0][c0+362] = MAX(S[c0][c0+362], S[c0+1][c0+362-1] + can_pair(RNA, c0, c0+362));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1636; c0 += 1)
    for (c1 = c0 + 363; c1 <= min(c0 + 725, 1999); c1 += 1) {
      if (c0 + 724 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-363+c0] + S[-c0+c1-363+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][362+c0] + S[362+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1636; c0 += 1)
    S[c0][c0+363] = MAX(S[c0][c0+363], S[c0+1][c0+363-1] + can_pair(RNA, c0, c0+363));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1635; c0 += 1)
    for (c1 = c0 + 364; c1 <= min(c0 + 727, 1999); c1 += 1) {
      if (c0 + 726 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-364+c0] + S[-c0+c1-364+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][363+c0] + S[363+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1635; c0 += 1)
    S[c0][c0+364] = MAX(S[c0][c0+364], S[c0+1][c0+364-1] + can_pair(RNA, c0, c0+364));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1634; c0 += 1)
    for (c1 = c0 + 365; c1 <= min(c0 + 729, 1999); c1 += 1) {
      if (c0 + 728 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-365+c0] + S[-c0+c1-365+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][364+c0] + S[364+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1634; c0 += 1)
    S[c0][c0+365] = MAX(S[c0][c0+365], S[c0+1][c0+365-1] + can_pair(RNA, c0, c0+365));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1633; c0 += 1)
    for (c1 = c0 + 366; c1 <= min(c0 + 731, 1999); c1 += 1) {
      if (c0 + 730 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-366+c0] + S[-c0+c1-366+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][365+c0] + S[365+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1633; c0 += 1)
    S[c0][c0+366] = MAX(S[c0][c0+366], S[c0+1][c0+366-1] + can_pair(RNA, c0, c0+366));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1632; c0 += 1)
    for (c1 = c0 + 367; c1 <= min(c0 + 733, 1999); c1 += 1) {
      if (c0 + 732 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-367+c0] + S[-c0+c1-367+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][366+c0] + S[366+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1632; c0 += 1)
    S[c0][c0+367] = MAX(S[c0][c0+367], S[c0+1][c0+367-1] + can_pair(RNA, c0, c0+367));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1631; c0 += 1)
    for (c1 = c0 + 368; c1 <= min(c0 + 735, 1999); c1 += 1) {
      if (c0 + 734 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-368+c0] + S[-c0+c1-368+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][367+c0] + S[367+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1631; c0 += 1)
    S[c0][c0+368] = MAX(S[c0][c0+368], S[c0+1][c0+368-1] + can_pair(RNA, c0, c0+368));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1630; c0 += 1)
    for (c1 = c0 + 369; c1 <= min(c0 + 737, 1999); c1 += 1) {
      if (c0 + 736 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-369+c0] + S[-c0+c1-369+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][368+c0] + S[368+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1630; c0 += 1)
    S[c0][c0+369] = MAX(S[c0][c0+369], S[c0+1][c0+369-1] + can_pair(RNA, c0, c0+369));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1629; c0 += 1)
    for (c1 = c0 + 370; c1 <= min(c0 + 739, 1999); c1 += 1) {
      if (c0 + 738 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-370+c0] + S[-c0+c1-370+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][369+c0] + S[369+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1629; c0 += 1)
    S[c0][c0+370] = MAX(S[c0][c0+370], S[c0+1][c0+370-1] + can_pair(RNA, c0, c0+370));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1628; c0 += 1)
    for (c1 = c0 + 371; c1 <= min(c0 + 741, 1999); c1 += 1) {
      if (c0 + 740 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-371+c0] + S[-c0+c1-371+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][370+c0] + S[370+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1628; c0 += 1)
    S[c0][c0+371] = MAX(S[c0][c0+371], S[c0+1][c0+371-1] + can_pair(RNA, c0, c0+371));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1627; c0 += 1)
    for (c1 = c0 + 372; c1 <= min(c0 + 743, 1999); c1 += 1) {
      if (c0 + 742 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-372+c0] + S[-c0+c1-372+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][371+c0] + S[371+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1627; c0 += 1)
    S[c0][c0+372] = MAX(S[c0][c0+372], S[c0+1][c0+372-1] + can_pair(RNA, c0, c0+372));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1626; c0 += 1)
    for (c1 = c0 + 373; c1 <= min(c0 + 745, 1999); c1 += 1) {
      if (c0 + 744 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-373+c0] + S[-c0+c1-373+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][372+c0] + S[372+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1626; c0 += 1)
    S[c0][c0+373] = MAX(S[c0][c0+373], S[c0+1][c0+373-1] + can_pair(RNA, c0, c0+373));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1625; c0 += 1)
    for (c1 = c0 + 374; c1 <= min(c0 + 747, 1999); c1 += 1) {
      if (c0 + 746 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-374+c0] + S[-c0+c1-374+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][373+c0] + S[373+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1625; c0 += 1)
    S[c0][c0+374] = MAX(S[c0][c0+374], S[c0+1][c0+374-1] + can_pair(RNA, c0, c0+374));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1624; c0 += 1)
    for (c1 = c0 + 375; c1 <= min(c0 + 749, 1999); c1 += 1) {
      if (c0 + 748 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-375+c0] + S[-c0+c1-375+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][374+c0] + S[374+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1624; c0 += 1)
    S[c0][c0+375] = MAX(S[c0][c0+375], S[c0+1][c0+375-1] + can_pair(RNA, c0, c0+375));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1623; c0 += 1)
    for (c1 = c0 + 376; c1 <= min(c0 + 751, 1999); c1 += 1) {
      if (c0 + 750 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-376+c0] + S[-c0+c1-376+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][375+c0] + S[375+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1623; c0 += 1)
    S[c0][c0+376] = MAX(S[c0][c0+376], S[c0+1][c0+376-1] + can_pair(RNA, c0, c0+376));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1622; c0 += 1)
    for (c1 = c0 + 377; c1 <= min(c0 + 753, 1999); c1 += 1) {
      if (c0 + 752 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-377+c0] + S[-c0+c1-377+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][376+c0] + S[376+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1622; c0 += 1)
    S[c0][c0+377] = MAX(S[c0][c0+377], S[c0+1][c0+377-1] + can_pair(RNA, c0, c0+377));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1621; c0 += 1)
    for (c1 = c0 + 378; c1 <= min(c0 + 755, 1999); c1 += 1) {
      if (c0 + 754 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-378+c0] + S[-c0+c1-378+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][377+c0] + S[377+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1621; c0 += 1)
    S[c0][c0+378] = MAX(S[c0][c0+378], S[c0+1][c0+378-1] + can_pair(RNA, c0, c0+378));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1620; c0 += 1)
    for (c1 = c0 + 379; c1 <= min(c0 + 757, 1999); c1 += 1) {
      if (c0 + 756 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-379+c0] + S[-c0+c1-379+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][378+c0] + S[378+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1620; c0 += 1)
    S[c0][c0+379] = MAX(S[c0][c0+379], S[c0+1][c0+379-1] + can_pair(RNA, c0, c0+379));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1619; c0 += 1)
    for (c1 = c0 + 380; c1 <= min(c0 + 759, 1999); c1 += 1) {
      if (c0 + 758 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-380+c0] + S[-c0+c1-380+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][379+c0] + S[379+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1619; c0 += 1)
    S[c0][c0+380] = MAX(S[c0][c0+380], S[c0+1][c0+380-1] + can_pair(RNA, c0, c0+380));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1618; c0 += 1)
    for (c1 = c0 + 381; c1 <= min(c0 + 761, 1999); c1 += 1) {
      if (c0 + 760 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-381+c0] + S[-c0+c1-381+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][380+c0] + S[380+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1618; c0 += 1)
    S[c0][c0+381] = MAX(S[c0][c0+381], S[c0+1][c0+381-1] + can_pair(RNA, c0, c0+381));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1617; c0 += 1)
    for (c1 = c0 + 382; c1 <= min(c0 + 763, 1999); c1 += 1) {
      if (c0 + 762 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-382+c0] + S[-c0+c1-382+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][381+c0] + S[381+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1617; c0 += 1)
    S[c0][c0+382] = MAX(S[c0][c0+382], S[c0+1][c0+382-1] + can_pair(RNA, c0, c0+382));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1616; c0 += 1)
    for (c1 = c0 + 383; c1 <= min(c0 + 765, 1999); c1 += 1) {
      if (c0 + 764 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-383+c0] + S[-c0+c1-383+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][382+c0] + S[382+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1616; c0 += 1)
    S[c0][c0+383] = MAX(S[c0][c0+383], S[c0+1][c0+383-1] + can_pair(RNA, c0, c0+383));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1615; c0 += 1)
    for (c1 = c0 + 384; c1 <= min(c0 + 767, 1999); c1 += 1) {
      if (c0 + 766 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-384+c0] + S[-c0+c1-384+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][383+c0] + S[383+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1615; c0 += 1)
    S[c0][c0+384] = MAX(S[c0][c0+384], S[c0+1][c0+384-1] + can_pair(RNA, c0, c0+384));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1614; c0 += 1)
    for (c1 = c0 + 385; c1 <= min(c0 + 769, 1999); c1 += 1) {
      if (c0 + 768 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-385+c0] + S[-c0+c1-385+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][384+c0] + S[384+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1614; c0 += 1)
    S[c0][c0+385] = MAX(S[c0][c0+385], S[c0+1][c0+385-1] + can_pair(RNA, c0, c0+385));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1613; c0 += 1)
    for (c1 = c0 + 386; c1 <= min(c0 + 771, 1999); c1 += 1) {
      if (c0 + 770 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-386+c0] + S[-c0+c1-386+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][385+c0] + S[385+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1613; c0 += 1)
    S[c0][c0+386] = MAX(S[c0][c0+386], S[c0+1][c0+386-1] + can_pair(RNA, c0, c0+386));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1612; c0 += 1)
    for (c1 = c0 + 387; c1 <= min(c0 + 773, 1999); c1 += 1) {
      if (c0 + 772 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-387+c0] + S[-c0+c1-387+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][386+c0] + S[386+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1612; c0 += 1)
    S[c0][c0+387] = MAX(S[c0][c0+387], S[c0+1][c0+387-1] + can_pair(RNA, c0, c0+387));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1611; c0 += 1)
    for (c1 = c0 + 388; c1 <= min(c0 + 775, 1999); c1 += 1) {
      if (c0 + 774 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-388+c0] + S[-c0+c1-388+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][387+c0] + S[387+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1611; c0 += 1)
    S[c0][c0+388] = MAX(S[c0][c0+388], S[c0+1][c0+388-1] + can_pair(RNA, c0, c0+388));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1610; c0 += 1)
    for (c1 = c0 + 389; c1 <= min(c0 + 777, 1999); c1 += 1) {
      if (c0 + 776 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-389+c0] + S[-c0+c1-389+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][388+c0] + S[388+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1610; c0 += 1)
    S[c0][c0+389] = MAX(S[c0][c0+389], S[c0+1][c0+389-1] + can_pair(RNA, c0, c0+389));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1609; c0 += 1)
    for (c1 = c0 + 390; c1 <= min(c0 + 779, 1999); c1 += 1) {
      if (c0 + 778 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-390+c0] + S[-c0+c1-390+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][389+c0] + S[389+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1609; c0 += 1)
    S[c0][c0+390] = MAX(S[c0][c0+390], S[c0+1][c0+390-1] + can_pair(RNA, c0, c0+390));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1608; c0 += 1)
    for (c1 = c0 + 391; c1 <= min(c0 + 781, 1999); c1 += 1) {
      if (c0 + 780 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-391+c0] + S[-c0+c1-391+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][390+c0] + S[390+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1608; c0 += 1)
    S[c0][c0+391] = MAX(S[c0][c0+391], S[c0+1][c0+391-1] + can_pair(RNA, c0, c0+391));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1607; c0 += 1)
    for (c1 = c0 + 392; c1 <= min(c0 + 783, 1999); c1 += 1) {
      if (c0 + 782 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-392+c0] + S[-c0+c1-392+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][391+c0] + S[391+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1607; c0 += 1)
    S[c0][c0+392] = MAX(S[c0][c0+392], S[c0+1][c0+392-1] + can_pair(RNA, c0, c0+392));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1606; c0 += 1)
    for (c1 = c0 + 393; c1 <= min(c0 + 785, 1999); c1 += 1) {
      if (c0 + 784 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-393+c0] + S[-c0+c1-393+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][392+c0] + S[392+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1606; c0 += 1)
    S[c0][c0+393] = MAX(S[c0][c0+393], S[c0+1][c0+393-1] + can_pair(RNA, c0, c0+393));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1605; c0 += 1)
    for (c1 = c0 + 394; c1 <= min(c0 + 787, 1999); c1 += 1) {
      if (c0 + 786 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-394+c0] + S[-c0+c1-394+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][393+c0] + S[393+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1605; c0 += 1)
    S[c0][c0+394] = MAX(S[c0][c0+394], S[c0+1][c0+394-1] + can_pair(RNA, c0, c0+394));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1604; c0 += 1)
    for (c1 = c0 + 395; c1 <= min(c0 + 789, 1999); c1 += 1) {
      if (c0 + 788 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-395+c0] + S[-c0+c1-395+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][394+c0] + S[394+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1604; c0 += 1)
    S[c0][c0+395] = MAX(S[c0][c0+395], S[c0+1][c0+395-1] + can_pair(RNA, c0, c0+395));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1603; c0 += 1)
    for (c1 = c0 + 396; c1 <= min(c0 + 791, 1999); c1 += 1) {
      if (c0 + 790 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-396+c0] + S[-c0+c1-396+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][395+c0] + S[395+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1603; c0 += 1)
    S[c0][c0+396] = MAX(S[c0][c0+396], S[c0+1][c0+396-1] + can_pair(RNA, c0, c0+396));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1602; c0 += 1)
    for (c1 = c0 + 397; c1 <= min(c0 + 793, 1999); c1 += 1) {
      if (c0 + 792 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-397+c0] + S[-c0+c1-397+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][396+c0] + S[396+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1602; c0 += 1)
    S[c0][c0+397] = MAX(S[c0][c0+397], S[c0+1][c0+397-1] + can_pair(RNA, c0, c0+397));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1601; c0 += 1)
    for (c1 = c0 + 398; c1 <= min(c0 + 795, 1999); c1 += 1) {
      if (c0 + 794 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-398+c0] + S[-c0+c1-398+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][397+c0] + S[397+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1601; c0 += 1)
    S[c0][c0+398] = MAX(S[c0][c0+398], S[c0+1][c0+398-1] + can_pair(RNA, c0, c0+398));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1600; c0 += 1)
    for (c1 = c0 + 399; c1 <= min(c0 + 797, 1999); c1 += 1) {
      if (c0 + 796 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-399+c0] + S[-c0+c1-399+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][398+c0] + S[398+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1600; c0 += 1)
    S[c0][c0+399] = MAX(S[c0][c0+399], S[c0+1][c0+399-1] + can_pair(RNA, c0, c0+399));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1599; c0 += 1)
    for (c1 = c0 + 400; c1 <= min(c0 + 799, 1999); c1 += 1) {
      if (c0 + 798 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-400+c0] + S[-c0+c1-400+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][399+c0] + S[399+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1599; c0 += 1)
    S[c0][c0+400] = MAX(S[c0][c0+400], S[c0+1][c0+400-1] + can_pair(RNA, c0, c0+400));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1598; c0 += 1)
    for (c1 = c0 + 401; c1 <= min(c0 + 801, 1999); c1 += 1) {
      if (c0 + 800 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-401+c0] + S[-c0+c1-401+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][400+c0] + S[400+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1598; c0 += 1)
    S[c0][c0+401] = MAX(S[c0][c0+401], S[c0+1][c0+401-1] + can_pair(RNA, c0, c0+401));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1597; c0 += 1)
    for (c1 = c0 + 402; c1 <= min(c0 + 803, 1999); c1 += 1) {
      if (c0 + 802 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-402+c0] + S[-c0+c1-402+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][401+c0] + S[401+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1597; c0 += 1)
    S[c0][c0+402] = MAX(S[c0][c0+402], S[c0+1][c0+402-1] + can_pair(RNA, c0, c0+402));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1596; c0 += 1)
    for (c1 = c0 + 403; c1 <= min(c0 + 805, 1999); c1 += 1) {
      if (c0 + 804 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-403+c0] + S[-c0+c1-403+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][402+c0] + S[402+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1596; c0 += 1)
    S[c0][c0+403] = MAX(S[c0][c0+403], S[c0+1][c0+403-1] + can_pair(RNA, c0, c0+403));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1595; c0 += 1)
    for (c1 = c0 + 404; c1 <= min(c0 + 807, 1999); c1 += 1) {
      if (c0 + 806 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-404+c0] + S[-c0+c1-404+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][403+c0] + S[403+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1595; c0 += 1)
    S[c0][c0+404] = MAX(S[c0][c0+404], S[c0+1][c0+404-1] + can_pair(RNA, c0, c0+404));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1594; c0 += 1)
    for (c1 = c0 + 405; c1 <= min(c0 + 809, 1999); c1 += 1) {
      if (c0 + 808 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-405+c0] + S[-c0+c1-405+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][404+c0] + S[404+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1594; c0 += 1)
    S[c0][c0+405] = MAX(S[c0][c0+405], S[c0+1][c0+405-1] + can_pair(RNA, c0, c0+405));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1593; c0 += 1)
    for (c1 = c0 + 406; c1 <= min(c0 + 811, 1999); c1 += 1) {
      if (c0 + 810 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-406+c0] + S[-c0+c1-406+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][405+c0] + S[405+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1593; c0 += 1)
    S[c0][c0+406] = MAX(S[c0][c0+406], S[c0+1][c0+406-1] + can_pair(RNA, c0, c0+406));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1592; c0 += 1)
    for (c1 = c0 + 407; c1 <= min(c0 + 813, 1999); c1 += 1) {
      if (c0 + 812 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-407+c0] + S[-c0+c1-407+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][406+c0] + S[406+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1592; c0 += 1)
    S[c0][c0+407] = MAX(S[c0][c0+407], S[c0+1][c0+407-1] + can_pair(RNA, c0, c0+407));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1591; c0 += 1)
    for (c1 = c0 + 408; c1 <= min(c0 + 815, 1999); c1 += 1) {
      if (c0 + 814 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-408+c0] + S[-c0+c1-408+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][407+c0] + S[407+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1591; c0 += 1)
    S[c0][c0+408] = MAX(S[c0][c0+408], S[c0+1][c0+408-1] + can_pair(RNA, c0, c0+408));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1590; c0 += 1)
    for (c1 = c0 + 409; c1 <= min(c0 + 817, 1999); c1 += 1) {
      if (c0 + 816 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-409+c0] + S[-c0+c1-409+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][408+c0] + S[408+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1590; c0 += 1)
    S[c0][c0+409] = MAX(S[c0][c0+409], S[c0+1][c0+409-1] + can_pair(RNA, c0, c0+409));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1589; c0 += 1)
    for (c1 = c0 + 410; c1 <= min(c0 + 819, 1999); c1 += 1) {
      if (c0 + 818 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-410+c0] + S[-c0+c1-410+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][409+c0] + S[409+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1589; c0 += 1)
    S[c0][c0+410] = MAX(S[c0][c0+410], S[c0+1][c0+410-1] + can_pair(RNA, c0, c0+410));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1588; c0 += 1)
    for (c1 = c0 + 411; c1 <= min(c0 + 821, 1999); c1 += 1) {
      if (c0 + 820 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-411+c0] + S[-c0+c1-411+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][410+c0] + S[410+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1588; c0 += 1)
    S[c0][c0+411] = MAX(S[c0][c0+411], S[c0+1][c0+411-1] + can_pair(RNA, c0, c0+411));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1587; c0 += 1)
    for (c1 = c0 + 412; c1 <= min(c0 + 823, 1999); c1 += 1) {
      if (c0 + 822 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-412+c0] + S[-c0+c1-412+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][411+c0] + S[411+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1587; c0 += 1)
    S[c0][c0+412] = MAX(S[c0][c0+412], S[c0+1][c0+412-1] + can_pair(RNA, c0, c0+412));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1586; c0 += 1)
    for (c1 = c0 + 413; c1 <= min(c0 + 825, 1999); c1 += 1) {
      if (c0 + 824 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-413+c0] + S[-c0+c1-413+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][412+c0] + S[412+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1586; c0 += 1)
    S[c0][c0+413] = MAX(S[c0][c0+413], S[c0+1][c0+413-1] + can_pair(RNA, c0, c0+413));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1585; c0 += 1)
    for (c1 = c0 + 414; c1 <= min(c0 + 827, 1999); c1 += 1) {
      if (c0 + 826 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-414+c0] + S[-c0+c1-414+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][413+c0] + S[413+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1585; c0 += 1)
    S[c0][c0+414] = MAX(S[c0][c0+414], S[c0+1][c0+414-1] + can_pair(RNA, c0, c0+414));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1584; c0 += 1)
    for (c1 = c0 + 415; c1 <= min(c0 + 829, 1999); c1 += 1) {
      if (c0 + 828 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-415+c0] + S[-c0+c1-415+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][414+c0] + S[414+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1584; c0 += 1)
    S[c0][c0+415] = MAX(S[c0][c0+415], S[c0+1][c0+415-1] + can_pair(RNA, c0, c0+415));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1583; c0 += 1)
    for (c1 = c0 + 416; c1 <= min(c0 + 831, 1999); c1 += 1) {
      if (c0 + 830 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-416+c0] + S[-c0+c1-416+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][415+c0] + S[415+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1583; c0 += 1)
    S[c0][c0+416] = MAX(S[c0][c0+416], S[c0+1][c0+416-1] + can_pair(RNA, c0, c0+416));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1582; c0 += 1)
    for (c1 = c0 + 417; c1 <= min(c0 + 833, 1999); c1 += 1) {
      if (c0 + 832 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-417+c0] + S[-c0+c1-417+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][416+c0] + S[416+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1582; c0 += 1)
    S[c0][c0+417] = MAX(S[c0][c0+417], S[c0+1][c0+417-1] + can_pair(RNA, c0, c0+417));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1581; c0 += 1)
    for (c1 = c0 + 418; c1 <= min(c0 + 835, 1999); c1 += 1) {
      if (c0 + 834 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-418+c0] + S[-c0+c1-418+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][417+c0] + S[417+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1581; c0 += 1)
    S[c0][c0+418] = MAX(S[c0][c0+418], S[c0+1][c0+418-1] + can_pair(RNA, c0, c0+418));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1580; c0 += 1)
    for (c1 = c0 + 419; c1 <= min(c0 + 837, 1999); c1 += 1) {
      if (c0 + 836 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-419+c0] + S[-c0+c1-419+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][418+c0] + S[418+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1580; c0 += 1)
    S[c0][c0+419] = MAX(S[c0][c0+419], S[c0+1][c0+419-1] + can_pair(RNA, c0, c0+419));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1579; c0 += 1)
    for (c1 = c0 + 420; c1 <= min(c0 + 839, 1999); c1 += 1) {
      if (c0 + 838 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-420+c0] + S[-c0+c1-420+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][419+c0] + S[419+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1579; c0 += 1)
    S[c0][c0+420] = MAX(S[c0][c0+420], S[c0+1][c0+420-1] + can_pair(RNA, c0, c0+420));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1578; c0 += 1)
    for (c1 = c0 + 421; c1 <= min(c0 + 841, 1999); c1 += 1) {
      if (c0 + 840 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-421+c0] + S[-c0+c1-421+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][420+c0] + S[420+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1578; c0 += 1)
    S[c0][c0+421] = MAX(S[c0][c0+421], S[c0+1][c0+421-1] + can_pair(RNA, c0, c0+421));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1577; c0 += 1)
    for (c1 = c0 + 422; c1 <= min(c0 + 843, 1999); c1 += 1) {
      if (c0 + 842 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-422+c0] + S[-c0+c1-422+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][421+c0] + S[421+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1577; c0 += 1)
    S[c0][c0+422] = MAX(S[c0][c0+422], S[c0+1][c0+422-1] + can_pair(RNA, c0, c0+422));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1576; c0 += 1)
    for (c1 = c0 + 423; c1 <= min(c0 + 845, 1999); c1 += 1) {
      if (c0 + 844 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-423+c0] + S[-c0+c1-423+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][422+c0] + S[422+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1576; c0 += 1)
    S[c0][c0+423] = MAX(S[c0][c0+423], S[c0+1][c0+423-1] + can_pair(RNA, c0, c0+423));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1575; c0 += 1)
    for (c1 = c0 + 424; c1 <= min(c0 + 847, 1999); c1 += 1) {
      if (c0 + 846 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-424+c0] + S[-c0+c1-424+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][423+c0] + S[423+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1575; c0 += 1)
    S[c0][c0+424] = MAX(S[c0][c0+424], S[c0+1][c0+424-1] + can_pair(RNA, c0, c0+424));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1574; c0 += 1)
    for (c1 = c0 + 425; c1 <= min(c0 + 849, 1999); c1 += 1) {
      if (c0 + 848 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-425+c0] + S[-c0+c1-425+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][424+c0] + S[424+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1574; c0 += 1)
    S[c0][c0+425] = MAX(S[c0][c0+425], S[c0+1][c0+425-1] + can_pair(RNA, c0, c0+425));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1573; c0 += 1)
    for (c1 = c0 + 426; c1 <= min(c0 + 851, 1999); c1 += 1) {
      if (c0 + 850 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-426+c0] + S[-c0+c1-426+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][425+c0] + S[425+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1573; c0 += 1)
    S[c0][c0+426] = MAX(S[c0][c0+426], S[c0+1][c0+426-1] + can_pair(RNA, c0, c0+426));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1572; c0 += 1)
    for (c1 = c0 + 427; c1 <= min(c0 + 853, 1999); c1 += 1) {
      if (c0 + 852 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-427+c0] + S[-c0+c1-427+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][426+c0] + S[426+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1572; c0 += 1)
    S[c0][c0+427] = MAX(S[c0][c0+427], S[c0+1][c0+427-1] + can_pair(RNA, c0, c0+427));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1571; c0 += 1)
    for (c1 = c0 + 428; c1 <= min(c0 + 855, 1999); c1 += 1) {
      if (c0 + 854 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-428+c0] + S[-c0+c1-428+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][427+c0] + S[427+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1571; c0 += 1)
    S[c0][c0+428] = MAX(S[c0][c0+428], S[c0+1][c0+428-1] + can_pair(RNA, c0, c0+428));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1570; c0 += 1)
    for (c1 = c0 + 429; c1 <= min(c0 + 857, 1999); c1 += 1) {
      if (c0 + 856 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-429+c0] + S[-c0+c1-429+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][428+c0] + S[428+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1570; c0 += 1)
    S[c0][c0+429] = MAX(S[c0][c0+429], S[c0+1][c0+429-1] + can_pair(RNA, c0, c0+429));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1569; c0 += 1)
    for (c1 = c0 + 430; c1 <= min(c0 + 859, 1999); c1 += 1) {
      if (c0 + 858 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-430+c0] + S[-c0+c1-430+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][429+c0] + S[429+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1569; c0 += 1)
    S[c0][c0+430] = MAX(S[c0][c0+430], S[c0+1][c0+430-1] + can_pair(RNA, c0, c0+430));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1568; c0 += 1)
    for (c1 = c0 + 431; c1 <= min(c0 + 861, 1999); c1 += 1) {
      if (c0 + 860 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-431+c0] + S[-c0+c1-431+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][430+c0] + S[430+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1568; c0 += 1)
    S[c0][c0+431] = MAX(S[c0][c0+431], S[c0+1][c0+431-1] + can_pair(RNA, c0, c0+431));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1567; c0 += 1)
    for (c1 = c0 + 432; c1 <= min(c0 + 863, 1999); c1 += 1) {
      if (c0 + 862 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-432+c0] + S[-c0+c1-432+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][431+c0] + S[431+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1567; c0 += 1)
    S[c0][c0+432] = MAX(S[c0][c0+432], S[c0+1][c0+432-1] + can_pair(RNA, c0, c0+432));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1566; c0 += 1)
    for (c1 = c0 + 433; c1 <= min(c0 + 865, 1999); c1 += 1) {
      if (c0 + 864 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-433+c0] + S[-c0+c1-433+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][432+c0] + S[432+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1566; c0 += 1)
    S[c0][c0+433] = MAX(S[c0][c0+433], S[c0+1][c0+433-1] + can_pair(RNA, c0, c0+433));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1565; c0 += 1)
    for (c1 = c0 + 434; c1 <= min(c0 + 867, 1999); c1 += 1) {
      if (c0 + 866 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-434+c0] + S[-c0+c1-434+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][433+c0] + S[433+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1565; c0 += 1)
    S[c0][c0+434] = MAX(S[c0][c0+434], S[c0+1][c0+434-1] + can_pair(RNA, c0, c0+434));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1564; c0 += 1)
    for (c1 = c0 + 435; c1 <= min(c0 + 869, 1999); c1 += 1) {
      if (c0 + 868 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-435+c0] + S[-c0+c1-435+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][434+c0] + S[434+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1564; c0 += 1)
    S[c0][c0+435] = MAX(S[c0][c0+435], S[c0+1][c0+435-1] + can_pair(RNA, c0, c0+435));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1563; c0 += 1)
    for (c1 = c0 + 436; c1 <= min(c0 + 871, 1999); c1 += 1) {
      if (c0 + 870 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-436+c0] + S[-c0+c1-436+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][435+c0] + S[435+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1563; c0 += 1)
    S[c0][c0+436] = MAX(S[c0][c0+436], S[c0+1][c0+436-1] + can_pair(RNA, c0, c0+436));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1562; c0 += 1)
    for (c1 = c0 + 437; c1 <= min(c0 + 873, 1999); c1 += 1) {
      if (c0 + 872 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-437+c0] + S[-c0+c1-437+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][436+c0] + S[436+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1562; c0 += 1)
    S[c0][c0+437] = MAX(S[c0][c0+437], S[c0+1][c0+437-1] + can_pair(RNA, c0, c0+437));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1561; c0 += 1)
    for (c1 = c0 + 438; c1 <= min(c0 + 875, 1999); c1 += 1) {
      if (c0 + 874 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-438+c0] + S[-c0+c1-438+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][437+c0] + S[437+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1561; c0 += 1)
    S[c0][c0+438] = MAX(S[c0][c0+438], S[c0+1][c0+438-1] + can_pair(RNA, c0, c0+438));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1560; c0 += 1)
    for (c1 = c0 + 439; c1 <= min(c0 + 877, 1999); c1 += 1) {
      if (c0 + 876 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-439+c0] + S[-c0+c1-439+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][438+c0] + S[438+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1560; c0 += 1)
    S[c0][c0+439] = MAX(S[c0][c0+439], S[c0+1][c0+439-1] + can_pair(RNA, c0, c0+439));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1559; c0 += 1)
    for (c1 = c0 + 440; c1 <= min(c0 + 879, 1999); c1 += 1) {
      if (c0 + 878 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-440+c0] + S[-c0+c1-440+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][439+c0] + S[439+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1559; c0 += 1)
    S[c0][c0+440] = MAX(S[c0][c0+440], S[c0+1][c0+440-1] + can_pair(RNA, c0, c0+440));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1558; c0 += 1)
    for (c1 = c0 + 441; c1 <= min(c0 + 881, 1999); c1 += 1) {
      if (c0 + 880 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-441+c0] + S[-c0+c1-441+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][440+c0] + S[440+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1558; c0 += 1)
    S[c0][c0+441] = MAX(S[c0][c0+441], S[c0+1][c0+441-1] + can_pair(RNA, c0, c0+441));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1557; c0 += 1)
    for (c1 = c0 + 442; c1 <= min(c0 + 883, 1999); c1 += 1) {
      if (c0 + 882 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-442+c0] + S[-c0+c1-442+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][441+c0] + S[441+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1557; c0 += 1)
    S[c0][c0+442] = MAX(S[c0][c0+442], S[c0+1][c0+442-1] + can_pair(RNA, c0, c0+442));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1556; c0 += 1)
    for (c1 = c0 + 443; c1 <= min(c0 + 885, 1999); c1 += 1) {
      if (c0 + 884 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-443+c0] + S[-c0+c1-443+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][442+c0] + S[442+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1556; c0 += 1)
    S[c0][c0+443] = MAX(S[c0][c0+443], S[c0+1][c0+443-1] + can_pair(RNA, c0, c0+443));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1555; c0 += 1)
    for (c1 = c0 + 444; c1 <= min(c0 + 887, 1999); c1 += 1) {
      if (c0 + 886 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-444+c0] + S[-c0+c1-444+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][443+c0] + S[443+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1555; c0 += 1)
    S[c0][c0+444] = MAX(S[c0][c0+444], S[c0+1][c0+444-1] + can_pair(RNA, c0, c0+444));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1554; c0 += 1)
    for (c1 = c0 + 445; c1 <= min(c0 + 889, 1999); c1 += 1) {
      if (c0 + 888 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-445+c0] + S[-c0+c1-445+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][444+c0] + S[444+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1554; c0 += 1)
    S[c0][c0+445] = MAX(S[c0][c0+445], S[c0+1][c0+445-1] + can_pair(RNA, c0, c0+445));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1553; c0 += 1)
    for (c1 = c0 + 446; c1 <= min(c0 + 891, 1999); c1 += 1) {
      if (c0 + 890 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-446+c0] + S[-c0+c1-446+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][445+c0] + S[445+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1553; c0 += 1)
    S[c0][c0+446] = MAX(S[c0][c0+446], S[c0+1][c0+446-1] + can_pair(RNA, c0, c0+446));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1552; c0 += 1)
    for (c1 = c0 + 447; c1 <= min(c0 + 893, 1999); c1 += 1) {
      if (c0 + 892 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-447+c0] + S[-c0+c1-447+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][446+c0] + S[446+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1552; c0 += 1)
    S[c0][c0+447] = MAX(S[c0][c0+447], S[c0+1][c0+447-1] + can_pair(RNA, c0, c0+447));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1551; c0 += 1)
    for (c1 = c0 + 448; c1 <= min(c0 + 895, 1999); c1 += 1) {
      if (c0 + 894 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-448+c0] + S[-c0+c1-448+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][447+c0] + S[447+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1551; c0 += 1)
    S[c0][c0+448] = MAX(S[c0][c0+448], S[c0+1][c0+448-1] + can_pair(RNA, c0, c0+448));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1550; c0 += 1)
    for (c1 = c0 + 449; c1 <= min(c0 + 897, 1999); c1 += 1) {
      if (c0 + 896 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-449+c0] + S[-c0+c1-449+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][448+c0] + S[448+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1550; c0 += 1)
    S[c0][c0+449] = MAX(S[c0][c0+449], S[c0+1][c0+449-1] + can_pair(RNA, c0, c0+449));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1549; c0 += 1)
    for (c1 = c0 + 450; c1 <= min(c0 + 899, 1999); c1 += 1) {
      if (c0 + 898 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-450+c0] + S[-c0+c1-450+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][449+c0] + S[449+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1549; c0 += 1)
    S[c0][c0+450] = MAX(S[c0][c0+450], S[c0+1][c0+450-1] + can_pair(RNA, c0, c0+450));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1548; c0 += 1)
    for (c1 = c0 + 451; c1 <= min(c0 + 901, 1999); c1 += 1) {
      if (c0 + 900 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-451+c0] + S[-c0+c1-451+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][450+c0] + S[450+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1548; c0 += 1)
    S[c0][c0+451] = MAX(S[c0][c0+451], S[c0+1][c0+451-1] + can_pair(RNA, c0, c0+451));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1547; c0 += 1)
    for (c1 = c0 + 452; c1 <= min(c0 + 903, 1999); c1 += 1) {
      if (c0 + 902 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-452+c0] + S[-c0+c1-452+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][451+c0] + S[451+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1547; c0 += 1)
    S[c0][c0+452] = MAX(S[c0][c0+452], S[c0+1][c0+452-1] + can_pair(RNA, c0, c0+452));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1546; c0 += 1)
    for (c1 = c0 + 453; c1 <= min(c0 + 905, 1999); c1 += 1) {
      if (c0 + 904 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-453+c0] + S[-c0+c1-453+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][452+c0] + S[452+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1546; c0 += 1)
    S[c0][c0+453] = MAX(S[c0][c0+453], S[c0+1][c0+453-1] + can_pair(RNA, c0, c0+453));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1545; c0 += 1)
    for (c1 = c0 + 454; c1 <= min(c0 + 907, 1999); c1 += 1) {
      if (c0 + 906 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-454+c0] + S[-c0+c1-454+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][453+c0] + S[453+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1545; c0 += 1)
    S[c0][c0+454] = MAX(S[c0][c0+454], S[c0+1][c0+454-1] + can_pair(RNA, c0, c0+454));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1544; c0 += 1)
    for (c1 = c0 + 455; c1 <= min(c0 + 909, 1999); c1 += 1) {
      if (c0 + 908 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-455+c0] + S[-c0+c1-455+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][454+c0] + S[454+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1544; c0 += 1)
    S[c0][c0+455] = MAX(S[c0][c0+455], S[c0+1][c0+455-1] + can_pair(RNA, c0, c0+455));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1543; c0 += 1)
    for (c1 = c0 + 456; c1 <= min(c0 + 911, 1999); c1 += 1) {
      if (c0 + 910 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-456+c0] + S[-c0+c1-456+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][455+c0] + S[455+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1543; c0 += 1)
    S[c0][c0+456] = MAX(S[c0][c0+456], S[c0+1][c0+456-1] + can_pair(RNA, c0, c0+456));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1542; c0 += 1)
    for (c1 = c0 + 457; c1 <= min(c0 + 913, 1999); c1 += 1) {
      if (c0 + 912 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-457+c0] + S[-c0+c1-457+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][456+c0] + S[456+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1542; c0 += 1)
    S[c0][c0+457] = MAX(S[c0][c0+457], S[c0+1][c0+457-1] + can_pair(RNA, c0, c0+457));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1541; c0 += 1)
    for (c1 = c0 + 458; c1 <= min(c0 + 915, 1999); c1 += 1) {
      if (c0 + 914 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-458+c0] + S[-c0+c1-458+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][457+c0] + S[457+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1541; c0 += 1)
    S[c0][c0+458] = MAX(S[c0][c0+458], S[c0+1][c0+458-1] + can_pair(RNA, c0, c0+458));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1540; c0 += 1)
    for (c1 = c0 + 459; c1 <= min(c0 + 917, 1999); c1 += 1) {
      if (c0 + 916 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-459+c0] + S[-c0+c1-459+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][458+c0] + S[458+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1540; c0 += 1)
    S[c0][c0+459] = MAX(S[c0][c0+459], S[c0+1][c0+459-1] + can_pair(RNA, c0, c0+459));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1539; c0 += 1)
    for (c1 = c0 + 460; c1 <= min(c0 + 919, 1999); c1 += 1) {
      if (c0 + 918 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-460+c0] + S[-c0+c1-460+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][459+c0] + S[459+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1539; c0 += 1)
    S[c0][c0+460] = MAX(S[c0][c0+460], S[c0+1][c0+460-1] + can_pair(RNA, c0, c0+460));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1538; c0 += 1)
    for (c1 = c0 + 461; c1 <= min(c0 + 921, 1999); c1 += 1) {
      if (c0 + 920 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-461+c0] + S[-c0+c1-461+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][460+c0] + S[460+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1538; c0 += 1)
    S[c0][c0+461] = MAX(S[c0][c0+461], S[c0+1][c0+461-1] + can_pair(RNA, c0, c0+461));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1537; c0 += 1)
    for (c1 = c0 + 462; c1 <= min(c0 + 923, 1999); c1 += 1) {
      if (c0 + 922 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-462+c0] + S[-c0+c1-462+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][461+c0] + S[461+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1537; c0 += 1)
    S[c0][c0+462] = MAX(S[c0][c0+462], S[c0+1][c0+462-1] + can_pair(RNA, c0, c0+462));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1536; c0 += 1)
    for (c1 = c0 + 463; c1 <= min(c0 + 925, 1999); c1 += 1) {
      if (c0 + 924 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-463+c0] + S[-c0+c1-463+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][462+c0] + S[462+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1536; c0 += 1)
    S[c0][c0+463] = MAX(S[c0][c0+463], S[c0+1][c0+463-1] + can_pair(RNA, c0, c0+463));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1535; c0 += 1)
    for (c1 = c0 + 464; c1 <= min(c0 + 927, 1999); c1 += 1) {
      if (c0 + 926 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-464+c0] + S[-c0+c1-464+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][463+c0] + S[463+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1535; c0 += 1)
    S[c0][c0+464] = MAX(S[c0][c0+464], S[c0+1][c0+464-1] + can_pair(RNA, c0, c0+464));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1534; c0 += 1)
    for (c1 = c0 + 465; c1 <= min(c0 + 929, 1999); c1 += 1) {
      if (c0 + 928 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-465+c0] + S[-c0+c1-465+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][464+c0] + S[464+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1534; c0 += 1)
    S[c0][c0+465] = MAX(S[c0][c0+465], S[c0+1][c0+465-1] + can_pair(RNA, c0, c0+465));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1533; c0 += 1)
    for (c1 = c0 + 466; c1 <= min(c0 + 931, 1999); c1 += 1) {
      if (c0 + 930 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-466+c0] + S[-c0+c1-466+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][465+c0] + S[465+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1533; c0 += 1)
    S[c0][c0+466] = MAX(S[c0][c0+466], S[c0+1][c0+466-1] + can_pair(RNA, c0, c0+466));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1532; c0 += 1)
    for (c1 = c0 + 467; c1 <= min(c0 + 933, 1999); c1 += 1) {
      if (c0 + 932 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-467+c0] + S[-c0+c1-467+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][466+c0] + S[466+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1532; c0 += 1)
    S[c0][c0+467] = MAX(S[c0][c0+467], S[c0+1][c0+467-1] + can_pair(RNA, c0, c0+467));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1531; c0 += 1)
    for (c1 = c0 + 468; c1 <= min(c0 + 935, 1999); c1 += 1) {
      if (c0 + 934 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-468+c0] + S[-c0+c1-468+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][467+c0] + S[467+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1531; c0 += 1)
    S[c0][c0+468] = MAX(S[c0][c0+468], S[c0+1][c0+468-1] + can_pair(RNA, c0, c0+468));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1530; c0 += 1)
    for (c1 = c0 + 469; c1 <= min(c0 + 937, 1999); c1 += 1) {
      if (c0 + 936 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-469+c0] + S[-c0+c1-469+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][468+c0] + S[468+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1530; c0 += 1)
    S[c0][c0+469] = MAX(S[c0][c0+469], S[c0+1][c0+469-1] + can_pair(RNA, c0, c0+469));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1529; c0 += 1)
    for (c1 = c0 + 470; c1 <= min(c0 + 939, 1999); c1 += 1) {
      if (c0 + 938 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-470+c0] + S[-c0+c1-470+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][469+c0] + S[469+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1529; c0 += 1)
    S[c0][c0+470] = MAX(S[c0][c0+470], S[c0+1][c0+470-1] + can_pair(RNA, c0, c0+470));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1528; c0 += 1)
    for (c1 = c0 + 471; c1 <= min(c0 + 941, 1999); c1 += 1) {
      if (c0 + 940 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-471+c0] + S[-c0+c1-471+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][470+c0] + S[470+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1528; c0 += 1)
    S[c0][c0+471] = MAX(S[c0][c0+471], S[c0+1][c0+471-1] + can_pair(RNA, c0, c0+471));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1527; c0 += 1)
    for (c1 = c0 + 472; c1 <= min(c0 + 943, 1999); c1 += 1) {
      if (c0 + 942 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-472+c0] + S[-c0+c1-472+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][471+c0] + S[471+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1527; c0 += 1)
    S[c0][c0+472] = MAX(S[c0][c0+472], S[c0+1][c0+472-1] + can_pair(RNA, c0, c0+472));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1526; c0 += 1)
    for (c1 = c0 + 473; c1 <= min(c0 + 945, 1999); c1 += 1) {
      if (c0 + 944 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-473+c0] + S[-c0+c1-473+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][472+c0] + S[472+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1526; c0 += 1)
    S[c0][c0+473] = MAX(S[c0][c0+473], S[c0+1][c0+473-1] + can_pair(RNA, c0, c0+473));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1525; c0 += 1)
    for (c1 = c0 + 474; c1 <= min(c0 + 947, 1999); c1 += 1) {
      if (c0 + 946 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-474+c0] + S[-c0+c1-474+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][473+c0] + S[473+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1525; c0 += 1)
    S[c0][c0+474] = MAX(S[c0][c0+474], S[c0+1][c0+474-1] + can_pair(RNA, c0, c0+474));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1524; c0 += 1)
    for (c1 = c0 + 475; c1 <= min(c0 + 949, 1999); c1 += 1) {
      if (c0 + 948 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-475+c0] + S[-c0+c1-475+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][474+c0] + S[474+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1524; c0 += 1)
    S[c0][c0+475] = MAX(S[c0][c0+475], S[c0+1][c0+475-1] + can_pair(RNA, c0, c0+475));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1523; c0 += 1)
    for (c1 = c0 + 476; c1 <= min(c0 + 951, 1999); c1 += 1) {
      if (c0 + 950 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-476+c0] + S[-c0+c1-476+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][475+c0] + S[475+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1523; c0 += 1)
    S[c0][c0+476] = MAX(S[c0][c0+476], S[c0+1][c0+476-1] + can_pair(RNA, c0, c0+476));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1522; c0 += 1)
    for (c1 = c0 + 477; c1 <= min(c0 + 953, 1999); c1 += 1) {
      if (c0 + 952 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-477+c0] + S[-c0+c1-477+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][476+c0] + S[476+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1522; c0 += 1)
    S[c0][c0+477] = MAX(S[c0][c0+477], S[c0+1][c0+477-1] + can_pair(RNA, c0, c0+477));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1521; c0 += 1)
    for (c1 = c0 + 478; c1 <= min(c0 + 955, 1999); c1 += 1) {
      if (c0 + 954 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-478+c0] + S[-c0+c1-478+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][477+c0] + S[477+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1521; c0 += 1)
    S[c0][c0+478] = MAX(S[c0][c0+478], S[c0+1][c0+478-1] + can_pair(RNA, c0, c0+478));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1520; c0 += 1)
    for (c1 = c0 + 479; c1 <= min(c0 + 957, 1999); c1 += 1) {
      if (c0 + 956 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-479+c0] + S[-c0+c1-479+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][478+c0] + S[478+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1520; c0 += 1)
    S[c0][c0+479] = MAX(S[c0][c0+479], S[c0+1][c0+479-1] + can_pair(RNA, c0, c0+479));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1519; c0 += 1)
    for (c1 = c0 + 480; c1 <= min(c0 + 959, 1999); c1 += 1) {
      if (c0 + 958 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-480+c0] + S[-c0+c1-480+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][479+c0] + S[479+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1519; c0 += 1)
    S[c0][c0+480] = MAX(S[c0][c0+480], S[c0+1][c0+480-1] + can_pair(RNA, c0, c0+480));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1518; c0 += 1)
    for (c1 = c0 + 481; c1 <= min(c0 + 961, 1999); c1 += 1) {
      if (c0 + 960 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-481+c0] + S[-c0+c1-481+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][480+c0] + S[480+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1518; c0 += 1)
    S[c0][c0+481] = MAX(S[c0][c0+481], S[c0+1][c0+481-1] + can_pair(RNA, c0, c0+481));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1517; c0 += 1)
    for (c1 = c0 + 482; c1 <= min(c0 + 963, 1999); c1 += 1) {
      if (c0 + 962 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-482+c0] + S[-c0+c1-482+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][481+c0] + S[481+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1517; c0 += 1)
    S[c0][c0+482] = MAX(S[c0][c0+482], S[c0+1][c0+482-1] + can_pair(RNA, c0, c0+482));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1516; c0 += 1)
    for (c1 = c0 + 483; c1 <= min(c0 + 965, 1999); c1 += 1) {
      if (c0 + 964 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-483+c0] + S[-c0+c1-483+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][482+c0] + S[482+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1516; c0 += 1)
    S[c0][c0+483] = MAX(S[c0][c0+483], S[c0+1][c0+483-1] + can_pair(RNA, c0, c0+483));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1515; c0 += 1)
    for (c1 = c0 + 484; c1 <= min(c0 + 967, 1999); c1 += 1) {
      if (c0 + 966 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-484+c0] + S[-c0+c1-484+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][483+c0] + S[483+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1515; c0 += 1)
    S[c0][c0+484] = MAX(S[c0][c0+484], S[c0+1][c0+484-1] + can_pair(RNA, c0, c0+484));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1514; c0 += 1)
    for (c1 = c0 + 485; c1 <= min(c0 + 969, 1999); c1 += 1) {
      if (c0 + 968 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-485+c0] + S[-c0+c1-485+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][484+c0] + S[484+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1514; c0 += 1)
    S[c0][c0+485] = MAX(S[c0][c0+485], S[c0+1][c0+485-1] + can_pair(RNA, c0, c0+485));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1513; c0 += 1)
    for (c1 = c0 + 486; c1 <= min(c0 + 971, 1999); c1 += 1) {
      if (c0 + 970 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-486+c0] + S[-c0+c1-486+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][485+c0] + S[485+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1513; c0 += 1)
    S[c0][c0+486] = MAX(S[c0][c0+486], S[c0+1][c0+486-1] + can_pair(RNA, c0, c0+486));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1512; c0 += 1)
    for (c1 = c0 + 487; c1 <= min(c0 + 973, 1999); c1 += 1) {
      if (c0 + 972 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-487+c0] + S[-c0+c1-487+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][486+c0] + S[486+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1512; c0 += 1)
    S[c0][c0+487] = MAX(S[c0][c0+487], S[c0+1][c0+487-1] + can_pair(RNA, c0, c0+487));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1511; c0 += 1)
    for (c1 = c0 + 488; c1 <= min(c0 + 975, 1999); c1 += 1) {
      if (c0 + 974 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-488+c0] + S[-c0+c1-488+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][487+c0] + S[487+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1511; c0 += 1)
    S[c0][c0+488] = MAX(S[c0][c0+488], S[c0+1][c0+488-1] + can_pair(RNA, c0, c0+488));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1510; c0 += 1)
    for (c1 = c0 + 489; c1 <= min(c0 + 977, 1999); c1 += 1) {
      if (c0 + 976 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-489+c0] + S[-c0+c1-489+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][488+c0] + S[488+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1510; c0 += 1)
    S[c0][c0+489] = MAX(S[c0][c0+489], S[c0+1][c0+489-1] + can_pair(RNA, c0, c0+489));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1509; c0 += 1)
    for (c1 = c0 + 490; c1 <= min(c0 + 979, 1999); c1 += 1) {
      if (c0 + 978 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-490+c0] + S[-c0+c1-490+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][489+c0] + S[489+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1509; c0 += 1)
    S[c0][c0+490] = MAX(S[c0][c0+490], S[c0+1][c0+490-1] + can_pair(RNA, c0, c0+490));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1508; c0 += 1)
    for (c1 = c0 + 491; c1 <= min(c0 + 981, 1999); c1 += 1) {
      if (c0 + 980 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-491+c0] + S[-c0+c1-491+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][490+c0] + S[490+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1508; c0 += 1)
    S[c0][c0+491] = MAX(S[c0][c0+491], S[c0+1][c0+491-1] + can_pair(RNA, c0, c0+491));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1507; c0 += 1)
    for (c1 = c0 + 492; c1 <= min(c0 + 983, 1999); c1 += 1) {
      if (c0 + 982 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-492+c0] + S[-c0+c1-492+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][491+c0] + S[491+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1507; c0 += 1)
    S[c0][c0+492] = MAX(S[c0][c0+492], S[c0+1][c0+492-1] + can_pair(RNA, c0, c0+492));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1506; c0 += 1)
    for (c1 = c0 + 493; c1 <= min(c0 + 985, 1999); c1 += 1) {
      if (c0 + 984 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-493+c0] + S[-c0+c1-493+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][492+c0] + S[492+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1506; c0 += 1)
    S[c0][c0+493] = MAX(S[c0][c0+493], S[c0+1][c0+493-1] + can_pair(RNA, c0, c0+493));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1505; c0 += 1)
    for (c1 = c0 + 494; c1 <= min(c0 + 987, 1999); c1 += 1) {
      if (c0 + 986 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-494+c0] + S[-c0+c1-494+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][493+c0] + S[493+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1505; c0 += 1)
    S[c0][c0+494] = MAX(S[c0][c0+494], S[c0+1][c0+494-1] + can_pair(RNA, c0, c0+494));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1504; c0 += 1)
    for (c1 = c0 + 495; c1 <= min(c0 + 989, 1999); c1 += 1) {
      if (c0 + 988 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-495+c0] + S[-c0+c1-495+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][494+c0] + S[494+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1504; c0 += 1)
    S[c0][c0+495] = MAX(S[c0][c0+495], S[c0+1][c0+495-1] + can_pair(RNA, c0, c0+495));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1503; c0 += 1)
    for (c1 = c0 + 496; c1 <= min(c0 + 991, 1999); c1 += 1) {
      if (c0 + 990 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-496+c0] + S[-c0+c1-496+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][495+c0] + S[495+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1503; c0 += 1)
    S[c0][c0+496] = MAX(S[c0][c0+496], S[c0+1][c0+496-1] + can_pair(RNA, c0, c0+496));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1502; c0 += 1)
    for (c1 = c0 + 497; c1 <= min(c0 + 993, 1999); c1 += 1) {
      if (c0 + 992 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-497+c0] + S[-c0+c1-497+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][496+c0] + S[496+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1502; c0 += 1)
    S[c0][c0+497] = MAX(S[c0][c0+497], S[c0+1][c0+497-1] + can_pair(RNA, c0, c0+497));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1501; c0 += 1)
    for (c1 = c0 + 498; c1 <= min(c0 + 995, 1999); c1 += 1) {
      if (c0 + 994 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-498+c0] + S[-c0+c1-498+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][497+c0] + S[497+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1501; c0 += 1)
    S[c0][c0+498] = MAX(S[c0][c0+498], S[c0+1][c0+498-1] + can_pair(RNA, c0, c0+498));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1500; c0 += 1)
    for (c1 = c0 + 499; c1 <= min(c0 + 997, 1999); c1 += 1) {
      if (c0 + 996 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-499+c0] + S[-c0+c1-499+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][498+c0] + S[498+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1500; c0 += 1)
    S[c0][c0+499] = MAX(S[c0][c0+499], S[c0+1][c0+499-1] + can_pair(RNA, c0, c0+499));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1499; c0 += 1)
    for (c1 = c0 + 500; c1 <= min(c0 + 999, 1999); c1 += 1) {
      if (c0 + 998 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-500+c0] + S[-c0+c1-500+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][499+c0] + S[499+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1499; c0 += 1)
    S[c0][c0+500] = MAX(S[c0][c0+500], S[c0+1][c0+500-1] + can_pair(RNA, c0, c0+500));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1498; c0 += 1)
    for (c1 = c0 + 501; c1 <= min(c0 + 1001, 1999); c1 += 1) {
      if (c0 + 1000 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-501+c0] + S[-c0+c1-501+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][500+c0] + S[500+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1498; c0 += 1)
    S[c0][c0+501] = MAX(S[c0][c0+501], S[c0+1][c0+501-1] + can_pair(RNA, c0, c0+501));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1497; c0 += 1)
    for (c1 = c0 + 502; c1 <= min(c0 + 1003, 1999); c1 += 1) {
      if (c0 + 1002 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-502+c0] + S[-c0+c1-502+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][501+c0] + S[501+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1497; c0 += 1)
    S[c0][c0+502] = MAX(S[c0][c0+502], S[c0+1][c0+502-1] + can_pair(RNA, c0, c0+502));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1496; c0 += 1)
    for (c1 = c0 + 503; c1 <= min(c0 + 1005, 1999); c1 += 1) {
      if (c0 + 1004 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-503+c0] + S[-c0+c1-503+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][502+c0] + S[502+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1496; c0 += 1)
    S[c0][c0+503] = MAX(S[c0][c0+503], S[c0+1][c0+503-1] + can_pair(RNA, c0, c0+503));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1495; c0 += 1)
    for (c1 = c0 + 504; c1 <= min(c0 + 1007, 1999); c1 += 1) {
      if (c0 + 1006 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-504+c0] + S[-c0+c1-504+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][503+c0] + S[503+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1495; c0 += 1)
    S[c0][c0+504] = MAX(S[c0][c0+504], S[c0+1][c0+504-1] + can_pair(RNA, c0, c0+504));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1494; c0 += 1)
    for (c1 = c0 + 505; c1 <= min(c0 + 1009, 1999); c1 += 1) {
      if (c0 + 1008 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-505+c0] + S[-c0+c1-505+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][504+c0] + S[504+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1494; c0 += 1)
    S[c0][c0+505] = MAX(S[c0][c0+505], S[c0+1][c0+505-1] + can_pair(RNA, c0, c0+505));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1493; c0 += 1)
    for (c1 = c0 + 506; c1 <= min(c0 + 1011, 1999); c1 += 1) {
      if (c0 + 1010 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-506+c0] + S[-c0+c1-506+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][505+c0] + S[505+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1493; c0 += 1)
    S[c0][c0+506] = MAX(S[c0][c0+506], S[c0+1][c0+506-1] + can_pair(RNA, c0, c0+506));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1492; c0 += 1)
    for (c1 = c0 + 507; c1 <= min(c0 + 1013, 1999); c1 += 1) {
      if (c0 + 1012 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-507+c0] + S[-c0+c1-507+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][506+c0] + S[506+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1492; c0 += 1)
    S[c0][c0+507] = MAX(S[c0][c0+507], S[c0+1][c0+507-1] + can_pair(RNA, c0, c0+507));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1491; c0 += 1)
    for (c1 = c0 + 508; c1 <= min(c0 + 1015, 1999); c1 += 1) {
      if (c0 + 1014 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-508+c0] + S[-c0+c1-508+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][507+c0] + S[507+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1491; c0 += 1)
    S[c0][c0+508] = MAX(S[c0][c0+508], S[c0+1][c0+508-1] + can_pair(RNA, c0, c0+508));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1490; c0 += 1)
    for (c1 = c0 + 509; c1 <= min(c0 + 1017, 1999); c1 += 1) {
      if (c0 + 1016 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-509+c0] + S[-c0+c1-509+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][508+c0] + S[508+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1490; c0 += 1)
    S[c0][c0+509] = MAX(S[c0][c0+509], S[c0+1][c0+509-1] + can_pair(RNA, c0, c0+509));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1489; c0 += 1)
    for (c1 = c0 + 510; c1 <= min(c0 + 1019, 1999); c1 += 1) {
      if (c0 + 1018 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-510+c0] + S[-c0+c1-510+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][509+c0] + S[509+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1489; c0 += 1)
    S[c0][c0+510] = MAX(S[c0][c0+510], S[c0+1][c0+510-1] + can_pair(RNA, c0, c0+510));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1488; c0 += 1)
    for (c1 = c0 + 511; c1 <= min(c0 + 1021, 1999); c1 += 1) {
      if (c0 + 1020 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-511+c0] + S[-c0+c1-511+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][510+c0] + S[510+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1488; c0 += 1)
    S[c0][c0+511] = MAX(S[c0][c0+511], S[c0+1][c0+511-1] + can_pair(RNA, c0, c0+511));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1487; c0 += 1)
    for (c1 = c0 + 512; c1 <= min(c0 + 1023, 1999); c1 += 1) {
      if (c0 + 1022 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-512+c0] + S[-c0+c1-512+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][511+c0] + S[511+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1487; c0 += 1)
    S[c0][c0+512] = MAX(S[c0][c0+512], S[c0+1][c0+512-1] + can_pair(RNA, c0, c0+512));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1486; c0 += 1)
    for (c1 = c0 + 513; c1 <= min(c0 + 1025, 1999); c1 += 1) {
      if (c0 + 1024 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-513+c0] + S[-c0+c1-513+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][512+c0] + S[512+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1486; c0 += 1)
    S[c0][c0+513] = MAX(S[c0][c0+513], S[c0+1][c0+513-1] + can_pair(RNA, c0, c0+513));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1485; c0 += 1)
    for (c1 = c0 + 514; c1 <= min(c0 + 1027, 1999); c1 += 1) {
      if (c0 + 1026 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-514+c0] + S[-c0+c1-514+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][513+c0] + S[513+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1485; c0 += 1)
    S[c0][c0+514] = MAX(S[c0][c0+514], S[c0+1][c0+514-1] + can_pair(RNA, c0, c0+514));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1484; c0 += 1)
    for (c1 = c0 + 515; c1 <= min(c0 + 1029, 1999); c1 += 1) {
      if (c0 + 1028 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-515+c0] + S[-c0+c1-515+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][514+c0] + S[514+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1484; c0 += 1)
    S[c0][c0+515] = MAX(S[c0][c0+515], S[c0+1][c0+515-1] + can_pair(RNA, c0, c0+515));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1483; c0 += 1)
    for (c1 = c0 + 516; c1 <= min(c0 + 1031, 1999); c1 += 1) {
      if (c0 + 1030 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-516+c0] + S[-c0+c1-516+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][515+c0] + S[515+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1483; c0 += 1)
    S[c0][c0+516] = MAX(S[c0][c0+516], S[c0+1][c0+516-1] + can_pair(RNA, c0, c0+516));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1482; c0 += 1)
    for (c1 = c0 + 517; c1 <= min(c0 + 1033, 1999); c1 += 1) {
      if (c0 + 1032 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-517+c0] + S[-c0+c1-517+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][516+c0] + S[516+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1482; c0 += 1)
    S[c0][c0+517] = MAX(S[c0][c0+517], S[c0+1][c0+517-1] + can_pair(RNA, c0, c0+517));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1481; c0 += 1)
    for (c1 = c0 + 518; c1 <= min(c0 + 1035, 1999); c1 += 1) {
      if (c0 + 1034 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-518+c0] + S[-c0+c1-518+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][517+c0] + S[517+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1481; c0 += 1)
    S[c0][c0+518] = MAX(S[c0][c0+518], S[c0+1][c0+518-1] + can_pair(RNA, c0, c0+518));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1480; c0 += 1)
    for (c1 = c0 + 519; c1 <= min(c0 + 1037, 1999); c1 += 1) {
      if (c0 + 1036 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-519+c0] + S[-c0+c1-519+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][518+c0] + S[518+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1480; c0 += 1)
    S[c0][c0+519] = MAX(S[c0][c0+519], S[c0+1][c0+519-1] + can_pair(RNA, c0, c0+519));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1479; c0 += 1)
    for (c1 = c0 + 520; c1 <= min(c0 + 1039, 1999); c1 += 1) {
      if (c0 + 1038 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-520+c0] + S[-c0+c1-520+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][519+c0] + S[519+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1479; c0 += 1)
    S[c0][c0+520] = MAX(S[c0][c0+520], S[c0+1][c0+520-1] + can_pair(RNA, c0, c0+520));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1478; c0 += 1)
    for (c1 = c0 + 521; c1 <= min(c0 + 1041, 1999); c1 += 1) {
      if (c0 + 1040 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-521+c0] + S[-c0+c1-521+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][520+c0] + S[520+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1478; c0 += 1)
    S[c0][c0+521] = MAX(S[c0][c0+521], S[c0+1][c0+521-1] + can_pair(RNA, c0, c0+521));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1477; c0 += 1)
    for (c1 = c0 + 522; c1 <= min(c0 + 1043, 1999); c1 += 1) {
      if (c0 + 1042 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-522+c0] + S[-c0+c1-522+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][521+c0] + S[521+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1477; c0 += 1)
    S[c0][c0+522] = MAX(S[c0][c0+522], S[c0+1][c0+522-1] + can_pair(RNA, c0, c0+522));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1476; c0 += 1)
    for (c1 = c0 + 523; c1 <= min(c0 + 1045, 1999); c1 += 1) {
      if (c0 + 1044 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-523+c0] + S[-c0+c1-523+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][522+c0] + S[522+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1476; c0 += 1)
    S[c0][c0+523] = MAX(S[c0][c0+523], S[c0+1][c0+523-1] + can_pair(RNA, c0, c0+523));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1475; c0 += 1)
    for (c1 = c0 + 524; c1 <= min(c0 + 1047, 1999); c1 += 1) {
      if (c0 + 1046 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-524+c0] + S[-c0+c1-524+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][523+c0] + S[523+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1475; c0 += 1)
    S[c0][c0+524] = MAX(S[c0][c0+524], S[c0+1][c0+524-1] + can_pair(RNA, c0, c0+524));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1474; c0 += 1)
    for (c1 = c0 + 525; c1 <= min(c0 + 1049, 1999); c1 += 1) {
      if (c0 + 1048 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-525+c0] + S[-c0+c1-525+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][524+c0] + S[524+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1474; c0 += 1)
    S[c0][c0+525] = MAX(S[c0][c0+525], S[c0+1][c0+525-1] + can_pair(RNA, c0, c0+525));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1473; c0 += 1)
    for (c1 = c0 + 526; c1 <= min(c0 + 1051, 1999); c1 += 1) {
      if (c0 + 1050 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-526+c0] + S[-c0+c1-526+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][525+c0] + S[525+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1473; c0 += 1)
    S[c0][c0+526] = MAX(S[c0][c0+526], S[c0+1][c0+526-1] + can_pair(RNA, c0, c0+526));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1472; c0 += 1)
    for (c1 = c0 + 527; c1 <= min(c0 + 1053, 1999); c1 += 1) {
      if (c0 + 1052 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-527+c0] + S[-c0+c1-527+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][526+c0] + S[526+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1472; c0 += 1)
    S[c0][c0+527] = MAX(S[c0][c0+527], S[c0+1][c0+527-1] + can_pair(RNA, c0, c0+527));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1471; c0 += 1)
    for (c1 = c0 + 528; c1 <= min(c0 + 1055, 1999); c1 += 1) {
      if (c0 + 1054 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-528+c0] + S[-c0+c1-528+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][527+c0] + S[527+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1471; c0 += 1)
    S[c0][c0+528] = MAX(S[c0][c0+528], S[c0+1][c0+528-1] + can_pair(RNA, c0, c0+528));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1470; c0 += 1)
    for (c1 = c0 + 529; c1 <= min(c0 + 1057, 1999); c1 += 1) {
      if (c0 + 1056 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-529+c0] + S[-c0+c1-529+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][528+c0] + S[528+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1470; c0 += 1)
    S[c0][c0+529] = MAX(S[c0][c0+529], S[c0+1][c0+529-1] + can_pair(RNA, c0, c0+529));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1469; c0 += 1)
    for (c1 = c0 + 530; c1 <= min(c0 + 1059, 1999); c1 += 1) {
      if (c0 + 1058 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-530+c0] + S[-c0+c1-530+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][529+c0] + S[529+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1469; c0 += 1)
    S[c0][c0+530] = MAX(S[c0][c0+530], S[c0+1][c0+530-1] + can_pair(RNA, c0, c0+530));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1468; c0 += 1)
    for (c1 = c0 + 531; c1 <= min(c0 + 1061, 1999); c1 += 1) {
      if (c0 + 1060 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-531+c0] + S[-c0+c1-531+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][530+c0] + S[530+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1468; c0 += 1)
    S[c0][c0+531] = MAX(S[c0][c0+531], S[c0+1][c0+531-1] + can_pair(RNA, c0, c0+531));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1467; c0 += 1)
    for (c1 = c0 + 532; c1 <= min(c0 + 1063, 1999); c1 += 1) {
      if (c0 + 1062 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-532+c0] + S[-c0+c1-532+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][531+c0] + S[531+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1467; c0 += 1)
    S[c0][c0+532] = MAX(S[c0][c0+532], S[c0+1][c0+532-1] + can_pair(RNA, c0, c0+532));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1466; c0 += 1)
    for (c1 = c0 + 533; c1 <= min(c0 + 1065, 1999); c1 += 1) {
      if (c0 + 1064 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-533+c0] + S[-c0+c1-533+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][532+c0] + S[532+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1466; c0 += 1)
    S[c0][c0+533] = MAX(S[c0][c0+533], S[c0+1][c0+533-1] + can_pair(RNA, c0, c0+533));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1465; c0 += 1)
    for (c1 = c0 + 534; c1 <= min(c0 + 1067, 1999); c1 += 1) {
      if (c0 + 1066 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-534+c0] + S[-c0+c1-534+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][533+c0] + S[533+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1465; c0 += 1)
    S[c0][c0+534] = MAX(S[c0][c0+534], S[c0+1][c0+534-1] + can_pair(RNA, c0, c0+534));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1464; c0 += 1)
    for (c1 = c0 + 535; c1 <= min(c0 + 1069, 1999); c1 += 1) {
      if (c0 + 1068 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-535+c0] + S[-c0+c1-535+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][534+c0] + S[534+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1464; c0 += 1)
    S[c0][c0+535] = MAX(S[c0][c0+535], S[c0+1][c0+535-1] + can_pair(RNA, c0, c0+535));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1463; c0 += 1)
    for (c1 = c0 + 536; c1 <= min(c0 + 1071, 1999); c1 += 1) {
      if (c0 + 1070 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-536+c0] + S[-c0+c1-536+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][535+c0] + S[535+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1463; c0 += 1)
    S[c0][c0+536] = MAX(S[c0][c0+536], S[c0+1][c0+536-1] + can_pair(RNA, c0, c0+536));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1462; c0 += 1)
    for (c1 = c0 + 537; c1 <= min(c0 + 1073, 1999); c1 += 1) {
      if (c0 + 1072 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-537+c0] + S[-c0+c1-537+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][536+c0] + S[536+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1462; c0 += 1)
    S[c0][c0+537] = MAX(S[c0][c0+537], S[c0+1][c0+537-1] + can_pair(RNA, c0, c0+537));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1461; c0 += 1)
    for (c1 = c0 + 538; c1 <= min(c0 + 1075, 1999); c1 += 1) {
      if (c0 + 1074 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-538+c0] + S[-c0+c1-538+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][537+c0] + S[537+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1461; c0 += 1)
    S[c0][c0+538] = MAX(S[c0][c0+538], S[c0+1][c0+538-1] + can_pair(RNA, c0, c0+538));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1460; c0 += 1)
    for (c1 = c0 + 539; c1 <= min(c0 + 1077, 1999); c1 += 1) {
      if (c0 + 1076 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-539+c0] + S[-c0+c1-539+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][538+c0] + S[538+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1460; c0 += 1)
    S[c0][c0+539] = MAX(S[c0][c0+539], S[c0+1][c0+539-1] + can_pair(RNA, c0, c0+539));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1459; c0 += 1)
    for (c1 = c0 + 540; c1 <= min(c0 + 1079, 1999); c1 += 1) {
      if (c0 + 1078 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-540+c0] + S[-c0+c1-540+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][539+c0] + S[539+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1459; c0 += 1)
    S[c0][c0+540] = MAX(S[c0][c0+540], S[c0+1][c0+540-1] + can_pair(RNA, c0, c0+540));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1458; c0 += 1)
    for (c1 = c0 + 541; c1 <= min(c0 + 1081, 1999); c1 += 1) {
      if (c0 + 1080 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-541+c0] + S[-c0+c1-541+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][540+c0] + S[540+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1458; c0 += 1)
    S[c0][c0+541] = MAX(S[c0][c0+541], S[c0+1][c0+541-1] + can_pair(RNA, c0, c0+541));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1457; c0 += 1)
    for (c1 = c0 + 542; c1 <= min(c0 + 1083, 1999); c1 += 1) {
      if (c0 + 1082 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-542+c0] + S[-c0+c1-542+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][541+c0] + S[541+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1457; c0 += 1)
    S[c0][c0+542] = MAX(S[c0][c0+542], S[c0+1][c0+542-1] + can_pair(RNA, c0, c0+542));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1456; c0 += 1)
    for (c1 = c0 + 543; c1 <= min(c0 + 1085, 1999); c1 += 1) {
      if (c0 + 1084 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-543+c0] + S[-c0+c1-543+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][542+c0] + S[542+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1456; c0 += 1)
    S[c0][c0+543] = MAX(S[c0][c0+543], S[c0+1][c0+543-1] + can_pair(RNA, c0, c0+543));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1455; c0 += 1)
    for (c1 = c0 + 544; c1 <= min(c0 + 1087, 1999); c1 += 1) {
      if (c0 + 1086 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-544+c0] + S[-c0+c1-544+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][543+c0] + S[543+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1455; c0 += 1)
    S[c0][c0+544] = MAX(S[c0][c0+544], S[c0+1][c0+544-1] + can_pair(RNA, c0, c0+544));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1454; c0 += 1)
    for (c1 = c0 + 545; c1 <= min(c0 + 1089, 1999); c1 += 1) {
      if (c0 + 1088 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-545+c0] + S[-c0+c1-545+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][544+c0] + S[544+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1454; c0 += 1)
    S[c0][c0+545] = MAX(S[c0][c0+545], S[c0+1][c0+545-1] + can_pair(RNA, c0, c0+545));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1453; c0 += 1)
    for (c1 = c0 + 546; c1 <= min(c0 + 1091, 1999); c1 += 1) {
      if (c0 + 1090 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-546+c0] + S[-c0+c1-546+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][545+c0] + S[545+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1453; c0 += 1)
    S[c0][c0+546] = MAX(S[c0][c0+546], S[c0+1][c0+546-1] + can_pair(RNA, c0, c0+546));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1452; c0 += 1)
    for (c1 = c0 + 547; c1 <= min(c0 + 1093, 1999); c1 += 1) {
      if (c0 + 1092 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-547+c0] + S[-c0+c1-547+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][546+c0] + S[546+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1452; c0 += 1)
    S[c0][c0+547] = MAX(S[c0][c0+547], S[c0+1][c0+547-1] + can_pair(RNA, c0, c0+547));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1451; c0 += 1)
    for (c1 = c0 + 548; c1 <= min(c0 + 1095, 1999); c1 += 1) {
      if (c0 + 1094 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-548+c0] + S[-c0+c1-548+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][547+c0] + S[547+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1451; c0 += 1)
    S[c0][c0+548] = MAX(S[c0][c0+548], S[c0+1][c0+548-1] + can_pair(RNA, c0, c0+548));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1450; c0 += 1)
    for (c1 = c0 + 549; c1 <= min(c0 + 1097, 1999); c1 += 1) {
      if (c0 + 1096 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-549+c0] + S[-c0+c1-549+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][548+c0] + S[548+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1450; c0 += 1)
    S[c0][c0+549] = MAX(S[c0][c0+549], S[c0+1][c0+549-1] + can_pair(RNA, c0, c0+549));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1449; c0 += 1)
    for (c1 = c0 + 550; c1 <= min(c0 + 1099, 1999); c1 += 1) {
      if (c0 + 1098 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-550+c0] + S[-c0+c1-550+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][549+c0] + S[549+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1449; c0 += 1)
    S[c0][c0+550] = MAX(S[c0][c0+550], S[c0+1][c0+550-1] + can_pair(RNA, c0, c0+550));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1448; c0 += 1)
    for (c1 = c0 + 551; c1 <= min(c0 + 1101, 1999); c1 += 1) {
      if (c0 + 1100 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-551+c0] + S[-c0+c1-551+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][550+c0] + S[550+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1448; c0 += 1)
    S[c0][c0+551] = MAX(S[c0][c0+551], S[c0+1][c0+551-1] + can_pair(RNA, c0, c0+551));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1447; c0 += 1)
    for (c1 = c0 + 552; c1 <= min(c0 + 1103, 1999); c1 += 1) {
      if (c0 + 1102 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-552+c0] + S[-c0+c1-552+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][551+c0] + S[551+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1447; c0 += 1)
    S[c0][c0+552] = MAX(S[c0][c0+552], S[c0+1][c0+552-1] + can_pair(RNA, c0, c0+552));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1446; c0 += 1)
    for (c1 = c0 + 553; c1 <= min(c0 + 1105, 1999); c1 += 1) {
      if (c0 + 1104 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-553+c0] + S[-c0+c1-553+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][552+c0] + S[552+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1446; c0 += 1)
    S[c0][c0+553] = MAX(S[c0][c0+553], S[c0+1][c0+553-1] + can_pair(RNA, c0, c0+553));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1445; c0 += 1)
    for (c1 = c0 + 554; c1 <= min(c0 + 1107, 1999); c1 += 1) {
      if (c0 + 1106 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-554+c0] + S[-c0+c1-554+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][553+c0] + S[553+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1445; c0 += 1)
    S[c0][c0+554] = MAX(S[c0][c0+554], S[c0+1][c0+554-1] + can_pair(RNA, c0, c0+554));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1444; c0 += 1)
    for (c1 = c0 + 555; c1 <= min(c0 + 1109, 1999); c1 += 1) {
      if (c0 + 1108 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-555+c0] + S[-c0+c1-555+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][554+c0] + S[554+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1444; c0 += 1)
    S[c0][c0+555] = MAX(S[c0][c0+555], S[c0+1][c0+555-1] + can_pair(RNA, c0, c0+555));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1443; c0 += 1)
    for (c1 = c0 + 556; c1 <= min(c0 + 1111, 1999); c1 += 1) {
      if (c0 + 1110 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-556+c0] + S[-c0+c1-556+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][555+c0] + S[555+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1443; c0 += 1)
    S[c0][c0+556] = MAX(S[c0][c0+556], S[c0+1][c0+556-1] + can_pair(RNA, c0, c0+556));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1442; c0 += 1)
    for (c1 = c0 + 557; c1 <= min(c0 + 1113, 1999); c1 += 1) {
      if (c0 + 1112 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-557+c0] + S[-c0+c1-557+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][556+c0] + S[556+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1442; c0 += 1)
    S[c0][c0+557] = MAX(S[c0][c0+557], S[c0+1][c0+557-1] + can_pair(RNA, c0, c0+557));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1441; c0 += 1)
    for (c1 = c0 + 558; c1 <= min(c0 + 1115, 1999); c1 += 1) {
      if (c0 + 1114 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-558+c0] + S[-c0+c1-558+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][557+c0] + S[557+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1441; c0 += 1)
    S[c0][c0+558] = MAX(S[c0][c0+558], S[c0+1][c0+558-1] + can_pair(RNA, c0, c0+558));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1440; c0 += 1)
    for (c1 = c0 + 559; c1 <= min(c0 + 1117, 1999); c1 += 1) {
      if (c0 + 1116 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-559+c0] + S[-c0+c1-559+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][558+c0] + S[558+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1440; c0 += 1)
    S[c0][c0+559] = MAX(S[c0][c0+559], S[c0+1][c0+559-1] + can_pair(RNA, c0, c0+559));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1439; c0 += 1)
    for (c1 = c0 + 560; c1 <= min(c0 + 1119, 1999); c1 += 1) {
      if (c0 + 1118 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-560+c0] + S[-c0+c1-560+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][559+c0] + S[559+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1439; c0 += 1)
    S[c0][c0+560] = MAX(S[c0][c0+560], S[c0+1][c0+560-1] + can_pair(RNA, c0, c0+560));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1438; c0 += 1)
    for (c1 = c0 + 561; c1 <= min(c0 + 1121, 1999); c1 += 1) {
      if (c0 + 1120 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-561+c0] + S[-c0+c1-561+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][560+c0] + S[560+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1438; c0 += 1)
    S[c0][c0+561] = MAX(S[c0][c0+561], S[c0+1][c0+561-1] + can_pair(RNA, c0, c0+561));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1437; c0 += 1)
    for (c1 = c0 + 562; c1 <= min(c0 + 1123, 1999); c1 += 1) {
      if (c0 + 1122 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-562+c0] + S[-c0+c1-562+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][561+c0] + S[561+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1437; c0 += 1)
    S[c0][c0+562] = MAX(S[c0][c0+562], S[c0+1][c0+562-1] + can_pair(RNA, c0, c0+562));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1436; c0 += 1)
    for (c1 = c0 + 563; c1 <= min(c0 + 1125, 1999); c1 += 1) {
      if (c0 + 1124 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-563+c0] + S[-c0+c1-563+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][562+c0] + S[562+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1436; c0 += 1)
    S[c0][c0+563] = MAX(S[c0][c0+563], S[c0+1][c0+563-1] + can_pair(RNA, c0, c0+563));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1435; c0 += 1)
    for (c1 = c0 + 564; c1 <= min(c0 + 1127, 1999); c1 += 1) {
      if (c0 + 1126 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-564+c0] + S[-c0+c1-564+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][563+c0] + S[563+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1435; c0 += 1)
    S[c0][c0+564] = MAX(S[c0][c0+564], S[c0+1][c0+564-1] + can_pair(RNA, c0, c0+564));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1434; c0 += 1)
    for (c1 = c0 + 565; c1 <= min(c0 + 1129, 1999); c1 += 1) {
      if (c0 + 1128 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-565+c0] + S[-c0+c1-565+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][564+c0] + S[564+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1434; c0 += 1)
    S[c0][c0+565] = MAX(S[c0][c0+565], S[c0+1][c0+565-1] + can_pair(RNA, c0, c0+565));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1433; c0 += 1)
    for (c1 = c0 + 566; c1 <= min(c0 + 1131, 1999); c1 += 1) {
      if (c0 + 1130 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-566+c0] + S[-c0+c1-566+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][565+c0] + S[565+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1433; c0 += 1)
    S[c0][c0+566] = MAX(S[c0][c0+566], S[c0+1][c0+566-1] + can_pair(RNA, c0, c0+566));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1432; c0 += 1)
    for (c1 = c0 + 567; c1 <= min(c0 + 1133, 1999); c1 += 1) {
      if (c0 + 1132 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-567+c0] + S[-c0+c1-567+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][566+c0] + S[566+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1432; c0 += 1)
    S[c0][c0+567] = MAX(S[c0][c0+567], S[c0+1][c0+567-1] + can_pair(RNA, c0, c0+567));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1431; c0 += 1)
    for (c1 = c0 + 568; c1 <= min(c0 + 1135, 1999); c1 += 1) {
      if (c0 + 1134 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-568+c0] + S[-c0+c1-568+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][567+c0] + S[567+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1431; c0 += 1)
    S[c0][c0+568] = MAX(S[c0][c0+568], S[c0+1][c0+568-1] + can_pair(RNA, c0, c0+568));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1430; c0 += 1)
    for (c1 = c0 + 569; c1 <= min(c0 + 1137, 1999); c1 += 1) {
      if (c0 + 1136 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-569+c0] + S[-c0+c1-569+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][568+c0] + S[568+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1430; c0 += 1)
    S[c0][c0+569] = MAX(S[c0][c0+569], S[c0+1][c0+569-1] + can_pair(RNA, c0, c0+569));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1429; c0 += 1)
    for (c1 = c0 + 570; c1 <= min(c0 + 1139, 1999); c1 += 1) {
      if (c0 + 1138 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-570+c0] + S[-c0+c1-570+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][569+c0] + S[569+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1429; c0 += 1)
    S[c0][c0+570] = MAX(S[c0][c0+570], S[c0+1][c0+570-1] + can_pair(RNA, c0, c0+570));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1428; c0 += 1)
    for (c1 = c0 + 571; c1 <= min(c0 + 1141, 1999); c1 += 1) {
      if (c0 + 1140 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-571+c0] + S[-c0+c1-571+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][570+c0] + S[570+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1428; c0 += 1)
    S[c0][c0+571] = MAX(S[c0][c0+571], S[c0+1][c0+571-1] + can_pair(RNA, c0, c0+571));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1427; c0 += 1)
    for (c1 = c0 + 572; c1 <= min(c0 + 1143, 1999); c1 += 1) {
      if (c0 + 1142 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-572+c0] + S[-c0+c1-572+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][571+c0] + S[571+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1427; c0 += 1)
    S[c0][c0+572] = MAX(S[c0][c0+572], S[c0+1][c0+572-1] + can_pair(RNA, c0, c0+572));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1426; c0 += 1)
    for (c1 = c0 + 573; c1 <= min(c0 + 1145, 1999); c1 += 1) {
      if (c0 + 1144 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-573+c0] + S[-c0+c1-573+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][572+c0] + S[572+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1426; c0 += 1)
    S[c0][c0+573] = MAX(S[c0][c0+573], S[c0+1][c0+573-1] + can_pair(RNA, c0, c0+573));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1425; c0 += 1)
    for (c1 = c0 + 574; c1 <= min(c0 + 1147, 1999); c1 += 1) {
      if (c0 + 1146 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-574+c0] + S[-c0+c1-574+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][573+c0] + S[573+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1425; c0 += 1)
    S[c0][c0+574] = MAX(S[c0][c0+574], S[c0+1][c0+574-1] + can_pair(RNA, c0, c0+574));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1424; c0 += 1)
    for (c1 = c0 + 575; c1 <= min(c0 + 1149, 1999); c1 += 1) {
      if (c0 + 1148 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-575+c0] + S[-c0+c1-575+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][574+c0] + S[574+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1424; c0 += 1)
    S[c0][c0+575] = MAX(S[c0][c0+575], S[c0+1][c0+575-1] + can_pair(RNA, c0, c0+575));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1423; c0 += 1)
    for (c1 = c0 + 576; c1 <= min(c0 + 1151, 1999); c1 += 1) {
      if (c0 + 1150 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-576+c0] + S[-c0+c1-576+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][575+c0] + S[575+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1423; c0 += 1)
    S[c0][c0+576] = MAX(S[c0][c0+576], S[c0+1][c0+576-1] + can_pair(RNA, c0, c0+576));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1422; c0 += 1)
    for (c1 = c0 + 577; c1 <= min(c0 + 1153, 1999); c1 += 1) {
      if (c0 + 1152 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-577+c0] + S[-c0+c1-577+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][576+c0] + S[576+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1422; c0 += 1)
    S[c0][c0+577] = MAX(S[c0][c0+577], S[c0+1][c0+577-1] + can_pair(RNA, c0, c0+577));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1421; c0 += 1)
    for (c1 = c0 + 578; c1 <= min(c0 + 1155, 1999); c1 += 1) {
      if (c0 + 1154 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-578+c0] + S[-c0+c1-578+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][577+c0] + S[577+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1421; c0 += 1)
    S[c0][c0+578] = MAX(S[c0][c0+578], S[c0+1][c0+578-1] + can_pair(RNA, c0, c0+578));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1420; c0 += 1)
    for (c1 = c0 + 579; c1 <= min(c0 + 1157, 1999); c1 += 1) {
      if (c0 + 1156 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-579+c0] + S[-c0+c1-579+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][578+c0] + S[578+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1420; c0 += 1)
    S[c0][c0+579] = MAX(S[c0][c0+579], S[c0+1][c0+579-1] + can_pair(RNA, c0, c0+579));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1419; c0 += 1)
    for (c1 = c0 + 580; c1 <= min(c0 + 1159, 1999); c1 += 1) {
      if (c0 + 1158 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-580+c0] + S[-c0+c1-580+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][579+c0] + S[579+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1419; c0 += 1)
    S[c0][c0+580] = MAX(S[c0][c0+580], S[c0+1][c0+580-1] + can_pair(RNA, c0, c0+580));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1418; c0 += 1)
    for (c1 = c0 + 581; c1 <= min(c0 + 1161, 1999); c1 += 1) {
      if (c0 + 1160 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-581+c0] + S[-c0+c1-581+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][580+c0] + S[580+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1418; c0 += 1)
    S[c0][c0+581] = MAX(S[c0][c0+581], S[c0+1][c0+581-1] + can_pair(RNA, c0, c0+581));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1417; c0 += 1)
    for (c1 = c0 + 582; c1 <= min(c0 + 1163, 1999); c1 += 1) {
      if (c0 + 1162 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-582+c0] + S[-c0+c1-582+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][581+c0] + S[581+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1417; c0 += 1)
    S[c0][c0+582] = MAX(S[c0][c0+582], S[c0+1][c0+582-1] + can_pair(RNA, c0, c0+582));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1416; c0 += 1)
    for (c1 = c0 + 583; c1 <= min(c0 + 1165, 1999); c1 += 1) {
      if (c0 + 1164 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-583+c0] + S[-c0+c1-583+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][582+c0] + S[582+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1416; c0 += 1)
    S[c0][c0+583] = MAX(S[c0][c0+583], S[c0+1][c0+583-1] + can_pair(RNA, c0, c0+583));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1415; c0 += 1)
    for (c1 = c0 + 584; c1 <= min(c0 + 1167, 1999); c1 += 1) {
      if (c0 + 1166 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-584+c0] + S[-c0+c1-584+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][583+c0] + S[583+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1415; c0 += 1)
    S[c0][c0+584] = MAX(S[c0][c0+584], S[c0+1][c0+584-1] + can_pair(RNA, c0, c0+584));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1414; c0 += 1)
    for (c1 = c0 + 585; c1 <= min(c0 + 1169, 1999); c1 += 1) {
      if (c0 + 1168 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-585+c0] + S[-c0+c1-585+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][584+c0] + S[584+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1414; c0 += 1)
    S[c0][c0+585] = MAX(S[c0][c0+585], S[c0+1][c0+585-1] + can_pair(RNA, c0, c0+585));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1413; c0 += 1)
    for (c1 = c0 + 586; c1 <= min(c0 + 1171, 1999); c1 += 1) {
      if (c0 + 1170 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-586+c0] + S[-c0+c1-586+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][585+c0] + S[585+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1413; c0 += 1)
    S[c0][c0+586] = MAX(S[c0][c0+586], S[c0+1][c0+586-1] + can_pair(RNA, c0, c0+586));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1412; c0 += 1)
    for (c1 = c0 + 587; c1 <= min(c0 + 1173, 1999); c1 += 1) {
      if (c0 + 1172 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-587+c0] + S[-c0+c1-587+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][586+c0] + S[586+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1412; c0 += 1)
    S[c0][c0+587] = MAX(S[c0][c0+587], S[c0+1][c0+587-1] + can_pair(RNA, c0, c0+587));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1411; c0 += 1)
    for (c1 = c0 + 588; c1 <= min(c0 + 1175, 1999); c1 += 1) {
      if (c0 + 1174 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-588+c0] + S[-c0+c1-588+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][587+c0] + S[587+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1411; c0 += 1)
    S[c0][c0+588] = MAX(S[c0][c0+588], S[c0+1][c0+588-1] + can_pair(RNA, c0, c0+588));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1410; c0 += 1)
    for (c1 = c0 + 589; c1 <= min(c0 + 1177, 1999); c1 += 1) {
      if (c0 + 1176 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-589+c0] + S[-c0+c1-589+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][588+c0] + S[588+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1410; c0 += 1)
    S[c0][c0+589] = MAX(S[c0][c0+589], S[c0+1][c0+589-1] + can_pair(RNA, c0, c0+589));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1409; c0 += 1)
    for (c1 = c0 + 590; c1 <= min(c0 + 1179, 1999); c1 += 1) {
      if (c0 + 1178 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-590+c0] + S[-c0+c1-590+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][589+c0] + S[589+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1409; c0 += 1)
    S[c0][c0+590] = MAX(S[c0][c0+590], S[c0+1][c0+590-1] + can_pair(RNA, c0, c0+590));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1408; c0 += 1)
    for (c1 = c0 + 591; c1 <= min(c0 + 1181, 1999); c1 += 1) {
      if (c0 + 1180 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-591+c0] + S[-c0+c1-591+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][590+c0] + S[590+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1408; c0 += 1)
    S[c0][c0+591] = MAX(S[c0][c0+591], S[c0+1][c0+591-1] + can_pair(RNA, c0, c0+591));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1407; c0 += 1)
    for (c1 = c0 + 592; c1 <= min(c0 + 1183, 1999); c1 += 1) {
      if (c0 + 1182 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-592+c0] + S[-c0+c1-592+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][591+c0] + S[591+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1407; c0 += 1)
    S[c0][c0+592] = MAX(S[c0][c0+592], S[c0+1][c0+592-1] + can_pair(RNA, c0, c0+592));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1406; c0 += 1)
    for (c1 = c0 + 593; c1 <= min(c0 + 1185, 1999); c1 += 1) {
      if (c0 + 1184 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-593+c0] + S[-c0+c1-593+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][592+c0] + S[592+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1406; c0 += 1)
    S[c0][c0+593] = MAX(S[c0][c0+593], S[c0+1][c0+593-1] + can_pair(RNA, c0, c0+593));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1405; c0 += 1)
    for (c1 = c0 + 594; c1 <= min(c0 + 1187, 1999); c1 += 1) {
      if (c0 + 1186 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-594+c0] + S[-c0+c1-594+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][593+c0] + S[593+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1405; c0 += 1)
    S[c0][c0+594] = MAX(S[c0][c0+594], S[c0+1][c0+594-1] + can_pair(RNA, c0, c0+594));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1404; c0 += 1)
    for (c1 = c0 + 595; c1 <= min(c0 + 1189, 1999); c1 += 1) {
      if (c0 + 1188 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-595+c0] + S[-c0+c1-595+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][594+c0] + S[594+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1404; c0 += 1)
    S[c0][c0+595] = MAX(S[c0][c0+595], S[c0+1][c0+595-1] + can_pair(RNA, c0, c0+595));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1403; c0 += 1)
    for (c1 = c0 + 596; c1 <= min(c0 + 1191, 1999); c1 += 1) {
      if (c0 + 1190 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-596+c0] + S[-c0+c1-596+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][595+c0] + S[595+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1403; c0 += 1)
    S[c0][c0+596] = MAX(S[c0][c0+596], S[c0+1][c0+596-1] + can_pair(RNA, c0, c0+596));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1402; c0 += 1)
    for (c1 = c0 + 597; c1 <= min(c0 + 1193, 1999); c1 += 1) {
      if (c0 + 1192 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-597+c0] + S[-c0+c1-597+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][596+c0] + S[596+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1402; c0 += 1)
    S[c0][c0+597] = MAX(S[c0][c0+597], S[c0+1][c0+597-1] + can_pair(RNA, c0, c0+597));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1401; c0 += 1)
    for (c1 = c0 + 598; c1 <= min(c0 + 1195, 1999); c1 += 1) {
      if (c0 + 1194 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-598+c0] + S[-c0+c1-598+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][597+c0] + S[597+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1401; c0 += 1)
    S[c0][c0+598] = MAX(S[c0][c0+598], S[c0+1][c0+598-1] + can_pair(RNA, c0, c0+598));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1400; c0 += 1)
    for (c1 = c0 + 599; c1 <= min(c0 + 1197, 1999); c1 += 1) {
      if (c0 + 1196 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-599+c0] + S[-c0+c1-599+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][598+c0] + S[598+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1400; c0 += 1)
    S[c0][c0+599] = MAX(S[c0][c0+599], S[c0+1][c0+599-1] + can_pair(RNA, c0, c0+599));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1399; c0 += 1)
    for (c1 = c0 + 600; c1 <= min(c0 + 1199, 1999); c1 += 1) {
      if (c0 + 1198 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-600+c0] + S[-c0+c1-600+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][599+c0] + S[599+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1399; c0 += 1)
    S[c0][c0+600] = MAX(S[c0][c0+600], S[c0+1][c0+600-1] + can_pair(RNA, c0, c0+600));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1398; c0 += 1)
    for (c1 = c0 + 601; c1 <= min(c0 + 1201, 1999); c1 += 1) {
      if (c0 + 1200 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-601+c0] + S[-c0+c1-601+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][600+c0] + S[600+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1398; c0 += 1)
    S[c0][c0+601] = MAX(S[c0][c0+601], S[c0+1][c0+601-1] + can_pair(RNA, c0, c0+601));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1397; c0 += 1)
    for (c1 = c0 + 602; c1 <= min(c0 + 1203, 1999); c1 += 1) {
      if (c0 + 1202 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-602+c0] + S[-c0+c1-602+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][601+c0] + S[601+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1397; c0 += 1)
    S[c0][c0+602] = MAX(S[c0][c0+602], S[c0+1][c0+602-1] + can_pair(RNA, c0, c0+602));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1396; c0 += 1)
    for (c1 = c0 + 603; c1 <= min(c0 + 1205, 1999); c1 += 1) {
      if (c0 + 1204 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-603+c0] + S[-c0+c1-603+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][602+c0] + S[602+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1396; c0 += 1)
    S[c0][c0+603] = MAX(S[c0][c0+603], S[c0+1][c0+603-1] + can_pair(RNA, c0, c0+603));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1395; c0 += 1)
    for (c1 = c0 + 604; c1 <= min(c0 + 1207, 1999); c1 += 1) {
      if (c0 + 1206 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-604+c0] + S[-c0+c1-604+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][603+c0] + S[603+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1395; c0 += 1)
    S[c0][c0+604] = MAX(S[c0][c0+604], S[c0+1][c0+604-1] + can_pair(RNA, c0, c0+604));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1394; c0 += 1)
    for (c1 = c0 + 605; c1 <= min(c0 + 1209, 1999); c1 += 1) {
      if (c0 + 1208 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-605+c0] + S[-c0+c1-605+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][604+c0] + S[604+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1394; c0 += 1)
    S[c0][c0+605] = MAX(S[c0][c0+605], S[c0+1][c0+605-1] + can_pair(RNA, c0, c0+605));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1393; c0 += 1)
    for (c1 = c0 + 606; c1 <= min(c0 + 1211, 1999); c1 += 1) {
      if (c0 + 1210 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-606+c0] + S[-c0+c1-606+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][605+c0] + S[605+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1393; c0 += 1)
    S[c0][c0+606] = MAX(S[c0][c0+606], S[c0+1][c0+606-1] + can_pair(RNA, c0, c0+606));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1392; c0 += 1)
    for (c1 = c0 + 607; c1 <= min(c0 + 1213, 1999); c1 += 1) {
      if (c0 + 1212 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-607+c0] + S[-c0+c1-607+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][606+c0] + S[606+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1392; c0 += 1)
    S[c0][c0+607] = MAX(S[c0][c0+607], S[c0+1][c0+607-1] + can_pair(RNA, c0, c0+607));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1391; c0 += 1)
    for (c1 = c0 + 608; c1 <= min(c0 + 1215, 1999); c1 += 1) {
      if (c0 + 1214 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-608+c0] + S[-c0+c1-608+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][607+c0] + S[607+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1391; c0 += 1)
    S[c0][c0+608] = MAX(S[c0][c0+608], S[c0+1][c0+608-1] + can_pair(RNA, c0, c0+608));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1390; c0 += 1)
    for (c1 = c0 + 609; c1 <= min(c0 + 1217, 1999); c1 += 1) {
      if (c0 + 1216 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-609+c0] + S[-c0+c1-609+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][608+c0] + S[608+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1390; c0 += 1)
    S[c0][c0+609] = MAX(S[c0][c0+609], S[c0+1][c0+609-1] + can_pair(RNA, c0, c0+609));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1389; c0 += 1)
    for (c1 = c0 + 610; c1 <= min(c0 + 1219, 1999); c1 += 1) {
      if (c0 + 1218 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-610+c0] + S[-c0+c1-610+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][609+c0] + S[609+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1389; c0 += 1)
    S[c0][c0+610] = MAX(S[c0][c0+610], S[c0+1][c0+610-1] + can_pair(RNA, c0, c0+610));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1388; c0 += 1)
    for (c1 = c0 + 611; c1 <= min(c0 + 1221, 1999); c1 += 1) {
      if (c0 + 1220 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-611+c0] + S[-c0+c1-611+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][610+c0] + S[610+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1388; c0 += 1)
    S[c0][c0+611] = MAX(S[c0][c0+611], S[c0+1][c0+611-1] + can_pair(RNA, c0, c0+611));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1387; c0 += 1)
    for (c1 = c0 + 612; c1 <= min(c0 + 1223, 1999); c1 += 1) {
      if (c0 + 1222 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-612+c0] + S[-c0+c1-612+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][611+c0] + S[611+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1387; c0 += 1)
    S[c0][c0+612] = MAX(S[c0][c0+612], S[c0+1][c0+612-1] + can_pair(RNA, c0, c0+612));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1386; c0 += 1)
    for (c1 = c0 + 613; c1 <= min(c0 + 1225, 1999); c1 += 1) {
      if (c0 + 1224 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-613+c0] + S[-c0+c1-613+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][612+c0] + S[612+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1386; c0 += 1)
    S[c0][c0+613] = MAX(S[c0][c0+613], S[c0+1][c0+613-1] + can_pair(RNA, c0, c0+613));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1385; c0 += 1)
    for (c1 = c0 + 614; c1 <= min(c0 + 1227, 1999); c1 += 1) {
      if (c0 + 1226 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-614+c0] + S[-c0+c1-614+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][613+c0] + S[613+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1385; c0 += 1)
    S[c0][c0+614] = MAX(S[c0][c0+614], S[c0+1][c0+614-1] + can_pair(RNA, c0, c0+614));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1384; c0 += 1)
    for (c1 = c0 + 615; c1 <= min(c0 + 1229, 1999); c1 += 1) {
      if (c0 + 1228 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-615+c0] + S[-c0+c1-615+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][614+c0] + S[614+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1384; c0 += 1)
    S[c0][c0+615] = MAX(S[c0][c0+615], S[c0+1][c0+615-1] + can_pair(RNA, c0, c0+615));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1383; c0 += 1)
    for (c1 = c0 + 616; c1 <= min(c0 + 1231, 1999); c1 += 1) {
      if (c0 + 1230 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-616+c0] + S[-c0+c1-616+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][615+c0] + S[615+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1383; c0 += 1)
    S[c0][c0+616] = MAX(S[c0][c0+616], S[c0+1][c0+616-1] + can_pair(RNA, c0, c0+616));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1382; c0 += 1)
    for (c1 = c0 + 617; c1 <= min(c0 + 1233, 1999); c1 += 1) {
      if (c0 + 1232 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-617+c0] + S[-c0+c1-617+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][616+c0] + S[616+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1382; c0 += 1)
    S[c0][c0+617] = MAX(S[c0][c0+617], S[c0+1][c0+617-1] + can_pair(RNA, c0, c0+617));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1381; c0 += 1)
    for (c1 = c0 + 618; c1 <= min(c0 + 1235, 1999); c1 += 1) {
      if (c0 + 1234 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-618+c0] + S[-c0+c1-618+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][617+c0] + S[617+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1381; c0 += 1)
    S[c0][c0+618] = MAX(S[c0][c0+618], S[c0+1][c0+618-1] + can_pair(RNA, c0, c0+618));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1380; c0 += 1)
    for (c1 = c0 + 619; c1 <= min(c0 + 1237, 1999); c1 += 1) {
      if (c0 + 1236 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-619+c0] + S[-c0+c1-619+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][618+c0] + S[618+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1380; c0 += 1)
    S[c0][c0+619] = MAX(S[c0][c0+619], S[c0+1][c0+619-1] + can_pair(RNA, c0, c0+619));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1379; c0 += 1)
    for (c1 = c0 + 620; c1 <= min(c0 + 1239, 1999); c1 += 1) {
      if (c0 + 1238 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-620+c0] + S[-c0+c1-620+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][619+c0] + S[619+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1379; c0 += 1)
    S[c0][c0+620] = MAX(S[c0][c0+620], S[c0+1][c0+620-1] + can_pair(RNA, c0, c0+620));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1378; c0 += 1)
    for (c1 = c0 + 621; c1 <= min(c0 + 1241, 1999); c1 += 1) {
      if (c0 + 1240 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-621+c0] + S[-c0+c1-621+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][620+c0] + S[620+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1378; c0 += 1)
    S[c0][c0+621] = MAX(S[c0][c0+621], S[c0+1][c0+621-1] + can_pair(RNA, c0, c0+621));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1377; c0 += 1)
    for (c1 = c0 + 622; c1 <= min(c0 + 1243, 1999); c1 += 1) {
      if (c0 + 1242 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-622+c0] + S[-c0+c1-622+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][621+c0] + S[621+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1377; c0 += 1)
    S[c0][c0+622] = MAX(S[c0][c0+622], S[c0+1][c0+622-1] + can_pair(RNA, c0, c0+622));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1376; c0 += 1)
    for (c1 = c0 + 623; c1 <= min(c0 + 1245, 1999); c1 += 1) {
      if (c0 + 1244 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-623+c0] + S[-c0+c1-623+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][622+c0] + S[622+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1376; c0 += 1)
    S[c0][c0+623] = MAX(S[c0][c0+623], S[c0+1][c0+623-1] + can_pair(RNA, c0, c0+623));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1375; c0 += 1)
    for (c1 = c0 + 624; c1 <= min(c0 + 1247, 1999); c1 += 1) {
      if (c0 + 1246 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-624+c0] + S[-c0+c1-624+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][623+c0] + S[623+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1375; c0 += 1)
    S[c0][c0+624] = MAX(S[c0][c0+624], S[c0+1][c0+624-1] + can_pair(RNA, c0, c0+624));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1374; c0 += 1)
    for (c1 = c0 + 625; c1 <= min(c0 + 1249, 1999); c1 += 1) {
      if (c0 + 1248 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-625+c0] + S[-c0+c1-625+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][624+c0] + S[624+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1374; c0 += 1)
    S[c0][c0+625] = MAX(S[c0][c0+625], S[c0+1][c0+625-1] + can_pair(RNA, c0, c0+625));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1373; c0 += 1)
    for (c1 = c0 + 626; c1 <= min(c0 + 1251, 1999); c1 += 1) {
      if (c0 + 1250 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-626+c0] + S[-c0+c1-626+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][625+c0] + S[625+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1373; c0 += 1)
    S[c0][c0+626] = MAX(S[c0][c0+626], S[c0+1][c0+626-1] + can_pair(RNA, c0, c0+626));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1372; c0 += 1)
    for (c1 = c0 + 627; c1 <= min(c0 + 1253, 1999); c1 += 1) {
      if (c0 + 1252 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-627+c0] + S[-c0+c1-627+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][626+c0] + S[626+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1372; c0 += 1)
    S[c0][c0+627] = MAX(S[c0][c0+627], S[c0+1][c0+627-1] + can_pair(RNA, c0, c0+627));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1371; c0 += 1)
    for (c1 = c0 + 628; c1 <= min(c0 + 1255, 1999); c1 += 1) {
      if (c0 + 1254 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-628+c0] + S[-c0+c1-628+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][627+c0] + S[627+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1371; c0 += 1)
    S[c0][c0+628] = MAX(S[c0][c0+628], S[c0+1][c0+628-1] + can_pair(RNA, c0, c0+628));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1370; c0 += 1)
    for (c1 = c0 + 629; c1 <= min(c0 + 1257, 1999); c1 += 1) {
      if (c0 + 1256 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-629+c0] + S[-c0+c1-629+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][628+c0] + S[628+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1370; c0 += 1)
    S[c0][c0+629] = MAX(S[c0][c0+629], S[c0+1][c0+629-1] + can_pair(RNA, c0, c0+629));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1369; c0 += 1)
    for (c1 = c0 + 630; c1 <= min(c0 + 1259, 1999); c1 += 1) {
      if (c0 + 1258 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-630+c0] + S[-c0+c1-630+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][629+c0] + S[629+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1369; c0 += 1)
    S[c0][c0+630] = MAX(S[c0][c0+630], S[c0+1][c0+630-1] + can_pair(RNA, c0, c0+630));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1368; c0 += 1)
    for (c1 = c0 + 631; c1 <= min(c0 + 1261, 1999); c1 += 1) {
      if (c0 + 1260 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-631+c0] + S[-c0+c1-631+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][630+c0] + S[630+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1368; c0 += 1)
    S[c0][c0+631] = MAX(S[c0][c0+631], S[c0+1][c0+631-1] + can_pair(RNA, c0, c0+631));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1367; c0 += 1)
    for (c1 = c0 + 632; c1 <= min(c0 + 1263, 1999); c1 += 1) {
      if (c0 + 1262 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-632+c0] + S[-c0+c1-632+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][631+c0] + S[631+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1367; c0 += 1)
    S[c0][c0+632] = MAX(S[c0][c0+632], S[c0+1][c0+632-1] + can_pair(RNA, c0, c0+632));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1366; c0 += 1)
    for (c1 = c0 + 633; c1 <= min(c0 + 1265, 1999); c1 += 1) {
      if (c0 + 1264 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-633+c0] + S[-c0+c1-633+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][632+c0] + S[632+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1366; c0 += 1)
    S[c0][c0+633] = MAX(S[c0][c0+633], S[c0+1][c0+633-1] + can_pair(RNA, c0, c0+633));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1365; c0 += 1)
    for (c1 = c0 + 634; c1 <= min(c0 + 1267, 1999); c1 += 1) {
      if (c0 + 1266 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-634+c0] + S[-c0+c1-634+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][633+c0] + S[633+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1365; c0 += 1)
    S[c0][c0+634] = MAX(S[c0][c0+634], S[c0+1][c0+634-1] + can_pair(RNA, c0, c0+634));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1364; c0 += 1)
    for (c1 = c0 + 635; c1 <= min(c0 + 1269, 1999); c1 += 1) {
      if (c0 + 1268 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-635+c0] + S[-c0+c1-635+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][634+c0] + S[634+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1364; c0 += 1)
    S[c0][c0+635] = MAX(S[c0][c0+635], S[c0+1][c0+635-1] + can_pair(RNA, c0, c0+635));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1363; c0 += 1)
    for (c1 = c0 + 636; c1 <= min(c0 + 1271, 1999); c1 += 1) {
      if (c0 + 1270 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-636+c0] + S[-c0+c1-636+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][635+c0] + S[635+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1363; c0 += 1)
    S[c0][c0+636] = MAX(S[c0][c0+636], S[c0+1][c0+636-1] + can_pair(RNA, c0, c0+636));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1362; c0 += 1)
    for (c1 = c0 + 637; c1 <= min(c0 + 1273, 1999); c1 += 1) {
      if (c0 + 1272 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-637+c0] + S[-c0+c1-637+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][636+c0] + S[636+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1362; c0 += 1)
    S[c0][c0+637] = MAX(S[c0][c0+637], S[c0+1][c0+637-1] + can_pair(RNA, c0, c0+637));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1361; c0 += 1)
    for (c1 = c0 + 638; c1 <= min(c0 + 1275, 1999); c1 += 1) {
      if (c0 + 1274 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-638+c0] + S[-c0+c1-638+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][637+c0] + S[637+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1361; c0 += 1)
    S[c0][c0+638] = MAX(S[c0][c0+638], S[c0+1][c0+638-1] + can_pair(RNA, c0, c0+638));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1360; c0 += 1)
    for (c1 = c0 + 639; c1 <= min(c0 + 1277, 1999); c1 += 1) {
      if (c0 + 1276 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-639+c0] + S[-c0+c1-639+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][638+c0] + S[638+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1360; c0 += 1)
    S[c0][c0+639] = MAX(S[c0][c0+639], S[c0+1][c0+639-1] + can_pair(RNA, c0, c0+639));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1359; c0 += 1)
    for (c1 = c0 + 640; c1 <= min(c0 + 1279, 1999); c1 += 1) {
      if (c0 + 1278 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-640+c0] + S[-c0+c1-640+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][639+c0] + S[639+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1359; c0 += 1)
    S[c0][c0+640] = MAX(S[c0][c0+640], S[c0+1][c0+640-1] + can_pair(RNA, c0, c0+640));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1358; c0 += 1)
    for (c1 = c0 + 641; c1 <= min(c0 + 1281, 1999); c1 += 1) {
      if (c0 + 1280 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-641+c0] + S[-c0+c1-641+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][640+c0] + S[640+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1358; c0 += 1)
    S[c0][c0+641] = MAX(S[c0][c0+641], S[c0+1][c0+641-1] + can_pair(RNA, c0, c0+641));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1357; c0 += 1)
    for (c1 = c0 + 642; c1 <= min(c0 + 1283, 1999); c1 += 1) {
      if (c0 + 1282 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-642+c0] + S[-c0+c1-642+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][641+c0] + S[641+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1357; c0 += 1)
    S[c0][c0+642] = MAX(S[c0][c0+642], S[c0+1][c0+642-1] + can_pair(RNA, c0, c0+642));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1356; c0 += 1)
    for (c1 = c0 + 643; c1 <= min(c0 + 1285, 1999); c1 += 1) {
      if (c0 + 1284 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-643+c0] + S[-c0+c1-643+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][642+c0] + S[642+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1356; c0 += 1)
    S[c0][c0+643] = MAX(S[c0][c0+643], S[c0+1][c0+643-1] + can_pair(RNA, c0, c0+643));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1355; c0 += 1)
    for (c1 = c0 + 644; c1 <= min(c0 + 1287, 1999); c1 += 1) {
      if (c0 + 1286 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-644+c0] + S[-c0+c1-644+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][643+c0] + S[643+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1355; c0 += 1)
    S[c0][c0+644] = MAX(S[c0][c0+644], S[c0+1][c0+644-1] + can_pair(RNA, c0, c0+644));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1354; c0 += 1)
    for (c1 = c0 + 645; c1 <= min(c0 + 1289, 1999); c1 += 1) {
      if (c0 + 1288 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-645+c0] + S[-c0+c1-645+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][644+c0] + S[644+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1354; c0 += 1)
    S[c0][c0+645] = MAX(S[c0][c0+645], S[c0+1][c0+645-1] + can_pair(RNA, c0, c0+645));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1353; c0 += 1)
    for (c1 = c0 + 646; c1 <= min(c0 + 1291, 1999); c1 += 1) {
      if (c0 + 1290 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-646+c0] + S[-c0+c1-646+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][645+c0] + S[645+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1353; c0 += 1)
    S[c0][c0+646] = MAX(S[c0][c0+646], S[c0+1][c0+646-1] + can_pair(RNA, c0, c0+646));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1352; c0 += 1)
    for (c1 = c0 + 647; c1 <= min(c0 + 1293, 1999); c1 += 1) {
      if (c0 + 1292 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-647+c0] + S[-c0+c1-647+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][646+c0] + S[646+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1352; c0 += 1)
    S[c0][c0+647] = MAX(S[c0][c0+647], S[c0+1][c0+647-1] + can_pair(RNA, c0, c0+647));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1351; c0 += 1)
    for (c1 = c0 + 648; c1 <= min(c0 + 1295, 1999); c1 += 1) {
      if (c0 + 1294 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-648+c0] + S[-c0+c1-648+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][647+c0] + S[647+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1351; c0 += 1)
    S[c0][c0+648] = MAX(S[c0][c0+648], S[c0+1][c0+648-1] + can_pair(RNA, c0, c0+648));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1350; c0 += 1)
    for (c1 = c0 + 649; c1 <= min(c0 + 1297, 1999); c1 += 1) {
      if (c0 + 1296 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-649+c0] + S[-c0+c1-649+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][648+c0] + S[648+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1350; c0 += 1)
    S[c0][c0+649] = MAX(S[c0][c0+649], S[c0+1][c0+649-1] + can_pair(RNA, c0, c0+649));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1349; c0 += 1)
    for (c1 = c0 + 650; c1 <= min(c0 + 1299, 1999); c1 += 1) {
      if (c0 + 1298 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-650+c0] + S[-c0+c1-650+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][649+c0] + S[649+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1349; c0 += 1)
    S[c0][c0+650] = MAX(S[c0][c0+650], S[c0+1][c0+650-1] + can_pair(RNA, c0, c0+650));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1348; c0 += 1)
    for (c1 = c0 + 651; c1 <= min(c0 + 1301, 1999); c1 += 1) {
      if (c0 + 1300 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-651+c0] + S[-c0+c1-651+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][650+c0] + S[650+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1348; c0 += 1)
    S[c0][c0+651] = MAX(S[c0][c0+651], S[c0+1][c0+651-1] + can_pair(RNA, c0, c0+651));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1347; c0 += 1)
    for (c1 = c0 + 652; c1 <= min(c0 + 1303, 1999); c1 += 1) {
      if (c0 + 1302 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-652+c0] + S[-c0+c1-652+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][651+c0] + S[651+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1347; c0 += 1)
    S[c0][c0+652] = MAX(S[c0][c0+652], S[c0+1][c0+652-1] + can_pair(RNA, c0, c0+652));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1346; c0 += 1)
    for (c1 = c0 + 653; c1 <= min(c0 + 1305, 1999); c1 += 1) {
      if (c0 + 1304 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-653+c0] + S[-c0+c1-653+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][652+c0] + S[652+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1346; c0 += 1)
    S[c0][c0+653] = MAX(S[c0][c0+653], S[c0+1][c0+653-1] + can_pair(RNA, c0, c0+653));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1345; c0 += 1)
    for (c1 = c0 + 654; c1 <= min(c0 + 1307, 1999); c1 += 1) {
      if (c0 + 1306 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-654+c0] + S[-c0+c1-654+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][653+c0] + S[653+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1345; c0 += 1)
    S[c0][c0+654] = MAX(S[c0][c0+654], S[c0+1][c0+654-1] + can_pair(RNA, c0, c0+654));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1344; c0 += 1)
    for (c1 = c0 + 655; c1 <= min(c0 + 1309, 1999); c1 += 1) {
      if (c0 + 1308 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-655+c0] + S[-c0+c1-655+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][654+c0] + S[654+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1344; c0 += 1)
    S[c0][c0+655] = MAX(S[c0][c0+655], S[c0+1][c0+655-1] + can_pair(RNA, c0, c0+655));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1343; c0 += 1)
    for (c1 = c0 + 656; c1 <= min(c0 + 1311, 1999); c1 += 1) {
      if (c0 + 1310 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-656+c0] + S[-c0+c1-656+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][655+c0] + S[655+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1343; c0 += 1)
    S[c0][c0+656] = MAX(S[c0][c0+656], S[c0+1][c0+656-1] + can_pair(RNA, c0, c0+656));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1342; c0 += 1)
    for (c1 = c0 + 657; c1 <= min(c0 + 1313, 1999); c1 += 1) {
      if (c0 + 1312 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-657+c0] + S[-c0+c1-657+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][656+c0] + S[656+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1342; c0 += 1)
    S[c0][c0+657] = MAX(S[c0][c0+657], S[c0+1][c0+657-1] + can_pair(RNA, c0, c0+657));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1341; c0 += 1)
    for (c1 = c0 + 658; c1 <= min(c0 + 1315, 1999); c1 += 1) {
      if (c0 + 1314 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-658+c0] + S[-c0+c1-658+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][657+c0] + S[657+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1341; c0 += 1)
    S[c0][c0+658] = MAX(S[c0][c0+658], S[c0+1][c0+658-1] + can_pair(RNA, c0, c0+658));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1340; c0 += 1)
    for (c1 = c0 + 659; c1 <= min(c0 + 1317, 1999); c1 += 1) {
      if (c0 + 1316 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-659+c0] + S[-c0+c1-659+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][658+c0] + S[658+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1340; c0 += 1)
    S[c0][c0+659] = MAX(S[c0][c0+659], S[c0+1][c0+659-1] + can_pair(RNA, c0, c0+659));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1339; c0 += 1)
    for (c1 = c0 + 660; c1 <= min(c0 + 1319, 1999); c1 += 1) {
      if (c0 + 1318 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-660+c0] + S[-c0+c1-660+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][659+c0] + S[659+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1339; c0 += 1)
    S[c0][c0+660] = MAX(S[c0][c0+660], S[c0+1][c0+660-1] + can_pair(RNA, c0, c0+660));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1338; c0 += 1)
    for (c1 = c0 + 661; c1 <= min(c0 + 1321, 1999); c1 += 1) {
      if (c0 + 1320 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-661+c0] + S[-c0+c1-661+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][660+c0] + S[660+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1338; c0 += 1)
    S[c0][c0+661] = MAX(S[c0][c0+661], S[c0+1][c0+661-1] + can_pair(RNA, c0, c0+661));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1337; c0 += 1)
    for (c1 = c0 + 662; c1 <= min(c0 + 1323, 1999); c1 += 1) {
      if (c0 + 1322 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-662+c0] + S[-c0+c1-662+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][661+c0] + S[661+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1337; c0 += 1)
    S[c0][c0+662] = MAX(S[c0][c0+662], S[c0+1][c0+662-1] + can_pair(RNA, c0, c0+662));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1336; c0 += 1)
    for (c1 = c0 + 663; c1 <= min(c0 + 1325, 1999); c1 += 1) {
      if (c0 + 1324 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-663+c0] + S[-c0+c1-663+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][662+c0] + S[662+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1336; c0 += 1)
    S[c0][c0+663] = MAX(S[c0][c0+663], S[c0+1][c0+663-1] + can_pair(RNA, c0, c0+663));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1335; c0 += 1)
    for (c1 = c0 + 664; c1 <= min(c0 + 1327, 1999); c1 += 1) {
      if (c0 + 1326 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-664+c0] + S[-c0+c1-664+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][663+c0] + S[663+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1335; c0 += 1)
    S[c0][c0+664] = MAX(S[c0][c0+664], S[c0+1][c0+664-1] + can_pair(RNA, c0, c0+664));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1334; c0 += 1)
    for (c1 = c0 + 665; c1 <= min(c0 + 1329, 1999); c1 += 1) {
      if (c0 + 1328 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-665+c0] + S[-c0+c1-665+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][664+c0] + S[664+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1334; c0 += 1)
    S[c0][c0+665] = MAX(S[c0][c0+665], S[c0+1][c0+665-1] + can_pair(RNA, c0, c0+665));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1333; c0 += 1)
    for (c1 = c0 + 666; c1 <= min(c0 + 1331, 1999); c1 += 1) {
      if (c0 + 1330 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-666+c0] + S[-c0+c1-666+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][665+c0] + S[665+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1333; c0 += 1)
    S[c0][c0+666] = MAX(S[c0][c0+666], S[c0+1][c0+666-1] + can_pair(RNA, c0, c0+666));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1332; c0 += 1)
    for (c1 = c0 + 667; c1 <= min(c0 + 1333, 1999); c1 += 1) {
      if (c0 + 1332 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-667+c0] + S[-c0+c1-667+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][666+c0] + S[666+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1332; c0 += 1)
    S[c0][c0+667] = MAX(S[c0][c0+667], S[c0+1][c0+667-1] + can_pair(RNA, c0, c0+667));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1331; c0 += 1)
    for (c1 = c0 + 668; c1 <= min(c0 + 1335, 1999); c1 += 1) {
      if (c0 + 1334 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-668+c0] + S[-c0+c1-668+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][667+c0] + S[667+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1331; c0 += 1)
    S[c0][c0+668] = MAX(S[c0][c0+668], S[c0+1][c0+668-1] + can_pair(RNA, c0, c0+668));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1330; c0 += 1)
    for (c1 = c0 + 669; c1 <= min(c0 + 1337, 1999); c1 += 1) {
      if (c0 + 1336 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-669+c0] + S[-c0+c1-669+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][668+c0] + S[668+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1330; c0 += 1)
    S[c0][c0+669] = MAX(S[c0][c0+669], S[c0+1][c0+669-1] + can_pair(RNA, c0, c0+669));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1329; c0 += 1)
    for (c1 = c0 + 670; c1 <= min(c0 + 1339, 1999); c1 += 1) {
      if (c0 + 1338 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-670+c0] + S[-c0+c1-670+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][669+c0] + S[669+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1329; c0 += 1)
    S[c0][c0+670] = MAX(S[c0][c0+670], S[c0+1][c0+670-1] + can_pair(RNA, c0, c0+670));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1328; c0 += 1)
    for (c1 = c0 + 671; c1 <= min(c0 + 1341, 1999); c1 += 1) {
      if (c0 + 1340 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-671+c0] + S[-c0+c1-671+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][670+c0] + S[670+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1328; c0 += 1)
    S[c0][c0+671] = MAX(S[c0][c0+671], S[c0+1][c0+671-1] + can_pair(RNA, c0, c0+671));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1327; c0 += 1)
    for (c1 = c0 + 672; c1 <= min(c0 + 1343, 1999); c1 += 1) {
      if (c0 + 1342 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-672+c0] + S[-c0+c1-672+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][671+c0] + S[671+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1327; c0 += 1)
    S[c0][c0+672] = MAX(S[c0][c0+672], S[c0+1][c0+672-1] + can_pair(RNA, c0, c0+672));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1326; c0 += 1)
    for (c1 = c0 + 673; c1 <= min(c0 + 1345, 1999); c1 += 1) {
      if (c0 + 1344 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-673+c0] + S[-c0+c1-673+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][672+c0] + S[672+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1326; c0 += 1)
    S[c0][c0+673] = MAX(S[c0][c0+673], S[c0+1][c0+673-1] + can_pair(RNA, c0, c0+673));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1325; c0 += 1)
    for (c1 = c0 + 674; c1 <= min(c0 + 1347, 1999); c1 += 1) {
      if (c0 + 1346 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-674+c0] + S[-c0+c1-674+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][673+c0] + S[673+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1325; c0 += 1)
    S[c0][c0+674] = MAX(S[c0][c0+674], S[c0+1][c0+674-1] + can_pair(RNA, c0, c0+674));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1324; c0 += 1)
    for (c1 = c0 + 675; c1 <= min(c0 + 1349, 1999); c1 += 1) {
      if (c0 + 1348 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-675+c0] + S[-c0+c1-675+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][674+c0] + S[674+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1324; c0 += 1)
    S[c0][c0+675] = MAX(S[c0][c0+675], S[c0+1][c0+675-1] + can_pair(RNA, c0, c0+675));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1323; c0 += 1)
    for (c1 = c0 + 676; c1 <= min(c0 + 1351, 1999); c1 += 1) {
      if (c0 + 1350 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-676+c0] + S[-c0+c1-676+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][675+c0] + S[675+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1323; c0 += 1)
    S[c0][c0+676] = MAX(S[c0][c0+676], S[c0+1][c0+676-1] + can_pair(RNA, c0, c0+676));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1322; c0 += 1)
    for (c1 = c0 + 677; c1 <= min(c0 + 1353, 1999); c1 += 1) {
      if (c0 + 1352 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-677+c0] + S[-c0+c1-677+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][676+c0] + S[676+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1322; c0 += 1)
    S[c0][c0+677] = MAX(S[c0][c0+677], S[c0+1][c0+677-1] + can_pair(RNA, c0, c0+677));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1321; c0 += 1)
    for (c1 = c0 + 678; c1 <= min(c0 + 1355, 1999); c1 += 1) {
      if (c0 + 1354 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-678+c0] + S[-c0+c1-678+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][677+c0] + S[677+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1321; c0 += 1)
    S[c0][c0+678] = MAX(S[c0][c0+678], S[c0+1][c0+678-1] + can_pair(RNA, c0, c0+678));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1320; c0 += 1)
    for (c1 = c0 + 679; c1 <= min(c0 + 1357, 1999); c1 += 1) {
      if (c0 + 1356 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-679+c0] + S[-c0+c1-679+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][678+c0] + S[678+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1320; c0 += 1)
    S[c0][c0+679] = MAX(S[c0][c0+679], S[c0+1][c0+679-1] + can_pair(RNA, c0, c0+679));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1319; c0 += 1)
    for (c1 = c0 + 680; c1 <= min(c0 + 1359, 1999); c1 += 1) {
      if (c0 + 1358 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-680+c0] + S[-c0+c1-680+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][679+c0] + S[679+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1319; c0 += 1)
    S[c0][c0+680] = MAX(S[c0][c0+680], S[c0+1][c0+680-1] + can_pair(RNA, c0, c0+680));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1318; c0 += 1)
    for (c1 = c0 + 681; c1 <= min(c0 + 1361, 1999); c1 += 1) {
      if (c0 + 1360 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-681+c0] + S[-c0+c1-681+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][680+c0] + S[680+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1318; c0 += 1)
    S[c0][c0+681] = MAX(S[c0][c0+681], S[c0+1][c0+681-1] + can_pair(RNA, c0, c0+681));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1317; c0 += 1)
    for (c1 = c0 + 682; c1 <= min(c0 + 1363, 1999); c1 += 1) {
      if (c0 + 1362 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-682+c0] + S[-c0+c1-682+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][681+c0] + S[681+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1317; c0 += 1)
    S[c0][c0+682] = MAX(S[c0][c0+682], S[c0+1][c0+682-1] + can_pair(RNA, c0, c0+682));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1316; c0 += 1)
    for (c1 = c0 + 683; c1 <= min(c0 + 1365, 1999); c1 += 1) {
      if (c0 + 1364 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-683+c0] + S[-c0+c1-683+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][682+c0] + S[682+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1316; c0 += 1)
    S[c0][c0+683] = MAX(S[c0][c0+683], S[c0+1][c0+683-1] + can_pair(RNA, c0, c0+683));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1315; c0 += 1)
    for (c1 = c0 + 684; c1 <= min(c0 + 1367, 1999); c1 += 1) {
      if (c0 + 1366 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-684+c0] + S[-c0+c1-684+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][683+c0] + S[683+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1315; c0 += 1)
    S[c0][c0+684] = MAX(S[c0][c0+684], S[c0+1][c0+684-1] + can_pair(RNA, c0, c0+684));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1314; c0 += 1)
    for (c1 = c0 + 685; c1 <= min(c0 + 1369, 1999); c1 += 1) {
      if (c0 + 1368 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-685+c0] + S[-c0+c1-685+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][684+c0] + S[684+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1314; c0 += 1)
    S[c0][c0+685] = MAX(S[c0][c0+685], S[c0+1][c0+685-1] + can_pair(RNA, c0, c0+685));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1313; c0 += 1)
    for (c1 = c0 + 686; c1 <= min(c0 + 1371, 1999); c1 += 1) {
      if (c0 + 1370 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-686+c0] + S[-c0+c1-686+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][685+c0] + S[685+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1313; c0 += 1)
    S[c0][c0+686] = MAX(S[c0][c0+686], S[c0+1][c0+686-1] + can_pair(RNA, c0, c0+686));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1312; c0 += 1)
    for (c1 = c0 + 687; c1 <= min(c0 + 1373, 1999); c1 += 1) {
      if (c0 + 1372 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-687+c0] + S[-c0+c1-687+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][686+c0] + S[686+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1312; c0 += 1)
    S[c0][c0+687] = MAX(S[c0][c0+687], S[c0+1][c0+687-1] + can_pair(RNA, c0, c0+687));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1311; c0 += 1)
    for (c1 = c0 + 688; c1 <= min(c0 + 1375, 1999); c1 += 1) {
      if (c0 + 1374 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-688+c0] + S[-c0+c1-688+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][687+c0] + S[687+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1311; c0 += 1)
    S[c0][c0+688] = MAX(S[c0][c0+688], S[c0+1][c0+688-1] + can_pair(RNA, c0, c0+688));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1310; c0 += 1)
    for (c1 = c0 + 689; c1 <= min(c0 + 1377, 1999); c1 += 1) {
      if (c0 + 1376 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-689+c0] + S[-c0+c1-689+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][688+c0] + S[688+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1310; c0 += 1)
    S[c0][c0+689] = MAX(S[c0][c0+689], S[c0+1][c0+689-1] + can_pair(RNA, c0, c0+689));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1309; c0 += 1)
    for (c1 = c0 + 690; c1 <= min(c0 + 1379, 1999); c1 += 1) {
      if (c0 + 1378 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-690+c0] + S[-c0+c1-690+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][689+c0] + S[689+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1309; c0 += 1)
    S[c0][c0+690] = MAX(S[c0][c0+690], S[c0+1][c0+690-1] + can_pair(RNA, c0, c0+690));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1308; c0 += 1)
    for (c1 = c0 + 691; c1 <= min(c0 + 1381, 1999); c1 += 1) {
      if (c0 + 1380 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-691+c0] + S[-c0+c1-691+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][690+c0] + S[690+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1308; c0 += 1)
    S[c0][c0+691] = MAX(S[c0][c0+691], S[c0+1][c0+691-1] + can_pair(RNA, c0, c0+691));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1307; c0 += 1)
    for (c1 = c0 + 692; c1 <= min(c0 + 1383, 1999); c1 += 1) {
      if (c0 + 1382 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-692+c0] + S[-c0+c1-692+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][691+c0] + S[691+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1307; c0 += 1)
    S[c0][c0+692] = MAX(S[c0][c0+692], S[c0+1][c0+692-1] + can_pair(RNA, c0, c0+692));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1306; c0 += 1)
    for (c1 = c0 + 693; c1 <= min(c0 + 1385, 1999); c1 += 1) {
      if (c0 + 1384 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-693+c0] + S[-c0+c1-693+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][692+c0] + S[692+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1306; c0 += 1)
    S[c0][c0+693] = MAX(S[c0][c0+693], S[c0+1][c0+693-1] + can_pair(RNA, c0, c0+693));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1305; c0 += 1)
    for (c1 = c0 + 694; c1 <= min(c0 + 1387, 1999); c1 += 1) {
      if (c0 + 1386 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-694+c0] + S[-c0+c1-694+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][693+c0] + S[693+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1305; c0 += 1)
    S[c0][c0+694] = MAX(S[c0][c0+694], S[c0+1][c0+694-1] + can_pair(RNA, c0, c0+694));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1304; c0 += 1)
    for (c1 = c0 + 695; c1 <= min(c0 + 1389, 1999); c1 += 1) {
      if (c0 + 1388 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-695+c0] + S[-c0+c1-695+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][694+c0] + S[694+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1304; c0 += 1)
    S[c0][c0+695] = MAX(S[c0][c0+695], S[c0+1][c0+695-1] + can_pair(RNA, c0, c0+695));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1303; c0 += 1)
    for (c1 = c0 + 696; c1 <= min(c0 + 1391, 1999); c1 += 1) {
      if (c0 + 1390 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-696+c0] + S[-c0+c1-696+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][695+c0] + S[695+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1303; c0 += 1)
    S[c0][c0+696] = MAX(S[c0][c0+696], S[c0+1][c0+696-1] + can_pair(RNA, c0, c0+696));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1302; c0 += 1)
    for (c1 = c0 + 697; c1 <= min(c0 + 1393, 1999); c1 += 1) {
      if (c0 + 1392 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-697+c0] + S[-c0+c1-697+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][696+c0] + S[696+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1302; c0 += 1)
    S[c0][c0+697] = MAX(S[c0][c0+697], S[c0+1][c0+697-1] + can_pair(RNA, c0, c0+697));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1301; c0 += 1)
    for (c1 = c0 + 698; c1 <= min(c0 + 1395, 1999); c1 += 1) {
      if (c0 + 1394 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-698+c0] + S[-c0+c1-698+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][697+c0] + S[697+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1301; c0 += 1)
    S[c0][c0+698] = MAX(S[c0][c0+698], S[c0+1][c0+698-1] + can_pair(RNA, c0, c0+698));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1300; c0 += 1)
    for (c1 = c0 + 699; c1 <= min(c0 + 1397, 1999); c1 += 1) {
      if (c0 + 1396 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-699+c0] + S[-c0+c1-699+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][698+c0] + S[698+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1300; c0 += 1)
    S[c0][c0+699] = MAX(S[c0][c0+699], S[c0+1][c0+699-1] + can_pair(RNA, c0, c0+699));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1299; c0 += 1)
    for (c1 = c0 + 700; c1 <= min(c0 + 1399, 1999); c1 += 1) {
      if (c0 + 1398 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-700+c0] + S[-c0+c1-700+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][699+c0] + S[699+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1299; c0 += 1)
    S[c0][c0+700] = MAX(S[c0][c0+700], S[c0+1][c0+700-1] + can_pair(RNA, c0, c0+700));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1298; c0 += 1)
    for (c1 = c0 + 701; c1 <= min(c0 + 1401, 1999); c1 += 1) {
      if (c0 + 1400 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-701+c0] + S[-c0+c1-701+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][700+c0] + S[700+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1298; c0 += 1)
    S[c0][c0+701] = MAX(S[c0][c0+701], S[c0+1][c0+701-1] + can_pair(RNA, c0, c0+701));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1297; c0 += 1)
    for (c1 = c0 + 702; c1 <= min(c0 + 1403, 1999); c1 += 1) {
      if (c0 + 1402 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-702+c0] + S[-c0+c1-702+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][701+c0] + S[701+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1297; c0 += 1)
    S[c0][c0+702] = MAX(S[c0][c0+702], S[c0+1][c0+702-1] + can_pair(RNA, c0, c0+702));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1296; c0 += 1)
    for (c1 = c0 + 703; c1 <= min(c0 + 1405, 1999); c1 += 1) {
      if (c0 + 1404 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-703+c0] + S[-c0+c1-703+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][702+c0] + S[702+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1296; c0 += 1)
    S[c0][c0+703] = MAX(S[c0][c0+703], S[c0+1][c0+703-1] + can_pair(RNA, c0, c0+703));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1295; c0 += 1)
    for (c1 = c0 + 704; c1 <= min(c0 + 1407, 1999); c1 += 1) {
      if (c0 + 1406 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-704+c0] + S[-c0+c1-704+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][703+c0] + S[703+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1295; c0 += 1)
    S[c0][c0+704] = MAX(S[c0][c0+704], S[c0+1][c0+704-1] + can_pair(RNA, c0, c0+704));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1294; c0 += 1)
    for (c1 = c0 + 705; c1 <= min(c0 + 1409, 1999); c1 += 1) {
      if (c0 + 1408 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-705+c0] + S[-c0+c1-705+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][704+c0] + S[704+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1294; c0 += 1)
    S[c0][c0+705] = MAX(S[c0][c0+705], S[c0+1][c0+705-1] + can_pair(RNA, c0, c0+705));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1293; c0 += 1)
    for (c1 = c0 + 706; c1 <= min(c0 + 1411, 1999); c1 += 1) {
      if (c0 + 1410 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-706+c0] + S[-c0+c1-706+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][705+c0] + S[705+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1293; c0 += 1)
    S[c0][c0+706] = MAX(S[c0][c0+706], S[c0+1][c0+706-1] + can_pair(RNA, c0, c0+706));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1292; c0 += 1)
    for (c1 = c0 + 707; c1 <= min(c0 + 1413, 1999); c1 += 1) {
      if (c0 + 1412 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-707+c0] + S[-c0+c1-707+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][706+c0] + S[706+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1292; c0 += 1)
    S[c0][c0+707] = MAX(S[c0][c0+707], S[c0+1][c0+707-1] + can_pair(RNA, c0, c0+707));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1291; c0 += 1)
    for (c1 = c0 + 708; c1 <= min(c0 + 1415, 1999); c1 += 1) {
      if (c0 + 1414 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-708+c0] + S[-c0+c1-708+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][707+c0] + S[707+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1291; c0 += 1)
    S[c0][c0+708] = MAX(S[c0][c0+708], S[c0+1][c0+708-1] + can_pair(RNA, c0, c0+708));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1290; c0 += 1)
    for (c1 = c0 + 709; c1 <= min(c0 + 1417, 1999); c1 += 1) {
      if (c0 + 1416 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-709+c0] + S[-c0+c1-709+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][708+c0] + S[708+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1290; c0 += 1)
    S[c0][c0+709] = MAX(S[c0][c0+709], S[c0+1][c0+709-1] + can_pair(RNA, c0, c0+709));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1289; c0 += 1)
    for (c1 = c0 + 710; c1 <= min(c0 + 1419, 1999); c1 += 1) {
      if (c0 + 1418 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-710+c0] + S[-c0+c1-710+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][709+c0] + S[709+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1289; c0 += 1)
    S[c0][c0+710] = MAX(S[c0][c0+710], S[c0+1][c0+710-1] + can_pair(RNA, c0, c0+710));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1288; c0 += 1)
    for (c1 = c0 + 711; c1 <= min(c0 + 1421, 1999); c1 += 1) {
      if (c0 + 1420 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-711+c0] + S[-c0+c1-711+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][710+c0] + S[710+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1288; c0 += 1)
    S[c0][c0+711] = MAX(S[c0][c0+711], S[c0+1][c0+711-1] + can_pair(RNA, c0, c0+711));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1287; c0 += 1)
    for (c1 = c0 + 712; c1 <= min(c0 + 1423, 1999); c1 += 1) {
      if (c0 + 1422 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-712+c0] + S[-c0+c1-712+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][711+c0] + S[711+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1287; c0 += 1)
    S[c0][c0+712] = MAX(S[c0][c0+712], S[c0+1][c0+712-1] + can_pair(RNA, c0, c0+712));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1286; c0 += 1)
    for (c1 = c0 + 713; c1 <= min(c0 + 1425, 1999); c1 += 1) {
      if (c0 + 1424 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-713+c0] + S[-c0+c1-713+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][712+c0] + S[712+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1286; c0 += 1)
    S[c0][c0+713] = MAX(S[c0][c0+713], S[c0+1][c0+713-1] + can_pair(RNA, c0, c0+713));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1285; c0 += 1)
    for (c1 = c0 + 714; c1 <= min(c0 + 1427, 1999); c1 += 1) {
      if (c0 + 1426 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-714+c0] + S[-c0+c1-714+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][713+c0] + S[713+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1285; c0 += 1)
    S[c0][c0+714] = MAX(S[c0][c0+714], S[c0+1][c0+714-1] + can_pair(RNA, c0, c0+714));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1284; c0 += 1)
    for (c1 = c0 + 715; c1 <= min(c0 + 1429, 1999); c1 += 1) {
      if (c0 + 1428 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-715+c0] + S[-c0+c1-715+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][714+c0] + S[714+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1284; c0 += 1)
    S[c0][c0+715] = MAX(S[c0][c0+715], S[c0+1][c0+715-1] + can_pair(RNA, c0, c0+715));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1283; c0 += 1)
    for (c1 = c0 + 716; c1 <= min(c0 + 1431, 1999); c1 += 1) {
      if (c0 + 1430 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-716+c0] + S[-c0+c1-716+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][715+c0] + S[715+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1283; c0 += 1)
    S[c0][c0+716] = MAX(S[c0][c0+716], S[c0+1][c0+716-1] + can_pair(RNA, c0, c0+716));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1282; c0 += 1)
    for (c1 = c0 + 717; c1 <= min(c0 + 1433, 1999); c1 += 1) {
      if (c0 + 1432 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-717+c0] + S[-c0+c1-717+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][716+c0] + S[716+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1282; c0 += 1)
    S[c0][c0+717] = MAX(S[c0][c0+717], S[c0+1][c0+717-1] + can_pair(RNA, c0, c0+717));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1281; c0 += 1)
    for (c1 = c0 + 718; c1 <= min(c0 + 1435, 1999); c1 += 1) {
      if (c0 + 1434 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-718+c0] + S[-c0+c1-718+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][717+c0] + S[717+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1281; c0 += 1)
    S[c0][c0+718] = MAX(S[c0][c0+718], S[c0+1][c0+718-1] + can_pair(RNA, c0, c0+718));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1280; c0 += 1)
    for (c1 = c0 + 719; c1 <= min(c0 + 1437, 1999); c1 += 1) {
      if (c0 + 1436 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-719+c0] + S[-c0+c1-719+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][718+c0] + S[718+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1280; c0 += 1)
    S[c0][c0+719] = MAX(S[c0][c0+719], S[c0+1][c0+719-1] + can_pair(RNA, c0, c0+719));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1279; c0 += 1)
    for (c1 = c0 + 720; c1 <= min(c0 + 1439, 1999); c1 += 1) {
      if (c0 + 1438 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-720+c0] + S[-c0+c1-720+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][719+c0] + S[719+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1279; c0 += 1)
    S[c0][c0+720] = MAX(S[c0][c0+720], S[c0+1][c0+720-1] + can_pair(RNA, c0, c0+720));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1278; c0 += 1)
    for (c1 = c0 + 721; c1 <= min(c0 + 1441, 1999); c1 += 1) {
      if (c0 + 1440 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-721+c0] + S[-c0+c1-721+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][720+c0] + S[720+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1278; c0 += 1)
    S[c0][c0+721] = MAX(S[c0][c0+721], S[c0+1][c0+721-1] + can_pair(RNA, c0, c0+721));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1277; c0 += 1)
    for (c1 = c0 + 722; c1 <= min(c0 + 1443, 1999); c1 += 1) {
      if (c0 + 1442 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-722+c0] + S[-c0+c1-722+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][721+c0] + S[721+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1277; c0 += 1)
    S[c0][c0+722] = MAX(S[c0][c0+722], S[c0+1][c0+722-1] + can_pair(RNA, c0, c0+722));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1276; c0 += 1)
    for (c1 = c0 + 723; c1 <= min(c0 + 1445, 1999); c1 += 1) {
      if (c0 + 1444 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-723+c0] + S[-c0+c1-723+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][722+c0] + S[722+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1276; c0 += 1)
    S[c0][c0+723] = MAX(S[c0][c0+723], S[c0+1][c0+723-1] + can_pair(RNA, c0, c0+723));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1275; c0 += 1)
    for (c1 = c0 + 724; c1 <= min(c0 + 1447, 1999); c1 += 1) {
      if (c0 + 1446 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-724+c0] + S[-c0+c1-724+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][723+c0] + S[723+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1275; c0 += 1)
    S[c0][c0+724] = MAX(S[c0][c0+724], S[c0+1][c0+724-1] + can_pair(RNA, c0, c0+724));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1274; c0 += 1)
    for (c1 = c0 + 725; c1 <= min(c0 + 1449, 1999); c1 += 1) {
      if (c0 + 1448 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-725+c0] + S[-c0+c1-725+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][724+c0] + S[724+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1274; c0 += 1)
    S[c0][c0+725] = MAX(S[c0][c0+725], S[c0+1][c0+725-1] + can_pair(RNA, c0, c0+725));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1273; c0 += 1)
    for (c1 = c0 + 726; c1 <= min(c0 + 1451, 1999); c1 += 1) {
      if (c0 + 1450 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-726+c0] + S[-c0+c1-726+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][725+c0] + S[725+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1273; c0 += 1)
    S[c0][c0+726] = MAX(S[c0][c0+726], S[c0+1][c0+726-1] + can_pair(RNA, c0, c0+726));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1272; c0 += 1)
    for (c1 = c0 + 727; c1 <= min(c0 + 1453, 1999); c1 += 1) {
      if (c0 + 1452 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-727+c0] + S[-c0+c1-727+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][726+c0] + S[726+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1272; c0 += 1)
    S[c0][c0+727] = MAX(S[c0][c0+727], S[c0+1][c0+727-1] + can_pair(RNA, c0, c0+727));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1271; c0 += 1)
    for (c1 = c0 + 728; c1 <= min(c0 + 1455, 1999); c1 += 1) {
      if (c0 + 1454 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-728+c0] + S[-c0+c1-728+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][727+c0] + S[727+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1271; c0 += 1)
    S[c0][c0+728] = MAX(S[c0][c0+728], S[c0+1][c0+728-1] + can_pair(RNA, c0, c0+728));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1270; c0 += 1)
    for (c1 = c0 + 729; c1 <= min(c0 + 1457, 1999); c1 += 1) {
      if (c0 + 1456 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-729+c0] + S[-c0+c1-729+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][728+c0] + S[728+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1270; c0 += 1)
    S[c0][c0+729] = MAX(S[c0][c0+729], S[c0+1][c0+729-1] + can_pair(RNA, c0, c0+729));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1269; c0 += 1)
    for (c1 = c0 + 730; c1 <= min(c0 + 1459, 1999); c1 += 1) {
      if (c0 + 1458 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-730+c0] + S[-c0+c1-730+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][729+c0] + S[729+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1269; c0 += 1)
    S[c0][c0+730] = MAX(S[c0][c0+730], S[c0+1][c0+730-1] + can_pair(RNA, c0, c0+730));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1268; c0 += 1)
    for (c1 = c0 + 731; c1 <= min(c0 + 1461, 1999); c1 += 1) {
      if (c0 + 1460 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-731+c0] + S[-c0+c1-731+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][730+c0] + S[730+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1268; c0 += 1)
    S[c0][c0+731] = MAX(S[c0][c0+731], S[c0+1][c0+731-1] + can_pair(RNA, c0, c0+731));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1267; c0 += 1)
    for (c1 = c0 + 732; c1 <= min(c0 + 1463, 1999); c1 += 1) {
      if (c0 + 1462 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-732+c0] + S[-c0+c1-732+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][731+c0] + S[731+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1267; c0 += 1)
    S[c0][c0+732] = MAX(S[c0][c0+732], S[c0+1][c0+732-1] + can_pair(RNA, c0, c0+732));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1266; c0 += 1)
    for (c1 = c0 + 733; c1 <= min(c0 + 1465, 1999); c1 += 1) {
      if (c0 + 1464 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-733+c0] + S[-c0+c1-733+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][732+c0] + S[732+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1266; c0 += 1)
    S[c0][c0+733] = MAX(S[c0][c0+733], S[c0+1][c0+733-1] + can_pair(RNA, c0, c0+733));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1265; c0 += 1)
    for (c1 = c0 + 734; c1 <= min(c0 + 1467, 1999); c1 += 1) {
      if (c0 + 1466 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-734+c0] + S[-c0+c1-734+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][733+c0] + S[733+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1265; c0 += 1)
    S[c0][c0+734] = MAX(S[c0][c0+734], S[c0+1][c0+734-1] + can_pair(RNA, c0, c0+734));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1264; c0 += 1)
    for (c1 = c0 + 735; c1 <= min(c0 + 1469, 1999); c1 += 1) {
      if (c0 + 1468 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-735+c0] + S[-c0+c1-735+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][734+c0] + S[734+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1264; c0 += 1)
    S[c0][c0+735] = MAX(S[c0][c0+735], S[c0+1][c0+735-1] + can_pair(RNA, c0, c0+735));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1263; c0 += 1)
    for (c1 = c0 + 736; c1 <= min(c0 + 1471, 1999); c1 += 1) {
      if (c0 + 1470 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-736+c0] + S[-c0+c1-736+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][735+c0] + S[735+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1263; c0 += 1)
    S[c0][c0+736] = MAX(S[c0][c0+736], S[c0+1][c0+736-1] + can_pair(RNA, c0, c0+736));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1262; c0 += 1)
    for (c1 = c0 + 737; c1 <= min(c0 + 1473, 1999); c1 += 1) {
      if (c0 + 1472 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-737+c0] + S[-c0+c1-737+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][736+c0] + S[736+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1262; c0 += 1)
    S[c0][c0+737] = MAX(S[c0][c0+737], S[c0+1][c0+737-1] + can_pair(RNA, c0, c0+737));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1261; c0 += 1)
    for (c1 = c0 + 738; c1 <= min(c0 + 1475, 1999); c1 += 1) {
      if (c0 + 1474 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-738+c0] + S[-c0+c1-738+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][737+c0] + S[737+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1261; c0 += 1)
    S[c0][c0+738] = MAX(S[c0][c0+738], S[c0+1][c0+738-1] + can_pair(RNA, c0, c0+738));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1260; c0 += 1)
    for (c1 = c0 + 739; c1 <= min(c0 + 1477, 1999); c1 += 1) {
      if (c0 + 1476 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-739+c0] + S[-c0+c1-739+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][738+c0] + S[738+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1260; c0 += 1)
    S[c0][c0+739] = MAX(S[c0][c0+739], S[c0+1][c0+739-1] + can_pair(RNA, c0, c0+739));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1259; c0 += 1)
    for (c1 = c0 + 740; c1 <= min(c0 + 1479, 1999); c1 += 1) {
      if (c0 + 1478 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-740+c0] + S[-c0+c1-740+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][739+c0] + S[739+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1259; c0 += 1)
    S[c0][c0+740] = MAX(S[c0][c0+740], S[c0+1][c0+740-1] + can_pair(RNA, c0, c0+740));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1258; c0 += 1)
    for (c1 = c0 + 741; c1 <= min(c0 + 1481, 1999); c1 += 1) {
      if (c0 + 1480 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-741+c0] + S[-c0+c1-741+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][740+c0] + S[740+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1258; c0 += 1)
    S[c0][c0+741] = MAX(S[c0][c0+741], S[c0+1][c0+741-1] + can_pair(RNA, c0, c0+741));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1257; c0 += 1)
    for (c1 = c0 + 742; c1 <= min(c0 + 1483, 1999); c1 += 1) {
      if (c0 + 1482 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-742+c0] + S[-c0+c1-742+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][741+c0] + S[741+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1257; c0 += 1)
    S[c0][c0+742] = MAX(S[c0][c0+742], S[c0+1][c0+742-1] + can_pair(RNA, c0, c0+742));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1256; c0 += 1)
    for (c1 = c0 + 743; c1 <= min(c0 + 1485, 1999); c1 += 1) {
      if (c0 + 1484 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-743+c0] + S[-c0+c1-743+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][742+c0] + S[742+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1256; c0 += 1)
    S[c0][c0+743] = MAX(S[c0][c0+743], S[c0+1][c0+743-1] + can_pair(RNA, c0, c0+743));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1255; c0 += 1)
    for (c1 = c0 + 744; c1 <= min(c0 + 1487, 1999); c1 += 1) {
      if (c0 + 1486 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-744+c0] + S[-c0+c1-744+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][743+c0] + S[743+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1255; c0 += 1)
    S[c0][c0+744] = MAX(S[c0][c0+744], S[c0+1][c0+744-1] + can_pair(RNA, c0, c0+744));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1254; c0 += 1)
    for (c1 = c0 + 745; c1 <= min(c0 + 1489, 1999); c1 += 1) {
      if (c0 + 1488 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-745+c0] + S[-c0+c1-745+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][744+c0] + S[744+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1254; c0 += 1)
    S[c0][c0+745] = MAX(S[c0][c0+745], S[c0+1][c0+745-1] + can_pair(RNA, c0, c0+745));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1253; c0 += 1)
    for (c1 = c0 + 746; c1 <= min(c0 + 1491, 1999); c1 += 1) {
      if (c0 + 1490 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-746+c0] + S[-c0+c1-746+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][745+c0] + S[745+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1253; c0 += 1)
    S[c0][c0+746] = MAX(S[c0][c0+746], S[c0+1][c0+746-1] + can_pair(RNA, c0, c0+746));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1252; c0 += 1)
    for (c1 = c0 + 747; c1 <= min(c0 + 1493, 1999); c1 += 1) {
      if (c0 + 1492 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-747+c0] + S[-c0+c1-747+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][746+c0] + S[746+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1252; c0 += 1)
    S[c0][c0+747] = MAX(S[c0][c0+747], S[c0+1][c0+747-1] + can_pair(RNA, c0, c0+747));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1251; c0 += 1)
    for (c1 = c0 + 748; c1 <= min(c0 + 1495, 1999); c1 += 1) {
      if (c0 + 1494 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-748+c0] + S[-c0+c1-748+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][747+c0] + S[747+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1251; c0 += 1)
    S[c0][c0+748] = MAX(S[c0][c0+748], S[c0+1][c0+748-1] + can_pair(RNA, c0, c0+748));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1250; c0 += 1)
    for (c1 = c0 + 749; c1 <= min(c0 + 1497, 1999); c1 += 1) {
      if (c0 + 1496 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-749+c0] + S[-c0+c1-749+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][748+c0] + S[748+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1250; c0 += 1)
    S[c0][c0+749] = MAX(S[c0][c0+749], S[c0+1][c0+749-1] + can_pair(RNA, c0, c0+749));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1249; c0 += 1)
    for (c1 = c0 + 750; c1 <= min(c0 + 1499, 1999); c1 += 1) {
      if (c0 + 1498 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-750+c0] + S[-c0+c1-750+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][749+c0] + S[749+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1249; c0 += 1)
    S[c0][c0+750] = MAX(S[c0][c0+750], S[c0+1][c0+750-1] + can_pair(RNA, c0, c0+750));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1248; c0 += 1)
    for (c1 = c0 + 751; c1 <= min(c0 + 1501, 1999); c1 += 1) {
      if (c0 + 1500 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-751+c0] + S[-c0+c1-751+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][750+c0] + S[750+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1248; c0 += 1)
    S[c0][c0+751] = MAX(S[c0][c0+751], S[c0+1][c0+751-1] + can_pair(RNA, c0, c0+751));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1247; c0 += 1)
    for (c1 = c0 + 752; c1 <= min(c0 + 1503, 1999); c1 += 1) {
      if (c0 + 1502 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-752+c0] + S[-c0+c1-752+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][751+c0] + S[751+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1247; c0 += 1)
    S[c0][c0+752] = MAX(S[c0][c0+752], S[c0+1][c0+752-1] + can_pair(RNA, c0, c0+752));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1246; c0 += 1)
    for (c1 = c0 + 753; c1 <= min(c0 + 1505, 1999); c1 += 1) {
      if (c0 + 1504 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-753+c0] + S[-c0+c1-753+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][752+c0] + S[752+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1246; c0 += 1)
    S[c0][c0+753] = MAX(S[c0][c0+753], S[c0+1][c0+753-1] + can_pair(RNA, c0, c0+753));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1245; c0 += 1)
    for (c1 = c0 + 754; c1 <= min(c0 + 1507, 1999); c1 += 1) {
      if (c0 + 1506 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-754+c0] + S[-c0+c1-754+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][753+c0] + S[753+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1245; c0 += 1)
    S[c0][c0+754] = MAX(S[c0][c0+754], S[c0+1][c0+754-1] + can_pair(RNA, c0, c0+754));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1244; c0 += 1)
    for (c1 = c0 + 755; c1 <= min(c0 + 1509, 1999); c1 += 1) {
      if (c0 + 1508 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-755+c0] + S[-c0+c1-755+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][754+c0] + S[754+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1244; c0 += 1)
    S[c0][c0+755] = MAX(S[c0][c0+755], S[c0+1][c0+755-1] + can_pair(RNA, c0, c0+755));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1243; c0 += 1)
    for (c1 = c0 + 756; c1 <= min(c0 + 1511, 1999); c1 += 1) {
      if (c0 + 1510 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-756+c0] + S[-c0+c1-756+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][755+c0] + S[755+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1243; c0 += 1)
    S[c0][c0+756] = MAX(S[c0][c0+756], S[c0+1][c0+756-1] + can_pair(RNA, c0, c0+756));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1242; c0 += 1)
    for (c1 = c0 + 757; c1 <= min(c0 + 1513, 1999); c1 += 1) {
      if (c0 + 1512 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-757+c0] + S[-c0+c1-757+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][756+c0] + S[756+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1242; c0 += 1)
    S[c0][c0+757] = MAX(S[c0][c0+757], S[c0+1][c0+757-1] + can_pair(RNA, c0, c0+757));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1241; c0 += 1)
    for (c1 = c0 + 758; c1 <= min(c0 + 1515, 1999); c1 += 1) {
      if (c0 + 1514 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-758+c0] + S[-c0+c1-758+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][757+c0] + S[757+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1241; c0 += 1)
    S[c0][c0+758] = MAX(S[c0][c0+758], S[c0+1][c0+758-1] + can_pair(RNA, c0, c0+758));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1240; c0 += 1)
    for (c1 = c0 + 759; c1 <= min(c0 + 1517, 1999); c1 += 1) {
      if (c0 + 1516 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-759+c0] + S[-c0+c1-759+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][758+c0] + S[758+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1240; c0 += 1)
    S[c0][c0+759] = MAX(S[c0][c0+759], S[c0+1][c0+759-1] + can_pair(RNA, c0, c0+759));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1239; c0 += 1)
    for (c1 = c0 + 760; c1 <= min(c0 + 1519, 1999); c1 += 1) {
      if (c0 + 1518 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-760+c0] + S[-c0+c1-760+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][759+c0] + S[759+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1239; c0 += 1)
    S[c0][c0+760] = MAX(S[c0][c0+760], S[c0+1][c0+760-1] + can_pair(RNA, c0, c0+760));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1238; c0 += 1)
    for (c1 = c0 + 761; c1 <= min(c0 + 1521, 1999); c1 += 1) {
      if (c0 + 1520 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-761+c0] + S[-c0+c1-761+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][760+c0] + S[760+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1238; c0 += 1)
    S[c0][c0+761] = MAX(S[c0][c0+761], S[c0+1][c0+761-1] + can_pair(RNA, c0, c0+761));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1237; c0 += 1)
    for (c1 = c0 + 762; c1 <= min(c0 + 1523, 1999); c1 += 1) {
      if (c0 + 1522 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-762+c0] + S[-c0+c1-762+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][761+c0] + S[761+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1237; c0 += 1)
    S[c0][c0+762] = MAX(S[c0][c0+762], S[c0+1][c0+762-1] + can_pair(RNA, c0, c0+762));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1236; c0 += 1)
    for (c1 = c0 + 763; c1 <= min(c0 + 1525, 1999); c1 += 1) {
      if (c0 + 1524 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-763+c0] + S[-c0+c1-763+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][762+c0] + S[762+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1236; c0 += 1)
    S[c0][c0+763] = MAX(S[c0][c0+763], S[c0+1][c0+763-1] + can_pair(RNA, c0, c0+763));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1235; c0 += 1)
    for (c1 = c0 + 764; c1 <= min(c0 + 1527, 1999); c1 += 1) {
      if (c0 + 1526 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-764+c0] + S[-c0+c1-764+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][763+c0] + S[763+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1235; c0 += 1)
    S[c0][c0+764] = MAX(S[c0][c0+764], S[c0+1][c0+764-1] + can_pair(RNA, c0, c0+764));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1234; c0 += 1)
    for (c1 = c0 + 765; c1 <= min(c0 + 1529, 1999); c1 += 1) {
      if (c0 + 1528 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-765+c0] + S[-c0+c1-765+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][764+c0] + S[764+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1234; c0 += 1)
    S[c0][c0+765] = MAX(S[c0][c0+765], S[c0+1][c0+765-1] + can_pair(RNA, c0, c0+765));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1233; c0 += 1)
    for (c1 = c0 + 766; c1 <= min(c0 + 1531, 1999); c1 += 1) {
      if (c0 + 1530 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-766+c0] + S[-c0+c1-766+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][765+c0] + S[765+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1233; c0 += 1)
    S[c0][c0+766] = MAX(S[c0][c0+766], S[c0+1][c0+766-1] + can_pair(RNA, c0, c0+766));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1232; c0 += 1)
    for (c1 = c0 + 767; c1 <= min(c0 + 1533, 1999); c1 += 1) {
      if (c0 + 1532 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-767+c0] + S[-c0+c1-767+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][766+c0] + S[766+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1232; c0 += 1)
    S[c0][c0+767] = MAX(S[c0][c0+767], S[c0+1][c0+767-1] + can_pair(RNA, c0, c0+767));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1231; c0 += 1)
    for (c1 = c0 + 768; c1 <= min(c0 + 1535, 1999); c1 += 1) {
      if (c0 + 1534 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-768+c0] + S[-c0+c1-768+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][767+c0] + S[767+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1231; c0 += 1)
    S[c0][c0+768] = MAX(S[c0][c0+768], S[c0+1][c0+768-1] + can_pair(RNA, c0, c0+768));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1230; c0 += 1)
    for (c1 = c0 + 769; c1 <= min(c0 + 1537, 1999); c1 += 1) {
      if (c0 + 1536 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-769+c0] + S[-c0+c1-769+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][768+c0] + S[768+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1230; c0 += 1)
    S[c0][c0+769] = MAX(S[c0][c0+769], S[c0+1][c0+769-1] + can_pair(RNA, c0, c0+769));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1229; c0 += 1)
    for (c1 = c0 + 770; c1 <= min(c0 + 1539, 1999); c1 += 1) {
      if (c0 + 1538 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-770+c0] + S[-c0+c1-770+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][769+c0] + S[769+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1229; c0 += 1)
    S[c0][c0+770] = MAX(S[c0][c0+770], S[c0+1][c0+770-1] + can_pair(RNA, c0, c0+770));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1228; c0 += 1)
    for (c1 = c0 + 771; c1 <= min(c0 + 1541, 1999); c1 += 1) {
      if (c0 + 1540 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-771+c0] + S[-c0+c1-771+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][770+c0] + S[770+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1228; c0 += 1)
    S[c0][c0+771] = MAX(S[c0][c0+771], S[c0+1][c0+771-1] + can_pair(RNA, c0, c0+771));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1227; c0 += 1)
    for (c1 = c0 + 772; c1 <= min(c0 + 1543, 1999); c1 += 1) {
      if (c0 + 1542 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-772+c0] + S[-c0+c1-772+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][771+c0] + S[771+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1227; c0 += 1)
    S[c0][c0+772] = MAX(S[c0][c0+772], S[c0+1][c0+772-1] + can_pair(RNA, c0, c0+772));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1226; c0 += 1)
    for (c1 = c0 + 773; c1 <= min(c0 + 1545, 1999); c1 += 1) {
      if (c0 + 1544 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-773+c0] + S[-c0+c1-773+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][772+c0] + S[772+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1226; c0 += 1)
    S[c0][c0+773] = MAX(S[c0][c0+773], S[c0+1][c0+773-1] + can_pair(RNA, c0, c0+773));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1225; c0 += 1)
    for (c1 = c0 + 774; c1 <= min(c0 + 1547, 1999); c1 += 1) {
      if (c0 + 1546 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-774+c0] + S[-c0+c1-774+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][773+c0] + S[773+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1225; c0 += 1)
    S[c0][c0+774] = MAX(S[c0][c0+774], S[c0+1][c0+774-1] + can_pair(RNA, c0, c0+774));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1224; c0 += 1)
    for (c1 = c0 + 775; c1 <= min(c0 + 1549, 1999); c1 += 1) {
      if (c0 + 1548 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-775+c0] + S[-c0+c1-775+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][774+c0] + S[774+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1224; c0 += 1)
    S[c0][c0+775] = MAX(S[c0][c0+775], S[c0+1][c0+775-1] + can_pair(RNA, c0, c0+775));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1223; c0 += 1)
    for (c1 = c0 + 776; c1 <= min(c0 + 1551, 1999); c1 += 1) {
      if (c0 + 1550 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-776+c0] + S[-c0+c1-776+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][775+c0] + S[775+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1223; c0 += 1)
    S[c0][c0+776] = MAX(S[c0][c0+776], S[c0+1][c0+776-1] + can_pair(RNA, c0, c0+776));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1222; c0 += 1)
    for (c1 = c0 + 777; c1 <= min(c0 + 1553, 1999); c1 += 1) {
      if (c0 + 1552 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-777+c0] + S[-c0+c1-777+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][776+c0] + S[776+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1222; c0 += 1)
    S[c0][c0+777] = MAX(S[c0][c0+777], S[c0+1][c0+777-1] + can_pair(RNA, c0, c0+777));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1221; c0 += 1)
    for (c1 = c0 + 778; c1 <= min(c0 + 1555, 1999); c1 += 1) {
      if (c0 + 1554 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-778+c0] + S[-c0+c1-778+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][777+c0] + S[777+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1221; c0 += 1)
    S[c0][c0+778] = MAX(S[c0][c0+778], S[c0+1][c0+778-1] + can_pair(RNA, c0, c0+778));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1220; c0 += 1)
    for (c1 = c0 + 779; c1 <= min(c0 + 1557, 1999); c1 += 1) {
      if (c0 + 1556 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-779+c0] + S[-c0+c1-779+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][778+c0] + S[778+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1220; c0 += 1)
    S[c0][c0+779] = MAX(S[c0][c0+779], S[c0+1][c0+779-1] + can_pair(RNA, c0, c0+779));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1219; c0 += 1)
    for (c1 = c0 + 780; c1 <= min(c0 + 1559, 1999); c1 += 1) {
      if (c0 + 1558 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-780+c0] + S[-c0+c1-780+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][779+c0] + S[779+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1219; c0 += 1)
    S[c0][c0+780] = MAX(S[c0][c0+780], S[c0+1][c0+780-1] + can_pair(RNA, c0, c0+780));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1218; c0 += 1)
    for (c1 = c0 + 781; c1 <= min(c0 + 1561, 1999); c1 += 1) {
      if (c0 + 1560 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-781+c0] + S[-c0+c1-781+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][780+c0] + S[780+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1218; c0 += 1)
    S[c0][c0+781] = MAX(S[c0][c0+781], S[c0+1][c0+781-1] + can_pair(RNA, c0, c0+781));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1217; c0 += 1)
    for (c1 = c0 + 782; c1 <= min(c0 + 1563, 1999); c1 += 1) {
      if (c0 + 1562 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-782+c0] + S[-c0+c1-782+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][781+c0] + S[781+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1217; c0 += 1)
    S[c0][c0+782] = MAX(S[c0][c0+782], S[c0+1][c0+782-1] + can_pair(RNA, c0, c0+782));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1216; c0 += 1)
    for (c1 = c0 + 783; c1 <= min(c0 + 1565, 1999); c1 += 1) {
      if (c0 + 1564 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-783+c0] + S[-c0+c1-783+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][782+c0] + S[782+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1216; c0 += 1)
    S[c0][c0+783] = MAX(S[c0][c0+783], S[c0+1][c0+783-1] + can_pair(RNA, c0, c0+783));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1215; c0 += 1)
    for (c1 = c0 + 784; c1 <= min(c0 + 1567, 1999); c1 += 1) {
      if (c0 + 1566 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-784+c0] + S[-c0+c1-784+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][783+c0] + S[783+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1215; c0 += 1)
    S[c0][c0+784] = MAX(S[c0][c0+784], S[c0+1][c0+784-1] + can_pair(RNA, c0, c0+784));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1214; c0 += 1)
    for (c1 = c0 + 785; c1 <= min(c0 + 1569, 1999); c1 += 1) {
      if (c0 + 1568 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-785+c0] + S[-c0+c1-785+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][784+c0] + S[784+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1214; c0 += 1)
    S[c0][c0+785] = MAX(S[c0][c0+785], S[c0+1][c0+785-1] + can_pair(RNA, c0, c0+785));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1213; c0 += 1)
    for (c1 = c0 + 786; c1 <= min(c0 + 1571, 1999); c1 += 1) {
      if (c0 + 1570 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-786+c0] + S[-c0+c1-786+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][785+c0] + S[785+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1213; c0 += 1)
    S[c0][c0+786] = MAX(S[c0][c0+786], S[c0+1][c0+786-1] + can_pair(RNA, c0, c0+786));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1212; c0 += 1)
    for (c1 = c0 + 787; c1 <= min(c0 + 1573, 1999); c1 += 1) {
      if (c0 + 1572 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-787+c0] + S[-c0+c1-787+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][786+c0] + S[786+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1212; c0 += 1)
    S[c0][c0+787] = MAX(S[c0][c0+787], S[c0+1][c0+787-1] + can_pair(RNA, c0, c0+787));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1211; c0 += 1)
    for (c1 = c0 + 788; c1 <= min(c0 + 1575, 1999); c1 += 1) {
      if (c0 + 1574 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-788+c0] + S[-c0+c1-788+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][787+c0] + S[787+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1211; c0 += 1)
    S[c0][c0+788] = MAX(S[c0][c0+788], S[c0+1][c0+788-1] + can_pair(RNA, c0, c0+788));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1210; c0 += 1)
    for (c1 = c0 + 789; c1 <= min(c0 + 1577, 1999); c1 += 1) {
      if (c0 + 1576 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-789+c0] + S[-c0+c1-789+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][788+c0] + S[788+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1210; c0 += 1)
    S[c0][c0+789] = MAX(S[c0][c0+789], S[c0+1][c0+789-1] + can_pair(RNA, c0, c0+789));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1209; c0 += 1)
    for (c1 = c0 + 790; c1 <= min(c0 + 1579, 1999); c1 += 1) {
      if (c0 + 1578 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-790+c0] + S[-c0+c1-790+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][789+c0] + S[789+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1209; c0 += 1)
    S[c0][c0+790] = MAX(S[c0][c0+790], S[c0+1][c0+790-1] + can_pair(RNA, c0, c0+790));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1208; c0 += 1)
    for (c1 = c0 + 791; c1 <= min(c0 + 1581, 1999); c1 += 1) {
      if (c0 + 1580 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-791+c0] + S[-c0+c1-791+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][790+c0] + S[790+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1208; c0 += 1)
    S[c0][c0+791] = MAX(S[c0][c0+791], S[c0+1][c0+791-1] + can_pair(RNA, c0, c0+791));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1207; c0 += 1)
    for (c1 = c0 + 792; c1 <= min(c0 + 1583, 1999); c1 += 1) {
      if (c0 + 1582 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-792+c0] + S[-c0+c1-792+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][791+c0] + S[791+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1207; c0 += 1)
    S[c0][c0+792] = MAX(S[c0][c0+792], S[c0+1][c0+792-1] + can_pair(RNA, c0, c0+792));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1206; c0 += 1)
    for (c1 = c0 + 793; c1 <= min(c0 + 1585, 1999); c1 += 1) {
      if (c0 + 1584 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-793+c0] + S[-c0+c1-793+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][792+c0] + S[792+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1206; c0 += 1)
    S[c0][c0+793] = MAX(S[c0][c0+793], S[c0+1][c0+793-1] + can_pair(RNA, c0, c0+793));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1205; c0 += 1)
    for (c1 = c0 + 794; c1 <= min(c0 + 1587, 1999); c1 += 1) {
      if (c0 + 1586 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-794+c0] + S[-c0+c1-794+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][793+c0] + S[793+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1205; c0 += 1)
    S[c0][c0+794] = MAX(S[c0][c0+794], S[c0+1][c0+794-1] + can_pair(RNA, c0, c0+794));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1204; c0 += 1)
    for (c1 = c0 + 795; c1 <= min(c0 + 1589, 1999); c1 += 1) {
      if (c0 + 1588 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-795+c0] + S[-c0+c1-795+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][794+c0] + S[794+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1204; c0 += 1)
    S[c0][c0+795] = MAX(S[c0][c0+795], S[c0+1][c0+795-1] + can_pair(RNA, c0, c0+795));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1203; c0 += 1)
    for (c1 = c0 + 796; c1 <= min(c0 + 1591, 1999); c1 += 1) {
      if (c0 + 1590 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-796+c0] + S[-c0+c1-796+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][795+c0] + S[795+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1203; c0 += 1)
    S[c0][c0+796] = MAX(S[c0][c0+796], S[c0+1][c0+796-1] + can_pair(RNA, c0, c0+796));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1202; c0 += 1)
    for (c1 = c0 + 797; c1 <= min(c0 + 1593, 1999); c1 += 1) {
      if (c0 + 1592 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-797+c0] + S[-c0+c1-797+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][796+c0] + S[796+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1202; c0 += 1)
    S[c0][c0+797] = MAX(S[c0][c0+797], S[c0+1][c0+797-1] + can_pair(RNA, c0, c0+797));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1201; c0 += 1)
    for (c1 = c0 + 798; c1 <= min(c0 + 1595, 1999); c1 += 1) {
      if (c0 + 1594 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-798+c0] + S[-c0+c1-798+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][797+c0] + S[797+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1201; c0 += 1)
    S[c0][c0+798] = MAX(S[c0][c0+798], S[c0+1][c0+798-1] + can_pair(RNA, c0, c0+798));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1200; c0 += 1)
    for (c1 = c0 + 799; c1 <= min(c0 + 1597, 1999); c1 += 1) {
      if (c0 + 1596 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-799+c0] + S[-c0+c1-799+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][798+c0] + S[798+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1200; c0 += 1)
    S[c0][c0+799] = MAX(S[c0][c0+799], S[c0+1][c0+799-1] + can_pair(RNA, c0, c0+799));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1199; c0 += 1)
    for (c1 = c0 + 800; c1 <= min(c0 + 1599, 1999); c1 += 1) {
      if (c0 + 1598 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-800+c0] + S[-c0+c1-800+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][799+c0] + S[799+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1199; c0 += 1)
    S[c0][c0+800] = MAX(S[c0][c0+800], S[c0+1][c0+800-1] + can_pair(RNA, c0, c0+800));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1198; c0 += 1)
    for (c1 = c0 + 801; c1 <= min(c0 + 1601, 1999); c1 += 1) {
      if (c0 + 1600 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-801+c0] + S[-c0+c1-801+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][800+c0] + S[800+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1198; c0 += 1)
    S[c0][c0+801] = MAX(S[c0][c0+801], S[c0+1][c0+801-1] + can_pair(RNA, c0, c0+801));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1197; c0 += 1)
    for (c1 = c0 + 802; c1 <= min(c0 + 1603, 1999); c1 += 1) {
      if (c0 + 1602 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-802+c0] + S[-c0+c1-802+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][801+c0] + S[801+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1197; c0 += 1)
    S[c0][c0+802] = MAX(S[c0][c0+802], S[c0+1][c0+802-1] + can_pair(RNA, c0, c0+802));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1196; c0 += 1)
    for (c1 = c0 + 803; c1 <= min(c0 + 1605, 1999); c1 += 1) {
      if (c0 + 1604 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-803+c0] + S[-c0+c1-803+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][802+c0] + S[802+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1196; c0 += 1)
    S[c0][c0+803] = MAX(S[c0][c0+803], S[c0+1][c0+803-1] + can_pair(RNA, c0, c0+803));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1195; c0 += 1)
    for (c1 = c0 + 804; c1 <= min(c0 + 1607, 1999); c1 += 1) {
      if (c0 + 1606 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-804+c0] + S[-c0+c1-804+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][803+c0] + S[803+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1195; c0 += 1)
    S[c0][c0+804] = MAX(S[c0][c0+804], S[c0+1][c0+804-1] + can_pair(RNA, c0, c0+804));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1194; c0 += 1)
    for (c1 = c0 + 805; c1 <= min(c0 + 1609, 1999); c1 += 1) {
      if (c0 + 1608 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-805+c0] + S[-c0+c1-805+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][804+c0] + S[804+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1194; c0 += 1)
    S[c0][c0+805] = MAX(S[c0][c0+805], S[c0+1][c0+805-1] + can_pair(RNA, c0, c0+805));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1193; c0 += 1)
    for (c1 = c0 + 806; c1 <= min(c0 + 1611, 1999); c1 += 1) {
      if (c0 + 1610 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-806+c0] + S[-c0+c1-806+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][805+c0] + S[805+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1193; c0 += 1)
    S[c0][c0+806] = MAX(S[c0][c0+806], S[c0+1][c0+806-1] + can_pair(RNA, c0, c0+806));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1192; c0 += 1)
    for (c1 = c0 + 807; c1 <= min(c0 + 1613, 1999); c1 += 1) {
      if (c0 + 1612 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-807+c0] + S[-c0+c1-807+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][806+c0] + S[806+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1192; c0 += 1)
    S[c0][c0+807] = MAX(S[c0][c0+807], S[c0+1][c0+807-1] + can_pair(RNA, c0, c0+807));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1191; c0 += 1)
    for (c1 = c0 + 808; c1 <= min(c0 + 1615, 1999); c1 += 1) {
      if (c0 + 1614 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-808+c0] + S[-c0+c1-808+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][807+c0] + S[807+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1191; c0 += 1)
    S[c0][c0+808] = MAX(S[c0][c0+808], S[c0+1][c0+808-1] + can_pair(RNA, c0, c0+808));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1190; c0 += 1)
    for (c1 = c0 + 809; c1 <= min(c0 + 1617, 1999); c1 += 1) {
      if (c0 + 1616 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-809+c0] + S[-c0+c1-809+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][808+c0] + S[808+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1190; c0 += 1)
    S[c0][c0+809] = MAX(S[c0][c0+809], S[c0+1][c0+809-1] + can_pair(RNA, c0, c0+809));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1189; c0 += 1)
    for (c1 = c0 + 810; c1 <= min(c0 + 1619, 1999); c1 += 1) {
      if (c0 + 1618 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-810+c0] + S[-c0+c1-810+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][809+c0] + S[809+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1189; c0 += 1)
    S[c0][c0+810] = MAX(S[c0][c0+810], S[c0+1][c0+810-1] + can_pair(RNA, c0, c0+810));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1188; c0 += 1)
    for (c1 = c0 + 811; c1 <= min(c0 + 1621, 1999); c1 += 1) {
      if (c0 + 1620 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-811+c0] + S[-c0+c1-811+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][810+c0] + S[810+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1188; c0 += 1)
    S[c0][c0+811] = MAX(S[c0][c0+811], S[c0+1][c0+811-1] + can_pair(RNA, c0, c0+811));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1187; c0 += 1)
    for (c1 = c0 + 812; c1 <= min(c0 + 1623, 1999); c1 += 1) {
      if (c0 + 1622 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-812+c0] + S[-c0+c1-812+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][811+c0] + S[811+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1187; c0 += 1)
    S[c0][c0+812] = MAX(S[c0][c0+812], S[c0+1][c0+812-1] + can_pair(RNA, c0, c0+812));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1186; c0 += 1)
    for (c1 = c0 + 813; c1 <= min(c0 + 1625, 1999); c1 += 1) {
      if (c0 + 1624 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-813+c0] + S[-c0+c1-813+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][812+c0] + S[812+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1186; c0 += 1)
    S[c0][c0+813] = MAX(S[c0][c0+813], S[c0+1][c0+813-1] + can_pair(RNA, c0, c0+813));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1185; c0 += 1)
    for (c1 = c0 + 814; c1 <= min(c0 + 1627, 1999); c1 += 1) {
      if (c0 + 1626 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-814+c0] + S[-c0+c1-814+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][813+c0] + S[813+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1185; c0 += 1)
    S[c0][c0+814] = MAX(S[c0][c0+814], S[c0+1][c0+814-1] + can_pair(RNA, c0, c0+814));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1184; c0 += 1)
    for (c1 = c0 + 815; c1 <= min(c0 + 1629, 1999); c1 += 1) {
      if (c0 + 1628 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-815+c0] + S[-c0+c1-815+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][814+c0] + S[814+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1184; c0 += 1)
    S[c0][c0+815] = MAX(S[c0][c0+815], S[c0+1][c0+815-1] + can_pair(RNA, c0, c0+815));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1183; c0 += 1)
    for (c1 = c0 + 816; c1 <= min(c0 + 1631, 1999); c1 += 1) {
      if (c0 + 1630 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-816+c0] + S[-c0+c1-816+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][815+c0] + S[815+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1183; c0 += 1)
    S[c0][c0+816] = MAX(S[c0][c0+816], S[c0+1][c0+816-1] + can_pair(RNA, c0, c0+816));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1182; c0 += 1)
    for (c1 = c0 + 817; c1 <= min(c0 + 1633, 1999); c1 += 1) {
      if (c0 + 1632 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-817+c0] + S[-c0+c1-817+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][816+c0] + S[816+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1182; c0 += 1)
    S[c0][c0+817] = MAX(S[c0][c0+817], S[c0+1][c0+817-1] + can_pair(RNA, c0, c0+817));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1181; c0 += 1)
    for (c1 = c0 + 818; c1 <= min(c0 + 1635, 1999); c1 += 1) {
      if (c0 + 1634 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-818+c0] + S[-c0+c1-818+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][817+c0] + S[817+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1181; c0 += 1)
    S[c0][c0+818] = MAX(S[c0][c0+818], S[c0+1][c0+818-1] + can_pair(RNA, c0, c0+818));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1180; c0 += 1)
    for (c1 = c0 + 819; c1 <= min(c0 + 1637, 1999); c1 += 1) {
      if (c0 + 1636 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-819+c0] + S[-c0+c1-819+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][818+c0] + S[818+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1180; c0 += 1)
    S[c0][c0+819] = MAX(S[c0][c0+819], S[c0+1][c0+819-1] + can_pair(RNA, c0, c0+819));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1179; c0 += 1)
    for (c1 = c0 + 820; c1 <= min(c0 + 1639, 1999); c1 += 1) {
      if (c0 + 1638 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-820+c0] + S[-c0+c1-820+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][819+c0] + S[819+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1179; c0 += 1)
    S[c0][c0+820] = MAX(S[c0][c0+820], S[c0+1][c0+820-1] + can_pair(RNA, c0, c0+820));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1178; c0 += 1)
    for (c1 = c0 + 821; c1 <= min(c0 + 1641, 1999); c1 += 1) {
      if (c0 + 1640 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-821+c0] + S[-c0+c1-821+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][820+c0] + S[820+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1178; c0 += 1)
    S[c0][c0+821] = MAX(S[c0][c0+821], S[c0+1][c0+821-1] + can_pair(RNA, c0, c0+821));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1177; c0 += 1)
    for (c1 = c0 + 822; c1 <= min(c0 + 1643, 1999); c1 += 1) {
      if (c0 + 1642 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-822+c0] + S[-c0+c1-822+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][821+c0] + S[821+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1177; c0 += 1)
    S[c0][c0+822] = MAX(S[c0][c0+822], S[c0+1][c0+822-1] + can_pair(RNA, c0, c0+822));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1176; c0 += 1)
    for (c1 = c0 + 823; c1 <= min(c0 + 1645, 1999); c1 += 1) {
      if (c0 + 1644 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-823+c0] + S[-c0+c1-823+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][822+c0] + S[822+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1176; c0 += 1)
    S[c0][c0+823] = MAX(S[c0][c0+823], S[c0+1][c0+823-1] + can_pair(RNA, c0, c0+823));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1175; c0 += 1)
    for (c1 = c0 + 824; c1 <= min(c0 + 1647, 1999); c1 += 1) {
      if (c0 + 1646 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-824+c0] + S[-c0+c1-824+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][823+c0] + S[823+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1175; c0 += 1)
    S[c0][c0+824] = MAX(S[c0][c0+824], S[c0+1][c0+824-1] + can_pair(RNA, c0, c0+824));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1174; c0 += 1)
    for (c1 = c0 + 825; c1 <= min(c0 + 1649, 1999); c1 += 1) {
      if (c0 + 1648 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-825+c0] + S[-c0+c1-825+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][824+c0] + S[824+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1174; c0 += 1)
    S[c0][c0+825] = MAX(S[c0][c0+825], S[c0+1][c0+825-1] + can_pair(RNA, c0, c0+825));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1173; c0 += 1)
    for (c1 = c0 + 826; c1 <= min(c0 + 1651, 1999); c1 += 1) {
      if (c0 + 1650 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-826+c0] + S[-c0+c1-826+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][825+c0] + S[825+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1173; c0 += 1)
    S[c0][c0+826] = MAX(S[c0][c0+826], S[c0+1][c0+826-1] + can_pair(RNA, c0, c0+826));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1172; c0 += 1)
    for (c1 = c0 + 827; c1 <= min(c0 + 1653, 1999); c1 += 1) {
      if (c0 + 1652 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-827+c0] + S[-c0+c1-827+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][826+c0] + S[826+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1172; c0 += 1)
    S[c0][c0+827] = MAX(S[c0][c0+827], S[c0+1][c0+827-1] + can_pair(RNA, c0, c0+827));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1171; c0 += 1)
    for (c1 = c0 + 828; c1 <= min(c0 + 1655, 1999); c1 += 1) {
      if (c0 + 1654 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-828+c0] + S[-c0+c1-828+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][827+c0] + S[827+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1171; c0 += 1)
    S[c0][c0+828] = MAX(S[c0][c0+828], S[c0+1][c0+828-1] + can_pair(RNA, c0, c0+828));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1170; c0 += 1)
    for (c1 = c0 + 829; c1 <= min(c0 + 1657, 1999); c1 += 1) {
      if (c0 + 1656 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-829+c0] + S[-c0+c1-829+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][828+c0] + S[828+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1170; c0 += 1)
    S[c0][c0+829] = MAX(S[c0][c0+829], S[c0+1][c0+829-1] + can_pair(RNA, c0, c0+829));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1169; c0 += 1)
    for (c1 = c0 + 830; c1 <= min(c0 + 1659, 1999); c1 += 1) {
      if (c0 + 1658 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-830+c0] + S[-c0+c1-830+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][829+c0] + S[829+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1169; c0 += 1)
    S[c0][c0+830] = MAX(S[c0][c0+830], S[c0+1][c0+830-1] + can_pair(RNA, c0, c0+830));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1168; c0 += 1)
    for (c1 = c0 + 831; c1 <= min(c0 + 1661, 1999); c1 += 1) {
      if (c0 + 1660 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-831+c0] + S[-c0+c1-831+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][830+c0] + S[830+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1168; c0 += 1)
    S[c0][c0+831] = MAX(S[c0][c0+831], S[c0+1][c0+831-1] + can_pair(RNA, c0, c0+831));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1167; c0 += 1)
    for (c1 = c0 + 832; c1 <= min(c0 + 1663, 1999); c1 += 1) {
      if (c0 + 1662 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-832+c0] + S[-c0+c1-832+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][831+c0] + S[831+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1167; c0 += 1)
    S[c0][c0+832] = MAX(S[c0][c0+832], S[c0+1][c0+832-1] + can_pair(RNA, c0, c0+832));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1166; c0 += 1)
    for (c1 = c0 + 833; c1 <= min(c0 + 1665, 1999); c1 += 1) {
      if (c0 + 1664 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-833+c0] + S[-c0+c1-833+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][832+c0] + S[832+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1166; c0 += 1)
    S[c0][c0+833] = MAX(S[c0][c0+833], S[c0+1][c0+833-1] + can_pair(RNA, c0, c0+833));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1165; c0 += 1)
    for (c1 = c0 + 834; c1 <= min(c0 + 1667, 1999); c1 += 1) {
      if (c0 + 1666 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-834+c0] + S[-c0+c1-834+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][833+c0] + S[833+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1165; c0 += 1)
    S[c0][c0+834] = MAX(S[c0][c0+834], S[c0+1][c0+834-1] + can_pair(RNA, c0, c0+834));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1164; c0 += 1)
    for (c1 = c0 + 835; c1 <= min(c0 + 1669, 1999); c1 += 1) {
      if (c0 + 1668 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-835+c0] + S[-c0+c1-835+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][834+c0] + S[834+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1164; c0 += 1)
    S[c0][c0+835] = MAX(S[c0][c0+835], S[c0+1][c0+835-1] + can_pair(RNA, c0, c0+835));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1163; c0 += 1)
    for (c1 = c0 + 836; c1 <= min(c0 + 1671, 1999); c1 += 1) {
      if (c0 + 1670 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-836+c0] + S[-c0+c1-836+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][835+c0] + S[835+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1163; c0 += 1)
    S[c0][c0+836] = MAX(S[c0][c0+836], S[c0+1][c0+836-1] + can_pair(RNA, c0, c0+836));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1162; c0 += 1)
    for (c1 = c0 + 837; c1 <= min(c0 + 1673, 1999); c1 += 1) {
      if (c0 + 1672 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-837+c0] + S[-c0+c1-837+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][836+c0] + S[836+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1162; c0 += 1)
    S[c0][c0+837] = MAX(S[c0][c0+837], S[c0+1][c0+837-1] + can_pair(RNA, c0, c0+837));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1161; c0 += 1)
    for (c1 = c0 + 838; c1 <= min(c0 + 1675, 1999); c1 += 1) {
      if (c0 + 1674 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-838+c0] + S[-c0+c1-838+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][837+c0] + S[837+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1161; c0 += 1)
    S[c0][c0+838] = MAX(S[c0][c0+838], S[c0+1][c0+838-1] + can_pair(RNA, c0, c0+838));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1160; c0 += 1)
    for (c1 = c0 + 839; c1 <= min(c0 + 1677, 1999); c1 += 1) {
      if (c0 + 1676 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-839+c0] + S[-c0+c1-839+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][838+c0] + S[838+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1160; c0 += 1)
    S[c0][c0+839] = MAX(S[c0][c0+839], S[c0+1][c0+839-1] + can_pair(RNA, c0, c0+839));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1159; c0 += 1)
    for (c1 = c0 + 840; c1 <= min(c0 + 1679, 1999); c1 += 1) {
      if (c0 + 1678 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-840+c0] + S[-c0+c1-840+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][839+c0] + S[839+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1159; c0 += 1)
    S[c0][c0+840] = MAX(S[c0][c0+840], S[c0+1][c0+840-1] + can_pair(RNA, c0, c0+840));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1158; c0 += 1)
    for (c1 = c0 + 841; c1 <= min(c0 + 1681, 1999); c1 += 1) {
      if (c0 + 1680 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-841+c0] + S[-c0+c1-841+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][840+c0] + S[840+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1158; c0 += 1)
    S[c0][c0+841] = MAX(S[c0][c0+841], S[c0+1][c0+841-1] + can_pair(RNA, c0, c0+841));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1157; c0 += 1)
    for (c1 = c0 + 842; c1 <= min(c0 + 1683, 1999); c1 += 1) {
      if (c0 + 1682 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-842+c0] + S[-c0+c1-842+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][841+c0] + S[841+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1157; c0 += 1)
    S[c0][c0+842] = MAX(S[c0][c0+842], S[c0+1][c0+842-1] + can_pair(RNA, c0, c0+842));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1156; c0 += 1)
    for (c1 = c0 + 843; c1 <= min(c0 + 1685, 1999); c1 += 1) {
      if (c0 + 1684 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-843+c0] + S[-c0+c1-843+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][842+c0] + S[842+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1156; c0 += 1)
    S[c0][c0+843] = MAX(S[c0][c0+843], S[c0+1][c0+843-1] + can_pair(RNA, c0, c0+843));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1155; c0 += 1)
    for (c1 = c0 + 844; c1 <= min(c0 + 1687, 1999); c1 += 1) {
      if (c0 + 1686 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-844+c0] + S[-c0+c1-844+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][843+c0] + S[843+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1155; c0 += 1)
    S[c0][c0+844] = MAX(S[c0][c0+844], S[c0+1][c0+844-1] + can_pair(RNA, c0, c0+844));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1154; c0 += 1)
    for (c1 = c0 + 845; c1 <= min(c0 + 1689, 1999); c1 += 1) {
      if (c0 + 1688 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-845+c0] + S[-c0+c1-845+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][844+c0] + S[844+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1154; c0 += 1)
    S[c0][c0+845] = MAX(S[c0][c0+845], S[c0+1][c0+845-1] + can_pair(RNA, c0, c0+845));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1153; c0 += 1)
    for (c1 = c0 + 846; c1 <= min(c0 + 1691, 1999); c1 += 1) {
      if (c0 + 1690 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-846+c0] + S[-c0+c1-846+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][845+c0] + S[845+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1153; c0 += 1)
    S[c0][c0+846] = MAX(S[c0][c0+846], S[c0+1][c0+846-1] + can_pair(RNA, c0, c0+846));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1152; c0 += 1)
    for (c1 = c0 + 847; c1 <= min(c0 + 1693, 1999); c1 += 1) {
      if (c0 + 1692 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-847+c0] + S[-c0+c1-847+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][846+c0] + S[846+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1152; c0 += 1)
    S[c0][c0+847] = MAX(S[c0][c0+847], S[c0+1][c0+847-1] + can_pair(RNA, c0, c0+847));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1151; c0 += 1)
    for (c1 = c0 + 848; c1 <= min(c0 + 1695, 1999); c1 += 1) {
      if (c0 + 1694 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-848+c0] + S[-c0+c1-848+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][847+c0] + S[847+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1151; c0 += 1)
    S[c0][c0+848] = MAX(S[c0][c0+848], S[c0+1][c0+848-1] + can_pair(RNA, c0, c0+848));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1150; c0 += 1)
    for (c1 = c0 + 849; c1 <= min(c0 + 1697, 1999); c1 += 1) {
      if (c0 + 1696 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-849+c0] + S[-c0+c1-849+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][848+c0] + S[848+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1150; c0 += 1)
    S[c0][c0+849] = MAX(S[c0][c0+849], S[c0+1][c0+849-1] + can_pair(RNA, c0, c0+849));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1149; c0 += 1)
    for (c1 = c0 + 850; c1 <= min(c0 + 1699, 1999); c1 += 1) {
      if (c0 + 1698 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-850+c0] + S[-c0+c1-850+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][849+c0] + S[849+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1149; c0 += 1)
    S[c0][c0+850] = MAX(S[c0][c0+850], S[c0+1][c0+850-1] + can_pair(RNA, c0, c0+850));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1148; c0 += 1)
    for (c1 = c0 + 851; c1 <= min(c0 + 1701, 1999); c1 += 1) {
      if (c0 + 1700 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-851+c0] + S[-c0+c1-851+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][850+c0] + S[850+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1148; c0 += 1)
    S[c0][c0+851] = MAX(S[c0][c0+851], S[c0+1][c0+851-1] + can_pair(RNA, c0, c0+851));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1147; c0 += 1)
    for (c1 = c0 + 852; c1 <= min(c0 + 1703, 1999); c1 += 1) {
      if (c0 + 1702 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-852+c0] + S[-c0+c1-852+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][851+c0] + S[851+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1147; c0 += 1)
    S[c0][c0+852] = MAX(S[c0][c0+852], S[c0+1][c0+852-1] + can_pair(RNA, c0, c0+852));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1146; c0 += 1)
    for (c1 = c0 + 853; c1 <= min(c0 + 1705, 1999); c1 += 1) {
      if (c0 + 1704 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-853+c0] + S[-c0+c1-853+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][852+c0] + S[852+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1146; c0 += 1)
    S[c0][c0+853] = MAX(S[c0][c0+853], S[c0+1][c0+853-1] + can_pair(RNA, c0, c0+853));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1145; c0 += 1)
    for (c1 = c0 + 854; c1 <= min(c0 + 1707, 1999); c1 += 1) {
      if (c0 + 1706 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-854+c0] + S[-c0+c1-854+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][853+c0] + S[853+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1145; c0 += 1)
    S[c0][c0+854] = MAX(S[c0][c0+854], S[c0+1][c0+854-1] + can_pair(RNA, c0, c0+854));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1144; c0 += 1)
    for (c1 = c0 + 855; c1 <= min(c0 + 1709, 1999); c1 += 1) {
      if (c0 + 1708 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-855+c0] + S[-c0+c1-855+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][854+c0] + S[854+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1144; c0 += 1)
    S[c0][c0+855] = MAX(S[c0][c0+855], S[c0+1][c0+855-1] + can_pair(RNA, c0, c0+855));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1143; c0 += 1)
    for (c1 = c0 + 856; c1 <= min(c0 + 1711, 1999); c1 += 1) {
      if (c0 + 1710 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-856+c0] + S[-c0+c1-856+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][855+c0] + S[855+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1143; c0 += 1)
    S[c0][c0+856] = MAX(S[c0][c0+856], S[c0+1][c0+856-1] + can_pair(RNA, c0, c0+856));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1142; c0 += 1)
    for (c1 = c0 + 857; c1 <= min(c0 + 1713, 1999); c1 += 1) {
      if (c0 + 1712 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-857+c0] + S[-c0+c1-857+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][856+c0] + S[856+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1142; c0 += 1)
    S[c0][c0+857] = MAX(S[c0][c0+857], S[c0+1][c0+857-1] + can_pair(RNA, c0, c0+857));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1141; c0 += 1)
    for (c1 = c0 + 858; c1 <= min(c0 + 1715, 1999); c1 += 1) {
      if (c0 + 1714 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-858+c0] + S[-c0+c1-858+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][857+c0] + S[857+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1141; c0 += 1)
    S[c0][c0+858] = MAX(S[c0][c0+858], S[c0+1][c0+858-1] + can_pair(RNA, c0, c0+858));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1140; c0 += 1)
    for (c1 = c0 + 859; c1 <= min(c0 + 1717, 1999); c1 += 1) {
      if (c0 + 1716 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-859+c0] + S[-c0+c1-859+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][858+c0] + S[858+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1140; c0 += 1)
    S[c0][c0+859] = MAX(S[c0][c0+859], S[c0+1][c0+859-1] + can_pair(RNA, c0, c0+859));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1139; c0 += 1)
    for (c1 = c0 + 860; c1 <= min(c0 + 1719, 1999); c1 += 1) {
      if (c0 + 1718 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-860+c0] + S[-c0+c1-860+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][859+c0] + S[859+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1139; c0 += 1)
    S[c0][c0+860] = MAX(S[c0][c0+860], S[c0+1][c0+860-1] + can_pair(RNA, c0, c0+860));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1138; c0 += 1)
    for (c1 = c0 + 861; c1 <= min(c0 + 1721, 1999); c1 += 1) {
      if (c0 + 1720 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-861+c0] + S[-c0+c1-861+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][860+c0] + S[860+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1138; c0 += 1)
    S[c0][c0+861] = MAX(S[c0][c0+861], S[c0+1][c0+861-1] + can_pair(RNA, c0, c0+861));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1137; c0 += 1)
    for (c1 = c0 + 862; c1 <= min(c0 + 1723, 1999); c1 += 1) {
      if (c0 + 1722 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-862+c0] + S[-c0+c1-862+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][861+c0] + S[861+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1137; c0 += 1)
    S[c0][c0+862] = MAX(S[c0][c0+862], S[c0+1][c0+862-1] + can_pair(RNA, c0, c0+862));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1136; c0 += 1)
    for (c1 = c0 + 863; c1 <= min(c0 + 1725, 1999); c1 += 1) {
      if (c0 + 1724 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-863+c0] + S[-c0+c1-863+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][862+c0] + S[862+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1136; c0 += 1)
    S[c0][c0+863] = MAX(S[c0][c0+863], S[c0+1][c0+863-1] + can_pair(RNA, c0, c0+863));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1135; c0 += 1)
    for (c1 = c0 + 864; c1 <= min(c0 + 1727, 1999); c1 += 1) {
      if (c0 + 1726 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-864+c0] + S[-c0+c1-864+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][863+c0] + S[863+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1135; c0 += 1)
    S[c0][c0+864] = MAX(S[c0][c0+864], S[c0+1][c0+864-1] + can_pair(RNA, c0, c0+864));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1134; c0 += 1)
    for (c1 = c0 + 865; c1 <= min(c0 + 1729, 1999); c1 += 1) {
      if (c0 + 1728 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-865+c0] + S[-c0+c1-865+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][864+c0] + S[864+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1134; c0 += 1)
    S[c0][c0+865] = MAX(S[c0][c0+865], S[c0+1][c0+865-1] + can_pair(RNA, c0, c0+865));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1133; c0 += 1)
    for (c1 = c0 + 866; c1 <= min(c0 + 1731, 1999); c1 += 1) {
      if (c0 + 1730 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-866+c0] + S[-c0+c1-866+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][865+c0] + S[865+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1133; c0 += 1)
    S[c0][c0+866] = MAX(S[c0][c0+866], S[c0+1][c0+866-1] + can_pair(RNA, c0, c0+866));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1132; c0 += 1)
    for (c1 = c0 + 867; c1 <= min(c0 + 1733, 1999); c1 += 1) {
      if (c0 + 1732 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-867+c0] + S[-c0+c1-867+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][866+c0] + S[866+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1132; c0 += 1)
    S[c0][c0+867] = MAX(S[c0][c0+867], S[c0+1][c0+867-1] + can_pair(RNA, c0, c0+867));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1131; c0 += 1)
    for (c1 = c0 + 868; c1 <= min(c0 + 1735, 1999); c1 += 1) {
      if (c0 + 1734 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-868+c0] + S[-c0+c1-868+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][867+c0] + S[867+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1131; c0 += 1)
    S[c0][c0+868] = MAX(S[c0][c0+868], S[c0+1][c0+868-1] + can_pair(RNA, c0, c0+868));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1130; c0 += 1)
    for (c1 = c0 + 869; c1 <= min(c0 + 1737, 1999); c1 += 1) {
      if (c0 + 1736 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-869+c0] + S[-c0+c1-869+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][868+c0] + S[868+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1130; c0 += 1)
    S[c0][c0+869] = MAX(S[c0][c0+869], S[c0+1][c0+869-1] + can_pair(RNA, c0, c0+869));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1129; c0 += 1)
    for (c1 = c0 + 870; c1 <= min(c0 + 1739, 1999); c1 += 1) {
      if (c0 + 1738 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-870+c0] + S[-c0+c1-870+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][869+c0] + S[869+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1129; c0 += 1)
    S[c0][c0+870] = MAX(S[c0][c0+870], S[c0+1][c0+870-1] + can_pair(RNA, c0, c0+870));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1128; c0 += 1)
    for (c1 = c0 + 871; c1 <= min(c0 + 1741, 1999); c1 += 1) {
      if (c0 + 1740 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-871+c0] + S[-c0+c1-871+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][870+c0] + S[870+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1128; c0 += 1)
    S[c0][c0+871] = MAX(S[c0][c0+871], S[c0+1][c0+871-1] + can_pair(RNA, c0, c0+871));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1127; c0 += 1)
    for (c1 = c0 + 872; c1 <= min(c0 + 1743, 1999); c1 += 1) {
      if (c0 + 1742 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-872+c0] + S[-c0+c1-872+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][871+c0] + S[871+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1127; c0 += 1)
    S[c0][c0+872] = MAX(S[c0][c0+872], S[c0+1][c0+872-1] + can_pair(RNA, c0, c0+872));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1126; c0 += 1)
    for (c1 = c0 + 873; c1 <= min(c0 + 1745, 1999); c1 += 1) {
      if (c0 + 1744 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-873+c0] + S[-c0+c1-873+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][872+c0] + S[872+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1126; c0 += 1)
    S[c0][c0+873] = MAX(S[c0][c0+873], S[c0+1][c0+873-1] + can_pair(RNA, c0, c0+873));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1125; c0 += 1)
    for (c1 = c0 + 874; c1 <= min(c0 + 1747, 1999); c1 += 1) {
      if (c0 + 1746 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-874+c0] + S[-c0+c1-874+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][873+c0] + S[873+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1125; c0 += 1)
    S[c0][c0+874] = MAX(S[c0][c0+874], S[c0+1][c0+874-1] + can_pair(RNA, c0, c0+874));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1124; c0 += 1)
    for (c1 = c0 + 875; c1 <= min(c0 + 1749, 1999); c1 += 1) {
      if (c0 + 1748 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-875+c0] + S[-c0+c1-875+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][874+c0] + S[874+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1124; c0 += 1)
    S[c0][c0+875] = MAX(S[c0][c0+875], S[c0+1][c0+875-1] + can_pair(RNA, c0, c0+875));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1123; c0 += 1)
    for (c1 = c0 + 876; c1 <= min(c0 + 1751, 1999); c1 += 1) {
      if (c0 + 1750 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-876+c0] + S[-c0+c1-876+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][875+c0] + S[875+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1123; c0 += 1)
    S[c0][c0+876] = MAX(S[c0][c0+876], S[c0+1][c0+876-1] + can_pair(RNA, c0, c0+876));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1122; c0 += 1)
    for (c1 = c0 + 877; c1 <= min(c0 + 1753, 1999); c1 += 1) {
      if (c0 + 1752 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-877+c0] + S[-c0+c1-877+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][876+c0] + S[876+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1122; c0 += 1)
    S[c0][c0+877] = MAX(S[c0][c0+877], S[c0+1][c0+877-1] + can_pair(RNA, c0, c0+877));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1121; c0 += 1)
    for (c1 = c0 + 878; c1 <= min(c0 + 1755, 1999); c1 += 1) {
      if (c0 + 1754 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-878+c0] + S[-c0+c1-878+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][877+c0] + S[877+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1121; c0 += 1)
    S[c0][c0+878] = MAX(S[c0][c0+878], S[c0+1][c0+878-1] + can_pair(RNA, c0, c0+878));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1120; c0 += 1)
    for (c1 = c0 + 879; c1 <= min(c0 + 1757, 1999); c1 += 1) {
      if (c0 + 1756 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-879+c0] + S[-c0+c1-879+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][878+c0] + S[878+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1120; c0 += 1)
    S[c0][c0+879] = MAX(S[c0][c0+879], S[c0+1][c0+879-1] + can_pair(RNA, c0, c0+879));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1119; c0 += 1)
    for (c1 = c0 + 880; c1 <= min(c0 + 1759, 1999); c1 += 1) {
      if (c0 + 1758 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-880+c0] + S[-c0+c1-880+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][879+c0] + S[879+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1119; c0 += 1)
    S[c0][c0+880] = MAX(S[c0][c0+880], S[c0+1][c0+880-1] + can_pair(RNA, c0, c0+880));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1118; c0 += 1)
    for (c1 = c0 + 881; c1 <= min(c0 + 1761, 1999); c1 += 1) {
      if (c0 + 1760 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-881+c0] + S[-c0+c1-881+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][880+c0] + S[880+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1118; c0 += 1)
    S[c0][c0+881] = MAX(S[c0][c0+881], S[c0+1][c0+881-1] + can_pair(RNA, c0, c0+881));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1117; c0 += 1)
    for (c1 = c0 + 882; c1 <= min(c0 + 1763, 1999); c1 += 1) {
      if (c0 + 1762 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-882+c0] + S[-c0+c1-882+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][881+c0] + S[881+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1117; c0 += 1)
    S[c0][c0+882] = MAX(S[c0][c0+882], S[c0+1][c0+882-1] + can_pair(RNA, c0, c0+882));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1116; c0 += 1)
    for (c1 = c0 + 883; c1 <= min(c0 + 1765, 1999); c1 += 1) {
      if (c0 + 1764 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-883+c0] + S[-c0+c1-883+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][882+c0] + S[882+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1116; c0 += 1)
    S[c0][c0+883] = MAX(S[c0][c0+883], S[c0+1][c0+883-1] + can_pair(RNA, c0, c0+883));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1115; c0 += 1)
    for (c1 = c0 + 884; c1 <= min(c0 + 1767, 1999); c1 += 1) {
      if (c0 + 1766 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-884+c0] + S[-c0+c1-884+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][883+c0] + S[883+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1115; c0 += 1)
    S[c0][c0+884] = MAX(S[c0][c0+884], S[c0+1][c0+884-1] + can_pair(RNA, c0, c0+884));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1114; c0 += 1)
    for (c1 = c0 + 885; c1 <= min(c0 + 1769, 1999); c1 += 1) {
      if (c0 + 1768 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-885+c0] + S[-c0+c1-885+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][884+c0] + S[884+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1114; c0 += 1)
    S[c0][c0+885] = MAX(S[c0][c0+885], S[c0+1][c0+885-1] + can_pair(RNA, c0, c0+885));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1113; c0 += 1)
    for (c1 = c0 + 886; c1 <= min(c0 + 1771, 1999); c1 += 1) {
      if (c0 + 1770 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-886+c0] + S[-c0+c1-886+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][885+c0] + S[885+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1113; c0 += 1)
    S[c0][c0+886] = MAX(S[c0][c0+886], S[c0+1][c0+886-1] + can_pair(RNA, c0, c0+886));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1112; c0 += 1)
    for (c1 = c0 + 887; c1 <= min(c0 + 1773, 1999); c1 += 1) {
      if (c0 + 1772 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-887+c0] + S[-c0+c1-887+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][886+c0] + S[886+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1112; c0 += 1)
    S[c0][c0+887] = MAX(S[c0][c0+887], S[c0+1][c0+887-1] + can_pair(RNA, c0, c0+887));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1111; c0 += 1)
    for (c1 = c0 + 888; c1 <= min(c0 + 1775, 1999); c1 += 1) {
      if (c0 + 1774 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-888+c0] + S[-c0+c1-888+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][887+c0] + S[887+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1111; c0 += 1)
    S[c0][c0+888] = MAX(S[c0][c0+888], S[c0+1][c0+888-1] + can_pair(RNA, c0, c0+888));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1110; c0 += 1)
    for (c1 = c0 + 889; c1 <= min(c0 + 1777, 1999); c1 += 1) {
      if (c0 + 1776 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-889+c0] + S[-c0+c1-889+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][888+c0] + S[888+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1110; c0 += 1)
    S[c0][c0+889] = MAX(S[c0][c0+889], S[c0+1][c0+889-1] + can_pair(RNA, c0, c0+889));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1109; c0 += 1)
    for (c1 = c0 + 890; c1 <= min(c0 + 1779, 1999); c1 += 1) {
      if (c0 + 1778 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-890+c0] + S[-c0+c1-890+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][889+c0] + S[889+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1109; c0 += 1)
    S[c0][c0+890] = MAX(S[c0][c0+890], S[c0+1][c0+890-1] + can_pair(RNA, c0, c0+890));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1108; c0 += 1)
    for (c1 = c0 + 891; c1 <= min(c0 + 1781, 1999); c1 += 1) {
      if (c0 + 1780 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-891+c0] + S[-c0+c1-891+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][890+c0] + S[890+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1108; c0 += 1)
    S[c0][c0+891] = MAX(S[c0][c0+891], S[c0+1][c0+891-1] + can_pair(RNA, c0, c0+891));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1107; c0 += 1)
    for (c1 = c0 + 892; c1 <= min(c0 + 1783, 1999); c1 += 1) {
      if (c0 + 1782 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-892+c0] + S[-c0+c1-892+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][891+c0] + S[891+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1107; c0 += 1)
    S[c0][c0+892] = MAX(S[c0][c0+892], S[c0+1][c0+892-1] + can_pair(RNA, c0, c0+892));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1106; c0 += 1)
    for (c1 = c0 + 893; c1 <= min(c0 + 1785, 1999); c1 += 1) {
      if (c0 + 1784 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-893+c0] + S[-c0+c1-893+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][892+c0] + S[892+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1106; c0 += 1)
    S[c0][c0+893] = MAX(S[c0][c0+893], S[c0+1][c0+893-1] + can_pair(RNA, c0, c0+893));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1105; c0 += 1)
    for (c1 = c0 + 894; c1 <= min(c0 + 1787, 1999); c1 += 1) {
      if (c0 + 1786 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-894+c0] + S[-c0+c1-894+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][893+c0] + S[893+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1105; c0 += 1)
    S[c0][c0+894] = MAX(S[c0][c0+894], S[c0+1][c0+894-1] + can_pair(RNA, c0, c0+894));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1104; c0 += 1)
    for (c1 = c0 + 895; c1 <= min(c0 + 1789, 1999); c1 += 1) {
      if (c0 + 1788 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-895+c0] + S[-c0+c1-895+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][894+c0] + S[894+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1104; c0 += 1)
    S[c0][c0+895] = MAX(S[c0][c0+895], S[c0+1][c0+895-1] + can_pair(RNA, c0, c0+895));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1103; c0 += 1)
    for (c1 = c0 + 896; c1 <= min(c0 + 1791, 1999); c1 += 1) {
      if (c0 + 1790 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-896+c0] + S[-c0+c1-896+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][895+c0] + S[895+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1103; c0 += 1)
    S[c0][c0+896] = MAX(S[c0][c0+896], S[c0+1][c0+896-1] + can_pair(RNA, c0, c0+896));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1102; c0 += 1)
    for (c1 = c0 + 897; c1 <= min(c0 + 1793, 1999); c1 += 1) {
      if (c0 + 1792 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-897+c0] + S[-c0+c1-897+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][896+c0] + S[896+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1102; c0 += 1)
    S[c0][c0+897] = MAX(S[c0][c0+897], S[c0+1][c0+897-1] + can_pair(RNA, c0, c0+897));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1101; c0 += 1)
    for (c1 = c0 + 898; c1 <= min(c0 + 1795, 1999); c1 += 1) {
      if (c0 + 1794 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-898+c0] + S[-c0+c1-898+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][897+c0] + S[897+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1101; c0 += 1)
    S[c0][c0+898] = MAX(S[c0][c0+898], S[c0+1][c0+898-1] + can_pair(RNA, c0, c0+898));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1100; c0 += 1)
    for (c1 = c0 + 899; c1 <= min(c0 + 1797, 1999); c1 += 1) {
      if (c0 + 1796 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-899+c0] + S[-c0+c1-899+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][898+c0] + S[898+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1100; c0 += 1)
    S[c0][c0+899] = MAX(S[c0][c0+899], S[c0+1][c0+899-1] + can_pair(RNA, c0, c0+899));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1099; c0 += 1)
    for (c1 = c0 + 900; c1 <= min(c0 + 1799, 1999); c1 += 1) {
      if (c0 + 1798 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-900+c0] + S[-c0+c1-900+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][899+c0] + S[899+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1099; c0 += 1)
    S[c0][c0+900] = MAX(S[c0][c0+900], S[c0+1][c0+900-1] + can_pair(RNA, c0, c0+900));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1098; c0 += 1)
    for (c1 = c0 + 901; c1 <= min(c0 + 1801, 1999); c1 += 1) {
      if (c0 + 1800 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-901+c0] + S[-c0+c1-901+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][900+c0] + S[900+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1098; c0 += 1)
    S[c0][c0+901] = MAX(S[c0][c0+901], S[c0+1][c0+901-1] + can_pair(RNA, c0, c0+901));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1097; c0 += 1)
    for (c1 = c0 + 902; c1 <= min(c0 + 1803, 1999); c1 += 1) {
      if (c0 + 1802 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-902+c0] + S[-c0+c1-902+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][901+c0] + S[901+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1097; c0 += 1)
    S[c0][c0+902] = MAX(S[c0][c0+902], S[c0+1][c0+902-1] + can_pair(RNA, c0, c0+902));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1096; c0 += 1)
    for (c1 = c0 + 903; c1 <= min(c0 + 1805, 1999); c1 += 1) {
      if (c0 + 1804 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-903+c0] + S[-c0+c1-903+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][902+c0] + S[902+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1096; c0 += 1)
    S[c0][c0+903] = MAX(S[c0][c0+903], S[c0+1][c0+903-1] + can_pair(RNA, c0, c0+903));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1095; c0 += 1)
    for (c1 = c0 + 904; c1 <= min(c0 + 1807, 1999); c1 += 1) {
      if (c0 + 1806 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-904+c0] + S[-c0+c1-904+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][903+c0] + S[903+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1095; c0 += 1)
    S[c0][c0+904] = MAX(S[c0][c0+904], S[c0+1][c0+904-1] + can_pair(RNA, c0, c0+904));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1094; c0 += 1)
    for (c1 = c0 + 905; c1 <= min(c0 + 1809, 1999); c1 += 1) {
      if (c0 + 1808 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-905+c0] + S[-c0+c1-905+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][904+c0] + S[904+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1094; c0 += 1)
    S[c0][c0+905] = MAX(S[c0][c0+905], S[c0+1][c0+905-1] + can_pair(RNA, c0, c0+905));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1093; c0 += 1)
    for (c1 = c0 + 906; c1 <= min(c0 + 1811, 1999); c1 += 1) {
      if (c0 + 1810 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-906+c0] + S[-c0+c1-906+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][905+c0] + S[905+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1093; c0 += 1)
    S[c0][c0+906] = MAX(S[c0][c0+906], S[c0+1][c0+906-1] + can_pair(RNA, c0, c0+906));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1092; c0 += 1)
    for (c1 = c0 + 907; c1 <= min(c0 + 1813, 1999); c1 += 1) {
      if (c0 + 1812 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-907+c0] + S[-c0+c1-907+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][906+c0] + S[906+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1092; c0 += 1)
    S[c0][c0+907] = MAX(S[c0][c0+907], S[c0+1][c0+907-1] + can_pair(RNA, c0, c0+907));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1091; c0 += 1)
    for (c1 = c0 + 908; c1 <= min(c0 + 1815, 1999); c1 += 1) {
      if (c0 + 1814 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-908+c0] + S[-c0+c1-908+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][907+c0] + S[907+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1091; c0 += 1)
    S[c0][c0+908] = MAX(S[c0][c0+908], S[c0+1][c0+908-1] + can_pair(RNA, c0, c0+908));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1090; c0 += 1)
    for (c1 = c0 + 909; c1 <= min(c0 + 1817, 1999); c1 += 1) {
      if (c0 + 1816 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-909+c0] + S[-c0+c1-909+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][908+c0] + S[908+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1090; c0 += 1)
    S[c0][c0+909] = MAX(S[c0][c0+909], S[c0+1][c0+909-1] + can_pair(RNA, c0, c0+909));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1089; c0 += 1)
    for (c1 = c0 + 910; c1 <= min(c0 + 1819, 1999); c1 += 1) {
      if (c0 + 1818 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-910+c0] + S[-c0+c1-910+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][909+c0] + S[909+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1089; c0 += 1)
    S[c0][c0+910] = MAX(S[c0][c0+910], S[c0+1][c0+910-1] + can_pair(RNA, c0, c0+910));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1088; c0 += 1)
    for (c1 = c0 + 911; c1 <= min(c0 + 1821, 1999); c1 += 1) {
      if (c0 + 1820 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-911+c0] + S[-c0+c1-911+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][910+c0] + S[910+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1088; c0 += 1)
    S[c0][c0+911] = MAX(S[c0][c0+911], S[c0+1][c0+911-1] + can_pair(RNA, c0, c0+911));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1087; c0 += 1)
    for (c1 = c0 + 912; c1 <= min(c0 + 1823, 1999); c1 += 1) {
      if (c0 + 1822 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-912+c0] + S[-c0+c1-912+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][911+c0] + S[911+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1087; c0 += 1)
    S[c0][c0+912] = MAX(S[c0][c0+912], S[c0+1][c0+912-1] + can_pair(RNA, c0, c0+912));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1086; c0 += 1)
    for (c1 = c0 + 913; c1 <= min(c0 + 1825, 1999); c1 += 1) {
      if (c0 + 1824 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-913+c0] + S[-c0+c1-913+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][912+c0] + S[912+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1086; c0 += 1)
    S[c0][c0+913] = MAX(S[c0][c0+913], S[c0+1][c0+913-1] + can_pair(RNA, c0, c0+913));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1085; c0 += 1)
    for (c1 = c0 + 914; c1 <= min(c0 + 1827, 1999); c1 += 1) {
      if (c0 + 1826 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-914+c0] + S[-c0+c1-914+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][913+c0] + S[913+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1085; c0 += 1)
    S[c0][c0+914] = MAX(S[c0][c0+914], S[c0+1][c0+914-1] + can_pair(RNA, c0, c0+914));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1084; c0 += 1)
    for (c1 = c0 + 915; c1 <= min(c0 + 1829, 1999); c1 += 1) {
      if (c0 + 1828 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-915+c0] + S[-c0+c1-915+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][914+c0] + S[914+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1084; c0 += 1)
    S[c0][c0+915] = MAX(S[c0][c0+915], S[c0+1][c0+915-1] + can_pair(RNA, c0, c0+915));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1083; c0 += 1)
    for (c1 = c0 + 916; c1 <= min(c0 + 1831, 1999); c1 += 1) {
      if (c0 + 1830 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-916+c0] + S[-c0+c1-916+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][915+c0] + S[915+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1083; c0 += 1)
    S[c0][c0+916] = MAX(S[c0][c0+916], S[c0+1][c0+916-1] + can_pair(RNA, c0, c0+916));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1082; c0 += 1)
    for (c1 = c0 + 917; c1 <= min(c0 + 1833, 1999); c1 += 1) {
      if (c0 + 1832 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-917+c0] + S[-c0+c1-917+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][916+c0] + S[916+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1082; c0 += 1)
    S[c0][c0+917] = MAX(S[c0][c0+917], S[c0+1][c0+917-1] + can_pair(RNA, c0, c0+917));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1081; c0 += 1)
    for (c1 = c0 + 918; c1 <= min(c0 + 1835, 1999); c1 += 1) {
      if (c0 + 1834 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-918+c0] + S[-c0+c1-918+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][917+c0] + S[917+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1081; c0 += 1)
    S[c0][c0+918] = MAX(S[c0][c0+918], S[c0+1][c0+918-1] + can_pair(RNA, c0, c0+918));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1080; c0 += 1)
    for (c1 = c0 + 919; c1 <= min(c0 + 1837, 1999); c1 += 1) {
      if (c0 + 1836 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-919+c0] + S[-c0+c1-919+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][918+c0] + S[918+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1080; c0 += 1)
    S[c0][c0+919] = MAX(S[c0][c0+919], S[c0+1][c0+919-1] + can_pair(RNA, c0, c0+919));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1079; c0 += 1)
    for (c1 = c0 + 920; c1 <= min(c0 + 1839, 1999); c1 += 1) {
      if (c0 + 1838 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-920+c0] + S[-c0+c1-920+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][919+c0] + S[919+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1079; c0 += 1)
    S[c0][c0+920] = MAX(S[c0][c0+920], S[c0+1][c0+920-1] + can_pair(RNA, c0, c0+920));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1078; c0 += 1)
    for (c1 = c0 + 921; c1 <= min(c0 + 1841, 1999); c1 += 1) {
      if (c0 + 1840 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-921+c0] + S[-c0+c1-921+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][920+c0] + S[920+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1078; c0 += 1)
    S[c0][c0+921] = MAX(S[c0][c0+921], S[c0+1][c0+921-1] + can_pair(RNA, c0, c0+921));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1077; c0 += 1)
    for (c1 = c0 + 922; c1 <= min(c0 + 1843, 1999); c1 += 1) {
      if (c0 + 1842 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-922+c0] + S[-c0+c1-922+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][921+c0] + S[921+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1077; c0 += 1)
    S[c0][c0+922] = MAX(S[c0][c0+922], S[c0+1][c0+922-1] + can_pair(RNA, c0, c0+922));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1076; c0 += 1)
    for (c1 = c0 + 923; c1 <= min(c0 + 1845, 1999); c1 += 1) {
      if (c0 + 1844 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-923+c0] + S[-c0+c1-923+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][922+c0] + S[922+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1076; c0 += 1)
    S[c0][c0+923] = MAX(S[c0][c0+923], S[c0+1][c0+923-1] + can_pair(RNA, c0, c0+923));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1075; c0 += 1)
    for (c1 = c0 + 924; c1 <= min(c0 + 1847, 1999); c1 += 1) {
      if (c0 + 1846 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-924+c0] + S[-c0+c1-924+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][923+c0] + S[923+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1075; c0 += 1)
    S[c0][c0+924] = MAX(S[c0][c0+924], S[c0+1][c0+924-1] + can_pair(RNA, c0, c0+924));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1074; c0 += 1)
    for (c1 = c0 + 925; c1 <= min(c0 + 1849, 1999); c1 += 1) {
      if (c0 + 1848 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-925+c0] + S[-c0+c1-925+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][924+c0] + S[924+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1074; c0 += 1)
    S[c0][c0+925] = MAX(S[c0][c0+925], S[c0+1][c0+925-1] + can_pair(RNA, c0, c0+925));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1073; c0 += 1)
    for (c1 = c0 + 926; c1 <= min(c0 + 1851, 1999); c1 += 1) {
      if (c0 + 1850 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-926+c0] + S[-c0+c1-926+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][925+c0] + S[925+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1073; c0 += 1)
    S[c0][c0+926] = MAX(S[c0][c0+926], S[c0+1][c0+926-1] + can_pair(RNA, c0, c0+926));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1072; c0 += 1)
    for (c1 = c0 + 927; c1 <= min(c0 + 1853, 1999); c1 += 1) {
      if (c0 + 1852 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-927+c0] + S[-c0+c1-927+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][926+c0] + S[926+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1072; c0 += 1)
    S[c0][c0+927] = MAX(S[c0][c0+927], S[c0+1][c0+927-1] + can_pair(RNA, c0, c0+927));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1071; c0 += 1)
    for (c1 = c0 + 928; c1 <= min(c0 + 1855, 1999); c1 += 1) {
      if (c0 + 1854 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-928+c0] + S[-c0+c1-928+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][927+c0] + S[927+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1071; c0 += 1)
    S[c0][c0+928] = MAX(S[c0][c0+928], S[c0+1][c0+928-1] + can_pair(RNA, c0, c0+928));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1070; c0 += 1)
    for (c1 = c0 + 929; c1 <= min(c0 + 1857, 1999); c1 += 1) {
      if (c0 + 1856 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-929+c0] + S[-c0+c1-929+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][928+c0] + S[928+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1070; c0 += 1)
    S[c0][c0+929] = MAX(S[c0][c0+929], S[c0+1][c0+929-1] + can_pair(RNA, c0, c0+929));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1069; c0 += 1)
    for (c1 = c0 + 930; c1 <= min(c0 + 1859, 1999); c1 += 1) {
      if (c0 + 1858 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-930+c0] + S[-c0+c1-930+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][929+c0] + S[929+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1069; c0 += 1)
    S[c0][c0+930] = MAX(S[c0][c0+930], S[c0+1][c0+930-1] + can_pair(RNA, c0, c0+930));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1068; c0 += 1)
    for (c1 = c0 + 931; c1 <= min(c0 + 1861, 1999); c1 += 1) {
      if (c0 + 1860 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-931+c0] + S[-c0+c1-931+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][930+c0] + S[930+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1068; c0 += 1)
    S[c0][c0+931] = MAX(S[c0][c0+931], S[c0+1][c0+931-1] + can_pair(RNA, c0, c0+931));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1067; c0 += 1)
    for (c1 = c0 + 932; c1 <= min(c0 + 1863, 1999); c1 += 1) {
      if (c0 + 1862 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-932+c0] + S[-c0+c1-932+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][931+c0] + S[931+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1067; c0 += 1)
    S[c0][c0+932] = MAX(S[c0][c0+932], S[c0+1][c0+932-1] + can_pair(RNA, c0, c0+932));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1066; c0 += 1)
    for (c1 = c0 + 933; c1 <= min(c0 + 1865, 1999); c1 += 1) {
      if (c0 + 1864 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-933+c0] + S[-c0+c1-933+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][932+c0] + S[932+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1066; c0 += 1)
    S[c0][c0+933] = MAX(S[c0][c0+933], S[c0+1][c0+933-1] + can_pair(RNA, c0, c0+933));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1065; c0 += 1)
    for (c1 = c0 + 934; c1 <= min(c0 + 1867, 1999); c1 += 1) {
      if (c0 + 1866 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-934+c0] + S[-c0+c1-934+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][933+c0] + S[933+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1065; c0 += 1)
    S[c0][c0+934] = MAX(S[c0][c0+934], S[c0+1][c0+934-1] + can_pair(RNA, c0, c0+934));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1064; c0 += 1)
    for (c1 = c0 + 935; c1 <= min(c0 + 1869, 1999); c1 += 1) {
      if (c0 + 1868 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-935+c0] + S[-c0+c1-935+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][934+c0] + S[934+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1064; c0 += 1)
    S[c0][c0+935] = MAX(S[c0][c0+935], S[c0+1][c0+935-1] + can_pair(RNA, c0, c0+935));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1063; c0 += 1)
    for (c1 = c0 + 936; c1 <= min(c0 + 1871, 1999); c1 += 1) {
      if (c0 + 1870 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-936+c0] + S[-c0+c1-936+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][935+c0] + S[935+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1063; c0 += 1)
    S[c0][c0+936] = MAX(S[c0][c0+936], S[c0+1][c0+936-1] + can_pair(RNA, c0, c0+936));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1062; c0 += 1)
    for (c1 = c0 + 937; c1 <= min(c0 + 1873, 1999); c1 += 1) {
      if (c0 + 1872 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-937+c0] + S[-c0+c1-937+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][936+c0] + S[936+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1062; c0 += 1)
    S[c0][c0+937] = MAX(S[c0][c0+937], S[c0+1][c0+937-1] + can_pair(RNA, c0, c0+937));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1061; c0 += 1)
    for (c1 = c0 + 938; c1 <= min(c0 + 1875, 1999); c1 += 1) {
      if (c0 + 1874 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-938+c0] + S[-c0+c1-938+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][937+c0] + S[937+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1061; c0 += 1)
    S[c0][c0+938] = MAX(S[c0][c0+938], S[c0+1][c0+938-1] + can_pair(RNA, c0, c0+938));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1060; c0 += 1)
    for (c1 = c0 + 939; c1 <= min(c0 + 1877, 1999); c1 += 1) {
      if (c0 + 1876 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-939+c0] + S[-c0+c1-939+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][938+c0] + S[938+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1060; c0 += 1)
    S[c0][c0+939] = MAX(S[c0][c0+939], S[c0+1][c0+939-1] + can_pair(RNA, c0, c0+939));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1059; c0 += 1)
    for (c1 = c0 + 940; c1 <= min(c0 + 1879, 1999); c1 += 1) {
      if (c0 + 1878 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-940+c0] + S[-c0+c1-940+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][939+c0] + S[939+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1059; c0 += 1)
    S[c0][c0+940] = MAX(S[c0][c0+940], S[c0+1][c0+940-1] + can_pair(RNA, c0, c0+940));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1058; c0 += 1)
    for (c1 = c0 + 941; c1 <= min(c0 + 1881, 1999); c1 += 1) {
      if (c0 + 1880 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-941+c0] + S[-c0+c1-941+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][940+c0] + S[940+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1058; c0 += 1)
    S[c0][c0+941] = MAX(S[c0][c0+941], S[c0+1][c0+941-1] + can_pair(RNA, c0, c0+941));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1057; c0 += 1)
    for (c1 = c0 + 942; c1 <= min(c0 + 1883, 1999); c1 += 1) {
      if (c0 + 1882 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-942+c0] + S[-c0+c1-942+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][941+c0] + S[941+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1057; c0 += 1)
    S[c0][c0+942] = MAX(S[c0][c0+942], S[c0+1][c0+942-1] + can_pair(RNA, c0, c0+942));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1056; c0 += 1)
    for (c1 = c0 + 943; c1 <= min(c0 + 1885, 1999); c1 += 1) {
      if (c0 + 1884 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-943+c0] + S[-c0+c1-943+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][942+c0] + S[942+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1056; c0 += 1)
    S[c0][c0+943] = MAX(S[c0][c0+943], S[c0+1][c0+943-1] + can_pair(RNA, c0, c0+943));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1055; c0 += 1)
    for (c1 = c0 + 944; c1 <= min(c0 + 1887, 1999); c1 += 1) {
      if (c0 + 1886 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-944+c0] + S[-c0+c1-944+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][943+c0] + S[943+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1055; c0 += 1)
    S[c0][c0+944] = MAX(S[c0][c0+944], S[c0+1][c0+944-1] + can_pair(RNA, c0, c0+944));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1054; c0 += 1)
    for (c1 = c0 + 945; c1 <= min(c0 + 1889, 1999); c1 += 1) {
      if (c0 + 1888 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-945+c0] + S[-c0+c1-945+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][944+c0] + S[944+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1054; c0 += 1)
    S[c0][c0+945] = MAX(S[c0][c0+945], S[c0+1][c0+945-1] + can_pair(RNA, c0, c0+945));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1053; c0 += 1)
    for (c1 = c0 + 946; c1 <= min(c0 + 1891, 1999); c1 += 1) {
      if (c0 + 1890 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-946+c0] + S[-c0+c1-946+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][945+c0] + S[945+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1053; c0 += 1)
    S[c0][c0+946] = MAX(S[c0][c0+946], S[c0+1][c0+946-1] + can_pair(RNA, c0, c0+946));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1052; c0 += 1)
    for (c1 = c0 + 947; c1 <= min(c0 + 1893, 1999); c1 += 1) {
      if (c0 + 1892 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-947+c0] + S[-c0+c1-947+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][946+c0] + S[946+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1052; c0 += 1)
    S[c0][c0+947] = MAX(S[c0][c0+947], S[c0+1][c0+947-1] + can_pair(RNA, c0, c0+947));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1051; c0 += 1)
    for (c1 = c0 + 948; c1 <= min(c0 + 1895, 1999); c1 += 1) {
      if (c0 + 1894 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-948+c0] + S[-c0+c1-948+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][947+c0] + S[947+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1051; c0 += 1)
    S[c0][c0+948] = MAX(S[c0][c0+948], S[c0+1][c0+948-1] + can_pair(RNA, c0, c0+948));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1050; c0 += 1)
    for (c1 = c0 + 949; c1 <= min(c0 + 1897, 1999); c1 += 1) {
      if (c0 + 1896 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-949+c0] + S[-c0+c1-949+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][948+c0] + S[948+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1050; c0 += 1)
    S[c0][c0+949] = MAX(S[c0][c0+949], S[c0+1][c0+949-1] + can_pair(RNA, c0, c0+949));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1049; c0 += 1)
    for (c1 = c0 + 950; c1 <= min(c0 + 1899, 1999); c1 += 1) {
      if (c0 + 1898 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-950+c0] + S[-c0+c1-950+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][949+c0] + S[949+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1049; c0 += 1)
    S[c0][c0+950] = MAX(S[c0][c0+950], S[c0+1][c0+950-1] + can_pair(RNA, c0, c0+950));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1048; c0 += 1)
    for (c1 = c0 + 951; c1 <= min(c0 + 1901, 1999); c1 += 1) {
      if (c0 + 1900 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-951+c0] + S[-c0+c1-951+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][950+c0] + S[950+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1048; c0 += 1)
    S[c0][c0+951] = MAX(S[c0][c0+951], S[c0+1][c0+951-1] + can_pair(RNA, c0, c0+951));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1047; c0 += 1)
    for (c1 = c0 + 952; c1 <= min(c0 + 1903, 1999); c1 += 1) {
      if (c0 + 1902 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-952+c0] + S[-c0+c1-952+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][951+c0] + S[951+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1047; c0 += 1)
    S[c0][c0+952] = MAX(S[c0][c0+952], S[c0+1][c0+952-1] + can_pair(RNA, c0, c0+952));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1046; c0 += 1)
    for (c1 = c0 + 953; c1 <= min(c0 + 1905, 1999); c1 += 1) {
      if (c0 + 1904 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-953+c0] + S[-c0+c1-953+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][952+c0] + S[952+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1046; c0 += 1)
    S[c0][c0+953] = MAX(S[c0][c0+953], S[c0+1][c0+953-1] + can_pair(RNA, c0, c0+953));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1045; c0 += 1)
    for (c1 = c0 + 954; c1 <= min(c0 + 1907, 1999); c1 += 1) {
      if (c0 + 1906 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-954+c0] + S[-c0+c1-954+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][953+c0] + S[953+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1045; c0 += 1)
    S[c0][c0+954] = MAX(S[c0][c0+954], S[c0+1][c0+954-1] + can_pair(RNA, c0, c0+954));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1044; c0 += 1)
    for (c1 = c0 + 955; c1 <= min(c0 + 1909, 1999); c1 += 1) {
      if (c0 + 1908 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-955+c0] + S[-c0+c1-955+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][954+c0] + S[954+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1044; c0 += 1)
    S[c0][c0+955] = MAX(S[c0][c0+955], S[c0+1][c0+955-1] + can_pair(RNA, c0, c0+955));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1043; c0 += 1)
    for (c1 = c0 + 956; c1 <= min(c0 + 1911, 1999); c1 += 1) {
      if (c0 + 1910 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-956+c0] + S[-c0+c1-956+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][955+c0] + S[955+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1043; c0 += 1)
    S[c0][c0+956] = MAX(S[c0][c0+956], S[c0+1][c0+956-1] + can_pair(RNA, c0, c0+956));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1042; c0 += 1)
    for (c1 = c0 + 957; c1 <= min(c0 + 1913, 1999); c1 += 1) {
      if (c0 + 1912 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-957+c0] + S[-c0+c1-957+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][956+c0] + S[956+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1042; c0 += 1)
    S[c0][c0+957] = MAX(S[c0][c0+957], S[c0+1][c0+957-1] + can_pair(RNA, c0, c0+957));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1041; c0 += 1)
    for (c1 = c0 + 958; c1 <= min(c0 + 1915, 1999); c1 += 1) {
      if (c0 + 1914 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-958+c0] + S[-c0+c1-958+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][957+c0] + S[957+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1041; c0 += 1)
    S[c0][c0+958] = MAX(S[c0][c0+958], S[c0+1][c0+958-1] + can_pair(RNA, c0, c0+958));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1040; c0 += 1)
    for (c1 = c0 + 959; c1 <= min(c0 + 1917, 1999); c1 += 1) {
      if (c0 + 1916 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-959+c0] + S[-c0+c1-959+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][958+c0] + S[958+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1040; c0 += 1)
    S[c0][c0+959] = MAX(S[c0][c0+959], S[c0+1][c0+959-1] + can_pair(RNA, c0, c0+959));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1039; c0 += 1)
    for (c1 = c0 + 960; c1 <= min(c0 + 1919, 1999); c1 += 1) {
      if (c0 + 1918 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-960+c0] + S[-c0+c1-960+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][959+c0] + S[959+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1039; c0 += 1)
    S[c0][c0+960] = MAX(S[c0][c0+960], S[c0+1][c0+960-1] + can_pair(RNA, c0, c0+960));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1038; c0 += 1)
    for (c1 = c0 + 961; c1 <= min(c0 + 1921, 1999); c1 += 1) {
      if (c0 + 1920 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-961+c0] + S[-c0+c1-961+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][960+c0] + S[960+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1038; c0 += 1)
    S[c0][c0+961] = MAX(S[c0][c0+961], S[c0+1][c0+961-1] + can_pair(RNA, c0, c0+961));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1037; c0 += 1)
    for (c1 = c0 + 962; c1 <= min(c0 + 1923, 1999); c1 += 1) {
      if (c0 + 1922 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-962+c0] + S[-c0+c1-962+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][961+c0] + S[961+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1037; c0 += 1)
    S[c0][c0+962] = MAX(S[c0][c0+962], S[c0+1][c0+962-1] + can_pair(RNA, c0, c0+962));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1036; c0 += 1)
    for (c1 = c0 + 963; c1 <= min(c0 + 1925, 1999); c1 += 1) {
      if (c0 + 1924 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-963+c0] + S[-c0+c1-963+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][962+c0] + S[962+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1036; c0 += 1)
    S[c0][c0+963] = MAX(S[c0][c0+963], S[c0+1][c0+963-1] + can_pair(RNA, c0, c0+963));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1035; c0 += 1)
    for (c1 = c0 + 964; c1 <= min(c0 + 1927, 1999); c1 += 1) {
      if (c0 + 1926 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-964+c0] + S[-c0+c1-964+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][963+c0] + S[963+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1035; c0 += 1)
    S[c0][c0+964] = MAX(S[c0][c0+964], S[c0+1][c0+964-1] + can_pair(RNA, c0, c0+964));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1034; c0 += 1)
    for (c1 = c0 + 965; c1 <= min(c0 + 1929, 1999); c1 += 1) {
      if (c0 + 1928 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-965+c0] + S[-c0+c1-965+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][964+c0] + S[964+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1034; c0 += 1)
    S[c0][c0+965] = MAX(S[c0][c0+965], S[c0+1][c0+965-1] + can_pair(RNA, c0, c0+965));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1033; c0 += 1)
    for (c1 = c0 + 966; c1 <= min(c0 + 1931, 1999); c1 += 1) {
      if (c0 + 1930 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-966+c0] + S[-c0+c1-966+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][965+c0] + S[965+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1033; c0 += 1)
    S[c0][c0+966] = MAX(S[c0][c0+966], S[c0+1][c0+966-1] + can_pair(RNA, c0, c0+966));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1032; c0 += 1)
    for (c1 = c0 + 967; c1 <= min(c0 + 1933, 1999); c1 += 1) {
      if (c0 + 1932 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-967+c0] + S[-c0+c1-967+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][966+c0] + S[966+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1032; c0 += 1)
    S[c0][c0+967] = MAX(S[c0][c0+967], S[c0+1][c0+967-1] + can_pair(RNA, c0, c0+967));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1031; c0 += 1)
    for (c1 = c0 + 968; c1 <= min(c0 + 1935, 1999); c1 += 1) {
      if (c0 + 1934 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-968+c0] + S[-c0+c1-968+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][967+c0] + S[967+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1031; c0 += 1)
    S[c0][c0+968] = MAX(S[c0][c0+968], S[c0+1][c0+968-1] + can_pair(RNA, c0, c0+968));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1030; c0 += 1)
    for (c1 = c0 + 969; c1 <= min(c0 + 1937, 1999); c1 += 1) {
      if (c0 + 1936 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-969+c0] + S[-c0+c1-969+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][968+c0] + S[968+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1030; c0 += 1)
    S[c0][c0+969] = MAX(S[c0][c0+969], S[c0+1][c0+969-1] + can_pair(RNA, c0, c0+969));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1029; c0 += 1)
    for (c1 = c0 + 970; c1 <= min(c0 + 1939, 1999); c1 += 1) {
      if (c0 + 1938 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-970+c0] + S[-c0+c1-970+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][969+c0] + S[969+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1029; c0 += 1)
    S[c0][c0+970] = MAX(S[c0][c0+970], S[c0+1][c0+970-1] + can_pair(RNA, c0, c0+970));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1028; c0 += 1)
    for (c1 = c0 + 971; c1 <= min(c0 + 1941, 1999); c1 += 1) {
      if (c0 + 1940 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-971+c0] + S[-c0+c1-971+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][970+c0] + S[970+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1028; c0 += 1)
    S[c0][c0+971] = MAX(S[c0][c0+971], S[c0+1][c0+971-1] + can_pair(RNA, c0, c0+971));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1027; c0 += 1)
    for (c1 = c0 + 972; c1 <= min(c0 + 1943, 1999); c1 += 1) {
      if (c0 + 1942 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-972+c0] + S[-c0+c1-972+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][971+c0] + S[971+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1027; c0 += 1)
    S[c0][c0+972] = MAX(S[c0][c0+972], S[c0+1][c0+972-1] + can_pair(RNA, c0, c0+972));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1026; c0 += 1)
    for (c1 = c0 + 973; c1 <= min(c0 + 1945, 1999); c1 += 1) {
      if (c0 + 1944 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-973+c0] + S[-c0+c1-973+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][972+c0] + S[972+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1026; c0 += 1)
    S[c0][c0+973] = MAX(S[c0][c0+973], S[c0+1][c0+973-1] + can_pair(RNA, c0, c0+973));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1025; c0 += 1)
    for (c1 = c0 + 974; c1 <= min(c0 + 1947, 1999); c1 += 1) {
      if (c0 + 1946 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-974+c0] + S[-c0+c1-974+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][973+c0] + S[973+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1025; c0 += 1)
    S[c0][c0+974] = MAX(S[c0][c0+974], S[c0+1][c0+974-1] + can_pair(RNA, c0, c0+974));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1024; c0 += 1)
    for (c1 = c0 + 975; c1 <= min(c0 + 1949, 1999); c1 += 1) {
      if (c0 + 1948 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-975+c0] + S[-c0+c1-975+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][974+c0] + S[974+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1024; c0 += 1)
    S[c0][c0+975] = MAX(S[c0][c0+975], S[c0+1][c0+975-1] + can_pair(RNA, c0, c0+975));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1023; c0 += 1)
    for (c1 = c0 + 976; c1 <= min(c0 + 1951, 1999); c1 += 1) {
      if (c0 + 1950 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-976+c0] + S[-c0+c1-976+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][975+c0] + S[975+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1023; c0 += 1)
    S[c0][c0+976] = MAX(S[c0][c0+976], S[c0+1][c0+976-1] + can_pair(RNA, c0, c0+976));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1022; c0 += 1)
    for (c1 = c0 + 977; c1 <= min(c0 + 1953, 1999); c1 += 1) {
      if (c0 + 1952 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-977+c0] + S[-c0+c1-977+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][976+c0] + S[976+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1022; c0 += 1)
    S[c0][c0+977] = MAX(S[c0][c0+977], S[c0+1][c0+977-1] + can_pair(RNA, c0, c0+977));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1021; c0 += 1)
    for (c1 = c0 + 978; c1 <= min(c0 + 1955, 1999); c1 += 1) {
      if (c0 + 1954 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-978+c0] + S[-c0+c1-978+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][977+c0] + S[977+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1021; c0 += 1)
    S[c0][c0+978] = MAX(S[c0][c0+978], S[c0+1][c0+978-1] + can_pair(RNA, c0, c0+978));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1020; c0 += 1)
    for (c1 = c0 + 979; c1 <= min(c0 + 1957, 1999); c1 += 1) {
      if (c0 + 1956 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-979+c0] + S[-c0+c1-979+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][978+c0] + S[978+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1020; c0 += 1)
    S[c0][c0+979] = MAX(S[c0][c0+979], S[c0+1][c0+979-1] + can_pair(RNA, c0, c0+979));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1019; c0 += 1)
    for (c1 = c0 + 980; c1 <= min(c0 + 1959, 1999); c1 += 1) {
      if (c0 + 1958 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-980+c0] + S[-c0+c1-980+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][979+c0] + S[979+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1019; c0 += 1)
    S[c0][c0+980] = MAX(S[c0][c0+980], S[c0+1][c0+980-1] + can_pair(RNA, c0, c0+980));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1018; c0 += 1)
    for (c1 = c0 + 981; c1 <= min(c0 + 1961, 1999); c1 += 1) {
      if (c0 + 1960 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-981+c0] + S[-c0+c1-981+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][980+c0] + S[980+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1018; c0 += 1)
    S[c0][c0+981] = MAX(S[c0][c0+981], S[c0+1][c0+981-1] + can_pair(RNA, c0, c0+981));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1017; c0 += 1)
    for (c1 = c0 + 982; c1 <= min(c0 + 1963, 1999); c1 += 1) {
      if (c0 + 1962 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-982+c0] + S[-c0+c1-982+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][981+c0] + S[981+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1017; c0 += 1)
    S[c0][c0+982] = MAX(S[c0][c0+982], S[c0+1][c0+982-1] + can_pair(RNA, c0, c0+982));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1016; c0 += 1)
    for (c1 = c0 + 983; c1 <= min(c0 + 1965, 1999); c1 += 1) {
      if (c0 + 1964 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-983+c0] + S[-c0+c1-983+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][982+c0] + S[982+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1016; c0 += 1)
    S[c0][c0+983] = MAX(S[c0][c0+983], S[c0+1][c0+983-1] + can_pair(RNA, c0, c0+983));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1015; c0 += 1)
    for (c1 = c0 + 984; c1 <= min(c0 + 1967, 1999); c1 += 1) {
      if (c0 + 1966 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-984+c0] + S[-c0+c1-984+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][983+c0] + S[983+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1015; c0 += 1)
    S[c0][c0+984] = MAX(S[c0][c0+984], S[c0+1][c0+984-1] + can_pair(RNA, c0, c0+984));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1014; c0 += 1)
    for (c1 = c0 + 985; c1 <= min(c0 + 1969, 1999); c1 += 1) {
      if (c0 + 1968 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-985+c0] + S[-c0+c1-985+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][984+c0] + S[984+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1014; c0 += 1)
    S[c0][c0+985] = MAX(S[c0][c0+985], S[c0+1][c0+985-1] + can_pair(RNA, c0, c0+985));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1013; c0 += 1)
    for (c1 = c0 + 986; c1 <= min(c0 + 1971, 1999); c1 += 1) {
      if (c0 + 1970 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-986+c0] + S[-c0+c1-986+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][985+c0] + S[985+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1013; c0 += 1)
    S[c0][c0+986] = MAX(S[c0][c0+986], S[c0+1][c0+986-1] + can_pair(RNA, c0, c0+986));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1012; c0 += 1)
    for (c1 = c0 + 987; c1 <= min(c0 + 1973, 1999); c1 += 1) {
      if (c0 + 1972 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-987+c0] + S[-c0+c1-987+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][986+c0] + S[986+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1012; c0 += 1)
    S[c0][c0+987] = MAX(S[c0][c0+987], S[c0+1][c0+987-1] + can_pair(RNA, c0, c0+987));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1011; c0 += 1)
    for (c1 = c0 + 988; c1 <= min(c0 + 1975, 1999); c1 += 1) {
      if (c0 + 1974 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-988+c0] + S[-c0+c1-988+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][987+c0] + S[987+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1011; c0 += 1)
    S[c0][c0+988] = MAX(S[c0][c0+988], S[c0+1][c0+988-1] + can_pair(RNA, c0, c0+988));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1010; c0 += 1)
    for (c1 = c0 + 989; c1 <= min(c0 + 1977, 1999); c1 += 1) {
      if (c0 + 1976 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-989+c0] + S[-c0+c1-989+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][988+c0] + S[988+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1010; c0 += 1)
    S[c0][c0+989] = MAX(S[c0][c0+989], S[c0+1][c0+989-1] + can_pair(RNA, c0, c0+989));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1009; c0 += 1)
    for (c1 = c0 + 990; c1 <= min(c0 + 1979, 1999); c1 += 1) {
      if (c0 + 1978 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-990+c0] + S[-c0+c1-990+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][989+c0] + S[989+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1009; c0 += 1)
    S[c0][c0+990] = MAX(S[c0][c0+990], S[c0+1][c0+990-1] + can_pair(RNA, c0, c0+990));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1008; c0 += 1)
    for (c1 = c0 + 991; c1 <= min(c0 + 1981, 1999); c1 += 1) {
      if (c0 + 1980 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-991+c0] + S[-c0+c1-991+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][990+c0] + S[990+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1008; c0 += 1)
    S[c0][c0+991] = MAX(S[c0][c0+991], S[c0+1][c0+991-1] + can_pair(RNA, c0, c0+991));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1007; c0 += 1)
    for (c1 = c0 + 992; c1 <= min(c0 + 1983, 1999); c1 += 1) {
      if (c0 + 1982 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-992+c0] + S[-c0+c1-992+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][991+c0] + S[991+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1007; c0 += 1)
    S[c0][c0+992] = MAX(S[c0][c0+992], S[c0+1][c0+992-1] + can_pair(RNA, c0, c0+992));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1006; c0 += 1)
    for (c1 = c0 + 993; c1 <= min(c0 + 1985, 1999); c1 += 1) {
      if (c0 + 1984 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-993+c0] + S[-c0+c1-993+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][992+c0] + S[992+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1006; c0 += 1)
    S[c0][c0+993] = MAX(S[c0][c0+993], S[c0+1][c0+993-1] + can_pair(RNA, c0, c0+993));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1005; c0 += 1)
    for (c1 = c0 + 994; c1 <= min(c0 + 1987, 1999); c1 += 1) {
      if (c0 + 1986 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-994+c0] + S[-c0+c1-994+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][993+c0] + S[993+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1005; c0 += 1)
    S[c0][c0+994] = MAX(S[c0][c0+994], S[c0+1][c0+994-1] + can_pair(RNA, c0, c0+994));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1004; c0 += 1)
    for (c1 = c0 + 995; c1 <= min(c0 + 1989, 1999); c1 += 1) {
      if (c0 + 1988 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-995+c0] + S[-c0+c1-995+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][994+c0] + S[994+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1004; c0 += 1)
    S[c0][c0+995] = MAX(S[c0][c0+995], S[c0+1][c0+995-1] + can_pair(RNA, c0, c0+995));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1003; c0 += 1)
    for (c1 = c0 + 996; c1 <= min(c0 + 1991, 1999); c1 += 1) {
      if (c0 + 1990 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-996+c0] + S[-c0+c1-996+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][995+c0] + S[995+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1003; c0 += 1)
    S[c0][c0+996] = MAX(S[c0][c0+996], S[c0+1][c0+996-1] + can_pair(RNA, c0, c0+996));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1002; c0 += 1)
    for (c1 = c0 + 997; c1 <= min(c0 + 1993, 1999); c1 += 1) {
      if (c0 + 1992 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-997+c0] + S[-c0+c1-997+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][996+c0] + S[996+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1002; c0 += 1)
    S[c0][c0+997] = MAX(S[c0][c0+997], S[c0+1][c0+997-1] + can_pair(RNA, c0, c0+997));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1001; c0 += 1)
    for (c1 = c0 + 998; c1 <= min(c0 + 1995, 1999); c1 += 1) {
      if (c0 + 1994 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-998+c0] + S[-c0+c1-998+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][997+c0] + S[997+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1001; c0 += 1)
    S[c0][c0+998] = MAX(S[c0][c0+998], S[c0+1][c0+998-1] + can_pair(RNA, c0, c0+998));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1000; c0 += 1)
    for (c1 = c0 + 999; c1 <= min(c0 + 1997, 1999); c1 += 1) {
      if (c0 + 1996 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-999+c0] + S[-c0+c1-999+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][998+c0] + S[998+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 1000; c0 += 1)
    S[c0][c0+999] = MAX(S[c0][c0+999], S[c0+1][c0+999-1] + can_pair(RNA, c0, c0+999));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 999; c0 += 1)
    for (c1 = c0 + 1000; c1 <= 1999; c1 += 1) {
      if (c0 + 1998 >= c1)
        S[c0][c1] = MAX(S[c0][-c0+c1-1000+c0] + S[-c0+c1-1000+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][999+c0] + S[999+c0+1][c1], S[c0][c1]);
    }
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 999; c0 += 1)
    S[c0][c0+1000] = MAX(S[c0][c0+1000], S[c0+1][c0+1000-1] + can_pair(RNA, c0, c0+1000));
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 998; c0 += 1)
    for (c1 = c0 + 1001; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1001+c0] + S[-c0+c1-1001+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1000+c0] + S[1000+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 998; c0 += 1)
    S[c0][c0+1001] = MAX(S[c0][c0+1001], S[c0+1][c0+1001-1] + can_pair(RNA, c0, c0+1001));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 997; c0 += 1)
    for (c1 = c0 + 1002; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1002+c0] + S[-c0+c1-1002+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1001+c0] + S[1001+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 997; c0 += 1)
    S[c0][c0+1002] = MAX(S[c0][c0+1002], S[c0+1][c0+1002-1] + can_pair(RNA, c0, c0+1002));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 996; c0 += 1)
    for (c1 = c0 + 1003; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1003+c0] + S[-c0+c1-1003+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1002+c0] + S[1002+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 996; c0 += 1)
    S[c0][c0+1003] = MAX(S[c0][c0+1003], S[c0+1][c0+1003-1] + can_pair(RNA, c0, c0+1003));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 995; c0 += 1)
    for (c1 = c0 + 1004; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1004+c0] + S[-c0+c1-1004+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1003+c0] + S[1003+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 995; c0 += 1)
    S[c0][c0+1004] = MAX(S[c0][c0+1004], S[c0+1][c0+1004-1] + can_pair(RNA, c0, c0+1004));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 994; c0 += 1)
    for (c1 = c0 + 1005; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1005+c0] + S[-c0+c1-1005+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1004+c0] + S[1004+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 994; c0 += 1)
    S[c0][c0+1005] = MAX(S[c0][c0+1005], S[c0+1][c0+1005-1] + can_pair(RNA, c0, c0+1005));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 993; c0 += 1)
    for (c1 = c0 + 1006; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1006+c0] + S[-c0+c1-1006+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1005+c0] + S[1005+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 993; c0 += 1)
    S[c0][c0+1006] = MAX(S[c0][c0+1006], S[c0+1][c0+1006-1] + can_pair(RNA, c0, c0+1006));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 992; c0 += 1)
    for (c1 = c0 + 1007; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1007+c0] + S[-c0+c1-1007+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1006+c0] + S[1006+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 992; c0 += 1)
    S[c0][c0+1007] = MAX(S[c0][c0+1007], S[c0+1][c0+1007-1] + can_pair(RNA, c0, c0+1007));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 991; c0 += 1)
    for (c1 = c0 + 1008; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1008+c0] + S[-c0+c1-1008+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1007+c0] + S[1007+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 991; c0 += 1)
    S[c0][c0+1008] = MAX(S[c0][c0+1008], S[c0+1][c0+1008-1] + can_pair(RNA, c0, c0+1008));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 990; c0 += 1)
    for (c1 = c0 + 1009; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1009+c0] + S[-c0+c1-1009+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1008+c0] + S[1008+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 990; c0 += 1)
    S[c0][c0+1009] = MAX(S[c0][c0+1009], S[c0+1][c0+1009-1] + can_pair(RNA, c0, c0+1009));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 989; c0 += 1)
    for (c1 = c0 + 1010; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1010+c0] + S[-c0+c1-1010+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1009+c0] + S[1009+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 989; c0 += 1)
    S[c0][c0+1010] = MAX(S[c0][c0+1010], S[c0+1][c0+1010-1] + can_pair(RNA, c0, c0+1010));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 988; c0 += 1)
    for (c1 = c0 + 1011; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1011+c0] + S[-c0+c1-1011+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1010+c0] + S[1010+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 988; c0 += 1)
    S[c0][c0+1011] = MAX(S[c0][c0+1011], S[c0+1][c0+1011-1] + can_pair(RNA, c0, c0+1011));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 987; c0 += 1)
    for (c1 = c0 + 1012; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1012+c0] + S[-c0+c1-1012+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1011+c0] + S[1011+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 987; c0 += 1)
    S[c0][c0+1012] = MAX(S[c0][c0+1012], S[c0+1][c0+1012-1] + can_pair(RNA, c0, c0+1012));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 986; c0 += 1)
    for (c1 = c0 + 1013; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1013+c0] + S[-c0+c1-1013+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1012+c0] + S[1012+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 986; c0 += 1)
    S[c0][c0+1013] = MAX(S[c0][c0+1013], S[c0+1][c0+1013-1] + can_pair(RNA, c0, c0+1013));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 985; c0 += 1)
    for (c1 = c0 + 1014; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1014+c0] + S[-c0+c1-1014+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1013+c0] + S[1013+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 985; c0 += 1)
    S[c0][c0+1014] = MAX(S[c0][c0+1014], S[c0+1][c0+1014-1] + can_pair(RNA, c0, c0+1014));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 984; c0 += 1)
    for (c1 = c0 + 1015; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1015+c0] + S[-c0+c1-1015+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1014+c0] + S[1014+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 984; c0 += 1)
    S[c0][c0+1015] = MAX(S[c0][c0+1015], S[c0+1][c0+1015-1] + can_pair(RNA, c0, c0+1015));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 983; c0 += 1)
    for (c1 = c0 + 1016; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1016+c0] + S[-c0+c1-1016+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1015+c0] + S[1015+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 983; c0 += 1)
    S[c0][c0+1016] = MAX(S[c0][c0+1016], S[c0+1][c0+1016-1] + can_pair(RNA, c0, c0+1016));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 982; c0 += 1)
    for (c1 = c0 + 1017; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1017+c0] + S[-c0+c1-1017+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1016+c0] + S[1016+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 982; c0 += 1)
    S[c0][c0+1017] = MAX(S[c0][c0+1017], S[c0+1][c0+1017-1] + can_pair(RNA, c0, c0+1017));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 981; c0 += 1)
    for (c1 = c0 + 1018; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1018+c0] + S[-c0+c1-1018+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1017+c0] + S[1017+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 981; c0 += 1)
    S[c0][c0+1018] = MAX(S[c0][c0+1018], S[c0+1][c0+1018-1] + can_pair(RNA, c0, c0+1018));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 980; c0 += 1)
    for (c1 = c0 + 1019; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1019+c0] + S[-c0+c1-1019+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1018+c0] + S[1018+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 980; c0 += 1)
    S[c0][c0+1019] = MAX(S[c0][c0+1019], S[c0+1][c0+1019-1] + can_pair(RNA, c0, c0+1019));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 979; c0 += 1)
    for (c1 = c0 + 1020; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1020+c0] + S[-c0+c1-1020+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1019+c0] + S[1019+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 979; c0 += 1)
    S[c0][c0+1020] = MAX(S[c0][c0+1020], S[c0+1][c0+1020-1] + can_pair(RNA, c0, c0+1020));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 978; c0 += 1)
    for (c1 = c0 + 1021; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1021+c0] + S[-c0+c1-1021+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1020+c0] + S[1020+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 978; c0 += 1)
    S[c0][c0+1021] = MAX(S[c0][c0+1021], S[c0+1][c0+1021-1] + can_pair(RNA, c0, c0+1021));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 977; c0 += 1)
    for (c1 = c0 + 1022; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1022+c0] + S[-c0+c1-1022+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1021+c0] + S[1021+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 977; c0 += 1)
    S[c0][c0+1022] = MAX(S[c0][c0+1022], S[c0+1][c0+1022-1] + can_pair(RNA, c0, c0+1022));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 976; c0 += 1)
    for (c1 = c0 + 1023; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1023+c0] + S[-c0+c1-1023+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1022+c0] + S[1022+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 976; c0 += 1)
    S[c0][c0+1023] = MAX(S[c0][c0+1023], S[c0+1][c0+1023-1] + can_pair(RNA, c0, c0+1023));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 975; c0 += 1)
    for (c1 = c0 + 1024; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1024+c0] + S[-c0+c1-1024+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1023+c0] + S[1023+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 975; c0 += 1)
    S[c0][c0+1024] = MAX(S[c0][c0+1024], S[c0+1][c0+1024-1] + can_pair(RNA, c0, c0+1024));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 974; c0 += 1)
    for (c1 = c0 + 1025; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1025+c0] + S[-c0+c1-1025+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1024+c0] + S[1024+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 974; c0 += 1)
    S[c0][c0+1025] = MAX(S[c0][c0+1025], S[c0+1][c0+1025-1] + can_pair(RNA, c0, c0+1025));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 973; c0 += 1)
    for (c1 = c0 + 1026; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1026+c0] + S[-c0+c1-1026+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1025+c0] + S[1025+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 973; c0 += 1)
    S[c0][c0+1026] = MAX(S[c0][c0+1026], S[c0+1][c0+1026-1] + can_pair(RNA, c0, c0+1026));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 972; c0 += 1)
    for (c1 = c0 + 1027; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1027+c0] + S[-c0+c1-1027+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1026+c0] + S[1026+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 972; c0 += 1)
    S[c0][c0+1027] = MAX(S[c0][c0+1027], S[c0+1][c0+1027-1] + can_pair(RNA, c0, c0+1027));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 971; c0 += 1)
    for (c1 = c0 + 1028; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1028+c0] + S[-c0+c1-1028+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1027+c0] + S[1027+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 971; c0 += 1)
    S[c0][c0+1028] = MAX(S[c0][c0+1028], S[c0+1][c0+1028-1] + can_pair(RNA, c0, c0+1028));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 970; c0 += 1)
    for (c1 = c0 + 1029; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1029+c0] + S[-c0+c1-1029+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1028+c0] + S[1028+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 970; c0 += 1)
    S[c0][c0+1029] = MAX(S[c0][c0+1029], S[c0+1][c0+1029-1] + can_pair(RNA, c0, c0+1029));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 969; c0 += 1)
    for (c1 = c0 + 1030; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1030+c0] + S[-c0+c1-1030+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1029+c0] + S[1029+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 969; c0 += 1)
    S[c0][c0+1030] = MAX(S[c0][c0+1030], S[c0+1][c0+1030-1] + can_pair(RNA, c0, c0+1030));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 968; c0 += 1)
    for (c1 = c0 + 1031; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1031+c0] + S[-c0+c1-1031+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1030+c0] + S[1030+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 968; c0 += 1)
    S[c0][c0+1031] = MAX(S[c0][c0+1031], S[c0+1][c0+1031-1] + can_pair(RNA, c0, c0+1031));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 967; c0 += 1)
    for (c1 = c0 + 1032; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1032+c0] + S[-c0+c1-1032+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1031+c0] + S[1031+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 967; c0 += 1)
    S[c0][c0+1032] = MAX(S[c0][c0+1032], S[c0+1][c0+1032-1] + can_pair(RNA, c0, c0+1032));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 966; c0 += 1)
    for (c1 = c0 + 1033; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1033+c0] + S[-c0+c1-1033+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1032+c0] + S[1032+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 966; c0 += 1)
    S[c0][c0+1033] = MAX(S[c0][c0+1033], S[c0+1][c0+1033-1] + can_pair(RNA, c0, c0+1033));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 965; c0 += 1)
    for (c1 = c0 + 1034; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1034+c0] + S[-c0+c1-1034+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1033+c0] + S[1033+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 965; c0 += 1)
    S[c0][c0+1034] = MAX(S[c0][c0+1034], S[c0+1][c0+1034-1] + can_pair(RNA, c0, c0+1034));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 964; c0 += 1)
    for (c1 = c0 + 1035; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1035+c0] + S[-c0+c1-1035+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1034+c0] + S[1034+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 964; c0 += 1)
    S[c0][c0+1035] = MAX(S[c0][c0+1035], S[c0+1][c0+1035-1] + can_pair(RNA, c0, c0+1035));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 963; c0 += 1)
    for (c1 = c0 + 1036; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1036+c0] + S[-c0+c1-1036+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1035+c0] + S[1035+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 963; c0 += 1)
    S[c0][c0+1036] = MAX(S[c0][c0+1036], S[c0+1][c0+1036-1] + can_pair(RNA, c0, c0+1036));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 962; c0 += 1)
    for (c1 = c0 + 1037; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1037+c0] + S[-c0+c1-1037+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1036+c0] + S[1036+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 962; c0 += 1)
    S[c0][c0+1037] = MAX(S[c0][c0+1037], S[c0+1][c0+1037-1] + can_pair(RNA, c0, c0+1037));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 961; c0 += 1)
    for (c1 = c0 + 1038; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1038+c0] + S[-c0+c1-1038+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1037+c0] + S[1037+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 961; c0 += 1)
    S[c0][c0+1038] = MAX(S[c0][c0+1038], S[c0+1][c0+1038-1] + can_pair(RNA, c0, c0+1038));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 960; c0 += 1)
    for (c1 = c0 + 1039; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1039+c0] + S[-c0+c1-1039+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1038+c0] + S[1038+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 960; c0 += 1)
    S[c0][c0+1039] = MAX(S[c0][c0+1039], S[c0+1][c0+1039-1] + can_pair(RNA, c0, c0+1039));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 959; c0 += 1)
    for (c1 = c0 + 1040; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1040+c0] + S[-c0+c1-1040+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1039+c0] + S[1039+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 959; c0 += 1)
    S[c0][c0+1040] = MAX(S[c0][c0+1040], S[c0+1][c0+1040-1] + can_pair(RNA, c0, c0+1040));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 958; c0 += 1)
    for (c1 = c0 + 1041; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1041+c0] + S[-c0+c1-1041+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1040+c0] + S[1040+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 958; c0 += 1)
    S[c0][c0+1041] = MAX(S[c0][c0+1041], S[c0+1][c0+1041-1] + can_pair(RNA, c0, c0+1041));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 957; c0 += 1)
    for (c1 = c0 + 1042; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1042+c0] + S[-c0+c1-1042+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1041+c0] + S[1041+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 957; c0 += 1)
    S[c0][c0+1042] = MAX(S[c0][c0+1042], S[c0+1][c0+1042-1] + can_pair(RNA, c0, c0+1042));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 956; c0 += 1)
    for (c1 = c0 + 1043; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1043+c0] + S[-c0+c1-1043+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1042+c0] + S[1042+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 956; c0 += 1)
    S[c0][c0+1043] = MAX(S[c0][c0+1043], S[c0+1][c0+1043-1] + can_pair(RNA, c0, c0+1043));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 955; c0 += 1)
    for (c1 = c0 + 1044; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1044+c0] + S[-c0+c1-1044+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1043+c0] + S[1043+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 955; c0 += 1)
    S[c0][c0+1044] = MAX(S[c0][c0+1044], S[c0+1][c0+1044-1] + can_pair(RNA, c0, c0+1044));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 954; c0 += 1)
    for (c1 = c0 + 1045; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1045+c0] + S[-c0+c1-1045+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1044+c0] + S[1044+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 954; c0 += 1)
    S[c0][c0+1045] = MAX(S[c0][c0+1045], S[c0+1][c0+1045-1] + can_pair(RNA, c0, c0+1045));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 953; c0 += 1)
    for (c1 = c0 + 1046; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1046+c0] + S[-c0+c1-1046+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1045+c0] + S[1045+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 953; c0 += 1)
    S[c0][c0+1046] = MAX(S[c0][c0+1046], S[c0+1][c0+1046-1] + can_pair(RNA, c0, c0+1046));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 952; c0 += 1)
    for (c1 = c0 + 1047; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1047+c0] + S[-c0+c1-1047+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1046+c0] + S[1046+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 952; c0 += 1)
    S[c0][c0+1047] = MAX(S[c0][c0+1047], S[c0+1][c0+1047-1] + can_pair(RNA, c0, c0+1047));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 951; c0 += 1)
    for (c1 = c0 + 1048; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1048+c0] + S[-c0+c1-1048+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1047+c0] + S[1047+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 951; c0 += 1)
    S[c0][c0+1048] = MAX(S[c0][c0+1048], S[c0+1][c0+1048-1] + can_pair(RNA, c0, c0+1048));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 950; c0 += 1)
    for (c1 = c0 + 1049; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1049+c0] + S[-c0+c1-1049+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1048+c0] + S[1048+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 950; c0 += 1)
    S[c0][c0+1049] = MAX(S[c0][c0+1049], S[c0+1][c0+1049-1] + can_pair(RNA, c0, c0+1049));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 949; c0 += 1)
    for (c1 = c0 + 1050; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1050+c0] + S[-c0+c1-1050+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1049+c0] + S[1049+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 949; c0 += 1)
    S[c0][c0+1050] = MAX(S[c0][c0+1050], S[c0+1][c0+1050-1] + can_pair(RNA, c0, c0+1050));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 948; c0 += 1)
    for (c1 = c0 + 1051; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1051+c0] + S[-c0+c1-1051+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1050+c0] + S[1050+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 948; c0 += 1)
    S[c0][c0+1051] = MAX(S[c0][c0+1051], S[c0+1][c0+1051-1] + can_pair(RNA, c0, c0+1051));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 947; c0 += 1)
    for (c1 = c0 + 1052; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1052+c0] + S[-c0+c1-1052+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1051+c0] + S[1051+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 947; c0 += 1)
    S[c0][c0+1052] = MAX(S[c0][c0+1052], S[c0+1][c0+1052-1] + can_pair(RNA, c0, c0+1052));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 946; c0 += 1)
    for (c1 = c0 + 1053; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1053+c0] + S[-c0+c1-1053+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1052+c0] + S[1052+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 946; c0 += 1)
    S[c0][c0+1053] = MAX(S[c0][c0+1053], S[c0+1][c0+1053-1] + can_pair(RNA, c0, c0+1053));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 945; c0 += 1)
    for (c1 = c0 + 1054; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1054+c0] + S[-c0+c1-1054+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1053+c0] + S[1053+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 945; c0 += 1)
    S[c0][c0+1054] = MAX(S[c0][c0+1054], S[c0+1][c0+1054-1] + can_pair(RNA, c0, c0+1054));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 944; c0 += 1)
    for (c1 = c0 + 1055; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1055+c0] + S[-c0+c1-1055+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1054+c0] + S[1054+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 944; c0 += 1)
    S[c0][c0+1055] = MAX(S[c0][c0+1055], S[c0+1][c0+1055-1] + can_pair(RNA, c0, c0+1055));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 943; c0 += 1)
    for (c1 = c0 + 1056; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1056+c0] + S[-c0+c1-1056+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1055+c0] + S[1055+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 943; c0 += 1)
    S[c0][c0+1056] = MAX(S[c0][c0+1056], S[c0+1][c0+1056-1] + can_pair(RNA, c0, c0+1056));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 942; c0 += 1)
    for (c1 = c0 + 1057; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1057+c0] + S[-c0+c1-1057+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1056+c0] + S[1056+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 942; c0 += 1)
    S[c0][c0+1057] = MAX(S[c0][c0+1057], S[c0+1][c0+1057-1] + can_pair(RNA, c0, c0+1057));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 941; c0 += 1)
    for (c1 = c0 + 1058; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1058+c0] + S[-c0+c1-1058+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1057+c0] + S[1057+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 941; c0 += 1)
    S[c0][c0+1058] = MAX(S[c0][c0+1058], S[c0+1][c0+1058-1] + can_pair(RNA, c0, c0+1058));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 940; c0 += 1)
    for (c1 = c0 + 1059; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1059+c0] + S[-c0+c1-1059+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1058+c0] + S[1058+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 940; c0 += 1)
    S[c0][c0+1059] = MAX(S[c0][c0+1059], S[c0+1][c0+1059-1] + can_pair(RNA, c0, c0+1059));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 939; c0 += 1)
    for (c1 = c0 + 1060; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1060+c0] + S[-c0+c1-1060+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1059+c0] + S[1059+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 939; c0 += 1)
    S[c0][c0+1060] = MAX(S[c0][c0+1060], S[c0+1][c0+1060-1] + can_pair(RNA, c0, c0+1060));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 938; c0 += 1)
    for (c1 = c0 + 1061; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1061+c0] + S[-c0+c1-1061+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1060+c0] + S[1060+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 938; c0 += 1)
    S[c0][c0+1061] = MAX(S[c0][c0+1061], S[c0+1][c0+1061-1] + can_pair(RNA, c0, c0+1061));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 937; c0 += 1)
    for (c1 = c0 + 1062; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1062+c0] + S[-c0+c1-1062+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1061+c0] + S[1061+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 937; c0 += 1)
    S[c0][c0+1062] = MAX(S[c0][c0+1062], S[c0+1][c0+1062-1] + can_pair(RNA, c0, c0+1062));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 936; c0 += 1)
    for (c1 = c0 + 1063; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1063+c0] + S[-c0+c1-1063+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1062+c0] + S[1062+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 936; c0 += 1)
    S[c0][c0+1063] = MAX(S[c0][c0+1063], S[c0+1][c0+1063-1] + can_pair(RNA, c0, c0+1063));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 935; c0 += 1)
    for (c1 = c0 + 1064; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1064+c0] + S[-c0+c1-1064+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1063+c0] + S[1063+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 935; c0 += 1)
    S[c0][c0+1064] = MAX(S[c0][c0+1064], S[c0+1][c0+1064-1] + can_pair(RNA, c0, c0+1064));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 934; c0 += 1)
    for (c1 = c0 + 1065; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1065+c0] + S[-c0+c1-1065+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1064+c0] + S[1064+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 934; c0 += 1)
    S[c0][c0+1065] = MAX(S[c0][c0+1065], S[c0+1][c0+1065-1] + can_pair(RNA, c0, c0+1065));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 933; c0 += 1)
    for (c1 = c0 + 1066; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1066+c0] + S[-c0+c1-1066+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1065+c0] + S[1065+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 933; c0 += 1)
    S[c0][c0+1066] = MAX(S[c0][c0+1066], S[c0+1][c0+1066-1] + can_pair(RNA, c0, c0+1066));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 932; c0 += 1)
    for (c1 = c0 + 1067; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1067+c0] + S[-c0+c1-1067+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1066+c0] + S[1066+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 932; c0 += 1)
    S[c0][c0+1067] = MAX(S[c0][c0+1067], S[c0+1][c0+1067-1] + can_pair(RNA, c0, c0+1067));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 931; c0 += 1)
    for (c1 = c0 + 1068; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1068+c0] + S[-c0+c1-1068+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1067+c0] + S[1067+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 931; c0 += 1)
    S[c0][c0+1068] = MAX(S[c0][c0+1068], S[c0+1][c0+1068-1] + can_pair(RNA, c0, c0+1068));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 930; c0 += 1)
    for (c1 = c0 + 1069; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1069+c0] + S[-c0+c1-1069+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1068+c0] + S[1068+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 930; c0 += 1)
    S[c0][c0+1069] = MAX(S[c0][c0+1069], S[c0+1][c0+1069-1] + can_pair(RNA, c0, c0+1069));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 929; c0 += 1)
    for (c1 = c0 + 1070; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1070+c0] + S[-c0+c1-1070+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1069+c0] + S[1069+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 929; c0 += 1)
    S[c0][c0+1070] = MAX(S[c0][c0+1070], S[c0+1][c0+1070-1] + can_pair(RNA, c0, c0+1070));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 928; c0 += 1)
    for (c1 = c0 + 1071; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1071+c0] + S[-c0+c1-1071+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1070+c0] + S[1070+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 928; c0 += 1)
    S[c0][c0+1071] = MAX(S[c0][c0+1071], S[c0+1][c0+1071-1] + can_pair(RNA, c0, c0+1071));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 927; c0 += 1)
    for (c1 = c0 + 1072; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1072+c0] + S[-c0+c1-1072+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1071+c0] + S[1071+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 927; c0 += 1)
    S[c0][c0+1072] = MAX(S[c0][c0+1072], S[c0+1][c0+1072-1] + can_pair(RNA, c0, c0+1072));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 926; c0 += 1)
    for (c1 = c0 + 1073; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1073+c0] + S[-c0+c1-1073+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1072+c0] + S[1072+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 926; c0 += 1)
    S[c0][c0+1073] = MAX(S[c0][c0+1073], S[c0+1][c0+1073-1] + can_pair(RNA, c0, c0+1073));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 925; c0 += 1)
    for (c1 = c0 + 1074; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1074+c0] + S[-c0+c1-1074+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1073+c0] + S[1073+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 925; c0 += 1)
    S[c0][c0+1074] = MAX(S[c0][c0+1074], S[c0+1][c0+1074-1] + can_pair(RNA, c0, c0+1074));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 924; c0 += 1)
    for (c1 = c0 + 1075; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1075+c0] + S[-c0+c1-1075+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1074+c0] + S[1074+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 924; c0 += 1)
    S[c0][c0+1075] = MAX(S[c0][c0+1075], S[c0+1][c0+1075-1] + can_pair(RNA, c0, c0+1075));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 923; c0 += 1)
    for (c1 = c0 + 1076; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1076+c0] + S[-c0+c1-1076+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1075+c0] + S[1075+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 923; c0 += 1)
    S[c0][c0+1076] = MAX(S[c0][c0+1076], S[c0+1][c0+1076-1] + can_pair(RNA, c0, c0+1076));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 922; c0 += 1)
    for (c1 = c0 + 1077; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1077+c0] + S[-c0+c1-1077+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1076+c0] + S[1076+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 922; c0 += 1)
    S[c0][c0+1077] = MAX(S[c0][c0+1077], S[c0+1][c0+1077-1] + can_pair(RNA, c0, c0+1077));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 921; c0 += 1)
    for (c1 = c0 + 1078; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1078+c0] + S[-c0+c1-1078+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1077+c0] + S[1077+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 921; c0 += 1)
    S[c0][c0+1078] = MAX(S[c0][c0+1078], S[c0+1][c0+1078-1] + can_pair(RNA, c0, c0+1078));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 920; c0 += 1)
    for (c1 = c0 + 1079; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1079+c0] + S[-c0+c1-1079+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1078+c0] + S[1078+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 920; c0 += 1)
    S[c0][c0+1079] = MAX(S[c0][c0+1079], S[c0+1][c0+1079-1] + can_pair(RNA, c0, c0+1079));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 919; c0 += 1)
    for (c1 = c0 + 1080; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1080+c0] + S[-c0+c1-1080+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1079+c0] + S[1079+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 919; c0 += 1)
    S[c0][c0+1080] = MAX(S[c0][c0+1080], S[c0+1][c0+1080-1] + can_pair(RNA, c0, c0+1080));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 918; c0 += 1)
    for (c1 = c0 + 1081; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1081+c0] + S[-c0+c1-1081+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1080+c0] + S[1080+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 918; c0 += 1)
    S[c0][c0+1081] = MAX(S[c0][c0+1081], S[c0+1][c0+1081-1] + can_pair(RNA, c0, c0+1081));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 917; c0 += 1)
    for (c1 = c0 + 1082; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1082+c0] + S[-c0+c1-1082+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1081+c0] + S[1081+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 917; c0 += 1)
    S[c0][c0+1082] = MAX(S[c0][c0+1082], S[c0+1][c0+1082-1] + can_pair(RNA, c0, c0+1082));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 916; c0 += 1)
    for (c1 = c0 + 1083; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1083+c0] + S[-c0+c1-1083+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1082+c0] + S[1082+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 916; c0 += 1)
    S[c0][c0+1083] = MAX(S[c0][c0+1083], S[c0+1][c0+1083-1] + can_pair(RNA, c0, c0+1083));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 915; c0 += 1)
    for (c1 = c0 + 1084; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1084+c0] + S[-c0+c1-1084+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1083+c0] + S[1083+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 915; c0 += 1)
    S[c0][c0+1084] = MAX(S[c0][c0+1084], S[c0+1][c0+1084-1] + can_pair(RNA, c0, c0+1084));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 914; c0 += 1)
    for (c1 = c0 + 1085; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1085+c0] + S[-c0+c1-1085+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1084+c0] + S[1084+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 914; c0 += 1)
    S[c0][c0+1085] = MAX(S[c0][c0+1085], S[c0+1][c0+1085-1] + can_pair(RNA, c0, c0+1085));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 913; c0 += 1)
    for (c1 = c0 + 1086; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1086+c0] + S[-c0+c1-1086+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1085+c0] + S[1085+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 913; c0 += 1)
    S[c0][c0+1086] = MAX(S[c0][c0+1086], S[c0+1][c0+1086-1] + can_pair(RNA, c0, c0+1086));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 912; c0 += 1)
    for (c1 = c0 + 1087; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1087+c0] + S[-c0+c1-1087+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1086+c0] + S[1086+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 912; c0 += 1)
    S[c0][c0+1087] = MAX(S[c0][c0+1087], S[c0+1][c0+1087-1] + can_pair(RNA, c0, c0+1087));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 911; c0 += 1)
    for (c1 = c0 + 1088; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1088+c0] + S[-c0+c1-1088+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1087+c0] + S[1087+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 911; c0 += 1)
    S[c0][c0+1088] = MAX(S[c0][c0+1088], S[c0+1][c0+1088-1] + can_pair(RNA, c0, c0+1088));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 910; c0 += 1)
    for (c1 = c0 + 1089; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1089+c0] + S[-c0+c1-1089+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1088+c0] + S[1088+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 910; c0 += 1)
    S[c0][c0+1089] = MAX(S[c0][c0+1089], S[c0+1][c0+1089-1] + can_pair(RNA, c0, c0+1089));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 909; c0 += 1)
    for (c1 = c0 + 1090; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1090+c0] + S[-c0+c1-1090+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1089+c0] + S[1089+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 909; c0 += 1)
    S[c0][c0+1090] = MAX(S[c0][c0+1090], S[c0+1][c0+1090-1] + can_pair(RNA, c0, c0+1090));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 908; c0 += 1)
    for (c1 = c0 + 1091; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1091+c0] + S[-c0+c1-1091+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1090+c0] + S[1090+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 908; c0 += 1)
    S[c0][c0+1091] = MAX(S[c0][c0+1091], S[c0+1][c0+1091-1] + can_pair(RNA, c0, c0+1091));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 907; c0 += 1)
    for (c1 = c0 + 1092; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1092+c0] + S[-c0+c1-1092+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1091+c0] + S[1091+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 907; c0 += 1)
    S[c0][c0+1092] = MAX(S[c0][c0+1092], S[c0+1][c0+1092-1] + can_pair(RNA, c0, c0+1092));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 906; c0 += 1)
    for (c1 = c0 + 1093; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1093+c0] + S[-c0+c1-1093+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1092+c0] + S[1092+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 906; c0 += 1)
    S[c0][c0+1093] = MAX(S[c0][c0+1093], S[c0+1][c0+1093-1] + can_pair(RNA, c0, c0+1093));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 905; c0 += 1)
    for (c1 = c0 + 1094; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1094+c0] + S[-c0+c1-1094+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1093+c0] + S[1093+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 905; c0 += 1)
    S[c0][c0+1094] = MAX(S[c0][c0+1094], S[c0+1][c0+1094-1] + can_pair(RNA, c0, c0+1094));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 904; c0 += 1)
    for (c1 = c0 + 1095; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1095+c0] + S[-c0+c1-1095+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1094+c0] + S[1094+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 904; c0 += 1)
    S[c0][c0+1095] = MAX(S[c0][c0+1095], S[c0+1][c0+1095-1] + can_pair(RNA, c0, c0+1095));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 903; c0 += 1)
    for (c1 = c0 + 1096; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1096+c0] + S[-c0+c1-1096+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1095+c0] + S[1095+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 903; c0 += 1)
    S[c0][c0+1096] = MAX(S[c0][c0+1096], S[c0+1][c0+1096-1] + can_pair(RNA, c0, c0+1096));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 902; c0 += 1)
    for (c1 = c0 + 1097; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1097+c0] + S[-c0+c1-1097+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1096+c0] + S[1096+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 902; c0 += 1)
    S[c0][c0+1097] = MAX(S[c0][c0+1097], S[c0+1][c0+1097-1] + can_pair(RNA, c0, c0+1097));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 901; c0 += 1)
    for (c1 = c0 + 1098; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1098+c0] + S[-c0+c1-1098+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1097+c0] + S[1097+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 901; c0 += 1)
    S[c0][c0+1098] = MAX(S[c0][c0+1098], S[c0+1][c0+1098-1] + can_pair(RNA, c0, c0+1098));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 900; c0 += 1)
    for (c1 = c0 + 1099; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1099+c0] + S[-c0+c1-1099+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1098+c0] + S[1098+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 900; c0 += 1)
    S[c0][c0+1099] = MAX(S[c0][c0+1099], S[c0+1][c0+1099-1] + can_pair(RNA, c0, c0+1099));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 899; c0 += 1)
    for (c1 = c0 + 1100; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1100+c0] + S[-c0+c1-1100+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1099+c0] + S[1099+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 899; c0 += 1)
    S[c0][c0+1100] = MAX(S[c0][c0+1100], S[c0+1][c0+1100-1] + can_pair(RNA, c0, c0+1100));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 898; c0 += 1)
    for (c1 = c0 + 1101; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1101+c0] + S[-c0+c1-1101+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1100+c0] + S[1100+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 898; c0 += 1)
    S[c0][c0+1101] = MAX(S[c0][c0+1101], S[c0+1][c0+1101-1] + can_pair(RNA, c0, c0+1101));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 897; c0 += 1)
    for (c1 = c0 + 1102; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1102+c0] + S[-c0+c1-1102+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1101+c0] + S[1101+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 897; c0 += 1)
    S[c0][c0+1102] = MAX(S[c0][c0+1102], S[c0+1][c0+1102-1] + can_pair(RNA, c0, c0+1102));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 896; c0 += 1)
    for (c1 = c0 + 1103; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1103+c0] + S[-c0+c1-1103+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1102+c0] + S[1102+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 896; c0 += 1)
    S[c0][c0+1103] = MAX(S[c0][c0+1103], S[c0+1][c0+1103-1] + can_pair(RNA, c0, c0+1103));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 895; c0 += 1)
    for (c1 = c0 + 1104; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1104+c0] + S[-c0+c1-1104+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1103+c0] + S[1103+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 895; c0 += 1)
    S[c0][c0+1104] = MAX(S[c0][c0+1104], S[c0+1][c0+1104-1] + can_pair(RNA, c0, c0+1104));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 894; c0 += 1)
    for (c1 = c0 + 1105; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1105+c0] + S[-c0+c1-1105+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1104+c0] + S[1104+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 894; c0 += 1)
    S[c0][c0+1105] = MAX(S[c0][c0+1105], S[c0+1][c0+1105-1] + can_pair(RNA, c0, c0+1105));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 893; c0 += 1)
    for (c1 = c0 + 1106; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1106+c0] + S[-c0+c1-1106+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1105+c0] + S[1105+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 893; c0 += 1)
    S[c0][c0+1106] = MAX(S[c0][c0+1106], S[c0+1][c0+1106-1] + can_pair(RNA, c0, c0+1106));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 892; c0 += 1)
    for (c1 = c0 + 1107; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1107+c0] + S[-c0+c1-1107+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1106+c0] + S[1106+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 892; c0 += 1)
    S[c0][c0+1107] = MAX(S[c0][c0+1107], S[c0+1][c0+1107-1] + can_pair(RNA, c0, c0+1107));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 891; c0 += 1)
    for (c1 = c0 + 1108; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1108+c0] + S[-c0+c1-1108+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1107+c0] + S[1107+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 891; c0 += 1)
    S[c0][c0+1108] = MAX(S[c0][c0+1108], S[c0+1][c0+1108-1] + can_pair(RNA, c0, c0+1108));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 890; c0 += 1)
    for (c1 = c0 + 1109; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1109+c0] + S[-c0+c1-1109+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1108+c0] + S[1108+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 890; c0 += 1)
    S[c0][c0+1109] = MAX(S[c0][c0+1109], S[c0+1][c0+1109-1] + can_pair(RNA, c0, c0+1109));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 889; c0 += 1)
    for (c1 = c0 + 1110; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1110+c0] + S[-c0+c1-1110+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1109+c0] + S[1109+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 889; c0 += 1)
    S[c0][c0+1110] = MAX(S[c0][c0+1110], S[c0+1][c0+1110-1] + can_pair(RNA, c0, c0+1110));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 888; c0 += 1)
    for (c1 = c0 + 1111; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1111+c0] + S[-c0+c1-1111+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1110+c0] + S[1110+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 888; c0 += 1)
    S[c0][c0+1111] = MAX(S[c0][c0+1111], S[c0+1][c0+1111-1] + can_pair(RNA, c0, c0+1111));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 887; c0 += 1)
    for (c1 = c0 + 1112; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1112+c0] + S[-c0+c1-1112+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1111+c0] + S[1111+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 887; c0 += 1)
    S[c0][c0+1112] = MAX(S[c0][c0+1112], S[c0+1][c0+1112-1] + can_pair(RNA, c0, c0+1112));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 886; c0 += 1)
    for (c1 = c0 + 1113; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1113+c0] + S[-c0+c1-1113+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1112+c0] + S[1112+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 886; c0 += 1)
    S[c0][c0+1113] = MAX(S[c0][c0+1113], S[c0+1][c0+1113-1] + can_pair(RNA, c0, c0+1113));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 885; c0 += 1)
    for (c1 = c0 + 1114; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1114+c0] + S[-c0+c1-1114+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1113+c0] + S[1113+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 885; c0 += 1)
    S[c0][c0+1114] = MAX(S[c0][c0+1114], S[c0+1][c0+1114-1] + can_pair(RNA, c0, c0+1114));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 884; c0 += 1)
    for (c1 = c0 + 1115; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1115+c0] + S[-c0+c1-1115+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1114+c0] + S[1114+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 884; c0 += 1)
    S[c0][c0+1115] = MAX(S[c0][c0+1115], S[c0+1][c0+1115-1] + can_pair(RNA, c0, c0+1115));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 883; c0 += 1)
    for (c1 = c0 + 1116; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1116+c0] + S[-c0+c1-1116+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1115+c0] + S[1115+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 883; c0 += 1)
    S[c0][c0+1116] = MAX(S[c0][c0+1116], S[c0+1][c0+1116-1] + can_pair(RNA, c0, c0+1116));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 882; c0 += 1)
    for (c1 = c0 + 1117; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1117+c0] + S[-c0+c1-1117+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1116+c0] + S[1116+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 882; c0 += 1)
    S[c0][c0+1117] = MAX(S[c0][c0+1117], S[c0+1][c0+1117-1] + can_pair(RNA, c0, c0+1117));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 881; c0 += 1)
    for (c1 = c0 + 1118; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1118+c0] + S[-c0+c1-1118+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1117+c0] + S[1117+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 881; c0 += 1)
    S[c0][c0+1118] = MAX(S[c0][c0+1118], S[c0+1][c0+1118-1] + can_pair(RNA, c0, c0+1118));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 880; c0 += 1)
    for (c1 = c0 + 1119; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1119+c0] + S[-c0+c1-1119+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1118+c0] + S[1118+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 880; c0 += 1)
    S[c0][c0+1119] = MAX(S[c0][c0+1119], S[c0+1][c0+1119-1] + can_pair(RNA, c0, c0+1119));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 879; c0 += 1)
    for (c1 = c0 + 1120; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1120+c0] + S[-c0+c1-1120+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1119+c0] + S[1119+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 879; c0 += 1)
    S[c0][c0+1120] = MAX(S[c0][c0+1120], S[c0+1][c0+1120-1] + can_pair(RNA, c0, c0+1120));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 878; c0 += 1)
    for (c1 = c0 + 1121; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1121+c0] + S[-c0+c1-1121+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1120+c0] + S[1120+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 878; c0 += 1)
    S[c0][c0+1121] = MAX(S[c0][c0+1121], S[c0+1][c0+1121-1] + can_pair(RNA, c0, c0+1121));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 877; c0 += 1)
    for (c1 = c0 + 1122; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1122+c0] + S[-c0+c1-1122+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1121+c0] + S[1121+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 877; c0 += 1)
    S[c0][c0+1122] = MAX(S[c0][c0+1122], S[c0+1][c0+1122-1] + can_pair(RNA, c0, c0+1122));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 876; c0 += 1)
    for (c1 = c0 + 1123; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1123+c0] + S[-c0+c1-1123+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1122+c0] + S[1122+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 876; c0 += 1)
    S[c0][c0+1123] = MAX(S[c0][c0+1123], S[c0+1][c0+1123-1] + can_pair(RNA, c0, c0+1123));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 875; c0 += 1)
    for (c1 = c0 + 1124; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1124+c0] + S[-c0+c1-1124+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1123+c0] + S[1123+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 875; c0 += 1)
    S[c0][c0+1124] = MAX(S[c0][c0+1124], S[c0+1][c0+1124-1] + can_pair(RNA, c0, c0+1124));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 874; c0 += 1)
    for (c1 = c0 + 1125; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1125+c0] + S[-c0+c1-1125+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1124+c0] + S[1124+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 874; c0 += 1)
    S[c0][c0+1125] = MAX(S[c0][c0+1125], S[c0+1][c0+1125-1] + can_pair(RNA, c0, c0+1125));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 873; c0 += 1)
    for (c1 = c0 + 1126; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1126+c0] + S[-c0+c1-1126+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1125+c0] + S[1125+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 873; c0 += 1)
    S[c0][c0+1126] = MAX(S[c0][c0+1126], S[c0+1][c0+1126-1] + can_pair(RNA, c0, c0+1126));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 872; c0 += 1)
    for (c1 = c0 + 1127; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1127+c0] + S[-c0+c1-1127+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1126+c0] + S[1126+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 872; c0 += 1)
    S[c0][c0+1127] = MAX(S[c0][c0+1127], S[c0+1][c0+1127-1] + can_pair(RNA, c0, c0+1127));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 871; c0 += 1)
    for (c1 = c0 + 1128; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1128+c0] + S[-c0+c1-1128+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1127+c0] + S[1127+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 871; c0 += 1)
    S[c0][c0+1128] = MAX(S[c0][c0+1128], S[c0+1][c0+1128-1] + can_pair(RNA, c0, c0+1128));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 870; c0 += 1)
    for (c1 = c0 + 1129; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1129+c0] + S[-c0+c1-1129+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1128+c0] + S[1128+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 870; c0 += 1)
    S[c0][c0+1129] = MAX(S[c0][c0+1129], S[c0+1][c0+1129-1] + can_pair(RNA, c0, c0+1129));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 869; c0 += 1)
    for (c1 = c0 + 1130; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1130+c0] + S[-c0+c1-1130+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1129+c0] + S[1129+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 869; c0 += 1)
    S[c0][c0+1130] = MAX(S[c0][c0+1130], S[c0+1][c0+1130-1] + can_pair(RNA, c0, c0+1130));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 868; c0 += 1)
    for (c1 = c0 + 1131; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1131+c0] + S[-c0+c1-1131+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1130+c0] + S[1130+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 868; c0 += 1)
    S[c0][c0+1131] = MAX(S[c0][c0+1131], S[c0+1][c0+1131-1] + can_pair(RNA, c0, c0+1131));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 867; c0 += 1)
    for (c1 = c0 + 1132; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1132+c0] + S[-c0+c1-1132+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1131+c0] + S[1131+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 867; c0 += 1)
    S[c0][c0+1132] = MAX(S[c0][c0+1132], S[c0+1][c0+1132-1] + can_pair(RNA, c0, c0+1132));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 866; c0 += 1)
    for (c1 = c0 + 1133; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1133+c0] + S[-c0+c1-1133+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1132+c0] + S[1132+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 866; c0 += 1)
    S[c0][c0+1133] = MAX(S[c0][c0+1133], S[c0+1][c0+1133-1] + can_pair(RNA, c0, c0+1133));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 865; c0 += 1)
    for (c1 = c0 + 1134; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1134+c0] + S[-c0+c1-1134+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1133+c0] + S[1133+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 865; c0 += 1)
    S[c0][c0+1134] = MAX(S[c0][c0+1134], S[c0+1][c0+1134-1] + can_pair(RNA, c0, c0+1134));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 864; c0 += 1)
    for (c1 = c0 + 1135; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1135+c0] + S[-c0+c1-1135+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1134+c0] + S[1134+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 864; c0 += 1)
    S[c0][c0+1135] = MAX(S[c0][c0+1135], S[c0+1][c0+1135-1] + can_pair(RNA, c0, c0+1135));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 863; c0 += 1)
    for (c1 = c0 + 1136; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1136+c0] + S[-c0+c1-1136+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1135+c0] + S[1135+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 863; c0 += 1)
    S[c0][c0+1136] = MAX(S[c0][c0+1136], S[c0+1][c0+1136-1] + can_pair(RNA, c0, c0+1136));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 862; c0 += 1)
    for (c1 = c0 + 1137; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1137+c0] + S[-c0+c1-1137+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1136+c0] + S[1136+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 862; c0 += 1)
    S[c0][c0+1137] = MAX(S[c0][c0+1137], S[c0+1][c0+1137-1] + can_pair(RNA, c0, c0+1137));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 861; c0 += 1)
    for (c1 = c0 + 1138; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1138+c0] + S[-c0+c1-1138+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1137+c0] + S[1137+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 861; c0 += 1)
    S[c0][c0+1138] = MAX(S[c0][c0+1138], S[c0+1][c0+1138-1] + can_pair(RNA, c0, c0+1138));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 860; c0 += 1)
    for (c1 = c0 + 1139; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1139+c0] + S[-c0+c1-1139+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1138+c0] + S[1138+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 860; c0 += 1)
    S[c0][c0+1139] = MAX(S[c0][c0+1139], S[c0+1][c0+1139-1] + can_pair(RNA, c0, c0+1139));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 859; c0 += 1)
    for (c1 = c0 + 1140; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1140+c0] + S[-c0+c1-1140+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1139+c0] + S[1139+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 859; c0 += 1)
    S[c0][c0+1140] = MAX(S[c0][c0+1140], S[c0+1][c0+1140-1] + can_pair(RNA, c0, c0+1140));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 858; c0 += 1)
    for (c1 = c0 + 1141; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1141+c0] + S[-c0+c1-1141+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1140+c0] + S[1140+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 858; c0 += 1)
    S[c0][c0+1141] = MAX(S[c0][c0+1141], S[c0+1][c0+1141-1] + can_pair(RNA, c0, c0+1141));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 857; c0 += 1)
    for (c1 = c0 + 1142; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1142+c0] + S[-c0+c1-1142+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1141+c0] + S[1141+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 857; c0 += 1)
    S[c0][c0+1142] = MAX(S[c0][c0+1142], S[c0+1][c0+1142-1] + can_pair(RNA, c0, c0+1142));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 856; c0 += 1)
    for (c1 = c0 + 1143; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1143+c0] + S[-c0+c1-1143+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1142+c0] + S[1142+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 856; c0 += 1)
    S[c0][c0+1143] = MAX(S[c0][c0+1143], S[c0+1][c0+1143-1] + can_pair(RNA, c0, c0+1143));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 855; c0 += 1)
    for (c1 = c0 + 1144; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1144+c0] + S[-c0+c1-1144+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1143+c0] + S[1143+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 855; c0 += 1)
    S[c0][c0+1144] = MAX(S[c0][c0+1144], S[c0+1][c0+1144-1] + can_pair(RNA, c0, c0+1144));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 854; c0 += 1)
    for (c1 = c0 + 1145; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1145+c0] + S[-c0+c1-1145+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1144+c0] + S[1144+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 854; c0 += 1)
    S[c0][c0+1145] = MAX(S[c0][c0+1145], S[c0+1][c0+1145-1] + can_pair(RNA, c0, c0+1145));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 853; c0 += 1)
    for (c1 = c0 + 1146; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1146+c0] + S[-c0+c1-1146+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1145+c0] + S[1145+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 853; c0 += 1)
    S[c0][c0+1146] = MAX(S[c0][c0+1146], S[c0+1][c0+1146-1] + can_pair(RNA, c0, c0+1146));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 852; c0 += 1)
    for (c1 = c0 + 1147; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1147+c0] + S[-c0+c1-1147+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1146+c0] + S[1146+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 852; c0 += 1)
    S[c0][c0+1147] = MAX(S[c0][c0+1147], S[c0+1][c0+1147-1] + can_pair(RNA, c0, c0+1147));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 851; c0 += 1)
    for (c1 = c0 + 1148; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1148+c0] + S[-c0+c1-1148+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1147+c0] + S[1147+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 851; c0 += 1)
    S[c0][c0+1148] = MAX(S[c0][c0+1148], S[c0+1][c0+1148-1] + can_pair(RNA, c0, c0+1148));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 850; c0 += 1)
    for (c1 = c0 + 1149; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1149+c0] + S[-c0+c1-1149+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1148+c0] + S[1148+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 850; c0 += 1)
    S[c0][c0+1149] = MAX(S[c0][c0+1149], S[c0+1][c0+1149-1] + can_pair(RNA, c0, c0+1149));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 849; c0 += 1)
    for (c1 = c0 + 1150; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1150+c0] + S[-c0+c1-1150+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1149+c0] + S[1149+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 849; c0 += 1)
    S[c0][c0+1150] = MAX(S[c0][c0+1150], S[c0+1][c0+1150-1] + can_pair(RNA, c0, c0+1150));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 848; c0 += 1)
    for (c1 = c0 + 1151; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1151+c0] + S[-c0+c1-1151+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1150+c0] + S[1150+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 848; c0 += 1)
    S[c0][c0+1151] = MAX(S[c0][c0+1151], S[c0+1][c0+1151-1] + can_pair(RNA, c0, c0+1151));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 847; c0 += 1)
    for (c1 = c0 + 1152; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1152+c0] + S[-c0+c1-1152+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1151+c0] + S[1151+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 847; c0 += 1)
    S[c0][c0+1152] = MAX(S[c0][c0+1152], S[c0+1][c0+1152-1] + can_pair(RNA, c0, c0+1152));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 846; c0 += 1)
    for (c1 = c0 + 1153; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1153+c0] + S[-c0+c1-1153+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1152+c0] + S[1152+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 846; c0 += 1)
    S[c0][c0+1153] = MAX(S[c0][c0+1153], S[c0+1][c0+1153-1] + can_pair(RNA, c0, c0+1153));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 845; c0 += 1)
    for (c1 = c0 + 1154; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1154+c0] + S[-c0+c1-1154+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1153+c0] + S[1153+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 845; c0 += 1)
    S[c0][c0+1154] = MAX(S[c0][c0+1154], S[c0+1][c0+1154-1] + can_pair(RNA, c0, c0+1154));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 844; c0 += 1)
    for (c1 = c0 + 1155; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1155+c0] + S[-c0+c1-1155+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1154+c0] + S[1154+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 844; c0 += 1)
    S[c0][c0+1155] = MAX(S[c0][c0+1155], S[c0+1][c0+1155-1] + can_pair(RNA, c0, c0+1155));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 843; c0 += 1)
    for (c1 = c0 + 1156; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1156+c0] + S[-c0+c1-1156+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1155+c0] + S[1155+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 843; c0 += 1)
    S[c0][c0+1156] = MAX(S[c0][c0+1156], S[c0+1][c0+1156-1] + can_pair(RNA, c0, c0+1156));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 842; c0 += 1)
    for (c1 = c0 + 1157; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1157+c0] + S[-c0+c1-1157+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1156+c0] + S[1156+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 842; c0 += 1)
    S[c0][c0+1157] = MAX(S[c0][c0+1157], S[c0+1][c0+1157-1] + can_pair(RNA, c0, c0+1157));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 841; c0 += 1)
    for (c1 = c0 + 1158; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1158+c0] + S[-c0+c1-1158+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1157+c0] + S[1157+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 841; c0 += 1)
    S[c0][c0+1158] = MAX(S[c0][c0+1158], S[c0+1][c0+1158-1] + can_pair(RNA, c0, c0+1158));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 840; c0 += 1)
    for (c1 = c0 + 1159; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1159+c0] + S[-c0+c1-1159+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1158+c0] + S[1158+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 840; c0 += 1)
    S[c0][c0+1159] = MAX(S[c0][c0+1159], S[c0+1][c0+1159-1] + can_pair(RNA, c0, c0+1159));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 839; c0 += 1)
    for (c1 = c0 + 1160; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1160+c0] + S[-c0+c1-1160+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1159+c0] + S[1159+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 839; c0 += 1)
    S[c0][c0+1160] = MAX(S[c0][c0+1160], S[c0+1][c0+1160-1] + can_pair(RNA, c0, c0+1160));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 838; c0 += 1)
    for (c1 = c0 + 1161; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1161+c0] + S[-c0+c1-1161+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1160+c0] + S[1160+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 838; c0 += 1)
    S[c0][c0+1161] = MAX(S[c0][c0+1161], S[c0+1][c0+1161-1] + can_pair(RNA, c0, c0+1161));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 837; c0 += 1)
    for (c1 = c0 + 1162; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1162+c0] + S[-c0+c1-1162+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1161+c0] + S[1161+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 837; c0 += 1)
    S[c0][c0+1162] = MAX(S[c0][c0+1162], S[c0+1][c0+1162-1] + can_pair(RNA, c0, c0+1162));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 836; c0 += 1)
    for (c1 = c0 + 1163; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1163+c0] + S[-c0+c1-1163+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1162+c0] + S[1162+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 836; c0 += 1)
    S[c0][c0+1163] = MAX(S[c0][c0+1163], S[c0+1][c0+1163-1] + can_pair(RNA, c0, c0+1163));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 835; c0 += 1)
    for (c1 = c0 + 1164; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1164+c0] + S[-c0+c1-1164+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1163+c0] + S[1163+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 835; c0 += 1)
    S[c0][c0+1164] = MAX(S[c0][c0+1164], S[c0+1][c0+1164-1] + can_pair(RNA, c0, c0+1164));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 834; c0 += 1)
    for (c1 = c0 + 1165; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1165+c0] + S[-c0+c1-1165+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1164+c0] + S[1164+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 834; c0 += 1)
    S[c0][c0+1165] = MAX(S[c0][c0+1165], S[c0+1][c0+1165-1] + can_pair(RNA, c0, c0+1165));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 833; c0 += 1)
    for (c1 = c0 + 1166; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1166+c0] + S[-c0+c1-1166+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1165+c0] + S[1165+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 833; c0 += 1)
    S[c0][c0+1166] = MAX(S[c0][c0+1166], S[c0+1][c0+1166-1] + can_pair(RNA, c0, c0+1166));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 832; c0 += 1)
    for (c1 = c0 + 1167; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1167+c0] + S[-c0+c1-1167+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1166+c0] + S[1166+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 832; c0 += 1)
    S[c0][c0+1167] = MAX(S[c0][c0+1167], S[c0+1][c0+1167-1] + can_pair(RNA, c0, c0+1167));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 831; c0 += 1)
    for (c1 = c0 + 1168; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1168+c0] + S[-c0+c1-1168+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1167+c0] + S[1167+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 831; c0 += 1)
    S[c0][c0+1168] = MAX(S[c0][c0+1168], S[c0+1][c0+1168-1] + can_pair(RNA, c0, c0+1168));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 830; c0 += 1)
    for (c1 = c0 + 1169; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1169+c0] + S[-c0+c1-1169+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1168+c0] + S[1168+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 830; c0 += 1)
    S[c0][c0+1169] = MAX(S[c0][c0+1169], S[c0+1][c0+1169-1] + can_pair(RNA, c0, c0+1169));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 829; c0 += 1)
    for (c1 = c0 + 1170; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1170+c0] + S[-c0+c1-1170+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1169+c0] + S[1169+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 829; c0 += 1)
    S[c0][c0+1170] = MAX(S[c0][c0+1170], S[c0+1][c0+1170-1] + can_pair(RNA, c0, c0+1170));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 828; c0 += 1)
    for (c1 = c0 + 1171; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1171+c0] + S[-c0+c1-1171+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1170+c0] + S[1170+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 828; c0 += 1)
    S[c0][c0+1171] = MAX(S[c0][c0+1171], S[c0+1][c0+1171-1] + can_pair(RNA, c0, c0+1171));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 827; c0 += 1)
    for (c1 = c0 + 1172; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1172+c0] + S[-c0+c1-1172+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1171+c0] + S[1171+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 827; c0 += 1)
    S[c0][c0+1172] = MAX(S[c0][c0+1172], S[c0+1][c0+1172-1] + can_pair(RNA, c0, c0+1172));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 826; c0 += 1)
    for (c1 = c0 + 1173; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1173+c0] + S[-c0+c1-1173+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1172+c0] + S[1172+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 826; c0 += 1)
    S[c0][c0+1173] = MAX(S[c0][c0+1173], S[c0+1][c0+1173-1] + can_pair(RNA, c0, c0+1173));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 825; c0 += 1)
    for (c1 = c0 + 1174; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1174+c0] + S[-c0+c1-1174+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1173+c0] + S[1173+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 825; c0 += 1)
    S[c0][c0+1174] = MAX(S[c0][c0+1174], S[c0+1][c0+1174-1] + can_pair(RNA, c0, c0+1174));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 824; c0 += 1)
    for (c1 = c0 + 1175; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1175+c0] + S[-c0+c1-1175+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1174+c0] + S[1174+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 824; c0 += 1)
    S[c0][c0+1175] = MAX(S[c0][c0+1175], S[c0+1][c0+1175-1] + can_pair(RNA, c0, c0+1175));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 823; c0 += 1)
    for (c1 = c0 + 1176; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1176+c0] + S[-c0+c1-1176+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1175+c0] + S[1175+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 823; c0 += 1)
    S[c0][c0+1176] = MAX(S[c0][c0+1176], S[c0+1][c0+1176-1] + can_pair(RNA, c0, c0+1176));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 822; c0 += 1)
    for (c1 = c0 + 1177; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1177+c0] + S[-c0+c1-1177+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1176+c0] + S[1176+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 822; c0 += 1)
    S[c0][c0+1177] = MAX(S[c0][c0+1177], S[c0+1][c0+1177-1] + can_pair(RNA, c0, c0+1177));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 821; c0 += 1)
    for (c1 = c0 + 1178; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1178+c0] + S[-c0+c1-1178+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1177+c0] + S[1177+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 821; c0 += 1)
    S[c0][c0+1178] = MAX(S[c0][c0+1178], S[c0+1][c0+1178-1] + can_pair(RNA, c0, c0+1178));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 820; c0 += 1)
    for (c1 = c0 + 1179; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1179+c0] + S[-c0+c1-1179+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1178+c0] + S[1178+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 820; c0 += 1)
    S[c0][c0+1179] = MAX(S[c0][c0+1179], S[c0+1][c0+1179-1] + can_pair(RNA, c0, c0+1179));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 819; c0 += 1)
    for (c1 = c0 + 1180; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1180+c0] + S[-c0+c1-1180+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1179+c0] + S[1179+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 819; c0 += 1)
    S[c0][c0+1180] = MAX(S[c0][c0+1180], S[c0+1][c0+1180-1] + can_pair(RNA, c0, c0+1180));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 818; c0 += 1)
    for (c1 = c0 + 1181; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1181+c0] + S[-c0+c1-1181+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1180+c0] + S[1180+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 818; c0 += 1)
    S[c0][c0+1181] = MAX(S[c0][c0+1181], S[c0+1][c0+1181-1] + can_pair(RNA, c0, c0+1181));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 817; c0 += 1)
    for (c1 = c0 + 1182; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1182+c0] + S[-c0+c1-1182+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1181+c0] + S[1181+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 817; c0 += 1)
    S[c0][c0+1182] = MAX(S[c0][c0+1182], S[c0+1][c0+1182-1] + can_pair(RNA, c0, c0+1182));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 816; c0 += 1)
    for (c1 = c0 + 1183; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1183+c0] + S[-c0+c1-1183+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1182+c0] + S[1182+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 816; c0 += 1)
    S[c0][c0+1183] = MAX(S[c0][c0+1183], S[c0+1][c0+1183-1] + can_pair(RNA, c0, c0+1183));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 815; c0 += 1)
    for (c1 = c0 + 1184; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1184+c0] + S[-c0+c1-1184+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1183+c0] + S[1183+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 815; c0 += 1)
    S[c0][c0+1184] = MAX(S[c0][c0+1184], S[c0+1][c0+1184-1] + can_pair(RNA, c0, c0+1184));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 814; c0 += 1)
    for (c1 = c0 + 1185; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1185+c0] + S[-c0+c1-1185+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1184+c0] + S[1184+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 814; c0 += 1)
    S[c0][c0+1185] = MAX(S[c0][c0+1185], S[c0+1][c0+1185-1] + can_pair(RNA, c0, c0+1185));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 813; c0 += 1)
    for (c1 = c0 + 1186; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1186+c0] + S[-c0+c1-1186+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1185+c0] + S[1185+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 813; c0 += 1)
    S[c0][c0+1186] = MAX(S[c0][c0+1186], S[c0+1][c0+1186-1] + can_pair(RNA, c0, c0+1186));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 812; c0 += 1)
    for (c1 = c0 + 1187; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1187+c0] + S[-c0+c1-1187+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1186+c0] + S[1186+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 812; c0 += 1)
    S[c0][c0+1187] = MAX(S[c0][c0+1187], S[c0+1][c0+1187-1] + can_pair(RNA, c0, c0+1187));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 811; c0 += 1)
    for (c1 = c0 + 1188; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1188+c0] + S[-c0+c1-1188+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1187+c0] + S[1187+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 811; c0 += 1)
    S[c0][c0+1188] = MAX(S[c0][c0+1188], S[c0+1][c0+1188-1] + can_pair(RNA, c0, c0+1188));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 810; c0 += 1)
    for (c1 = c0 + 1189; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1189+c0] + S[-c0+c1-1189+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1188+c0] + S[1188+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 810; c0 += 1)
    S[c0][c0+1189] = MAX(S[c0][c0+1189], S[c0+1][c0+1189-1] + can_pair(RNA, c0, c0+1189));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 809; c0 += 1)
    for (c1 = c0 + 1190; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1190+c0] + S[-c0+c1-1190+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1189+c0] + S[1189+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 809; c0 += 1)
    S[c0][c0+1190] = MAX(S[c0][c0+1190], S[c0+1][c0+1190-1] + can_pair(RNA, c0, c0+1190));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 808; c0 += 1)
    for (c1 = c0 + 1191; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1191+c0] + S[-c0+c1-1191+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1190+c0] + S[1190+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 808; c0 += 1)
    S[c0][c0+1191] = MAX(S[c0][c0+1191], S[c0+1][c0+1191-1] + can_pair(RNA, c0, c0+1191));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 807; c0 += 1)
    for (c1 = c0 + 1192; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1192+c0] + S[-c0+c1-1192+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1191+c0] + S[1191+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 807; c0 += 1)
    S[c0][c0+1192] = MAX(S[c0][c0+1192], S[c0+1][c0+1192-1] + can_pair(RNA, c0, c0+1192));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 806; c0 += 1)
    for (c1 = c0 + 1193; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1193+c0] + S[-c0+c1-1193+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1192+c0] + S[1192+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 806; c0 += 1)
    S[c0][c0+1193] = MAX(S[c0][c0+1193], S[c0+1][c0+1193-1] + can_pair(RNA, c0, c0+1193));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 805; c0 += 1)
    for (c1 = c0 + 1194; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1194+c0] + S[-c0+c1-1194+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1193+c0] + S[1193+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 805; c0 += 1)
    S[c0][c0+1194] = MAX(S[c0][c0+1194], S[c0+1][c0+1194-1] + can_pair(RNA, c0, c0+1194));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 804; c0 += 1)
    for (c1 = c0 + 1195; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1195+c0] + S[-c0+c1-1195+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1194+c0] + S[1194+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 804; c0 += 1)
    S[c0][c0+1195] = MAX(S[c0][c0+1195], S[c0+1][c0+1195-1] + can_pair(RNA, c0, c0+1195));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 803; c0 += 1)
    for (c1 = c0 + 1196; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1196+c0] + S[-c0+c1-1196+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1195+c0] + S[1195+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 803; c0 += 1)
    S[c0][c0+1196] = MAX(S[c0][c0+1196], S[c0+1][c0+1196-1] + can_pair(RNA, c0, c0+1196));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 802; c0 += 1)
    for (c1 = c0 + 1197; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1197+c0] + S[-c0+c1-1197+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1196+c0] + S[1196+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 802; c0 += 1)
    S[c0][c0+1197] = MAX(S[c0][c0+1197], S[c0+1][c0+1197-1] + can_pair(RNA, c0, c0+1197));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 801; c0 += 1)
    for (c1 = c0 + 1198; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1198+c0] + S[-c0+c1-1198+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1197+c0] + S[1197+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 801; c0 += 1)
    S[c0][c0+1198] = MAX(S[c0][c0+1198], S[c0+1][c0+1198-1] + can_pair(RNA, c0, c0+1198));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 800; c0 += 1)
    for (c1 = c0 + 1199; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1199+c0] + S[-c0+c1-1199+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1198+c0] + S[1198+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 800; c0 += 1)
    S[c0][c0+1199] = MAX(S[c0][c0+1199], S[c0+1][c0+1199-1] + can_pair(RNA, c0, c0+1199));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 799; c0 += 1)
    for (c1 = c0 + 1200; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1200+c0] + S[-c0+c1-1200+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1199+c0] + S[1199+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 799; c0 += 1)
    S[c0][c0+1200] = MAX(S[c0][c0+1200], S[c0+1][c0+1200-1] + can_pair(RNA, c0, c0+1200));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 798; c0 += 1)
    for (c1 = c0 + 1201; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1201+c0] + S[-c0+c1-1201+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1200+c0] + S[1200+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 798; c0 += 1)
    S[c0][c0+1201] = MAX(S[c0][c0+1201], S[c0+1][c0+1201-1] + can_pair(RNA, c0, c0+1201));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 797; c0 += 1)
    for (c1 = c0 + 1202; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1202+c0] + S[-c0+c1-1202+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1201+c0] + S[1201+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 797; c0 += 1)
    S[c0][c0+1202] = MAX(S[c0][c0+1202], S[c0+1][c0+1202-1] + can_pair(RNA, c0, c0+1202));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 796; c0 += 1)
    for (c1 = c0 + 1203; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1203+c0] + S[-c0+c1-1203+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1202+c0] + S[1202+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 796; c0 += 1)
    S[c0][c0+1203] = MAX(S[c0][c0+1203], S[c0+1][c0+1203-1] + can_pair(RNA, c0, c0+1203));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 795; c0 += 1)
    for (c1 = c0 + 1204; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1204+c0] + S[-c0+c1-1204+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1203+c0] + S[1203+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 795; c0 += 1)
    S[c0][c0+1204] = MAX(S[c0][c0+1204], S[c0+1][c0+1204-1] + can_pair(RNA, c0, c0+1204));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 794; c0 += 1)
    for (c1 = c0 + 1205; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1205+c0] + S[-c0+c1-1205+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1204+c0] + S[1204+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 794; c0 += 1)
    S[c0][c0+1205] = MAX(S[c0][c0+1205], S[c0+1][c0+1205-1] + can_pair(RNA, c0, c0+1205));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 793; c0 += 1)
    for (c1 = c0 + 1206; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1206+c0] + S[-c0+c1-1206+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1205+c0] + S[1205+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 793; c0 += 1)
    S[c0][c0+1206] = MAX(S[c0][c0+1206], S[c0+1][c0+1206-1] + can_pair(RNA, c0, c0+1206));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 792; c0 += 1)
    for (c1 = c0 + 1207; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1207+c0] + S[-c0+c1-1207+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1206+c0] + S[1206+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 792; c0 += 1)
    S[c0][c0+1207] = MAX(S[c0][c0+1207], S[c0+1][c0+1207-1] + can_pair(RNA, c0, c0+1207));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 791; c0 += 1)
    for (c1 = c0 + 1208; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1208+c0] + S[-c0+c1-1208+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1207+c0] + S[1207+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 791; c0 += 1)
    S[c0][c0+1208] = MAX(S[c0][c0+1208], S[c0+1][c0+1208-1] + can_pair(RNA, c0, c0+1208));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 790; c0 += 1)
    for (c1 = c0 + 1209; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1209+c0] + S[-c0+c1-1209+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1208+c0] + S[1208+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 790; c0 += 1)
    S[c0][c0+1209] = MAX(S[c0][c0+1209], S[c0+1][c0+1209-1] + can_pair(RNA, c0, c0+1209));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 789; c0 += 1)
    for (c1 = c0 + 1210; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1210+c0] + S[-c0+c1-1210+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1209+c0] + S[1209+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 789; c0 += 1)
    S[c0][c0+1210] = MAX(S[c0][c0+1210], S[c0+1][c0+1210-1] + can_pair(RNA, c0, c0+1210));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 788; c0 += 1)
    for (c1 = c0 + 1211; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1211+c0] + S[-c0+c1-1211+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1210+c0] + S[1210+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 788; c0 += 1)
    S[c0][c0+1211] = MAX(S[c0][c0+1211], S[c0+1][c0+1211-1] + can_pair(RNA, c0, c0+1211));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 787; c0 += 1)
    for (c1 = c0 + 1212; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1212+c0] + S[-c0+c1-1212+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1211+c0] + S[1211+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 787; c0 += 1)
    S[c0][c0+1212] = MAX(S[c0][c0+1212], S[c0+1][c0+1212-1] + can_pair(RNA, c0, c0+1212));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 786; c0 += 1)
    for (c1 = c0 + 1213; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1213+c0] + S[-c0+c1-1213+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1212+c0] + S[1212+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 786; c0 += 1)
    S[c0][c0+1213] = MAX(S[c0][c0+1213], S[c0+1][c0+1213-1] + can_pair(RNA, c0, c0+1213));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 785; c0 += 1)
    for (c1 = c0 + 1214; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1214+c0] + S[-c0+c1-1214+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1213+c0] + S[1213+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 785; c0 += 1)
    S[c0][c0+1214] = MAX(S[c0][c0+1214], S[c0+1][c0+1214-1] + can_pair(RNA, c0, c0+1214));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 784; c0 += 1)
    for (c1 = c0 + 1215; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1215+c0] + S[-c0+c1-1215+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1214+c0] + S[1214+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 784; c0 += 1)
    S[c0][c0+1215] = MAX(S[c0][c0+1215], S[c0+1][c0+1215-1] + can_pair(RNA, c0, c0+1215));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 783; c0 += 1)
    for (c1 = c0 + 1216; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1216+c0] + S[-c0+c1-1216+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1215+c0] + S[1215+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 783; c0 += 1)
    S[c0][c0+1216] = MAX(S[c0][c0+1216], S[c0+1][c0+1216-1] + can_pair(RNA, c0, c0+1216));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 782; c0 += 1)
    for (c1 = c0 + 1217; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1217+c0] + S[-c0+c1-1217+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1216+c0] + S[1216+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 782; c0 += 1)
    S[c0][c0+1217] = MAX(S[c0][c0+1217], S[c0+1][c0+1217-1] + can_pair(RNA, c0, c0+1217));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 781; c0 += 1)
    for (c1 = c0 + 1218; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1218+c0] + S[-c0+c1-1218+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1217+c0] + S[1217+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 781; c0 += 1)
    S[c0][c0+1218] = MAX(S[c0][c0+1218], S[c0+1][c0+1218-1] + can_pair(RNA, c0, c0+1218));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 780; c0 += 1)
    for (c1 = c0 + 1219; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1219+c0] + S[-c0+c1-1219+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1218+c0] + S[1218+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 780; c0 += 1)
    S[c0][c0+1219] = MAX(S[c0][c0+1219], S[c0+1][c0+1219-1] + can_pair(RNA, c0, c0+1219));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 779; c0 += 1)
    for (c1 = c0 + 1220; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1220+c0] + S[-c0+c1-1220+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1219+c0] + S[1219+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 779; c0 += 1)
    S[c0][c0+1220] = MAX(S[c0][c0+1220], S[c0+1][c0+1220-1] + can_pair(RNA, c0, c0+1220));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 778; c0 += 1)
    for (c1 = c0 + 1221; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1221+c0] + S[-c0+c1-1221+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1220+c0] + S[1220+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 778; c0 += 1)
    S[c0][c0+1221] = MAX(S[c0][c0+1221], S[c0+1][c0+1221-1] + can_pair(RNA, c0, c0+1221));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 777; c0 += 1)
    for (c1 = c0 + 1222; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1222+c0] + S[-c0+c1-1222+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1221+c0] + S[1221+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 777; c0 += 1)
    S[c0][c0+1222] = MAX(S[c0][c0+1222], S[c0+1][c0+1222-1] + can_pair(RNA, c0, c0+1222));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 776; c0 += 1)
    for (c1 = c0 + 1223; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1223+c0] + S[-c0+c1-1223+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1222+c0] + S[1222+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 776; c0 += 1)
    S[c0][c0+1223] = MAX(S[c0][c0+1223], S[c0+1][c0+1223-1] + can_pair(RNA, c0, c0+1223));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 775; c0 += 1)
    for (c1 = c0 + 1224; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1224+c0] + S[-c0+c1-1224+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1223+c0] + S[1223+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 775; c0 += 1)
    S[c0][c0+1224] = MAX(S[c0][c0+1224], S[c0+1][c0+1224-1] + can_pair(RNA, c0, c0+1224));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 774; c0 += 1)
    for (c1 = c0 + 1225; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1225+c0] + S[-c0+c1-1225+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1224+c0] + S[1224+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 774; c0 += 1)
    S[c0][c0+1225] = MAX(S[c0][c0+1225], S[c0+1][c0+1225-1] + can_pair(RNA, c0, c0+1225));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 773; c0 += 1)
    for (c1 = c0 + 1226; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1226+c0] + S[-c0+c1-1226+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1225+c0] + S[1225+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 773; c0 += 1)
    S[c0][c0+1226] = MAX(S[c0][c0+1226], S[c0+1][c0+1226-1] + can_pair(RNA, c0, c0+1226));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 772; c0 += 1)
    for (c1 = c0 + 1227; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1227+c0] + S[-c0+c1-1227+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1226+c0] + S[1226+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 772; c0 += 1)
    S[c0][c0+1227] = MAX(S[c0][c0+1227], S[c0+1][c0+1227-1] + can_pair(RNA, c0, c0+1227));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 771; c0 += 1)
    for (c1 = c0 + 1228; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1228+c0] + S[-c0+c1-1228+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1227+c0] + S[1227+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 771; c0 += 1)
    S[c0][c0+1228] = MAX(S[c0][c0+1228], S[c0+1][c0+1228-1] + can_pair(RNA, c0, c0+1228));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 770; c0 += 1)
    for (c1 = c0 + 1229; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1229+c0] + S[-c0+c1-1229+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1228+c0] + S[1228+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 770; c0 += 1)
    S[c0][c0+1229] = MAX(S[c0][c0+1229], S[c0+1][c0+1229-1] + can_pair(RNA, c0, c0+1229));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 769; c0 += 1)
    for (c1 = c0 + 1230; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1230+c0] + S[-c0+c1-1230+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1229+c0] + S[1229+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 769; c0 += 1)
    S[c0][c0+1230] = MAX(S[c0][c0+1230], S[c0+1][c0+1230-1] + can_pair(RNA, c0, c0+1230));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 768; c0 += 1)
    for (c1 = c0 + 1231; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1231+c0] + S[-c0+c1-1231+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1230+c0] + S[1230+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 768; c0 += 1)
    S[c0][c0+1231] = MAX(S[c0][c0+1231], S[c0+1][c0+1231-1] + can_pair(RNA, c0, c0+1231));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 767; c0 += 1)
    for (c1 = c0 + 1232; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1232+c0] + S[-c0+c1-1232+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1231+c0] + S[1231+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 767; c0 += 1)
    S[c0][c0+1232] = MAX(S[c0][c0+1232], S[c0+1][c0+1232-1] + can_pair(RNA, c0, c0+1232));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 766; c0 += 1)
    for (c1 = c0 + 1233; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1233+c0] + S[-c0+c1-1233+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1232+c0] + S[1232+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 766; c0 += 1)
    S[c0][c0+1233] = MAX(S[c0][c0+1233], S[c0+1][c0+1233-1] + can_pair(RNA, c0, c0+1233));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 765; c0 += 1)
    for (c1 = c0 + 1234; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1234+c0] + S[-c0+c1-1234+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1233+c0] + S[1233+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 765; c0 += 1)
    S[c0][c0+1234] = MAX(S[c0][c0+1234], S[c0+1][c0+1234-1] + can_pair(RNA, c0, c0+1234));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 764; c0 += 1)
    for (c1 = c0 + 1235; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1235+c0] + S[-c0+c1-1235+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1234+c0] + S[1234+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 764; c0 += 1)
    S[c0][c0+1235] = MAX(S[c0][c0+1235], S[c0+1][c0+1235-1] + can_pair(RNA, c0, c0+1235));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 763; c0 += 1)
    for (c1 = c0 + 1236; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1236+c0] + S[-c0+c1-1236+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1235+c0] + S[1235+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 763; c0 += 1)
    S[c0][c0+1236] = MAX(S[c0][c0+1236], S[c0+1][c0+1236-1] + can_pair(RNA, c0, c0+1236));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 762; c0 += 1)
    for (c1 = c0 + 1237; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1237+c0] + S[-c0+c1-1237+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1236+c0] + S[1236+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 762; c0 += 1)
    S[c0][c0+1237] = MAX(S[c0][c0+1237], S[c0+1][c0+1237-1] + can_pair(RNA, c0, c0+1237));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 761; c0 += 1)
    for (c1 = c0 + 1238; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1238+c0] + S[-c0+c1-1238+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1237+c0] + S[1237+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 761; c0 += 1)
    S[c0][c0+1238] = MAX(S[c0][c0+1238], S[c0+1][c0+1238-1] + can_pair(RNA, c0, c0+1238));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 760; c0 += 1)
    for (c1 = c0 + 1239; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1239+c0] + S[-c0+c1-1239+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1238+c0] + S[1238+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 760; c0 += 1)
    S[c0][c0+1239] = MAX(S[c0][c0+1239], S[c0+1][c0+1239-1] + can_pair(RNA, c0, c0+1239));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 759; c0 += 1)
    for (c1 = c0 + 1240; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1240+c0] + S[-c0+c1-1240+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1239+c0] + S[1239+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 759; c0 += 1)
    S[c0][c0+1240] = MAX(S[c0][c0+1240], S[c0+1][c0+1240-1] + can_pair(RNA, c0, c0+1240));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 758; c0 += 1)
    for (c1 = c0 + 1241; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1241+c0] + S[-c0+c1-1241+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1240+c0] + S[1240+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 758; c0 += 1)
    S[c0][c0+1241] = MAX(S[c0][c0+1241], S[c0+1][c0+1241-1] + can_pair(RNA, c0, c0+1241));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 757; c0 += 1)
    for (c1 = c0 + 1242; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1242+c0] + S[-c0+c1-1242+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1241+c0] + S[1241+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 757; c0 += 1)
    S[c0][c0+1242] = MAX(S[c0][c0+1242], S[c0+1][c0+1242-1] + can_pair(RNA, c0, c0+1242));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 756; c0 += 1)
    for (c1 = c0 + 1243; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1243+c0] + S[-c0+c1-1243+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1242+c0] + S[1242+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 756; c0 += 1)
    S[c0][c0+1243] = MAX(S[c0][c0+1243], S[c0+1][c0+1243-1] + can_pair(RNA, c0, c0+1243));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 755; c0 += 1)
    for (c1 = c0 + 1244; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1244+c0] + S[-c0+c1-1244+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1243+c0] + S[1243+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 755; c0 += 1)
    S[c0][c0+1244] = MAX(S[c0][c0+1244], S[c0+1][c0+1244-1] + can_pair(RNA, c0, c0+1244));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 754; c0 += 1)
    for (c1 = c0 + 1245; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1245+c0] + S[-c0+c1-1245+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1244+c0] + S[1244+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 754; c0 += 1)
    S[c0][c0+1245] = MAX(S[c0][c0+1245], S[c0+1][c0+1245-1] + can_pair(RNA, c0, c0+1245));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 753; c0 += 1)
    for (c1 = c0 + 1246; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1246+c0] + S[-c0+c1-1246+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1245+c0] + S[1245+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 753; c0 += 1)
    S[c0][c0+1246] = MAX(S[c0][c0+1246], S[c0+1][c0+1246-1] + can_pair(RNA, c0, c0+1246));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 752; c0 += 1)
    for (c1 = c0 + 1247; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1247+c0] + S[-c0+c1-1247+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1246+c0] + S[1246+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 752; c0 += 1)
    S[c0][c0+1247] = MAX(S[c0][c0+1247], S[c0+1][c0+1247-1] + can_pair(RNA, c0, c0+1247));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 751; c0 += 1)
    for (c1 = c0 + 1248; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1248+c0] + S[-c0+c1-1248+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1247+c0] + S[1247+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 751; c0 += 1)
    S[c0][c0+1248] = MAX(S[c0][c0+1248], S[c0+1][c0+1248-1] + can_pair(RNA, c0, c0+1248));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 750; c0 += 1)
    for (c1 = c0 + 1249; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1249+c0] + S[-c0+c1-1249+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1248+c0] + S[1248+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 750; c0 += 1)
    S[c0][c0+1249] = MAX(S[c0][c0+1249], S[c0+1][c0+1249-1] + can_pair(RNA, c0, c0+1249));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 749; c0 += 1)
    for (c1 = c0 + 1250; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1250+c0] + S[-c0+c1-1250+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1249+c0] + S[1249+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 749; c0 += 1)
    S[c0][c0+1250] = MAX(S[c0][c0+1250], S[c0+1][c0+1250-1] + can_pair(RNA, c0, c0+1250));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 748; c0 += 1)
    for (c1 = c0 + 1251; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1251+c0] + S[-c0+c1-1251+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1250+c0] + S[1250+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 748; c0 += 1)
    S[c0][c0+1251] = MAX(S[c0][c0+1251], S[c0+1][c0+1251-1] + can_pair(RNA, c0, c0+1251));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 747; c0 += 1)
    for (c1 = c0 + 1252; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1252+c0] + S[-c0+c1-1252+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1251+c0] + S[1251+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 747; c0 += 1)
    S[c0][c0+1252] = MAX(S[c0][c0+1252], S[c0+1][c0+1252-1] + can_pair(RNA, c0, c0+1252));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 746; c0 += 1)
    for (c1 = c0 + 1253; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1253+c0] + S[-c0+c1-1253+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1252+c0] + S[1252+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 746; c0 += 1)
    S[c0][c0+1253] = MAX(S[c0][c0+1253], S[c0+1][c0+1253-1] + can_pair(RNA, c0, c0+1253));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 745; c0 += 1)
    for (c1 = c0 + 1254; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1254+c0] + S[-c0+c1-1254+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1253+c0] + S[1253+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 745; c0 += 1)
    S[c0][c0+1254] = MAX(S[c0][c0+1254], S[c0+1][c0+1254-1] + can_pair(RNA, c0, c0+1254));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 744; c0 += 1)
    for (c1 = c0 + 1255; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1255+c0] + S[-c0+c1-1255+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1254+c0] + S[1254+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 744; c0 += 1)
    S[c0][c0+1255] = MAX(S[c0][c0+1255], S[c0+1][c0+1255-1] + can_pair(RNA, c0, c0+1255));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 743; c0 += 1)
    for (c1 = c0 + 1256; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1256+c0] + S[-c0+c1-1256+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1255+c0] + S[1255+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 743; c0 += 1)
    S[c0][c0+1256] = MAX(S[c0][c0+1256], S[c0+1][c0+1256-1] + can_pair(RNA, c0, c0+1256));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 742; c0 += 1)
    for (c1 = c0 + 1257; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1257+c0] + S[-c0+c1-1257+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1256+c0] + S[1256+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 742; c0 += 1)
    S[c0][c0+1257] = MAX(S[c0][c0+1257], S[c0+1][c0+1257-1] + can_pair(RNA, c0, c0+1257));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 741; c0 += 1)
    for (c1 = c0 + 1258; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1258+c0] + S[-c0+c1-1258+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1257+c0] + S[1257+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 741; c0 += 1)
    S[c0][c0+1258] = MAX(S[c0][c0+1258], S[c0+1][c0+1258-1] + can_pair(RNA, c0, c0+1258));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 740; c0 += 1)
    for (c1 = c0 + 1259; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1259+c0] + S[-c0+c1-1259+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1258+c0] + S[1258+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 740; c0 += 1)
    S[c0][c0+1259] = MAX(S[c0][c0+1259], S[c0+1][c0+1259-1] + can_pair(RNA, c0, c0+1259));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 739; c0 += 1)
    for (c1 = c0 + 1260; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1260+c0] + S[-c0+c1-1260+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1259+c0] + S[1259+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 739; c0 += 1)
    S[c0][c0+1260] = MAX(S[c0][c0+1260], S[c0+1][c0+1260-1] + can_pair(RNA, c0, c0+1260));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 738; c0 += 1)
    for (c1 = c0 + 1261; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1261+c0] + S[-c0+c1-1261+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1260+c0] + S[1260+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 738; c0 += 1)
    S[c0][c0+1261] = MAX(S[c0][c0+1261], S[c0+1][c0+1261-1] + can_pair(RNA, c0, c0+1261));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 737; c0 += 1)
    for (c1 = c0 + 1262; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1262+c0] + S[-c0+c1-1262+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1261+c0] + S[1261+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 737; c0 += 1)
    S[c0][c0+1262] = MAX(S[c0][c0+1262], S[c0+1][c0+1262-1] + can_pair(RNA, c0, c0+1262));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 736; c0 += 1)
    for (c1 = c0 + 1263; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1263+c0] + S[-c0+c1-1263+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1262+c0] + S[1262+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 736; c0 += 1)
    S[c0][c0+1263] = MAX(S[c0][c0+1263], S[c0+1][c0+1263-1] + can_pair(RNA, c0, c0+1263));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 735; c0 += 1)
    for (c1 = c0 + 1264; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1264+c0] + S[-c0+c1-1264+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1263+c0] + S[1263+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 735; c0 += 1)
    S[c0][c0+1264] = MAX(S[c0][c0+1264], S[c0+1][c0+1264-1] + can_pair(RNA, c0, c0+1264));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 734; c0 += 1)
    for (c1 = c0 + 1265; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1265+c0] + S[-c0+c1-1265+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1264+c0] + S[1264+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 734; c0 += 1)
    S[c0][c0+1265] = MAX(S[c0][c0+1265], S[c0+1][c0+1265-1] + can_pair(RNA, c0, c0+1265));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 733; c0 += 1)
    for (c1 = c0 + 1266; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1266+c0] + S[-c0+c1-1266+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1265+c0] + S[1265+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 733; c0 += 1)
    S[c0][c0+1266] = MAX(S[c0][c0+1266], S[c0+1][c0+1266-1] + can_pair(RNA, c0, c0+1266));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 732; c0 += 1)
    for (c1 = c0 + 1267; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1267+c0] + S[-c0+c1-1267+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1266+c0] + S[1266+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 732; c0 += 1)
    S[c0][c0+1267] = MAX(S[c0][c0+1267], S[c0+1][c0+1267-1] + can_pair(RNA, c0, c0+1267));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 731; c0 += 1)
    for (c1 = c0 + 1268; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1268+c0] + S[-c0+c1-1268+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1267+c0] + S[1267+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 731; c0 += 1)
    S[c0][c0+1268] = MAX(S[c0][c0+1268], S[c0+1][c0+1268-1] + can_pair(RNA, c0, c0+1268));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 730; c0 += 1)
    for (c1 = c0 + 1269; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1269+c0] + S[-c0+c1-1269+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1268+c0] + S[1268+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 730; c0 += 1)
    S[c0][c0+1269] = MAX(S[c0][c0+1269], S[c0+1][c0+1269-1] + can_pair(RNA, c0, c0+1269));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 729; c0 += 1)
    for (c1 = c0 + 1270; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1270+c0] + S[-c0+c1-1270+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1269+c0] + S[1269+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 729; c0 += 1)
    S[c0][c0+1270] = MAX(S[c0][c0+1270], S[c0+1][c0+1270-1] + can_pair(RNA, c0, c0+1270));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 728; c0 += 1)
    for (c1 = c0 + 1271; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1271+c0] + S[-c0+c1-1271+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1270+c0] + S[1270+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 728; c0 += 1)
    S[c0][c0+1271] = MAX(S[c0][c0+1271], S[c0+1][c0+1271-1] + can_pair(RNA, c0, c0+1271));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 727; c0 += 1)
    for (c1 = c0 + 1272; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1272+c0] + S[-c0+c1-1272+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1271+c0] + S[1271+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 727; c0 += 1)
    S[c0][c0+1272] = MAX(S[c0][c0+1272], S[c0+1][c0+1272-1] + can_pair(RNA, c0, c0+1272));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 726; c0 += 1)
    for (c1 = c0 + 1273; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1273+c0] + S[-c0+c1-1273+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1272+c0] + S[1272+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 726; c0 += 1)
    S[c0][c0+1273] = MAX(S[c0][c0+1273], S[c0+1][c0+1273-1] + can_pair(RNA, c0, c0+1273));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 725; c0 += 1)
    for (c1 = c0 + 1274; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1274+c0] + S[-c0+c1-1274+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1273+c0] + S[1273+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 725; c0 += 1)
    S[c0][c0+1274] = MAX(S[c0][c0+1274], S[c0+1][c0+1274-1] + can_pair(RNA, c0, c0+1274));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 724; c0 += 1)
    for (c1 = c0 + 1275; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1275+c0] + S[-c0+c1-1275+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1274+c0] + S[1274+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 724; c0 += 1)
    S[c0][c0+1275] = MAX(S[c0][c0+1275], S[c0+1][c0+1275-1] + can_pair(RNA, c0, c0+1275));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 723; c0 += 1)
    for (c1 = c0 + 1276; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1276+c0] + S[-c0+c1-1276+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1275+c0] + S[1275+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 723; c0 += 1)
    S[c0][c0+1276] = MAX(S[c0][c0+1276], S[c0+1][c0+1276-1] + can_pair(RNA, c0, c0+1276));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 722; c0 += 1)
    for (c1 = c0 + 1277; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1277+c0] + S[-c0+c1-1277+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1276+c0] + S[1276+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 722; c0 += 1)
    S[c0][c0+1277] = MAX(S[c0][c0+1277], S[c0+1][c0+1277-1] + can_pair(RNA, c0, c0+1277));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 721; c0 += 1)
    for (c1 = c0 + 1278; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1278+c0] + S[-c0+c1-1278+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1277+c0] + S[1277+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 721; c0 += 1)
    S[c0][c0+1278] = MAX(S[c0][c0+1278], S[c0+1][c0+1278-1] + can_pair(RNA, c0, c0+1278));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 720; c0 += 1)
    for (c1 = c0 + 1279; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1279+c0] + S[-c0+c1-1279+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1278+c0] + S[1278+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 720; c0 += 1)
    S[c0][c0+1279] = MAX(S[c0][c0+1279], S[c0+1][c0+1279-1] + can_pair(RNA, c0, c0+1279));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 719; c0 += 1)
    for (c1 = c0 + 1280; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1280+c0] + S[-c0+c1-1280+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1279+c0] + S[1279+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 719; c0 += 1)
    S[c0][c0+1280] = MAX(S[c0][c0+1280], S[c0+1][c0+1280-1] + can_pair(RNA, c0, c0+1280));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 718; c0 += 1)
    for (c1 = c0 + 1281; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1281+c0] + S[-c0+c1-1281+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1280+c0] + S[1280+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 718; c0 += 1)
    S[c0][c0+1281] = MAX(S[c0][c0+1281], S[c0+1][c0+1281-1] + can_pair(RNA, c0, c0+1281));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 717; c0 += 1)
    for (c1 = c0 + 1282; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1282+c0] + S[-c0+c1-1282+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1281+c0] + S[1281+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 717; c0 += 1)
    S[c0][c0+1282] = MAX(S[c0][c0+1282], S[c0+1][c0+1282-1] + can_pair(RNA, c0, c0+1282));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 716; c0 += 1)
    for (c1 = c0 + 1283; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1283+c0] + S[-c0+c1-1283+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1282+c0] + S[1282+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 716; c0 += 1)
    S[c0][c0+1283] = MAX(S[c0][c0+1283], S[c0+1][c0+1283-1] + can_pair(RNA, c0, c0+1283));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 715; c0 += 1)
    for (c1 = c0 + 1284; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1284+c0] + S[-c0+c1-1284+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1283+c0] + S[1283+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 715; c0 += 1)
    S[c0][c0+1284] = MAX(S[c0][c0+1284], S[c0+1][c0+1284-1] + can_pair(RNA, c0, c0+1284));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 714; c0 += 1)
    for (c1 = c0 + 1285; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1285+c0] + S[-c0+c1-1285+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1284+c0] + S[1284+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 714; c0 += 1)
    S[c0][c0+1285] = MAX(S[c0][c0+1285], S[c0+1][c0+1285-1] + can_pair(RNA, c0, c0+1285));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 713; c0 += 1)
    for (c1 = c0 + 1286; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1286+c0] + S[-c0+c1-1286+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1285+c0] + S[1285+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 713; c0 += 1)
    S[c0][c0+1286] = MAX(S[c0][c0+1286], S[c0+1][c0+1286-1] + can_pair(RNA, c0, c0+1286));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 712; c0 += 1)
    for (c1 = c0 + 1287; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1287+c0] + S[-c0+c1-1287+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1286+c0] + S[1286+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 712; c0 += 1)
    S[c0][c0+1287] = MAX(S[c0][c0+1287], S[c0+1][c0+1287-1] + can_pair(RNA, c0, c0+1287));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 711; c0 += 1)
    for (c1 = c0 + 1288; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1288+c0] + S[-c0+c1-1288+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1287+c0] + S[1287+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 711; c0 += 1)
    S[c0][c0+1288] = MAX(S[c0][c0+1288], S[c0+1][c0+1288-1] + can_pair(RNA, c0, c0+1288));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 710; c0 += 1)
    for (c1 = c0 + 1289; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1289+c0] + S[-c0+c1-1289+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1288+c0] + S[1288+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 710; c0 += 1)
    S[c0][c0+1289] = MAX(S[c0][c0+1289], S[c0+1][c0+1289-1] + can_pair(RNA, c0, c0+1289));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 709; c0 += 1)
    for (c1 = c0 + 1290; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1290+c0] + S[-c0+c1-1290+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1289+c0] + S[1289+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 709; c0 += 1)
    S[c0][c0+1290] = MAX(S[c0][c0+1290], S[c0+1][c0+1290-1] + can_pair(RNA, c0, c0+1290));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 708; c0 += 1)
    for (c1 = c0 + 1291; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1291+c0] + S[-c0+c1-1291+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1290+c0] + S[1290+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 708; c0 += 1)
    S[c0][c0+1291] = MAX(S[c0][c0+1291], S[c0+1][c0+1291-1] + can_pair(RNA, c0, c0+1291));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 707; c0 += 1)
    for (c1 = c0 + 1292; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1292+c0] + S[-c0+c1-1292+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1291+c0] + S[1291+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 707; c0 += 1)
    S[c0][c0+1292] = MAX(S[c0][c0+1292], S[c0+1][c0+1292-1] + can_pair(RNA, c0, c0+1292));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 706; c0 += 1)
    for (c1 = c0 + 1293; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1293+c0] + S[-c0+c1-1293+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1292+c0] + S[1292+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 706; c0 += 1)
    S[c0][c0+1293] = MAX(S[c0][c0+1293], S[c0+1][c0+1293-1] + can_pair(RNA, c0, c0+1293));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 705; c0 += 1)
    for (c1 = c0 + 1294; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1294+c0] + S[-c0+c1-1294+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1293+c0] + S[1293+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 705; c0 += 1)
    S[c0][c0+1294] = MAX(S[c0][c0+1294], S[c0+1][c0+1294-1] + can_pair(RNA, c0, c0+1294));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 704; c0 += 1)
    for (c1 = c0 + 1295; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1295+c0] + S[-c0+c1-1295+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1294+c0] + S[1294+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 704; c0 += 1)
    S[c0][c0+1295] = MAX(S[c0][c0+1295], S[c0+1][c0+1295-1] + can_pair(RNA, c0, c0+1295));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 703; c0 += 1)
    for (c1 = c0 + 1296; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1296+c0] + S[-c0+c1-1296+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1295+c0] + S[1295+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 703; c0 += 1)
    S[c0][c0+1296] = MAX(S[c0][c0+1296], S[c0+1][c0+1296-1] + can_pair(RNA, c0, c0+1296));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 702; c0 += 1)
    for (c1 = c0 + 1297; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1297+c0] + S[-c0+c1-1297+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1296+c0] + S[1296+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 702; c0 += 1)
    S[c0][c0+1297] = MAX(S[c0][c0+1297], S[c0+1][c0+1297-1] + can_pair(RNA, c0, c0+1297));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 701; c0 += 1)
    for (c1 = c0 + 1298; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1298+c0] + S[-c0+c1-1298+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1297+c0] + S[1297+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 701; c0 += 1)
    S[c0][c0+1298] = MAX(S[c0][c0+1298], S[c0+1][c0+1298-1] + can_pair(RNA, c0, c0+1298));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 700; c0 += 1)
    for (c1 = c0 + 1299; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1299+c0] + S[-c0+c1-1299+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1298+c0] + S[1298+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 700; c0 += 1)
    S[c0][c0+1299] = MAX(S[c0][c0+1299], S[c0+1][c0+1299-1] + can_pair(RNA, c0, c0+1299));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 699; c0 += 1)
    for (c1 = c0 + 1300; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1300+c0] + S[-c0+c1-1300+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1299+c0] + S[1299+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 699; c0 += 1)
    S[c0][c0+1300] = MAX(S[c0][c0+1300], S[c0+1][c0+1300-1] + can_pair(RNA, c0, c0+1300));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 698; c0 += 1)
    for (c1 = c0 + 1301; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1301+c0] + S[-c0+c1-1301+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1300+c0] + S[1300+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 698; c0 += 1)
    S[c0][c0+1301] = MAX(S[c0][c0+1301], S[c0+1][c0+1301-1] + can_pair(RNA, c0, c0+1301));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 697; c0 += 1)
    for (c1 = c0 + 1302; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1302+c0] + S[-c0+c1-1302+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1301+c0] + S[1301+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 697; c0 += 1)
    S[c0][c0+1302] = MAX(S[c0][c0+1302], S[c0+1][c0+1302-1] + can_pair(RNA, c0, c0+1302));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 696; c0 += 1)
    for (c1 = c0 + 1303; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1303+c0] + S[-c0+c1-1303+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1302+c0] + S[1302+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 696; c0 += 1)
    S[c0][c0+1303] = MAX(S[c0][c0+1303], S[c0+1][c0+1303-1] + can_pair(RNA, c0, c0+1303));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 695; c0 += 1)
    for (c1 = c0 + 1304; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1304+c0] + S[-c0+c1-1304+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1303+c0] + S[1303+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 695; c0 += 1)
    S[c0][c0+1304] = MAX(S[c0][c0+1304], S[c0+1][c0+1304-1] + can_pair(RNA, c0, c0+1304));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 694; c0 += 1)
    for (c1 = c0 + 1305; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1305+c0] + S[-c0+c1-1305+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1304+c0] + S[1304+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 694; c0 += 1)
    S[c0][c0+1305] = MAX(S[c0][c0+1305], S[c0+1][c0+1305-1] + can_pair(RNA, c0, c0+1305));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 693; c0 += 1)
    for (c1 = c0 + 1306; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1306+c0] + S[-c0+c1-1306+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1305+c0] + S[1305+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 693; c0 += 1)
    S[c0][c0+1306] = MAX(S[c0][c0+1306], S[c0+1][c0+1306-1] + can_pair(RNA, c0, c0+1306));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 692; c0 += 1)
    for (c1 = c0 + 1307; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1307+c0] + S[-c0+c1-1307+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1306+c0] + S[1306+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 692; c0 += 1)
    S[c0][c0+1307] = MAX(S[c0][c0+1307], S[c0+1][c0+1307-1] + can_pair(RNA, c0, c0+1307));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 691; c0 += 1)
    for (c1 = c0 + 1308; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1308+c0] + S[-c0+c1-1308+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1307+c0] + S[1307+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 691; c0 += 1)
    S[c0][c0+1308] = MAX(S[c0][c0+1308], S[c0+1][c0+1308-1] + can_pair(RNA, c0, c0+1308));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 690; c0 += 1)
    for (c1 = c0 + 1309; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1309+c0] + S[-c0+c1-1309+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1308+c0] + S[1308+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 690; c0 += 1)
    S[c0][c0+1309] = MAX(S[c0][c0+1309], S[c0+1][c0+1309-1] + can_pair(RNA, c0, c0+1309));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 689; c0 += 1)
    for (c1 = c0 + 1310; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1310+c0] + S[-c0+c1-1310+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1309+c0] + S[1309+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 689; c0 += 1)
    S[c0][c0+1310] = MAX(S[c0][c0+1310], S[c0+1][c0+1310-1] + can_pair(RNA, c0, c0+1310));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 688; c0 += 1)
    for (c1 = c0 + 1311; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1311+c0] + S[-c0+c1-1311+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1310+c0] + S[1310+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 688; c0 += 1)
    S[c0][c0+1311] = MAX(S[c0][c0+1311], S[c0+1][c0+1311-1] + can_pair(RNA, c0, c0+1311));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 687; c0 += 1)
    for (c1 = c0 + 1312; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1312+c0] + S[-c0+c1-1312+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1311+c0] + S[1311+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 687; c0 += 1)
    S[c0][c0+1312] = MAX(S[c0][c0+1312], S[c0+1][c0+1312-1] + can_pair(RNA, c0, c0+1312));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 686; c0 += 1)
    for (c1 = c0 + 1313; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1313+c0] + S[-c0+c1-1313+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1312+c0] + S[1312+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 686; c0 += 1)
    S[c0][c0+1313] = MAX(S[c0][c0+1313], S[c0+1][c0+1313-1] + can_pair(RNA, c0, c0+1313));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 685; c0 += 1)
    for (c1 = c0 + 1314; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1314+c0] + S[-c0+c1-1314+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1313+c0] + S[1313+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 685; c0 += 1)
    S[c0][c0+1314] = MAX(S[c0][c0+1314], S[c0+1][c0+1314-1] + can_pair(RNA, c0, c0+1314));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 684; c0 += 1)
    for (c1 = c0 + 1315; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1315+c0] + S[-c0+c1-1315+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1314+c0] + S[1314+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 684; c0 += 1)
    S[c0][c0+1315] = MAX(S[c0][c0+1315], S[c0+1][c0+1315-1] + can_pair(RNA, c0, c0+1315));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 683; c0 += 1)
    for (c1 = c0 + 1316; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1316+c0] + S[-c0+c1-1316+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1315+c0] + S[1315+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 683; c0 += 1)
    S[c0][c0+1316] = MAX(S[c0][c0+1316], S[c0+1][c0+1316-1] + can_pair(RNA, c0, c0+1316));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 682; c0 += 1)
    for (c1 = c0 + 1317; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1317+c0] + S[-c0+c1-1317+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1316+c0] + S[1316+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 682; c0 += 1)
    S[c0][c0+1317] = MAX(S[c0][c0+1317], S[c0+1][c0+1317-1] + can_pair(RNA, c0, c0+1317));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 681; c0 += 1)
    for (c1 = c0 + 1318; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1318+c0] + S[-c0+c1-1318+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1317+c0] + S[1317+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 681; c0 += 1)
    S[c0][c0+1318] = MAX(S[c0][c0+1318], S[c0+1][c0+1318-1] + can_pair(RNA, c0, c0+1318));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 680; c0 += 1)
    for (c1 = c0 + 1319; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1319+c0] + S[-c0+c1-1319+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1318+c0] + S[1318+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 680; c0 += 1)
    S[c0][c0+1319] = MAX(S[c0][c0+1319], S[c0+1][c0+1319-1] + can_pair(RNA, c0, c0+1319));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 679; c0 += 1)
    for (c1 = c0 + 1320; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1320+c0] + S[-c0+c1-1320+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1319+c0] + S[1319+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 679; c0 += 1)
    S[c0][c0+1320] = MAX(S[c0][c0+1320], S[c0+1][c0+1320-1] + can_pair(RNA, c0, c0+1320));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 678; c0 += 1)
    for (c1 = c0 + 1321; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1321+c0] + S[-c0+c1-1321+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1320+c0] + S[1320+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 678; c0 += 1)
    S[c0][c0+1321] = MAX(S[c0][c0+1321], S[c0+1][c0+1321-1] + can_pair(RNA, c0, c0+1321));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 677; c0 += 1)
    for (c1 = c0 + 1322; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1322+c0] + S[-c0+c1-1322+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1321+c0] + S[1321+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 677; c0 += 1)
    S[c0][c0+1322] = MAX(S[c0][c0+1322], S[c0+1][c0+1322-1] + can_pair(RNA, c0, c0+1322));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 676; c0 += 1)
    for (c1 = c0 + 1323; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1323+c0] + S[-c0+c1-1323+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1322+c0] + S[1322+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 676; c0 += 1)
    S[c0][c0+1323] = MAX(S[c0][c0+1323], S[c0+1][c0+1323-1] + can_pair(RNA, c0, c0+1323));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 675; c0 += 1)
    for (c1 = c0 + 1324; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1324+c0] + S[-c0+c1-1324+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1323+c0] + S[1323+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 675; c0 += 1)
    S[c0][c0+1324] = MAX(S[c0][c0+1324], S[c0+1][c0+1324-1] + can_pair(RNA, c0, c0+1324));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 674; c0 += 1)
    for (c1 = c0 + 1325; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1325+c0] + S[-c0+c1-1325+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1324+c0] + S[1324+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 674; c0 += 1)
    S[c0][c0+1325] = MAX(S[c0][c0+1325], S[c0+1][c0+1325-1] + can_pair(RNA, c0, c0+1325));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 673; c0 += 1)
    for (c1 = c0 + 1326; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1326+c0] + S[-c0+c1-1326+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1325+c0] + S[1325+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 673; c0 += 1)
    S[c0][c0+1326] = MAX(S[c0][c0+1326], S[c0+1][c0+1326-1] + can_pair(RNA, c0, c0+1326));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 672; c0 += 1)
    for (c1 = c0 + 1327; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1327+c0] + S[-c0+c1-1327+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1326+c0] + S[1326+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 672; c0 += 1)
    S[c0][c0+1327] = MAX(S[c0][c0+1327], S[c0+1][c0+1327-1] + can_pair(RNA, c0, c0+1327));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 671; c0 += 1)
    for (c1 = c0 + 1328; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1328+c0] + S[-c0+c1-1328+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1327+c0] + S[1327+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 671; c0 += 1)
    S[c0][c0+1328] = MAX(S[c0][c0+1328], S[c0+1][c0+1328-1] + can_pair(RNA, c0, c0+1328));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 670; c0 += 1)
    for (c1 = c0 + 1329; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1329+c0] + S[-c0+c1-1329+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1328+c0] + S[1328+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 670; c0 += 1)
    S[c0][c0+1329] = MAX(S[c0][c0+1329], S[c0+1][c0+1329-1] + can_pair(RNA, c0, c0+1329));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 669; c0 += 1)
    for (c1 = c0 + 1330; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1330+c0] + S[-c0+c1-1330+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1329+c0] + S[1329+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 669; c0 += 1)
    S[c0][c0+1330] = MAX(S[c0][c0+1330], S[c0+1][c0+1330-1] + can_pair(RNA, c0, c0+1330));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 668; c0 += 1)
    for (c1 = c0 + 1331; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1331+c0] + S[-c0+c1-1331+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1330+c0] + S[1330+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 668; c0 += 1)
    S[c0][c0+1331] = MAX(S[c0][c0+1331], S[c0+1][c0+1331-1] + can_pair(RNA, c0, c0+1331));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 667; c0 += 1)
    for (c1 = c0 + 1332; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1332+c0] + S[-c0+c1-1332+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1331+c0] + S[1331+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 667; c0 += 1)
    S[c0][c0+1332] = MAX(S[c0][c0+1332], S[c0+1][c0+1332-1] + can_pair(RNA, c0, c0+1332));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 666; c0 += 1)
    for (c1 = c0 + 1333; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1333+c0] + S[-c0+c1-1333+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1332+c0] + S[1332+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 666; c0 += 1)
    S[c0][c0+1333] = MAX(S[c0][c0+1333], S[c0+1][c0+1333-1] + can_pair(RNA, c0, c0+1333));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 665; c0 += 1)
    for (c1 = c0 + 1334; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1334+c0] + S[-c0+c1-1334+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1333+c0] + S[1333+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 665; c0 += 1)
    S[c0][c0+1334] = MAX(S[c0][c0+1334], S[c0+1][c0+1334-1] + can_pair(RNA, c0, c0+1334));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 664; c0 += 1)
    for (c1 = c0 + 1335; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1335+c0] + S[-c0+c1-1335+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1334+c0] + S[1334+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 664; c0 += 1)
    S[c0][c0+1335] = MAX(S[c0][c0+1335], S[c0+1][c0+1335-1] + can_pair(RNA, c0, c0+1335));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 663; c0 += 1)
    for (c1 = c0 + 1336; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1336+c0] + S[-c0+c1-1336+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1335+c0] + S[1335+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 663; c0 += 1)
    S[c0][c0+1336] = MAX(S[c0][c0+1336], S[c0+1][c0+1336-1] + can_pair(RNA, c0, c0+1336));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 662; c0 += 1)
    for (c1 = c0 + 1337; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1337+c0] + S[-c0+c1-1337+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1336+c0] + S[1336+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 662; c0 += 1)
    S[c0][c0+1337] = MAX(S[c0][c0+1337], S[c0+1][c0+1337-1] + can_pair(RNA, c0, c0+1337));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 661; c0 += 1)
    for (c1 = c0 + 1338; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1338+c0] + S[-c0+c1-1338+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1337+c0] + S[1337+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 661; c0 += 1)
    S[c0][c0+1338] = MAX(S[c0][c0+1338], S[c0+1][c0+1338-1] + can_pair(RNA, c0, c0+1338));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 660; c0 += 1)
    for (c1 = c0 + 1339; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1339+c0] + S[-c0+c1-1339+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1338+c0] + S[1338+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 660; c0 += 1)
    S[c0][c0+1339] = MAX(S[c0][c0+1339], S[c0+1][c0+1339-1] + can_pair(RNA, c0, c0+1339));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 659; c0 += 1)
    for (c1 = c0 + 1340; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1340+c0] + S[-c0+c1-1340+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1339+c0] + S[1339+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 659; c0 += 1)
    S[c0][c0+1340] = MAX(S[c0][c0+1340], S[c0+1][c0+1340-1] + can_pair(RNA, c0, c0+1340));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 658; c0 += 1)
    for (c1 = c0 + 1341; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1341+c0] + S[-c0+c1-1341+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1340+c0] + S[1340+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 658; c0 += 1)
    S[c0][c0+1341] = MAX(S[c0][c0+1341], S[c0+1][c0+1341-1] + can_pair(RNA, c0, c0+1341));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 657; c0 += 1)
    for (c1 = c0 + 1342; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1342+c0] + S[-c0+c1-1342+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1341+c0] + S[1341+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 657; c0 += 1)
    S[c0][c0+1342] = MAX(S[c0][c0+1342], S[c0+1][c0+1342-1] + can_pair(RNA, c0, c0+1342));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 656; c0 += 1)
    for (c1 = c0 + 1343; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1343+c0] + S[-c0+c1-1343+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1342+c0] + S[1342+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 656; c0 += 1)
    S[c0][c0+1343] = MAX(S[c0][c0+1343], S[c0+1][c0+1343-1] + can_pair(RNA, c0, c0+1343));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 655; c0 += 1)
    for (c1 = c0 + 1344; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1344+c0] + S[-c0+c1-1344+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1343+c0] + S[1343+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 655; c0 += 1)
    S[c0][c0+1344] = MAX(S[c0][c0+1344], S[c0+1][c0+1344-1] + can_pair(RNA, c0, c0+1344));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 654; c0 += 1)
    for (c1 = c0 + 1345; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1345+c0] + S[-c0+c1-1345+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1344+c0] + S[1344+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 654; c0 += 1)
    S[c0][c0+1345] = MAX(S[c0][c0+1345], S[c0+1][c0+1345-1] + can_pair(RNA, c0, c0+1345));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 653; c0 += 1)
    for (c1 = c0 + 1346; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1346+c0] + S[-c0+c1-1346+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1345+c0] + S[1345+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 653; c0 += 1)
    S[c0][c0+1346] = MAX(S[c0][c0+1346], S[c0+1][c0+1346-1] + can_pair(RNA, c0, c0+1346));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 652; c0 += 1)
    for (c1 = c0 + 1347; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1347+c0] + S[-c0+c1-1347+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1346+c0] + S[1346+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 652; c0 += 1)
    S[c0][c0+1347] = MAX(S[c0][c0+1347], S[c0+1][c0+1347-1] + can_pair(RNA, c0, c0+1347));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 651; c0 += 1)
    for (c1 = c0 + 1348; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1348+c0] + S[-c0+c1-1348+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1347+c0] + S[1347+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 651; c0 += 1)
    S[c0][c0+1348] = MAX(S[c0][c0+1348], S[c0+1][c0+1348-1] + can_pair(RNA, c0, c0+1348));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 650; c0 += 1)
    for (c1 = c0 + 1349; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1349+c0] + S[-c0+c1-1349+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1348+c0] + S[1348+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 650; c0 += 1)
    S[c0][c0+1349] = MAX(S[c0][c0+1349], S[c0+1][c0+1349-1] + can_pair(RNA, c0, c0+1349));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 649; c0 += 1)
    for (c1 = c0 + 1350; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1350+c0] + S[-c0+c1-1350+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1349+c0] + S[1349+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 649; c0 += 1)
    S[c0][c0+1350] = MAX(S[c0][c0+1350], S[c0+1][c0+1350-1] + can_pair(RNA, c0, c0+1350));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 648; c0 += 1)
    for (c1 = c0 + 1351; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1351+c0] + S[-c0+c1-1351+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1350+c0] + S[1350+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 648; c0 += 1)
    S[c0][c0+1351] = MAX(S[c0][c0+1351], S[c0+1][c0+1351-1] + can_pair(RNA, c0, c0+1351));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 647; c0 += 1)
    for (c1 = c0 + 1352; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1352+c0] + S[-c0+c1-1352+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1351+c0] + S[1351+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 647; c0 += 1)
    S[c0][c0+1352] = MAX(S[c0][c0+1352], S[c0+1][c0+1352-1] + can_pair(RNA, c0, c0+1352));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 646; c0 += 1)
    for (c1 = c0 + 1353; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1353+c0] + S[-c0+c1-1353+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1352+c0] + S[1352+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 646; c0 += 1)
    S[c0][c0+1353] = MAX(S[c0][c0+1353], S[c0+1][c0+1353-1] + can_pair(RNA, c0, c0+1353));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 645; c0 += 1)
    for (c1 = c0 + 1354; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1354+c0] + S[-c0+c1-1354+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1353+c0] + S[1353+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 645; c0 += 1)
    S[c0][c0+1354] = MAX(S[c0][c0+1354], S[c0+1][c0+1354-1] + can_pair(RNA, c0, c0+1354));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 644; c0 += 1)
    for (c1 = c0 + 1355; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1355+c0] + S[-c0+c1-1355+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1354+c0] + S[1354+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 644; c0 += 1)
    S[c0][c0+1355] = MAX(S[c0][c0+1355], S[c0+1][c0+1355-1] + can_pair(RNA, c0, c0+1355));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 643; c0 += 1)
    for (c1 = c0 + 1356; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1356+c0] + S[-c0+c1-1356+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1355+c0] + S[1355+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 643; c0 += 1)
    S[c0][c0+1356] = MAX(S[c0][c0+1356], S[c0+1][c0+1356-1] + can_pair(RNA, c0, c0+1356));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 642; c0 += 1)
    for (c1 = c0 + 1357; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1357+c0] + S[-c0+c1-1357+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1356+c0] + S[1356+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 642; c0 += 1)
    S[c0][c0+1357] = MAX(S[c0][c0+1357], S[c0+1][c0+1357-1] + can_pair(RNA, c0, c0+1357));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 641; c0 += 1)
    for (c1 = c0 + 1358; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1358+c0] + S[-c0+c1-1358+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1357+c0] + S[1357+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 641; c0 += 1)
    S[c0][c0+1358] = MAX(S[c0][c0+1358], S[c0+1][c0+1358-1] + can_pair(RNA, c0, c0+1358));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 640; c0 += 1)
    for (c1 = c0 + 1359; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1359+c0] + S[-c0+c1-1359+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1358+c0] + S[1358+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 640; c0 += 1)
    S[c0][c0+1359] = MAX(S[c0][c0+1359], S[c0+1][c0+1359-1] + can_pair(RNA, c0, c0+1359));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 639; c0 += 1)
    for (c1 = c0 + 1360; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1360+c0] + S[-c0+c1-1360+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1359+c0] + S[1359+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 639; c0 += 1)
    S[c0][c0+1360] = MAX(S[c0][c0+1360], S[c0+1][c0+1360-1] + can_pair(RNA, c0, c0+1360));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 638; c0 += 1)
    for (c1 = c0 + 1361; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1361+c0] + S[-c0+c1-1361+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1360+c0] + S[1360+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 638; c0 += 1)
    S[c0][c0+1361] = MAX(S[c0][c0+1361], S[c0+1][c0+1361-1] + can_pair(RNA, c0, c0+1361));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 637; c0 += 1)
    for (c1 = c0 + 1362; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1362+c0] + S[-c0+c1-1362+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1361+c0] + S[1361+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 637; c0 += 1)
    S[c0][c0+1362] = MAX(S[c0][c0+1362], S[c0+1][c0+1362-1] + can_pair(RNA, c0, c0+1362));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 636; c0 += 1)
    for (c1 = c0 + 1363; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1363+c0] + S[-c0+c1-1363+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1362+c0] + S[1362+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 636; c0 += 1)
    S[c0][c0+1363] = MAX(S[c0][c0+1363], S[c0+1][c0+1363-1] + can_pair(RNA, c0, c0+1363));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 635; c0 += 1)
    for (c1 = c0 + 1364; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1364+c0] + S[-c0+c1-1364+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1363+c0] + S[1363+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 635; c0 += 1)
    S[c0][c0+1364] = MAX(S[c0][c0+1364], S[c0+1][c0+1364-1] + can_pair(RNA, c0, c0+1364));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 634; c0 += 1)
    for (c1 = c0 + 1365; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1365+c0] + S[-c0+c1-1365+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1364+c0] + S[1364+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 634; c0 += 1)
    S[c0][c0+1365] = MAX(S[c0][c0+1365], S[c0+1][c0+1365-1] + can_pair(RNA, c0, c0+1365));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 633; c0 += 1)
    for (c1 = c0 + 1366; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1366+c0] + S[-c0+c1-1366+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1365+c0] + S[1365+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 633; c0 += 1)
    S[c0][c0+1366] = MAX(S[c0][c0+1366], S[c0+1][c0+1366-1] + can_pair(RNA, c0, c0+1366));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 632; c0 += 1)
    for (c1 = c0 + 1367; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1367+c0] + S[-c0+c1-1367+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1366+c0] + S[1366+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 632; c0 += 1)
    S[c0][c0+1367] = MAX(S[c0][c0+1367], S[c0+1][c0+1367-1] + can_pair(RNA, c0, c0+1367));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 631; c0 += 1)
    for (c1 = c0 + 1368; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1368+c0] + S[-c0+c1-1368+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1367+c0] + S[1367+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 631; c0 += 1)
    S[c0][c0+1368] = MAX(S[c0][c0+1368], S[c0+1][c0+1368-1] + can_pair(RNA, c0, c0+1368));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 630; c0 += 1)
    for (c1 = c0 + 1369; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1369+c0] + S[-c0+c1-1369+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1368+c0] + S[1368+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 630; c0 += 1)
    S[c0][c0+1369] = MAX(S[c0][c0+1369], S[c0+1][c0+1369-1] + can_pair(RNA, c0, c0+1369));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 629; c0 += 1)
    for (c1 = c0 + 1370; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1370+c0] + S[-c0+c1-1370+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1369+c0] + S[1369+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 629; c0 += 1)
    S[c0][c0+1370] = MAX(S[c0][c0+1370], S[c0+1][c0+1370-1] + can_pair(RNA, c0, c0+1370));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 628; c0 += 1)
    for (c1 = c0 + 1371; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1371+c0] + S[-c0+c1-1371+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1370+c0] + S[1370+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 628; c0 += 1)
    S[c0][c0+1371] = MAX(S[c0][c0+1371], S[c0+1][c0+1371-1] + can_pair(RNA, c0, c0+1371));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 627; c0 += 1)
    for (c1 = c0 + 1372; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1372+c0] + S[-c0+c1-1372+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1371+c0] + S[1371+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 627; c0 += 1)
    S[c0][c0+1372] = MAX(S[c0][c0+1372], S[c0+1][c0+1372-1] + can_pair(RNA, c0, c0+1372));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 626; c0 += 1)
    for (c1 = c0 + 1373; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1373+c0] + S[-c0+c1-1373+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1372+c0] + S[1372+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 626; c0 += 1)
    S[c0][c0+1373] = MAX(S[c0][c0+1373], S[c0+1][c0+1373-1] + can_pair(RNA, c0, c0+1373));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 625; c0 += 1)
    for (c1 = c0 + 1374; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1374+c0] + S[-c0+c1-1374+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1373+c0] + S[1373+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 625; c0 += 1)
    S[c0][c0+1374] = MAX(S[c0][c0+1374], S[c0+1][c0+1374-1] + can_pair(RNA, c0, c0+1374));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 624; c0 += 1)
    for (c1 = c0 + 1375; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1375+c0] + S[-c0+c1-1375+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1374+c0] + S[1374+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 624; c0 += 1)
    S[c0][c0+1375] = MAX(S[c0][c0+1375], S[c0+1][c0+1375-1] + can_pair(RNA, c0, c0+1375));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 623; c0 += 1)
    for (c1 = c0 + 1376; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1376+c0] + S[-c0+c1-1376+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1375+c0] + S[1375+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 623; c0 += 1)
    S[c0][c0+1376] = MAX(S[c0][c0+1376], S[c0+1][c0+1376-1] + can_pair(RNA, c0, c0+1376));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 622; c0 += 1)
    for (c1 = c0 + 1377; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1377+c0] + S[-c0+c1-1377+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1376+c0] + S[1376+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 622; c0 += 1)
    S[c0][c0+1377] = MAX(S[c0][c0+1377], S[c0+1][c0+1377-1] + can_pair(RNA, c0, c0+1377));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 621; c0 += 1)
    for (c1 = c0 + 1378; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1378+c0] + S[-c0+c1-1378+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1377+c0] + S[1377+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 621; c0 += 1)
    S[c0][c0+1378] = MAX(S[c0][c0+1378], S[c0+1][c0+1378-1] + can_pair(RNA, c0, c0+1378));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 620; c0 += 1)
    for (c1 = c0 + 1379; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1379+c0] + S[-c0+c1-1379+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1378+c0] + S[1378+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 620; c0 += 1)
    S[c0][c0+1379] = MAX(S[c0][c0+1379], S[c0+1][c0+1379-1] + can_pair(RNA, c0, c0+1379));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 619; c0 += 1)
    for (c1 = c0 + 1380; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1380+c0] + S[-c0+c1-1380+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1379+c0] + S[1379+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 619; c0 += 1)
    S[c0][c0+1380] = MAX(S[c0][c0+1380], S[c0+1][c0+1380-1] + can_pair(RNA, c0, c0+1380));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 618; c0 += 1)
    for (c1 = c0 + 1381; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1381+c0] + S[-c0+c1-1381+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1380+c0] + S[1380+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 618; c0 += 1)
    S[c0][c0+1381] = MAX(S[c0][c0+1381], S[c0+1][c0+1381-1] + can_pair(RNA, c0, c0+1381));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 617; c0 += 1)
    for (c1 = c0 + 1382; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1382+c0] + S[-c0+c1-1382+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1381+c0] + S[1381+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 617; c0 += 1)
    S[c0][c0+1382] = MAX(S[c0][c0+1382], S[c0+1][c0+1382-1] + can_pair(RNA, c0, c0+1382));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 616; c0 += 1)
    for (c1 = c0 + 1383; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1383+c0] + S[-c0+c1-1383+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1382+c0] + S[1382+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 616; c0 += 1)
    S[c0][c0+1383] = MAX(S[c0][c0+1383], S[c0+1][c0+1383-1] + can_pair(RNA, c0, c0+1383));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 615; c0 += 1)
    for (c1 = c0 + 1384; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1384+c0] + S[-c0+c1-1384+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1383+c0] + S[1383+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 615; c0 += 1)
    S[c0][c0+1384] = MAX(S[c0][c0+1384], S[c0+1][c0+1384-1] + can_pair(RNA, c0, c0+1384));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 614; c0 += 1)
    for (c1 = c0 + 1385; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1385+c0] + S[-c0+c1-1385+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1384+c0] + S[1384+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 614; c0 += 1)
    S[c0][c0+1385] = MAX(S[c0][c0+1385], S[c0+1][c0+1385-1] + can_pair(RNA, c0, c0+1385));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 613; c0 += 1)
    for (c1 = c0 + 1386; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1386+c0] + S[-c0+c1-1386+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1385+c0] + S[1385+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 613; c0 += 1)
    S[c0][c0+1386] = MAX(S[c0][c0+1386], S[c0+1][c0+1386-1] + can_pair(RNA, c0, c0+1386));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 612; c0 += 1)
    for (c1 = c0 + 1387; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1387+c0] + S[-c0+c1-1387+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1386+c0] + S[1386+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 612; c0 += 1)
    S[c0][c0+1387] = MAX(S[c0][c0+1387], S[c0+1][c0+1387-1] + can_pair(RNA, c0, c0+1387));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 611; c0 += 1)
    for (c1 = c0 + 1388; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1388+c0] + S[-c0+c1-1388+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1387+c0] + S[1387+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 611; c0 += 1)
    S[c0][c0+1388] = MAX(S[c0][c0+1388], S[c0+1][c0+1388-1] + can_pair(RNA, c0, c0+1388));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 610; c0 += 1)
    for (c1 = c0 + 1389; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1389+c0] + S[-c0+c1-1389+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1388+c0] + S[1388+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 610; c0 += 1)
    S[c0][c0+1389] = MAX(S[c0][c0+1389], S[c0+1][c0+1389-1] + can_pair(RNA, c0, c0+1389));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 609; c0 += 1)
    for (c1 = c0 + 1390; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1390+c0] + S[-c0+c1-1390+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1389+c0] + S[1389+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 609; c0 += 1)
    S[c0][c0+1390] = MAX(S[c0][c0+1390], S[c0+1][c0+1390-1] + can_pair(RNA, c0, c0+1390));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 608; c0 += 1)
    for (c1 = c0 + 1391; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1391+c0] + S[-c0+c1-1391+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1390+c0] + S[1390+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 608; c0 += 1)
    S[c0][c0+1391] = MAX(S[c0][c0+1391], S[c0+1][c0+1391-1] + can_pair(RNA, c0, c0+1391));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 607; c0 += 1)
    for (c1 = c0 + 1392; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1392+c0] + S[-c0+c1-1392+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1391+c0] + S[1391+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 607; c0 += 1)
    S[c0][c0+1392] = MAX(S[c0][c0+1392], S[c0+1][c0+1392-1] + can_pair(RNA, c0, c0+1392));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 606; c0 += 1)
    for (c1 = c0 + 1393; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1393+c0] + S[-c0+c1-1393+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1392+c0] + S[1392+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 606; c0 += 1)
    S[c0][c0+1393] = MAX(S[c0][c0+1393], S[c0+1][c0+1393-1] + can_pair(RNA, c0, c0+1393));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 605; c0 += 1)
    for (c1 = c0 + 1394; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1394+c0] + S[-c0+c1-1394+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1393+c0] + S[1393+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 605; c0 += 1)
    S[c0][c0+1394] = MAX(S[c0][c0+1394], S[c0+1][c0+1394-1] + can_pair(RNA, c0, c0+1394));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 604; c0 += 1)
    for (c1 = c0 + 1395; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1395+c0] + S[-c0+c1-1395+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1394+c0] + S[1394+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 604; c0 += 1)
    S[c0][c0+1395] = MAX(S[c0][c0+1395], S[c0+1][c0+1395-1] + can_pair(RNA, c0, c0+1395));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 603; c0 += 1)
    for (c1 = c0 + 1396; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1396+c0] + S[-c0+c1-1396+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1395+c0] + S[1395+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 603; c0 += 1)
    S[c0][c0+1396] = MAX(S[c0][c0+1396], S[c0+1][c0+1396-1] + can_pair(RNA, c0, c0+1396));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 602; c0 += 1)
    for (c1 = c0 + 1397; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1397+c0] + S[-c0+c1-1397+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1396+c0] + S[1396+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 602; c0 += 1)
    S[c0][c0+1397] = MAX(S[c0][c0+1397], S[c0+1][c0+1397-1] + can_pair(RNA, c0, c0+1397));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 601; c0 += 1)
    for (c1 = c0 + 1398; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1398+c0] + S[-c0+c1-1398+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1397+c0] + S[1397+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 601; c0 += 1)
    S[c0][c0+1398] = MAX(S[c0][c0+1398], S[c0+1][c0+1398-1] + can_pair(RNA, c0, c0+1398));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 600; c0 += 1)
    for (c1 = c0 + 1399; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1399+c0] + S[-c0+c1-1399+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1398+c0] + S[1398+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 600; c0 += 1)
    S[c0][c0+1399] = MAX(S[c0][c0+1399], S[c0+1][c0+1399-1] + can_pair(RNA, c0, c0+1399));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 599; c0 += 1)
    for (c1 = c0 + 1400; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1400+c0] + S[-c0+c1-1400+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1399+c0] + S[1399+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 599; c0 += 1)
    S[c0][c0+1400] = MAX(S[c0][c0+1400], S[c0+1][c0+1400-1] + can_pair(RNA, c0, c0+1400));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 598; c0 += 1)
    for (c1 = c0 + 1401; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1401+c0] + S[-c0+c1-1401+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1400+c0] + S[1400+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 598; c0 += 1)
    S[c0][c0+1401] = MAX(S[c0][c0+1401], S[c0+1][c0+1401-1] + can_pair(RNA, c0, c0+1401));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 597; c0 += 1)
    for (c1 = c0 + 1402; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1402+c0] + S[-c0+c1-1402+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1401+c0] + S[1401+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 597; c0 += 1)
    S[c0][c0+1402] = MAX(S[c0][c0+1402], S[c0+1][c0+1402-1] + can_pair(RNA, c0, c0+1402));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 596; c0 += 1)
    for (c1 = c0 + 1403; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1403+c0] + S[-c0+c1-1403+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1402+c0] + S[1402+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 596; c0 += 1)
    S[c0][c0+1403] = MAX(S[c0][c0+1403], S[c0+1][c0+1403-1] + can_pair(RNA, c0, c0+1403));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 595; c0 += 1)
    for (c1 = c0 + 1404; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1404+c0] + S[-c0+c1-1404+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1403+c0] + S[1403+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 595; c0 += 1)
    S[c0][c0+1404] = MAX(S[c0][c0+1404], S[c0+1][c0+1404-1] + can_pair(RNA, c0, c0+1404));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 594; c0 += 1)
    for (c1 = c0 + 1405; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1405+c0] + S[-c0+c1-1405+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1404+c0] + S[1404+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 594; c0 += 1)
    S[c0][c0+1405] = MAX(S[c0][c0+1405], S[c0+1][c0+1405-1] + can_pair(RNA, c0, c0+1405));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 593; c0 += 1)
    for (c1 = c0 + 1406; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1406+c0] + S[-c0+c1-1406+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1405+c0] + S[1405+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 593; c0 += 1)
    S[c0][c0+1406] = MAX(S[c0][c0+1406], S[c0+1][c0+1406-1] + can_pair(RNA, c0, c0+1406));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 592; c0 += 1)
    for (c1 = c0 + 1407; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1407+c0] + S[-c0+c1-1407+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1406+c0] + S[1406+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 592; c0 += 1)
    S[c0][c0+1407] = MAX(S[c0][c0+1407], S[c0+1][c0+1407-1] + can_pair(RNA, c0, c0+1407));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 591; c0 += 1)
    for (c1 = c0 + 1408; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1408+c0] + S[-c0+c1-1408+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1407+c0] + S[1407+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 591; c0 += 1)
    S[c0][c0+1408] = MAX(S[c0][c0+1408], S[c0+1][c0+1408-1] + can_pair(RNA, c0, c0+1408));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 590; c0 += 1)
    for (c1 = c0 + 1409; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1409+c0] + S[-c0+c1-1409+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1408+c0] + S[1408+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 590; c0 += 1)
    S[c0][c0+1409] = MAX(S[c0][c0+1409], S[c0+1][c0+1409-1] + can_pair(RNA, c0, c0+1409));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 589; c0 += 1)
    for (c1 = c0 + 1410; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1410+c0] + S[-c0+c1-1410+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1409+c0] + S[1409+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 589; c0 += 1)
    S[c0][c0+1410] = MAX(S[c0][c0+1410], S[c0+1][c0+1410-1] + can_pair(RNA, c0, c0+1410));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 588; c0 += 1)
    for (c1 = c0 + 1411; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1411+c0] + S[-c0+c1-1411+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1410+c0] + S[1410+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 588; c0 += 1)
    S[c0][c0+1411] = MAX(S[c0][c0+1411], S[c0+1][c0+1411-1] + can_pair(RNA, c0, c0+1411));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 587; c0 += 1)
    for (c1 = c0 + 1412; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1412+c0] + S[-c0+c1-1412+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1411+c0] + S[1411+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 587; c0 += 1)
    S[c0][c0+1412] = MAX(S[c0][c0+1412], S[c0+1][c0+1412-1] + can_pair(RNA, c0, c0+1412));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 586; c0 += 1)
    for (c1 = c0 + 1413; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1413+c0] + S[-c0+c1-1413+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1412+c0] + S[1412+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 586; c0 += 1)
    S[c0][c0+1413] = MAX(S[c0][c0+1413], S[c0+1][c0+1413-1] + can_pair(RNA, c0, c0+1413));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 585; c0 += 1)
    for (c1 = c0 + 1414; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1414+c0] + S[-c0+c1-1414+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1413+c0] + S[1413+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 585; c0 += 1)
    S[c0][c0+1414] = MAX(S[c0][c0+1414], S[c0+1][c0+1414-1] + can_pair(RNA, c0, c0+1414));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 584; c0 += 1)
    for (c1 = c0 + 1415; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1415+c0] + S[-c0+c1-1415+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1414+c0] + S[1414+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 584; c0 += 1)
    S[c0][c0+1415] = MAX(S[c0][c0+1415], S[c0+1][c0+1415-1] + can_pair(RNA, c0, c0+1415));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 583; c0 += 1)
    for (c1 = c0 + 1416; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1416+c0] + S[-c0+c1-1416+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1415+c0] + S[1415+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 583; c0 += 1)
    S[c0][c0+1416] = MAX(S[c0][c0+1416], S[c0+1][c0+1416-1] + can_pair(RNA, c0, c0+1416));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 582; c0 += 1)
    for (c1 = c0 + 1417; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1417+c0] + S[-c0+c1-1417+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1416+c0] + S[1416+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 582; c0 += 1)
    S[c0][c0+1417] = MAX(S[c0][c0+1417], S[c0+1][c0+1417-1] + can_pair(RNA, c0, c0+1417));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 581; c0 += 1)
    for (c1 = c0 + 1418; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1418+c0] + S[-c0+c1-1418+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1417+c0] + S[1417+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 581; c0 += 1)
    S[c0][c0+1418] = MAX(S[c0][c0+1418], S[c0+1][c0+1418-1] + can_pair(RNA, c0, c0+1418));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 580; c0 += 1)
    for (c1 = c0 + 1419; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1419+c0] + S[-c0+c1-1419+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1418+c0] + S[1418+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 580; c0 += 1)
    S[c0][c0+1419] = MAX(S[c0][c0+1419], S[c0+1][c0+1419-1] + can_pair(RNA, c0, c0+1419));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 579; c0 += 1)
    for (c1 = c0 + 1420; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1420+c0] + S[-c0+c1-1420+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1419+c0] + S[1419+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 579; c0 += 1)
    S[c0][c0+1420] = MAX(S[c0][c0+1420], S[c0+1][c0+1420-1] + can_pair(RNA, c0, c0+1420));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 578; c0 += 1)
    for (c1 = c0 + 1421; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1421+c0] + S[-c0+c1-1421+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1420+c0] + S[1420+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 578; c0 += 1)
    S[c0][c0+1421] = MAX(S[c0][c0+1421], S[c0+1][c0+1421-1] + can_pair(RNA, c0, c0+1421));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 577; c0 += 1)
    for (c1 = c0 + 1422; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1422+c0] + S[-c0+c1-1422+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1421+c0] + S[1421+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 577; c0 += 1)
    S[c0][c0+1422] = MAX(S[c0][c0+1422], S[c0+1][c0+1422-1] + can_pair(RNA, c0, c0+1422));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 576; c0 += 1)
    for (c1 = c0 + 1423; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1423+c0] + S[-c0+c1-1423+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1422+c0] + S[1422+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 576; c0 += 1)
    S[c0][c0+1423] = MAX(S[c0][c0+1423], S[c0+1][c0+1423-1] + can_pair(RNA, c0, c0+1423));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 575; c0 += 1)
    for (c1 = c0 + 1424; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1424+c0] + S[-c0+c1-1424+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1423+c0] + S[1423+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 575; c0 += 1)
    S[c0][c0+1424] = MAX(S[c0][c0+1424], S[c0+1][c0+1424-1] + can_pair(RNA, c0, c0+1424));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 574; c0 += 1)
    for (c1 = c0 + 1425; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1425+c0] + S[-c0+c1-1425+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1424+c0] + S[1424+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 574; c0 += 1)
    S[c0][c0+1425] = MAX(S[c0][c0+1425], S[c0+1][c0+1425-1] + can_pair(RNA, c0, c0+1425));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 573; c0 += 1)
    for (c1 = c0 + 1426; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1426+c0] + S[-c0+c1-1426+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1425+c0] + S[1425+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 573; c0 += 1)
    S[c0][c0+1426] = MAX(S[c0][c0+1426], S[c0+1][c0+1426-1] + can_pair(RNA, c0, c0+1426));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 572; c0 += 1)
    for (c1 = c0 + 1427; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1427+c0] + S[-c0+c1-1427+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1426+c0] + S[1426+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 572; c0 += 1)
    S[c0][c0+1427] = MAX(S[c0][c0+1427], S[c0+1][c0+1427-1] + can_pair(RNA, c0, c0+1427));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 571; c0 += 1)
    for (c1 = c0 + 1428; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1428+c0] + S[-c0+c1-1428+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1427+c0] + S[1427+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 571; c0 += 1)
    S[c0][c0+1428] = MAX(S[c0][c0+1428], S[c0+1][c0+1428-1] + can_pair(RNA, c0, c0+1428));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 570; c0 += 1)
    for (c1 = c0 + 1429; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1429+c0] + S[-c0+c1-1429+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1428+c0] + S[1428+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 570; c0 += 1)
    S[c0][c0+1429] = MAX(S[c0][c0+1429], S[c0+1][c0+1429-1] + can_pair(RNA, c0, c0+1429));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 569; c0 += 1)
    for (c1 = c0 + 1430; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1430+c0] + S[-c0+c1-1430+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1429+c0] + S[1429+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 569; c0 += 1)
    S[c0][c0+1430] = MAX(S[c0][c0+1430], S[c0+1][c0+1430-1] + can_pair(RNA, c0, c0+1430));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 568; c0 += 1)
    for (c1 = c0 + 1431; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1431+c0] + S[-c0+c1-1431+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1430+c0] + S[1430+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 568; c0 += 1)
    S[c0][c0+1431] = MAX(S[c0][c0+1431], S[c0+1][c0+1431-1] + can_pair(RNA, c0, c0+1431));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 567; c0 += 1)
    for (c1 = c0 + 1432; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1432+c0] + S[-c0+c1-1432+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1431+c0] + S[1431+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 567; c0 += 1)
    S[c0][c0+1432] = MAX(S[c0][c0+1432], S[c0+1][c0+1432-1] + can_pair(RNA, c0, c0+1432));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 566; c0 += 1)
    for (c1 = c0 + 1433; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1433+c0] + S[-c0+c1-1433+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1432+c0] + S[1432+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 566; c0 += 1)
    S[c0][c0+1433] = MAX(S[c0][c0+1433], S[c0+1][c0+1433-1] + can_pair(RNA, c0, c0+1433));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 565; c0 += 1)
    for (c1 = c0 + 1434; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1434+c0] + S[-c0+c1-1434+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1433+c0] + S[1433+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 565; c0 += 1)
    S[c0][c0+1434] = MAX(S[c0][c0+1434], S[c0+1][c0+1434-1] + can_pair(RNA, c0, c0+1434));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 564; c0 += 1)
    for (c1 = c0 + 1435; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1435+c0] + S[-c0+c1-1435+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1434+c0] + S[1434+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 564; c0 += 1)
    S[c0][c0+1435] = MAX(S[c0][c0+1435], S[c0+1][c0+1435-1] + can_pair(RNA, c0, c0+1435));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 563; c0 += 1)
    for (c1 = c0 + 1436; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1436+c0] + S[-c0+c1-1436+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1435+c0] + S[1435+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 563; c0 += 1)
    S[c0][c0+1436] = MAX(S[c0][c0+1436], S[c0+1][c0+1436-1] + can_pair(RNA, c0, c0+1436));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 562; c0 += 1)
    for (c1 = c0 + 1437; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1437+c0] + S[-c0+c1-1437+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1436+c0] + S[1436+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 562; c0 += 1)
    S[c0][c0+1437] = MAX(S[c0][c0+1437], S[c0+1][c0+1437-1] + can_pair(RNA, c0, c0+1437));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 561; c0 += 1)
    for (c1 = c0 + 1438; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1438+c0] + S[-c0+c1-1438+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1437+c0] + S[1437+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 561; c0 += 1)
    S[c0][c0+1438] = MAX(S[c0][c0+1438], S[c0+1][c0+1438-1] + can_pair(RNA, c0, c0+1438));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 560; c0 += 1)
    for (c1 = c0 + 1439; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1439+c0] + S[-c0+c1-1439+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1438+c0] + S[1438+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 560; c0 += 1)
    S[c0][c0+1439] = MAX(S[c0][c0+1439], S[c0+1][c0+1439-1] + can_pair(RNA, c0, c0+1439));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 559; c0 += 1)
    for (c1 = c0 + 1440; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1440+c0] + S[-c0+c1-1440+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1439+c0] + S[1439+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 559; c0 += 1)
    S[c0][c0+1440] = MAX(S[c0][c0+1440], S[c0+1][c0+1440-1] + can_pair(RNA, c0, c0+1440));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 558; c0 += 1)
    for (c1 = c0 + 1441; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1441+c0] + S[-c0+c1-1441+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1440+c0] + S[1440+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 558; c0 += 1)
    S[c0][c0+1441] = MAX(S[c0][c0+1441], S[c0+1][c0+1441-1] + can_pair(RNA, c0, c0+1441));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 557; c0 += 1)
    for (c1 = c0 + 1442; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1442+c0] + S[-c0+c1-1442+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1441+c0] + S[1441+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 557; c0 += 1)
    S[c0][c0+1442] = MAX(S[c0][c0+1442], S[c0+1][c0+1442-1] + can_pair(RNA, c0, c0+1442));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 556; c0 += 1)
    for (c1 = c0 + 1443; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1443+c0] + S[-c0+c1-1443+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1442+c0] + S[1442+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 556; c0 += 1)
    S[c0][c0+1443] = MAX(S[c0][c0+1443], S[c0+1][c0+1443-1] + can_pair(RNA, c0, c0+1443));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 555; c0 += 1)
    for (c1 = c0 + 1444; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1444+c0] + S[-c0+c1-1444+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1443+c0] + S[1443+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 555; c0 += 1)
    S[c0][c0+1444] = MAX(S[c0][c0+1444], S[c0+1][c0+1444-1] + can_pair(RNA, c0, c0+1444));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 554; c0 += 1)
    for (c1 = c0 + 1445; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1445+c0] + S[-c0+c1-1445+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1444+c0] + S[1444+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 554; c0 += 1)
    S[c0][c0+1445] = MAX(S[c0][c0+1445], S[c0+1][c0+1445-1] + can_pair(RNA, c0, c0+1445));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 553; c0 += 1)
    for (c1 = c0 + 1446; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1446+c0] + S[-c0+c1-1446+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1445+c0] + S[1445+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 553; c0 += 1)
    S[c0][c0+1446] = MAX(S[c0][c0+1446], S[c0+1][c0+1446-1] + can_pair(RNA, c0, c0+1446));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 552; c0 += 1)
    for (c1 = c0 + 1447; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1447+c0] + S[-c0+c1-1447+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1446+c0] + S[1446+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 552; c0 += 1)
    S[c0][c0+1447] = MAX(S[c0][c0+1447], S[c0+1][c0+1447-1] + can_pair(RNA, c0, c0+1447));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 551; c0 += 1)
    for (c1 = c0 + 1448; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1448+c0] + S[-c0+c1-1448+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1447+c0] + S[1447+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 551; c0 += 1)
    S[c0][c0+1448] = MAX(S[c0][c0+1448], S[c0+1][c0+1448-1] + can_pair(RNA, c0, c0+1448));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 550; c0 += 1)
    for (c1 = c0 + 1449; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1449+c0] + S[-c0+c1-1449+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1448+c0] + S[1448+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 550; c0 += 1)
    S[c0][c0+1449] = MAX(S[c0][c0+1449], S[c0+1][c0+1449-1] + can_pair(RNA, c0, c0+1449));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 549; c0 += 1)
    for (c1 = c0 + 1450; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1450+c0] + S[-c0+c1-1450+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1449+c0] + S[1449+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 549; c0 += 1)
    S[c0][c0+1450] = MAX(S[c0][c0+1450], S[c0+1][c0+1450-1] + can_pair(RNA, c0, c0+1450));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 548; c0 += 1)
    for (c1 = c0 + 1451; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1451+c0] + S[-c0+c1-1451+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1450+c0] + S[1450+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 548; c0 += 1)
    S[c0][c0+1451] = MAX(S[c0][c0+1451], S[c0+1][c0+1451-1] + can_pair(RNA, c0, c0+1451));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 547; c0 += 1)
    for (c1 = c0 + 1452; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1452+c0] + S[-c0+c1-1452+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1451+c0] + S[1451+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 547; c0 += 1)
    S[c0][c0+1452] = MAX(S[c0][c0+1452], S[c0+1][c0+1452-1] + can_pair(RNA, c0, c0+1452));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 546; c0 += 1)
    for (c1 = c0 + 1453; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1453+c0] + S[-c0+c1-1453+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1452+c0] + S[1452+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 546; c0 += 1)
    S[c0][c0+1453] = MAX(S[c0][c0+1453], S[c0+1][c0+1453-1] + can_pair(RNA, c0, c0+1453));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 545; c0 += 1)
    for (c1 = c0 + 1454; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1454+c0] + S[-c0+c1-1454+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1453+c0] + S[1453+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 545; c0 += 1)
    S[c0][c0+1454] = MAX(S[c0][c0+1454], S[c0+1][c0+1454-1] + can_pair(RNA, c0, c0+1454));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 544; c0 += 1)
    for (c1 = c0 + 1455; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1455+c0] + S[-c0+c1-1455+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1454+c0] + S[1454+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 544; c0 += 1)
    S[c0][c0+1455] = MAX(S[c0][c0+1455], S[c0+1][c0+1455-1] + can_pair(RNA, c0, c0+1455));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 543; c0 += 1)
    for (c1 = c0 + 1456; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1456+c0] + S[-c0+c1-1456+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1455+c0] + S[1455+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 543; c0 += 1)
    S[c0][c0+1456] = MAX(S[c0][c0+1456], S[c0+1][c0+1456-1] + can_pair(RNA, c0, c0+1456));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 542; c0 += 1)
    for (c1 = c0 + 1457; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1457+c0] + S[-c0+c1-1457+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1456+c0] + S[1456+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 542; c0 += 1)
    S[c0][c0+1457] = MAX(S[c0][c0+1457], S[c0+1][c0+1457-1] + can_pair(RNA, c0, c0+1457));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 541; c0 += 1)
    for (c1 = c0 + 1458; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1458+c0] + S[-c0+c1-1458+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1457+c0] + S[1457+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 541; c0 += 1)
    S[c0][c0+1458] = MAX(S[c0][c0+1458], S[c0+1][c0+1458-1] + can_pair(RNA, c0, c0+1458));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 540; c0 += 1)
    for (c1 = c0 + 1459; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1459+c0] + S[-c0+c1-1459+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1458+c0] + S[1458+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 540; c0 += 1)
    S[c0][c0+1459] = MAX(S[c0][c0+1459], S[c0+1][c0+1459-1] + can_pair(RNA, c0, c0+1459));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 539; c0 += 1)
    for (c1 = c0 + 1460; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1460+c0] + S[-c0+c1-1460+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1459+c0] + S[1459+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 539; c0 += 1)
    S[c0][c0+1460] = MAX(S[c0][c0+1460], S[c0+1][c0+1460-1] + can_pair(RNA, c0, c0+1460));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 538; c0 += 1)
    for (c1 = c0 + 1461; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1461+c0] + S[-c0+c1-1461+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1460+c0] + S[1460+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 538; c0 += 1)
    S[c0][c0+1461] = MAX(S[c0][c0+1461], S[c0+1][c0+1461-1] + can_pair(RNA, c0, c0+1461));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 537; c0 += 1)
    for (c1 = c0 + 1462; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1462+c0] + S[-c0+c1-1462+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1461+c0] + S[1461+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 537; c0 += 1)
    S[c0][c0+1462] = MAX(S[c0][c0+1462], S[c0+1][c0+1462-1] + can_pair(RNA, c0, c0+1462));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 536; c0 += 1)
    for (c1 = c0 + 1463; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1463+c0] + S[-c0+c1-1463+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1462+c0] + S[1462+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 536; c0 += 1)
    S[c0][c0+1463] = MAX(S[c0][c0+1463], S[c0+1][c0+1463-1] + can_pair(RNA, c0, c0+1463));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 535; c0 += 1)
    for (c1 = c0 + 1464; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1464+c0] + S[-c0+c1-1464+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1463+c0] + S[1463+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 535; c0 += 1)
    S[c0][c0+1464] = MAX(S[c0][c0+1464], S[c0+1][c0+1464-1] + can_pair(RNA, c0, c0+1464));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 534; c0 += 1)
    for (c1 = c0 + 1465; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1465+c0] + S[-c0+c1-1465+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1464+c0] + S[1464+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 534; c0 += 1)
    S[c0][c0+1465] = MAX(S[c0][c0+1465], S[c0+1][c0+1465-1] + can_pair(RNA, c0, c0+1465));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 533; c0 += 1)
    for (c1 = c0 + 1466; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1466+c0] + S[-c0+c1-1466+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1465+c0] + S[1465+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 533; c0 += 1)
    S[c0][c0+1466] = MAX(S[c0][c0+1466], S[c0+1][c0+1466-1] + can_pair(RNA, c0, c0+1466));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 532; c0 += 1)
    for (c1 = c0 + 1467; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1467+c0] + S[-c0+c1-1467+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1466+c0] + S[1466+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 532; c0 += 1)
    S[c0][c0+1467] = MAX(S[c0][c0+1467], S[c0+1][c0+1467-1] + can_pair(RNA, c0, c0+1467));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 531; c0 += 1)
    for (c1 = c0 + 1468; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1468+c0] + S[-c0+c1-1468+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1467+c0] + S[1467+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 531; c0 += 1)
    S[c0][c0+1468] = MAX(S[c0][c0+1468], S[c0+1][c0+1468-1] + can_pair(RNA, c0, c0+1468));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 530; c0 += 1)
    for (c1 = c0 + 1469; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1469+c0] + S[-c0+c1-1469+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1468+c0] + S[1468+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 530; c0 += 1)
    S[c0][c0+1469] = MAX(S[c0][c0+1469], S[c0+1][c0+1469-1] + can_pair(RNA, c0, c0+1469));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 529; c0 += 1)
    for (c1 = c0 + 1470; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1470+c0] + S[-c0+c1-1470+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1469+c0] + S[1469+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 529; c0 += 1)
    S[c0][c0+1470] = MAX(S[c0][c0+1470], S[c0+1][c0+1470-1] + can_pair(RNA, c0, c0+1470));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 528; c0 += 1)
    for (c1 = c0 + 1471; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1471+c0] + S[-c0+c1-1471+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1470+c0] + S[1470+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 528; c0 += 1)
    S[c0][c0+1471] = MAX(S[c0][c0+1471], S[c0+1][c0+1471-1] + can_pair(RNA, c0, c0+1471));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 527; c0 += 1)
    for (c1 = c0 + 1472; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1472+c0] + S[-c0+c1-1472+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1471+c0] + S[1471+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 527; c0 += 1)
    S[c0][c0+1472] = MAX(S[c0][c0+1472], S[c0+1][c0+1472-1] + can_pair(RNA, c0, c0+1472));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 526; c0 += 1)
    for (c1 = c0 + 1473; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1473+c0] + S[-c0+c1-1473+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1472+c0] + S[1472+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 526; c0 += 1)
    S[c0][c0+1473] = MAX(S[c0][c0+1473], S[c0+1][c0+1473-1] + can_pair(RNA, c0, c0+1473));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 525; c0 += 1)
    for (c1 = c0 + 1474; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1474+c0] + S[-c0+c1-1474+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1473+c0] + S[1473+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 525; c0 += 1)
    S[c0][c0+1474] = MAX(S[c0][c0+1474], S[c0+1][c0+1474-1] + can_pair(RNA, c0, c0+1474));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 524; c0 += 1)
    for (c1 = c0 + 1475; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1475+c0] + S[-c0+c1-1475+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1474+c0] + S[1474+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 524; c0 += 1)
    S[c0][c0+1475] = MAX(S[c0][c0+1475], S[c0+1][c0+1475-1] + can_pair(RNA, c0, c0+1475));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 523; c0 += 1)
    for (c1 = c0 + 1476; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1476+c0] + S[-c0+c1-1476+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1475+c0] + S[1475+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 523; c0 += 1)
    S[c0][c0+1476] = MAX(S[c0][c0+1476], S[c0+1][c0+1476-1] + can_pair(RNA, c0, c0+1476));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 522; c0 += 1)
    for (c1 = c0 + 1477; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1477+c0] + S[-c0+c1-1477+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1476+c0] + S[1476+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 522; c0 += 1)
    S[c0][c0+1477] = MAX(S[c0][c0+1477], S[c0+1][c0+1477-1] + can_pair(RNA, c0, c0+1477));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 521; c0 += 1)
    for (c1 = c0 + 1478; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1478+c0] + S[-c0+c1-1478+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1477+c0] + S[1477+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 521; c0 += 1)
    S[c0][c0+1478] = MAX(S[c0][c0+1478], S[c0+1][c0+1478-1] + can_pair(RNA, c0, c0+1478));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 520; c0 += 1)
    for (c1 = c0 + 1479; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1479+c0] + S[-c0+c1-1479+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1478+c0] + S[1478+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 520; c0 += 1)
    S[c0][c0+1479] = MAX(S[c0][c0+1479], S[c0+1][c0+1479-1] + can_pair(RNA, c0, c0+1479));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 519; c0 += 1)
    for (c1 = c0 + 1480; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1480+c0] + S[-c0+c1-1480+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1479+c0] + S[1479+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 519; c0 += 1)
    S[c0][c0+1480] = MAX(S[c0][c0+1480], S[c0+1][c0+1480-1] + can_pair(RNA, c0, c0+1480));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 518; c0 += 1)
    for (c1 = c0 + 1481; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1481+c0] + S[-c0+c1-1481+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1480+c0] + S[1480+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 518; c0 += 1)
    S[c0][c0+1481] = MAX(S[c0][c0+1481], S[c0+1][c0+1481-1] + can_pair(RNA, c0, c0+1481));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 517; c0 += 1)
    for (c1 = c0 + 1482; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1482+c0] + S[-c0+c1-1482+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1481+c0] + S[1481+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 517; c0 += 1)
    S[c0][c0+1482] = MAX(S[c0][c0+1482], S[c0+1][c0+1482-1] + can_pair(RNA, c0, c0+1482));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 516; c0 += 1)
    for (c1 = c0 + 1483; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1483+c0] + S[-c0+c1-1483+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1482+c0] + S[1482+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 516; c0 += 1)
    S[c0][c0+1483] = MAX(S[c0][c0+1483], S[c0+1][c0+1483-1] + can_pair(RNA, c0, c0+1483));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 515; c0 += 1)
    for (c1 = c0 + 1484; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1484+c0] + S[-c0+c1-1484+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1483+c0] + S[1483+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 515; c0 += 1)
    S[c0][c0+1484] = MAX(S[c0][c0+1484], S[c0+1][c0+1484-1] + can_pair(RNA, c0, c0+1484));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 514; c0 += 1)
    for (c1 = c0 + 1485; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1485+c0] + S[-c0+c1-1485+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1484+c0] + S[1484+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 514; c0 += 1)
    S[c0][c0+1485] = MAX(S[c0][c0+1485], S[c0+1][c0+1485-1] + can_pair(RNA, c0, c0+1485));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 513; c0 += 1)
    for (c1 = c0 + 1486; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1486+c0] + S[-c0+c1-1486+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1485+c0] + S[1485+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 513; c0 += 1)
    S[c0][c0+1486] = MAX(S[c0][c0+1486], S[c0+1][c0+1486-1] + can_pair(RNA, c0, c0+1486));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 512; c0 += 1)
    for (c1 = c0 + 1487; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1487+c0] + S[-c0+c1-1487+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1486+c0] + S[1486+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 512; c0 += 1)
    S[c0][c0+1487] = MAX(S[c0][c0+1487], S[c0+1][c0+1487-1] + can_pair(RNA, c0, c0+1487));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 511; c0 += 1)
    for (c1 = c0 + 1488; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1488+c0] + S[-c0+c1-1488+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1487+c0] + S[1487+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 511; c0 += 1)
    S[c0][c0+1488] = MAX(S[c0][c0+1488], S[c0+1][c0+1488-1] + can_pair(RNA, c0, c0+1488));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 510; c0 += 1)
    for (c1 = c0 + 1489; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1489+c0] + S[-c0+c1-1489+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1488+c0] + S[1488+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 510; c0 += 1)
    S[c0][c0+1489] = MAX(S[c0][c0+1489], S[c0+1][c0+1489-1] + can_pair(RNA, c0, c0+1489));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 509; c0 += 1)
    for (c1 = c0 + 1490; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1490+c0] + S[-c0+c1-1490+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1489+c0] + S[1489+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 509; c0 += 1)
    S[c0][c0+1490] = MAX(S[c0][c0+1490], S[c0+1][c0+1490-1] + can_pair(RNA, c0, c0+1490));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 508; c0 += 1)
    for (c1 = c0 + 1491; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1491+c0] + S[-c0+c1-1491+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1490+c0] + S[1490+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 508; c0 += 1)
    S[c0][c0+1491] = MAX(S[c0][c0+1491], S[c0+1][c0+1491-1] + can_pair(RNA, c0, c0+1491));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 507; c0 += 1)
    for (c1 = c0 + 1492; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1492+c0] + S[-c0+c1-1492+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1491+c0] + S[1491+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 507; c0 += 1)
    S[c0][c0+1492] = MAX(S[c0][c0+1492], S[c0+1][c0+1492-1] + can_pair(RNA, c0, c0+1492));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 506; c0 += 1)
    for (c1 = c0 + 1493; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1493+c0] + S[-c0+c1-1493+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1492+c0] + S[1492+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 506; c0 += 1)
    S[c0][c0+1493] = MAX(S[c0][c0+1493], S[c0+1][c0+1493-1] + can_pair(RNA, c0, c0+1493));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 505; c0 += 1)
    for (c1 = c0 + 1494; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1494+c0] + S[-c0+c1-1494+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1493+c0] + S[1493+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 505; c0 += 1)
    S[c0][c0+1494] = MAX(S[c0][c0+1494], S[c0+1][c0+1494-1] + can_pair(RNA, c0, c0+1494));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 504; c0 += 1)
    for (c1 = c0 + 1495; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1495+c0] + S[-c0+c1-1495+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1494+c0] + S[1494+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 504; c0 += 1)
    S[c0][c0+1495] = MAX(S[c0][c0+1495], S[c0+1][c0+1495-1] + can_pair(RNA, c0, c0+1495));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 503; c0 += 1)
    for (c1 = c0 + 1496; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1496+c0] + S[-c0+c1-1496+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1495+c0] + S[1495+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 503; c0 += 1)
    S[c0][c0+1496] = MAX(S[c0][c0+1496], S[c0+1][c0+1496-1] + can_pair(RNA, c0, c0+1496));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 502; c0 += 1)
    for (c1 = c0 + 1497; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1497+c0] + S[-c0+c1-1497+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1496+c0] + S[1496+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 502; c0 += 1)
    S[c0][c0+1497] = MAX(S[c0][c0+1497], S[c0+1][c0+1497-1] + can_pair(RNA, c0, c0+1497));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 501; c0 += 1)
    for (c1 = c0 + 1498; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1498+c0] + S[-c0+c1-1498+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1497+c0] + S[1497+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 501; c0 += 1)
    S[c0][c0+1498] = MAX(S[c0][c0+1498], S[c0+1][c0+1498-1] + can_pair(RNA, c0, c0+1498));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 500; c0 += 1)
    for (c1 = c0 + 1499; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1499+c0] + S[-c0+c1-1499+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1498+c0] + S[1498+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 500; c0 += 1)
    S[c0][c0+1499] = MAX(S[c0][c0+1499], S[c0+1][c0+1499-1] + can_pair(RNA, c0, c0+1499));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 499; c0 += 1)
    for (c1 = c0 + 1500; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1500+c0] + S[-c0+c1-1500+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1499+c0] + S[1499+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 499; c0 += 1)
    S[c0][c0+1500] = MAX(S[c0][c0+1500], S[c0+1][c0+1500-1] + can_pair(RNA, c0, c0+1500));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 498; c0 += 1)
    for (c1 = c0 + 1501; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1501+c0] + S[-c0+c1-1501+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1500+c0] + S[1500+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 498; c0 += 1)
    S[c0][c0+1501] = MAX(S[c0][c0+1501], S[c0+1][c0+1501-1] + can_pair(RNA, c0, c0+1501));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 497; c0 += 1)
    for (c1 = c0 + 1502; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1502+c0] + S[-c0+c1-1502+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1501+c0] + S[1501+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 497; c0 += 1)
    S[c0][c0+1502] = MAX(S[c0][c0+1502], S[c0+1][c0+1502-1] + can_pair(RNA, c0, c0+1502));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 496; c0 += 1)
    for (c1 = c0 + 1503; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1503+c0] + S[-c0+c1-1503+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1502+c0] + S[1502+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 496; c0 += 1)
    S[c0][c0+1503] = MAX(S[c0][c0+1503], S[c0+1][c0+1503-1] + can_pair(RNA, c0, c0+1503));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 495; c0 += 1)
    for (c1 = c0 + 1504; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1504+c0] + S[-c0+c1-1504+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1503+c0] + S[1503+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 495; c0 += 1)
    S[c0][c0+1504] = MAX(S[c0][c0+1504], S[c0+1][c0+1504-1] + can_pair(RNA, c0, c0+1504));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 494; c0 += 1)
    for (c1 = c0 + 1505; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1505+c0] + S[-c0+c1-1505+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1504+c0] + S[1504+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 494; c0 += 1)
    S[c0][c0+1505] = MAX(S[c0][c0+1505], S[c0+1][c0+1505-1] + can_pair(RNA, c0, c0+1505));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 493; c0 += 1)
    for (c1 = c0 + 1506; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1506+c0] + S[-c0+c1-1506+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1505+c0] + S[1505+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 493; c0 += 1)
    S[c0][c0+1506] = MAX(S[c0][c0+1506], S[c0+1][c0+1506-1] + can_pair(RNA, c0, c0+1506));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 492; c0 += 1)
    for (c1 = c0 + 1507; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1507+c0] + S[-c0+c1-1507+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1506+c0] + S[1506+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 492; c0 += 1)
    S[c0][c0+1507] = MAX(S[c0][c0+1507], S[c0+1][c0+1507-1] + can_pair(RNA, c0, c0+1507));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 491; c0 += 1)
    for (c1 = c0 + 1508; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1508+c0] + S[-c0+c1-1508+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1507+c0] + S[1507+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 491; c0 += 1)
    S[c0][c0+1508] = MAX(S[c0][c0+1508], S[c0+1][c0+1508-1] + can_pair(RNA, c0, c0+1508));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 490; c0 += 1)
    for (c1 = c0 + 1509; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1509+c0] + S[-c0+c1-1509+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1508+c0] + S[1508+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 490; c0 += 1)
    S[c0][c0+1509] = MAX(S[c0][c0+1509], S[c0+1][c0+1509-1] + can_pair(RNA, c0, c0+1509));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 489; c0 += 1)
    for (c1 = c0 + 1510; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1510+c0] + S[-c0+c1-1510+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1509+c0] + S[1509+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 489; c0 += 1)
    S[c0][c0+1510] = MAX(S[c0][c0+1510], S[c0+1][c0+1510-1] + can_pair(RNA, c0, c0+1510));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 488; c0 += 1)
    for (c1 = c0 + 1511; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1511+c0] + S[-c0+c1-1511+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1510+c0] + S[1510+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 488; c0 += 1)
    S[c0][c0+1511] = MAX(S[c0][c0+1511], S[c0+1][c0+1511-1] + can_pair(RNA, c0, c0+1511));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 487; c0 += 1)
    for (c1 = c0 + 1512; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1512+c0] + S[-c0+c1-1512+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1511+c0] + S[1511+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 487; c0 += 1)
    S[c0][c0+1512] = MAX(S[c0][c0+1512], S[c0+1][c0+1512-1] + can_pair(RNA, c0, c0+1512));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 486; c0 += 1)
    for (c1 = c0 + 1513; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1513+c0] + S[-c0+c1-1513+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1512+c0] + S[1512+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 486; c0 += 1)
    S[c0][c0+1513] = MAX(S[c0][c0+1513], S[c0+1][c0+1513-1] + can_pair(RNA, c0, c0+1513));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 485; c0 += 1)
    for (c1 = c0 + 1514; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1514+c0] + S[-c0+c1-1514+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1513+c0] + S[1513+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 485; c0 += 1)
    S[c0][c0+1514] = MAX(S[c0][c0+1514], S[c0+1][c0+1514-1] + can_pair(RNA, c0, c0+1514));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 484; c0 += 1)
    for (c1 = c0 + 1515; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1515+c0] + S[-c0+c1-1515+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1514+c0] + S[1514+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 484; c0 += 1)
    S[c0][c0+1515] = MAX(S[c0][c0+1515], S[c0+1][c0+1515-1] + can_pair(RNA, c0, c0+1515));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 483; c0 += 1)
    for (c1 = c0 + 1516; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1516+c0] + S[-c0+c1-1516+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1515+c0] + S[1515+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 483; c0 += 1)
    S[c0][c0+1516] = MAX(S[c0][c0+1516], S[c0+1][c0+1516-1] + can_pair(RNA, c0, c0+1516));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 482; c0 += 1)
    for (c1 = c0 + 1517; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1517+c0] + S[-c0+c1-1517+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1516+c0] + S[1516+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 482; c0 += 1)
    S[c0][c0+1517] = MAX(S[c0][c0+1517], S[c0+1][c0+1517-1] + can_pair(RNA, c0, c0+1517));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 481; c0 += 1)
    for (c1 = c0 + 1518; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1518+c0] + S[-c0+c1-1518+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1517+c0] + S[1517+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 481; c0 += 1)
    S[c0][c0+1518] = MAX(S[c0][c0+1518], S[c0+1][c0+1518-1] + can_pair(RNA, c0, c0+1518));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 480; c0 += 1)
    for (c1 = c0 + 1519; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1519+c0] + S[-c0+c1-1519+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1518+c0] + S[1518+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 480; c0 += 1)
    S[c0][c0+1519] = MAX(S[c0][c0+1519], S[c0+1][c0+1519-1] + can_pair(RNA, c0, c0+1519));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 479; c0 += 1)
    for (c1 = c0 + 1520; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1520+c0] + S[-c0+c1-1520+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1519+c0] + S[1519+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 479; c0 += 1)
    S[c0][c0+1520] = MAX(S[c0][c0+1520], S[c0+1][c0+1520-1] + can_pair(RNA, c0, c0+1520));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 478; c0 += 1)
    for (c1 = c0 + 1521; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1521+c0] + S[-c0+c1-1521+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1520+c0] + S[1520+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 478; c0 += 1)
    S[c0][c0+1521] = MAX(S[c0][c0+1521], S[c0+1][c0+1521-1] + can_pair(RNA, c0, c0+1521));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 477; c0 += 1)
    for (c1 = c0 + 1522; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1522+c0] + S[-c0+c1-1522+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1521+c0] + S[1521+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 477; c0 += 1)
    S[c0][c0+1522] = MAX(S[c0][c0+1522], S[c0+1][c0+1522-1] + can_pair(RNA, c0, c0+1522));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 476; c0 += 1)
    for (c1 = c0 + 1523; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1523+c0] + S[-c0+c1-1523+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1522+c0] + S[1522+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 476; c0 += 1)
    S[c0][c0+1523] = MAX(S[c0][c0+1523], S[c0+1][c0+1523-1] + can_pair(RNA, c0, c0+1523));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 475; c0 += 1)
    for (c1 = c0 + 1524; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1524+c0] + S[-c0+c1-1524+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1523+c0] + S[1523+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 475; c0 += 1)
    S[c0][c0+1524] = MAX(S[c0][c0+1524], S[c0+1][c0+1524-1] + can_pair(RNA, c0, c0+1524));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 474; c0 += 1)
    for (c1 = c0 + 1525; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1525+c0] + S[-c0+c1-1525+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1524+c0] + S[1524+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 474; c0 += 1)
    S[c0][c0+1525] = MAX(S[c0][c0+1525], S[c0+1][c0+1525-1] + can_pair(RNA, c0, c0+1525));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 473; c0 += 1)
    for (c1 = c0 + 1526; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1526+c0] + S[-c0+c1-1526+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1525+c0] + S[1525+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 473; c0 += 1)
    S[c0][c0+1526] = MAX(S[c0][c0+1526], S[c0+1][c0+1526-1] + can_pair(RNA, c0, c0+1526));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 472; c0 += 1)
    for (c1 = c0 + 1527; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1527+c0] + S[-c0+c1-1527+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1526+c0] + S[1526+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 472; c0 += 1)
    S[c0][c0+1527] = MAX(S[c0][c0+1527], S[c0+1][c0+1527-1] + can_pair(RNA, c0, c0+1527));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 471; c0 += 1)
    for (c1 = c0 + 1528; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1528+c0] + S[-c0+c1-1528+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1527+c0] + S[1527+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 471; c0 += 1)
    S[c0][c0+1528] = MAX(S[c0][c0+1528], S[c0+1][c0+1528-1] + can_pair(RNA, c0, c0+1528));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 470; c0 += 1)
    for (c1 = c0 + 1529; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1529+c0] + S[-c0+c1-1529+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1528+c0] + S[1528+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 470; c0 += 1)
    S[c0][c0+1529] = MAX(S[c0][c0+1529], S[c0+1][c0+1529-1] + can_pair(RNA, c0, c0+1529));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 469; c0 += 1)
    for (c1 = c0 + 1530; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1530+c0] + S[-c0+c1-1530+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1529+c0] + S[1529+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 469; c0 += 1)
    S[c0][c0+1530] = MAX(S[c0][c0+1530], S[c0+1][c0+1530-1] + can_pair(RNA, c0, c0+1530));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 468; c0 += 1)
    for (c1 = c0 + 1531; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1531+c0] + S[-c0+c1-1531+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1530+c0] + S[1530+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 468; c0 += 1)
    S[c0][c0+1531] = MAX(S[c0][c0+1531], S[c0+1][c0+1531-1] + can_pair(RNA, c0, c0+1531));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 467; c0 += 1)
    for (c1 = c0 + 1532; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1532+c0] + S[-c0+c1-1532+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1531+c0] + S[1531+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 467; c0 += 1)
    S[c0][c0+1532] = MAX(S[c0][c0+1532], S[c0+1][c0+1532-1] + can_pair(RNA, c0, c0+1532));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 466; c0 += 1)
    for (c1 = c0 + 1533; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1533+c0] + S[-c0+c1-1533+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1532+c0] + S[1532+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 466; c0 += 1)
    S[c0][c0+1533] = MAX(S[c0][c0+1533], S[c0+1][c0+1533-1] + can_pair(RNA, c0, c0+1533));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 465; c0 += 1)
    for (c1 = c0 + 1534; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1534+c0] + S[-c0+c1-1534+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1533+c0] + S[1533+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 465; c0 += 1)
    S[c0][c0+1534] = MAX(S[c0][c0+1534], S[c0+1][c0+1534-1] + can_pair(RNA, c0, c0+1534));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 464; c0 += 1)
    for (c1 = c0 + 1535; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1535+c0] + S[-c0+c1-1535+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1534+c0] + S[1534+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 464; c0 += 1)
    S[c0][c0+1535] = MAX(S[c0][c0+1535], S[c0+1][c0+1535-1] + can_pair(RNA, c0, c0+1535));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 463; c0 += 1)
    for (c1 = c0 + 1536; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1536+c0] + S[-c0+c1-1536+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1535+c0] + S[1535+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 463; c0 += 1)
    S[c0][c0+1536] = MAX(S[c0][c0+1536], S[c0+1][c0+1536-1] + can_pair(RNA, c0, c0+1536));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 462; c0 += 1)
    for (c1 = c0 + 1537; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1537+c0] + S[-c0+c1-1537+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1536+c0] + S[1536+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 462; c0 += 1)
    S[c0][c0+1537] = MAX(S[c0][c0+1537], S[c0+1][c0+1537-1] + can_pair(RNA, c0, c0+1537));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 461; c0 += 1)
    for (c1 = c0 + 1538; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1538+c0] + S[-c0+c1-1538+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1537+c0] + S[1537+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 461; c0 += 1)
    S[c0][c0+1538] = MAX(S[c0][c0+1538], S[c0+1][c0+1538-1] + can_pair(RNA, c0, c0+1538));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 460; c0 += 1)
    for (c1 = c0 + 1539; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1539+c0] + S[-c0+c1-1539+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1538+c0] + S[1538+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 460; c0 += 1)
    S[c0][c0+1539] = MAX(S[c0][c0+1539], S[c0+1][c0+1539-1] + can_pair(RNA, c0, c0+1539));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 459; c0 += 1)
    for (c1 = c0 + 1540; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1540+c0] + S[-c0+c1-1540+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1539+c0] + S[1539+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 459; c0 += 1)
    S[c0][c0+1540] = MAX(S[c0][c0+1540], S[c0+1][c0+1540-1] + can_pair(RNA, c0, c0+1540));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 458; c0 += 1)
    for (c1 = c0 + 1541; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1541+c0] + S[-c0+c1-1541+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1540+c0] + S[1540+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 458; c0 += 1)
    S[c0][c0+1541] = MAX(S[c0][c0+1541], S[c0+1][c0+1541-1] + can_pair(RNA, c0, c0+1541));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 457; c0 += 1)
    for (c1 = c0 + 1542; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1542+c0] + S[-c0+c1-1542+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1541+c0] + S[1541+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 457; c0 += 1)
    S[c0][c0+1542] = MAX(S[c0][c0+1542], S[c0+1][c0+1542-1] + can_pair(RNA, c0, c0+1542));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 456; c0 += 1)
    for (c1 = c0 + 1543; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1543+c0] + S[-c0+c1-1543+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1542+c0] + S[1542+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 456; c0 += 1)
    S[c0][c0+1543] = MAX(S[c0][c0+1543], S[c0+1][c0+1543-1] + can_pair(RNA, c0, c0+1543));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 455; c0 += 1)
    for (c1 = c0 + 1544; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1544+c0] + S[-c0+c1-1544+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1543+c0] + S[1543+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 455; c0 += 1)
    S[c0][c0+1544] = MAX(S[c0][c0+1544], S[c0+1][c0+1544-1] + can_pair(RNA, c0, c0+1544));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 454; c0 += 1)
    for (c1 = c0 + 1545; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1545+c0] + S[-c0+c1-1545+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1544+c0] + S[1544+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 454; c0 += 1)
    S[c0][c0+1545] = MAX(S[c0][c0+1545], S[c0+1][c0+1545-1] + can_pair(RNA, c0, c0+1545));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 453; c0 += 1)
    for (c1 = c0 + 1546; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1546+c0] + S[-c0+c1-1546+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1545+c0] + S[1545+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 453; c0 += 1)
    S[c0][c0+1546] = MAX(S[c0][c0+1546], S[c0+1][c0+1546-1] + can_pair(RNA, c0, c0+1546));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 452; c0 += 1)
    for (c1 = c0 + 1547; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1547+c0] + S[-c0+c1-1547+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1546+c0] + S[1546+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 452; c0 += 1)
    S[c0][c0+1547] = MAX(S[c0][c0+1547], S[c0+1][c0+1547-1] + can_pair(RNA, c0, c0+1547));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 451; c0 += 1)
    for (c1 = c0 + 1548; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1548+c0] + S[-c0+c1-1548+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1547+c0] + S[1547+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 451; c0 += 1)
    S[c0][c0+1548] = MAX(S[c0][c0+1548], S[c0+1][c0+1548-1] + can_pair(RNA, c0, c0+1548));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 450; c0 += 1)
    for (c1 = c0 + 1549; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1549+c0] + S[-c0+c1-1549+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1548+c0] + S[1548+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 450; c0 += 1)
    S[c0][c0+1549] = MAX(S[c0][c0+1549], S[c0+1][c0+1549-1] + can_pair(RNA, c0, c0+1549));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 449; c0 += 1)
    for (c1 = c0 + 1550; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1550+c0] + S[-c0+c1-1550+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1549+c0] + S[1549+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 449; c0 += 1)
    S[c0][c0+1550] = MAX(S[c0][c0+1550], S[c0+1][c0+1550-1] + can_pair(RNA, c0, c0+1550));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 448; c0 += 1)
    for (c1 = c0 + 1551; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1551+c0] + S[-c0+c1-1551+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1550+c0] + S[1550+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 448; c0 += 1)
    S[c0][c0+1551] = MAX(S[c0][c0+1551], S[c0+1][c0+1551-1] + can_pair(RNA, c0, c0+1551));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 447; c0 += 1)
    for (c1 = c0 + 1552; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1552+c0] + S[-c0+c1-1552+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1551+c0] + S[1551+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 447; c0 += 1)
    S[c0][c0+1552] = MAX(S[c0][c0+1552], S[c0+1][c0+1552-1] + can_pair(RNA, c0, c0+1552));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 446; c0 += 1)
    for (c1 = c0 + 1553; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1553+c0] + S[-c0+c1-1553+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1552+c0] + S[1552+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 446; c0 += 1)
    S[c0][c0+1553] = MAX(S[c0][c0+1553], S[c0+1][c0+1553-1] + can_pair(RNA, c0, c0+1553));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 445; c0 += 1)
    for (c1 = c0 + 1554; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1554+c0] + S[-c0+c1-1554+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1553+c0] + S[1553+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 445; c0 += 1)
    S[c0][c0+1554] = MAX(S[c0][c0+1554], S[c0+1][c0+1554-1] + can_pair(RNA, c0, c0+1554));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 444; c0 += 1)
    for (c1 = c0 + 1555; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1555+c0] + S[-c0+c1-1555+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1554+c0] + S[1554+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 444; c0 += 1)
    S[c0][c0+1555] = MAX(S[c0][c0+1555], S[c0+1][c0+1555-1] + can_pair(RNA, c0, c0+1555));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 443; c0 += 1)
    for (c1 = c0 + 1556; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1556+c0] + S[-c0+c1-1556+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1555+c0] + S[1555+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 443; c0 += 1)
    S[c0][c0+1556] = MAX(S[c0][c0+1556], S[c0+1][c0+1556-1] + can_pair(RNA, c0, c0+1556));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 442; c0 += 1)
    for (c1 = c0 + 1557; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1557+c0] + S[-c0+c1-1557+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1556+c0] + S[1556+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 442; c0 += 1)
    S[c0][c0+1557] = MAX(S[c0][c0+1557], S[c0+1][c0+1557-1] + can_pair(RNA, c0, c0+1557));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 441; c0 += 1)
    for (c1 = c0 + 1558; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1558+c0] + S[-c0+c1-1558+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1557+c0] + S[1557+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 441; c0 += 1)
    S[c0][c0+1558] = MAX(S[c0][c0+1558], S[c0+1][c0+1558-1] + can_pair(RNA, c0, c0+1558));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 440; c0 += 1)
    for (c1 = c0 + 1559; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1559+c0] + S[-c0+c1-1559+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1558+c0] + S[1558+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 440; c0 += 1)
    S[c0][c0+1559] = MAX(S[c0][c0+1559], S[c0+1][c0+1559-1] + can_pair(RNA, c0, c0+1559));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 439; c0 += 1)
    for (c1 = c0 + 1560; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1560+c0] + S[-c0+c1-1560+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1559+c0] + S[1559+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 439; c0 += 1)
    S[c0][c0+1560] = MAX(S[c0][c0+1560], S[c0+1][c0+1560-1] + can_pair(RNA, c0, c0+1560));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 438; c0 += 1)
    for (c1 = c0 + 1561; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1561+c0] + S[-c0+c1-1561+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1560+c0] + S[1560+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 438; c0 += 1)
    S[c0][c0+1561] = MAX(S[c0][c0+1561], S[c0+1][c0+1561-1] + can_pair(RNA, c0, c0+1561));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 437; c0 += 1)
    for (c1 = c0 + 1562; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1562+c0] + S[-c0+c1-1562+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1561+c0] + S[1561+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 437; c0 += 1)
    S[c0][c0+1562] = MAX(S[c0][c0+1562], S[c0+1][c0+1562-1] + can_pair(RNA, c0, c0+1562));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 436; c0 += 1)
    for (c1 = c0 + 1563; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1563+c0] + S[-c0+c1-1563+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1562+c0] + S[1562+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 436; c0 += 1)
    S[c0][c0+1563] = MAX(S[c0][c0+1563], S[c0+1][c0+1563-1] + can_pair(RNA, c0, c0+1563));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 435; c0 += 1)
    for (c1 = c0 + 1564; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1564+c0] + S[-c0+c1-1564+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1563+c0] + S[1563+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 435; c0 += 1)
    S[c0][c0+1564] = MAX(S[c0][c0+1564], S[c0+1][c0+1564-1] + can_pair(RNA, c0, c0+1564));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 434; c0 += 1)
    for (c1 = c0 + 1565; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1565+c0] + S[-c0+c1-1565+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1564+c0] + S[1564+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 434; c0 += 1)
    S[c0][c0+1565] = MAX(S[c0][c0+1565], S[c0+1][c0+1565-1] + can_pair(RNA, c0, c0+1565));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 433; c0 += 1)
    for (c1 = c0 + 1566; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1566+c0] + S[-c0+c1-1566+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1565+c0] + S[1565+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 433; c0 += 1)
    S[c0][c0+1566] = MAX(S[c0][c0+1566], S[c0+1][c0+1566-1] + can_pair(RNA, c0, c0+1566));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 432; c0 += 1)
    for (c1 = c0 + 1567; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1567+c0] + S[-c0+c1-1567+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1566+c0] + S[1566+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 432; c0 += 1)
    S[c0][c0+1567] = MAX(S[c0][c0+1567], S[c0+1][c0+1567-1] + can_pair(RNA, c0, c0+1567));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 431; c0 += 1)
    for (c1 = c0 + 1568; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1568+c0] + S[-c0+c1-1568+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1567+c0] + S[1567+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 431; c0 += 1)
    S[c0][c0+1568] = MAX(S[c0][c0+1568], S[c0+1][c0+1568-1] + can_pair(RNA, c0, c0+1568));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 430; c0 += 1)
    for (c1 = c0 + 1569; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1569+c0] + S[-c0+c1-1569+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1568+c0] + S[1568+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 430; c0 += 1)
    S[c0][c0+1569] = MAX(S[c0][c0+1569], S[c0+1][c0+1569-1] + can_pair(RNA, c0, c0+1569));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 429; c0 += 1)
    for (c1 = c0 + 1570; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1570+c0] + S[-c0+c1-1570+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1569+c0] + S[1569+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 429; c0 += 1)
    S[c0][c0+1570] = MAX(S[c0][c0+1570], S[c0+1][c0+1570-1] + can_pair(RNA, c0, c0+1570));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 428; c0 += 1)
    for (c1 = c0 + 1571; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1571+c0] + S[-c0+c1-1571+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1570+c0] + S[1570+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 428; c0 += 1)
    S[c0][c0+1571] = MAX(S[c0][c0+1571], S[c0+1][c0+1571-1] + can_pair(RNA, c0, c0+1571));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 427; c0 += 1)
    for (c1 = c0 + 1572; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1572+c0] + S[-c0+c1-1572+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1571+c0] + S[1571+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 427; c0 += 1)
    S[c0][c0+1572] = MAX(S[c0][c0+1572], S[c0+1][c0+1572-1] + can_pair(RNA, c0, c0+1572));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 426; c0 += 1)
    for (c1 = c0 + 1573; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1573+c0] + S[-c0+c1-1573+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1572+c0] + S[1572+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 426; c0 += 1)
    S[c0][c0+1573] = MAX(S[c0][c0+1573], S[c0+1][c0+1573-1] + can_pair(RNA, c0, c0+1573));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 425; c0 += 1)
    for (c1 = c0 + 1574; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1574+c0] + S[-c0+c1-1574+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1573+c0] + S[1573+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 425; c0 += 1)
    S[c0][c0+1574] = MAX(S[c0][c0+1574], S[c0+1][c0+1574-1] + can_pair(RNA, c0, c0+1574));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 424; c0 += 1)
    for (c1 = c0 + 1575; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1575+c0] + S[-c0+c1-1575+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1574+c0] + S[1574+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 424; c0 += 1)
    S[c0][c0+1575] = MAX(S[c0][c0+1575], S[c0+1][c0+1575-1] + can_pair(RNA, c0, c0+1575));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 423; c0 += 1)
    for (c1 = c0 + 1576; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1576+c0] + S[-c0+c1-1576+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1575+c0] + S[1575+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 423; c0 += 1)
    S[c0][c0+1576] = MAX(S[c0][c0+1576], S[c0+1][c0+1576-1] + can_pair(RNA, c0, c0+1576));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 422; c0 += 1)
    for (c1 = c0 + 1577; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1577+c0] + S[-c0+c1-1577+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1576+c0] + S[1576+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 422; c0 += 1)
    S[c0][c0+1577] = MAX(S[c0][c0+1577], S[c0+1][c0+1577-1] + can_pair(RNA, c0, c0+1577));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 421; c0 += 1)
    for (c1 = c0 + 1578; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1578+c0] + S[-c0+c1-1578+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1577+c0] + S[1577+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 421; c0 += 1)
    S[c0][c0+1578] = MAX(S[c0][c0+1578], S[c0+1][c0+1578-1] + can_pair(RNA, c0, c0+1578));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 420; c0 += 1)
    for (c1 = c0 + 1579; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1579+c0] + S[-c0+c1-1579+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1578+c0] + S[1578+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 420; c0 += 1)
    S[c0][c0+1579] = MAX(S[c0][c0+1579], S[c0+1][c0+1579-1] + can_pair(RNA, c0, c0+1579));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 419; c0 += 1)
    for (c1 = c0 + 1580; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1580+c0] + S[-c0+c1-1580+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1579+c0] + S[1579+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 419; c0 += 1)
    S[c0][c0+1580] = MAX(S[c0][c0+1580], S[c0+1][c0+1580-1] + can_pair(RNA, c0, c0+1580));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 418; c0 += 1)
    for (c1 = c0 + 1581; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1581+c0] + S[-c0+c1-1581+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1580+c0] + S[1580+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 418; c0 += 1)
    S[c0][c0+1581] = MAX(S[c0][c0+1581], S[c0+1][c0+1581-1] + can_pair(RNA, c0, c0+1581));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 417; c0 += 1)
    for (c1 = c0 + 1582; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1582+c0] + S[-c0+c1-1582+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1581+c0] + S[1581+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 417; c0 += 1)
    S[c0][c0+1582] = MAX(S[c0][c0+1582], S[c0+1][c0+1582-1] + can_pair(RNA, c0, c0+1582));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 416; c0 += 1)
    for (c1 = c0 + 1583; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1583+c0] + S[-c0+c1-1583+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1582+c0] + S[1582+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 416; c0 += 1)
    S[c0][c0+1583] = MAX(S[c0][c0+1583], S[c0+1][c0+1583-1] + can_pair(RNA, c0, c0+1583));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 415; c0 += 1)
    for (c1 = c0 + 1584; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1584+c0] + S[-c0+c1-1584+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1583+c0] + S[1583+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 415; c0 += 1)
    S[c0][c0+1584] = MAX(S[c0][c0+1584], S[c0+1][c0+1584-1] + can_pair(RNA, c0, c0+1584));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 414; c0 += 1)
    for (c1 = c0 + 1585; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1585+c0] + S[-c0+c1-1585+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1584+c0] + S[1584+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 414; c0 += 1)
    S[c0][c0+1585] = MAX(S[c0][c0+1585], S[c0+1][c0+1585-1] + can_pair(RNA, c0, c0+1585));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 413; c0 += 1)
    for (c1 = c0 + 1586; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1586+c0] + S[-c0+c1-1586+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1585+c0] + S[1585+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 413; c0 += 1)
    S[c0][c0+1586] = MAX(S[c0][c0+1586], S[c0+1][c0+1586-1] + can_pair(RNA, c0, c0+1586));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 412; c0 += 1)
    for (c1 = c0 + 1587; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1587+c0] + S[-c0+c1-1587+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1586+c0] + S[1586+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 412; c0 += 1)
    S[c0][c0+1587] = MAX(S[c0][c0+1587], S[c0+1][c0+1587-1] + can_pair(RNA, c0, c0+1587));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 411; c0 += 1)
    for (c1 = c0 + 1588; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1588+c0] + S[-c0+c1-1588+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1587+c0] + S[1587+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 411; c0 += 1)
    S[c0][c0+1588] = MAX(S[c0][c0+1588], S[c0+1][c0+1588-1] + can_pair(RNA, c0, c0+1588));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 410; c0 += 1)
    for (c1 = c0 + 1589; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1589+c0] + S[-c0+c1-1589+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1588+c0] + S[1588+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 410; c0 += 1)
    S[c0][c0+1589] = MAX(S[c0][c0+1589], S[c0+1][c0+1589-1] + can_pair(RNA, c0, c0+1589));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 409; c0 += 1)
    for (c1 = c0 + 1590; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1590+c0] + S[-c0+c1-1590+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1589+c0] + S[1589+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 409; c0 += 1)
    S[c0][c0+1590] = MAX(S[c0][c0+1590], S[c0+1][c0+1590-1] + can_pair(RNA, c0, c0+1590));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 408; c0 += 1)
    for (c1 = c0 + 1591; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1591+c0] + S[-c0+c1-1591+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1590+c0] + S[1590+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 408; c0 += 1)
    S[c0][c0+1591] = MAX(S[c0][c0+1591], S[c0+1][c0+1591-1] + can_pair(RNA, c0, c0+1591));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 407; c0 += 1)
    for (c1 = c0 + 1592; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1592+c0] + S[-c0+c1-1592+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1591+c0] + S[1591+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 407; c0 += 1)
    S[c0][c0+1592] = MAX(S[c0][c0+1592], S[c0+1][c0+1592-1] + can_pair(RNA, c0, c0+1592));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 406; c0 += 1)
    for (c1 = c0 + 1593; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1593+c0] + S[-c0+c1-1593+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1592+c0] + S[1592+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 406; c0 += 1)
    S[c0][c0+1593] = MAX(S[c0][c0+1593], S[c0+1][c0+1593-1] + can_pair(RNA, c0, c0+1593));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 405; c0 += 1)
    for (c1 = c0 + 1594; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1594+c0] + S[-c0+c1-1594+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1593+c0] + S[1593+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 405; c0 += 1)
    S[c0][c0+1594] = MAX(S[c0][c0+1594], S[c0+1][c0+1594-1] + can_pair(RNA, c0, c0+1594));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 404; c0 += 1)
    for (c1 = c0 + 1595; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1595+c0] + S[-c0+c1-1595+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1594+c0] + S[1594+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 404; c0 += 1)
    S[c0][c0+1595] = MAX(S[c0][c0+1595], S[c0+1][c0+1595-1] + can_pair(RNA, c0, c0+1595));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 403; c0 += 1)
    for (c1 = c0 + 1596; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1596+c0] + S[-c0+c1-1596+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1595+c0] + S[1595+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 403; c0 += 1)
    S[c0][c0+1596] = MAX(S[c0][c0+1596], S[c0+1][c0+1596-1] + can_pair(RNA, c0, c0+1596));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 402; c0 += 1)
    for (c1 = c0 + 1597; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1597+c0] + S[-c0+c1-1597+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1596+c0] + S[1596+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 402; c0 += 1)
    S[c0][c0+1597] = MAX(S[c0][c0+1597], S[c0+1][c0+1597-1] + can_pair(RNA, c0, c0+1597));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 401; c0 += 1)
    for (c1 = c0 + 1598; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1598+c0] + S[-c0+c1-1598+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1597+c0] + S[1597+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 401; c0 += 1)
    S[c0][c0+1598] = MAX(S[c0][c0+1598], S[c0+1][c0+1598-1] + can_pair(RNA, c0, c0+1598));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 400; c0 += 1)
    for (c1 = c0 + 1599; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1599+c0] + S[-c0+c1-1599+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1598+c0] + S[1598+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 400; c0 += 1)
    S[c0][c0+1599] = MAX(S[c0][c0+1599], S[c0+1][c0+1599-1] + can_pair(RNA, c0, c0+1599));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 399; c0 += 1)
    for (c1 = c0 + 1600; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1600+c0] + S[-c0+c1-1600+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1599+c0] + S[1599+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 399; c0 += 1)
    S[c0][c0+1600] = MAX(S[c0][c0+1600], S[c0+1][c0+1600-1] + can_pair(RNA, c0, c0+1600));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 398; c0 += 1)
    for (c1 = c0 + 1601; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1601+c0] + S[-c0+c1-1601+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1600+c0] + S[1600+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 398; c0 += 1)
    S[c0][c0+1601] = MAX(S[c0][c0+1601], S[c0+1][c0+1601-1] + can_pair(RNA, c0, c0+1601));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 397; c0 += 1)
    for (c1 = c0 + 1602; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1602+c0] + S[-c0+c1-1602+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1601+c0] + S[1601+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 397; c0 += 1)
    S[c0][c0+1602] = MAX(S[c0][c0+1602], S[c0+1][c0+1602-1] + can_pair(RNA, c0, c0+1602));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 396; c0 += 1)
    for (c1 = c0 + 1603; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1603+c0] + S[-c0+c1-1603+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1602+c0] + S[1602+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 396; c0 += 1)
    S[c0][c0+1603] = MAX(S[c0][c0+1603], S[c0+1][c0+1603-1] + can_pair(RNA, c0, c0+1603));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 395; c0 += 1)
    for (c1 = c0 + 1604; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1604+c0] + S[-c0+c1-1604+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1603+c0] + S[1603+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 395; c0 += 1)
    S[c0][c0+1604] = MAX(S[c0][c0+1604], S[c0+1][c0+1604-1] + can_pair(RNA, c0, c0+1604));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 394; c0 += 1)
    for (c1 = c0 + 1605; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1605+c0] + S[-c0+c1-1605+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1604+c0] + S[1604+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 394; c0 += 1)
    S[c0][c0+1605] = MAX(S[c0][c0+1605], S[c0+1][c0+1605-1] + can_pair(RNA, c0, c0+1605));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 393; c0 += 1)
    for (c1 = c0 + 1606; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1606+c0] + S[-c0+c1-1606+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1605+c0] + S[1605+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 393; c0 += 1)
    S[c0][c0+1606] = MAX(S[c0][c0+1606], S[c0+1][c0+1606-1] + can_pair(RNA, c0, c0+1606));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 392; c0 += 1)
    for (c1 = c0 + 1607; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1607+c0] + S[-c0+c1-1607+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1606+c0] + S[1606+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 392; c0 += 1)
    S[c0][c0+1607] = MAX(S[c0][c0+1607], S[c0+1][c0+1607-1] + can_pair(RNA, c0, c0+1607));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 391; c0 += 1)
    for (c1 = c0 + 1608; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1608+c0] + S[-c0+c1-1608+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1607+c0] + S[1607+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 391; c0 += 1)
    S[c0][c0+1608] = MAX(S[c0][c0+1608], S[c0+1][c0+1608-1] + can_pair(RNA, c0, c0+1608));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 390; c0 += 1)
    for (c1 = c0 + 1609; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1609+c0] + S[-c0+c1-1609+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1608+c0] + S[1608+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 390; c0 += 1)
    S[c0][c0+1609] = MAX(S[c0][c0+1609], S[c0+1][c0+1609-1] + can_pair(RNA, c0, c0+1609));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 389; c0 += 1)
    for (c1 = c0 + 1610; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1610+c0] + S[-c0+c1-1610+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1609+c0] + S[1609+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 389; c0 += 1)
    S[c0][c0+1610] = MAX(S[c0][c0+1610], S[c0+1][c0+1610-1] + can_pair(RNA, c0, c0+1610));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 388; c0 += 1)
    for (c1 = c0 + 1611; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1611+c0] + S[-c0+c1-1611+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1610+c0] + S[1610+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 388; c0 += 1)
    S[c0][c0+1611] = MAX(S[c0][c0+1611], S[c0+1][c0+1611-1] + can_pair(RNA, c0, c0+1611));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 387; c0 += 1)
    for (c1 = c0 + 1612; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1612+c0] + S[-c0+c1-1612+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1611+c0] + S[1611+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 387; c0 += 1)
    S[c0][c0+1612] = MAX(S[c0][c0+1612], S[c0+1][c0+1612-1] + can_pair(RNA, c0, c0+1612));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 386; c0 += 1)
    for (c1 = c0 + 1613; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1613+c0] + S[-c0+c1-1613+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1612+c0] + S[1612+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 386; c0 += 1)
    S[c0][c0+1613] = MAX(S[c0][c0+1613], S[c0+1][c0+1613-1] + can_pair(RNA, c0, c0+1613));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 385; c0 += 1)
    for (c1 = c0 + 1614; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1614+c0] + S[-c0+c1-1614+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1613+c0] + S[1613+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 385; c0 += 1)
    S[c0][c0+1614] = MAX(S[c0][c0+1614], S[c0+1][c0+1614-1] + can_pair(RNA, c0, c0+1614));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 384; c0 += 1)
    for (c1 = c0 + 1615; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1615+c0] + S[-c0+c1-1615+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1614+c0] + S[1614+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 384; c0 += 1)
    S[c0][c0+1615] = MAX(S[c0][c0+1615], S[c0+1][c0+1615-1] + can_pair(RNA, c0, c0+1615));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 383; c0 += 1)
    for (c1 = c0 + 1616; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1616+c0] + S[-c0+c1-1616+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1615+c0] + S[1615+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 383; c0 += 1)
    S[c0][c0+1616] = MAX(S[c0][c0+1616], S[c0+1][c0+1616-1] + can_pair(RNA, c0, c0+1616));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 382; c0 += 1)
    for (c1 = c0 + 1617; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1617+c0] + S[-c0+c1-1617+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1616+c0] + S[1616+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 382; c0 += 1)
    S[c0][c0+1617] = MAX(S[c0][c0+1617], S[c0+1][c0+1617-1] + can_pair(RNA, c0, c0+1617));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 381; c0 += 1)
    for (c1 = c0 + 1618; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1618+c0] + S[-c0+c1-1618+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1617+c0] + S[1617+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 381; c0 += 1)
    S[c0][c0+1618] = MAX(S[c0][c0+1618], S[c0+1][c0+1618-1] + can_pair(RNA, c0, c0+1618));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 380; c0 += 1)
    for (c1 = c0 + 1619; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1619+c0] + S[-c0+c1-1619+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1618+c0] + S[1618+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 380; c0 += 1)
    S[c0][c0+1619] = MAX(S[c0][c0+1619], S[c0+1][c0+1619-1] + can_pair(RNA, c0, c0+1619));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 379; c0 += 1)
    for (c1 = c0 + 1620; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1620+c0] + S[-c0+c1-1620+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1619+c0] + S[1619+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 379; c0 += 1)
    S[c0][c0+1620] = MAX(S[c0][c0+1620], S[c0+1][c0+1620-1] + can_pair(RNA, c0, c0+1620));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 378; c0 += 1)
    for (c1 = c0 + 1621; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1621+c0] + S[-c0+c1-1621+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1620+c0] + S[1620+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 378; c0 += 1)
    S[c0][c0+1621] = MAX(S[c0][c0+1621], S[c0+1][c0+1621-1] + can_pair(RNA, c0, c0+1621));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 377; c0 += 1)
    for (c1 = c0 + 1622; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1622+c0] + S[-c0+c1-1622+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1621+c0] + S[1621+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 377; c0 += 1)
    S[c0][c0+1622] = MAX(S[c0][c0+1622], S[c0+1][c0+1622-1] + can_pair(RNA, c0, c0+1622));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 376; c0 += 1)
    for (c1 = c0 + 1623; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1623+c0] + S[-c0+c1-1623+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1622+c0] + S[1622+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 376; c0 += 1)
    S[c0][c0+1623] = MAX(S[c0][c0+1623], S[c0+1][c0+1623-1] + can_pair(RNA, c0, c0+1623));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 375; c0 += 1)
    for (c1 = c0 + 1624; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1624+c0] + S[-c0+c1-1624+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1623+c0] + S[1623+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 375; c0 += 1)
    S[c0][c0+1624] = MAX(S[c0][c0+1624], S[c0+1][c0+1624-1] + can_pair(RNA, c0, c0+1624));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 374; c0 += 1)
    for (c1 = c0 + 1625; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1625+c0] + S[-c0+c1-1625+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1624+c0] + S[1624+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 374; c0 += 1)
    S[c0][c0+1625] = MAX(S[c0][c0+1625], S[c0+1][c0+1625-1] + can_pair(RNA, c0, c0+1625));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 373; c0 += 1)
    for (c1 = c0 + 1626; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1626+c0] + S[-c0+c1-1626+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1625+c0] + S[1625+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 373; c0 += 1)
    S[c0][c0+1626] = MAX(S[c0][c0+1626], S[c0+1][c0+1626-1] + can_pair(RNA, c0, c0+1626));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 372; c0 += 1)
    for (c1 = c0 + 1627; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1627+c0] + S[-c0+c1-1627+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1626+c0] + S[1626+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 372; c0 += 1)
    S[c0][c0+1627] = MAX(S[c0][c0+1627], S[c0+1][c0+1627-1] + can_pair(RNA, c0, c0+1627));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 371; c0 += 1)
    for (c1 = c0 + 1628; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1628+c0] + S[-c0+c1-1628+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1627+c0] + S[1627+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 371; c0 += 1)
    S[c0][c0+1628] = MAX(S[c0][c0+1628], S[c0+1][c0+1628-1] + can_pair(RNA, c0, c0+1628));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 370; c0 += 1)
    for (c1 = c0 + 1629; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1629+c0] + S[-c0+c1-1629+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1628+c0] + S[1628+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 370; c0 += 1)
    S[c0][c0+1629] = MAX(S[c0][c0+1629], S[c0+1][c0+1629-1] + can_pair(RNA, c0, c0+1629));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 369; c0 += 1)
    for (c1 = c0 + 1630; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1630+c0] + S[-c0+c1-1630+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1629+c0] + S[1629+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 369; c0 += 1)
    S[c0][c0+1630] = MAX(S[c0][c0+1630], S[c0+1][c0+1630-1] + can_pair(RNA, c0, c0+1630));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 368; c0 += 1)
    for (c1 = c0 + 1631; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1631+c0] + S[-c0+c1-1631+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1630+c0] + S[1630+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 368; c0 += 1)
    S[c0][c0+1631] = MAX(S[c0][c0+1631], S[c0+1][c0+1631-1] + can_pair(RNA, c0, c0+1631));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 367; c0 += 1)
    for (c1 = c0 + 1632; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1632+c0] + S[-c0+c1-1632+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1631+c0] + S[1631+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 367; c0 += 1)
    S[c0][c0+1632] = MAX(S[c0][c0+1632], S[c0+1][c0+1632-1] + can_pair(RNA, c0, c0+1632));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 366; c0 += 1)
    for (c1 = c0 + 1633; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1633+c0] + S[-c0+c1-1633+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1632+c0] + S[1632+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 366; c0 += 1)
    S[c0][c0+1633] = MAX(S[c0][c0+1633], S[c0+1][c0+1633-1] + can_pair(RNA, c0, c0+1633));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 365; c0 += 1)
    for (c1 = c0 + 1634; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1634+c0] + S[-c0+c1-1634+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1633+c0] + S[1633+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 365; c0 += 1)
    S[c0][c0+1634] = MAX(S[c0][c0+1634], S[c0+1][c0+1634-1] + can_pair(RNA, c0, c0+1634));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 364; c0 += 1)
    for (c1 = c0 + 1635; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1635+c0] + S[-c0+c1-1635+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1634+c0] + S[1634+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 364; c0 += 1)
    S[c0][c0+1635] = MAX(S[c0][c0+1635], S[c0+1][c0+1635-1] + can_pair(RNA, c0, c0+1635));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 363; c0 += 1)
    for (c1 = c0 + 1636; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1636+c0] + S[-c0+c1-1636+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1635+c0] + S[1635+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 363; c0 += 1)
    S[c0][c0+1636] = MAX(S[c0][c0+1636], S[c0+1][c0+1636-1] + can_pair(RNA, c0, c0+1636));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 362; c0 += 1)
    for (c1 = c0 + 1637; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1637+c0] + S[-c0+c1-1637+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1636+c0] + S[1636+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 362; c0 += 1)
    S[c0][c0+1637] = MAX(S[c0][c0+1637], S[c0+1][c0+1637-1] + can_pair(RNA, c0, c0+1637));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 361; c0 += 1)
    for (c1 = c0 + 1638; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1638+c0] + S[-c0+c1-1638+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1637+c0] + S[1637+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 361; c0 += 1)
    S[c0][c0+1638] = MAX(S[c0][c0+1638], S[c0+1][c0+1638-1] + can_pair(RNA, c0, c0+1638));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 360; c0 += 1)
    for (c1 = c0 + 1639; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1639+c0] + S[-c0+c1-1639+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1638+c0] + S[1638+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 360; c0 += 1)
    S[c0][c0+1639] = MAX(S[c0][c0+1639], S[c0+1][c0+1639-1] + can_pair(RNA, c0, c0+1639));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 359; c0 += 1)
    for (c1 = c0 + 1640; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1640+c0] + S[-c0+c1-1640+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1639+c0] + S[1639+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 359; c0 += 1)
    S[c0][c0+1640] = MAX(S[c0][c0+1640], S[c0+1][c0+1640-1] + can_pair(RNA, c0, c0+1640));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 358; c0 += 1)
    for (c1 = c0 + 1641; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1641+c0] + S[-c0+c1-1641+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1640+c0] + S[1640+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 358; c0 += 1)
    S[c0][c0+1641] = MAX(S[c0][c0+1641], S[c0+1][c0+1641-1] + can_pair(RNA, c0, c0+1641));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 357; c0 += 1)
    for (c1 = c0 + 1642; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1642+c0] + S[-c0+c1-1642+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1641+c0] + S[1641+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 357; c0 += 1)
    S[c0][c0+1642] = MAX(S[c0][c0+1642], S[c0+1][c0+1642-1] + can_pair(RNA, c0, c0+1642));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 356; c0 += 1)
    for (c1 = c0 + 1643; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1643+c0] + S[-c0+c1-1643+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1642+c0] + S[1642+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 356; c0 += 1)
    S[c0][c0+1643] = MAX(S[c0][c0+1643], S[c0+1][c0+1643-1] + can_pair(RNA, c0, c0+1643));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 355; c0 += 1)
    for (c1 = c0 + 1644; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1644+c0] + S[-c0+c1-1644+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1643+c0] + S[1643+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 355; c0 += 1)
    S[c0][c0+1644] = MAX(S[c0][c0+1644], S[c0+1][c0+1644-1] + can_pair(RNA, c0, c0+1644));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 354; c0 += 1)
    for (c1 = c0 + 1645; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1645+c0] + S[-c0+c1-1645+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1644+c0] + S[1644+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 354; c0 += 1)
    S[c0][c0+1645] = MAX(S[c0][c0+1645], S[c0+1][c0+1645-1] + can_pair(RNA, c0, c0+1645));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 353; c0 += 1)
    for (c1 = c0 + 1646; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1646+c0] + S[-c0+c1-1646+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1645+c0] + S[1645+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 353; c0 += 1)
    S[c0][c0+1646] = MAX(S[c0][c0+1646], S[c0+1][c0+1646-1] + can_pair(RNA, c0, c0+1646));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 352; c0 += 1)
    for (c1 = c0 + 1647; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1647+c0] + S[-c0+c1-1647+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1646+c0] + S[1646+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 352; c0 += 1)
    S[c0][c0+1647] = MAX(S[c0][c0+1647], S[c0+1][c0+1647-1] + can_pair(RNA, c0, c0+1647));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 351; c0 += 1)
    for (c1 = c0 + 1648; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1648+c0] + S[-c0+c1-1648+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1647+c0] + S[1647+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 351; c0 += 1)
    S[c0][c0+1648] = MAX(S[c0][c0+1648], S[c0+1][c0+1648-1] + can_pair(RNA, c0, c0+1648));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 350; c0 += 1)
    for (c1 = c0 + 1649; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1649+c0] + S[-c0+c1-1649+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1648+c0] + S[1648+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 350; c0 += 1)
    S[c0][c0+1649] = MAX(S[c0][c0+1649], S[c0+1][c0+1649-1] + can_pair(RNA, c0, c0+1649));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 349; c0 += 1)
    for (c1 = c0 + 1650; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1650+c0] + S[-c0+c1-1650+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1649+c0] + S[1649+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 349; c0 += 1)
    S[c0][c0+1650] = MAX(S[c0][c0+1650], S[c0+1][c0+1650-1] + can_pair(RNA, c0, c0+1650));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 348; c0 += 1)
    for (c1 = c0 + 1651; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1651+c0] + S[-c0+c1-1651+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1650+c0] + S[1650+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 348; c0 += 1)
    S[c0][c0+1651] = MAX(S[c0][c0+1651], S[c0+1][c0+1651-1] + can_pair(RNA, c0, c0+1651));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 347; c0 += 1)
    for (c1 = c0 + 1652; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1652+c0] + S[-c0+c1-1652+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1651+c0] + S[1651+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 347; c0 += 1)
    S[c0][c0+1652] = MAX(S[c0][c0+1652], S[c0+1][c0+1652-1] + can_pair(RNA, c0, c0+1652));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 346; c0 += 1)
    for (c1 = c0 + 1653; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1653+c0] + S[-c0+c1-1653+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1652+c0] + S[1652+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 346; c0 += 1)
    S[c0][c0+1653] = MAX(S[c0][c0+1653], S[c0+1][c0+1653-1] + can_pair(RNA, c0, c0+1653));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 345; c0 += 1)
    for (c1 = c0 + 1654; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1654+c0] + S[-c0+c1-1654+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1653+c0] + S[1653+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 345; c0 += 1)
    S[c0][c0+1654] = MAX(S[c0][c0+1654], S[c0+1][c0+1654-1] + can_pair(RNA, c0, c0+1654));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 344; c0 += 1)
    for (c1 = c0 + 1655; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1655+c0] + S[-c0+c1-1655+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1654+c0] + S[1654+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 344; c0 += 1)
    S[c0][c0+1655] = MAX(S[c0][c0+1655], S[c0+1][c0+1655-1] + can_pair(RNA, c0, c0+1655));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 343; c0 += 1)
    for (c1 = c0 + 1656; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1656+c0] + S[-c0+c1-1656+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1655+c0] + S[1655+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 343; c0 += 1)
    S[c0][c0+1656] = MAX(S[c0][c0+1656], S[c0+1][c0+1656-1] + can_pair(RNA, c0, c0+1656));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 342; c0 += 1)
    for (c1 = c0 + 1657; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1657+c0] + S[-c0+c1-1657+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1656+c0] + S[1656+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 342; c0 += 1)
    S[c0][c0+1657] = MAX(S[c0][c0+1657], S[c0+1][c0+1657-1] + can_pair(RNA, c0, c0+1657));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 341; c0 += 1)
    for (c1 = c0 + 1658; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1658+c0] + S[-c0+c1-1658+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1657+c0] + S[1657+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 341; c0 += 1)
    S[c0][c0+1658] = MAX(S[c0][c0+1658], S[c0+1][c0+1658-1] + can_pair(RNA, c0, c0+1658));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 340; c0 += 1)
    for (c1 = c0 + 1659; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1659+c0] + S[-c0+c1-1659+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1658+c0] + S[1658+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 340; c0 += 1)
    S[c0][c0+1659] = MAX(S[c0][c0+1659], S[c0+1][c0+1659-1] + can_pair(RNA, c0, c0+1659));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 339; c0 += 1)
    for (c1 = c0 + 1660; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1660+c0] + S[-c0+c1-1660+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1659+c0] + S[1659+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 339; c0 += 1)
    S[c0][c0+1660] = MAX(S[c0][c0+1660], S[c0+1][c0+1660-1] + can_pair(RNA, c0, c0+1660));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 338; c0 += 1)
    for (c1 = c0 + 1661; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1661+c0] + S[-c0+c1-1661+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1660+c0] + S[1660+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 338; c0 += 1)
    S[c0][c0+1661] = MAX(S[c0][c0+1661], S[c0+1][c0+1661-1] + can_pair(RNA, c0, c0+1661));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 337; c0 += 1)
    for (c1 = c0 + 1662; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1662+c0] + S[-c0+c1-1662+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1661+c0] + S[1661+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 337; c0 += 1)
    S[c0][c0+1662] = MAX(S[c0][c0+1662], S[c0+1][c0+1662-1] + can_pair(RNA, c0, c0+1662));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 336; c0 += 1)
    for (c1 = c0 + 1663; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1663+c0] + S[-c0+c1-1663+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1662+c0] + S[1662+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 336; c0 += 1)
    S[c0][c0+1663] = MAX(S[c0][c0+1663], S[c0+1][c0+1663-1] + can_pair(RNA, c0, c0+1663));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 335; c0 += 1)
    for (c1 = c0 + 1664; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1664+c0] + S[-c0+c1-1664+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1663+c0] + S[1663+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 335; c0 += 1)
    S[c0][c0+1664] = MAX(S[c0][c0+1664], S[c0+1][c0+1664-1] + can_pair(RNA, c0, c0+1664));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 334; c0 += 1)
    for (c1 = c0 + 1665; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1665+c0] + S[-c0+c1-1665+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1664+c0] + S[1664+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 334; c0 += 1)
    S[c0][c0+1665] = MAX(S[c0][c0+1665], S[c0+1][c0+1665-1] + can_pair(RNA, c0, c0+1665));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 333; c0 += 1)
    for (c1 = c0 + 1666; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1666+c0] + S[-c0+c1-1666+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1665+c0] + S[1665+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 333; c0 += 1)
    S[c0][c0+1666] = MAX(S[c0][c0+1666], S[c0+1][c0+1666-1] + can_pair(RNA, c0, c0+1666));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 332; c0 += 1)
    for (c1 = c0 + 1667; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1667+c0] + S[-c0+c1-1667+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1666+c0] + S[1666+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 332; c0 += 1)
    S[c0][c0+1667] = MAX(S[c0][c0+1667], S[c0+1][c0+1667-1] + can_pair(RNA, c0, c0+1667));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 331; c0 += 1)
    for (c1 = c0 + 1668; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1668+c0] + S[-c0+c1-1668+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1667+c0] + S[1667+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 331; c0 += 1)
    S[c0][c0+1668] = MAX(S[c0][c0+1668], S[c0+1][c0+1668-1] + can_pair(RNA, c0, c0+1668));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 330; c0 += 1)
    for (c1 = c0 + 1669; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1669+c0] + S[-c0+c1-1669+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1668+c0] + S[1668+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 330; c0 += 1)
    S[c0][c0+1669] = MAX(S[c0][c0+1669], S[c0+1][c0+1669-1] + can_pair(RNA, c0, c0+1669));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 329; c0 += 1)
    for (c1 = c0 + 1670; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1670+c0] + S[-c0+c1-1670+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1669+c0] + S[1669+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 329; c0 += 1)
    S[c0][c0+1670] = MAX(S[c0][c0+1670], S[c0+1][c0+1670-1] + can_pair(RNA, c0, c0+1670));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 328; c0 += 1)
    for (c1 = c0 + 1671; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1671+c0] + S[-c0+c1-1671+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1670+c0] + S[1670+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 328; c0 += 1)
    S[c0][c0+1671] = MAX(S[c0][c0+1671], S[c0+1][c0+1671-1] + can_pair(RNA, c0, c0+1671));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 327; c0 += 1)
    for (c1 = c0 + 1672; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1672+c0] + S[-c0+c1-1672+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1671+c0] + S[1671+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 327; c0 += 1)
    S[c0][c0+1672] = MAX(S[c0][c0+1672], S[c0+1][c0+1672-1] + can_pair(RNA, c0, c0+1672));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 326; c0 += 1)
    for (c1 = c0 + 1673; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1673+c0] + S[-c0+c1-1673+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1672+c0] + S[1672+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 326; c0 += 1)
    S[c0][c0+1673] = MAX(S[c0][c0+1673], S[c0+1][c0+1673-1] + can_pair(RNA, c0, c0+1673));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 325; c0 += 1)
    for (c1 = c0 + 1674; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1674+c0] + S[-c0+c1-1674+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1673+c0] + S[1673+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 325; c0 += 1)
    S[c0][c0+1674] = MAX(S[c0][c0+1674], S[c0+1][c0+1674-1] + can_pair(RNA, c0, c0+1674));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 324; c0 += 1)
    for (c1 = c0 + 1675; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1675+c0] + S[-c0+c1-1675+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1674+c0] + S[1674+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 324; c0 += 1)
    S[c0][c0+1675] = MAX(S[c0][c0+1675], S[c0+1][c0+1675-1] + can_pair(RNA, c0, c0+1675));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 323; c0 += 1)
    for (c1 = c0 + 1676; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1676+c0] + S[-c0+c1-1676+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1675+c0] + S[1675+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 323; c0 += 1)
    S[c0][c0+1676] = MAX(S[c0][c0+1676], S[c0+1][c0+1676-1] + can_pair(RNA, c0, c0+1676));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 322; c0 += 1)
    for (c1 = c0 + 1677; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1677+c0] + S[-c0+c1-1677+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1676+c0] + S[1676+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 322; c0 += 1)
    S[c0][c0+1677] = MAX(S[c0][c0+1677], S[c0+1][c0+1677-1] + can_pair(RNA, c0, c0+1677));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 321; c0 += 1)
    for (c1 = c0 + 1678; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1678+c0] + S[-c0+c1-1678+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1677+c0] + S[1677+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 321; c0 += 1)
    S[c0][c0+1678] = MAX(S[c0][c0+1678], S[c0+1][c0+1678-1] + can_pair(RNA, c0, c0+1678));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 320; c0 += 1)
    for (c1 = c0 + 1679; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1679+c0] + S[-c0+c1-1679+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1678+c0] + S[1678+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 320; c0 += 1)
    S[c0][c0+1679] = MAX(S[c0][c0+1679], S[c0+1][c0+1679-1] + can_pair(RNA, c0, c0+1679));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 319; c0 += 1)
    for (c1 = c0 + 1680; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1680+c0] + S[-c0+c1-1680+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1679+c0] + S[1679+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 319; c0 += 1)
    S[c0][c0+1680] = MAX(S[c0][c0+1680], S[c0+1][c0+1680-1] + can_pair(RNA, c0, c0+1680));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 318; c0 += 1)
    for (c1 = c0 + 1681; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1681+c0] + S[-c0+c1-1681+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1680+c0] + S[1680+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 318; c0 += 1)
    S[c0][c0+1681] = MAX(S[c0][c0+1681], S[c0+1][c0+1681-1] + can_pair(RNA, c0, c0+1681));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 317; c0 += 1)
    for (c1 = c0 + 1682; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1682+c0] + S[-c0+c1-1682+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1681+c0] + S[1681+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 317; c0 += 1)
    S[c0][c0+1682] = MAX(S[c0][c0+1682], S[c0+1][c0+1682-1] + can_pair(RNA, c0, c0+1682));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 316; c0 += 1)
    for (c1 = c0 + 1683; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1683+c0] + S[-c0+c1-1683+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1682+c0] + S[1682+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 316; c0 += 1)
    S[c0][c0+1683] = MAX(S[c0][c0+1683], S[c0+1][c0+1683-1] + can_pair(RNA, c0, c0+1683));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 315; c0 += 1)
    for (c1 = c0 + 1684; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1684+c0] + S[-c0+c1-1684+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1683+c0] + S[1683+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 315; c0 += 1)
    S[c0][c0+1684] = MAX(S[c0][c0+1684], S[c0+1][c0+1684-1] + can_pair(RNA, c0, c0+1684));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 314; c0 += 1)
    for (c1 = c0 + 1685; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1685+c0] + S[-c0+c1-1685+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1684+c0] + S[1684+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 314; c0 += 1)
    S[c0][c0+1685] = MAX(S[c0][c0+1685], S[c0+1][c0+1685-1] + can_pair(RNA, c0, c0+1685));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 313; c0 += 1)
    for (c1 = c0 + 1686; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1686+c0] + S[-c0+c1-1686+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1685+c0] + S[1685+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 313; c0 += 1)
    S[c0][c0+1686] = MAX(S[c0][c0+1686], S[c0+1][c0+1686-1] + can_pair(RNA, c0, c0+1686));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 312; c0 += 1)
    for (c1 = c0 + 1687; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1687+c0] + S[-c0+c1-1687+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1686+c0] + S[1686+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 312; c0 += 1)
    S[c0][c0+1687] = MAX(S[c0][c0+1687], S[c0+1][c0+1687-1] + can_pair(RNA, c0, c0+1687));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 311; c0 += 1)
    for (c1 = c0 + 1688; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1688+c0] + S[-c0+c1-1688+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1687+c0] + S[1687+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 311; c0 += 1)
    S[c0][c0+1688] = MAX(S[c0][c0+1688], S[c0+1][c0+1688-1] + can_pair(RNA, c0, c0+1688));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 310; c0 += 1)
    for (c1 = c0 + 1689; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1689+c0] + S[-c0+c1-1689+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1688+c0] + S[1688+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 310; c0 += 1)
    S[c0][c0+1689] = MAX(S[c0][c0+1689], S[c0+1][c0+1689-1] + can_pair(RNA, c0, c0+1689));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 309; c0 += 1)
    for (c1 = c0 + 1690; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1690+c0] + S[-c0+c1-1690+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1689+c0] + S[1689+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 309; c0 += 1)
    S[c0][c0+1690] = MAX(S[c0][c0+1690], S[c0+1][c0+1690-1] + can_pair(RNA, c0, c0+1690));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 308; c0 += 1)
    for (c1 = c0 + 1691; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1691+c0] + S[-c0+c1-1691+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1690+c0] + S[1690+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 308; c0 += 1)
    S[c0][c0+1691] = MAX(S[c0][c0+1691], S[c0+1][c0+1691-1] + can_pair(RNA, c0, c0+1691));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 307; c0 += 1)
    for (c1 = c0 + 1692; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1692+c0] + S[-c0+c1-1692+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1691+c0] + S[1691+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 307; c0 += 1)
    S[c0][c0+1692] = MAX(S[c0][c0+1692], S[c0+1][c0+1692-1] + can_pair(RNA, c0, c0+1692));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 306; c0 += 1)
    for (c1 = c0 + 1693; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1693+c0] + S[-c0+c1-1693+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1692+c0] + S[1692+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 306; c0 += 1)
    S[c0][c0+1693] = MAX(S[c0][c0+1693], S[c0+1][c0+1693-1] + can_pair(RNA, c0, c0+1693));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 305; c0 += 1)
    for (c1 = c0 + 1694; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1694+c0] + S[-c0+c1-1694+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1693+c0] + S[1693+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 305; c0 += 1)
    S[c0][c0+1694] = MAX(S[c0][c0+1694], S[c0+1][c0+1694-1] + can_pair(RNA, c0, c0+1694));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 304; c0 += 1)
    for (c1 = c0 + 1695; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1695+c0] + S[-c0+c1-1695+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1694+c0] + S[1694+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 304; c0 += 1)
    S[c0][c0+1695] = MAX(S[c0][c0+1695], S[c0+1][c0+1695-1] + can_pair(RNA, c0, c0+1695));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 303; c0 += 1)
    for (c1 = c0 + 1696; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1696+c0] + S[-c0+c1-1696+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1695+c0] + S[1695+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 303; c0 += 1)
    S[c0][c0+1696] = MAX(S[c0][c0+1696], S[c0+1][c0+1696-1] + can_pair(RNA, c0, c0+1696));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 302; c0 += 1)
    for (c1 = c0 + 1697; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1697+c0] + S[-c0+c1-1697+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1696+c0] + S[1696+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 302; c0 += 1)
    S[c0][c0+1697] = MAX(S[c0][c0+1697], S[c0+1][c0+1697-1] + can_pair(RNA, c0, c0+1697));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 301; c0 += 1)
    for (c1 = c0 + 1698; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1698+c0] + S[-c0+c1-1698+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1697+c0] + S[1697+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 301; c0 += 1)
    S[c0][c0+1698] = MAX(S[c0][c0+1698], S[c0+1][c0+1698-1] + can_pair(RNA, c0, c0+1698));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 300; c0 += 1)
    for (c1 = c0 + 1699; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1699+c0] + S[-c0+c1-1699+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1698+c0] + S[1698+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 300; c0 += 1)
    S[c0][c0+1699] = MAX(S[c0][c0+1699], S[c0+1][c0+1699-1] + can_pair(RNA, c0, c0+1699));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 299; c0 += 1)
    for (c1 = c0 + 1700; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1700+c0] + S[-c0+c1-1700+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1699+c0] + S[1699+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 299; c0 += 1)
    S[c0][c0+1700] = MAX(S[c0][c0+1700], S[c0+1][c0+1700-1] + can_pair(RNA, c0, c0+1700));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 298; c0 += 1)
    for (c1 = c0 + 1701; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1701+c0] + S[-c0+c1-1701+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1700+c0] + S[1700+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 298; c0 += 1)
    S[c0][c0+1701] = MAX(S[c0][c0+1701], S[c0+1][c0+1701-1] + can_pair(RNA, c0, c0+1701));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 297; c0 += 1)
    for (c1 = c0 + 1702; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1702+c0] + S[-c0+c1-1702+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1701+c0] + S[1701+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 297; c0 += 1)
    S[c0][c0+1702] = MAX(S[c0][c0+1702], S[c0+1][c0+1702-1] + can_pair(RNA, c0, c0+1702));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 296; c0 += 1)
    for (c1 = c0 + 1703; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1703+c0] + S[-c0+c1-1703+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1702+c0] + S[1702+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 296; c0 += 1)
    S[c0][c0+1703] = MAX(S[c0][c0+1703], S[c0+1][c0+1703-1] + can_pair(RNA, c0, c0+1703));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 295; c0 += 1)
    for (c1 = c0 + 1704; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1704+c0] + S[-c0+c1-1704+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1703+c0] + S[1703+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 295; c0 += 1)
    S[c0][c0+1704] = MAX(S[c0][c0+1704], S[c0+1][c0+1704-1] + can_pair(RNA, c0, c0+1704));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 294; c0 += 1)
    for (c1 = c0 + 1705; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1705+c0] + S[-c0+c1-1705+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1704+c0] + S[1704+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 294; c0 += 1)
    S[c0][c0+1705] = MAX(S[c0][c0+1705], S[c0+1][c0+1705-1] + can_pair(RNA, c0, c0+1705));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 293; c0 += 1)
    for (c1 = c0 + 1706; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1706+c0] + S[-c0+c1-1706+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1705+c0] + S[1705+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 293; c0 += 1)
    S[c0][c0+1706] = MAX(S[c0][c0+1706], S[c0+1][c0+1706-1] + can_pair(RNA, c0, c0+1706));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 292; c0 += 1)
    for (c1 = c0 + 1707; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1707+c0] + S[-c0+c1-1707+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1706+c0] + S[1706+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 292; c0 += 1)
    S[c0][c0+1707] = MAX(S[c0][c0+1707], S[c0+1][c0+1707-1] + can_pair(RNA, c0, c0+1707));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 291; c0 += 1)
    for (c1 = c0 + 1708; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1708+c0] + S[-c0+c1-1708+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1707+c0] + S[1707+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 291; c0 += 1)
    S[c0][c0+1708] = MAX(S[c0][c0+1708], S[c0+1][c0+1708-1] + can_pair(RNA, c0, c0+1708));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 290; c0 += 1)
    for (c1 = c0 + 1709; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1709+c0] + S[-c0+c1-1709+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1708+c0] + S[1708+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 290; c0 += 1)
    S[c0][c0+1709] = MAX(S[c0][c0+1709], S[c0+1][c0+1709-1] + can_pair(RNA, c0, c0+1709));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 289; c0 += 1)
    for (c1 = c0 + 1710; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1710+c0] + S[-c0+c1-1710+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1709+c0] + S[1709+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 289; c0 += 1)
    S[c0][c0+1710] = MAX(S[c0][c0+1710], S[c0+1][c0+1710-1] + can_pair(RNA, c0, c0+1710));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 288; c0 += 1)
    for (c1 = c0 + 1711; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1711+c0] + S[-c0+c1-1711+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1710+c0] + S[1710+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 288; c0 += 1)
    S[c0][c0+1711] = MAX(S[c0][c0+1711], S[c0+1][c0+1711-1] + can_pair(RNA, c0, c0+1711));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 287; c0 += 1)
    for (c1 = c0 + 1712; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1712+c0] + S[-c0+c1-1712+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1711+c0] + S[1711+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 287; c0 += 1)
    S[c0][c0+1712] = MAX(S[c0][c0+1712], S[c0+1][c0+1712-1] + can_pair(RNA, c0, c0+1712));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 286; c0 += 1)
    for (c1 = c0 + 1713; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1713+c0] + S[-c0+c1-1713+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1712+c0] + S[1712+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 286; c0 += 1)
    S[c0][c0+1713] = MAX(S[c0][c0+1713], S[c0+1][c0+1713-1] + can_pair(RNA, c0, c0+1713));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 285; c0 += 1)
    for (c1 = c0 + 1714; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1714+c0] + S[-c0+c1-1714+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1713+c0] + S[1713+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 285; c0 += 1)
    S[c0][c0+1714] = MAX(S[c0][c0+1714], S[c0+1][c0+1714-1] + can_pair(RNA, c0, c0+1714));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 284; c0 += 1)
    for (c1 = c0 + 1715; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1715+c0] + S[-c0+c1-1715+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1714+c0] + S[1714+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 284; c0 += 1)
    S[c0][c0+1715] = MAX(S[c0][c0+1715], S[c0+1][c0+1715-1] + can_pair(RNA, c0, c0+1715));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 283; c0 += 1)
    for (c1 = c0 + 1716; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1716+c0] + S[-c0+c1-1716+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1715+c0] + S[1715+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 283; c0 += 1)
    S[c0][c0+1716] = MAX(S[c0][c0+1716], S[c0+1][c0+1716-1] + can_pair(RNA, c0, c0+1716));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 282; c0 += 1)
    for (c1 = c0 + 1717; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1717+c0] + S[-c0+c1-1717+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1716+c0] + S[1716+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 282; c0 += 1)
    S[c0][c0+1717] = MAX(S[c0][c0+1717], S[c0+1][c0+1717-1] + can_pair(RNA, c0, c0+1717));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 281; c0 += 1)
    for (c1 = c0 + 1718; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1718+c0] + S[-c0+c1-1718+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1717+c0] + S[1717+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 281; c0 += 1)
    S[c0][c0+1718] = MAX(S[c0][c0+1718], S[c0+1][c0+1718-1] + can_pair(RNA, c0, c0+1718));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 280; c0 += 1)
    for (c1 = c0 + 1719; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1719+c0] + S[-c0+c1-1719+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1718+c0] + S[1718+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 280; c0 += 1)
    S[c0][c0+1719] = MAX(S[c0][c0+1719], S[c0+1][c0+1719-1] + can_pair(RNA, c0, c0+1719));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 279; c0 += 1)
    for (c1 = c0 + 1720; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1720+c0] + S[-c0+c1-1720+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1719+c0] + S[1719+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 279; c0 += 1)
    S[c0][c0+1720] = MAX(S[c0][c0+1720], S[c0+1][c0+1720-1] + can_pair(RNA, c0, c0+1720));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 278; c0 += 1)
    for (c1 = c0 + 1721; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1721+c0] + S[-c0+c1-1721+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1720+c0] + S[1720+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 278; c0 += 1)
    S[c0][c0+1721] = MAX(S[c0][c0+1721], S[c0+1][c0+1721-1] + can_pair(RNA, c0, c0+1721));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 277; c0 += 1)
    for (c1 = c0 + 1722; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1722+c0] + S[-c0+c1-1722+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1721+c0] + S[1721+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 277; c0 += 1)
    S[c0][c0+1722] = MAX(S[c0][c0+1722], S[c0+1][c0+1722-1] + can_pair(RNA, c0, c0+1722));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 276; c0 += 1)
    for (c1 = c0 + 1723; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1723+c0] + S[-c0+c1-1723+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1722+c0] + S[1722+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 276; c0 += 1)
    S[c0][c0+1723] = MAX(S[c0][c0+1723], S[c0+1][c0+1723-1] + can_pair(RNA, c0, c0+1723));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 275; c0 += 1)
    for (c1 = c0 + 1724; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1724+c0] + S[-c0+c1-1724+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1723+c0] + S[1723+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 275; c0 += 1)
    S[c0][c0+1724] = MAX(S[c0][c0+1724], S[c0+1][c0+1724-1] + can_pair(RNA, c0, c0+1724));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 274; c0 += 1)
    for (c1 = c0 + 1725; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1725+c0] + S[-c0+c1-1725+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1724+c0] + S[1724+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 274; c0 += 1)
    S[c0][c0+1725] = MAX(S[c0][c0+1725], S[c0+1][c0+1725-1] + can_pair(RNA, c0, c0+1725));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 273; c0 += 1)
    for (c1 = c0 + 1726; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1726+c0] + S[-c0+c1-1726+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1725+c0] + S[1725+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 273; c0 += 1)
    S[c0][c0+1726] = MAX(S[c0][c0+1726], S[c0+1][c0+1726-1] + can_pair(RNA, c0, c0+1726));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 272; c0 += 1)
    for (c1 = c0 + 1727; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1727+c0] + S[-c0+c1-1727+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1726+c0] + S[1726+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 272; c0 += 1)
    S[c0][c0+1727] = MAX(S[c0][c0+1727], S[c0+1][c0+1727-1] + can_pair(RNA, c0, c0+1727));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 271; c0 += 1)
    for (c1 = c0 + 1728; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1728+c0] + S[-c0+c1-1728+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1727+c0] + S[1727+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 271; c0 += 1)
    S[c0][c0+1728] = MAX(S[c0][c0+1728], S[c0+1][c0+1728-1] + can_pair(RNA, c0, c0+1728));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 270; c0 += 1)
    for (c1 = c0 + 1729; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1729+c0] + S[-c0+c1-1729+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1728+c0] + S[1728+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 270; c0 += 1)
    S[c0][c0+1729] = MAX(S[c0][c0+1729], S[c0+1][c0+1729-1] + can_pair(RNA, c0, c0+1729));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 269; c0 += 1)
    for (c1 = c0 + 1730; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1730+c0] + S[-c0+c1-1730+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1729+c0] + S[1729+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 269; c0 += 1)
    S[c0][c0+1730] = MAX(S[c0][c0+1730], S[c0+1][c0+1730-1] + can_pair(RNA, c0, c0+1730));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 268; c0 += 1)
    for (c1 = c0 + 1731; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1731+c0] + S[-c0+c1-1731+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1730+c0] + S[1730+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 268; c0 += 1)
    S[c0][c0+1731] = MAX(S[c0][c0+1731], S[c0+1][c0+1731-1] + can_pair(RNA, c0, c0+1731));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 267; c0 += 1)
    for (c1 = c0 + 1732; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1732+c0] + S[-c0+c1-1732+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1731+c0] + S[1731+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 267; c0 += 1)
    S[c0][c0+1732] = MAX(S[c0][c0+1732], S[c0+1][c0+1732-1] + can_pair(RNA, c0, c0+1732));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 266; c0 += 1)
    for (c1 = c0 + 1733; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1733+c0] + S[-c0+c1-1733+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1732+c0] + S[1732+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 266; c0 += 1)
    S[c0][c0+1733] = MAX(S[c0][c0+1733], S[c0+1][c0+1733-1] + can_pair(RNA, c0, c0+1733));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 265; c0 += 1)
    for (c1 = c0 + 1734; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1734+c0] + S[-c0+c1-1734+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1733+c0] + S[1733+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 265; c0 += 1)
    S[c0][c0+1734] = MAX(S[c0][c0+1734], S[c0+1][c0+1734-1] + can_pair(RNA, c0, c0+1734));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 264; c0 += 1)
    for (c1 = c0 + 1735; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1735+c0] + S[-c0+c1-1735+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1734+c0] + S[1734+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 264; c0 += 1)
    S[c0][c0+1735] = MAX(S[c0][c0+1735], S[c0+1][c0+1735-1] + can_pair(RNA, c0, c0+1735));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 263; c0 += 1)
    for (c1 = c0 + 1736; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1736+c0] + S[-c0+c1-1736+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1735+c0] + S[1735+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 263; c0 += 1)
    S[c0][c0+1736] = MAX(S[c0][c0+1736], S[c0+1][c0+1736-1] + can_pair(RNA, c0, c0+1736));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 262; c0 += 1)
    for (c1 = c0 + 1737; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1737+c0] + S[-c0+c1-1737+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1736+c0] + S[1736+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 262; c0 += 1)
    S[c0][c0+1737] = MAX(S[c0][c0+1737], S[c0+1][c0+1737-1] + can_pair(RNA, c0, c0+1737));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 261; c0 += 1)
    for (c1 = c0 + 1738; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1738+c0] + S[-c0+c1-1738+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1737+c0] + S[1737+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 261; c0 += 1)
    S[c0][c0+1738] = MAX(S[c0][c0+1738], S[c0+1][c0+1738-1] + can_pair(RNA, c0, c0+1738));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 260; c0 += 1)
    for (c1 = c0 + 1739; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1739+c0] + S[-c0+c1-1739+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1738+c0] + S[1738+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 260; c0 += 1)
    S[c0][c0+1739] = MAX(S[c0][c0+1739], S[c0+1][c0+1739-1] + can_pair(RNA, c0, c0+1739));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 259; c0 += 1)
    for (c1 = c0 + 1740; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1740+c0] + S[-c0+c1-1740+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1739+c0] + S[1739+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 259; c0 += 1)
    S[c0][c0+1740] = MAX(S[c0][c0+1740], S[c0+1][c0+1740-1] + can_pair(RNA, c0, c0+1740));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 258; c0 += 1)
    for (c1 = c0 + 1741; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1741+c0] + S[-c0+c1-1741+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1740+c0] + S[1740+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 258; c0 += 1)
    S[c0][c0+1741] = MAX(S[c0][c0+1741], S[c0+1][c0+1741-1] + can_pair(RNA, c0, c0+1741));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 257; c0 += 1)
    for (c1 = c0 + 1742; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1742+c0] + S[-c0+c1-1742+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1741+c0] + S[1741+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 257; c0 += 1)
    S[c0][c0+1742] = MAX(S[c0][c0+1742], S[c0+1][c0+1742-1] + can_pair(RNA, c0, c0+1742));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 256; c0 += 1)
    for (c1 = c0 + 1743; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1743+c0] + S[-c0+c1-1743+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1742+c0] + S[1742+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 256; c0 += 1)
    S[c0][c0+1743] = MAX(S[c0][c0+1743], S[c0+1][c0+1743-1] + can_pair(RNA, c0, c0+1743));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 255; c0 += 1)
    for (c1 = c0 + 1744; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1744+c0] + S[-c0+c1-1744+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1743+c0] + S[1743+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 255; c0 += 1)
    S[c0][c0+1744] = MAX(S[c0][c0+1744], S[c0+1][c0+1744-1] + can_pair(RNA, c0, c0+1744));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 254; c0 += 1)
    for (c1 = c0 + 1745; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1745+c0] + S[-c0+c1-1745+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1744+c0] + S[1744+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 254; c0 += 1)
    S[c0][c0+1745] = MAX(S[c0][c0+1745], S[c0+1][c0+1745-1] + can_pair(RNA, c0, c0+1745));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 253; c0 += 1)
    for (c1 = c0 + 1746; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1746+c0] + S[-c0+c1-1746+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1745+c0] + S[1745+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 253; c0 += 1)
    S[c0][c0+1746] = MAX(S[c0][c0+1746], S[c0+1][c0+1746-1] + can_pair(RNA, c0, c0+1746));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 252; c0 += 1)
    for (c1 = c0 + 1747; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1747+c0] + S[-c0+c1-1747+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1746+c0] + S[1746+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 252; c0 += 1)
    S[c0][c0+1747] = MAX(S[c0][c0+1747], S[c0+1][c0+1747-1] + can_pair(RNA, c0, c0+1747));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 251; c0 += 1)
    for (c1 = c0 + 1748; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1748+c0] + S[-c0+c1-1748+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1747+c0] + S[1747+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 251; c0 += 1)
    S[c0][c0+1748] = MAX(S[c0][c0+1748], S[c0+1][c0+1748-1] + can_pair(RNA, c0, c0+1748));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 250; c0 += 1)
    for (c1 = c0 + 1749; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1749+c0] + S[-c0+c1-1749+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1748+c0] + S[1748+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 250; c0 += 1)
    S[c0][c0+1749] = MAX(S[c0][c0+1749], S[c0+1][c0+1749-1] + can_pair(RNA, c0, c0+1749));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 249; c0 += 1)
    for (c1 = c0 + 1750; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1750+c0] + S[-c0+c1-1750+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1749+c0] + S[1749+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 249; c0 += 1)
    S[c0][c0+1750] = MAX(S[c0][c0+1750], S[c0+1][c0+1750-1] + can_pair(RNA, c0, c0+1750));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 248; c0 += 1)
    for (c1 = c0 + 1751; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1751+c0] + S[-c0+c1-1751+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1750+c0] + S[1750+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 248; c0 += 1)
    S[c0][c0+1751] = MAX(S[c0][c0+1751], S[c0+1][c0+1751-1] + can_pair(RNA, c0, c0+1751));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 247; c0 += 1)
    for (c1 = c0 + 1752; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1752+c0] + S[-c0+c1-1752+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1751+c0] + S[1751+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 247; c0 += 1)
    S[c0][c0+1752] = MAX(S[c0][c0+1752], S[c0+1][c0+1752-1] + can_pair(RNA, c0, c0+1752));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 246; c0 += 1)
    for (c1 = c0 + 1753; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1753+c0] + S[-c0+c1-1753+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1752+c0] + S[1752+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 246; c0 += 1)
    S[c0][c0+1753] = MAX(S[c0][c0+1753], S[c0+1][c0+1753-1] + can_pair(RNA, c0, c0+1753));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 245; c0 += 1)
    for (c1 = c0 + 1754; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1754+c0] + S[-c0+c1-1754+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1753+c0] + S[1753+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 245; c0 += 1)
    S[c0][c0+1754] = MAX(S[c0][c0+1754], S[c0+1][c0+1754-1] + can_pair(RNA, c0, c0+1754));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 244; c0 += 1)
    for (c1 = c0 + 1755; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1755+c0] + S[-c0+c1-1755+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1754+c0] + S[1754+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 244; c0 += 1)
    S[c0][c0+1755] = MAX(S[c0][c0+1755], S[c0+1][c0+1755-1] + can_pair(RNA, c0, c0+1755));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 243; c0 += 1)
    for (c1 = c0 + 1756; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1756+c0] + S[-c0+c1-1756+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1755+c0] + S[1755+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 243; c0 += 1)
    S[c0][c0+1756] = MAX(S[c0][c0+1756], S[c0+1][c0+1756-1] + can_pair(RNA, c0, c0+1756));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 242; c0 += 1)
    for (c1 = c0 + 1757; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1757+c0] + S[-c0+c1-1757+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1756+c0] + S[1756+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 242; c0 += 1)
    S[c0][c0+1757] = MAX(S[c0][c0+1757], S[c0+1][c0+1757-1] + can_pair(RNA, c0, c0+1757));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 241; c0 += 1)
    for (c1 = c0 + 1758; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1758+c0] + S[-c0+c1-1758+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1757+c0] + S[1757+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 241; c0 += 1)
    S[c0][c0+1758] = MAX(S[c0][c0+1758], S[c0+1][c0+1758-1] + can_pair(RNA, c0, c0+1758));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 240; c0 += 1)
    for (c1 = c0 + 1759; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1759+c0] + S[-c0+c1-1759+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1758+c0] + S[1758+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 240; c0 += 1)
    S[c0][c0+1759] = MAX(S[c0][c0+1759], S[c0+1][c0+1759-1] + can_pair(RNA, c0, c0+1759));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 239; c0 += 1)
    for (c1 = c0 + 1760; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1760+c0] + S[-c0+c1-1760+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1759+c0] + S[1759+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 239; c0 += 1)
    S[c0][c0+1760] = MAX(S[c0][c0+1760], S[c0+1][c0+1760-1] + can_pair(RNA, c0, c0+1760));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 238; c0 += 1)
    for (c1 = c0 + 1761; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1761+c0] + S[-c0+c1-1761+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1760+c0] + S[1760+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 238; c0 += 1)
    S[c0][c0+1761] = MAX(S[c0][c0+1761], S[c0+1][c0+1761-1] + can_pair(RNA, c0, c0+1761));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 237; c0 += 1)
    for (c1 = c0 + 1762; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1762+c0] + S[-c0+c1-1762+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1761+c0] + S[1761+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 237; c0 += 1)
    S[c0][c0+1762] = MAX(S[c0][c0+1762], S[c0+1][c0+1762-1] + can_pair(RNA, c0, c0+1762));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 236; c0 += 1)
    for (c1 = c0 + 1763; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1763+c0] + S[-c0+c1-1763+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1762+c0] + S[1762+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 236; c0 += 1)
    S[c0][c0+1763] = MAX(S[c0][c0+1763], S[c0+1][c0+1763-1] + can_pair(RNA, c0, c0+1763));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 235; c0 += 1)
    for (c1 = c0 + 1764; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1764+c0] + S[-c0+c1-1764+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1763+c0] + S[1763+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 235; c0 += 1)
    S[c0][c0+1764] = MAX(S[c0][c0+1764], S[c0+1][c0+1764-1] + can_pair(RNA, c0, c0+1764));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 234; c0 += 1)
    for (c1 = c0 + 1765; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1765+c0] + S[-c0+c1-1765+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1764+c0] + S[1764+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 234; c0 += 1)
    S[c0][c0+1765] = MAX(S[c0][c0+1765], S[c0+1][c0+1765-1] + can_pair(RNA, c0, c0+1765));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 233; c0 += 1)
    for (c1 = c0 + 1766; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1766+c0] + S[-c0+c1-1766+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1765+c0] + S[1765+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 233; c0 += 1)
    S[c0][c0+1766] = MAX(S[c0][c0+1766], S[c0+1][c0+1766-1] + can_pair(RNA, c0, c0+1766));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 232; c0 += 1)
    for (c1 = c0 + 1767; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1767+c0] + S[-c0+c1-1767+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1766+c0] + S[1766+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 232; c0 += 1)
    S[c0][c0+1767] = MAX(S[c0][c0+1767], S[c0+1][c0+1767-1] + can_pair(RNA, c0, c0+1767));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 231; c0 += 1)
    for (c1 = c0 + 1768; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1768+c0] + S[-c0+c1-1768+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1767+c0] + S[1767+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 231; c0 += 1)
    S[c0][c0+1768] = MAX(S[c0][c0+1768], S[c0+1][c0+1768-1] + can_pair(RNA, c0, c0+1768));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 230; c0 += 1)
    for (c1 = c0 + 1769; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1769+c0] + S[-c0+c1-1769+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1768+c0] + S[1768+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 230; c0 += 1)
    S[c0][c0+1769] = MAX(S[c0][c0+1769], S[c0+1][c0+1769-1] + can_pair(RNA, c0, c0+1769));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 229; c0 += 1)
    for (c1 = c0 + 1770; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1770+c0] + S[-c0+c1-1770+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1769+c0] + S[1769+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 229; c0 += 1)
    S[c0][c0+1770] = MAX(S[c0][c0+1770], S[c0+1][c0+1770-1] + can_pair(RNA, c0, c0+1770));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 228; c0 += 1)
    for (c1 = c0 + 1771; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1771+c0] + S[-c0+c1-1771+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1770+c0] + S[1770+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 228; c0 += 1)
    S[c0][c0+1771] = MAX(S[c0][c0+1771], S[c0+1][c0+1771-1] + can_pair(RNA, c0, c0+1771));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 227; c0 += 1)
    for (c1 = c0 + 1772; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1772+c0] + S[-c0+c1-1772+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1771+c0] + S[1771+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 227; c0 += 1)
    S[c0][c0+1772] = MAX(S[c0][c0+1772], S[c0+1][c0+1772-1] + can_pair(RNA, c0, c0+1772));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 226; c0 += 1)
    for (c1 = c0 + 1773; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1773+c0] + S[-c0+c1-1773+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1772+c0] + S[1772+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 226; c0 += 1)
    S[c0][c0+1773] = MAX(S[c0][c0+1773], S[c0+1][c0+1773-1] + can_pair(RNA, c0, c0+1773));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 225; c0 += 1)
    for (c1 = c0 + 1774; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1774+c0] + S[-c0+c1-1774+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1773+c0] + S[1773+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 225; c0 += 1)
    S[c0][c0+1774] = MAX(S[c0][c0+1774], S[c0+1][c0+1774-1] + can_pair(RNA, c0, c0+1774));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 224; c0 += 1)
    for (c1 = c0 + 1775; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1775+c0] + S[-c0+c1-1775+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1774+c0] + S[1774+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 224; c0 += 1)
    S[c0][c0+1775] = MAX(S[c0][c0+1775], S[c0+1][c0+1775-1] + can_pair(RNA, c0, c0+1775));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 223; c0 += 1)
    for (c1 = c0 + 1776; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1776+c0] + S[-c0+c1-1776+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1775+c0] + S[1775+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 223; c0 += 1)
    S[c0][c0+1776] = MAX(S[c0][c0+1776], S[c0+1][c0+1776-1] + can_pair(RNA, c0, c0+1776));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 222; c0 += 1)
    for (c1 = c0 + 1777; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1777+c0] + S[-c0+c1-1777+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1776+c0] + S[1776+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 222; c0 += 1)
    S[c0][c0+1777] = MAX(S[c0][c0+1777], S[c0+1][c0+1777-1] + can_pair(RNA, c0, c0+1777));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 221; c0 += 1)
    for (c1 = c0 + 1778; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1778+c0] + S[-c0+c1-1778+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1777+c0] + S[1777+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 221; c0 += 1)
    S[c0][c0+1778] = MAX(S[c0][c0+1778], S[c0+1][c0+1778-1] + can_pair(RNA, c0, c0+1778));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 220; c0 += 1)
    for (c1 = c0 + 1779; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1779+c0] + S[-c0+c1-1779+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1778+c0] + S[1778+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 220; c0 += 1)
    S[c0][c0+1779] = MAX(S[c0][c0+1779], S[c0+1][c0+1779-1] + can_pair(RNA, c0, c0+1779));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 219; c0 += 1)
    for (c1 = c0 + 1780; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1780+c0] + S[-c0+c1-1780+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1779+c0] + S[1779+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 219; c0 += 1)
    S[c0][c0+1780] = MAX(S[c0][c0+1780], S[c0+1][c0+1780-1] + can_pair(RNA, c0, c0+1780));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 218; c0 += 1)
    for (c1 = c0 + 1781; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1781+c0] + S[-c0+c1-1781+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1780+c0] + S[1780+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 218; c0 += 1)
    S[c0][c0+1781] = MAX(S[c0][c0+1781], S[c0+1][c0+1781-1] + can_pair(RNA, c0, c0+1781));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 217; c0 += 1)
    for (c1 = c0 + 1782; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1782+c0] + S[-c0+c1-1782+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1781+c0] + S[1781+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 217; c0 += 1)
    S[c0][c0+1782] = MAX(S[c0][c0+1782], S[c0+1][c0+1782-1] + can_pair(RNA, c0, c0+1782));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 216; c0 += 1)
    for (c1 = c0 + 1783; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1783+c0] + S[-c0+c1-1783+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1782+c0] + S[1782+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 216; c0 += 1)
    S[c0][c0+1783] = MAX(S[c0][c0+1783], S[c0+1][c0+1783-1] + can_pair(RNA, c0, c0+1783));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 215; c0 += 1)
    for (c1 = c0 + 1784; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1784+c0] + S[-c0+c1-1784+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1783+c0] + S[1783+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 215; c0 += 1)
    S[c0][c0+1784] = MAX(S[c0][c0+1784], S[c0+1][c0+1784-1] + can_pair(RNA, c0, c0+1784));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 214; c0 += 1)
    for (c1 = c0 + 1785; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1785+c0] + S[-c0+c1-1785+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1784+c0] + S[1784+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 214; c0 += 1)
    S[c0][c0+1785] = MAX(S[c0][c0+1785], S[c0+1][c0+1785-1] + can_pair(RNA, c0, c0+1785));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 213; c0 += 1)
    for (c1 = c0 + 1786; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1786+c0] + S[-c0+c1-1786+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1785+c0] + S[1785+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 213; c0 += 1)
    S[c0][c0+1786] = MAX(S[c0][c0+1786], S[c0+1][c0+1786-1] + can_pair(RNA, c0, c0+1786));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 212; c0 += 1)
    for (c1 = c0 + 1787; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1787+c0] + S[-c0+c1-1787+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1786+c0] + S[1786+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 212; c0 += 1)
    S[c0][c0+1787] = MAX(S[c0][c0+1787], S[c0+1][c0+1787-1] + can_pair(RNA, c0, c0+1787));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 211; c0 += 1)
    for (c1 = c0 + 1788; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1788+c0] + S[-c0+c1-1788+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1787+c0] + S[1787+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 211; c0 += 1)
    S[c0][c0+1788] = MAX(S[c0][c0+1788], S[c0+1][c0+1788-1] + can_pair(RNA, c0, c0+1788));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 210; c0 += 1)
    for (c1 = c0 + 1789; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1789+c0] + S[-c0+c1-1789+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1788+c0] + S[1788+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 210; c0 += 1)
    S[c0][c0+1789] = MAX(S[c0][c0+1789], S[c0+1][c0+1789-1] + can_pair(RNA, c0, c0+1789));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 209; c0 += 1)
    for (c1 = c0 + 1790; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1790+c0] + S[-c0+c1-1790+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1789+c0] + S[1789+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 209; c0 += 1)
    S[c0][c0+1790] = MAX(S[c0][c0+1790], S[c0+1][c0+1790-1] + can_pair(RNA, c0, c0+1790));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 208; c0 += 1)
    for (c1 = c0 + 1791; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1791+c0] + S[-c0+c1-1791+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1790+c0] + S[1790+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 208; c0 += 1)
    S[c0][c0+1791] = MAX(S[c0][c0+1791], S[c0+1][c0+1791-1] + can_pair(RNA, c0, c0+1791));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 207; c0 += 1)
    for (c1 = c0 + 1792; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1792+c0] + S[-c0+c1-1792+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1791+c0] + S[1791+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 207; c0 += 1)
    S[c0][c0+1792] = MAX(S[c0][c0+1792], S[c0+1][c0+1792-1] + can_pair(RNA, c0, c0+1792));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 206; c0 += 1)
    for (c1 = c0 + 1793; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1793+c0] + S[-c0+c1-1793+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1792+c0] + S[1792+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 206; c0 += 1)
    S[c0][c0+1793] = MAX(S[c0][c0+1793], S[c0+1][c0+1793-1] + can_pair(RNA, c0, c0+1793));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 205; c0 += 1)
    for (c1 = c0 + 1794; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1794+c0] + S[-c0+c1-1794+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1793+c0] + S[1793+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 205; c0 += 1)
    S[c0][c0+1794] = MAX(S[c0][c0+1794], S[c0+1][c0+1794-1] + can_pair(RNA, c0, c0+1794));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 204; c0 += 1)
    for (c1 = c0 + 1795; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1795+c0] + S[-c0+c1-1795+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1794+c0] + S[1794+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 204; c0 += 1)
    S[c0][c0+1795] = MAX(S[c0][c0+1795], S[c0+1][c0+1795-1] + can_pair(RNA, c0, c0+1795));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 203; c0 += 1)
    for (c1 = c0 + 1796; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1796+c0] + S[-c0+c1-1796+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1795+c0] + S[1795+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 203; c0 += 1)
    S[c0][c0+1796] = MAX(S[c0][c0+1796], S[c0+1][c0+1796-1] + can_pair(RNA, c0, c0+1796));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 202; c0 += 1)
    for (c1 = c0 + 1797; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1797+c0] + S[-c0+c1-1797+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1796+c0] + S[1796+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 202; c0 += 1)
    S[c0][c0+1797] = MAX(S[c0][c0+1797], S[c0+1][c0+1797-1] + can_pair(RNA, c0, c0+1797));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 201; c0 += 1)
    for (c1 = c0 + 1798; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1798+c0] + S[-c0+c1-1798+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1797+c0] + S[1797+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 201; c0 += 1)
    S[c0][c0+1798] = MAX(S[c0][c0+1798], S[c0+1][c0+1798-1] + can_pair(RNA, c0, c0+1798));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 200; c0 += 1)
    for (c1 = c0 + 1799; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1799+c0] + S[-c0+c1-1799+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1798+c0] + S[1798+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 200; c0 += 1)
    S[c0][c0+1799] = MAX(S[c0][c0+1799], S[c0+1][c0+1799-1] + can_pair(RNA, c0, c0+1799));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 199; c0 += 1)
    for (c1 = c0 + 1800; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1800+c0] + S[-c0+c1-1800+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1799+c0] + S[1799+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 199; c0 += 1)
    S[c0][c0+1800] = MAX(S[c0][c0+1800], S[c0+1][c0+1800-1] + can_pair(RNA, c0, c0+1800));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 198; c0 += 1)
    for (c1 = c0 + 1801; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1801+c0] + S[-c0+c1-1801+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1800+c0] + S[1800+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 198; c0 += 1)
    S[c0][c0+1801] = MAX(S[c0][c0+1801], S[c0+1][c0+1801-1] + can_pair(RNA, c0, c0+1801));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 197; c0 += 1)
    for (c1 = c0 + 1802; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1802+c0] + S[-c0+c1-1802+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1801+c0] + S[1801+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 197; c0 += 1)
    S[c0][c0+1802] = MAX(S[c0][c0+1802], S[c0+1][c0+1802-1] + can_pair(RNA, c0, c0+1802));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 196; c0 += 1)
    for (c1 = c0 + 1803; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1803+c0] + S[-c0+c1-1803+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1802+c0] + S[1802+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 196; c0 += 1)
    S[c0][c0+1803] = MAX(S[c0][c0+1803], S[c0+1][c0+1803-1] + can_pair(RNA, c0, c0+1803));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 195; c0 += 1)
    for (c1 = c0 + 1804; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1804+c0] + S[-c0+c1-1804+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1803+c0] + S[1803+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 195; c0 += 1)
    S[c0][c0+1804] = MAX(S[c0][c0+1804], S[c0+1][c0+1804-1] + can_pair(RNA, c0, c0+1804));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 194; c0 += 1)
    for (c1 = c0 + 1805; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1805+c0] + S[-c0+c1-1805+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1804+c0] + S[1804+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 194; c0 += 1)
    S[c0][c0+1805] = MAX(S[c0][c0+1805], S[c0+1][c0+1805-1] + can_pair(RNA, c0, c0+1805));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 193; c0 += 1)
    for (c1 = c0 + 1806; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1806+c0] + S[-c0+c1-1806+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1805+c0] + S[1805+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 193; c0 += 1)
    S[c0][c0+1806] = MAX(S[c0][c0+1806], S[c0+1][c0+1806-1] + can_pair(RNA, c0, c0+1806));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 192; c0 += 1)
    for (c1 = c0 + 1807; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1807+c0] + S[-c0+c1-1807+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1806+c0] + S[1806+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 192; c0 += 1)
    S[c0][c0+1807] = MAX(S[c0][c0+1807], S[c0+1][c0+1807-1] + can_pair(RNA, c0, c0+1807));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 191; c0 += 1)
    for (c1 = c0 + 1808; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1808+c0] + S[-c0+c1-1808+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1807+c0] + S[1807+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 191; c0 += 1)
    S[c0][c0+1808] = MAX(S[c0][c0+1808], S[c0+1][c0+1808-1] + can_pair(RNA, c0, c0+1808));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 190; c0 += 1)
    for (c1 = c0 + 1809; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1809+c0] + S[-c0+c1-1809+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1808+c0] + S[1808+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 190; c0 += 1)
    S[c0][c0+1809] = MAX(S[c0][c0+1809], S[c0+1][c0+1809-1] + can_pair(RNA, c0, c0+1809));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 189; c0 += 1)
    for (c1 = c0 + 1810; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1810+c0] + S[-c0+c1-1810+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1809+c0] + S[1809+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 189; c0 += 1)
    S[c0][c0+1810] = MAX(S[c0][c0+1810], S[c0+1][c0+1810-1] + can_pair(RNA, c0, c0+1810));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 188; c0 += 1)
    for (c1 = c0 + 1811; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1811+c0] + S[-c0+c1-1811+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1810+c0] + S[1810+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 188; c0 += 1)
    S[c0][c0+1811] = MAX(S[c0][c0+1811], S[c0+1][c0+1811-1] + can_pair(RNA, c0, c0+1811));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 187; c0 += 1)
    for (c1 = c0 + 1812; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1812+c0] + S[-c0+c1-1812+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1811+c0] + S[1811+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 187; c0 += 1)
    S[c0][c0+1812] = MAX(S[c0][c0+1812], S[c0+1][c0+1812-1] + can_pair(RNA, c0, c0+1812));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 186; c0 += 1)
    for (c1 = c0 + 1813; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1813+c0] + S[-c0+c1-1813+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1812+c0] + S[1812+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 186; c0 += 1)
    S[c0][c0+1813] = MAX(S[c0][c0+1813], S[c0+1][c0+1813-1] + can_pair(RNA, c0, c0+1813));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 185; c0 += 1)
    for (c1 = c0 + 1814; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1814+c0] + S[-c0+c1-1814+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1813+c0] + S[1813+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 185; c0 += 1)
    S[c0][c0+1814] = MAX(S[c0][c0+1814], S[c0+1][c0+1814-1] + can_pair(RNA, c0, c0+1814));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 184; c0 += 1)
    for (c1 = c0 + 1815; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1815+c0] + S[-c0+c1-1815+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1814+c0] + S[1814+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 184; c0 += 1)
    S[c0][c0+1815] = MAX(S[c0][c0+1815], S[c0+1][c0+1815-1] + can_pair(RNA, c0, c0+1815));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 183; c0 += 1)
    for (c1 = c0 + 1816; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1816+c0] + S[-c0+c1-1816+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1815+c0] + S[1815+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 183; c0 += 1)
    S[c0][c0+1816] = MAX(S[c0][c0+1816], S[c0+1][c0+1816-1] + can_pair(RNA, c0, c0+1816));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 182; c0 += 1)
    for (c1 = c0 + 1817; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1817+c0] + S[-c0+c1-1817+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1816+c0] + S[1816+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 182; c0 += 1)
    S[c0][c0+1817] = MAX(S[c0][c0+1817], S[c0+1][c0+1817-1] + can_pair(RNA, c0, c0+1817));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 181; c0 += 1)
    for (c1 = c0 + 1818; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1818+c0] + S[-c0+c1-1818+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1817+c0] + S[1817+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 181; c0 += 1)
    S[c0][c0+1818] = MAX(S[c0][c0+1818], S[c0+1][c0+1818-1] + can_pair(RNA, c0, c0+1818));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 180; c0 += 1)
    for (c1 = c0 + 1819; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1819+c0] + S[-c0+c1-1819+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1818+c0] + S[1818+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 180; c0 += 1)
    S[c0][c0+1819] = MAX(S[c0][c0+1819], S[c0+1][c0+1819-1] + can_pair(RNA, c0, c0+1819));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 179; c0 += 1)
    for (c1 = c0 + 1820; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1820+c0] + S[-c0+c1-1820+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1819+c0] + S[1819+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 179; c0 += 1)
    S[c0][c0+1820] = MAX(S[c0][c0+1820], S[c0+1][c0+1820-1] + can_pair(RNA, c0, c0+1820));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 178; c0 += 1)
    for (c1 = c0 + 1821; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1821+c0] + S[-c0+c1-1821+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1820+c0] + S[1820+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 178; c0 += 1)
    S[c0][c0+1821] = MAX(S[c0][c0+1821], S[c0+1][c0+1821-1] + can_pair(RNA, c0, c0+1821));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 177; c0 += 1)
    for (c1 = c0 + 1822; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1822+c0] + S[-c0+c1-1822+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1821+c0] + S[1821+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 177; c0 += 1)
    S[c0][c0+1822] = MAX(S[c0][c0+1822], S[c0+1][c0+1822-1] + can_pair(RNA, c0, c0+1822));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 176; c0 += 1)
    for (c1 = c0 + 1823; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1823+c0] + S[-c0+c1-1823+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1822+c0] + S[1822+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 176; c0 += 1)
    S[c0][c0+1823] = MAX(S[c0][c0+1823], S[c0+1][c0+1823-1] + can_pair(RNA, c0, c0+1823));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 175; c0 += 1)
    for (c1 = c0 + 1824; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1824+c0] + S[-c0+c1-1824+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1823+c0] + S[1823+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 175; c0 += 1)
    S[c0][c0+1824] = MAX(S[c0][c0+1824], S[c0+1][c0+1824-1] + can_pair(RNA, c0, c0+1824));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 174; c0 += 1)
    for (c1 = c0 + 1825; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1825+c0] + S[-c0+c1-1825+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1824+c0] + S[1824+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 174; c0 += 1)
    S[c0][c0+1825] = MAX(S[c0][c0+1825], S[c0+1][c0+1825-1] + can_pair(RNA, c0, c0+1825));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 173; c0 += 1)
    for (c1 = c0 + 1826; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1826+c0] + S[-c0+c1-1826+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1825+c0] + S[1825+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 173; c0 += 1)
    S[c0][c0+1826] = MAX(S[c0][c0+1826], S[c0+1][c0+1826-1] + can_pair(RNA, c0, c0+1826));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 172; c0 += 1)
    for (c1 = c0 + 1827; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1827+c0] + S[-c0+c1-1827+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1826+c0] + S[1826+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 172; c0 += 1)
    S[c0][c0+1827] = MAX(S[c0][c0+1827], S[c0+1][c0+1827-1] + can_pair(RNA, c0, c0+1827));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 171; c0 += 1)
    for (c1 = c0 + 1828; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1828+c0] + S[-c0+c1-1828+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1827+c0] + S[1827+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 171; c0 += 1)
    S[c0][c0+1828] = MAX(S[c0][c0+1828], S[c0+1][c0+1828-1] + can_pair(RNA, c0, c0+1828));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 170; c0 += 1)
    for (c1 = c0 + 1829; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1829+c0] + S[-c0+c1-1829+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1828+c0] + S[1828+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 170; c0 += 1)
    S[c0][c0+1829] = MAX(S[c0][c0+1829], S[c0+1][c0+1829-1] + can_pair(RNA, c0, c0+1829));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 169; c0 += 1)
    for (c1 = c0 + 1830; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1830+c0] + S[-c0+c1-1830+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1829+c0] + S[1829+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 169; c0 += 1)
    S[c0][c0+1830] = MAX(S[c0][c0+1830], S[c0+1][c0+1830-1] + can_pair(RNA, c0, c0+1830));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 168; c0 += 1)
    for (c1 = c0 + 1831; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1831+c0] + S[-c0+c1-1831+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1830+c0] + S[1830+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 168; c0 += 1)
    S[c0][c0+1831] = MAX(S[c0][c0+1831], S[c0+1][c0+1831-1] + can_pair(RNA, c0, c0+1831));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 167; c0 += 1)
    for (c1 = c0 + 1832; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1832+c0] + S[-c0+c1-1832+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1831+c0] + S[1831+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 167; c0 += 1)
    S[c0][c0+1832] = MAX(S[c0][c0+1832], S[c0+1][c0+1832-1] + can_pair(RNA, c0, c0+1832));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 166; c0 += 1)
    for (c1 = c0 + 1833; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1833+c0] + S[-c0+c1-1833+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1832+c0] + S[1832+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 166; c0 += 1)
    S[c0][c0+1833] = MAX(S[c0][c0+1833], S[c0+1][c0+1833-1] + can_pair(RNA, c0, c0+1833));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 165; c0 += 1)
    for (c1 = c0 + 1834; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1834+c0] + S[-c0+c1-1834+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1833+c0] + S[1833+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 165; c0 += 1)
    S[c0][c0+1834] = MAX(S[c0][c0+1834], S[c0+1][c0+1834-1] + can_pair(RNA, c0, c0+1834));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 164; c0 += 1)
    for (c1 = c0 + 1835; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1835+c0] + S[-c0+c1-1835+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1834+c0] + S[1834+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 164; c0 += 1)
    S[c0][c0+1835] = MAX(S[c0][c0+1835], S[c0+1][c0+1835-1] + can_pair(RNA, c0, c0+1835));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 163; c0 += 1)
    for (c1 = c0 + 1836; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1836+c0] + S[-c0+c1-1836+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1835+c0] + S[1835+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 163; c0 += 1)
    S[c0][c0+1836] = MAX(S[c0][c0+1836], S[c0+1][c0+1836-1] + can_pair(RNA, c0, c0+1836));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 162; c0 += 1)
    for (c1 = c0 + 1837; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1837+c0] + S[-c0+c1-1837+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1836+c0] + S[1836+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 162; c0 += 1)
    S[c0][c0+1837] = MAX(S[c0][c0+1837], S[c0+1][c0+1837-1] + can_pair(RNA, c0, c0+1837));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 161; c0 += 1)
    for (c1 = c0 + 1838; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1838+c0] + S[-c0+c1-1838+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1837+c0] + S[1837+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 161; c0 += 1)
    S[c0][c0+1838] = MAX(S[c0][c0+1838], S[c0+1][c0+1838-1] + can_pair(RNA, c0, c0+1838));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 160; c0 += 1)
    for (c1 = c0 + 1839; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1839+c0] + S[-c0+c1-1839+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1838+c0] + S[1838+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 160; c0 += 1)
    S[c0][c0+1839] = MAX(S[c0][c0+1839], S[c0+1][c0+1839-1] + can_pair(RNA, c0, c0+1839));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 159; c0 += 1)
    for (c1 = c0 + 1840; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1840+c0] + S[-c0+c1-1840+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1839+c0] + S[1839+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 159; c0 += 1)
    S[c0][c0+1840] = MAX(S[c0][c0+1840], S[c0+1][c0+1840-1] + can_pair(RNA, c0, c0+1840));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 158; c0 += 1)
    for (c1 = c0 + 1841; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1841+c0] + S[-c0+c1-1841+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1840+c0] + S[1840+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 158; c0 += 1)
    S[c0][c0+1841] = MAX(S[c0][c0+1841], S[c0+1][c0+1841-1] + can_pair(RNA, c0, c0+1841));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 157; c0 += 1)
    for (c1 = c0 + 1842; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1842+c0] + S[-c0+c1-1842+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1841+c0] + S[1841+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 157; c0 += 1)
    S[c0][c0+1842] = MAX(S[c0][c0+1842], S[c0+1][c0+1842-1] + can_pair(RNA, c0, c0+1842));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 156; c0 += 1)
    for (c1 = c0 + 1843; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1843+c0] + S[-c0+c1-1843+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1842+c0] + S[1842+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 156; c0 += 1)
    S[c0][c0+1843] = MAX(S[c0][c0+1843], S[c0+1][c0+1843-1] + can_pair(RNA, c0, c0+1843));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 155; c0 += 1)
    for (c1 = c0 + 1844; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1844+c0] + S[-c0+c1-1844+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1843+c0] + S[1843+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 155; c0 += 1)
    S[c0][c0+1844] = MAX(S[c0][c0+1844], S[c0+1][c0+1844-1] + can_pair(RNA, c0, c0+1844));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 154; c0 += 1)
    for (c1 = c0 + 1845; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1845+c0] + S[-c0+c1-1845+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1844+c0] + S[1844+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 154; c0 += 1)
    S[c0][c0+1845] = MAX(S[c0][c0+1845], S[c0+1][c0+1845-1] + can_pair(RNA, c0, c0+1845));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 153; c0 += 1)
    for (c1 = c0 + 1846; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1846+c0] + S[-c0+c1-1846+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1845+c0] + S[1845+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 153; c0 += 1)
    S[c0][c0+1846] = MAX(S[c0][c0+1846], S[c0+1][c0+1846-1] + can_pair(RNA, c0, c0+1846));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 152; c0 += 1)
    for (c1 = c0 + 1847; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1847+c0] + S[-c0+c1-1847+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1846+c0] + S[1846+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 152; c0 += 1)
    S[c0][c0+1847] = MAX(S[c0][c0+1847], S[c0+1][c0+1847-1] + can_pair(RNA, c0, c0+1847));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 151; c0 += 1)
    for (c1 = c0 + 1848; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1848+c0] + S[-c0+c1-1848+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1847+c0] + S[1847+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 151; c0 += 1)
    S[c0][c0+1848] = MAX(S[c0][c0+1848], S[c0+1][c0+1848-1] + can_pair(RNA, c0, c0+1848));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 150; c0 += 1)
    for (c1 = c0 + 1849; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1849+c0] + S[-c0+c1-1849+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1848+c0] + S[1848+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 150; c0 += 1)
    S[c0][c0+1849] = MAX(S[c0][c0+1849], S[c0+1][c0+1849-1] + can_pair(RNA, c0, c0+1849));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 149; c0 += 1)
    for (c1 = c0 + 1850; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1850+c0] + S[-c0+c1-1850+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1849+c0] + S[1849+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 149; c0 += 1)
    S[c0][c0+1850] = MAX(S[c0][c0+1850], S[c0+1][c0+1850-1] + can_pair(RNA, c0, c0+1850));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 148; c0 += 1)
    for (c1 = c0 + 1851; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1851+c0] + S[-c0+c1-1851+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1850+c0] + S[1850+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 148; c0 += 1)
    S[c0][c0+1851] = MAX(S[c0][c0+1851], S[c0+1][c0+1851-1] + can_pair(RNA, c0, c0+1851));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 147; c0 += 1)
    for (c1 = c0 + 1852; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1852+c0] + S[-c0+c1-1852+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1851+c0] + S[1851+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 147; c0 += 1)
    S[c0][c0+1852] = MAX(S[c0][c0+1852], S[c0+1][c0+1852-1] + can_pair(RNA, c0, c0+1852));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 146; c0 += 1)
    for (c1 = c0 + 1853; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1853+c0] + S[-c0+c1-1853+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1852+c0] + S[1852+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 146; c0 += 1)
    S[c0][c0+1853] = MAX(S[c0][c0+1853], S[c0+1][c0+1853-1] + can_pair(RNA, c0, c0+1853));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 145; c0 += 1)
    for (c1 = c0 + 1854; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1854+c0] + S[-c0+c1-1854+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1853+c0] + S[1853+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 145; c0 += 1)
    S[c0][c0+1854] = MAX(S[c0][c0+1854], S[c0+1][c0+1854-1] + can_pair(RNA, c0, c0+1854));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 144; c0 += 1)
    for (c1 = c0 + 1855; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1855+c0] + S[-c0+c1-1855+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1854+c0] + S[1854+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 144; c0 += 1)
    S[c0][c0+1855] = MAX(S[c0][c0+1855], S[c0+1][c0+1855-1] + can_pair(RNA, c0, c0+1855));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 143; c0 += 1)
    for (c1 = c0 + 1856; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1856+c0] + S[-c0+c1-1856+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1855+c0] + S[1855+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 143; c0 += 1)
    S[c0][c0+1856] = MAX(S[c0][c0+1856], S[c0+1][c0+1856-1] + can_pair(RNA, c0, c0+1856));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 142; c0 += 1)
    for (c1 = c0 + 1857; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1857+c0] + S[-c0+c1-1857+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1856+c0] + S[1856+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 142; c0 += 1)
    S[c0][c0+1857] = MAX(S[c0][c0+1857], S[c0+1][c0+1857-1] + can_pair(RNA, c0, c0+1857));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 141; c0 += 1)
    for (c1 = c0 + 1858; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1858+c0] + S[-c0+c1-1858+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1857+c0] + S[1857+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 141; c0 += 1)
    S[c0][c0+1858] = MAX(S[c0][c0+1858], S[c0+1][c0+1858-1] + can_pair(RNA, c0, c0+1858));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 140; c0 += 1)
    for (c1 = c0 + 1859; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1859+c0] + S[-c0+c1-1859+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1858+c0] + S[1858+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 140; c0 += 1)
    S[c0][c0+1859] = MAX(S[c0][c0+1859], S[c0+1][c0+1859-1] + can_pair(RNA, c0, c0+1859));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 139; c0 += 1)
    for (c1 = c0 + 1860; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1860+c0] + S[-c0+c1-1860+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1859+c0] + S[1859+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 139; c0 += 1)
    S[c0][c0+1860] = MAX(S[c0][c0+1860], S[c0+1][c0+1860-1] + can_pair(RNA, c0, c0+1860));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 138; c0 += 1)
    for (c1 = c0 + 1861; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1861+c0] + S[-c0+c1-1861+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1860+c0] + S[1860+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 138; c0 += 1)
    S[c0][c0+1861] = MAX(S[c0][c0+1861], S[c0+1][c0+1861-1] + can_pair(RNA, c0, c0+1861));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 137; c0 += 1)
    for (c1 = c0 + 1862; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1862+c0] + S[-c0+c1-1862+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1861+c0] + S[1861+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 137; c0 += 1)
    S[c0][c0+1862] = MAX(S[c0][c0+1862], S[c0+1][c0+1862-1] + can_pair(RNA, c0, c0+1862));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 136; c0 += 1)
    for (c1 = c0 + 1863; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1863+c0] + S[-c0+c1-1863+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1862+c0] + S[1862+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 136; c0 += 1)
    S[c0][c0+1863] = MAX(S[c0][c0+1863], S[c0+1][c0+1863-1] + can_pair(RNA, c0, c0+1863));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 135; c0 += 1)
    for (c1 = c0 + 1864; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1864+c0] + S[-c0+c1-1864+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1863+c0] + S[1863+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 135; c0 += 1)
    S[c0][c0+1864] = MAX(S[c0][c0+1864], S[c0+1][c0+1864-1] + can_pair(RNA, c0, c0+1864));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 134; c0 += 1)
    for (c1 = c0 + 1865; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1865+c0] + S[-c0+c1-1865+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1864+c0] + S[1864+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 134; c0 += 1)
    S[c0][c0+1865] = MAX(S[c0][c0+1865], S[c0+1][c0+1865-1] + can_pair(RNA, c0, c0+1865));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 133; c0 += 1)
    for (c1 = c0 + 1866; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1866+c0] + S[-c0+c1-1866+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1865+c0] + S[1865+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 133; c0 += 1)
    S[c0][c0+1866] = MAX(S[c0][c0+1866], S[c0+1][c0+1866-1] + can_pair(RNA, c0, c0+1866));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 132; c0 += 1)
    for (c1 = c0 + 1867; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1867+c0] + S[-c0+c1-1867+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1866+c0] + S[1866+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 132; c0 += 1)
    S[c0][c0+1867] = MAX(S[c0][c0+1867], S[c0+1][c0+1867-1] + can_pair(RNA, c0, c0+1867));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 131; c0 += 1)
    for (c1 = c0 + 1868; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1868+c0] + S[-c0+c1-1868+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1867+c0] + S[1867+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 131; c0 += 1)
    S[c0][c0+1868] = MAX(S[c0][c0+1868], S[c0+1][c0+1868-1] + can_pair(RNA, c0, c0+1868));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 130; c0 += 1)
    for (c1 = c0 + 1869; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1869+c0] + S[-c0+c1-1869+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1868+c0] + S[1868+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 130; c0 += 1)
    S[c0][c0+1869] = MAX(S[c0][c0+1869], S[c0+1][c0+1869-1] + can_pair(RNA, c0, c0+1869));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 129; c0 += 1)
    for (c1 = c0 + 1870; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1870+c0] + S[-c0+c1-1870+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1869+c0] + S[1869+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 129; c0 += 1)
    S[c0][c0+1870] = MAX(S[c0][c0+1870], S[c0+1][c0+1870-1] + can_pair(RNA, c0, c0+1870));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 128; c0 += 1)
    for (c1 = c0 + 1871; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1871+c0] + S[-c0+c1-1871+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1870+c0] + S[1870+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 128; c0 += 1)
    S[c0][c0+1871] = MAX(S[c0][c0+1871], S[c0+1][c0+1871-1] + can_pair(RNA, c0, c0+1871));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 127; c0 += 1)
    for (c1 = c0 + 1872; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1872+c0] + S[-c0+c1-1872+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1871+c0] + S[1871+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 127; c0 += 1)
    S[c0][c0+1872] = MAX(S[c0][c0+1872], S[c0+1][c0+1872-1] + can_pair(RNA, c0, c0+1872));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 126; c0 += 1)
    for (c1 = c0 + 1873; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1873+c0] + S[-c0+c1-1873+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1872+c0] + S[1872+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 126; c0 += 1)
    S[c0][c0+1873] = MAX(S[c0][c0+1873], S[c0+1][c0+1873-1] + can_pair(RNA, c0, c0+1873));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 125; c0 += 1)
    for (c1 = c0 + 1874; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1874+c0] + S[-c0+c1-1874+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1873+c0] + S[1873+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 125; c0 += 1)
    S[c0][c0+1874] = MAX(S[c0][c0+1874], S[c0+1][c0+1874-1] + can_pair(RNA, c0, c0+1874));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 124; c0 += 1)
    for (c1 = c0 + 1875; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1875+c0] + S[-c0+c1-1875+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1874+c0] + S[1874+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 124; c0 += 1)
    S[c0][c0+1875] = MAX(S[c0][c0+1875], S[c0+1][c0+1875-1] + can_pair(RNA, c0, c0+1875));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 123; c0 += 1)
    for (c1 = c0 + 1876; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1876+c0] + S[-c0+c1-1876+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1875+c0] + S[1875+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 123; c0 += 1)
    S[c0][c0+1876] = MAX(S[c0][c0+1876], S[c0+1][c0+1876-1] + can_pair(RNA, c0, c0+1876));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 122; c0 += 1)
    for (c1 = c0 + 1877; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1877+c0] + S[-c0+c1-1877+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1876+c0] + S[1876+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 122; c0 += 1)
    S[c0][c0+1877] = MAX(S[c0][c0+1877], S[c0+1][c0+1877-1] + can_pair(RNA, c0, c0+1877));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 121; c0 += 1)
    for (c1 = c0 + 1878; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1878+c0] + S[-c0+c1-1878+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1877+c0] + S[1877+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 121; c0 += 1)
    S[c0][c0+1878] = MAX(S[c0][c0+1878], S[c0+1][c0+1878-1] + can_pair(RNA, c0, c0+1878));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 120; c0 += 1)
    for (c1 = c0 + 1879; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1879+c0] + S[-c0+c1-1879+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1878+c0] + S[1878+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 120; c0 += 1)
    S[c0][c0+1879] = MAX(S[c0][c0+1879], S[c0+1][c0+1879-1] + can_pair(RNA, c0, c0+1879));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 119; c0 += 1)
    for (c1 = c0 + 1880; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1880+c0] + S[-c0+c1-1880+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1879+c0] + S[1879+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 119; c0 += 1)
    S[c0][c0+1880] = MAX(S[c0][c0+1880], S[c0+1][c0+1880-1] + can_pair(RNA, c0, c0+1880));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 118; c0 += 1)
    for (c1 = c0 + 1881; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1881+c0] + S[-c0+c1-1881+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1880+c0] + S[1880+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 118; c0 += 1)
    S[c0][c0+1881] = MAX(S[c0][c0+1881], S[c0+1][c0+1881-1] + can_pair(RNA, c0, c0+1881));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 117; c0 += 1)
    for (c1 = c0 + 1882; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1882+c0] + S[-c0+c1-1882+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1881+c0] + S[1881+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 117; c0 += 1)
    S[c0][c0+1882] = MAX(S[c0][c0+1882], S[c0+1][c0+1882-1] + can_pair(RNA, c0, c0+1882));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 116; c0 += 1)
    for (c1 = c0 + 1883; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1883+c0] + S[-c0+c1-1883+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1882+c0] + S[1882+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 116; c0 += 1)
    S[c0][c0+1883] = MAX(S[c0][c0+1883], S[c0+1][c0+1883-1] + can_pair(RNA, c0, c0+1883));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 115; c0 += 1)
    for (c1 = c0 + 1884; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1884+c0] + S[-c0+c1-1884+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1883+c0] + S[1883+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 115; c0 += 1)
    S[c0][c0+1884] = MAX(S[c0][c0+1884], S[c0+1][c0+1884-1] + can_pair(RNA, c0, c0+1884));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 114; c0 += 1)
    for (c1 = c0 + 1885; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1885+c0] + S[-c0+c1-1885+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1884+c0] + S[1884+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 114; c0 += 1)
    S[c0][c0+1885] = MAX(S[c0][c0+1885], S[c0+1][c0+1885-1] + can_pair(RNA, c0, c0+1885));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 113; c0 += 1)
    for (c1 = c0 + 1886; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1886+c0] + S[-c0+c1-1886+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1885+c0] + S[1885+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 113; c0 += 1)
    S[c0][c0+1886] = MAX(S[c0][c0+1886], S[c0+1][c0+1886-1] + can_pair(RNA, c0, c0+1886));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 112; c0 += 1)
    for (c1 = c0 + 1887; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1887+c0] + S[-c0+c1-1887+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1886+c0] + S[1886+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 112; c0 += 1)
    S[c0][c0+1887] = MAX(S[c0][c0+1887], S[c0+1][c0+1887-1] + can_pair(RNA, c0, c0+1887));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 111; c0 += 1)
    for (c1 = c0 + 1888; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1888+c0] + S[-c0+c1-1888+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1887+c0] + S[1887+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 111; c0 += 1)
    S[c0][c0+1888] = MAX(S[c0][c0+1888], S[c0+1][c0+1888-1] + can_pair(RNA, c0, c0+1888));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 110; c0 += 1)
    for (c1 = c0 + 1889; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1889+c0] + S[-c0+c1-1889+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1888+c0] + S[1888+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 110; c0 += 1)
    S[c0][c0+1889] = MAX(S[c0][c0+1889], S[c0+1][c0+1889-1] + can_pair(RNA, c0, c0+1889));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 109; c0 += 1)
    for (c1 = c0 + 1890; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1890+c0] + S[-c0+c1-1890+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1889+c0] + S[1889+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 109; c0 += 1)
    S[c0][c0+1890] = MAX(S[c0][c0+1890], S[c0+1][c0+1890-1] + can_pair(RNA, c0, c0+1890));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 108; c0 += 1)
    for (c1 = c0 + 1891; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1891+c0] + S[-c0+c1-1891+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1890+c0] + S[1890+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 108; c0 += 1)
    S[c0][c0+1891] = MAX(S[c0][c0+1891], S[c0+1][c0+1891-1] + can_pair(RNA, c0, c0+1891));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 107; c0 += 1)
    for (c1 = c0 + 1892; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1892+c0] + S[-c0+c1-1892+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1891+c0] + S[1891+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 107; c0 += 1)
    S[c0][c0+1892] = MAX(S[c0][c0+1892], S[c0+1][c0+1892-1] + can_pair(RNA, c0, c0+1892));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 106; c0 += 1)
    for (c1 = c0 + 1893; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1893+c0] + S[-c0+c1-1893+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1892+c0] + S[1892+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 106; c0 += 1)
    S[c0][c0+1893] = MAX(S[c0][c0+1893], S[c0+1][c0+1893-1] + can_pair(RNA, c0, c0+1893));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 105; c0 += 1)
    for (c1 = c0 + 1894; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1894+c0] + S[-c0+c1-1894+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1893+c0] + S[1893+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 105; c0 += 1)
    S[c0][c0+1894] = MAX(S[c0][c0+1894], S[c0+1][c0+1894-1] + can_pair(RNA, c0, c0+1894));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 104; c0 += 1)
    for (c1 = c0 + 1895; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1895+c0] + S[-c0+c1-1895+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1894+c0] + S[1894+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 104; c0 += 1)
    S[c0][c0+1895] = MAX(S[c0][c0+1895], S[c0+1][c0+1895-1] + can_pair(RNA, c0, c0+1895));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 103; c0 += 1)
    for (c1 = c0 + 1896; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1896+c0] + S[-c0+c1-1896+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1895+c0] + S[1895+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 103; c0 += 1)
    S[c0][c0+1896] = MAX(S[c0][c0+1896], S[c0+1][c0+1896-1] + can_pair(RNA, c0, c0+1896));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 102; c0 += 1)
    for (c1 = c0 + 1897; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1897+c0] + S[-c0+c1-1897+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1896+c0] + S[1896+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 102; c0 += 1)
    S[c0][c0+1897] = MAX(S[c0][c0+1897], S[c0+1][c0+1897-1] + can_pair(RNA, c0, c0+1897));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 101; c0 += 1)
    for (c1 = c0 + 1898; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1898+c0] + S[-c0+c1-1898+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1897+c0] + S[1897+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 101; c0 += 1)
    S[c0][c0+1898] = MAX(S[c0][c0+1898], S[c0+1][c0+1898-1] + can_pair(RNA, c0, c0+1898));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 100; c0 += 1)
    for (c1 = c0 + 1899; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1899+c0] + S[-c0+c1-1899+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1898+c0] + S[1898+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 100; c0 += 1)
    S[c0][c0+1899] = MAX(S[c0][c0+1899], S[c0+1][c0+1899-1] + can_pair(RNA, c0, c0+1899));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 99; c0 += 1)
    for (c1 = c0 + 1900; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1900+c0] + S[-c0+c1-1900+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1899+c0] + S[1899+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 99; c0 += 1)
    S[c0][c0+1900] = MAX(S[c0][c0+1900], S[c0+1][c0+1900-1] + can_pair(RNA, c0, c0+1900));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 98; c0 += 1)
    for (c1 = c0 + 1901; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1901+c0] + S[-c0+c1-1901+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1900+c0] + S[1900+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 98; c0 += 1)
    S[c0][c0+1901] = MAX(S[c0][c0+1901], S[c0+1][c0+1901-1] + can_pair(RNA, c0, c0+1901));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 97; c0 += 1)
    for (c1 = c0 + 1902; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1902+c0] + S[-c0+c1-1902+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1901+c0] + S[1901+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 97; c0 += 1)
    S[c0][c0+1902] = MAX(S[c0][c0+1902], S[c0+1][c0+1902-1] + can_pair(RNA, c0, c0+1902));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 96; c0 += 1)
    for (c1 = c0 + 1903; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1903+c0] + S[-c0+c1-1903+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1902+c0] + S[1902+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 96; c0 += 1)
    S[c0][c0+1903] = MAX(S[c0][c0+1903], S[c0+1][c0+1903-1] + can_pair(RNA, c0, c0+1903));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 95; c0 += 1)
    for (c1 = c0 + 1904; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1904+c0] + S[-c0+c1-1904+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1903+c0] + S[1903+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 95; c0 += 1)
    S[c0][c0+1904] = MAX(S[c0][c0+1904], S[c0+1][c0+1904-1] + can_pair(RNA, c0, c0+1904));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 94; c0 += 1)
    for (c1 = c0 + 1905; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1905+c0] + S[-c0+c1-1905+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1904+c0] + S[1904+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 94; c0 += 1)
    S[c0][c0+1905] = MAX(S[c0][c0+1905], S[c0+1][c0+1905-1] + can_pair(RNA, c0, c0+1905));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 93; c0 += 1)
    for (c1 = c0 + 1906; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1906+c0] + S[-c0+c1-1906+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1905+c0] + S[1905+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 93; c0 += 1)
    S[c0][c0+1906] = MAX(S[c0][c0+1906], S[c0+1][c0+1906-1] + can_pair(RNA, c0, c0+1906));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 92; c0 += 1)
    for (c1 = c0 + 1907; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1907+c0] + S[-c0+c1-1907+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1906+c0] + S[1906+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 92; c0 += 1)
    S[c0][c0+1907] = MAX(S[c0][c0+1907], S[c0+1][c0+1907-1] + can_pair(RNA, c0, c0+1907));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 91; c0 += 1)
    for (c1 = c0 + 1908; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1908+c0] + S[-c0+c1-1908+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1907+c0] + S[1907+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 91; c0 += 1)
    S[c0][c0+1908] = MAX(S[c0][c0+1908], S[c0+1][c0+1908-1] + can_pair(RNA, c0, c0+1908));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 90; c0 += 1)
    for (c1 = c0 + 1909; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1909+c0] + S[-c0+c1-1909+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1908+c0] + S[1908+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 90; c0 += 1)
    S[c0][c0+1909] = MAX(S[c0][c0+1909], S[c0+1][c0+1909-1] + can_pair(RNA, c0, c0+1909));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 89; c0 += 1)
    for (c1 = c0 + 1910; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1910+c0] + S[-c0+c1-1910+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1909+c0] + S[1909+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 89; c0 += 1)
    S[c0][c0+1910] = MAX(S[c0][c0+1910], S[c0+1][c0+1910-1] + can_pair(RNA, c0, c0+1910));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 88; c0 += 1)
    for (c1 = c0 + 1911; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1911+c0] + S[-c0+c1-1911+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1910+c0] + S[1910+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 88; c0 += 1)
    S[c0][c0+1911] = MAX(S[c0][c0+1911], S[c0+1][c0+1911-1] + can_pair(RNA, c0, c0+1911));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 87; c0 += 1)
    for (c1 = c0 + 1912; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1912+c0] + S[-c0+c1-1912+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1911+c0] + S[1911+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 87; c0 += 1)
    S[c0][c0+1912] = MAX(S[c0][c0+1912], S[c0+1][c0+1912-1] + can_pair(RNA, c0, c0+1912));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 86; c0 += 1)
    for (c1 = c0 + 1913; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1913+c0] + S[-c0+c1-1913+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1912+c0] + S[1912+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 86; c0 += 1)
    S[c0][c0+1913] = MAX(S[c0][c0+1913], S[c0+1][c0+1913-1] + can_pair(RNA, c0, c0+1913));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 85; c0 += 1)
    for (c1 = c0 + 1914; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1914+c0] + S[-c0+c1-1914+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1913+c0] + S[1913+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 85; c0 += 1)
    S[c0][c0+1914] = MAX(S[c0][c0+1914], S[c0+1][c0+1914-1] + can_pair(RNA, c0, c0+1914));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 84; c0 += 1)
    for (c1 = c0 + 1915; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1915+c0] + S[-c0+c1-1915+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1914+c0] + S[1914+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 84; c0 += 1)
    S[c0][c0+1915] = MAX(S[c0][c0+1915], S[c0+1][c0+1915-1] + can_pair(RNA, c0, c0+1915));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 83; c0 += 1)
    for (c1 = c0 + 1916; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1916+c0] + S[-c0+c1-1916+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1915+c0] + S[1915+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 83; c0 += 1)
    S[c0][c0+1916] = MAX(S[c0][c0+1916], S[c0+1][c0+1916-1] + can_pair(RNA, c0, c0+1916));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 82; c0 += 1)
    for (c1 = c0 + 1917; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1917+c0] + S[-c0+c1-1917+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1916+c0] + S[1916+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 82; c0 += 1)
    S[c0][c0+1917] = MAX(S[c0][c0+1917], S[c0+1][c0+1917-1] + can_pair(RNA, c0, c0+1917));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 81; c0 += 1)
    for (c1 = c0 + 1918; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1918+c0] + S[-c0+c1-1918+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1917+c0] + S[1917+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 81; c0 += 1)
    S[c0][c0+1918] = MAX(S[c0][c0+1918], S[c0+1][c0+1918-1] + can_pair(RNA, c0, c0+1918));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 80; c0 += 1)
    for (c1 = c0 + 1919; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1919+c0] + S[-c0+c1-1919+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1918+c0] + S[1918+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 80; c0 += 1)
    S[c0][c0+1919] = MAX(S[c0][c0+1919], S[c0+1][c0+1919-1] + can_pair(RNA, c0, c0+1919));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 79; c0 += 1)
    for (c1 = c0 + 1920; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1920+c0] + S[-c0+c1-1920+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1919+c0] + S[1919+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 79; c0 += 1)
    S[c0][c0+1920] = MAX(S[c0][c0+1920], S[c0+1][c0+1920-1] + can_pair(RNA, c0, c0+1920));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 78; c0 += 1)
    for (c1 = c0 + 1921; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1921+c0] + S[-c0+c1-1921+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1920+c0] + S[1920+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 78; c0 += 1)
    S[c0][c0+1921] = MAX(S[c0][c0+1921], S[c0+1][c0+1921-1] + can_pair(RNA, c0, c0+1921));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 77; c0 += 1)
    for (c1 = c0 + 1922; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1922+c0] + S[-c0+c1-1922+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1921+c0] + S[1921+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 77; c0 += 1)
    S[c0][c0+1922] = MAX(S[c0][c0+1922], S[c0+1][c0+1922-1] + can_pair(RNA, c0, c0+1922));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 76; c0 += 1)
    for (c1 = c0 + 1923; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1923+c0] + S[-c0+c1-1923+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1922+c0] + S[1922+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 76; c0 += 1)
    S[c0][c0+1923] = MAX(S[c0][c0+1923], S[c0+1][c0+1923-1] + can_pair(RNA, c0, c0+1923));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 75; c0 += 1)
    for (c1 = c0 + 1924; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1924+c0] + S[-c0+c1-1924+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1923+c0] + S[1923+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 75; c0 += 1)
    S[c0][c0+1924] = MAX(S[c0][c0+1924], S[c0+1][c0+1924-1] + can_pair(RNA, c0, c0+1924));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 74; c0 += 1)
    for (c1 = c0 + 1925; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1925+c0] + S[-c0+c1-1925+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1924+c0] + S[1924+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 74; c0 += 1)
    S[c0][c0+1925] = MAX(S[c0][c0+1925], S[c0+1][c0+1925-1] + can_pair(RNA, c0, c0+1925));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 73; c0 += 1)
    for (c1 = c0 + 1926; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1926+c0] + S[-c0+c1-1926+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1925+c0] + S[1925+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 73; c0 += 1)
    S[c0][c0+1926] = MAX(S[c0][c0+1926], S[c0+1][c0+1926-1] + can_pair(RNA, c0, c0+1926));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 72; c0 += 1)
    for (c1 = c0 + 1927; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1927+c0] + S[-c0+c1-1927+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1926+c0] + S[1926+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 72; c0 += 1)
    S[c0][c0+1927] = MAX(S[c0][c0+1927], S[c0+1][c0+1927-1] + can_pair(RNA, c0, c0+1927));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 71; c0 += 1)
    for (c1 = c0 + 1928; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1928+c0] + S[-c0+c1-1928+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1927+c0] + S[1927+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 71; c0 += 1)
    S[c0][c0+1928] = MAX(S[c0][c0+1928], S[c0+1][c0+1928-1] + can_pair(RNA, c0, c0+1928));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 70; c0 += 1)
    for (c1 = c0 + 1929; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1929+c0] + S[-c0+c1-1929+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1928+c0] + S[1928+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 70; c0 += 1)
    S[c0][c0+1929] = MAX(S[c0][c0+1929], S[c0+1][c0+1929-1] + can_pair(RNA, c0, c0+1929));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 69; c0 += 1)
    for (c1 = c0 + 1930; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1930+c0] + S[-c0+c1-1930+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1929+c0] + S[1929+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 69; c0 += 1)
    S[c0][c0+1930] = MAX(S[c0][c0+1930], S[c0+1][c0+1930-1] + can_pair(RNA, c0, c0+1930));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 68; c0 += 1)
    for (c1 = c0 + 1931; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1931+c0] + S[-c0+c1-1931+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1930+c0] + S[1930+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 68; c0 += 1)
    S[c0][c0+1931] = MAX(S[c0][c0+1931], S[c0+1][c0+1931-1] + can_pair(RNA, c0, c0+1931));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 67; c0 += 1)
    for (c1 = c0 + 1932; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1932+c0] + S[-c0+c1-1932+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1931+c0] + S[1931+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 67; c0 += 1)
    S[c0][c0+1932] = MAX(S[c0][c0+1932], S[c0+1][c0+1932-1] + can_pair(RNA, c0, c0+1932));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 66; c0 += 1)
    for (c1 = c0 + 1933; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1933+c0] + S[-c0+c1-1933+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1932+c0] + S[1932+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 66; c0 += 1)
    S[c0][c0+1933] = MAX(S[c0][c0+1933], S[c0+1][c0+1933-1] + can_pair(RNA, c0, c0+1933));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 65; c0 += 1)
    for (c1 = c0 + 1934; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1934+c0] + S[-c0+c1-1934+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1933+c0] + S[1933+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 65; c0 += 1)
    S[c0][c0+1934] = MAX(S[c0][c0+1934], S[c0+1][c0+1934-1] + can_pair(RNA, c0, c0+1934));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 64; c0 += 1)
    for (c1 = c0 + 1935; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1935+c0] + S[-c0+c1-1935+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1934+c0] + S[1934+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 64; c0 += 1)
    S[c0][c0+1935] = MAX(S[c0][c0+1935], S[c0+1][c0+1935-1] + can_pair(RNA, c0, c0+1935));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 63; c0 += 1)
    for (c1 = c0 + 1936; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1936+c0] + S[-c0+c1-1936+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1935+c0] + S[1935+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 63; c0 += 1)
    S[c0][c0+1936] = MAX(S[c0][c0+1936], S[c0+1][c0+1936-1] + can_pair(RNA, c0, c0+1936));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 62; c0 += 1)
    for (c1 = c0 + 1937; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1937+c0] + S[-c0+c1-1937+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1936+c0] + S[1936+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 62; c0 += 1)
    S[c0][c0+1937] = MAX(S[c0][c0+1937], S[c0+1][c0+1937-1] + can_pair(RNA, c0, c0+1937));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 61; c0 += 1)
    for (c1 = c0 + 1938; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1938+c0] + S[-c0+c1-1938+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1937+c0] + S[1937+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 61; c0 += 1)
    S[c0][c0+1938] = MAX(S[c0][c0+1938], S[c0+1][c0+1938-1] + can_pair(RNA, c0, c0+1938));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 60; c0 += 1)
    for (c1 = c0 + 1939; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1939+c0] + S[-c0+c1-1939+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1938+c0] + S[1938+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 60; c0 += 1)
    S[c0][c0+1939] = MAX(S[c0][c0+1939], S[c0+1][c0+1939-1] + can_pair(RNA, c0, c0+1939));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 59; c0 += 1)
    for (c1 = c0 + 1940; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1940+c0] + S[-c0+c1-1940+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1939+c0] + S[1939+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 59; c0 += 1)
    S[c0][c0+1940] = MAX(S[c0][c0+1940], S[c0+1][c0+1940-1] + can_pair(RNA, c0, c0+1940));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 58; c0 += 1)
    for (c1 = c0 + 1941; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1941+c0] + S[-c0+c1-1941+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1940+c0] + S[1940+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 58; c0 += 1)
    S[c0][c0+1941] = MAX(S[c0][c0+1941], S[c0+1][c0+1941-1] + can_pair(RNA, c0, c0+1941));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 57; c0 += 1)
    for (c1 = c0 + 1942; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1942+c0] + S[-c0+c1-1942+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1941+c0] + S[1941+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 57; c0 += 1)
    S[c0][c0+1942] = MAX(S[c0][c0+1942], S[c0+1][c0+1942-1] + can_pair(RNA, c0, c0+1942));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 56; c0 += 1)
    for (c1 = c0 + 1943; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1943+c0] + S[-c0+c1-1943+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1942+c0] + S[1942+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 56; c0 += 1)
    S[c0][c0+1943] = MAX(S[c0][c0+1943], S[c0+1][c0+1943-1] + can_pair(RNA, c0, c0+1943));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 55; c0 += 1)
    for (c1 = c0 + 1944; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1944+c0] + S[-c0+c1-1944+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1943+c0] + S[1943+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 55; c0 += 1)
    S[c0][c0+1944] = MAX(S[c0][c0+1944], S[c0+1][c0+1944-1] + can_pair(RNA, c0, c0+1944));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 54; c0 += 1)
    for (c1 = c0 + 1945; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1945+c0] + S[-c0+c1-1945+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1944+c0] + S[1944+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 54; c0 += 1)
    S[c0][c0+1945] = MAX(S[c0][c0+1945], S[c0+1][c0+1945-1] + can_pair(RNA, c0, c0+1945));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 53; c0 += 1)
    for (c1 = c0 + 1946; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1946+c0] + S[-c0+c1-1946+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1945+c0] + S[1945+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 53; c0 += 1)
    S[c0][c0+1946] = MAX(S[c0][c0+1946], S[c0+1][c0+1946-1] + can_pair(RNA, c0, c0+1946));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 52; c0 += 1)
    for (c1 = c0 + 1947; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1947+c0] + S[-c0+c1-1947+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1946+c0] + S[1946+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 52; c0 += 1)
    S[c0][c0+1947] = MAX(S[c0][c0+1947], S[c0+1][c0+1947-1] + can_pair(RNA, c0, c0+1947));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 51; c0 += 1)
    for (c1 = c0 + 1948; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1948+c0] + S[-c0+c1-1948+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1947+c0] + S[1947+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 51; c0 += 1)
    S[c0][c0+1948] = MAX(S[c0][c0+1948], S[c0+1][c0+1948-1] + can_pair(RNA, c0, c0+1948));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 50; c0 += 1)
    for (c1 = c0 + 1949; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1949+c0] + S[-c0+c1-1949+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1948+c0] + S[1948+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 50; c0 += 1)
    S[c0][c0+1949] = MAX(S[c0][c0+1949], S[c0+1][c0+1949-1] + can_pair(RNA, c0, c0+1949));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 49; c0 += 1)
    for (c1 = c0 + 1950; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1950+c0] + S[-c0+c1-1950+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1949+c0] + S[1949+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 49; c0 += 1)
    S[c0][c0+1950] = MAX(S[c0][c0+1950], S[c0+1][c0+1950-1] + can_pair(RNA, c0, c0+1950));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 48; c0 += 1)
    for (c1 = c0 + 1951; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1951+c0] + S[-c0+c1-1951+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1950+c0] + S[1950+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 48; c0 += 1)
    S[c0][c0+1951] = MAX(S[c0][c0+1951], S[c0+1][c0+1951-1] + can_pair(RNA, c0, c0+1951));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 47; c0 += 1)
    for (c1 = c0 + 1952; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1952+c0] + S[-c0+c1-1952+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1951+c0] + S[1951+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 47; c0 += 1)
    S[c0][c0+1952] = MAX(S[c0][c0+1952], S[c0+1][c0+1952-1] + can_pair(RNA, c0, c0+1952));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 46; c0 += 1)
    for (c1 = c0 + 1953; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1953+c0] + S[-c0+c1-1953+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1952+c0] + S[1952+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 46; c0 += 1)
    S[c0][c0+1953] = MAX(S[c0][c0+1953], S[c0+1][c0+1953-1] + can_pair(RNA, c0, c0+1953));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 45; c0 += 1)
    for (c1 = c0 + 1954; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1954+c0] + S[-c0+c1-1954+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1953+c0] + S[1953+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 45; c0 += 1)
    S[c0][c0+1954] = MAX(S[c0][c0+1954], S[c0+1][c0+1954-1] + can_pair(RNA, c0, c0+1954));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 44; c0 += 1)
    for (c1 = c0 + 1955; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1955+c0] + S[-c0+c1-1955+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1954+c0] + S[1954+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 44; c0 += 1)
    S[c0][c0+1955] = MAX(S[c0][c0+1955], S[c0+1][c0+1955-1] + can_pair(RNA, c0, c0+1955));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 43; c0 += 1)
    for (c1 = c0 + 1956; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1956+c0] + S[-c0+c1-1956+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1955+c0] + S[1955+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 43; c0 += 1)
    S[c0][c0+1956] = MAX(S[c0][c0+1956], S[c0+1][c0+1956-1] + can_pair(RNA, c0, c0+1956));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 42; c0 += 1)
    for (c1 = c0 + 1957; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1957+c0] + S[-c0+c1-1957+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1956+c0] + S[1956+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 42; c0 += 1)
    S[c0][c0+1957] = MAX(S[c0][c0+1957], S[c0+1][c0+1957-1] + can_pair(RNA, c0, c0+1957));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 41; c0 += 1)
    for (c1 = c0 + 1958; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1958+c0] + S[-c0+c1-1958+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1957+c0] + S[1957+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 41; c0 += 1)
    S[c0][c0+1958] = MAX(S[c0][c0+1958], S[c0+1][c0+1958-1] + can_pair(RNA, c0, c0+1958));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 40; c0 += 1)
    for (c1 = c0 + 1959; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1959+c0] + S[-c0+c1-1959+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1958+c0] + S[1958+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 40; c0 += 1)
    S[c0][c0+1959] = MAX(S[c0][c0+1959], S[c0+1][c0+1959-1] + can_pair(RNA, c0, c0+1959));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 39; c0 += 1)
    for (c1 = c0 + 1960; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1960+c0] + S[-c0+c1-1960+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1959+c0] + S[1959+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 39; c0 += 1)
    S[c0][c0+1960] = MAX(S[c0][c0+1960], S[c0+1][c0+1960-1] + can_pair(RNA, c0, c0+1960));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 38; c0 += 1)
    for (c1 = c0 + 1961; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1961+c0] + S[-c0+c1-1961+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1960+c0] + S[1960+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 38; c0 += 1)
    S[c0][c0+1961] = MAX(S[c0][c0+1961], S[c0+1][c0+1961-1] + can_pair(RNA, c0, c0+1961));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 37; c0 += 1)
    for (c1 = c0 + 1962; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1962+c0] + S[-c0+c1-1962+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1961+c0] + S[1961+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 37; c0 += 1)
    S[c0][c0+1962] = MAX(S[c0][c0+1962], S[c0+1][c0+1962-1] + can_pair(RNA, c0, c0+1962));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 36; c0 += 1)
    for (c1 = c0 + 1963; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1963+c0] + S[-c0+c1-1963+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1962+c0] + S[1962+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 36; c0 += 1)
    S[c0][c0+1963] = MAX(S[c0][c0+1963], S[c0+1][c0+1963-1] + can_pair(RNA, c0, c0+1963));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 35; c0 += 1)
    for (c1 = c0 + 1964; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1964+c0] + S[-c0+c1-1964+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1963+c0] + S[1963+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 35; c0 += 1)
    S[c0][c0+1964] = MAX(S[c0][c0+1964], S[c0+1][c0+1964-1] + can_pair(RNA, c0, c0+1964));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 34; c0 += 1)
    for (c1 = c0 + 1965; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1965+c0] + S[-c0+c1-1965+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1964+c0] + S[1964+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 34; c0 += 1)
    S[c0][c0+1965] = MAX(S[c0][c0+1965], S[c0+1][c0+1965-1] + can_pair(RNA, c0, c0+1965));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 33; c0 += 1)
    for (c1 = c0 + 1966; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1966+c0] + S[-c0+c1-1966+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1965+c0] + S[1965+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 33; c0 += 1)
    S[c0][c0+1966] = MAX(S[c0][c0+1966], S[c0+1][c0+1966-1] + can_pair(RNA, c0, c0+1966));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 32; c0 += 1)
    for (c1 = c0 + 1967; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1967+c0] + S[-c0+c1-1967+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1966+c0] + S[1966+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 32; c0 += 1)
    S[c0][c0+1967] = MAX(S[c0][c0+1967], S[c0+1][c0+1967-1] + can_pair(RNA, c0, c0+1967));
}
// parallel -----
#pragma omp for
  for (c0 = 0; c0 <= 31; c0 += 1)
    for (c1 = c0 + 1968; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1968+c0] + S[-c0+c1-1968+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1967+c0] + S[1967+c0+1][c1], S[c0][c1]);
    }
// --------------
#pragma omp single
{
  for (c0 = 0; c0 <= 31; c0 += 1)
    S[c0][c0+1968] = MAX(S[c0][c0+1968], S[c0+1][c0+1968-1] + can_pair(RNA, c0, c0+1968));
// --------------
  for (c0 = 0; c0 <= 30; c0 += 1)
    for (c1 = c0 + 1969; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1969+c0] + S[-c0+c1-1969+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1968+c0] + S[1968+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 30; c0 += 1)
    S[c0][c0+1969] = MAX(S[c0][c0+1969], S[c0+1][c0+1969-1] + can_pair(RNA, c0, c0+1969));
// --------------
  for (c0 = 0; c0 <= 29; c0 += 1)
    for (c1 = c0 + 1970; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1970+c0] + S[-c0+c1-1970+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1969+c0] + S[1969+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 29; c0 += 1)
    S[c0][c0+1970] = MAX(S[c0][c0+1970], S[c0+1][c0+1970-1] + can_pair(RNA, c0, c0+1970));
// --------------
  for (c0 = 0; c0 <= 28; c0 += 1)
    for (c1 = c0 + 1971; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1971+c0] + S[-c0+c1-1971+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1970+c0] + S[1970+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 28; c0 += 1)
    S[c0][c0+1971] = MAX(S[c0][c0+1971], S[c0+1][c0+1971-1] + can_pair(RNA, c0, c0+1971));
// --------------
  for (c0 = 0; c0 <= 27; c0 += 1)
    for (c1 = c0 + 1972; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1972+c0] + S[-c0+c1-1972+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1971+c0] + S[1971+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 27; c0 += 1)
    S[c0][c0+1972] = MAX(S[c0][c0+1972], S[c0+1][c0+1972-1] + can_pair(RNA, c0, c0+1972));
// --------------
  for (c0 = 0; c0 <= 26; c0 += 1)
    for (c1 = c0 + 1973; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1973+c0] + S[-c0+c1-1973+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1972+c0] + S[1972+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 26; c0 += 1)
    S[c0][c0+1973] = MAX(S[c0][c0+1973], S[c0+1][c0+1973-1] + can_pair(RNA, c0, c0+1973));
// --------------
  for (c0 = 0; c0 <= 25; c0 += 1)
    for (c1 = c0 + 1974; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1974+c0] + S[-c0+c1-1974+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1973+c0] + S[1973+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 25; c0 += 1)
    S[c0][c0+1974] = MAX(S[c0][c0+1974], S[c0+1][c0+1974-1] + can_pair(RNA, c0, c0+1974));
// --------------
  for (c0 = 0; c0 <= 24; c0 += 1)
    for (c1 = c0 + 1975; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1975+c0] + S[-c0+c1-1975+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1974+c0] + S[1974+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 24; c0 += 1)
    S[c0][c0+1975] = MAX(S[c0][c0+1975], S[c0+1][c0+1975-1] + can_pair(RNA, c0, c0+1975));
// --------------
  for (c0 = 0; c0 <= 23; c0 += 1)
    for (c1 = c0 + 1976; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1976+c0] + S[-c0+c1-1976+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1975+c0] + S[1975+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 23; c0 += 1)
    S[c0][c0+1976] = MAX(S[c0][c0+1976], S[c0+1][c0+1976-1] + can_pair(RNA, c0, c0+1976));
// --------------
  for (c0 = 0; c0 <= 22; c0 += 1)
    for (c1 = c0 + 1977; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1977+c0] + S[-c0+c1-1977+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1976+c0] + S[1976+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 22; c0 += 1)
    S[c0][c0+1977] = MAX(S[c0][c0+1977], S[c0+1][c0+1977-1] + can_pair(RNA, c0, c0+1977));
// --------------
  for (c0 = 0; c0 <= 21; c0 += 1)
    for (c1 = c0 + 1978; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1978+c0] + S[-c0+c1-1978+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1977+c0] + S[1977+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 21; c0 += 1)
    S[c0][c0+1978] = MAX(S[c0][c0+1978], S[c0+1][c0+1978-1] + can_pair(RNA, c0, c0+1978));
// --------------
  for (c0 = 0; c0 <= 20; c0 += 1)
    for (c1 = c0 + 1979; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1979+c0] + S[-c0+c1-1979+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1978+c0] + S[1978+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 20; c0 += 1)
    S[c0][c0+1979] = MAX(S[c0][c0+1979], S[c0+1][c0+1979-1] + can_pair(RNA, c0, c0+1979));
// --------------
  for (c0 = 0; c0 <= 19; c0 += 1)
    for (c1 = c0 + 1980; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1980+c0] + S[-c0+c1-1980+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1979+c0] + S[1979+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 19; c0 += 1)
    S[c0][c0+1980] = MAX(S[c0][c0+1980], S[c0+1][c0+1980-1] + can_pair(RNA, c0, c0+1980));
// --------------
  for (c0 = 0; c0 <= 18; c0 += 1)
    for (c1 = c0 + 1981; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1981+c0] + S[-c0+c1-1981+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1980+c0] + S[1980+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 18; c0 += 1)
    S[c0][c0+1981] = MAX(S[c0][c0+1981], S[c0+1][c0+1981-1] + can_pair(RNA, c0, c0+1981));
// --------------
  for (c0 = 0; c0 <= 17; c0 += 1)
    for (c1 = c0 + 1982; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1982+c0] + S[-c0+c1-1982+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1981+c0] + S[1981+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 17; c0 += 1)
    S[c0][c0+1982] = MAX(S[c0][c0+1982], S[c0+1][c0+1982-1] + can_pair(RNA, c0, c0+1982));
// --------------
  for (c0 = 0; c0 <= 16; c0 += 1)
    for (c1 = c0 + 1983; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1983+c0] + S[-c0+c1-1983+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1982+c0] + S[1982+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 16; c0 += 1)
    S[c0][c0+1983] = MAX(S[c0][c0+1983], S[c0+1][c0+1983-1] + can_pair(RNA, c0, c0+1983));
// --------------
  for (c0 = 0; c0 <= 15; c0 += 1)
    for (c1 = c0 + 1984; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1984+c0] + S[-c0+c1-1984+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1983+c0] + S[1983+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 15; c0 += 1)
    S[c0][c0+1984] = MAX(S[c0][c0+1984], S[c0+1][c0+1984-1] + can_pair(RNA, c0, c0+1984));
// --------------
  for (c0 = 0; c0 <= 14; c0 += 1)
    for (c1 = c0 + 1985; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1985+c0] + S[-c0+c1-1985+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1984+c0] + S[1984+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 14; c0 += 1)
    S[c0][c0+1985] = MAX(S[c0][c0+1985], S[c0+1][c0+1985-1] + can_pair(RNA, c0, c0+1985));
// --------------
  for (c0 = 0; c0 <= 13; c0 += 1)
    for (c1 = c0 + 1986; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1986+c0] + S[-c0+c1-1986+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1985+c0] + S[1985+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 13; c0 += 1)
    S[c0][c0+1986] = MAX(S[c0][c0+1986], S[c0+1][c0+1986-1] + can_pair(RNA, c0, c0+1986));
// --------------
  for (c0 = 0; c0 <= 12; c0 += 1)
    for (c1 = c0 + 1987; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1987+c0] + S[-c0+c1-1987+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1986+c0] + S[1986+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 12; c0 += 1)
    S[c0][c0+1987] = MAX(S[c0][c0+1987], S[c0+1][c0+1987-1] + can_pair(RNA, c0, c0+1987));
// --------------
  for (c0 = 0; c0 <= 11; c0 += 1)
    for (c1 = c0 + 1988; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1988+c0] + S[-c0+c1-1988+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1987+c0] + S[1987+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 11; c0 += 1)
    S[c0][c0+1988] = MAX(S[c0][c0+1988], S[c0+1][c0+1988-1] + can_pair(RNA, c0, c0+1988));
// --------------
  for (c0 = 0; c0 <= 10; c0 += 1)
    for (c1 = c0 + 1989; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1989+c0] + S[-c0+c1-1989+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1988+c0] + S[1988+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 10; c0 += 1)
    S[c0][c0+1989] = MAX(S[c0][c0+1989], S[c0+1][c0+1989-1] + can_pair(RNA, c0, c0+1989));
// --------------
  for (c0 = 0; c0 <= 9; c0 += 1)
    for (c1 = c0 + 1990; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1990+c0] + S[-c0+c1-1990+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1989+c0] + S[1989+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 9; c0 += 1)
    S[c0][c0+1990] = MAX(S[c0][c0+1990], S[c0+1][c0+1990-1] + can_pair(RNA, c0, c0+1990));
// --------------
  for (c0 = 0; c0 <= 8; c0 += 1)
    for (c1 = c0 + 1991; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1991+c0] + S[-c0+c1-1991+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1990+c0] + S[1990+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 8; c0 += 1)
    S[c0][c0+1991] = MAX(S[c0][c0+1991], S[c0+1][c0+1991-1] + can_pair(RNA, c0, c0+1991));
// --------------
  for (c0 = 0; c0 <= 7; c0 += 1)
    for (c1 = c0 + 1992; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1992+c0] + S[-c0+c1-1992+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1991+c0] + S[1991+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 7; c0 += 1)
    S[c0][c0+1992] = MAX(S[c0][c0+1992], S[c0+1][c0+1992-1] + can_pair(RNA, c0, c0+1992));
// --------------
  for (c0 = 0; c0 <= 6; c0 += 1)
    for (c1 = c0 + 1993; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1993+c0] + S[-c0+c1-1993+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1992+c0] + S[1992+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 6; c0 += 1)
    S[c0][c0+1993] = MAX(S[c0][c0+1993], S[c0+1][c0+1993-1] + can_pair(RNA, c0, c0+1993));
// --------------
  for (c0 = 0; c0 <= 5; c0 += 1)
    for (c1 = c0 + 1994; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1994+c0] + S[-c0+c1-1994+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1993+c0] + S[1993+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 5; c0 += 1)
    S[c0][c0+1994] = MAX(S[c0][c0+1994], S[c0+1][c0+1994-1] + can_pair(RNA, c0, c0+1994));
// --------------
  for (c0 = 0; c0 <= 4; c0 += 1)
    for (c1 = c0 + 1995; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1995+c0] + S[-c0+c1-1995+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1994+c0] + S[1994+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 4; c0 += 1)
    S[c0][c0+1995] = MAX(S[c0][c0+1995], S[c0+1][c0+1995-1] + can_pair(RNA, c0, c0+1995));
// --------------
  for (c0 = 0; c0 <= 3; c0 += 1)
    for (c1 = c0 + 1996; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1996+c0] + S[-c0+c1-1996+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1995+c0] + S[1995+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 3; c0 += 1)
    S[c0][c0+1996] = MAX(S[c0][c0+1996], S[c0+1][c0+1996-1] + can_pair(RNA, c0, c0+1996));
// --------------
  for (c0 = 0; c0 <= 2; c0 += 1)
    for (c1 = c0 + 1997; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1997+c0] + S[-c0+c1-1997+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1996+c0] + S[1996+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 2; c0 += 1)
    S[c0][c0+1997] = MAX(S[c0][c0+1997], S[c0+1][c0+1997-1] + can_pair(RNA, c0, c0+1997));
// --------------
  for (c0 = 0; c0 <= 1; c0 += 1)
    for (c1 = c0 + 1998; c1 <= 1999; c1 += 1) {
      S[c0][c1] = MAX(S[c0][-c0+c1-1998+c0] + S[-c0+c1-1998+c0+1][c1], S[c0][c1]);
      S[c0][c1] = MAX(S[c0][1997+c0] + S[1997+c0+1][c1], S[c0][c1]);
    }
// --------------
  for (c0 = 0; c0 <= 1; c0 += 1)
    S[c0][c0+1998] = MAX(S[c0][c0+1998], S[c0+1][c0+1998-1] + can_pair(RNA, c0, c0+1998));
// --------------
if (N == 2000) {
  S[0][1999] = MAX(S[0][0+0] + S[0+0+1][1999], S[0][1999]);
  S[0][1999] = MAX(S[0][1998+0] + S[1998+0+1][1999], S[0][1999]);
}
// --------------
  S[0][1999] = MAX(S[0][1999], S[0+1][1999-1] + can_pair(RNA, 0, 1999));

}
}


    end = omp_get_wtime();
	printf("%.6f\n", end - start);

    return 0;


}

