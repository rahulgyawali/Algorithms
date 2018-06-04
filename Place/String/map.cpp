#include <bits/stdc++.h>
using namespace std;
int main()
{
	map< int, pair <string,int> > mp;
	mp.insert(make_pair(11,make_pair("hello",4)));
	mp.insert(make_pair(1,make_pair("he",6)));
	mp.insert(make_pair(11,make_pair("hello",9)));
	mp.insert(make_pair(9,make_pair("ello",3)));

	map<int, pair<string,int> >:: iterator mx;

	for(mx = mp.begin() ; mx != mp.end() ; ++mx) {

		cout<<mx->first<<" "<<mx->second.first<<" "<<mx->second.second;
		cout<<endl;
	}
	return 0;
}
