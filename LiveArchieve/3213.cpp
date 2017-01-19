#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int mp[27];
string s, t;
bool ans;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> s >> t) {
    memset(mp, 0, sizeof(mp));
    if (s.length() != t.length()) { cout << "NO\n"; continue; }
    ans = true;
    swap(s, t);
    for (int i = 0; i < s.length(); ++i) {
      if (mp[s[i] - 'A' + 1] && mp[s[i] - 'A' + 1] != t[i] - 'A' + 1) ans = false;
      else mp[s[i] - 'A' + 1] = t[i] - 'A' + 1;
    }
    cout << (ans ? "YES\n" : "NO\n");
  }
  return 0;
}
