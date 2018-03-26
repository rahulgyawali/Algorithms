#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int i;
	int j;

	int arr[] = {1, 2, 3, 4, 5, 3, 2};

	int n = sizeof(arr)/sizeof(arr[0]);
	int len[n];
	int Max = INT_MIN;
	for(i = 0; i < n; i++)
		len[i]=1;
	for(i = 1; i < n; i++) {
		j = 0;
		while(j < i) {
		
			if(arr[i]+1==arr[j] || arr[i]-1==arr[j]) {
			
				len[i] = max(len[i],len[j]+1);
			}
			j++;
		}
	}

	for(i = 0; i < n; i++) {
		if(Max < len[i]) {

			Max = len[i];
		}	
	}

	cout<<Max<<endl;

	return 0;
}
