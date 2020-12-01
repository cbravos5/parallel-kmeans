for (i = 0; i < k; i++)
{
    for (j = 0; j < DIM; j++) 
    {
        mean[i*DIM+j] = sum[i*DIM+j]/count[i];
    }
}