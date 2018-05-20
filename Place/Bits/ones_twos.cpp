#include <bits/stdc++.h>
using namespace std;

int flip(char a)
{
	return (a == '1')?'0':'1';
}

int main()
{
	int i;

	string a;
	string b;
	string c;

	cin>>a;

	for(i = 0; i < a.size(); i++) {
		
		b += flip(a[i]);
	}
	
	cout<<b<<endl;
	c = b;

	for(i  = b.size()-1;i >=0; i--) {

		if(b[i] == '1') {

			c[i] = '0';
		}else {
			c[i] = '1';
			break;
			
		}
	}
	if(i == -1) {
		c = '1' + c;
	}

	cout<<c<<endl;
	return 0;
}
