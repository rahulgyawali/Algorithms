#include <bits/stdc++.h>
using namespace std;

int max(int a,int b,int c)
{
    return a>b?(a>c?a:c):(b>c?b:c);
}

int lcs_three(string A,string B,string C)
{
    int m = A.size();
    int n = B.size();
    int p = C.size();

    int i;
    int j;
    int k;

    int dp[m+1][n+1][p+1];

    for(i = 0 ; i <=m; i++) {

       for(j = 0; j <=n; j++) {

	    for(k = 0; k <=p; k++) {
	
		dp[i][j][k] = 0;

	    }

	}
    }

    for(i = 1; i <=m; i++) {
	
	for(j = 1; j <=n; j++) {

	    for(k = 1; k <= p; k++) {
	    
		if(A[i-1] == B[j-1] && B[j-1] == C[k-1] && C[k-1] == A[i-1]) {

		    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
		}else {

		    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]);
		}   
	    }	
	}    
    }
/*
    vector<char> v;

    i = m;
    j = n;
    k = p;

    while( i > 0 && j > 0 && k > 0) {

	if(A[i-1] == B[j-1] || B[j-1] == C[k-1] || C[k-1] == A[i-1]) {
	    
		v.push_back(A[i-1]);
		i--;
		j--;
		k--;
	}else {

		if (dp[i-1][j][k] > 		
    

	}
    }	
*/
    return dp[m][n][p];
}

int main()
{
    string a;
    string b;
    string c;

    cin>>a>>b>>c;
    cout<<lcs_three(a,b,c)<<endl;

    return 0;
}
