#include <bits/stdc++.h>
using namespace std;

int safe(int n,int a,int b,vector< vector<int> > & arr)
{
	if(a>=0 && b>=0 && a<n && b<n) {
	
		if(arr[a][b] ==1) {

			return 1;
		}
	}

	return 0;
}


int done(int n,int a,int b,vector< vector<int > > & dp, vector< vector<int> > &arr)
{
	if(a == n-1 && b == n-1) {

		dp[a][b] = 1;
		return 1;
	}

	if(safe(n,a,b,arr)) {

		dp[a][b] = 1;

		if(done(n,a+1,b,dp,arr)) {

			return 1;
		}
		
		if(done(n,a,b+1,dp,arr)){

			return 1;
		}

		dp[a][b] = 0;
		return 0;
	}

	return 0;
}

void sol(int n,vector< vector<int > > & arr)
{
	vector< vector<int> > dp (n , vector<int> (n , 0));
	int i;
	int j;

	
	if(done(n,0,0,dp,arr)) {
		for( i= 0; i < n ; i++) {

			for(j = 0; j < n; j++) {

				cout<<dp[i][j]<<" ";
			}

			cout<<endl;
		}
	}else{

		cout<<"No"<<endl;
	}
}

int main()
{
	int i;
	int j;
	int n;
	int x;

	cin >>n;

	vector< vector<int> > arr (n , vector<int> (n) );

	for(i = 0; i < n ; i++) {
	
		for(j = 0; j < n; j++) {
			cin>>x;
			arr[i][j] = x;
		}
	}	
	sol(n,arr);

	return 0;
}
