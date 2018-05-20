#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{	
	int n;
	cin>>n;
	cout<<"METHOD 1\n";
	cout<<log2(n&~n)+1<<endl;
	cout<<"METHOD 2\n";
	cout<<ffs(n)<<endl;
	return 0;
}
