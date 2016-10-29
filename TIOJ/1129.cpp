#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int A, B, C, x[4005], y[4005], djs[4005], sz[4005], cnt[4005], jizz, ans;
bool v[4005];
map<int, int> mp;

int dis(int i, int j) {
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  if (sz[x] < sz[y]) swap(x, y);
  djs[y] = x;
  sz[x] += sz[y];
}

int main() {
  while (cin >> A >> B >> C) {
    for (int i = 0; i < B; ++i) djs[i] = i, sz[i] = 1;
    memset(v, false, sizeof(v)); ans = 0; jizz = 0; mp.clear(); memset(cnt, 0, sizeof(cnt));
    x[0] = (269 * A + 11) % 103; y[0] = (271 * A + 13) % 97;
    for (int i = 1; i < B; ++i) x[i] = (269 * x[i - 1] + 11) % 103, y[i] = (271 * y[i - 1] + 13) % 97;
    for (int i = 0; i < B; ++i) {
      for (int j = i + 1; j < B; ++j) {
        if (dis(i, j) <= C * C) U(i, j);
      }
    }
    for (int i = 0; i < B; ++i) {
      if (!v[F(i)]) v[F(i)] = true, ans++;
      if (mp.find(F(i)) == mp.end()) mp[F(i)] = jizz++;
      cnt[mp[F(i)]]++;
    }
    cout << ans << endl;
    sort(cnt, cnt + B);
    for (int i = 0; i < B; ++i) {
      if (cnt[i]) cout << cnt[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
