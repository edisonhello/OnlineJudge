#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > pq;
int n, g, G, a, b;

int main() {
  G = 0;
  cin >> n;
  n--;
  while (n--) cin >> g, pq.push(g);
  while (pq.size() > 1) {
    a = pq.top(), pq.pop();
    b = pq.top(), pq.pop();
    G += a + b;
    pq.push(a + b);
  }
  cout << G << endl;
  return 0;
}
