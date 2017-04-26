#include<stdio.h>
#include<stdlib.h>

int safe (int n,int a[n][n],int row,int col)
{
	int i;
	int j;

	for (i = 0; i < col;i++) {

		if (a[row][i])
			return 0;
	}
	
	for (i = row,j = col;i>= 0 && j>=0;i--,j--) {

		if (a[i][j])
			return 0;
	}

	for (i = row,j = col;j>=0 && i<n;i++,j--) {

		if (a[i][j]) 
			return 0;
	}

	return 1;
}

int util(int n,int a[n][n],int cy) 
{
	int i;

	if (cy >= n) {
		
		return 1;
	}

	for (i = 0; i < n; i++) {
			
				
		if (safe(n,a,i,cy)) {

		
			a[i][cy] = 1;

			if (util(n,a,cy+1)) {
	
				return 1;
			}

			a[i][cy] = 0;
		}
	}

 	return 0;

}

void PrintSol(int n,int a[n][n])
{
	int i;
	int j;

	for (i = 0; i < n; i++) {

		for (j = 0; j < n; j++) {

			printf("%d ",a[i][j]);
		}
		
		printf("\n");
	}
}

void solve(int n)
{
	int a[n][n];
	int i;
	int j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) 
			a[i][j] = 0;
		
	
	if(util(n,a,0)==0) {
	
		printf("No Solution\n");
	}else {

		PrintSol(n,a);
	}
	
}

int main()
{
	solve(8);

	return 0;
}
