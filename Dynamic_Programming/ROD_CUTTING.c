#include <stdio.h>
#include <stdlib.h>

struct rod {
	
	int length;	
	int value;
};

int max (int a,int b) 
{
	if (a > b) {

		return a;
		
	} else if (a < b) {

		return b;
	}
	
	return a;	
}


int main()
{
	int i;
	int n;
	int j;
	int x;
	
	scanf("%d",&n);

	struct rod arr[n+1];
	int b[n+1];
	
	for (i = 1; i <= n; i++) {

		scanf("%d",&arr[i].length);
		scanf("%d",&arr[i].value);
	}

	
	
	b[0] = 0;
	b[1] = arr[1].value;
	
	for (i = 2; i <= n; i++) {

		b[i] = 0;
	}	

	for (i = 2; i <= n; i++) {
		
		x = arr[i].value;				//x stores maximum value for given lenght i

		for (j = 1; j <= i; j++) {

			x = max(x,(arr[j].value + b[i-j]));	//every time we find maximum between max till now and particluar permutation for that lenght
		}

		b[i] = x;
	}

	printf("%d is the maximum profit for length %d\n",b[n],n);

	return 0;
}
