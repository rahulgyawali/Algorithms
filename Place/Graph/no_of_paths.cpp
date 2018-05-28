#include <bits/stdc++.h>
using namespace std;

void dfs(bool vis[],vector<int> g[],int s, int e,int* ways)
{
	vis[s] = true;
	
	if(s == e) {
		
		*ways = *ways+1;
	}else{
		int i;

		for(i = 0; i < g[s].size(); i++) {

			if(vis[g[s][i]] == false) {
				
				dfs(vis,g,g[s][i],e,ways);
			}
		}	
	}	
	
	vis[s] = false;
}

int main()
{
	vector<int> g[4];

	g[0].push_back(1);
	g[0].push_back(2);
	g[0].push_back(3);
	g[2].push_back( 0);
	g[2].push_back(1);
	g[1].push_back(3);

	int count = 0;
	bool vis[4] = {false};
	
	int* ways = &count;
		
	dfs(vis,g,2,3,ways);
		
	cout<<*ways<<endl;
}
