//Sahil Gupta
//sahil16gupta11@gmail.com
//@_the_stranded_alien_

// C++ Code

#include<bits/stdc++.h>
using namespace std;

int a[1000];
long long dp[1000][1000];

long long sum(int s, int e) {
	long long ans = 0;
	for (int i = s; i <= e; i++) {
		ans += a[i];
		ans %= 100;
	}
	return ans;
}

long long solveMixtures(int i, int j) {
	// Base case
	if (i >= j) return 0;
	//If the answer already there
	if (dp[i][j] != -1) return dp[i][j];
	// We need to break our expression at every possible k
	dp[i][j] = INT_MAX;
	for (int k = i; k <= j; k++) {
		dp[i][j] = min(dp[i][j], (solveMixtures(i, k) + solveMixtures(k + 1, j) + (sum(i, k) * sum(k + 1, j))));
	}
	return dp[i][j];
}

int main() {

	int n;
	cin >> n;

	// while ((scanf("%d", &n)) != EOF) {
	// Read N integers
	// }

	for (int i = 0; i < n; i++) cin >> a[i];

	// Init dp with -1
	memset(dp, -1, sizeof(dp));
	cout << solveMixtures(0, n - 1) << endl;
	return 0;
}