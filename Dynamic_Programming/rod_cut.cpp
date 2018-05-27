#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return a > b? a:b;
}

int rod(int profit[],int n,int len)
{
	int dp[n+1][len+1];
	int i;
	int j;

	memset(dp,0,sizeof(int)*(n)*(len+1));

	
	for(i = 1; i <= n; i++)  {

		for(j = 1; j <= len ; j++) {

			if(i <= j) {

				dp[i][j] = max(profit[i-1] + dp[i][j-i],dp[i-1][j]); 
			}else{

				dp[i][j] = dp[i-1][j];
			}
		}
	}


	return dp[n][len];

}


int main()
{
	int profit[] = {2,5,7,8};

	int n = sizeof(profit)/sizeof(profit[0]);

	cout<<"Max Profit "<<rod(profit,n,5);

	return 0;
}
