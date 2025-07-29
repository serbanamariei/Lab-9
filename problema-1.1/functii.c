#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int **citire(int n, int m)
{
	int **a=0;
	a=(int **)malloc(n*sizeof(int *));
	if(a==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		*(a+i)=0;
		*(a+i)=(int *)malloc(m*sizeof(int));
		if(*(a+i)==0)
		{
			fprintf(stderr,"Memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
	}

	for(int i=0;i<n;++i)
	{
		printf("Linia %d: ",i);
		for(int j=0;j<m;++j)
			scanf(" %d",&a[i][j]);
	}

	return a;
}

void dealocare(int **a, int n, int m)
{
	for(int i=0;i<m;++i)
	{
		memset(*(a+i),0,m*sizeof(int));
		free(*(a+i));
		*(a+i)=0;
	}

	memset(a,0,n*sizeof(int *));
	free(a);
	a=0;
}

void afisare(int **a, int n, int m)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			printf("%d ",*(*(a+i)+j));
		printf("\n");
	}
}

int maxim(int *a, int m)
{
	int max=a[0];
	for(int i=1;i<m;++i)
	{
		if(a[i]>max) max=a[i];
	}

	return max;
}

void interschimbare(int **a, int **b)
{
	int *aux=*a;
	*a=*b;
	*b=aux;
}


void ordonare(int **a, int n, int m)
{
	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(maxim(a[i],m)>maxim(a[j],m)) interschimbare(&a[i],&a[j]);
		}
	}
}


