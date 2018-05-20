#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	string a;
	cin>>a;
	for(i = 0; i < a.size(); i++) {
		if(a[i] <=90)	{

			a[i] += 1<<5;
		}else{
			a[i] -= 1<<5;
		}
	}

	cout<<a<<endl;
	return 0;
}
