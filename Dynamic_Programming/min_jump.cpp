#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{

    return a<b?a:b;   
}

int minj(int a[],int n)
{   
    int MNJ[n];
    int i,j,x;
    int results[n];
    results[0] = -1;
    if(n == 0 || a[0] == 0) return INT_MAX;

    for(i=1;i<n;i++)
       MNJ[i] = INT_MAX;
    MNJ[0] = 0;
    

    for(i = 1; i < n; i++) {

	j  = 0;

	while(j < i) {
	    x = a[j];
	
	    if(x + j >= i) {

		MNJ[i] = min(MNJ[i],MNJ[j]+1);
		
		results[i] = a[j];
	    }

	   j++;
	}    
    }
    
    set<int>s;
	
    for(i=1; i < n; i++)
	s.insert(results[i]);
	
    set<int>:: iterator it;
	
    for(it=s.begin();it != s.end() ;++it) {
	cout<<*it<<" ";
    }
	
    cout<<"---\n";    
    return MNJ[n-1];
}

int main()
{
    int a[] = {2,3,1,1,2,4,2,0,1,1};

    cout<<minj(a,10)<<endl;

    return 0;
}
