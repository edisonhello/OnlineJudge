#include <bits/stdc++.h>
using namespace std;

string m, n;
int osas[20] = { 1, 4, 7, 6, 5, 6, 3, 6, 9, 0, 1, 6, 3, 6, 5, 6, 7, 4, 9, 0 };

int solve(string);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> m >> n;
  cout << solve(m) + solve(n) << '\n';
  return 0;
}

int solve(string s) {
  if (s.length() > 2) s = s.substr(s.length() - 2, 2);
  stringstream ss(s);
  int x; ss >> x;
  int ret = 0;
  for (int i = 1; i <= x; ++i) {
    ret += osas[(i - 1) % 20];
  }
  return ret % 10;
}
