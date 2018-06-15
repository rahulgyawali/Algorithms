#include <bits/stdc++.h>
using namespace std;

void replace_con(int a[],int n)
{
    stack<int> ss;
    int i;
    int curr;
  
    for(i = 0; i < n; i++) {

        if(ss.empty() || ss.top()!=a[i]){     //If there's a Mismatch from current element or stack is empty then push
            ss.push(a[i]);
          
        }else{

            curr = a[i];                       //Here we've got a match with stack's top
            
            while(!ss.empty()&&curr==ss.top()){
                                                 // while we get match we keep poping from stack and pushing top + 1 parallely
                curr = ss.top()+1;
                ss.pop();
            }
            ss.push(curr);              //Push recent mismatch  to stack
            
        }
    }

    int b[ss.size()];   //Now whatever elements are left in stack is our answer , store it in b
    i= 0;
    int m = ss.size();

    while(!ss.empty()){                 
      
         b[i] = ss.top();               // poping from stack and putting in array b 
         i++;
         ss.pop();
    }

    for(i = m-1; i >= 0; i--){               //Since Stack Follows LIFO just print aray b in reverse
        
        cout<<b[i]<<" ";
    }
    
    cout<<endl;
}
int main()
{
	int i;
	int n;
	int t;

	cin>>t;

	while(t--){

		cin>>n;

		int arr[n];

		for(i = 0;i < n; i++) {

			cin>>arr[i];
        }
		
		replace_con(arr,n);
	}

	return 0;
}