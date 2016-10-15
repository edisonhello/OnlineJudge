#include <iostream>
#include <cstring>
using namespace std;

int a[1000010], n, k, pos, m[1000010];
long long ans;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  memcpy(m, a, sizeof(a));
  pos = 0;
  ans = m[0];
  m[0] = 0;
  for (int i = 0; i < k; ++i) {
    m[pos - 1] = a[pos - 1], m[pos + 1] = a[pos + 1];
    if (pos == 0) ans += m[1], pos = 1, m[1] = 0;
    else if (pos == n - 1) ans += m[n - 2], pos = n - 2, m[n - 2] = 0;
    else {
      if (m[pos + 1] >= m[pos - 1]) ans += m[pos + 1], m[pos + 1] = 0, pos++;
      else ans += m[pos - 1], m[pos - 1] = 0, pos--;
    }
  }
  cout << ans << endl;
  return 0;
}
