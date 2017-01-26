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

int  main()
{
	int i;
	int n;
	int min;
	int j;

	printf("Enter the size of Array\n");
	scanf("%d",&n);

	int A[n];

	printf("Enter the Elements\n");

	for (i = 0; i < n; i++) {

		scanf("%d",&A[i]);
	}

	for (i = 0; i < n - 1; i++) {

			min = i;

			for (j = i + 1; j < n; j++) {

					if (A[j] < A[min]) {

						min = j;
					}
			}

			swap(&A[i],&A[min]);
	}

	for (i = 0; i < n; i++) {

		printf("%d\n",A[i]);
	}

	return 0;
}
