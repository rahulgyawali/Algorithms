#include <bits/stdc++.h>
using namespace std;

void dfs(int s,vector<int> g[],bool vis[],stack<int>& ss)
{
	vis[s] =true;

	int i;

	for(i = 0; i < g[s].size(); i++) {
	
		if(!vis[g[s][i]]) {
		
			dfs(g[s][i],g,vis,ss);
		}
	}

	ss.push(s);
}


int main()
{
	int i;
	vector<int> g[6];
	
	int a;
	int b;
	int e;

	
	cin>>e;

	while(e--)
	{	
		cin>>a;
		cin>>b;
		g[a].push_back(b);
	}

	bool vis[6];

	memset(vis,false,6*sizeof(int));

	stack<int> s;

	for(i = 0; i < 6; i++) {
	
		if(vis[i] == false) {
			
			dfs(i,g,vis,s);
		}
	}

	while(!s.empty()) {
		
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}
