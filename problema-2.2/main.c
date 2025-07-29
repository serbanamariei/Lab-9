#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n;
	printf("n = ");
	scanf("%d",&n);

	printf("\n\nCititi matricea:\n");
	double **a=citire(n);
	printf("\n\nMatricea dvs:\n");
	afisare(a,n);
	printf("\n\nSuma elementelor din NORD: %.3lf\n",suma(a,n));
	printf("Produsul elementelor din SUD: %.3lf\n",produs(a,n));
	printf("Media aritmetica a elementelor din EST: %.3lf\n",mediaAritmetica(a,n));
	printf("Media geometrica a elementelor din VEST: %.3lf\n",mediaGeo(a,n));

	double **c=(double **)malloc(n*sizeof(double *));
	if(c==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		c[i]=(double *)malloc(n*sizeof(double));
		if(c[i]==0)
		{
			fprintf(stderr,"Memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
	}

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			c[i][j]=a[i][j];
	
	printf("\n\nMatricea oglindita fata de marginea din dreapta:\n");
	oglindaStDrt(c,n);
	afisare(c,n);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			c[i][j]=a[i][j];
	printf("\n\nMatricea oglindita fata de marginea de jos:\n");
	oglindaSusJos(c,n);
	afisare(c,n);

	for(int i=0;i<n;++i)
		{
			memset(c[i],0,n*sizeof(double *));
			memset(a[i],0,n*sizeof(double *));
			free(a[i]);
			free(c[i]);
			a[i]=0;
			c[i]=0;
		}
	memset(a,0,n*sizeof(double));
	memset(c,0,n*sizeof(double));
	free(a);
	free(c);
	a=0;
	c=0;

	return 0;
}
