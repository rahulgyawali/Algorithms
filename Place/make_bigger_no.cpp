#include <bits/stdc++.h>
using namespace std;

bool compare(string x,string y)
{
	string a = x.append(y);
	string b = y.append(x);

	return a.compare(b) > 0 ? true:false;
}

int main()
{
	vector<string> v;
	v.push_back("54");
    v.push_back("546");
    v.push_back("548");
    v.push_back("60");

    sort(v.begin(),v.end(),compare);

    int i;

    for(i = 0; i < v.size() ; i++) {
    	cout<<v[i];
    }

    cout<<endl;

	return 0;

}
