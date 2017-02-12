#include <stdio.h>
#include <stdlib.h>

void swap (int*,int*);
int partition (int**,int,int);
void quicksort (int**,int,int);

void swap (int* a,int* b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition (int a[][2],int low,int high)
{
	int pivot;
	int pindex;
	int i;

	pivot = a[high][0];
	pindex = low;
	
	for (i = low; i < high; i++) {

		if ((a[i][0] < pivot) || ((a[i][0] == pivot) && (a[i][1] < a[high][1]))) {
	
			swap(&a[i][0],&a[pindex][0]);
			swap(&a[i][1],&a[pindex][1]);	
			pindex++;	
		}
	}

	swap(&a[high][0],&a[pindex][0]);
	swap(&a[high][1],&a[pindex][1]);	

	return pindex;
}

void quicksort (int a[][2],int low,int high)
{
	if (low < high) {

		int pindex = partition(a,low,high);
		quicksort(a,low,pindex-1);
		quicksort(a,pindex+1,high);
	}
}

int  main()
{
	int i;
	int n;
	int j;
	
	scanf("%d",&n);

	int a[n][2];	

	for (i = 0; i < n; i++) {

		for (j = 0; j < 2; j++) {

			scanf("%d",&a[i][j]);
	
		}
	}

	quicksort(a,0,n-1);
	printf("Sorted Output\n");
	for (i = 0; i < n; i++) {

		for (j = 0; j < 2; j++) {

			printf("%d ",a[i][j]);
	
		}
		printf("\n");
	}
	

}
