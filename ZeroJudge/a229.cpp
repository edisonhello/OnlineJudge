#include <bits/stdc++.h>
using namespace std;

int n;

void solve(int, int, string);

int main() {
	while (cin >> n) {
		solve(0, 0, "");
		cout << '\n';
	}
	return 0;
}

void solve(int l, int r, string s) {
	if (l == n && r == n) {
		cout << s << '\n';
		return;
	}
	if (r > l) return;
	if (l < n) solve(l + 1, r, s + '(');
	if (r < n) solve(l, r + 1, s + ')');
}
