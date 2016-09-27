#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define MOD 1000007
using namespace std;

vector<int> G[100050];
bool v[100050], color[100050], b;
int t, n, m, p, q, tree, ans, i;
char c;
void DFS(int);

inline int rit() {
	t = 0;
	do {
		c = getchar_unlocked();
	} while (c < '0' || c > '9');
	do {
		t = t * 10 + c - '0';
		c = getchar_unlocked();
	} while (c >= '0' && c <= '9');
	return t;
}

int main() {
	n = rit(); m = rit();
	for (int i = 0; i < m; ++i) {
		p = rit();
		q = rit();
		G[p].push_back(q);
		G[q].push_back(p);
	}
	tree = 0;
	ans = 1;
	b = true;
	for (i = 1; i <= n; ++i) {
		if (!v[i]) {
			v[i] = true;
			color[i] = true;
			DFS(i);
			if (!b) {printf("0\n"); return 0;}
			else tree++;
		}
	}
	for (i = 0; i < tree - 1; ++i) {
		ans <<= 1;
		ans %= MOD;
	}
	printf("%d\n", ans);
	return 0;
}

void DFS(int start) {
	for (int i = 0; i < G[start].size(); ++i) {
		if (!v[G[start][i]]) {
			v[G[start][i]] = true;
			color[G[start][i]] = !color[start];
			DFS(G[start][i]);
		} else {
			if (color[G[start][i]] == color[start]) {
				b = false;
				return;
			}
		}
	}
}
