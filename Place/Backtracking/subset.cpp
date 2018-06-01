#include <bits/stdc++.h>
using namespace std;

void check(int arr[],int f[],int n,int t_size,int sum,int it,int target)
{
	int i;

	if(sum == target) {

		for(i = 0; i < t_size; i++)
			cout<<f[i]<<" ";
		cout<<endl<<"--------------"<<endl;

		if( it + 1 < n && sum - arr[it] + arr[it+1] <= target )	
			check(arr,f,n,t_size-1,sum-arr[it],it+1,target);

	}else {
	
		if(it < n && sum + arr[it] <= target) {
		
			for( i = it; i < n; i++) {
				
				f[t_size] = arr[i];

				check(arr,f,n,t_size+1,sum+arr[i],i+1,target);
			}
		}
	}
}

void solve(int arr[],int target,int n)
{	
	int i;
	int f[n];
	int total = 0;

	for(i =0; i < n; i++)
		total += arr[i];

	if(arr[0] <= target && total >= target) {

		check(arr,f,n,0,0,0,target);
	}else{

		cout<<"No Solution"<<endl;
	}	
}

int main()
{
	int arr[8] = {15, 22, 14, 26, 32, 9, 16, 8};
	int target = 53;

	sort(arr,arr+8);
	
	solve(arr,target,8);

	return 0;
}
