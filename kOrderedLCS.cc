#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll m;
ll a[2005];
ll b[2005];
ll dp[2005][2005][8];

ll kLCS(ll i, ll j, ll k) {
	if (i == n || j == m) return 0; // if any string is finished, ans is 0.
	// If current state has already been updated
	if (dp[i][j][k] != -1) return dp[i][j][k];
	ll res = 0;
	if (a[i] == b[j]) res = 1 + kLCS(i + 1, j + 1, k);
	else {
		if (k > 0) {
			// We have converted a single char to match with jth of string b
			res = 1 + kLCS(i + 1, j + 1, k - 1);
		}
		res = max(res, kLCS(i, j + 1, k));
		res = max(res, kLCS(i + 1, j, k));
	}
	dp[i][j][k] = res;
	return res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	ll k;
	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll j = 0; j < m; j++) cin >> b[j];
	ll ans = kLCS(0, 0, k);
	cout << ans << endl;
	return 0;
}