void zuker_traco2(){

int c1,c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15;


for( c1 = 0; c1 < N - 1; c1 += 1)
  #pragma omp parallel for shared(c1,N) private(c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15)
  for( c3 = max(0, -N + c1 + N / 2 + 1); c3 <= c1 / 2; c3 += 1)
    for( c4 = max(0, -c3 + 1); c4 <= 2; c4 += 1) {
      if (c4 >= 1) {
        for( c9 = max(-N + 2 * c1 - 2 * c3 + 1, -N + 2 * c3 + 2); c9 <= min(0, -N + 2 * c1 - 2 * c3 + 2); c9 += 1)
          for( c11 = 2 * c3 - c9 + 1; c11 <= min(N - 1, 2 * c3 - c9 + 2); c11 += 1) {
            if (c9 + c11 >= 2 * c3 + c4) {
              if (c4 == 1) {
                V[(-c9)][c11] = MIN( MIN (V[(-c9)+1][c11-1], EHF[(-c9)][c11]), V[(-c9)][c11]);
              } else
                W[(-c9)][(2*c3-c9+2)] = MIN ( MIN(W[(-c9)][(2*c3-c9+1)], W[(2*c3-c9+1)+1][(2*c3-c9+2)]), W[(-c9)][(2*c3-c9+2)]);
            }
            if (c4 == 2)
              W[(-c9)][c11] = MIN( MIN ( MIN ( W[(-c9)+1][c11], W[(-c9)][c11-1]), V[(-c9)][c11]), W[(-c9)][c11]);
          }
      } else
        for( c5 = 0; c5 < c3; c5 += 1)
          for( c6 = max(0, -c1 + c3 + 2); c6 <= 2; c6 += 1) {
            if (c6 >= 1) {
              for( c9 = max(-N + 2 * c1 - 2 * c3 + 1, -N + 2 * c3 + 2); c9 <= min(0, -N + 2 * c1 - 2 * c3 + 2); c9 += 1)
                for( c11 = 2 * c3 - c9 + 1; c11 <= min(N - 1, 2 * c3 - c9 + 2); c11 += 1)
                  for( c13 = 2 * c5 - c9 + 1; c13 <= min(2 * c5 - c9 + 2, -c6 + c11); c13 += 1) {
                    if (c6 == 2 && c9 + c13 == 2 * c5 + 2)
                      for( c15 = 2 * c5 - c9 + 3; c15 < c11; c15 += 1)
                        V[(-c9)][c11] = MIN(V[(2*c5-c9+2)][c15] + EFL[(-c9)][c11], V[(-c9)][c11]);
                    if (c6 == 2) {
                      V[(-c9)][c11] = MIN(W[(-c9)+1][c13] + W[c13+1][c11-1], V[(-c9)][c11]);
                    } else
                      W[(-c9)][c11] = MIN ( MIN(W[(-c9)][c13], W[c13+1][c11]), W[(-c9)][c11]);
                  }
            } else
              for( c7 = 0; c7 < min(c1 - c3 - 1, c3 - c5); c7 += 1)
                for( c9 = max(-N + 2 * c1 - 2 * c3 + 1, -N + 2 * c3 + 2); c9 <= min(0, -N + 2 * c1 - 2 * c3 + 2); c9 += 1)
                  for( c11 = max(2 * c3 - c9 + 1, 2 * c7 - c9 + 4); c11 <= min(N - 1, 2 * c3 - c9 + 2); c11 += 1)
                    for( c15 = 2 * c5 + 2 * c7 - c9 + 2; c15 <= min(min(2 * c5 + 2 * c7 - c9 + 3, 2 * c5 + c11 - 2), c11 - 1); c15 += 1)
                      V[(-c9)][c11] = MIN(V[(2*c5-c9+1)][c15] + EFL[(-c9)][c11], V[(-c9)][c11]);
          }
    }



}
