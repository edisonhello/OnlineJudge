#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctype.h>
#include <iomanip>
using namespace std;

int k, r, c, it, cnt, cs;
string s, ss;
char mat[25][25];
string encode(char);
void test();

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  // test();
  cin >> k;
  while (k--) {
    cin >> r >> c;
    getline(cin, s); ss = "";
    for (int _ = 1; _ < s.length(); ++_) {
      ss += encode(s[_]);
    }
    while (ss.length() < r * c) ss += '0';
    it = 0; cnt = 0;
    for (int l = 0; cnt < r * c; ++l) {
      for (int i = l; i < c - l; ++i) mat[l][i] = ss[it++], cnt++;
      for (int i = l + 1; i < r - l; ++i) mat[i][c - l - 1] = ss[it++], cnt++;
      for (int i = c - l - 2; i >= l; --i) mat[r - l - 1][i] = ss[it++], cnt++;
      for (int i = r - l - 2; i > l; --i) mat[i][l] = ss[it++], cnt++;
    }
    cout << ++cs << ' ';
    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) cout << mat[i][j];
    cout << endl;
  }
  return 0;
}

string encode(char c) {
  int num;
  if (!isalpha(c)) return "00000";
  if (c < 97) c += 32;
  num = c - 'a' + 1;
  string ret = "";
  while (num) {
    if (num & 1) ret += '1';
    else ret += '0';
    num /= 2;
  }
  while (ret.length() < 5) ret += '0';
  reverse(ret.begin(), ret.end());
  return ret;
}

void test() {
  int r, c, mat[25][25];
  while (cin >> r >> c) {
    it = 0; cnt = 0;
    for (int l = 0; cnt < r * c; ++l) {
      for (int i = l; i < c - l; ++i) mat[l][i] = cnt++;
      for (int i = l + 1; i < r - l; ++i) mat[i][c - l - 1] = cnt++;
      for (int i = c - l - 2; i >= l; --i) mat[r - l - 1][i] = cnt++;
      for (int i = r - l - 2; i > l; --i) mat[i][l] = cnt++;
    }
    // cout << ++cs << ' ';
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) cout << setw(3) << mat[i][j];
      cout << endl;
    }
    cout << endl;
  }
}
