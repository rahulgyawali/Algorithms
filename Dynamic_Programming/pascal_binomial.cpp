#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
    return a>b?a:b;
}

int ncr(int n,int r)
{
    int i;
    int j;

    int C[r+1] ;

    for( i =0; i <=r; i++)
       C[i] = 0;

    C[0] = 1;

    for(i = 1; i <= n; i++) {

	for( j = min(i,r); j > 0 ; j--) {
	    
	    C[j] = C[j] + C[j-1];
	}
    }

    return C[r];
}

int main()
{
    int n;
    int r;
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
   return 0;

}
