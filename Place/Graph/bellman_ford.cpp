#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int n;
	int e;
	int a;
	int b;
	int c;
	int j;

	cin>>n>>e;

	pair<pair<int,int>,int >  g[e];

	for(i = 0;i < e; i++) {

		cin>>a;
		cin>>b;
		cin>>c;

		g[i].first.first = a;
		g[i].first.second = b;
		g[i].second = c;
		

	}

	int dis[n];

	for(i = 0 ; i < n ; i++) {

		dis[i] = 999999;
	}	

	dis[0] = 0;

	for(i = 0; i < n-1;i++) {

		for(j = 0; j < e; j++) {

			a = g[j].first.first; 
			b = g[j].first.second;
			c = g[j].second;

			if(dis[b] > dis[a] + c) {
	
				dis[b] = dis[a] + c;
			}
		}

	}

	for(i = 0; i < n-1; i++) {

		for(j = 0; j < e ; j++) {

			a = g[j].first.first;
			b = g[j].first.second;
			c = g[j].second;

			if(dis[b] > dis[a] + c) {

				cout<<"Negative Cycle"<<endl;
				return 0;
			}
		}
	}

	cout<<"From 0 the distances are "<<endl;

	for(i = 0; i < n ; i++) {

		cout<<dis[i]<<endl;
		
	}

	return 0;
}
