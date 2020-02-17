//Sahil Gupta
//sahil16gupta11@gmail.com
//@_the_stranded_alien_

// C++ Code

#include<bits/stdc++.h>
using namespace std;

int memo[100];

int maxProfit(int priceOfEachLen[], int totalLen) {
	if (totalLen == 0) return 0;
	int best = 0;
	for (int len = 1; len <= totalLen; ++len) {
		int netProfit = priceOfEachLen[len] + maxProfit(priceOfEachLen, totalLen - len);
		best = max(best, netProfit);
	}
	return best;
}

int maxProfitMemo(int priceOfEachLen[], int totalLen) {
	if (totalLen == 0) return 0;
	if (memo[totalLen] != -1) {
		return memo[totalLen];
	}
	int best = 0;
	for (int len = 1; len <= totalLen; ++len) {
		int netProfit = priceOfEachLen[len] + maxProfit(priceOfEachLen, totalLen - len);
		best = max(best, netProfit);
	}
	memo[totalLen] = best;
	return best;
}

int maxProfitBU(int arr[], int totalLen) {
	int dp[100] = {};
	for (int len = 1; len <= totalLen; ++len) {
		int best = 0;
		for (int cut = 1; cut <= len; ++cut) {
			best = max(best, (arr[cut] + dp[len - cut]));
		}
		dp[len] = best;
	}
	return dp[totalLen];
}

int main() {
	int priceOfEachLen[100];
	int totalLen;
	cin >> totalLen;
	for (int eachPiece = 1; eachPiece <= totalLen; ++eachPiece) {
		cin >> priceOfEachLen[eachPiece];
	}
	// reset memopad
	for (int i = 0; i <= totalLen; i++) {
		memo[i] = -1;
	}
	int ans = maxProfitBU(priceOfEachLen, totalLen);
	cout << ans << endl;
	return 0;
}