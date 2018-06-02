#include <bits/stdc++.h>
using namespace std;

int safe(int c,int color[],int v,vector<int> g[])
{
	int i;

	for(i = 0; i < g[v].size(); i++) {

		if(color[g[v][i]] == c) {

			return 0;
		}
	}

	return 1;
}

bool assign(int v,int n,int color[],int m,vector<int> g[])
{
	if(v == n)
		return true;

	int i;

	for(i =1; i <= m ; i++) {


		if(safe(i,color,v,g)) {

			color[v] = i;


			if(assign(v+1,n,color,m,g)) {

				return true;
			}

			color[v] = 0;
		}

	}

	return false;
}	


void start(int n,int m, vector<int> g[])
{
	int color[n];

	int i;


	for(i = 0; i < n ; i++) {

		color[i] = 0;
	
	}


	if(assign(0,n,color,m,g) == true){

		for(i = 0; i < n; i++) {

			cout<<color[i]<<endl;
		}
	}else{

		cout<<"No solution"<<endl;
	}

}

int main()
{
	int n;
	int e;
	int a;
	int b;
	int m;

	cin>>m;
	cin>>n;
	vector<int> g[n];
	cin>> e;

	while(e--) {
		cin>>a;
		cin>>b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	start(n,m,g);
	return 0;

}
