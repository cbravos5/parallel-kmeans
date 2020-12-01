scanf("%d", &k);
scanf("%d", &n);
x = (double *)malloc(sizeof(double)*DIM*n); //pontos
mean = (double *)malloc(sizeof(double)*DIM*k); //centroides
sum= (double *)malloc(sizeof(double)*DIM*k);
cluster = (int *)malloc(sizeof(int)*n);
count = (int *)malloc(sizeof(int)*k);
for (i = 0; i<n; i++)
    cluster[i] = 0;
for (i = 0; i<k; i++)
    scanf("%lf %lf %lf", mean+i*DIM, mean+i*DIM+1, mean+i*DIM+2);
for (i = 0; i<n; i++)
    scanf("%lf %lf %lf", x+i*DIM, x+i*DIM+1, x+i*DIM+2);
flips = n;