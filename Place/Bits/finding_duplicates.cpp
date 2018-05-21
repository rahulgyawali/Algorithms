#include <bits/stdc++.h>
using namespace std;
int main()
{	
	int arr [] = {1,2,4,2,4,5,6,7,3,5};
	int i;
	
	bitset<32000> bs;

	bs.reset();

	for(i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++) {
		
		if(bs.test([arr[i]])) {
			cout<arr[i]<<endl;

		}else {

			bs = bs ^ (1<<arr[i]);
		}	
	}

	return 0;
}
