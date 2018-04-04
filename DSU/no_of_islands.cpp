#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

struct sets{
	int parent;
	int size;
	int rank;
	
};

struct sets ds[MAX];

void make(int n)
{
	int i;
	for(i = 0; i < n; i++) {
		
		ds[i].parent = i;
		ds[i].size = 1;
		ds[i].rank = 0;
	}
}
int R;
int C;

int find(int x)
{
	if(x != ds[x].parent) {
		ds[x].parent = find(ds[x].parent);
	}
	return x;
}

void uni(int fx,int fy)
{
	int x = find(fx);
	int y = find(fy);
	if(x == y) {
		return ;
	}

	if(ds[x].rank < ds[y].rank) {
		ds[x].parent = ds[y].parent;
		ds[y].size += ds[x].size;

	}else if(ds[x].rank > ds[y].rank) {
		ds[y].parent = ds[x].parent;
		ds[x].size += ds[y].size;
	}else{
		ds[x].parent = ds[y].parent;
		ds[y].size += ds[x].size;
		ds[y].rank++;
	}

}	

int island(int R,int C,int M[][5])
{
	int i;
	int j;
	int n = R;
	int m = C;
	make(n*m);
	for(i = 0; i < n; i ++) {
		for(j = 0; j < m; j++) {
			if(M[i][j] == 0) {
				continue;
			}else{
				if( i -1>=0 && M[i-1][j] == 1) {
					uni(i*n + j,(i-1)*n +j);
				}
				if( i + 1< n && M[i+1][j] == 1) {
					uni(i*n + j,(i+1)*n+j);
				}
				if( j -1>=0 && M[i][j-1] == 1) {
					uni(i*n + j,(i)*n+j-1);
				}
				if( j + 1 <m && M[i][j+1] == 1) {
					uni(i*n + j,(i)*n+j+1);
				}
				if( i -1>=0 && j-1 >=0 && M[i-1][j-1] == 1) {
					uni(i*n + j,(i-1)*n+j-1);
				}
				if( i -1>=0 && j+1 <m && M[i-1][j+1] == 1) {
					uni(i*n + j,(i-1)*n+j+1);
				}if(i +1 <n && j-1 >=0 &&  M[i+1][j-1] == 1) {
					uni(i*n + j,(i+1)*n+j-1);

				}if(i +1 <n && j+1 < m && M[i+1][j+1] == 1) {
					uni(i*n + j,(i+1)*n+j+1);
				}

			}

		}
	}
	int count = 0;
	int area = INT_MIN;
	for(i = 0; i < n ;i++) {
		for(j = 0; j < m; j++) {
			if(M[i][j] == 1 && ds[i*n+j].parent == i*n+j) {
				++count;
				
			}

		}
	}
	for(i = 0; i < n*m; i++) {
		if(ds[find(i)].size > area) {
					area = ds[find(i)].size;
		}
	}
	cout<<area<<endl;
	return count;
}

int main()
{
	int M[][5] = {{1, 1, 1, 1, 0},{1, 1, 0, 1, 0},{1, 1, 0, 0, 0},{0, 0, 0, 0, 0}};
	R = 4;
	C = 5;
    int count = island(4,5,M);
    cout<<count<<endl;
	return 0;
}
