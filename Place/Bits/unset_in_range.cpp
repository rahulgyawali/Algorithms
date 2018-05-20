#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int num;
	int l;
	int r;
	cin>>n;
	cin>>l>>r;
	unsigned int x = (1 << (sizeof(int)*8-1)) - 1 ;
	num = ((1 << r)-1)^((1<<(l-1))-1);
	num = x ^ num;
	n = n & num;
	cout<<n<<endl;
	return 0;
}
