#include <bits/stdc++.h>
using namespace std;

long long n;
int kase;
vector<int> ans;
string s[4] = { "kuti", "lakh", "hajar", "shata" };

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n) {
    ans.clear();
    ans.push_back(n / 10000000);
    n %= 10000000;
    ans.push_back(n / 100000);
    n %= 100000;
    ans.push_back(n / 1000);
    n %= 1000;
    ans.push_back(n / 100);
    cout << ++kase << ". ";
    for (int i = 0; i < 4; ++i) {
      if (!ans[i]) continue;
      cout << ans[i] << ' ' << s[i] << ' ';
    }
    if (n) cout << n << '\n';
  }
  return 0;
}
