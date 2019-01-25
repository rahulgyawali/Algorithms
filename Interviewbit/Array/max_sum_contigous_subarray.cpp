#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{

	return a>b?a:b;
}

int main()
{
	int i;
	int n;
	int x;
	
	cin>>n;
	
	vector<int>a;

	for(i=0;i<n;i++) {
		cin>>x;
		a.push_back(x);
	}

	int till = a[0];
	int mex = a[0];

	for(i = 1; i < n ; i++) {
;
		till = max(a[i],a[i]+till);
		mex = max(mex,till);
	}

	cout<<mex<<endl;

	return 0;
}
