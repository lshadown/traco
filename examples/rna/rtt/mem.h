long double **mem()
{
int i;
long double **S;
S = (long double **) malloc(DIM * sizeof(long double*));

for (i=0; i<DIM; i++)
    S[i] = (long double*)malloc(DIM * sizeof(long double));

return S;
}
