#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
	return a>b?a:b;
}

int lbs(int a[],int n)
{
	int i;
	int LIS[n];
	int j;
	int LDS[n];

	for(i = 0; i < n; i++) {
		LIS[i] = LDS[i] = 1;

	}

	for(i = 1; i < n; i++) {
		j = 0;
		while(j < i) {
			if(a[j] < a[i]) {
				LIS[i] = max(LIS[i],LIS[j]+1);
			}
			j++;
		}
	}
	for(i = n-2; i >=0; i--) {
		j = n-1;
		while(j > i) {
			if(a[j] < a[i]) {
				LDS[i] = max(LDS[i],LDS[j]+1);
			}
			j--;
		}
	}

	int Max = LIS[0] + LDS[0]-1;

	for(i = 1; i < n; i++) {
		if(Max < LDS[i] + LIS[i] -1) {
			Max = LDS[i] + LIS[i] -1;
		}
	}
	return Max;
}

int main()
{
	int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
	cout<<lbs(a,sizeof(a)/sizeof(a[0]))<<endl;
}
