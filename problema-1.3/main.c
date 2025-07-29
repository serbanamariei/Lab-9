#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n,m;
	printf("n = ");
	scanf("%d",&n);
	printf("m = ");
	scanf("%d",&m);

	printf("Cititi valorile matricii:\n");
	int **a=citire(n,m);

	printf("\n\nMatricea dvs:\n");
	afisare(a,n,m);

	int ok=1;
	while(ok)
	{
		int alegere;
		printf("\n\nAlegeti ce doriti sa faceti:\n");
		printf("1) Diagonala principala sa fie crescatoare\n");
		printf("2) Diagonala secundara sa fie crescatoare\n");
		printf("3) Linia mediana verticala sa fie crescatoare (nr coloane impar)\n");
		printf("alegere --> ");
		scanf("%d",&alegere);

		switch(alegere){
			case 1:{
					   int **c=copie(a,n,m);
					   printf("Matricea dvs cu diagonala principala crescatoare:\n");
					   diagP(c,n,m);
					   afisare(c,n,m);
					   dealocare(c,n,m);
				   }
				   break;
			case 2:{
					   int **c=copie(a,n,m);
					   printf("Matricea dvs cu diagonala secundara crescatoare:\n");
					   diagS(c,n,m);
					   afisare(c,n,m);
					   dealocare(c,n,m);
				   }
				   break;
			case 3:{
					   int **c=copie(a,n,m);
					   printf("Matricea dvs cu linia verticala crescatoare:\n");
					   linieV(c,n,m);
					   afisare(c,n,m);
					   dealocare(c,n,m);
				   }
				   break;
			default: printf("Alegere invalida!\n");
					 break;
		}

		printf("Doriti sa faceti altceva? 1-DA 0-NU\n");
		printf("alegere --> ");
		scanf("%d",&ok);
	}

	return 0;
}
