for(j = 1; j <= N1; j++){
  for(i = 2; i <= N2; i++){
    tmor[j][1]= tmor[j][1] + qbnew[i-1][j  ][1]*tx[i][1][1];
  }
}

