#include <bits/stdc++.h>
using namespace std;

bool dfs(bool vis[],bool rs[],vector<int> g[],int s)
{
	if(vis[s] == false) {
		vis[s] = true;
		rs[s] = true;

		int i;

		for(i = 0; i < g[s].size(); i++) {

			if(vis[g[s][i]] ==false && dfs(vis,rs,g,g[s][i])) {

				return true;


			} else if (rs[g[s][i]] == true) {

					return true;
			}
		}
	}

	rs[s] = false;
	return false;
}


int main()
{
	vector<int> g[1001];

	int i;
	int e;

	cin>>e;

	int a;
	int b;

	while(e--) {

		cin>>a>>b;

		g[a].push_back(b);

	}

	bool vis[4];
	bool rs[4];

	memset(vis,false,sizeof(bool)*4);
	memset(rs,false,sizeof(bool)*4);

	for(i = 0; i < 4; i++) {

		if(vis[i] == false) {

			if(dfs(vis,rs,g,i)) {

				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
