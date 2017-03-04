#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 10;
int n;
long long a[maxn];
vector<long long> v;

struct BIT {
  #define lowbit(x) (x & -x)
  int bit[maxn], n;
  void init(int _n) {
    memset(bit, 0, sizeof(bit));
    n = _n;
  }
  void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) bit[i] += v;
  }
  int sum(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += bit[i];
    return ret;
  }
} bit;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n) {
    v.clear();
    for (int i = 0; i < n; ++i) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    bit.init(v.size() + 5);
    for (int i = 0; i < n; ++i) {
      int ind = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
      cout << bit.sum(v.size()) - bit.sum(ind) + 1 << '\n';
      bit.add(ind, 1);
    }
  }
  return 0;
}
