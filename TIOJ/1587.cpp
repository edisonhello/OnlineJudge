#include <iostream>
#include <string>
using namespace std;

string s, ans;
int main() {
  cin >> s;
  int l = s.length();
  ans = s;
  for (int i = l - 2; i >= 0; --i) ans += s[i];
  cout << ans << endl;
  return 0;
}
