//Sahil Gupta
//sahil16gupta11@gmail.com
//@_the_stranded_alien_

// C++ Code

#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
int memo[100][100];

int maxProfit(int arr[], int be, int en, int year) {
	++cnt;
	if (be > en) return 0;
	int q1 = (arr[be] * year) + maxProfit(arr, be + 1, en, year + 1); // Sell from beginning
	int q2 = (arr[en] * year) + maxProfit(arr, be, en - 1, year + 1); // Sell from end
	int ans = max(q1, q2);
	return ans;
}

int maxProfitMemo(int arr[], int be, int en, int year) {
	++cnt;
	if (be > en) return 0;

	if (memo[be][en] != -1) return memo[be][en];

	int q1 = (arr[be] * year) + maxProfit(arr, be + 1, en, year + 1); // Sell from beginning
	int q2 = (arr[en] * year) + maxProfit(arr, be, en - 1, year + 1); // Sell from end
	int ans = max(q1, q2);
	memo[be][en] = ans; // Ans for this particular range [be, en]
	return ans;
}

int maxProfitBU(int arr[], int n) {
	int dp[100][100] = {};
	int year = n;

	for (int i = 0; i < n; i++) {
		dp[i][i] = year * arr[i];
	}
	--year;

	for (int len = 2; len <= n; ++len) {
		int srt = 0;
		int end = n - len;
		while (srt <= end) {
			int endWindow = srt + len - 1;
			dp[srt][endWindow] = max(
			                         arr[srt] * year + dp[srt + 1][endWindow],
			                         arr[endWindow] * year + dp[srt][endWindow - 1]
			                     );
			++srt;
		}
		--year;
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;

	return dp[0][n - 1];
}

int main() {
	int arr[100];
	int n;			// Number of Bottles Kept on Table
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 		// Prices of Bottles
	}

	// int ans = maxProfit(arr, 0, n - 1, 1);
	// cout << ans << endl;

	// memset(memo, -1, sizeof(memo));
	int ans = maxProfitBU(arr, n);
	cout << ans << endl;
	// cout << cnt << endl;

	return 0;
}