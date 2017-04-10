#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min (int d[],int v,int final[])
{
	int i;
	int min = INT_MAX;
	int minindex;

	for (i = 0; i < v; i++) {

		if ( (final[i] == 0) && (d[i] <= min) ) {

			min = d[i];
			minindex = i; 
		}
	}

	return minindex;
}

void print (int d[],int v,int parent[])
{
	int i;
	
	printf("Vertices Distance(From Source) Parent\n"); 	

	for (i = 0; i < v; i++) {

 		printf("%d %d %d\n",i,d[i],parent[i]);

	}

}

void DIJKSTRA (int v,int adj[v][v],int s)
{
	int x;	
	int i;
	int j;
	
	int d[v];                                               //To store distance from source in current shortest path
        int parent[v];                                          //To store Predecessor/Parent in current shortest path
        int final[v];

	for (i = 0; i < v; i++) {
		
		d[i] = 0;
		parent[i] = 0;
		final[i] = 0;
	}

        for (i = 0; i < v; i++) {

                d[i] = INT_MAX;                                         //All vertices are undiscovered at first so they are far from source
                parent[i] = -1;                                         //Since Undiscovered intially noone has Parent/Predecessor
                final[i] = 0;
        }

        d[s] = 0;

	for (i = 0; i < v - 1; i++) {

		x = min(d,v,final);
		final[x] = 1;
		
		for (j = 0; j < v; j++) {

			if (!final[j] && (adj[x][j]) && d[x] != INT_MAX && d[j] > d[x] + adj[x][j]  ) {

				d[j] = d[x] + adj[x][j];
				parent[j] = x;
			
			}		
		}	
	}
	
	print(d,v,parent);
}




int main()
{

	int i;
	int v;
	int e;
	int p;
	int q;
	int s;
	int w;
		
	scanf("%d",&v);						
	int adj[v][v];

	scanf("%d %d %d",&p,&q,&w); 

	for (i = 0; i < (v*v-1); i++) {

		if (p == -1) {

			break;

		} else {			
									
 			adj[p][q] = w;						
			adj[q][p] = w;		

			scanf("%d %d %d",&p,&q,&w);
		}	
	}
	
	scanf("%d",&s);
	
	DIJKSTRA(v,adj,s);	

	return 0;
}

