#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n,alegere;
	printf("n = ");
	scanf("%d",&n);
	double **a;
	int ok=1;
	printf("Cititi valorile matricii:\n");
	a=citire(n);
	printf("\n\nValorile matricii dvs:\n");
	afisare(a,n);
	while(ok)
	{
		printf("\n\nAlegeti ce doriti sa faceti:\n");
		printf("1) Norma infinit\n");
		printf("2) Norma 1:\n");
		printf("3) Norma 2:\n");
		printf("alegere --> ");
		scanf("%d",&alegere);

		switch(alegere)
		{
			case 1:{
					   printf("\nNorma infinit a matricii dvs este %.3lf\n",normaInfinit(a,n));
				   }
				   break;
			case 2:{
					   printf("\nNorma 1 a matricii dvs este: %.3lf\n",norma1(a,n));
				   }
				   break;
			case 3:{
					   printf("\nNorma 2 a matricii dvs este: %.3lf\n",norma2(a,n));
				   }
				   break;
			default: printf("Alegere invalida\n");
					 break;
		}

		printf("Doriti sa faceti si altceva? 1-DA 0-NU\n");
		printf("alegere --> ");
		scanf("%d",&ok);
	}
	
	for(int i=0;i<n;++i)
	{
		memset(a[i],0,n*sizeof(double));
		free(a[i]);
		a[i]=0;
	}
	memset(a,0,n*sizeof(double));
	free(a);
	a=0;

	return 0;

}
