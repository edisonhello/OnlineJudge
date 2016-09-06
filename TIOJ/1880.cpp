#include <iostream>
#include <cstring>
#include <deque>
#include <queue>
#define MOD 1000007
using namespace std;

deque<int> f[100050];
bool v[100050];
bool color[100050];

int main() {
	int n, m, p, q;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		f[i].clear();
	}
	for (int i = 0; i < m; ++i) {
		cin >> p >> q;
		f[p].push_back(q);
		f[q].push_back(p);
	}
	memset(v, false, sizeof(v));
	// memset(color, 0, sizeof(color));
	int tree = 0;
	queue<int> qq;
	int cur;
	for (int i = 0; i < n; ++i) {
		if (!v[i + 1]) {
			tree++;
			qq.push(i + 1);
			color[i + 1] = true;
			v[i + 1] = true;
			while (!qq.empty()) {
				cur = qq.front();
				qq.pop();
				for (int j = 0; j < f[cur].size(); ++j) {
					if (!v[f[cur][j]]) {
						v[f[cur][j]] = true;
						color[f[cur][j]] = !color[cur];
						qq.push(f[cur][j]);
					} else {
						if (color[f[cur][j]] == color[cur]) {
							cout << 0 << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	int ans = 1;
	for (int i = 1; i < tree; ++i) {
		ans *= 2;
	}
	cout << ans % MOD << endl;
	return 0;
}
