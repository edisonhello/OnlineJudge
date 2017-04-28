#include <bits/stdc++.h>
using namespace std;

string s = "abaababbabaab";
int z[13];

int main() {
  z[0] = 0;
  int L = 0, R = 1;
  for (int i = 1; i < 13; ++i) {
    if (R <= i || z[i - L] >= R - i) {
      int x = (R <= i ? i : R);
      while (x < 13 && s[x] == s[x - i]) ++x;
      z[i] = x - i;
      if (i < x) L = i, R = x;
    } else {
      z[i] = z[i - L];
    }
  }
  int ans = 0;
  for (int i = 0; i < 13; ++i) ans += z[i];
  cout << ans << '\n';
  return 0;
}
