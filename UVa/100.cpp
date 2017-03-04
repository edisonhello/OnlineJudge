#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000000 + 5;
int L, R;

int dp(int);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> L >> R) {
		int ans = 0;
		for (int i = min(L, R); i <= max(R, L); ++i) ans = max(ans, dp(i));
		cout << L << ' ' << R << ' ' << ans << '\n';
	}
	return 0;
}

int dp(int x) {
	return x == 1 ? 1 : x & 1 ? dp(3 * x + 1) + 1 : dp(x / 2) + 1;
}
