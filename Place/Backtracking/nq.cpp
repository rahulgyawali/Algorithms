#include <bits/stdc++.h>
using namespace std;

int safe(int row ,int col,int n,vector< vector<int> > & dp)
{
	int i;
	int j;
	

	for(i = 0; i < col; i++) {
	
		if(dp[row][i] == 1)
			return 0;
	}

	for(i = row,j = col ; i >= 0 && j>= 0    ;i--,j--) {
		if(dp[i][j])
			return 0;

	}

        for(i = row,j = col ; i< n && j>= 0    ;i++,j--) {
		     if(dp[i][j])
			return 0;
	}

	return 1;

}


int solve(int col,int n,vector <vector <int> > &dp)
{
	if(col >= n)
		return 1;

	int i;
	for(i = 0; i< n; i++) {

		if(safe(i,col,n,dp)) {

			dp[i][col] = 1;

			if(solve(col+1,n,dp)) {
	
				return 1;
			}

			dp[i][col] = 0;
		}
	}

	return 0;
}

void sol(int n)
{
	vector< vector<int> > dp (n,vector<int> (n,0));

	int i;
	int j;

	if(solve(0,n,dp)) {

		for(i = 0; i < n; i++) {

			for(j = 0; j < n; j++) {


				cout<<dp[i][j]<<" ";
			}

			cout<<endl;
		}
	}else{

		cout<<"Not psss"<<endl;
	}
}



int main()
{
	int n;
	cin>>n;
	sol(n);
	return 0;
}
