#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
long double dp[maxn][maxn];

int main() {
	int k, n; while (cin >> k, k) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= k; ++i) dp[i][1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				dp[j][i] = dp[j][i - 1];
				if (j) dp[j][i] += dp[j - 1][i - 1];
				if (j < k) dp[j][i] += dp[j + 1][i - 1];
			}
		}
		long double t = 0;
		for (int i = 0; i <= k; ++i) t += dp[i][n];
		for (int i = 1; i <= n; ++i) t /= (long double)(k+1);
		t *= 100;
		cout << fixed << setprecision(5) << t << endl;
	}	
	return 0;
}
