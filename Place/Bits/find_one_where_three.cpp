#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int x;
	int n;
	set<int>s;
	int tsum = 0;
	int isum = 0 ;
	set<int>::iterator it;
	int result;

	cin>>n;

	for(i = 0; i < n; i++) {
		cin>>x;
		tsum += x;
		s.insert(x);	
	}
	
	for(it = s.begin();it!=s.end() ; ++it) {
		isum+=*it;

	}

	result = (3*isum - tsum)/2;
	cout<<result<<endl;

	return 0;
}
