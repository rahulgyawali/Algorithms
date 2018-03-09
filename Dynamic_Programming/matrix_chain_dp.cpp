#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{

    return a < b ? a:b;
}

int matrix_chain(int A[],int n)
{
    int l;
    int i;
    int j;
    int k;

    int dp[n][n];
    int product;
    

    for(i=1;i< n; i++) {

	for (j = 1;j < n; j++) {

	   if(i == j) {

		dp[i][j] = 0;

	    }
	}
    }

    for(l = 2; l < n; l++) {

	for(i = 1;i < n-l+1; i++) {

	    j = i+l-1;
	    dp[i][j] = INT_MAX;
	    
	    for (k = i; k <= j-1; k++) {

		product = min(dp[i][j],dp[i][k] + dp[k+1][j] + A[i-1]*A[k]*A[j]);		    
		dp[i][j] = product;
	    }
	}	    
    }

    return dp[1][n-1];
}

int main()
{

    int A[]={1,2,3,4};

    cout<<matrix_chain(A,4)<<endl;

    return 0;
}
