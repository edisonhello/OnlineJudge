#include <bits/stdc++.h>
using namespace std;

int n, t, dot;
string s;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> t;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') dot = i;
  }

  return 0;
}
