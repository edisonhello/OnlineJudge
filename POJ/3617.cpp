#include <iostream>
#include <string>
using namespace std;

int N, st, ed;
char c[2005];
string ans;

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> c[i];
  st = 0; ed = N - 1;
  while (ans.length() < N) {
    if (c[st] < c[ed]) ans += c[st++];
    else ans += c[ed--];
  }
  while (ans.length()) {
    if (ans.length() >= 80) cout << ans.substr(0, 80) << endl, ans = ans.substr(80, ans.length() - 80);
    else { cout << ans << endl; break; }
  }
  return 0;
}
