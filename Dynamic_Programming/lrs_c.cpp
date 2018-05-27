#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{

    return a>b?a:b;
}

int lrs(string X)
{
    int i;
    int j;
    int n  = X.size();

    int dp[n+1][n+1];


    for( i = 0 ; i <= n; i++)
       for(j = 0; j <= n; j++)
	  dp[i][j] = 0;

    for(i = 1; i <= n ; i++) {

	for( j =1; j <= n ; j++) {

	    if((X[i-1] == X[j-1])&&(i != j)) {
		    
		dp[i][j] = 1 + dp[i-1][j-1];

	    }else {

		dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	    }
	}
    }

    vector<char> v;

    i = n;
    j = n;

    while(i > 0 && j > 0) {

	if(dp[i][j] > dp[i-1][j] &&  dp[i][j] > dp[i][j-1]) {

	   v.push_back(X[i-1]);
	    i--;
	    j--;

	}else{
	    
		if (dp[i-1][j] == dp[i][j]) {
		
		    i--;
		}else {

		    j--;
	}	}
    }   


    reverse(v.begin(),v.end());

    for( i= 0 ; i < v.size(); i++)
	cout<<v[i];

    cout<<endl;

    return dp[n][n];
}

int main()
{
    string X;
    cin>>X;
    cout<<lrs(X)<<endl;

}
