#include <stdio.h>
#include <stdlib.h>

void swap (int*,int*);

void swap (int* a,int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int i;
	int n;
	int k;
	int j;

	printf("Enter the size of Array (BUBBLE)\n");
	scanf("%d",&n);

	int A[n];

	printf("Enter the Elements\n");

	for (i = 0; i < n; i++) {

		scanf("%d",&A[i]);
	}

	for (i = 0; i < n - 1; i++) {

		for (j = 0; j < n - i - 1; j++) {

				if (A[j] > A[j+1]) {

					swap(&A[j],&A[j+1]);
				}

		}
	}

	for (i = 0; i < n; i++) {

		printf("%d\n",A[i]);
	}


	return 0;
}
