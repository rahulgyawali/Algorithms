#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
    return (a < b ? (a < c? a:c) : (b < c?b:c));
}

int dpedit(string X,string Y,int m,int n)
{   
    int i;
    int j;
    
   int  dis[m+1][n+1] ;

    for(i = 0; i <=m ; i++) {

	for(j  = 0; j <= n; j++) {

	    if(i == 0) {
		dis[i][j] = j;
	    }else if(j == 0) {

		dis[i][j] = i;
	    }else if(X[i-1] == Y[j-1]) {

		dis[i][j] = dis[i-1][j-1];
	    }else {
	
		dis[i][j] = 1 + min(dis[i-1][j-1],dis[i-1][j],dis[i][j-1]);
	    }
	}   
    }

    return dis[m][n];

}   

int main()
{
    string X = "sunday";
    string Y = "saturday";

    cout<<dpedit(X,Y,X.size(),Y.size())<<endl;

    return 0;
}
