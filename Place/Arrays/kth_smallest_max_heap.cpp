#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int k;
	int t;
	int n;

	cin>>t;

	while(t--) {

		cin>>n;
		cin>>k;

		int a[n];

		for(i = 0; i < n; i++) {

			cin>>a[i];
		}

		priority_queue<int> pq;
		
		for(i = 0;i < k; i++) {

			pq.push(a[i]);
		}

		for(i = k; i < n; i++) {

			if(a[i] < pq.top()) {

				pq.pop();
				pq.push(a[i]);
			}
		}

		cout<<pq.top()<<endl;
	}	

	return 0;
}
