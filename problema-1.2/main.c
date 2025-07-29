#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functii.h"

int main()
{
	int n;
	printf("n = ");
	scanf("%d",&n);
	while(n>20)
	{
		printf("n trebuie sa fie <=20, reintroduceti alta valoare pentru n:\n");
		scanf("%d",&n);
	}

	printf("Cititi valorile din matrice:\n");
	int **a=citire(n,n);

	int ok=1;
	while(ok)
	{
		int alegere;
		printf("\n\nAlegeti ce doriti sa faceti:\n");
		printf("1) Elementele de pe prima linie sa fie in ordine crescatoare\n");
		printf("2) Elementele de pe prima coloana sa fie in ordine crescatoare\n");
		printf("3) Elementele de pe diagonala principala sa fie in ordine crescatoare\n");
		printf("alegere --> ");
		scanf("%d",&alegere);
		switch(alegere)
		{
			case 1:{
					   int **c=copie(a,n);
					   primaLinie(c,n);
					   printf("Matricea cu prima linie crescatoare:\n");
					   afisare(c,n,n);
					   dealocare(c,n,n);
				   }
			break;
			case 2:{
						int **c=copie(a,n);
						primaCol(c,n);
						printf("Matricea cu prima coloana crescatoare:\n");
						afisare(c,n,n);
						dealocare(c,n,n);
				   }
			break;
			case 3:{
					   int **c=copie(a,n);
					   diagP(c,n);
					   printf("Matricea cu prima diagonala crescatoare:\n");
					   afisare(c,n,n);
					   dealocare(c,n,n);
				   }
			break;
			default: printf("Alegere invalida!\n");
			break;
					
		}

		printf("\n\nDoriti sa faceti altceva? 1-DA 0-NU\n");
		printf("alegere --> ");
		scanf("%d",&ok);
	}

	return 0;
}
