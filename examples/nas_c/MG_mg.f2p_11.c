for(i3 = 2; i3 <= N1; i3++){
  for(i2 = 2; i2 <= N2; i2++){
    u[ 1][i2][i3] = u[n1-1][i2][i3];
    u[n1][i2][i3] = u[   2][i2][i3];
  }
}

