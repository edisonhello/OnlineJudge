#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int mt[35][35], m, __i, __j, N, ans[35][35], tmp[35][35], cnt;
string s;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      mt[i][j] = s[j] == '1';
    }
  }
  cin >> __i >> __j >> N;
  for (int i = 0; i < m; ++i) ans[i][i] = 1;
  for (int _ = 1; _ <= N; ++_) {
    for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) tmp[i][j] = ans[i][j], ans[i][j] = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < m; ++k) {
          ans[i][j] += tmp[i][k] * mt[j][k];
        }
      }
    }
    cnt += ans[__i - 1][__j - 1];
  }
  cout << cnt << endl;
  return 0;
}
