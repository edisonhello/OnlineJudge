#include <iostream>
#include <queue>
using namespace std;

int n, a, ans, x, y;

int main() {
  while (cin >> n, n) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; ++i) {cin >> a; pq.push(a);}
    ans = 0;
    while (pq.size() > 1) {
      x = pq.top(), pq.pop();
      y = pq.top(), pq.pop();
      ans += x + y;
      pq.push(x + y);
    }
    cout << ans << endl;
  }
  return 0;
}
