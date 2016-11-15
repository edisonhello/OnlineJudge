#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

priority_queue<double, vector<double>, greater<double>> pq;
int n;
char c;
double f, ans, a, b;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c >> f;
    pq.push(f);
  }
  ans = 0.0;
  while (pq.size() - 1) {
    a = pq.top(), pq.pop();
    b = pq.top(), pq.pop();
    ans += (a + b);
    pq.push(a + b);
  }
  cout << fixed << setprecision(2) << ans << '\n';
  return 0;
}
