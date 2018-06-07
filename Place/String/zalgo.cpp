#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int left;
	int right;
	int k;
	int k1;

	string x;
	string pattern;

	getline(cin,x);
	getline(cin,pattern);

	int m = pattern.size();
	pattern = pattern + '$';
	pattern = pattern + x;

	int z[pattern.size()];
	
	left = 0;
	right = 0;

	for(k  = 1; k < pattern.size(); k++){

		if(k > right){
			left = k;
			right = k;

			while(right < pattern.size() && pattern[right] == pattern[right-left]){

				right++;
			}

			z[k] = right - left;
			right--;

		}else{

			k1 = k -left;

			if(k1 < right -k + 1) {

				z[k] = z[k1];
			}else{
				
			     left = k;

			     while(right < pattern.size() && pattern[right] == pattern[right-left]) {

					right++;
			    }  
			    
			    z[k] = right-left;
			   right--;

			}
		}

	}

	for(i = 0; i < pattern.size();i++) {

		if(z[i] == m) {

			cout<<"Found at index "<<i-m-1<<endl;
		}	
	}	

	return 0;
}
