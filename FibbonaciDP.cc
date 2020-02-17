#include<bits/stdc++.h>
using namespace std;

int memo[1000];


// Memoization - Top Down
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (memo[n] != -1) {
		return memo[n];
	}

	int ans = fib(n - 1) + fib(n - 2);
	memo[n] = ans;
	return ans;
}

// Bottom Up Approach
int fibBU(int n) {
	int dp[1000] = {};

	dp[0] = 0;
	dp[1] = 1;

	for (int curNum = 2; curNum <= n; curNum++) {
		dp[curNum] = dp[curNum - 1] + dp[curNum - 2];
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	// Initialize Memo With '-1'.
	for (int i = 0; i <= 1000; i++) memo[i] = -1; // Emptied the memopad.

	int ans = fibBU(n);
	cout << n << " th fib no is : " << ans << endl;
	return 0;
}