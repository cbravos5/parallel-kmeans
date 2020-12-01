for (i = 0; i < n; i++) 
{
    dmin = -1; color = cluster[i];
    for (c = 0; c < k; c++)
    {
        dx = 0.0;
        for (j = 0; j < DIM; j++)
            dx +=  (x[i*DIM+j] - mean[c*DIM+j])*(x[i*DIM+j] - mean[c*DIM+j]);
        if (dx < dmin || dmin == -1)
        {
            color = c;
            dmin = dx;
        }
    }
    if (cluster[i] != color)
    {
        flips++;
        cluster[i] = color;
    }
}