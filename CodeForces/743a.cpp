#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n, a, b;
string s;

int main() {
  cin >> n >> a >> b;
  a--; b--;
  cin >> s;
  if (s[a] == s[b]) { cout << "0\n"; return 0; }
  for (int i = 1; ; ++i) {
    if (b - i >= 0) if (s[b - i] == s[a]) { cout << i << '\n'; return 0; }
    if (b + 1 < n) if (s[b + i] == s[a]) { cout << i << '\n'; return 0; }
  }
  return 0;
}
