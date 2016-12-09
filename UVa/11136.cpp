#include <iostream>
#include <queue>
#include <bitset>
#define int long long
using namespace std;

struct S {
  int id, v;
  bool operator<(const S& res) const {
    return v < res.v;
  }
  bool operator>(const S& res) const {
    return v > res.v;
  }
};

bitset<500000005> v;
priority_queue<S, vector<S>, less<S>> pq1;
priority_queue<S, vector<S>, greater<S>> pq2;
int n, k, x, id, ans;

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> n, n) {
    while (pq1.size()) pq1.pop();
    while (pq2.size()) pq2.pop();
    v.reset(); id = 0; ans = 0;
    while (n--) {
      cin >> k;
      for (int i = 0; i < k; ++i, ++id) cin >> x, pq1.push((S){ id, x }), pq2.push((S){ id, x });
      while (pq1.size() && v[pq1.top().id]) pq1.pop();
      while (pq2.size() && v[pq2.top().id]) pq2.pop();
      S Max = pq1.top(); pq1.pop();
      S Min = pq2.top(); pq2.pop();
      ans += Max.v - Min.v;
      v[Max.id] = v[Min.id] = true;
    }
    cout << ans << '\n';
  }
  return 0;
}
