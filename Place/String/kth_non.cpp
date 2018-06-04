#include <bits/stdc++.h>
using namespace std;
int main()
{
	string x = "geeksforgeeks";
	int hash[256] = {0};
	int fir[256];
	int k = 3;
	int i;
	
	for(i = 0; i < 256; i++) {

		hash[i] = 0;
		fir[i] = x.size();
	}

	for(i = 0; i < x.size(); i++) {
	
		++(hash[x[i]]);
		if(hash[x[i]] == 1) {
		
			fir[x[i]] = i;
		}
		if(hash[x[i]] == 2) {
		
			fir[x[i]] = x.size();	
		}	
	}

	sort(fir,fir+256);
	
	if(k - 1< x.size() && fir[k-1] != x.size()) {

		cout<<x[fir[k-1]]<<endl;
	}else{
		cout<<-1<<endl;
	}


	return 0;
}	
