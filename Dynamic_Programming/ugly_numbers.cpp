#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
	return min( min(a,b),c);

}

int main()
{
	int i;
	int i2 = 0;
	int i3 = 0;
	int i5= 0;
	int n;
	cin>>n;
	int a[n];
	a[0] = 1;
	int n2 = a[i2]*2;
	int n3 = a[i3]*3;
	int n5 = a[i5]*5;
	int nx;

	for(i=1; i < n; i++) {

		nx = min(min(n2,n3),n5);
		a[i] = nx;
		if(nx == n2) {
			i2 +=1;
			n2 = a[i2]*2;
		}

		if(nx == n3) {
			i3+=1;
			n3 = a[i3]*3;
		}

		if(nx == n5){
			i5+=1;
			n5 = a[i5]*5;
		}
	}

	cout<<nx<<endl;	

	return 0;
}
