#include <bits/stdc++.h>
using namespace std;
int MAX(int a,int b)
{
	return a>b?a:b;
}
int max_sum_is(vector <int>  v)
{
	int i;
	int j;
	int LIS[v.size()];
	int max = 0;

	for(i = 0; i < v.size(); i++) {

		LIS[i] = v[i];
	}	

	for(i  = 1; i < v.size(); i++) {

		j = 0;

		while(j < i) {

			if(v[j] < v[i]) {

				LIS[i] = MAX(LIS[j] + v[i],LIS[i]);
			}

			j++;
		} 
	}

	for(i = 0; i < v.size(); i++) {
		if(max < LIS[i]) {

			max = LIS[i];
		}
	}

	return max;

}

int main()
{	
	vector<int> v(7);
	v[0] = 1;
	v[1] = 101;
	v[2] = 2;
	v[3] = 3;
	v[4] = 100;
	v[5] = 4;
	v[6] = 5;


	cout<<max_sum_is(v)<<endl;

	return 0;
}
