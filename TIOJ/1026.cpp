#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int d, p;
string ans;
void solve();

int main() {
  cin >> d;
  ans = "";
  p = floor(log2(d));
  while (d) solve();
  cout << ans.length() << '\n' << ans << endl;
  return 0;
}

void solve() {
  if (d > 0) {
    d -= pow(2, p);
    ans = '+' + ans;
    p--;
  } else if (d < 0) {
    d += pow(2, p);
    ans = '-' + ans;
    p--;
  }
}
