#include <stdio.h>
#include <stdlib.h>
#define max 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void input(int* a, int n )
{
	int i;
	for (i=0; i<n ; i++)
	{
		printf("Enter element[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
int printAsc (int* a, int n)
{
	int** adds= (int**)calloc(n, sizeof(int*));
	int i,j;
	for (i=0; i<n; i++)
		adds[i]=&a[i];
	int* t;
	for (i=0; i<n-1; i++)
		for (j=n-1; j>i;j--)
			if (*adds[j]<*adds[j-1])
			{
				t=adds[j];
				adds[j]=adds[j-1];
				adds[j-1]=t;
			}
	for (i=0;i<n;i++)
	printf("%d ",*adds[i]);
}

void add (int value, int* a, int* pn)
{
	a[*pn] = value;
	(*pn)++;
}
int main(int argc, char *argv[]) {
	int value;
	int num;
	int* a;
	char key;
	do
	{
		a=(int*) calloc (num,sizeof(int));
		do
		{
			printf("Please enter size of array: ");
			scanf("%d",&num);		
		} 
		while (num <=1 || num > max);
		input(a,num);
		printf("The array after sorting:\n ");
		printAsc(a,num);
		printf("\nPlease enter the new value: ");
		scanf("%d",&value);
		add(value,a,&num);
		printf("New array:\n ");
		printAsc(a,num);
		printf("\nPress any key to continue, Exit if press ESC.");
		key=getchar();
		key=getch();
		printf("\n");
	}
	while (key!=27);
	return 0;
}
