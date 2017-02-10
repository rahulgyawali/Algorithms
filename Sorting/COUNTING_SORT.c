#include <stdio.h>
#include <stdlib.h>
 
void counting(int *,int,int);

void counting(int a[],int size,int k)
{
	int count[k+1];					//Create an array 'count' that counts occurence of each of the elements in array 'a'
	int output[size]; 
	int i;
	
	for (i = 0; i <= k; i++) {

		count[i] = 0;
	}

	for (i = 0; i < size; i++) {	

		count[a[i]]++;				//Mark Frequency of Each Elements
	}

	for (i = 1; i <= k; i++) {

		count[i] = count[i] + count[i-1];	//Count Cummulative Frequency
	}

	for (i = size - 1; i >= 0; i--) {
		
		output[count[a[i]]-1] = a[i];		//Store sorted output in output array
		count[a[i]]--;
	}

	for (i = 0; i < size; i++) {

		printf("%d\n",output[i]);
		
	}	
}

int main()
{
	int i;
	int n;
	int max;

	scanf("%d",&n);
	
	int a[n]; 				

	for (i = 0; i < n; i++) {

		scanf("%d",&a[i]);	
	}

	max = a[0];

	for (i = 1; i < n; i++) { 

		if (a[i] > max) {

			max = a[i];				
						//Find the max after scanning through array
		}	
	}

	counting(a,n,max);			//Pass the required array with its size and value of maximum elements in array

	return 0;
}
