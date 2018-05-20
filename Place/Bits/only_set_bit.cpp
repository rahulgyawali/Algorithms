#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n && !(n & (n-1))) {

		int i = 1;
		int pos = 1;

		while(!(i&n)) {
			pos++;
			i = i<<1;
		}
		cout<<pos<<endl;
	}else{
		cout<<"Not power of 2\n";
	}
	return 0;
}
