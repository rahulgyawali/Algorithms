#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{   
    return a < b ?(a < c?a:c):(b<c?b:c);
}

int mins(int cost[3][3],int m,int n,int x,int y)
{
    int dp[m+1][n+1];
    int i;
    int j;
    

    dp[0][0] = cost[0][0];
    for(i = 1; i <=m; i++) {

	dp[0][i] = cost[0][i]+dp[0][i-1];
    }

    for(i=1; i<=n;i++) {

       dp[i][0] = cost[i][0] + dp[i-1][0];
    }

    for(i = 1; i <=m ; i++) {

	for(j = 1; j <=n ; j++) {

	    
		dp[i][j] = cost[i][j] + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
	}
    }
    

    return dp[m][n];
}

int main()
{

   int cost[3][3] = {{1,2,3},
    
		    {4,8,2},
		    {1,5,3}
		};

    cout<<mins(cost,2,2,0,0)<<endl;
    return 0;
}
