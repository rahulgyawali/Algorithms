#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int j;
	int m;
	int n;

	cin>>m;
	cin>>n;

	int left;
	int right;
	int top;
	int bottom;
	int dir;

	left = 0;
	right = n-1;
	top = 0;
	bottom = m-1;

	int matrix[m][n];

	for(i = 0; i < m; i++) {

		for(j = 0; j < n; j++) {

			cin>>matrix[i][j];
		}
	}
	
	dir = 0;

	while(left <= right && top <= bottom) {

		if(dir == 0) {

			for(i = left; i <= right; i++) {

				cout<<matrix[top][i]<<" ";
			}

			top++;
			
		}

		else if(dir == 1) {

			for(i = top; i<= bottom; i++) {
		
				cout<<matrix[i][right]<<" ";
			}

			right--;
		}


		else if(dir == 2) {

			for(i = right; i >= left; i--) {


				cout<<matrix[bottom][i]<<" ";
			}
			
			bottom--;

		}	
		
		else if(dir == 3) {

			for(i = bottom; i >= top; i--) {

				cout<<matrix[i][left]<<" ";
			}
			
			left++;

		}

		dir = (dir+1)%4;
	}

	return 0;
}
