for(i = 1; i <= N1; i++){
  for(j = 1; j <= N2; j++){
    for(ip = 1; ip <= N3; ip++){
      wdtdr[i][j] = wdtdr[i][j] + wxm1[ip]*dxm1[ip][i]*dxm1[ip][j];
    }
  }
}

