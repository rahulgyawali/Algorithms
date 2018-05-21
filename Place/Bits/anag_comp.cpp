#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int b = ~a;
	int arr[32];
	int brr[32];

	int i = 0;
	while(a) {
		arr[i] = a%2;
		a = a/2;
		i++;
	}
	i = 0;
	while(b) {
		brr[i] = b%2;
		b =b/2;
		i++;
	}
	sort(arr,arr+32);
	sort(brr,brr+32);
	for(i = 0;i < 32; i++) {
		if(arr[i] != brr[i]) {
		
			cout<<"NO"<<endl;
			return 0;	
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
