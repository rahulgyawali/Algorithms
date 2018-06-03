#include <bits/stdc++.h>
using namespace std;
int main()
{
	string x = "geeksforgeeks";
	int hash[256] = {0};
	int i;
	
	for(i = 0; i < x.size(); i++) {
	
		hash[x[i]]++;
	}
	int index = -1;

	for(i = 0; i < x.size(); i++) {

		if(hash[x[i]] == 1) {

			index = i;
			break;
		}
	}
	
	if(index == -1) {

		cout<<"Such doesn't exist"<<endl;

	}else {

		cout<<x[index]<<endl;
	}

	return 0;
}	
