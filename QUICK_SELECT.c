#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition (int a[],int low,int high)
{
	int pindex;
	int pivot;
	int i;

	pivot = a[high];
	pindex = low;

	for (i = low; i < high; i++) {

		if (a[i] >= pivot) {

			swap(&a[pindex],&a[i]);
			pindex++;
		}
	}

	swap(&a[high],&a[pindex]);

	return pindex;
}

int quickselect (int a[],int low,int high,int k)
{
	int p;
	
	p = partition(a,low,high);

	if (p == k-1) {

		return a[p];

	}else if (p < k-1) {

		return quickselect(a,p+1,high,k);

	}else if (p > k-1) {

		return quickselect(a,low,p-1,k);
	}
}

int main()
{
	int n;
	int i;
	int k;

	scanf("%d",&n);
	scanf("%d",&k);

	int a[n];

	for (i = 0; i < n; i++) {

		scanf("%d",&a[i]);

	}

	int x = quickselect(a,0,n-1,k);
	
	printf("%d",x);
}
