#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int e;
	int a;
	int b;
	int c;
	int i;
	int s;

	cin>>n;
	cin>>e;

	vector <pair<int,int> > g[n+1];

	for(i = 0; i < e ; i++) {
	
		cin>>a>>b>>c;
		
		g[a].push_back(make_pair(c,b));
	
	}


	s = 1;
	
	bool vis[n+1];
	int dis[n+1];
	int par[n+1];

	for(i = 1; i <= n; i++) {

		vis[i] = false;
		dis[i] = 999;
	}

	par[s] = -1;
	dis[s] = 0;

	priority_queue < pair <int,int> ,vector < pair<int,int> > ,greater < pair<int,int> > > p;

	p.push(make_pair(0,s));

	while(!p.empty()) {
		
		pair<int,int> x= p.top();
		p.pop();

		a = x.second;

		if(vis[a] == true)
			continue;

		vis[a] = true;
		

		for(i = 0; i < g[a].size(); i++) {

			int ne = g[a][i].second;
			int wt = g[a][i].first;
			
			if(dis[ne] > wt + dis[a]) {
			
				dis[ne] = dis[a] + wt;
				par[ne] = a;
				p.push(make_pair(dis[ne],ne));
			}
		}
	}

	cout<<"---------------"<<endl;

	for(i = 1; i <= n; i++) {

		cout<<"Parent of "<< i <<" : " << par[i]<<"		"<<" at distance "<<dis[i]<<" 		from "<<s<<endl;
	}

	return 0;
}
