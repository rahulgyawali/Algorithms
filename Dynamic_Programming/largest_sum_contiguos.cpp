#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int lsca(int  a[],int n)
{
    int i;
    int cm = a[0];
    int fm = a[0];

    for(i = 1; i < n ; i++) {

	cm = max(cm+a[i],a[i]);
	fm = max(fm,cm);
    }

    return fm;
}

int main()
{
    int a[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<lsca(a,n)<<endl;

    return 0;
}
