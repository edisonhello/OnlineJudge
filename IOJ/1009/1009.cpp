#include <iostream>
#include <string>
#include <fstream>
#define endl '\n'
using namespace std;

int mt[105][105], m, __i, __j, N, ans[105][105], tmp[105][105], cnt, n, st, ed;
string s;

int main() {
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> m;
  while (m--) {
    cin >> st >> ed;
    mt[st - 1][ed - 1] = 1;
  }
  cin >> __i >> __j >> N;
  for (int i = 0; i < n; ++i) ans[i][i] = 1;
  for (int _ = 1; _ <= N; ++_) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) tmp[i][j] = ans[i][j], ans[i][j] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          ans[i][j] += tmp[i][k] * mt[k][j];
        }
      }
    }
    cnt += ans[__i - 1][__j - 1];
  }
  cout << cnt << endl;
  return 0;
}
