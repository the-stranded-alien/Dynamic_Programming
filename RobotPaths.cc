#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];

int numWays(int row, int col) {
	// Base Case
	if (dp[0][0] == -1) return 0;

	// Compute the no of ways for first row
	for (int j = 0; j < col; j++) {
		if (dp[0][j] == -1) break;
		dp[0][j] = 1;
	}

	// Compute the no of ways for first col
	for (int k = 0; k < row; k++) {
		if (dp[k][0] == -1) break;
		dp[k][0] = 1;
	}

	// Bottom Up Approach for Rest of the Matrix
	for (int x = 1; x < row; x++) {
		for (int y = 1; y < col; y++) {
			// if cell is blocked leave it
			if (dp[x][y] == -1) continue;
			dp[x][y] = 0;
			if (dp[x][y - 1] != -1) dp[x][y] = dp[x][y - 1] % MOD;
			if (dp[x - 1][y] != -1) dp[x][y] = (dp[x][y] + dp[x - 1][y]) % MOD;
		}
	}

	// Check for the Final Cell
	if (dp[row - 1][col - 1] == -1) return 0;
	return dp[row - 1][col - 1];
}

int main() {
	memset(dp, 0, sizeof(dp));
	int M, N, P; 	// M : no. of rows & N : no. of columns
	cin >> M >> N >> P;
	for (int i = 0; i < P; i++) {
		int X, Y;
		cin >> X >> Y;
		// Mark all the blocked cells as -1
		dp[X - 1][Y - 1] = -1;
	}
	cout << numWays(M, N) << endl;
	return 0;
}