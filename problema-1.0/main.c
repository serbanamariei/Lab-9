#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int **a=0,n;
	printf("n = ");
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	if(a==0)
	{
		fprintf(stderr,"Memorie insuficienta\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;++i)
	{
		*(a+i)=(int *)malloc(n*sizeof(int));
		if(*(a+i)==0)
		{
			fprintf(stderr,"Memorie insuficienta\n");
			exit(EXIT_FAILURE);
		}
	}

	printf("Introduceti valorile din matrice:\n");
	for(int i=0;i<n;++i)
	{
		printf("Linia %d: ",i);
		for(int j=0;j<n;++j)
			scanf(" %d",&*(*(a+i)+j));
	}

	printf("Valorile din matrice:\n");
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			printf("%d ",*(*(a+i)+j));
		}
		printf("\n");
	}

	for(int i=0;i<n;++i)
	{
		memset(*(a+i),0,n*sizeof(int));
		free(*(a+i));
		*(a+i)=0;
	}
	memset(a,0,n*sizeof(int *));
	free(a);
	a=0;

	return 0;
}
