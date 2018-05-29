#include <bits/stdc++.h>
using namespace std;

struct sets {

	int parent;
	int rank;
};	

struct sets ds[10001];

void makes(int n)
{
	int i;
	for(i = 0; i <= n; i++) {

		ds[i].parent = i;
		ds[i].rank = 0;
	}
}

int find(int x)
{
	if(ds[x].parent != x) ds[x].parent = find(ds[x].parent);
	return x;

}

void uni(int a,int b)
{
	int x= find(a);
	int y= find(b);

	if(a == b) {

		return;
	}else{

		if(ds[x].rank > ds[y].rank) {

			ds[y].parent = x;
		}else if (ds[x].rank < ds[y].rank) {
			ds[x].parent = y;

		}else{
			
			ds[x].parent = y;
			ds[y].rank++;
		}
	}
}


int main()
{
	int i;

	vector<int> g[10001];

	g[1].push_back(2);
	g[2].push_back(1);
	g[1].push_back(6);
	g[6].push_back(1);
	g[2].push_back(3);
	g[3].push_back(2);
	g[5].push_back(2);
	g[2].push_back(5);
	g[4].push_back(3);
	g[3].push_back(4);	
	g[5].push_back(4);
	g[4].push_back(5);

	return 0;
}
