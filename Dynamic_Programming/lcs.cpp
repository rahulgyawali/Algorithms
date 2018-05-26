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
    int LCS[m+1][n+1];

    memset(LCS,0,sizeof(int)*(m+1)*(n+1));
    for(i = 1; i <= m; i++) {

       for(j = 1; j <= n; j++) {
	
	  
	  if(X[i-1] == Y[j-1]) {

		LCS[i][j] = 1+LCS[i-1][j-1];
	    }else {

		LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
	    }
	}
    }

   i = m;
   j = n;
   stack<char> ss;
   while(i > 0 && j > 0) {
	
	   if(LCS[i][j] > LCS[i][j-1] && LCS[i][j] > LCS[i-1][j]) {
		ss.push(X[i-1]);
		i--;
		j--;
	   }else{

	   	if(LCS[i-1][j] > LCS[i][j-1]) {
			i--;
		}else {
			j--;
		}
	   }
   }

    while(!ss.empty()) {
	cout<<ss.top();
	ss.pop();
    }
    
    cout<<endl;

    return LCS[m][n];
}

int main()
{
    string x = "AGGTAB" ;
    string y =	"GXTXAYB";
    cout<<lcs(x,y)<<endl;
    
    return 0;
}

