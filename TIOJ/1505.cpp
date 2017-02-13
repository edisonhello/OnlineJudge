#include <bits/stdc++.h>
using namespace std;

int T, N, now, x;

int main() {
  cin >> T;
  while (T--) {
    cin >> N;
    cin >> now;
    bool ans = true;
    for (int i = 1; i < N; ++i) {
      cin >> x;
      if (now % x == 0) now /= x;
      else ans = false;
    }
    if (ans) cout << ""
  }
}
