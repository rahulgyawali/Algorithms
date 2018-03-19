#include <bits/stdc++.h>
using namespace std;

int lis(int a[],int n)
{
	int i;
	int j;
	int len=1;
	int max=1;
	int index = 0;
	for(i = 1; i < n; i++) {
	
		if(a[i] > a[i-1]) {
		
			len++;	
		}else {

			if(max < len) {

				max = len;
				index = i - max;
			}

			len  = 1;
		}	
	}

	if(max < len) {
		max = len;
	       index = n - max;	
	}		

	for(i = index; i < index+ max ;i++) {
	
		cout<<a[i]<<" ";

	}

	cout<<endl;

	return max;

}

int main()
{	
	int a[] = {5,6,3,5,7,8,9,1,2};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<lis(a,n)<<endl;
	return 0;
}
