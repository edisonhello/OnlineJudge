#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
long long s, f, t, tt[maxn];
int n;

int main() {
  cin >> s >> f >> t;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> tt[i];
  sort(tt, tt + n);
  long long cur = s;
  for (int i = 0; i < n; ++i) {
    if (tt[i] > cur) {
      if (tt[i] - t >= cur) return cout << tt[i] - t << '\n', 0;
    }
    
  }
  return 0;
}
