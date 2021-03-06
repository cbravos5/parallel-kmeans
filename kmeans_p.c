#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define DIM 3
int main(void) {
	int i, j, k, n, c;
	double dmin, dx;
	double *x, *mean, *sum;
	int *cluster, *count, color;
	int flips;
	scanf("%d", &k);//# centróides/cluster
	scanf("%d", &n);//# pontos
	x = (double *)malloc(sizeof(double)*DIM*n); //pontos
	mean = (double *)malloc(sizeof(double)*DIM*k); //centroides
	sum= (double *)malloc(sizeof(double)*DIM*k);
	cluster = (int *)malloc(sizeof(int)*n);
	count = (int *)malloc(sizeof(int)*k);
	#pragma omp parallel for
	for (i = 0; i<n; i++)
		cluster[i] = 0;
	for (i = 0; i<k; i++)
		scanf("%lf %lf %lf", mean+i*DIM, mean+i*DIM+1, mean+i*DIM+2);
	for (i = 0; i<n; i++)
		scanf("%lf %lf %lf", x+i*DIM, x+i*DIM+1, x+i*DIM+2);
	flips = n;
	while (flips>0) {
		flips = 0;
		#pragma omp parallel 
        {
            #pragma omp for
            for (j = 0; j < k; j++)
            {
                count[j] = 0;
                for (i = 0; i < DIM; i++)
                    sum[j*DIM+i] = 0.0;
            }
               
            //calcula a distância de cada ponto i de cada centroide c 
            #pragma omp for private(dmin, color, dx) reduction(+:flips)
            for (i = 0; i < n; i++) 
            {
                dmin = -1; color = cluster[i];
                for (c = 0; c < k; c++)
                {
                    dx = 0.0;
                    for (j = 0; j < DIM; j++)//distancia euclidiana
                        dx +=  (x[i*DIM+j] - mean[c*DIM+j])*(x[i*DIM+j] - mean[c*DIM+j]);
                    if (dx < dmin || dmin == -1)//se a distância for menor que de outro centroide, atualiza o centroide
                    {
                        color = c;
                        dmin = dx;
                    }
                }
                //se o centroide atual for diferente do mais próximo, então novo calculo de média deverá ser feito
                //consequentemente os centroides irão mudar de posição, entao um novo loop deverá ser feito
                if (cluster[i] != color)
                {
                    flips++;
                    cluster[i] = color;
                }
            }
        }
       	#pragma omp parallel for default(shared) reduction(+:count[:k],sum[:DIM*k])
	    for (i = 0; i < n; i++) 
		{
			count[cluster[i]]++;//adiciona o ponto i ao centroide correspondente
			for (j = 0; j < DIM; j++)				//Soma x,y,z do ponto i e adiciona a posiçao correspondente
				sum[cluster[i]*DIM+j] += x[i*DIM+j];// do centroide pertencente ao ponto
		}
		#pragma omp parallel for collapse(2)
		for (i = 0; i < k; i++)//Calcula a media das distâncias para cada centroide i 
		{
			for (j = 0; j < DIM; j++) 
			{
				mean[i*DIM+j] = sum[i*DIM+j]/count[i];
  			}
		}
	}
	for (i = 0; i < k; i++) //imprime as posições de cada centroide
	{
		for (j = 0; j < DIM; j++)
			printf("%5.2f ", mean[i*DIM+j]);
		printf("\n");
	}
	#ifdef DEBUG
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < DIM; j++)
			printf("%5.2f ", x[i*DIM+j]);
		printf("%d\n", cluster[i]);
	}
	#endif
	return(0);
}
