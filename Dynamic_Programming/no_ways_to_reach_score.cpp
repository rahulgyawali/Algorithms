#include <bits/stdc++.h>
using namespace std;

int ways(int score)
{
	int i;
	int dp[score+1];
	dp[0] = 1;

	for(i = 1; i <= score;i++) {
		dp[i] = 0;
	}

	for(i = 3; i <= score; i++) {
		dp[i] += dp[i-3];
	}

	for(i = 5; i <= score; i++) {
		dp[i] += dp[i-5];
	}

	for(i = 10; i <= score; i++) {
		dp[i] += dp[i-10];
	}

	return dp[score];
}

int main()
{
	int score = 20;
	cout<<ways(score)<<endl;
	return 0;
}