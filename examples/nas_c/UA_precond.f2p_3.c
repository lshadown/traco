for(i = 2; i <= N1; i++){
  for(j = 1; j <= N2; j++){
    tmp[i][1] = tmp[i][1]+ qbnew[i-1][j][1]*tig[j];
  }
}

