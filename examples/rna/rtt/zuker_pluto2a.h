 void zuker_pluto2a(){
     int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
 int lb, ub, lbp, ubp, lb2, ub2;
 register int lbv, ubv;

 if (N >= 2) {
  lbp=1;
  ubp=N-1;
#pragma omp parallel for private(lbv,ubv,t5,t6,t7,t8,t9)
  for (t4=lbp;t4<=ubp;t4++) {
    V[(t4-1)][t4] = MIN( MIN (V[(t4-1)+1][t4-1], EHF[(t4-1)][t4]), V[(t4-1)][t4]);;
    W[(t4-1)][t4] = MIN( MIN ( MIN ( W[(t4-1)+1][t4], W[(t4-1)][t4-1]), V[(t4-1)][t4]), W[(t4-1)][t4]);;
  }
  if (N >= 3) {
    lbp=2;
    ubp=N-1;
#pragma omp parallel for private(lbv,ubv,t5,t6,t7,t8,t9)
    for (t4=lbp;t4<=ubp;t4++) {
      W[(t4-2)][t4] += MIN ( MIN(W[(t4-2)][(t4-1)], W[(t4-1)+1][t4]), W[(t4-2)][t4]);;
      V[(t4-2)][t4] = MIN( MIN (V[(t4-2)+1][t4-1], EHF[(t4-2)][t4]), V[(t4-2)][t4]);;
      W[(t4-2)][t4] = MIN( MIN ( MIN ( W[(t4-2)+1][t4], W[(t4-2)][t4-1]), V[(t4-2)][t4]), W[(t4-2)][t4]);;
    }
  }
  if (N >= 4) {
    lbp=3;
    ubp=N-1;
#pragma omp parallel for private(lbv,ubv,t5,t6,t7,t8,t9)
    for (t4=lbp;t4<=ubp;t4++) {
      W[(t4-3)][t4] += MIN ( MIN(W[(t4-3)][(t4-2)], W[(t4-2)+1][t4]), W[(t4-3)][t4]);;
      V[(t4-3)][t4] = MIN(W[(t4-3)+1][(t4-2)] + W[(t4-2)+1][t4-1], V[(t4-3)][t4]);;
      W[(t4-3)][t4] += MIN ( MIN(W[(t4-3)][(t4-1)], W[(t4-1)+1][t4]), W[(t4-3)][t4]);;
      V[(t4-3)][t4] = MIN( MIN (V[(t4-3)+1][t4-1], EHF[(t4-3)][t4]), V[(t4-3)][t4]);;
      W[(t4-3)][t4] = MIN( MIN ( MIN ( W[(t4-3)+1][t4], W[(t4-3)][t4-1]), V[(t4-3)][t4]), W[(t4-3)][t4]);;
    }
  }
  for (t2=4;t2<=N-1;t2++) {
    lbp=t2;
    ubp=N-1;
#pragma omp parallel for private(lbv,ubv,t5,t6,t7,t8,t9)
    for (t4=lbp;t4<=ubp;t4++) {
      for (t6=-t2+t4+1;t6<=t4-2;t6++) {
        for (t8=t6+1;t8<=min(t4-1,t2+t6-3);t8++) {
          V[(-t2+t4)][t4] = MIN(V[t6][t8] + EFL[(-t2+t4)][t4], V[(-t2+t4)][t4]);;
        }
        W[(-t2+t4)][t4] += MIN ( MIN(W[(-t2+t4)][t6], W[t6+1][t4]), W[(-t2+t4)][t4]);;
        V[(-t2+t4)][t4] = MIN(W[(-t2+t4)+1][t6] + W[t6+1][t4-1], V[(-t2+t4)][t4]);;
      }
      W[(-t2+t4)][t4] += MIN ( MIN(W[(-t2+t4)][(t4-1)], W[(t4-1)+1][t4]), W[(-t2+t4)][t4]);;
      V[(-t2+t4)][t4] = MIN( MIN (V[(-t2+t4)+1][t4-1], EHF[(-t2+t4)][t4]), V[(-t2+t4)][t4]);;
      W[(-t2+t4)][t4] = MIN( MIN ( MIN ( W[(-t2+t4)+1][t4], W[(-t2+t4)][t4-1]), V[(-t2+t4)][t4]), W[(-t2+t4)][t4]);;
    }
  }
}
/* End of CLooG code */
}
