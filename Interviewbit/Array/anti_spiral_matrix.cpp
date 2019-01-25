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
	stack<int> s;

	for(i = 0; i < m; i++) {

		for(j = 0; j < n; j++) {

			cin>>matrix[i][j];
		}
	}
	
	dir = 0;

	while(left <= right && top <= bottom) {

		if(dir == 0) {

			for(i = left; i <= right; i++) {

				s.push(matrix[top][i]);
			}

			top++;
			
		}

		else if(dir == 1) {

			for(i = top; i<= bottom; i++) {
		
				s.push(matrix[i][right]);
			}

			right--;
		}


		else if(dir == 2) {

			for(i = right; i >= left; i--) {


				s.push(matrix[bottom][i]);
			}
			
			bottom--;

		}	
		
		else if(dir == 3) {

			for(i = bottom; i >= top; i--) {

				s.push(matrix[i][left]);
			}
			
			left++;

		}

		dir = (dir+1)%4;
	}

	while(!s.empty()) {

		cout<<s.top()<<" ";
		s.pop();

	}


	return 0;
}
