#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{

    return a>b?a:b;
}

int ksp(int val[],int wt[],int W,int n)
{
    int dp[n+1][W+1];
    int i;
    int j;

    for(i = 0;i < n+1; i++) {

	for(j = 0; j < W+1; j++) {

	    dp[i][j] = 0;
	}
    }

    for(i = 1;i<=n;i++) {

	for(j = 1; j <= W; j++) {

	    if(wt[i-1] > j) dp[i][j] = dp[i-1][j];
	    else
	       dp[i][j] = max(dp[i-1][j],val[i-1] + dp[i-1][j-wt[i-1]]);
    
	}	
    }
	
    i = n;
    j = W;

    stack<int> items;

    while(i> 0 && j > 0) {

	if(dp[i][j] != dp[i-1][j] ){
		items.push(wt[i-1]);
		j = j - wt[i-1];
		i--;
	}else{
		i--;
	}
    }
	

    cout<<"-------------ITEMS-------------------------"<<endl;
    while(!items.empty()) {

		cout<<items.top()<<endl;
		items.pop();

    }

    return dp[n][W];
}

int main()
{
    int val[] = {1,4,5,7};
    int wt[] = {1,3,4,5};
    int W = 7;

    cout<<ksp(val,wt,W,4)<<endl;
   
   return 0;
}
