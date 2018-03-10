#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int lps(string X,int n)
{
    int i;
    int w;
    int j;    
    int dp[n][n];

    for(i=0; i <n; i++)
       dp[i][i] = 1;

    for(w = 2; w <=n; w++) {

	for(i = 0; i < n+1-w; i++) {

	    j = i + w -1;

	    if((X[i] == X[j])&&w == 2)
	       dp[i][j] = 2;
	    else if (X[i] == X[j])
	       dp[i][j] = 2 + dp[i+1][j-1];
	    else
	       dp[i][j] = max(dp[i+1][j],dp[i][j-1]);

	}
    }

    return dp[0][n-1];
}

int main()
{
    string X = "GEEKS FOR GEEKS";
    int n = X.size();
    cout<<lps(X,n)<<endl;
    return 0;
}
