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
		LIS[i] = LDS[i] = a[i];

	}

	for(i = 1; i < n; i++) {
		j = 0;
		while(j < i) {
			if(a[j] < a[i]) {
				LIS[i] = max(LIS[i],LIS[j]+a[i]);
			}
			j++;
		}
	}
	for(i = n-2; i >=0; i--) {
		j = n-1;
		while(j > i) {
			if(a[j] < a[i]) {
				LDS[i] = max(LDS[i],LDS[j]+a[i]);
			}
			j--;
		}
	}

	int Max = INT_MIN;

	for(i = 0; i < n; i++) {
		
		Max = max(Max,LIS[i]+LDS[i]-a[i]);
		
	}
	return Max;
}

int main()
{
	int a[] = {1,15,51,45,33,100,12,18,9};
	cout<<lbs(a,sizeof(a)/sizeof(a[0]))<<endl;
}