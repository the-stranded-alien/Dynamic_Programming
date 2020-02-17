#include<bits/stdc++.h>
using namespace std;

int editDistance(char inp[100], char out[100]) {
	int dp[101][101] = {};

	int m = strlen(inp);
	int n = strlen(out);

	// Base Case
	for (int i = 1; i <= n; ++i) dp[0][i] = dp[0][i - 1] + 1; 	// insertion
	for (int j = 1; j <= m; ++j) dp[j][0] = dp[j - 1][0] + 1; 	// deletion

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			int q1 = dp[i - 1][j - 1];	// replacement
			int q2 = dp[i - 1][j];		// deletion
			int q3 = dp[i][j - 1];		// insertion
			dp[i][j] = min(q1, min(q2, q3)) + (inp[i - 1] != out[j - 1]); // As we have to account for equal char
		}
	}
	return dp[m][n];
}

int main() {
	char inp[100], out[100];
	cin >> inp >> out;
	int ans = editDistance(inp, out);
	cout << ans << endl;
	return 0;
}5