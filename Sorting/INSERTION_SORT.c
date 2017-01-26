#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int hole;
	int value;
	int n;

	scanf("%d",&n);

	int a[n];

	for (i = 0; i < n; i++) {

		scanf("%d",&a[i]);
	}

	for (i = 1; i < n; i++) {

			value = a[i];
			hole = i;

			while (hole > 0 && a[hole-1] > value) {

				a[hole] = a[hole - 1];
				hole = hole - 1;
			}		

			a[hole] = value;
	}

	for (i = 0; i < n; i++) {

		printf("%d\n",a[i]);
	}

	return 0;
}