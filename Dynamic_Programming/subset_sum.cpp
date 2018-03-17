#include <bits/stdc++.h>
using namespace std;

int subset_sum(int a[],int n,int sum)
{
   int i;
   int j;
   bool dp[n+1][sum+1];

   for(i = 0; i <= n; i++)
      dp[i][0] = true;
   for(i = 1;  i <= sum; i++)
      dp[0][i] = false;

   for(i = 1; i <= n; i++) {

	for(j = 1; j <= sum; j++) {

	   if (a[i-1] > j) {
		
	      dp[i][j] = dp[i-1][j];
	   }else{
	      dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
	   }   
	}
    }
   
     i = n;
     j = sum;

     stack<int> s;

     while(i > 0 && j > 0) {

	if(dp[i][j] == true) {

	    i--;
	}else {
	   s.push(a[i-1]);
	   
	   j = j - a[i-1];
	   i--;
	}
     }

     while(!s.empty()) {
	     
	cout<<s.top()<<" ";	
     	s.pop();
     }
	
    cout<<endl;

    return dp[n][sum];
}
int main()
{
    int a[]={2,3,7,8,10};
    int sum = 11;
    int n = sizeof(a)/sizeof(a[0]);

    cout<<subset_sum(a,n,sum)<<endl;

    return 0;
}
