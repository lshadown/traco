int main(){
#pragma scop



for(k = 1; k <= N1; k++){
  for(j = 1; j <= N2; j++){
    for(i = 1; i <= N3; i++){
      for(m = 1; m <= 5; m++){
        forcing[m][i][j][k] = -1. * forcing[m][i][j][k];
      }
    }
  }
}


#pragma endsco;p
}

#pragma endscop
}