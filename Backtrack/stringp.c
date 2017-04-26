#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a,char* b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void per(char a[],int l,int r)
{
	int i;

	if (l == r) {

		printf("%s\n",a);

	}else {

		for (i = l; i <= r; i++) {

			swap(a+l,a+i);
			per(a,l+1,r);
			swap(a+l,a+i);
		}	
	}
}

int main()
{
	int i;
	int n;

	char arr[100];

	scanf("%s",arr);

	n = strlen(arr);
	
	per(arr,0,n-1);

	return 0;
}
