#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n1;
	int n2;

	vector<int> graph[10000];

	bool prime[10000];

	int i;
	int j;
	
	n1 = 1033;
	n2 = 8179;

	memset(prime,true,sizeof(bool)*10000);

	prime[1] = false;

	for(i = 2; i*i < 10000; i++) {

		if(prime[i] == true) {
		
			for(j = i*i; j < 10000; j+=i) {

				prime[j] = false;
			}
		}
	}

	vector<int> primes;

	for(i=1000; i < 10000; i++) {

		if(prime[i] == true)
			primes.push_back(i);

	}

	for(i = 0; i < primes.size(); i++) {

		for(j = i + 1; j < primes.size() ; j++) {
			
			string x = to_string(i);
			string y = to_string(j);

			int count = 0;
			if(x[0] != y[0])
				count++;
			if(x[1] != y[1])
				count++;
			if(x[2] != y[2])
				count++;
			if(x[3] != y[3])
				count++;
			if(count == 1) {

				graph[i].push_back(j);
				graph[j].push_back(i);


			}

		}
	}

	queue<int> q;
	int vis[10000];
	
	memset(vis,0,10000*sizeof(int));

	for(i = 0; i < primes.size(); i++) {
		if(primes[i] == n1) {
			
			n1 = i;
		}
		
	}

	for(i = 0 ; i <primes.size(); i++) {
		if(primes[i] == n2) {

			n2 = i;
		}
	}

	q.push(n1);
	vis[n1] = 0;
	int e = 0;
	while(!q.empty()) {

		int w = q.front();
		q.pop();
		
		for(i = 0; i < graph[w].size(); i++) {

			if(vis[graph[w][i]] == 0) {

				vis[graph[w][i]] = vis[w] + 1;
				q.push(graph[w][i]);

			}
			if(graph[w][i] == n2) {
			
				cout<<"Shortest path "<<vis[graph[w][i]]<<endl;
				e = 1;
				break;
			}
		}
		if(e == 1)
			break;
	}

	return 0;
}
