#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int n, cnt[26], jizz, ans, st;

bool check() {
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == 0) return false;
  }
  return true;
}

int main() {
  while (cin >> n, n) {
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    jizz = 0; ans = 1e9;
    for (int i = 0; i < n; ++i) {
      cnt[s[i] - 'a']++;
      if (!check()) continue;
      while (true) {
        if (i - jizz + 1 < ans) {ans = i - jizz + 1; st = jizz;}
        if (cnt[s[jizz] - 'a'] - 1 == 0) break;
        cnt[s[jizz] - 'a']--; jizz++;
      }
    }
    if (ans == 1e9) {cout << "not found\n";}
    else {
      cout << s.substr(st, ans) << endl;
    }
  }
  return 0;
}
