#include <bits/stdc++.h>
using namespace std;

int check(int arr[],int n)
{
	int i;
	int sum = 0;

	for( i= 0; i < n ; i++)
		sum += arr[i];
	
	if(sum % 2 != 0) return 0;

	int dp[n+1][sum/2+1];
	
	int j;

	for(i = 0; i <= n; i++)
		dp[i][0] = true;

	for(i = 1; i<= sum/2; i++)
		dp[0][i] = false;

	for(i = 1; i <= n; i++) {

		for(j =1; j <= sum/2 ; j++) {

			if(arr[i-1] <= j) {
				dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
			}else{

				dp[i][j] = dp[i-1][j];
			}
		}	
	}

	return dp[n][sum/2];
}

int main()
{
	int arr[] = {4,1,5,9,12};

	if(check(arr,sizeof(arr)/sizeof(arr[0]))) {
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
