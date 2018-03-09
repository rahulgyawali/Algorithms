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
    int i,j;
    int LCS[m+1][n+1] = {0} ;

    for(i = 1; i <= m; i++) {

       for(j = 1; j <= n; j++) {
	
	  
	  if(X[i-1] == Y[j-1]) {

		LCS[i][j] = 1+LCS[i-1][j-1];
	    }else {

		LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
	    }
	}
    }

    return LCS[m][n];
}

int main()
{
    string x = "abcdaf";
    string y =	"acbc";
    cout<<lcs(x,y);
    return 0;
}

