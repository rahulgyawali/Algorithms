#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int rod_cutting(int profit[],int n,int len)
{
	int dp[n+1][len+1];
	int i;
	int j;
	for(i = 0; i < len+1;i++)
		dp[0][i] = 0;
	for(i = 0; i < n+1;i++)
		dp[i][0] = 0;
	for(i = 1;i <len+1;i++)
		dp[1][i] = i*profit[0];
	for(i = 2; i < n+1; i++) {
	
		for(j = 1; j < len+1; j++) {

			if(j < i) {
			
				dp[i][j] = dp[i-1][j];
			}else {
				dp[i][j] = max(dp[i-1][j],profit[i-1]+dp[i][j-i]);
			}
		}	
	}

	return dp[n][len];
}

int main()
{
	int profit[] = {1, 5, 8, 9, 10, 17, 17, 20};
	
	cout<<rod_cutting(profit,8,8)<<endl;

}
