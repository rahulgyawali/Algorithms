#include <bits/stdc++.h>
using namespace std;
int main()
{
	int pos;
	int level;
	cin>>level>>pos;
	if(__builtin_popcount(pos-1)%2==0) {
		cout<<"Engineer"<<endl;

	}else {

		cout<<"Doctor"<<endl;
	}	
	return 0;
}
