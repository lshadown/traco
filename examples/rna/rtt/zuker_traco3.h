void zuker_traco3(){

int c0,c1,c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15;

for( c0 = 0; c0 <= floord(N - 2, 16); c0 += 1)
  #pragma omp parallel for
  for( c1 = (c0 + 1) / 2; c1 <= min(c0, (N - 1) / 32); c1 += 1)
    for( c3 = 32 * c0 - 32 * c1 + 1; c3 <= min(min(N - 1, 32 * c1 + 31), 32 * c0 - 32 * c1 + 32); c3 += 1) {
      if (c3 >= 3 && (c3 % 32) + N >= 32 * c1 + c3 + 63) {
        for( c6 = max(-N + 32 * c1 + 1, -N + c3 + 1); c6 <= -N + 32 * c1 + 32; c6 += 1)
          for( c10 = -c6 + 1; c10 < c3 - c6; c10 += 1)
            W[(-c6)][(c3-c6)] += MIN ( MIN(W[(-c6)][c10], W[c10+1][(c3-c6)]), W[(-c6)][(c3-c6)]);
      } else if (N >= 32 * c0 + 62 && c1 == c0 && c3 == 2) {
        for( c6 = max(-N + 3, -N + 32 * c0 + 1); c6 <= -N + 32 * c0 + 32; c6 += 1)
          W[(-c6)][(-c6+2)] += MIN ( MIN(W[(-c6)][(-c6+1)], W[(-c6+1)+1][(-c6+2)]), W[(-c6)][(-c6+2)]);
      }
      if (c3 >= 3) {
        for( c4 = max(0, -c1 + (N + 1) / 32 - 1); c4 < -c1 + (N + c3) / 32 - 1; c4 += 1) {
          if (c3 >= 32 * c4 + 32) {
            for( c6 = max(max(-N + 32 * c1 + 1, -N + c3 + 1), -32 * c4 - 30); c6 <= min(0, -N + 32 * c1 + 32); c6 += 1)
              for( c10 = max(32 * c4, -c6 + 1); c10 <= min(32 * c4 + 31, c3 - c6 - 2); c10 += 1) {
                for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                  V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
                V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
              }
          } else if (32 * c4 >= c3 + 1) {
            for( c6 = max(max(-N + 32 * c1 + 1, -N + c3 + 1), -32 * c4 - 30); c6 <= -N + 32 * c1 + 32; c6 += 1)
              for( c10 = max(32 * c4, -c6 + 1); c10 <= min(32 * c4 + 31, c3 - c6 - 2); c10 += 1) {
                for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                  V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
                V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
              }
          } else {
            for( c6 = max(-N + 32 * c1 + 1, -N + c3 + 1); c6 <= -N + 32 * c1 + 32; c6 += 1)
              for( c10 = -c6 + 1; c10 < c3 - c6; c10 += 1) {
                if (c10 >= 32 * c4 && 32 * c4 + 31 >= c10)
                  for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                    V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
                W[(-c6)][(c3-c6)] += MIN ( MIN(W[(-c6)][c10], W[c10+1][(c3-c6)]), W[(-c6)][(c3-c6)]);
                if (c3 >= c6 + c10 + 2 && c10 >= 32 * c4 && 32 * c4 + 31 >= c10)
                  V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
              }
          }
        }
        if ((c3 >= 32 && 32 * c1 + 63 >= N + c3) || (N + c3 >= 32 * c1 + 64 && 32 * c1 + 31 >= ((31 * N + 31 * c3 + 31) % 32) + N)) {
          int c4 = 32 * c1 + 62 >= N + c3 ? 0 : N - c1 + c3 - (31 * N + 31 * c3 + 31) / 32 - 1;
          for( c6 = max(-N + 32 * c1 + 1, -N + c3 + 1); c6 <= 0; c6 += 1)
            for( c10 = max(32 * c4, -c6 + 1); c10 <= min(32 * c4 + 31, c3 - c6 - 2); c10 += 1) {
              for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
              V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
            }
        }
      }
      for( c4 = max(c3 / 32, -c1 + (N + c3) / 32 - 1); c4 <= min((N - 1) / 32, -c1 + (N + c3 - 1) / 32); c4 += 1) {
        if (c1 == c0 && c3 >= 3 && c4 == 0) {
          for( c6 = max(-N + 32 * c0 + 1, -N + c3 + 1); c6 < -30; c6 += 1)
            for( c10 = -c6 + 1; c10 < c3 - c6; c10 += 1)
              W[(-c6)][(c3-c6)] += MIN ( MIN(W[(-c6)][c10], W[c10+1][(c3-c6)]), W[(-c6)][(c3-c6)]);
        } else if (c1 == c0 && c3 == 2 && c4 == 0) {
          for( c6 = max(-N + 3, -N + 32 * c0 + 1); c6 < -29; c6 += 1)
            W[(-c6)][(-c6+2)] += MIN ( MIN(W[(-c6)][(-c6+1)], W[(-c6+1)+1][(-c6+2)]), W[(-c6)][(-c6+2)]);
        }
        if (c3 >= 3)
          for( c6 = max(max(-N + 32 * c1 + 1, -N + c3 + 1), -32 * c4 - 30); c6 < c3 - 32 * c4 - 31; c6 += 1) {
            if (32 * c4 >= c3 + 1) {
              for( c10 = max(32 * c4, -c6 + 1); c10 <= min(32 * c4 + 31, c3 - c6 - 2); c10 += 1) {
                for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                  V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
                V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
              }
            } else {
              for( c10 = -c6 + 1; c10 < c3 - c6; c10 += 1) {
                if (c10 >= 32 * c4 && 32 * c4 + 31 >= c10)
                  for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                    V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
                W[(-c6)][(c3-c6)] += MIN ( MIN(W[(-c6)][c10], W[c10+1][(c3-c6)]), W[(-c6)][(c3-c6)]);
                if (c3 >= c6 + c10 + 2 && c10 >= 32 * c4 && 32 * c4 + 31 >= c10)
                  V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
              }
            }
          }
        for( c6 = max(max(-N + 32 * c1 + 1, -N + c3 + 1), c3 - 32 * c4 - 31); c6 <= min(min(0, -N + 32 * c1 + 32), c3 - 32 * c4); c6 += 1) {
          if (32 * c4 >= c3 + 1) {
            for( c10 = max(32 * c4, -c6 + 1); c10 < c3 - c6 - 1; c10 += 1) {
              for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
              V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
            }
          } else {
            for( c10 = -c6 + 1; c10 < c3 - c6; c10 += 1) {
              if (c10 >= 32 * c4)
                for( c12 = c10 + 1; c12 < min(c3 - c6, c3 + c10 - 2); c12 += 1)
                  V[(-c6)][(c3-c6)] = MIN(V[c10][c12] + EFL[(-c6)][(c3-c6)], V[(-c6)][(c3-c6)]);
              W[(-c6)][(c3-c6)] += MIN ( MIN(W[(-c6)][c10], W[c10+1][(c3-c6)]), W[(-c6)][(c3-c6)]);
              if (c3 >= c6 + c10 + 2 && c10 >= 32 * c4)
                V[(-c6)][(c3-c6)] = MIN(W[(-c6)+1][c10] + W[c10+1][(c3-c6)-1], V[(-c6)][(c3-c6)]);
            }
          }
          V[(-c6)][(c3-c6)] = MIN( MIN (V[(-c6)+1][(c3-c6)-1], EHF[(-c6)][(c3-c6)]), V[(-c6)][(c3-c6)]);
          W[(-c6)][(c3-c6)] = MIN( MIN ( MIN ( W[(-c6)+1][(c3-c6)], W[(-c6)][(c3-c6)-1]), V[(-c6)][(c3-c6)]), W[(-c6)][(c3-c6)]);
        }
      }
    }

}
