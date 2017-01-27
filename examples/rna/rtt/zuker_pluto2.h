 void zuker_pluto2(){
     int t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
 int lb, ub, lbp, ubp, lb2, ub2;
 register int lbv, ubv;

/* Start of CLooG code */
if (N >= 2) {
  for (t2=1;t2<=N-1;t2++) {
    lbp=t2;
    ubp=N-1;
#pragma omp parallel for private(lbv,ubv,t5,t6,t7,t8,t9,t10,t11,t12)
    for (t4=lbp;t4<=ubp;t4++) {
      if (t2 >= 4) {
        for (t9=-t2+t4+1;t9<=t4-2;t9++) {
          for (t11=t9+1;t11<=min(t4-1,t2+t9-3);t11++) {
            V[(-t2+t4)][t4] = MIN(V[t9][t11] + EFL[(-t2+t4)][t4], V[(-t2+t4)][t4]);;
          }
          W[(-t2+t4)][t4] += MIN ( MIN(W[(-t2+t4)][t9], W[t9+1][t4]), W[(-t2+t4)][t4]);;
          V[(-t2+t4)][t4] = MIN(W[(-t2+t4)+1][t9] + W[t9+1][t4-1], V[(-t2+t4)][t4]);;
        }
        W[(-t2+t4)][t4] += MIN ( MIN(W[(-t2+t4)][(t4-1)], W[(t4-1)+1][t4]), W[(-t2+t4)][t4]);;
      }
      if (t2 == 3) {
        W[(t4-3)][t4] += MIN ( MIN(W[(t4-3)][(t4-2)], W[(t4-2)+1][t4]), W[(t4-3)][t4]);;
        V[(t4-3)][t4] = MIN(W[(t4-3)+1][(t4-2)] + W[(t4-2)+1][t4-1], V[(t4-3)][t4]);;
        W[(t4-3)][t4] += MIN ( MIN(W[(t4-3)][(t4-1)], W[(t4-1)+1][t4]), W[(t4-3)][t4]);;
      }
      if (t2 == 2) {
        W[(t4-2)][t4] += MIN ( MIN(W[(t4-2)][(t4-1)], W[(t4-1)+1][t4]), W[(t4-2)][t4]);;
      }
      V[(-t2+t4)][t4] = MIN( MIN (V[(-t2+t4)+1][t4-1], EHF[(-t2+t4)][t4]), V[(-t2+t4)][t4]);;
      W[(-t2+t4)][t4] = MIN( MIN ( MIN ( W[(-t2+t4)+1][t4], W[(-t2+t4)][t4-1]), V[(-t2+t4)][t4]), W[(-t2+t4)][t4]);;
    }
  }
}
/* End of CLooG code */
}
