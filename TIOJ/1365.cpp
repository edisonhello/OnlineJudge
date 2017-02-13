#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 1000000 + 5;

struct Car {
  int x, v;
  bool operator<(const Car& c) const {
    return x < c.x;
  }
} c[maxn];

int n, BIT[maxn], b[maxn];
map<int, int> m;
long long ans;

long long sum(int);
void add(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> c[i].x >> c[i].v;
    sort(c, c + n);
    memset(BIT, 0, sizeof(BIT));
    for (int i = 0; i < n; ++i) b[i] = c[i].v;
    sort(b, b + n);
    for (int i = 0; i < n; ++i) m[b[i]] = i + 1;
    ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += i - sum(m[c[i].v]);
      add(m[c[i].v], 1);
    }
    cout << ans << '\n';
  }
  return 0;
}

long long sum(int x) {
  long long ret = 0;
  while (x) {
    ret += BIT[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int v) {
  while (x <= n) BIT[x] += v, x += lowbit(x);
}
