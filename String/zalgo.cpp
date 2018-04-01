#include <bits/stdc++.h>
using namespace std;

vector<int> zalgo(string text,string pattern)
{	
	int i;
	string full = pattern + "$" + text;
	vector<int> z(full.size(),0);
	int l = 0;
	int r = 0;
	int k;

	for(k = 1; k < full.size(); k++) {
		if(k > r) {	

			l = r = k;

			while(r < full.size() && full[r] == full[r-l]) {
				r++;
			}

			z[k] = r-l;
			r--;
		}else{
			int k1 = k - l;

			if(z[k1] + k< r+1) {
				
				z[k] = z[k1];
			}else{
				l = k;
				while(r < full.size() && full[r] == full[r-l]) {

					r++;
				}
				z[k] = r-l;
				r--;
			}
		}
	}

	return z;
}

int main()
{
	string text = "xabcabzabc";
	string pattern = "abc";
	vector<int> zarray = zalgo(text,pattern);
	int i;

	for(i = 0; i < zarray.size(); i++) {
	
		if(zarray[i] == pattern.size() ) {

			cout<<"Found at "<<i-pattern.size()-1<<endl;
		}
	}

	return 0;
}
