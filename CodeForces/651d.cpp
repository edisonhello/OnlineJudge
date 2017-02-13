#include <bits/stdc++.h>
#define int long long
#define add(x) (x == N - 1 ? 0 : x + 1)
#define sub(x) (x == 0 ? N - 1 : x - 1)
using namespace std;

const int maxn = 500000 + 5;
int N, a, b, T, tot, cnt, d[maxn];
bool v[maxn];
string s;

inline int dis(int, int, int);

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> a >> b >> T;
  cin >> s;
  fill(d, d + maxn, LLONG_MAX);
  int l = sub(0), r = add(0);
  d[0] = s[0] == 'w' ? b + 1 : 1;
  int cur = 0;
  cnt = 0;
  while (cnt < N && tot + d[cur] <= T) {
    tot += d[cur];
    ++cnt;
    d[l] = dis(cur, l, 0) * a + (s[l] == 'w' ? b + 1 : 1);
    d[r] = dis(cur, r, 1) * a + (s[r] == 'w' ? b + 1 : 1);
    if (d[l] < d[r]) cur = l, l = sub(cur);
    else cur = r, r = add(cur);
  }
  cout << cnt << '\n';
  return 0;
}

inline int dis(int x, int y, int dir) {
  int ret;
  if (dir) ret = y - x;
  else ret = x - y;
  if (ret <= 0) ret += N;
  return ret;
}
