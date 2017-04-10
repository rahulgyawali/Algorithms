#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void floyd(int n,int adj[n][n])
{
	int d[n][n];
	int i;
	int j;
	int k;

	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++) {

			d[i][j] = 0;
		
		}
	}	

	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++) {

			d[i][j] = adj [i][j];
		}
	}

	for (k = 0; k < n; k++) {

		for( i = 0; i < n; i++) {

			for (j = 0; j < n; j++) {

				if (d[i][k] + d[k][j] < d[i][j]) {

					d[i][j] = d[i][k] + d[k][j];	
	
				}
			}
		}
		
	}

	printf("ALL PAIR SHORTEST MATRIX\n");

	for ( i = 0; i < n; i++) {

		for (j = 0; j < n;j++) {
		
				if (d[i][j] == 99999) {

					printf("INF ");	
				}else {

					printf("%d  ",d[i][j]);
				}
		}
		
		printf("\n");
	}

}


int main()
{
	int i;
	int j;
	int n;
	int a;
	int b;
	int c;

	scanf("%d",&n);

	int adj[n][n];


	for (i = 0; i < n; i++) {

		for (j = 0; j < n ;j ++) {
	
			adj[i][j] = 0;
		}
	}

	scanf("%d %d %d",&a,&b,&c);


	for (i = 0; i < n*(n-1); i++) {

		if (a == -1) {

			break;
		}
		
		adj[a][b] = c;	

		scanf("%d %d %d",&a,&b,&c);

	}

	for (i = 0; i < n; i++) {
		for(j = 0; j <n;j++) {
			
			if (!(adj[i][j] > 0 )) {

				if (i != j) {


					adj[i][j] = 99999;
				}		
			}
		}
	}

	
	floyd(n,adj);
	
	return 0;
}

