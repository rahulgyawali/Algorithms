#include <bits/stdc++.h>
using namespace std;

int min(int a,int b){
	return a<b?a:b;
}

int max(int a,int b){
	return a>b?a:b;
}

int valx(char a)
{
    if(a == 'I'){
        return 1;
    }
    if(a == 'V'){
        return 5;
    }
    if(a == 'X'){
        return 10;
    }
    if(a == 'L'){
        return 50;
    }
    if(a == 'C'){
        return 100;
    }
    if(a == 'D'){
        return 500;
    }
    if(a == 'M'){
        return 1000;
    }
    return -1;
}

int main()
{
	int i;
	int j;
	int n;
	int t;

    string x;
    

    int res;
    int a;
    int b;

	cin>>t;
   
	while(t--){
	    
        cin>>x;
        
        
        res = 0;
        
        for(i = 0; i < x.size(); i++) {
            
            a = valx(x[i]);
            
            
            if(i+1 < x.size()){
                
                b = valx(x[i+1]);
                
                if(a >= b){
                    
                    res = res + a;
                        
                }else{
                    
                    res = res + (b-a);
                    i++;
                }
                
            }else{
                res = res + a;
                
            }
        }
        //cout<<endl;
        cout<<res<<endl;
	}


	return 0;
}