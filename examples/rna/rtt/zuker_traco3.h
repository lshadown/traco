void zuker_traco3(){

int c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15;

for( c0 = 1; c0 < N + floord(N - 2, 16); c0 += 1)
  #pragma omp parallel for
  for( c1 = c0 - (c0 + 16) / 17 + 1; c1 <= min(N - 1, c0); c1 += 1)
    for( c3 = 16 * c0 - 16 * c1 + 1; c3 <= min(c1, 16 * c0 - 16 * c1 + 16); c3 += 1) {
      if (c3 >= 3 && (c3 % 16) + N >= c1 + c3 + 16)
        for( c10 = N - c1; c10 < N - c1 + c3 - 1; c10 += 1)
          W[(N-c1-1)][(N-c1+c3-1)] += MIN ( MIN(W[(N-c1-1)][c10], W[c10+1][(N-c1+c3-1)]), W[(N-c1-1)][(N-c1+c3-1)]);
      if (c3 >= 3)
        for( c4 = (N - c1) / 16; c4 <= (N - c1 + c3 - 3) / 16; c4 += 1) {
          if (c3 >= 16 * c4 && 16 * c4 + 15 >= c3)
            for( c10 = N - c1; c10 < 16 * c4; c10 += 1)
              W[(N-c1-1)][(N-c1+c3-1)] += MIN ( MIN(W[(N-c1-1)][c10], W[c10+1][(N-c1+c3-1)]), W[(N-c1-1)][(N-c1+c3-1)]);
          for( c10 = max(N - c1, 16 * c4); c10 <= min(N - c1 + c3 - 3, 16 * c4 + 15); c10 += 1) {
            for( c12 = c10 + 1; c12 < min(N - c1 + c3 - 1, c3 + c10 - 2); c12 += 1)
              V[(N-c1-1)][(N-c1+c3-1)] = MIN(V[c10][c12] + EFL[(N-c1-1)][(N-c1+c3-1)][c10][c12], V[(N-c1-1)][(N-c1+c3-1)]);
            if (c3 >= 16 * c4 && 16 * c4 + 15 >= c3)
              W[(N-c1-1)][(N-c1+c3-1)] += MIN ( MIN(W[(N-c1-1)][c10], W[c10+1][(N-c1+c3-1)]), W[(N-c1-1)][(N-c1+c3-1)]);
            V[(N-c1-1)][(N-c1+c3-1)] = MIN(W[(N-c1-1)+1][c10] + W[c10+1][(N-c1+c3-1)-1], V[(N-c1-1)][(N-c1+c3-1)]);
          }
          if (c3 >= 16 * c4 && 16 * c4 + 15 >= c3 && c1 + 16 * c4 + 17 >= N + c3)
            W[(N-c1-1)][(N-c1+c3-1)] += MIN ( MIN(W[(N-c1-1)][(N-c1+c3-2)], W[(N-c1+c3-2)+1][(N-c1+c3-1)]), W[(N-c1-1)][(N-c1+c3-1)]);
          if (c3 >= 16 * c4 && 16 * c4 + 15 >= c3)
            for( c10 = 16 * c4 + 16; c10 < N - c1 + c3 - 1; c10 += 1)
              W[(N-c1-1)][(N-c1+c3-1)] += MIN ( MIN(W[(N-c1-1)][c10], W[c10+1][(N-c1+c3-1)]), W[(N-c1-1)][(N-c1+c3-1)]);
        }
      if (31 * c1 + c3 + 14 >= 15 * N + 16 * c0 && (c0 - c1 - c3 + 1) % 15 == 0)
        for( c10 = N - c1; c10 < N - c1 + c3 - 1; c10 += 1)
          W[(N-c1-1)][(N-c1+c3-1)] += MIN ( MIN(W[(N-c1-1)][c10], W[c10+1][(N-c1+c3-1)]), W[(N-c1-1)][(N-c1+c3-1)]);
      if (c1 == c0 && c3 == 2)
        W[(N-c0-1)][(N-c0+1)] += MIN ( MIN(W[(N-c0-1)][(N-c0)], W[(N-c0)+1][(N-c0+1)]), W[(N-c0-1)][(N-c0+1)]);
      V[(N-c1-1)][(N-c1+c3-1)] = MIN( MIN (V[(N-c1-1)+1][(N-c1+c3-1)-1], EHF[(N-c1-1)][(N-c1+c3-1)]), V[(N-c1-1)][(N-c1+c3-1)]);
      W[(N-c1-1)][(N-c1+c3-1)] = MIN( MIN ( MIN ( W[(N-c1-1)+1][(N-c1+c3-1)], W[(N-c1-1)][(N-c1+c3-1)-1]), V[(N-c1-1)][(N-c1+c3-1)]), W[(N-c1-1)][(N-c1+c3-1)]);

}
