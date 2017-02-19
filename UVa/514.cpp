#include <bits/stdc++.h>
using namespace std;

int a[1000], b[1000];

int main() {
	int n, x;
	while (cin >> n) {
		if (n == 0) break;
		while (cin >> x) {
			if (x == 0) break;
			int ai = 0; int bi = 0;
			stack<int> s;
			b[bi++] = x;
			a[ai++] = 1;
			for (int i = 1; i < n; ++i) {
				cin >> x;
				b[bi++] = x;
				a[ai++] = i + 1;
			}
			bool success = true;
			ai = 0;
			bi = 0;
			while (bi < n) {
				if (s.empty()) s.push(a[ai++]);
				if (s.top() == b[bi]) {
					s.pop();
					bi++;
				} else if (s.top() < b[bi]) {
					s.push(a[ai++]);
				} else if (s.top() > b[bi]) {
					success = false;
					break;
				}
			}
			if (success) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << '\n';
	}
	return 0;
}
