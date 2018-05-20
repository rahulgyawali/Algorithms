#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={1,3,5};
	int qrr[]={8,7};
	int i;
	int x;
	bitset<10000>b1;
	b1.reset();
	b1[0] = 1;

	for(i  = 0; i < 3; i++) {
		x = arr[i];
		b1 = b1|(b1<<x);
	}
	for(i = 0; i < 2; i++) {
		x = qrr[i];
		if(b1.test(x)) {
			cout<<"YES"<<endl;
		}else{

			cout<<"NO"<<endl;
		}
	}

	return 0;
}	
