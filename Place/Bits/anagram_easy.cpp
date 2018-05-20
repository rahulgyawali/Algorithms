#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	int n;

	cin>>m>>n;							//Take Two No.s as input 

	if(__builtin_popcount(m) == __builtin_popcount(n)) {		// Check if No. of ones are equal
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
