#include <bits/stdc++.h>
using namespace std;

void make(int parent[],int x)
{
	int i;
	for(i = 0; i < x; i++) {
		parent[i] = i;
	}
}


int find(int parent[],int x)
{
	if(parent[x] !=x) {
		parent[x] = find(parent,parent[x]);
	}

	return parent[x];
}

void uni(int parent[],int a,int b)
{
	int x = find(parent,a);
	int y = find(parent,b);

	if(x == y) {
		return ;
	}else{
		parent[y] = parent[x];
	}
	
}


int kruskal(int parent[],vector<pair <int , pair<int,int> > > & edges)
{
	
	int i;
	int count  = 0;
	int a;
	int b;

	for(i = 0; i < edges.size(); i++) {
		
		a = edges[i].second.first;
		b = edges[i].second.second;	
		

		if(find(parent,a) != find(parent,b)) {

			count = count +  edges[i].first;
			uni(parent,a,b);
			cout<<a<<" "<<b<<" "<<edges[i].first<<endl;
			
		}
	}

	return count;	
}


int main()
{
	int i;
	int e;
	int a;
	int b;
	int c;

	vector<pair<int,pair<int,int> > > edges;

	cin>>e;

	int parent[1000];

	make(parent,1000);

	while(e--)
	{
		cin>>a>>b>>c;
		edges.push_back(make_pair(c,make_pair(a,b)));

	}

	sort(edges.begin(),edges.end());

	cout<<kruskal(parent,edges)<<endl;
	return 0;
}
