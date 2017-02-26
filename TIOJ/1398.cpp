#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x, ans;
priority_queue<int, vector<int>, greater<int>> pq;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> n) {
    ans = 0;
    while (pq.size()) pq.pop();
    for (int i = 0; i < n; ++i) cin >> x, pq.push(x);
    while (pq.size() > 4) {
      int a, b, c;
      a = pq.top(); pq.pop();
      b = pq.top(); pq.pop();
      c = pq.top(); pq.pop();
      ans += (a + b + c);
      pq.push(a + b + c);
    }
    int tmp = 0;
    if (pq.size() == 3) {
      tmp += pq.top(); pq.pop();
      tmp += pq.top(); pq.pop();
      tmp += pq.top(); pq.pop();
      ans += tmp;
      cout << ans << '\n';
      continue;
    }
    if (pq.size() == 4) {
      tmp += pq.top(); pq.pop();
      tmp += pq.top(); pq.pop();
      ans += tmp;
      pq.push(tmp);
    }
    while (pq.size()) ans += pq.top(), pq.pop();
    cout << ans << '\n';
  }
  return 0;
}
