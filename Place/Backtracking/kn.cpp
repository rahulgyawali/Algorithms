#include <bits/stdc++.h>
using namespace std;
int safe(int n,int a,int b,vector< vector<int> > &dp)
{
	if(a >= 0 && b>=0 && a<n && b < n) {
	    if(dp[a][b] == -1){
	        return 1;
	    }
	}
	return 0;
}
int done(int n,int i,int j,int move,int xm[8],int ym[8],vector< vector<int> > &dp)
{
	if(move == n*n)
		return 1;
	int k;
	int nx;
	int ny;

	for(k = 0; k < 8; k++) {

		nx = i + xm[k];
		ny = j + ym[k];

		if(safe(n,nx,ny,dp)) {

			dp[nx][ny] = move;

			if(done(n,nx,ny,move+1,xm,ym,dp)) {

				return 1;
			}else{

				dp[nx][ny] = -1;
			}
		}
	}

	return 0;
}

void check(int n)
{
	int i;
	int j;

	vector< vector<int> > dp ( n, vector<int> (n,-1));


	dp[0][0] = 0;

	int xm[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int ym[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

	if(done(n,0,0,1,xm,ym,dp)) {

		for(i = 0;i < n; i++) {

	                for(j = 0; j  < n; j++) {

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
	int n;
	cin>>n;
	check(n);
	return 0;
}

