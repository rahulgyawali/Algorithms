#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int lcs(string X,string Y)
{
    int m = X.size();
    int n = Y.size();

    int i;
    int j;
    int longest=0;
    int dp[m+1][n+1];

    for(i=0; i <= m; i++) {

	   for(j = 0; j <= n; j++) {

	       dp[i][j] = 0;
	   }
    }


    for(i = 1; i <= m; i++) {
	
	    for(j = 1; j <= n; j++) {

	        if(X[i-1] == Y[j-1]) {

		       dp[i][j] = dp[i-1][j-1]+1;
		       longest = max(longest,dp[i][j]);

	       }
	   }
    }   

    return longest;
}

int main()
{
    string X;
    string Y;

    cin>>X>>Y;
    cout<<lcs(X,Y)<<endl;

    return 0;
}
