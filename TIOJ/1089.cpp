#include <iostream>
#include <utility>
#include <queue>
#include <cstdio>
using namespace std;

int n, k, r[501], c[501], x, y, tot, cnt, rm, cm;
// pair<int, int> r[501], c[501];
bool cv[501], rv[501];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> rr, cc;

int main() {
  cin >> n >> k;
  // for (int i = 0; i <= n; ++i) r[i].second = i;
  for (int i = 0; i < k; ++i) {
    cin >> y >> x;
    r[y]++; c[x]++;
  }
  for (int i = 1; i <= n; ++i) printf("r[%d]: %d\n", i, r[i]);
  for (int i = 1; i <= n; ++i) printf("c[%d]: %d\n", i, c[i]);
  for (int i = 1; i <= n; ++i) rr.push(make_pair(r[i], i)), cc.push(make_pair(c[i], i));
  tot = k;
  while (tot) {
    if (rr.top() - rm > cc.top() - cm) {
      tot -= (rr.top() - rm);
      cnt++;
      cm++;
      rr.pop();
    } else {
      tot -= (cc.top() - cm);
      cnt++;
      rm++;
      cc.pop();
    }
  }
  cout << cnt << endl;
  return 0;
}
