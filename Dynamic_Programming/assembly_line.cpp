#include <bits/stdc++.h>
using namespace std;

int min(int a,int b){
	return a<b?a:b;
}

int main()
{
	int A[2][4] = {{4,5,3,2},{2,10,1,4}};
	int t[2][4] = {{0,7,4,5},{0,9,2,8}};
	int e[] = {10,12};
	int x[] = {18,7};
	int T[2][4];

	int i;
	int j;

	T[0][0] = e[0] + A[0][0];
	T[1][0] = e[1] + A[1][0];

	for(i = 1; i < 4; i++) {
		T[0][i] = min(T[0][i-1]+A[0][i],T[1][i-1] + t[1][i] + A[0][i]);
		T[1][i] = min(T[1][i-1]+A[1][i],T[0][i-1] + t[0][i] + A[1][i]);
	}

	cout<<min(T[0][3]+x[0],T[1][3] + x[1])<<endl;
}