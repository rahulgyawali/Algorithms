#include <bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
    return (a < b ? (a < c? a:c) : (b < c?b:c));
}

int edit(string X,string Y,int m,int n)
{   

    if(m == 0) return n;
    if(n == 0) return m;

    if(X[m-1] == Y[n-1]) return edit(X,Y,m-1,n-1);

    else return 1 + min(edit(X,Y,m-1,n-1),edit(X,Y,m,n-1),edit(X,Y,m-1,n));

}

int main()
{
    string X = "sunday";
    string Y = "saturday";

    cout<<edit(X,Y,X.size(),Y.size())<<endl;

    return 0;
}
