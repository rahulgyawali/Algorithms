#include <bits/stdc++.h>
using namespace std;

struct cmp {

	bool operator() ( pair<int,char> a,pair<int,char> b)
	{
		if(a.first > b.first) {
		
			return false;

		}else if (a.first == b.first){

			if(a.second < b.second) {	

				return false;
			}	
		}
		return true;
	}		
};

int main()
{
	priority_queue< pair<int,char> , vector< pair<int,char> > ,cmp> pq;

	pq.push(make_pair(1,'z'));
	pq.push(make_pair(15,'p'));
	pq.push(make_pair(15,'a'));
	
	while(!pq.empty()) {
		pair<int,char> x = pq.top();
		cout<<x.first<<" "<<x.second;
		cout<<endl;
		pq.pop();
	}

	return 0;
}
