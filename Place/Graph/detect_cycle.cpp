#include <bits/stdc++.h>
using namespace std;

struct sets {

	int parent;
	int rank;
};	

struct sets ds[10001];

void make(int n)
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
	return ds[x].parent;

}

void uni(int a,int b)
{
	int x= find(a);
	int y= find(b);

	if(x == y) {

		return;
	}else{

		if(ds[x].rank > ds[y].rank) {

			ds[y].parent = ds[x].parent;

		}else if (ds[x].rank < ds[y].rank) {
			ds[x].parent = ds[y].parent;

		}else{
			
			ds[x].parent = ds[y].parent;
			(ds[y].rank)++;
		}
	}
}


int main()
{
	int i;
	int e;

	cin>>e;

	int a;
	int b;

	make(6);

	while(e--) {
		cin>>a>>b;
		if(find(a) != find(b)) {
			uni(a,b);
			cout<<ds[a].parent<<" "<<ds[b].parent<<endl;
		}else{
			cout<<"CYCLE"<<endl;
			break;
		}
	}



	return 0;
}
