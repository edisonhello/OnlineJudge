#include <iostream>
#include <cstring>
#define int long long
using namespace std;

int t, m, k, a[510], sm[510], tot, mx, L, R, M, now, used, ans, cur, pre, cnt;
int bs();
bool check();

signed main() {
  cin >> t;
  while (t--) {
    cin >> m >> k;
    mx = 0; tot = 0;
    memset(sm, 0, sizeof(sm));
    for (int i = 0; i < m; ++i) {
      cin >> a[i], tot += a[i];
      if (a[i] > mx) mx = a[i];
    }
    ans = bs(); cur = 0; pre = 0;
    cnt = 0;
    for (int i = 0; i < m; ++i) {
      if (cur + a[i] > ans && cnt < k - 1) {
        for (int j = pre; j < i; ++j) cout << a[j] << ' ';
        cout << "/ ";
        pre = i;
        cur = a[i];
        cnt++;
      } else {
        cur += a[i];
      }
    }
    for (int j = pre; j < m; ++j) cout << a[j] << ' ';
    cout << endl;
  }
  return 0;
}

int bs() {
  L = mx; R = tot;
  M = (L + R) / 2;
  while (L + 1< R) {
    if (check()) R = M;
    else L = M;
    M = (L + R) / 2;
  }
  return L == R - 1 && check() ? L : R;
}

bool check() {
  now = 0; used = 0;
  for (int i = 0; i < m; ++i) {
    if (now + a[i] > M) {
      used++;
      now = a[i];
      if (used > k) return false;
    } else {
      now += a[i];
    }
  }
  return true;
}
