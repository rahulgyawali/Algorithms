#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int j;
	string a;
	cin>>a;

	for(i = a.size()-1; i>=0; i--) {
		if(a[i] == '1') {
	
			break;
		}
	}
	
	if(i == -1) {

		a = '1' + a;
	}else {
		
		for(j = i-1; j >=0 ; j--) {

			a[j] = (a[j] == '1')?'0':'1';
		}
	}

	cout<<a<<endl;

	return 0;
}
