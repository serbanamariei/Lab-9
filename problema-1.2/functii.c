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

void interschimbareLinii(int **a, int n, int x, int y)
{
	int *aux=a[x];
	a[x]=a[y];
	a[y]=aux;
}

void interschimbareCol(int **a, int n, int x, int y)
{
	for(int i=0;i<n;++i)
	{
		int aux=a[i][x];
		a[i][x]=a[i][y];
		a[i][y]=aux;
	}
}


/*void ordonare(int **a, int n, int m)
{
	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(maxim(a[i],m)>maxim(a[j],m)) interschimbare(&a[i],&a[j]);
		}
	}
}*/

void primaCol(int **a, int n)
{
	for(int i=0;i<n-1;++i)
		for(int j=i+1;j<n;++j)
		{
			if(a[i][0]>a[j][0]) interschimbareLinii(a,n,i,j);
		}
}

void primaLinie(int **a, int n)
{
	for(int j=0;j<n-1;++j)
		for(int k=j+1;k<n;++k)
		{
			if(a[0][j]>a[0][k]) interschimbareCol(a,n,j,k);
		}
}

void diagP(int **a, int n)
{
	for(int i=0;i<n-1;++i)
		for(int j=i+1;j<n;++j)
		{
			if(a[i][i]>a[j][j]) interschimbareCol(a,n,i,j);
		}
}

int **copie(int **a, int n)
{
	int **c=0;
	c=(int **)malloc(n*sizeof(int *));
	if(c==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		c[i]=(int *)malloc(n*sizeof(int));
		if(c[i]==0)
		{
			fprintf(stderr,"Memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
	}

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			c[i][j]=a[i][j];

	return c;
}
