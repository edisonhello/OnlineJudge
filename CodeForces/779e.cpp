#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int n, m;
string s[maxn], ans[2];
char rec[maxn];
map<string, int> var;
vector<string> parse[maxn];

vector<string> Parse(const string&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  string _; getline(cin, _);
  for (int i = 0; i < n; ++i) {
    getline(cin, s[i]);
    parse[i] = Parse(s[i]);
  }
  for (int i = 0; i < n; ++i) {
    var[parse[i][0]] = i;
  }
  for (int bit = 0; bit < m; ++bit) {
    int cnt[2]; memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        char b;
        if (parse[j].size() == 3) {
          if (parse[j][2] == "?") b = i ? '1' : '0';
          else if (parse[j][2][0] >= 'a' && parse[j][2][0] <= 'z') b = rec[var[parse[j][2]]];
          else b = parse[j][2][bit];
          if (b == '1') ++cnt[i];
        }
        if (parse[j].size() == 5) {
          char b1, b2;
          if (parse[j][2] == "?") b1 = i + '0';
          else if (parse[j][2][0] >= 'a' && parse[j][2][0] <= 'z') b1 = rec[var[parse[j][2]]];
          else b1 = parse[j][2][bit];
          if (parse[j][4] == "?") b2 = i + '0';
          else if (parse[j][4][0] >= 'a' && parse[j][4][0] <= 'z') b2 = rec[var[parse[j][4]]];
          else b2 = parse[j][4][bit];
          if (parse[j][3] == "XOR") {
            if (b1 == '1' && b2 == '0' || b1 == '0' && b2 == '1') ++cnt[i], b = '1';
            else b = '0';
          }
          if (parse[j][3] == "AND") {
            if (b1 == '1' && b2 == '1') ++cnt[i], b = '1';
            else b = '0';
          }
          if (parse[j][3] == "OR") {
            if (b1 == '0' && b2 == '0') b = '0';
            else ++cnt[i], b = '1';
          }
        }
        rec[j] = b;
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

vector<string> Parse(const string& s) {
  vector<string> ret;
  int ind = 0, cur = 0;
  while (ind < s.length()) {
    if (s[cur] == ' ') ret.push_back(s.substr(ind, cur - ind)), ind = cur + 1;
    ++cur;
  }
  if (ind < cur) ret.push_back(s.substr(ind, cur - ind));
  return ret;
}
