for (i = 0; i < n; i++) 
{
    count[cluster[i]]++;
    for (j = 0; j < DIM; j++)				
        sum[cluster[i]*DIM+j] += x[i*DIM+j];		
}