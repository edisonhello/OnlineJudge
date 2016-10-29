#include <iostream>
#include <queue>
using namespace std;

int n, x, a, b, tot;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x, pq.push(x);
  while (pq.size() > 1) {
    a = pq.top(), pq.pop();
    b = pq.top(), pq.pop();
    tot += (a + b);
    pq.push(a + b);
  }
  cout << tot << endl;
  return 0;
}
