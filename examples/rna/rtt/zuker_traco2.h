void zuker_traco2(){

int c1,c2,c3,c4,c5,c6,c7,c8,c9,c11,c10,c12,c13,c14,c15;




for( c1 = 1; c1 < 2 * N - 2; c1 += 1)
  #pragma omp parallel for
  for( c3 = max(0, -N + c1 + 1); c3 < (c1 + 1) / 2; c3 += 1)
    for( c4 = max(0, -c3 + 1); c4 <= 2; c4 += 1) {
      if (c4 >= 1) {
        if (c4 == 2) {
          W[(N-c1+c3-1)][(N-c1+2*c3)] = MIN( MIN ( MIN ( W[(N-c1+c3-1)+1][(N-c1+2*c3)], W[(N-c1+c3-1)][(N-c1+2*c3)-1]), V[(N-c1+c3-1)][(N-c1+2*c3)]), W[(N-c1+c3-1)][(N-c1+2*c3)]);
        } else
          V[(N-c1+c3-1)][(N-c1+2*c3)] = MIN( MIN (V[(N-c1+c3-1)+1][(N-c1+2*c3)-1], EHF[(N-c1+c3-1)][(N-c1+2*c3)]), V[(N-c1+c3-1)][(N-c1+2*c3)]);
      } else
        for( c5 = 0; c5 < c3; c5 += 1) {
          for( c7 = 0; c7 < min(c3 - 2, c3 - c5 - 1); c7 += 1)
            V[(N-c1+c3-1)][(N-c1+2*c3)] = MIN(V[(N-c1+c3+c5)][(N-c1+c3+c5+c7+1)] + EFL[(N-c1+c3-1)][(N-c1+2*c3)], V[(N-c1+c3-1)][(N-c1+2*c3)]);
          for( c6 = 1; c6 <= min(2, c3 - c5); c6 += 1) {
            if (c6 == 2) {
              V[(N-c1+c3-1)][(N-c1+2*c3)] = MIN(W[(N-c1+c3-1)+1][(N-c1+c3+c5)] + W[(N-c1+c3+c5)+1][(N-c1+2*c3)-1], V[(N-c1+c3-1)][(N-c1+2*c3)]);
            } else
              W[(N-c1+c3-1)][(N-c1+2*c3)] = MIN ( MIN(W[(N-c1+c3-1)][(N-c1+c3+c5)], W[(N-c1+c3+c5)+1][(N-c1+2*c3)]), W[(N-c1+c3-1)][(N-c1+2*c3)]);
          }
        }
    }


}
