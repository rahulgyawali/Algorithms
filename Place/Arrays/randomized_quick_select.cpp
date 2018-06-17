#include <bits/stdc++.h>
using namespace std;

void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[],int start,int end)
{
	int pivot = a[end];
	int pindex = start;
	int i;

	for(i = start; i < end; i++) {
		if(a[i]<=pivot) {
			swap(&a[pindex],&a[i]);
			pindex++;
		}
	}

	swap(&a[pindex],&a[end]);

	return pindex;
}

int random_parition(int a[],int start,int end)
{
	int n = end-start+1;
	int pindex = rand()%n;
	swap(&a[pindex+1],&a[end]);

	return partition(a,start,end);
}


int k_small(int a[],int start,int end,int k)
{
	if(k > 0 && k <= end-start+1) {
		int pindex = random_parition(a,start,end);

		if(pindex -1 == k- 1) {

			return a[pindex];

		}else if (pindex - 1 > k - 1 ) {

			return k_small(a,start,pindex-1,k);
		}

		return k_small(a,pindex+1,end,k-pindex-1+start);
	}

	return INT_MAX;
}

int main()
{
	int i;
	int k;
	int t;
	int n;
	int res;

	cin>>t;

	while(t--) {

		cin>>n;
		
		int a[n];

		for(i = 0; i < n; i++) {

			cin>>a[i];
		}

		cin>>k;

		res = k_small(a,0,n-1,k);

		cout<<res<<endl;
	}	

	return 0;
}
