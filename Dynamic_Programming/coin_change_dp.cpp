#include <bits/stdc++.h>
using namespace std;
/*
int count(int S[],int m,int N)
{
    if(N < 0) return 0;
    else if (N== 0) return 1;
    else if (m <= 0 && N>=1) return 0;
    
    
    return count(S,m-1,N) + count(S,m,N-S[m-1]);
}
*/


int countdp(int m,int S[],int N)
{   
    int i;
    int j;

    int dp[m+1][N+1];

    for(i = 0; i <= m; i++)
        dp[i][0] = 1;
    
    for(i = 1; i<= N; i++ )
        dp[0][i] = 0;
    
    for(i = 1; i <  m+1; i++) {
        
        for(j = 1; j < N+1 ; j++) {
            
            if(S[i-1] > j) {
		    dp[i][j] = dp[i-1][j];
	    }
            else {
		    dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]];
        	
	    }
        }
        
    }	
	
    return dp[m][N];
}

int main()
{
    int S[] = {1,2,3};
    int N = 4;

//    cout<<count(S,3,N)<<endl;
      cout<<countdp(3,S,N)<<endl;
    return 0;
}
