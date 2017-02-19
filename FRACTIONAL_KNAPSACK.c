#include <stdio.h>
#include <stdlib.h>

struct item {

	int value;
	int weight;
};


void swap(int* a,int *b)
{	
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(struct item a[],int start,int end)
{
	double pivot;
	int pindex;
	int i;
	
	pindex = start;
	pivot = (double)((a[end].value) /(a[end].weight)) ;
	
	for (i = start; i < end; i++) {
		
		if (((double)((a[i].value)/(a[i].weight))) >= pivot) {
			
			swap(&a[i].value,&a[pindex].value);
			swap(&a[i].weight,&a[pindex].weight);
			pindex = pindex + 1;
	
		}
	}

	swap(&a[end].value,&a[pindex].value);
	swap(&a[end].weight,&a[pindex].weight);
	
	return pindex;
}

void quicksort(struct item a[],int start,int end)
{
	if (start < end) {
		
		int pindex;
		
		pindex = partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	
	}
}


double FractionalKnapsack(int w,struct item arr[],int n)
{
	int i;
	int cw = 0;
	double fvalue = 0.0;

	quicksort(arr,0,n-1); //Sort Items by Value/Weight Ratio in Descending order

	for (i = 0; i < n; i++) {
	
		if (cw + arr[i].weight <= w) {

			cw = cw + arr[i].weight;
			fvalue = fvalue + arr[i].value;
		}else {
			int remain = w - cw;	//Take remaining weight
			fvalue = fvalue + ((double)arr[i].value)*((double)remain/arr[i].weight); //Add value to Fraction of Wight
			break;
		}
	}

	return fvalue;
}

int main()
{
	int i;
	int n;
	int w;
	double max;

	printf("No.of Items and Max Weight\n");
	scanf("%d %d",&n,&w);
	
	struct item arr[n];

	for (i = 0; i < n; i++) {
		
		scanf("%d %d",&arr[i].value,&arr[i].weight);
	}

	max = FractionalKnapsack(w,arr,n);

	printf("%lf is Max\n",max);

	return 0;

}
