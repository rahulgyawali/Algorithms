#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 4156;
	vector<char> v;
	int i;
	int j;
	int rem;
	
	while(n){
		rem = n%16;
		if(rem > 9) {
			v.push_back(rem%10+'A');
		}else{
			v.push_back(rem+'0');
		}
		n = n/16;
	}

	reverse(v.begin(),v.end());
	for(i = 0; i < v.size();i++)
		cout<<v[i];
	cout<<endl;
	return 0;
}
