#include <bits/stdc++.h>
using namespace std;

string get(string x)
{
	int hash[26] = {0};
	int i;

	for(i = 0 ; i < x.size(); i++) {
		hash[x[i]-'a']++;
	}

	string h = "";

	for(i = 0; i < 26 ; i++) {
		if(hash[i] != 0){
			h = h + (char)(i+'a');
		}
	}

	return h;

}

void find(vector<string> v)
{
	string x;
	int i;
	map<string,vector<int> > mp;
	for(i = 0; i < v.size(); i++) {
		x = get(v[i]);
		mp[x].push_back(i);
	}
	map<string,vector<int> >::iterator mx;

	for(mx = mp.begin(); mx != mp.end(); ++mx) {

		for(auto it = (*mx).second.begin(); it != (*mx).second.end(); ++it ) {

			cout<<v[*it]<<" ";
		}
		cout<<endl;
	}

}

int main()
{
	int i;
	int j;

	vector<string> v;
	v.push_back("may");
	v.push_back("yam");
	v.push_back("glow");
	v.push_back("logw");
	v.push_back("wlog");


	find(v);

	return 0;
}
