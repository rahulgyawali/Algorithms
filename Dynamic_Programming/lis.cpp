#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int A[] = {3,4,-1,0,6,2,3};
    int i;
    int j;
    int n = sizeof(A)/sizeof(A[0]);
    int LIS[n];
    int max;	

    for(i = 0; i < n; i++) {

	LIS[i] = 1;
    }

    int res[n];

    memset(res,-1,sizeof(int)*n);

    for(i = 1; i <n; i++) {
	j = 0;
	
	while(j < i) {

	    if(A[j] < A[i]) {

		if(LIS[i] < LIS[j]+1) {

			LIS[i] =LIS[j] + 1;
			res[i] = A[j];
		}
	    }
	    j++;
	}   

    }

   for(i = 0; i < n ; i++) {
	
	if(res[i] != -1) {

		cout<<res[i]<<" ";	
	}
    }

   cout<<endl;

    max = 1;
	
    for(i = 0; i < n; i++) {
	    if(LIS[i] > max) {
		max = LIS[i];    
	    }	
    }	
	
    cout<<max<<endl;
	
    return 0;
}
