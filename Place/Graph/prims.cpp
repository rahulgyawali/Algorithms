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

	vector <pair<int,int> > g[n];

	for(i = 0; i < e ; i++) {
	
		cin>>a>>b>>c;
		
		g[a].push_back(make_pair(c,b));
		g[b].push_back(make_pair(c,a));
	}


	s = 0;
	
	bool vis[n];


	for(i = 0; i <= n; i++) {

		vis[i] = false;
	}



	priority_queue < pair <int,int> ,vector < pair<int,int> > ,greater < pair<int,int> > > p;

	p.push(make_pair(0,s));
	int cost  = 0;

	while(!p.empty()) {
		
		pair<int,int> x= p.top();
		p.pop();

		a = x.second;

		if(vis[a] == true)
			continue;

		vis[a] = true;
		
		cost += x.first;

		for(i = 0; i < g[a].size(); i++) {

			int ne = g[a][i].second;
			int wt = g[a][i].first;
			
			if(vis[ne] == false) {

				p.push(make_pair(wt,ne));
			}
		}
	}

	cout<<cost<<endl;

	return 0;
}
