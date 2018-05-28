#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={1,2,3};
	int len = 5;

	int dp[4][len+1];

	int i;
	int j;

	for(i = 0 ; i< 4; i++)
		dp[i][0] = true;
	for(i = 1; i < len +1; i++)
		dp[0][i] = false;

	for(i = 1; i < 4; i++) {

		for(j = 1; j <= len; j++) {
	
			if(arr[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j] ||  dp[i-1][j-arr[i-1]];
			}	
		}
	}

	cout<<dp[3][len]<<endl ;

	return 0;
}
