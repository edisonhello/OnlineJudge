#include <iostream>
#define int long long
using namespace std;

int BIT[3005][3005], a[3005][3005], n, m, q, x1, y1, x2, y2, __i, __j, __k;
char c;
int query(int, int);
void add(int, int, int);

inline int lowbit(int x) { return x & -x; }

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) add(i, j, a[i][j]);
  cin >> q;
  while (q--) {
    cin >> c;
    if (c == 'C') {
      cin >> __i >> __j >> __k;
      add(__i, __j, __k - a[__i][__j]);
    }
    if (c == 'Q') {
      cin >> x1 >> y1 >> x2 >> y2;
      cout << query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1) << '\n';
    }
  }
  return 0;
}

int query(int x, int y) {
  int ret = 0;
  while (x) {
    for (int j = y; j; j -= lowbit(j)) ret += BIT[x][j];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int y, int d) {
  while (x <= n) {
    for (int j = y; j <= m; j += lowbit(j)) BIT[x][j] += d;
    x += lowbit(x);
  }
}
