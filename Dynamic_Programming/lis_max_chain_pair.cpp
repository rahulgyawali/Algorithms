#include <bits/stdc++.h>
using namespace std;

int max_chain(vector < pair <int,int> > v)
{
	int i;
	int j;
	int LIS[v.size()];
	int max = 1;

	for(i = 0; i < v.size(); i++) {

		LIS[i] = 1;
	}	

	for(i  = 1; i < v.size(); i++) {

		j = 0;

		while(j < i) {

			if(v[j].second < v[i].first && LIS[i] < LIS[j] +1) {

				LIS[i] = LIS[j] + 1;
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
	vector < pair<int,int> > v;
	v.push_back(make_pair(15,25));
	v.push_back(make_pair(50,60));
	v.push_back(make_pair(5,24));
	v.push_back(make_pair(27,40));

	sort(v.begin(),v.end());

	cout<<max_chain(v)<<endl;

	return 0;
}
