#include <bits/stdc++.h>
using namespace std;
int find(vector<int>&v,int l,int r,int x)
{
    int m;
    while(r-l>1){
        m = l+(r-l)/2;
        if(v[m]>=x){
            r = m;
        }else{
            l = m;
        }
    }
    return r;
}
int main() {
	//code
	int t;
	int n;
	int x;
	int i;
	int len;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int> a;
	    for(i=0;i<n;i++) {
	        cin>>x;
	        a.push_back(x);
	    }
	    
	    vector<int> tail(n);
	    tail[0]=a[0];
	    len = 1;
	    for(i = 1; i < n; i++) {
	        if(a[i] < tail[0]){
	            tail[0] = a[i];
	           // cout<<i<<" if"<<endl;
	        }else if(a[i] > tail[len-1]){
	            tail[len] = a[i];
	            len++;
	            //cout<<i<<" else if"<<endl;
	        }else{
	            tail[find(a,-1,len-1,a[i])] =a[i];
	            //cout<<i<<" else"<<endl;
	        }
	    }
	    cout<<len<<endl;
	}
	return 0;
}