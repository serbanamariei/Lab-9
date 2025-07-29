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

	printf("\n\nCitim matricea:\n");
	int **matrice=citire(n,m);
	printf("\n\nMatricea:\n");
	afisare(matrice,n,m);
	printf("\n\nMatricea ordonata:\n");
	ordonare(matrice,n,m);
	afisare(matrice,n,m);

	dealocare(matrice,n,m);

	return 0;
}
