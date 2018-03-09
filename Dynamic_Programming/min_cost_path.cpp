#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{   
    return a < b ?(a < c?a:c):(b<c?b:c);
}

int mins(int cost[3][3],int m,int n,int x,int y)
{
    if(m < x || n < y)  return INT_MAX;
    else if(m == x && n == y) return cost[m][n];
    else
    return cost[m][n] + min(mins(cost,m-1,n,x,y),mins(cost,m,n-1,x,y),mins(cost,m-1,n-1,x,y));
}

int main()
{

   int cost[3][3] = {{1,2,3},
    
		    {4,8,2},
		    {1,5,3}
		};

    cout<<mins(cost,2,2,0,0)<<endl;
    return 0;
}
