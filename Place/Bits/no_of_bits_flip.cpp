#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	int count;
	int b;
	int c;

	cin>>a>>b;

	c = a^b;

	count = 0;

	while(c) {
		c  = c & (c-1);
		count++;
	}

	cout<<count<<endl;
	return 0;
}
