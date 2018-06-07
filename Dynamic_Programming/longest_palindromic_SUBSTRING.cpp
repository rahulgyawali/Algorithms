#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    int j;
    int l;
    int m;
    int start;
    string x;
    int t;
    int n;
    
    cin>>t;
    
    while(t--) {
        
        cin>>x;
        n = x.size();
        
        bool dp[n][n];
        
        for(i = 0 ; i < n ; i++){
            for(j = 0; j < n ; j++) {
                if(i == j) {
                    dp[i][j] = true;
                }else{
                    dp[i][j] =false;
                }
            }
        }
        m = 1;
        start =0;
         
        for(i=0; i< n-1; i++) {
            
            if(x[i] == x[i+1]) {
                dp[i][i+1] = true;
                if(m != 2) {
                    m = 2;
                    start = i;
                }
                
            }
        }
                
        
        for(l = 3; l <= n; l++){
            for(i = 0; i < n-l+1; i++ ) {
                j = i+l-1;
                 if(x[i] == x[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if(l > m) {
                        m = l;
                        start = i;
                    }
                }
            }
        }
        
        for(i = start; i <= start+m-1; i++) {
            cout<<x[i];
        }
        cout<<endl;
    }
    
    
    return 0;
}
