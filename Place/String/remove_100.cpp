#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i;
    int tmp;
    string x;
    int t;
    int maxlen;
    
    cin>>t;
    
    while(t--){
        
        cin>>x;
        maxlen = 0;
        vector< pair<char,int> > v;
        
        v.push_back(make_pair('@',-1));
        
        for(i = 0; i < x.size(); i++){
            v.push_back(make_pair(x[i],i));
            
            while(v.size() >= 3 && v[v.size()-3].first == '1' && v[v.size()-2].first == 'O' && v[v.size()-1].first == '0'){
                v.pop_back();
                v.pop_back();
                v.pop_back();
            }
         
            tmp = v.back().second;
            
            maxlen = max(maxlen,i-tmp);
            
        }
        cout<<maxlen<<endl;
    }
    
    
    return 0;
}