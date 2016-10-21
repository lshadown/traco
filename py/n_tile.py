




#pragma scop
#for (j=0; j<n; j++)
#for (i=j-1; i>-1; i--)
#for (k=i; k<j; k++)
#d[i][j]=d[i][j] + d[i][k]+d[k][j];
#pragma endscop




rel = " [n] -> { [j,i,k,v] -> [j',i',k',v'] : ( i' = i and j' = j and v = 9 and v' = 9 and 0 <= i <= k < k' < j < n and i <= j-1, k'-1 and k <= j-2 and 0 <= j ) or ( i = k and j' = j and i' = k and v = 9 and v' = 9 and 0 <= k < k' < j < n and k <= j-2 and 0 <= j ) or ( i' = i and j' = j and v = 9 and v' = 9 and 0 <= i <= k < k' < j < n and i <= j-1, k'-1 and k <= j-2 and 0 <= j ) or ( i' = i and k' = j and v = 9 and v' = 9 and 0 <= i <= k < j < j' < n and i <= j-1, n-2, j'-1 and 0 <= j <= n-2 and 1 <= n and 0 <= j' ) or ( k' = i and j' = j and v = 9 and v' = 9 and 1, i'+1 <= i <= k < j < n and 0 <= i' < j and i < j and 1 <= j ) or ( i' = i and j' = j and v = 9 and v' = 9 and 0 <= i <= k < k' < j < n and i <= j-1, k'-1 and k <= j-2 and 0 <= j ) }"


relplus = ""
