#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

double **citire(int n)
{
	double **a=0;
	a=(double **)malloc(n*sizeof(double *));
	if(a==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		a[i]=0;
		a[i]=(double *)malloc(n*sizeof(double));
		if(a[i]==0)
		{
			fprintf(stderr,"Memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
	}

	for(int i=0;i<n;++i)
	{
		printf("Linia %d: ",i);
		for(int j=0;j<n;++j)
		{
			scanf(" %lf",&a[i][j]);
		}
	}

	return a;
}

void afisare(double **a, int n)
{
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			printf("%.2lf ",a[i][j]);
		printf("\n");
	}
}

double normaInfinit(double **a, int n)
{
	double max=0;
	for(int j=0;j<n;++j)
	{
		max+=fabs(a[0][j]);
	}
	for(int i=1;i<n;++i)
	{
		double s=0;
		for(int j=0;j<n;++j)
		{
			s+=fabs(a[i][j]);
		}
		if(s>max) max=s;
	}

	return max;
}

double norma1(double **a, int n)
{
	double max=0;
	for(int i=0;i<n;++i)
		max+=fabs(a[i][0]);
	for(int j=1;j<n;++j)
	{
		double s=0;
		for(int i=0;i<n;++i)
			s+=fabs(a[i][j]);
		if(s>max) max=s;
	}

	return max;	
}

double norma2(double **a, int n)
{
	double s=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			s+=a[i][j]*a[i][j];
	return sqrt(s);
}

double suma(double **a,int n)
{
	double s=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(i<j && j<n-i-1)
				s+=a[i][j];
	return s;
}

double produs(double **a, int n)
{
	double p=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(i>j && j>n-i-1)
				p*=a[i][j];
	return p;
}

double mediaAritmetica(double **a, int n)
{
	double ma=0;
	double nr=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(i>j && j<n-i-1)
			{
				ma+=a[i][j];
				nr++;
			}
	return ma/nr;
}

double mediaGeo(double **a, int n)
{
	double mg=1;
	double nr=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(i<j && j>n-i-1)
			{
				mg*=a[i][j];
				nr++;
			}
	return pow(mg,1/nr);
}

void oglindaSusJos(double **a, int n)
{
	for(int i=0;i<n/2;++i)
		for(int j=0;j<n;++j)
		{
			double aux=a[i][j];
			a[i][j]=a[n-i-1][j];
			a[n-i-1][j]=aux;
		}
}

void oglindaStDrt(double **a, int n)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<n/2;++j)
		{
			double aux=a[i][j];
			a[i][j]=a[i][n-j-1];
			a[i][n-j-1]=aux;
		}
}
