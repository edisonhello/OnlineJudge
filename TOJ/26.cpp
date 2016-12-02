#include <string>
#include <iostream>
#include <cstring>
#define max(x,y) x>y?x:y
using namespace std;

string s, ret;
int T, z[6005], N, L, R, mx;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> s; ret = ".";
    for (int i = 0; i < s.length(); ++i) ret += s[i], ret += '.';
    N = ret.length(); memset(z, 0, sizeof(z));
    z[0] = 1; L = 0; R = 0;
    for (int i = 1; i < N; ++i) {
      z[i] = (R > i) ? min(z[L * 2 - i], R - i) : 1;
      while (i - z[i] >= 0 && i + z[i] < N && ret[i - z[i]] == ret[i + z[i]]) z[i]++;
      if (i + z[i] > R) R = i + z[i], L = i;
    }
    mx = 0;
    for (int i = 1; i < N; ++i) mx = max(mx, z[i]);
    cout << (mx - 1) / 2 << endl;
  }
}
