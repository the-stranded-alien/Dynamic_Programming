//Sahil Gupta
//sahil16gupta11@gmail.com
//@_the_stranded_alien_

// C++ Code

#include<bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;

int memo[10000];

int reduceNoRec(int n) {
	if (n == 1) return 0;
	int q1 = inf;
	int q2 = inf;
	int q3 = inf;

	if (n % 3 == 0) q1 = 1 + reduceNoRec(n / 3);
	if (n % 2 == 0) q2 = 1 + reduceNoRec(n / 2);
	q3 = 1 + reduceNoRec(n - 1);

	return min(q1, min(q2, q3));
}

int reduceNoMemo(int n) {
	if (n == 1) return 0;
	int q1 = inf;
	int q2 = inf;
	int q3 = inf;
	if (memo[n] != -1) return memo[n]; // because this has already been computed ! No recomputation
	if (n % 3 == 0) q1 = 1 + reduceNoMemo(n / 3);
	if (n % 2 == 0) q2 = 1 + reduceNoMemo(n / 2);
	q3 = 1 + reduceNoMemo(n - 1);

	memo[n] = min(q1, min(q2, q3));

	return memo[n];
}

int reduceNoDP(int n) {
	int dp[10000];

	//Setting The Base Cases
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	// Compute The Answer for 'n'.
	for (int curNum = 4; curNum <= n; curNum++) {
		int q1 = inf;
		int q2 = inf;
		int q3 = inf;
		if (curNum % 3 == 0) q1 = 1 + dp[curNum / 3];
		if (curNum % 2 == 0) q2 = 1 + dp[curNum / 2];
		q3 = 1 + dp[curNum - 1];
		dp[curNum] = min(q1, min(q2, q3));
	}
	return dp[n];

}

int main() {
	int n;
	cin >> n;
	fill(memo, memo + n + 1, -1);
	int ans = reduceNoDP(n);
	cout << ans << endl;

	return 0;
}