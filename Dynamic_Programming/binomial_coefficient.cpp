#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
    return a<b?a:b;
}

int ncr(int n,int r)
{
    int i;
    int j;

    int dp[n+1][r+1];

    for(i = 0; i <= n; i++) {

	for(j = 0; j <= min(i,r); j++) {
	    
	    if(j == 0|| j == i) {

		dp[i][j] = 1;	 

	    }else{

		dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	    }  
	}
    }

    return dp[n][r];
}

int main()
{
    int n;
    int r;

    cin>>n>>r;

    cout<<ncr(n,r)<<endl;

    return 0;
}
