#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    
    int i;
    int a = 0;
    int b = 1;
    int c;
    if(n == 0) return 0;
    if(n ==1) return 1;

    for(i = 2; i <= n; i++) {
    
	c = a + b; 
	a = b;
	b = c;
    }

    return c;

}

int main()
{


    cout<<fib(9)<<endl;

    return 0;
}
