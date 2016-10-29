#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s, ret;
vector<string> v;
string push, s2;

int main() {
  while (cin >> n) {
    cin >> s;
    v.clear();
    for (int i = 0; i < n; ++i) {
      push = "";
      for (int j = i; j < n; ++j) push += s[j];
      for (int j = 0; j < i; ++j) push += s[j];
      if (i == 1) s2 = push;
      v.push_back(push);
    }
    sort(v.begin(), v.end());
    ret = "";
    for (int i = 0; i < n; ++i) ret += v[i][n - 1];
    cout << ret << endl;
    for (int i = 0; i < n; ++i) if (v[i] == s2) {cout << i + 1 << endl; break;}
  }
  return 0;
}
