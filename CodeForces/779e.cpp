#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int n, m;
string s[maxn], ans[2];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  string _; getline(cin, _);
  for (int i = 0; i < n; ++i) getline(cin, s[i]);
  for (int bit = 0; bit < m; ++bit) {
    int cnt[2]; memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 2; ++i) {
      unordered_map<string, char> var;
      for (int j = 0; j < n; ++j) {
        stringstream ss(s[j]);
        string osas, name; ss >> name; ss >> osas;
        vector<string> hao;
        char b;
        while (ss >> osas) hao.push_back(osas);
        if (hao.size() == 1) {
          if (hao[0] == "?") b = i ? '1' : '0';
          else b = hao[0][bit];
          if (hao[0] == "?") if (i) ++cnt[i];
          else if (hao[0][bit] == '1') ++cnt[i];
        }
        if (hao.size() == 3) {
          char b1, b2;
          if (hao[0] == "?") b1 = i + '0';
          else if (hao[0][0] >= 'a' && hao[0][0] <= 'z') b1 = var[hao[0]];
          else b1 = hao[0][bit];
          if (hao[2] == "?") b2 = i + '0';
          else if (hao[2][0] >= 'a' && hao[2][0] <= 'z') b2 = var[hao[2]];
          else b2 = hao[2][bit];
          if (hao[1] == "XOR") {
            if (b1 == '1' && b2 == '0' || b1 == '0' && b2 == '1') ++cnt[i], b = '1';
            else b = '0';
          }
          if (hao[1] == "AND") {
            if (b1 == '1' && b2 == '1') ++cnt[i], b = '1';
            else b = '0';
          }
          if (hao[1] == "OR") {
            if (b1 == '0' && b2 == '0') b = '0';
            else ++cnt[i], b = '1';
          }
        }
        var[name] = b;
      }
    }
    if (cnt[1] > cnt[0]) ans[0] += '1';
    else ans[0] += '0';
    if (cnt[1] < cnt[0]) ans[1] += '1';
    else ans[1] += '0';
  }
  cout << ans[1] << '\n' << ans[0] << '\n';
  return 0;
}
