#include <bits/stdc++.h>
using namespace std;

int min(int a,int b){
	return a<b?a:b;
}

int max(int a,int b){
	return a>b?a:b;
}
void swap(int*a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}
void print(int a[],int n)
{
 	int i;
 	for(i=0;i<n;i++)
 		cout<<a[i]<<" ";
 	cout<<endl;   
}
void rev(int a[],int n){

}
void f(int a[],int n)
{
    int next;
    int ele;
    int i;
    stack<int>ss;
    ss.push(0);
    int nge[n];
    nge[n-1]=-1;
    for(i=1;i<n;i++){
        next = i;
        if(!ss.empty()){
            ele = ss.top();
            ss.pop();
            
            while(a[next] > a[ele]) {
                nge[ele] = next;
                if(ss.empty())
                    break;
                ele = ss.top();
                ss.pop();
            }
            
            if(a[ele] > a[next]) {
                ss.push(ele);
            }
        }
        ss.push(i);
    }
    while(!ss.empty()){
        nge[ss.top()]=-1;
        ss.pop();
    }
    for(i=0;i<n;i++){
        if(nge[i]!=-1)
            cout<<a[nge[i]]<<" ";
        else
            cout<<-1<<" ";
    }
    cout<<endl;
}
int bs(int a[],int low,int high,int x)
{

}
int main()
{
	int i;
	int j;
	int n;
	int t;
	int x;
	int res;

	cin>>t;

	while(t--){
		cin>>n;
		int arr[n];
		for(i = 0;i<n;i++)
			cin>>arr[i];
		
		f(arr,n);
	}


	return 0;
}