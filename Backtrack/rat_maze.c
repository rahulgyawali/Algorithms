#include<stdio.h>
#include<stdlib.h>

void PrintSol(int n,int sol[n][n]) 
{
	int i;
	int j;

	for (i = 0; i < n ; i++) {

		for (j = 0; j < n; j++) {
		
			printf("%d ",sol[i][j]);
		}
	
		printf("\n");
	}

}

int safe(int n,int nx,int ny,int a[n][n]) 
{
	
	return ((nx >=0 && nx < n) &&(ny >= 0 && ny < n) && a[nx][ny] == 1);
}


int util(int n,int cx,int cy,int sol[n][n],int a[n][n])
{
	int i;
	int j;
	int nx;
	int ny;
	if ((cx == n-1) && (cy == n-1)) {
		sol[cx][cy] = 1;
		return 1;
	}

	for (i = 0;i < 2;i++) {

		if (i == 0) {

			if(safe(n,cx,cy,a)) {
				
				nx = cx;
				ny = cy + 1;
				sol[cx][cy] = 1;
				
				if (util(n,nx,ny,sol,a) == 1) {

					return 1;
				}else{	
	
					sol[cx][cy] = 0;
				}
			}

		}else if (i == 1) {
			
		
			if (safe(n,cx,cy,a)) {
				
				nx = cx + 1;
				ny = cy;
				sol[cx][cy] = 1;

				if (util(n,nx,ny,sol,a) == 1) {

					return 1;	
				}else {

					sol[cx][cy] = 0;
			
				}
			}
		}
	}

	return 0;	
}

void solve(int n,int a[n][n])
{
	int sol[n][n];
	int i;
	int j;
	
	for (i = 0; i < n; i++) {
	
		for (j = 0; j < n; j++) {
		
			sol[i][j] = 0;
		}
	}

	if (util(n,0,0,sol,a) == 0) {

		printf("Doesn't Exist\n");
	}else {

		PrintSol(n,sol);	
	}	
}

int main()
{
	int a[4][4] = { {1,0,0,0},
		      {1,1,0,1},
		      {0,1,0,0},			
		      {1,1,1,1}
		   };

	solve(4,a);
}
