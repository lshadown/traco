void zuker_traco2(){

int c1,c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15;





for( c1 = 1; c1 < N + floord(N - 2, 16); c1 += 1)
   #pragma omp parallel for shared(c1,N) private(c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15)
  for( c3 = max(0, -N + c1 + 1); c3 <= (c1 - 1) / 17; c3 += 1) {
    for( c5 = 0; c5 <= min(c3, floord(c1 - c3 - 3, 16)); c5 += 1) {
      for( c7 = 0; c7 <= min(min(c3 - c5, floord(c1 - c3 - 4, 16)), -c5 + (c1 - c3 - 3) / 16); c7 += 1)
        for( c11 = max(max(N - c1 + 17 * c3, N - c1 + c3 + 16 * c5 + 16 * c7 + 2), N - c1 + c3 + 16 * c7 + 3); c11 <= min(N - 1, N - c1 + 17 * c3 + 15); c11 += 1)
          for( c15 = N - c1 + c3 + 16 * c5 + 16 * c7 + 1; c15 <= min(min(N - c1 + c3 + 16 * c5 + 16 * c7 + 16, 16 * c5 + c11 - 2), c11 - 1); c15 += 1)
            V[(N-c1+c3-1)][c11] = MIN(V[(N-c1+c3+16*c5)][c15] + EFL[(N-c1+c3-1)][c11], V[(N-c1+c3-1)][c11]);
      for( c6 = max(1, -c3 + c5 + 2); c6 <= 2; c6 += 1) {
        if (c6 == 2) {
          for( c11 = max(N - c1 + 17 * c3, N - c1 + c3 + 16 * c5 + 2); c11 <= min(N - 1, N - c1 + 17 * c3 + 15); c11 += 1)
            for( c13 = N - c1 + c3 + 16 * c5; c13 <= min(N - c1 + c3 + 16 * c5 + 15, c11 - 2); c13 += 1) {
              if (c1 + c13 >= N + c3 + 16 * c5 + 1)
                for( c15 = c13 + 1; c15 < c11; c15 += 1)
                  V[(N-c1+c3-1)][c11] = MIN(V[c13][c15] + EFL[(N-c1+c3-1)][c11], V[(N-c1+c3-1)][c11]);
              V[(N-c1+c3-1)][c11] = MIN(W[(N-c1+c3-1)+1][c13] + W[c13+1][c11-1], V[(N-c1+c3-1)][c11]);
            }
        } else
          for( c11 = N - c1 + 17 * c3; c11 <= min(N - 1, N - c1 + 17 * c3 + 15); c11 += 1)
            for( c13 = N - c1 + c3 + 16 * c5; c13 <= N - c1 + c3 + 16 * c5 + 15; c13 += 1)
              W[(N-c1+c3-1)][c11] = MIN ( MIN(W[(N-c1+c3-1)][c13], W[c13+1][c11]), W[(N-c1+c3-1)][c11]);
      }
    }
    for( c4 = 1; c4 <= 2; c4 += 1)
      for( c11 = N - c1 + 17 * c3; c11 <= min(N - 1, N - c1 + 17 * c3 + 15); c11 += 1) {
        if (c4 == 2)
          for( c13 = N - c1 + 17 * c3; c13 < c11; c13 += 1)
            W[(N-c1+c3-1)][c11] = MIN ( MIN(W[(N-c1+c3-1)][c13], W[c13+1][c11]), W[(N-c1+c3-1)][c11]);
        if (c4 == 2) {
          W[(N-c1+c3-1)][c11] = MIN( MIN ( MIN ( W[(N-c1+c3-1)+1][c11], W[(N-c1+c3-1)][c11-1]), V[(N-c1+c3-1)][c11]), W[(N-c1+c3-1)][c11]);
        } else
          V[(N-c1+c3-1)][c11] = MIN( MIN (V[(N-c1+c3-1)+1][c11-1], EHF[(N-c1+c3-1)][c11]), V[(N-c1+c3-1)][c11]);
      }
  }



}
