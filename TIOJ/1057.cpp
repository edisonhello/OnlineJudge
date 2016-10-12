#include <iostream>
using namespace std;

int m, p, n, s[101], cur, cnt;

int main() {
  cin >> m >> p >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    if (s[i] - s[i - 1] > m) {cout << "IMPOSSIBLE\n"; return 0;}
  }
  if (s[0] > m) {cout << "IMPOSSIBLE\n"; return 0;}
  if (p - s[n - 1] > m) {cout << "IMPOSSIBLE\n"; return 0;}
  cur = 0; cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (cur >= p) break;
    if (s[i] > cur) {
      cnt++;
      cur = s[i - 1] + m;
    }
  }
  if (cur < p) cnt++;
  cout << cnt - 1 << endl;
  return 0;
}
