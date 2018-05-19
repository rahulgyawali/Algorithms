#include <bits/stdc++.h>
using namespace std;
int main()
{
	string x = "abcdefaabaal";
	int p = 1331;
	int hash1[x.size()];
	int hash2[x.size()];

	int i;
	hash2[x.size()-1] = x[x.size()-1];
	hash1[0] = x[0];
	int pi[x.size()];
	pi[0] = 1;

	for(i = 1; i < x.size(); i++) {
		pi[i] = pi[i-1]*p;
	}

	for(i = 1; i < x.size(); i++) {

		hash1[i] = hash1[i-1]*p + x[i];
	}

	for(i = x.size()-2;i >= 0; i--) {

		hash2[i] = hash2[i+1]*p + x[i];
	}

	int l;
	int r;
	cin>>l>>r;

	if(hash1[r] - hash1[l-1]*pi[r-l+1] == hash2[l] - hash2[r+1]*pi[r-l+1]) {
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
