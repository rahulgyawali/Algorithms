#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	int i;
	int e;
	int a;
	int b;

	cin>>n;

	vector<int> g[n];
	vector<int> indegree(n,0);

	cin>>e;

	for(i = 0; i < e; i++ ) {
	
		cin>>a>>b;
		g[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	vector<int> topo;

	for(i = 0; i < n; i++) {
		
		if(indegree[i] == 0) {
		
			q.push(i);
			
		}
	}

	int count = 0;

	while(!q.empty()) {

		int x = q.front();
		q.pop();
		topo.push_back(x);

		for(i = 0; i < g[x].size(); i++) {

			--indegree[g[x][i]];
			if(indegree[g[x][i]] == 0) {

				q.push(g[x][i]);
			}
		}

		count++;
	}
	if(n != count) {
		cout<<"There's a Cycle :( "<<endl;
		return 0;
	}else{

		cout<<"Topological Sort "<<endl;

		for(i = 0; i < n; i++) {

			cout<<topo[i]<<endl;
		}
	}

	

	return 0;

}
