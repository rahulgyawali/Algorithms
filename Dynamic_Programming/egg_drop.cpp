#include <bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
    return a<b?a:b;
}

int max(int a,int b)
{

    return a>b?a:b;
}

int egg_drop(int n,int k)
{
    int i;
    int j;
    int x;

    int eggfloor[n+1][k+1] = {0};

    for(i = 1;i < n+1; i++) {

	eggfloor[i][0] = 0;
	eggfloor[i][1] = 1;
    }

    for(i = 1; i < k+1; i++) {

	
	eggfloor[1][i] = i;
    }

    for(i = 2; i <=n;  i++) {
	
	for(j = 2; j <= k; j++) {

	    eggfloor[i][j] = INT_MAX;

	    for(x = 1; x <= j; x++) {
	
		
		   eggfloor[i][j] = min(eggfloor[i][j],1+max(eggfloor[i-1][x-1],eggfloor[i][j-x]));

	    }   
	}
    }

    return eggfloor[n][k];
}

int main()
{

    int egg = 2;
    int floor = 36;
    cout<<egg_drop(egg,floor)<<endl;
    return 0;
}
