#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
	if(a < b) {
		if(a < c) return a;
		else return c;
	}else{
		if(b < c) return b;
		else return c;
	}
}

int min_cost(int M[3][3])
{
	int sum = 0;
	int i;
	int j;
	
	for(i = 0; i < 3 ; i++) {
	
		sum += M[0][i];
		M[0][i] = sum;
	}
	sum = 0;
	for(i = 0; i < 3 ; i++) {
		sum += M[i][0];
		M[i][0] = sum;	
	}
	for(i = 1; i  <3; i++) {
	
		for(j = 1; j < 3; j++) {
			
			M[i][j] = M[i][j] + min(M[i-1][j-1],M[i-1][j],M[i][j-1]);
	
		}
	}

	return M[2][2];
}

int main()
{
	int M[3][3] = {{1,2,3},{4,8,2},{1,5,3}};
	cout<<min_cost(M)<<endl;
	return 0;
}
