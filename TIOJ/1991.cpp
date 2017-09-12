#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
vector<vector<int>> a, s, rs, cs;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int r, c; cin >> r >> c;
	s.resize(r + 1);
	for (int i = 0; i < r + 1; ++i) s[i].resize(c + 1);
	a.resize(r + 1);
	for (int i = 0; i < r + 1; ++i) a[i].resize(c + 1);
	rs.resize(r + 1);
	for (int i = 0; i < r + 1; ++i) rs[i].resize(c + 1);
	cs.resize(r + 1);
	for (int i = 0; i < r + 1; ++i) cs[i].resize(c + 1);
	for(int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) cin >> a[i][j];
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			if (a[i][j] == 1 && a[i - 1][j] == 1) ++s[i][j], ++rs[i][j];
			if (a[i][j] == 1 && a[i][j - 1] == 1) ++s[i][j], ++cs[i][j];
		}
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) rs[i][j] += rs[i][j - 1];
	}
	for (int j = 1; j <= c; ++j) for (int i = 1; i <= r; ++i) cs[i][j] += cs[i - 1][j];
	int q; cin >> q; while (q--) {
		int aa, bb, cc, dd; cin >> aa >> bb >> cc >> dd; swap(aa, cc); swap(bb, dd);
		int ans = s[aa][bb] + s[cc - 1][dd - 1] - s[cc - 1][bb] - s[aa][dd - 1];
		cout << ans - rs[cc][bb] + rs[cc][dd - 1] - cs[aa][dd] + cs[cc - 1][dd] << endl;
	}
	return 0;
} 
