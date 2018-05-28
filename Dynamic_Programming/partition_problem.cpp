#include <bits/stdc++.h>
using namespace std;

int find(int arr[],int n,int sum)
{
	if(sum == 0) return 1;
	if(n < 0 && sum != 0) return 0;

	if(arr[n] > sum)
		return find(arr,n-1,sum);

	return find(arr,n-1,sum-arr[n]) || find(arr,n-1,sum);

}

int check(int arr[],int n)
{
	int i;
	int sum = 0;

	for(i = 0; i < n; i++) 
		sum+= arr[i];

	return find(arr,n-1,sum/2);
	
	
}

int main()
{
	int arr[] = {3,1,5,9,12};

	if(check(arr,sizeof(arr)/sizeof(arr[0]))) {
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
