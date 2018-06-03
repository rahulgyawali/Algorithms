#include <bits/stdc++.h>
using namespace std;
int main()
{
	string x = "geeksforgeeks";
	int hash[256] = {0};
	int fir[256];

	int i;
	
	for(i = 0; i < x.size(); i++) {
	
		++(hash[x[i]]);
		if(hash[x[i]] == 1) {
		
			fir[x[i]] = i;
		}

		
	}

	int index = INT_MAX;

	for(i = 0; i < 256; i++) {

		if(hash[i] == 1 && fir[i] < index) {

			index = fir[i];
		}
	}
	
	if(index == INT_MAX) {

		cout<<"Such doesn't exist"<<endl;

	}else {

		cout<<x[index]<<endl;
	}

	return 0;
}	
