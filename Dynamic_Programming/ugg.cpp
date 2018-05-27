#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i;
	int n = 150;
	int i2;
	int i3;
	int i5;
	
	i2 = 0;
	i3 = 0;
	i5 = 0;

	int ugly[n];

	ugly[0] = 1;

	int next2 = ugly[i2]*2;
	int next3 = ugly[i3]*3;
	int next5 = ugly[i5]*5;

	for(i = 1; i < n ; i ++) {

		int next = min(next2,next3,next5);
		ugly[i] = next;

		if(next == next2) {
			i2++;
			next2 = ugly[i2]*2;
		}

	}

	return 0;
}
