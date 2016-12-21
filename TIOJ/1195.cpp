#include <iostream>
#include <string>
using namespace std;

int n, tot;
string s;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> s;
    if (s[2] == s[3] && s[3] == s[4] && s[4] == s[5]) tot += 2000;
    else if (s[2] == s[3] && s[3] == s[4] || s[3] == s[4] && s[4] == s[5]) tot += 1000;
    else if (s[2] == s[3] && s[4] == s[5]) tot += 1500;
  }
  cout << tot << '\n';
}
