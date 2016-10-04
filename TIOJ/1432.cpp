#include <iostream>
using namespace std;

int n, w, s[1010], mx, total, l, r, m, now, used;

bool jizz() {
  now = 0; used = 0;
  for (int i = 0; i < n; ++i) {
    if (now + s[i] > m) {
      used++;
      now = s[i];
      if (used > w) return false;
    } else {
      now += s[i];
    }
  }
  return true;
}

int bs() {
  l = mx; r = total;
  m = (l + r) / 2;
  while (l + 1 < r) {
    if (jizz()) r = m;
    else l = m;
    m = (l + r) / 2;
  }
  return l == r - 1 && jizz() ? l : r;
}

int main() {
  while (cin >> n >> w) {
    if (n == 0 && w == 0) break;
    mx = 0; total = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      total += s[i];
      if (s[i] > mx) mx = s[i];
    }
    cout << bs() << endl;
  }
}
