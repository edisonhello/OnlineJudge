#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
struct Res { int s, r; } res[maxn];
int n, m;
long long ans;

struct BIT {
  #define lowbit(x) (x & -x)
  int bit[maxn];
  void init() {
    memset(bit, 0, sizeof(bit));
  }
  void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) bit[i] += v;
  }
  long long sum(int x) {
    long long ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += bit[i];
    return ret;
  }
  #undef lowbit
} bit;

long long Reverse(const vector<int>&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> res[i].s;
  for (int i = 1; i <= n; ++i) cin >> res[i].r;
  sort(res + 1, res + n + 1, [](const Res& a, const Res& b) -> bool {
    return a.s == b.s ? a.r < b.r : a.s < b.s;
  });
  vector<int> v;
  for (int i = 1; i <= n; ++i) v.push_back(res[i].r);
  ans += Reverse(v);
  sort(res + 1, res + n + 1, [](const Res& a, const Res& b) -> bool {
    return a.r == b.r ? a.s < b.s : a.r < b.r;
  });
  v.clear();
  for (int i = 1; i <= n; ++i) v.push_back(res[i].s);
  ans += Reverse(v);
  cout << ans / 2 << '\n';
  return 0;
}

long long Reverse(const vector<int>& v) {
  bit.init();
  map<int, int> mp;
  vector<int> vec(v.begin(), v.end());
  sort(vec.begin(), vec.end());
  int ind = 0;
  long long ret = 0;
  for (int i : vec) mp[i] = ++ind;
  for (int i = 0; i < v.size(); ++i) {
    ret += i - bit.sum(mp[v[i]]);
    bit.add(mp[v[i]], 1);
  }
  return ret;
}
