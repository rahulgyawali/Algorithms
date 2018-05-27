#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}

int minCoin(int arr[],int m,int n)
{	
	int i;
	int j;
	int dp[n+1];
	int res[n+1];

	dp[0] = 0;

	memset(dp,0,sizeof(int)*(n+1));
	memset(res,-1,sizeof(int)*(n+1));

	for(i = 1 ; i <= n; i++) {
	
		dp[i] = INT_MAX;
	}

	for(i = 0; i < m ; i++) {

		for (j = 1; j <= n ; j++) {

			if(arr[i] <= j && dp[j-arr[i]] != INT_MAX) {
					
				dp[j] = min(dp[j], 1 + dp[j-arr[i]]);
				res[j] = arr[i];
			}
		}
	}

	return dp[n];
}	

int main()
{
	int arr[] = {7,2,3,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"minimum coins for 13 is "<<minCoin(arr,n,13)<<endl;
	return 0;
}
