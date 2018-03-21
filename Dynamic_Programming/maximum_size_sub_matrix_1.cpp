#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
	return a<b?(a<c?a:c):(b<c?b:c);
}
int main()
{
	int M[6][5] = {{0,1,1,0,1},{1,1,0,1,0},{0,1,1,1,0},{1,1,1,1,0},{1,1,1,1,1},{0,0,0,0,0}};
	
	int n = 5;
	int s[6][5];
	int i;
	int j;

	for(i = 0; i < 5; i ++) {

		s[0][i] = M[0][i];
	}

	for(i = 0; i < 6; i++) {

		s[i][0] = M[i][0];
	}

	for(i = 1; i  < 6; i++) {

		for( j = 1; j < 5; j++) {

			if(M[i][j] == 1) {
			
				s[i][j] = min(s[i-1][j],s[i-1][j-1],s[i][j-1])+1;
			}else{
			
				s[i][j] = 0;
			}	
		}
	}
	int max = s[0][0];
	int mr = 0;
	int mc = 0;


	for(i = 0; i <6; i++) {

		for(j = 0;j < 5; j++) {
	
			if(max < s[i][j]) {
				max = s[i][j];
				mr = i;
				mc = j;
			}
		}
	}

	for(i = mr;i > mr-max ; i--) {

		for(j = mc; j > mc-max;j--) {

			cout<<M[i][j]<<" ";
		
		}
		cout<<endl;
	}
	return 0;
}	
