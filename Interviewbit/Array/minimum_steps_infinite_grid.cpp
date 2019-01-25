#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int a;
	int b;
	vector<int> A;
	vector<int> B;
	int i;
	int n;
	int sum = 0;


	cin>>n;

	
	for(i = 0; i < n; i++) {
		
		cin>>a;
		cin>>b;
		A.push_back(a);
		B.push_back(b);
	}

	for(i = 0; i < n-1; i++) {

		sum += max(abs(A[i]-A[i+1]),abs(B[i]-B[i+1]));
	}

	cout<<sum<<endl;

	return 0;
}
