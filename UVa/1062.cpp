#include <bits/stdc++.h>
using namespace std;

string s;
int kase;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> s, s != "end") {
    vector<char> v;
    v.push_back(s[0]);
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] > v.back()) v.push_back(s[i]);
      else *lower_bound(v.begin(), v.end(), s[i]) = s[i];
    }
    cout << "Case " << ++kase << ": " << v.size() << '\n';
  }
  return 0;
}
