#include <stdio.h>
#include <stdlib.h>

int tme;

void dfs (int state[],int parent[],int d[],int f[],int v,int g[][1000])
{

	int i;

	for (i = 0; i < v; i++) {

		state[i] = -1;
		parent[i] = -1;

	}

	tme = 0;
	printf("\n");
	
	for (i = 0; i < v; i++) {

		if (state[i] == -1) {

			DFSVISIT(i,state,parent,d,f,v,g);

		}

	}

	
}

void DFSVISIT (int u,int state[],int parent[],int d[],int f[],int v,int g[][1000])
{
	int i;

	tme = tme + 1;
	d[u] = tme;
	state[u] = 0;
	printf("%d ",u);
	
	for (i = 0; i < v; i++) {

		if (g[u][i] == 1) {

			if (state[i] == -1) {

				parent[i] = u;
				DFSVISIT(i,state,parent,d,f,v,g);

			}
		}
	}
	
	state[u] = 1;
	tme = tme + 1;
	f[u] = tme;
}

int main()
{
	int max;
	int v;
	int e;
	int i;
	int j;
	int x;
	int y;
	int g[1000][1000];    							//Adjancency Matrix 'g'of int of  1000x1000

	scanf("%d %d",&v,&e);

	for (i = 0; i < v; i++) {

		for (j = 0; j < v ; j++) {

			g[i][j] = 0;
		}
	}
	
	for (i = 0; i < e; i++) {

		scanf("%d %d",&x,&y);						//Nodes with Edges in Undirected Graph

		g[x][y] = 1;

	}


	int state[v];
	int parent[v];
	int d[v];
	int f[v];

	for (i = 0; i < v; i++) {
	
		state[i] = -1;							//All Nodes are Unvisited initially
		parent[i] = -1;
		d[i] = 0;
		f[i] = 0;
	}


	dfs(state,parent,d,f,v,g);

	return 0;
}

