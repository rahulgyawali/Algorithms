#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int i;
	string x = "geeks";
	string y = "forgeeks";

	int count1[26] = {0};
	int count2[26] = {0};

	for(i = 0; i < x.size(); i++)
		count1[x[i]-'a']++;
	for(i = 0; i < y.size(); i++)
		count2[y[i]-'a']++;

	string h = "";
	int j;

	for(i = 0; i < 26; i++) {
	
		if(count1[i] && count2[i]) {

			for(j = 0; j < min(count1[i],count2[i]); j++) {

				h = h + (char)('a'+i);
			}	
		}
	}

	cout<<h<<endl;
	return 0;
}
