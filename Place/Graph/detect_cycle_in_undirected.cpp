#include <bits/stdc++.h>
using namespace std;

bool dfs(int s,vector<int> g[],bool vis[],int parent)
{
	vis[s] = true;
	int i;
	for(i = 0; i < g[s].size(); i++) {

		if(vis[g[s][i]] == false ){
			if(dfs(g[s][i],g,vis,s)) {

				return true;
			}
		}else if (g[s][i] != parent) {

			return true;
		}
	}

	return false;
}

int main()
{
	int i;
	int a;
	int b;
	int e;

	cin>>e;

	vector<int> g[100];

	while(e--)
	{
		cin>>a;
		cin>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	bool vis[5];

	memset(vis,false,sizeof(bool)*5);

	for(i = 0; i < 5; i++) {
	
		if(vis[i] == false ) {

			if(dfs(i,g,vis,-1)) {

				cout<<"YES"<<endl;
				return 0;
			}
		}	
	}

	cout<<"NO"<<endl;

	return 0;
}
