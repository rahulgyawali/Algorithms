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
		

		}
	}

	return 0;

}
