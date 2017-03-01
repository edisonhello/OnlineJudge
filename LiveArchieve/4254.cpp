#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5, maxw = 1000;
int T, n;
struct P { int l, r, w; } p[maxn];
struct Interval {
  double L, R;
  int id;
  bool operator<(const Interval& i) const {
    return L == i.L ? R < i.R : L < i.L;
  }
  bool operator>(const Interval& i) const {
    return L == i.L ? R > i.R : L > i.L;
  }
};

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n;
    p[0].l = 0, p[0].r = 0;
    for (int i = 1; i <= n; ++i) cin >> p[i].l >> p[i].r >> p[i].w;
    int d = 1, ans = maxw;
    while (d <= maxw) d <<= 1;
    while (d >>= 1) if (ans - d >= 1) if (check(ans - d)) ans -= d;
    cout << ans << '\n';
  }
  return 0;
}

bool check(int s) {
  cout << "s: " << s << '\n';
  priority_queue<Interval, vector<Interval>, greater<Interval>> pq;
  double w[maxn];
  for (int i = 1; i <= n; ++i) w[i] = (double)p[i].w / (double)s;
  for (int i = 1; i <= n; ++i) pq.push((Interval){ (double)p[i].l, (double)p[i].r, i });
  Interval cur = (Interval){ 0, 0, 0 };
  while (pq.size()) {
    Interval in = pq.top(); pq.pop();
    if (cur.id == in.id) continue;
    if (in.R < cur.R) {
      w[cur.id] -= in.L - cur.L;
      if (w[cur.id]) pq.push((Interval){ in.L, cur.R, cur.id });
    } else {
      pq.push((Interval){ max(cur.L + w[cur.id], in.L), in.R, in.id });
      w[cur.id] = 0;
    }
    cur = in;
  }
  for (int i = 0; i < n; ++i) if (w[i] > 0) return false;
  return true;
}
