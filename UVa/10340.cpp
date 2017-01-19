#include <iostream>
#include <string>

std::string s, t;

int main() {
  std::ios_base::sync_with_stdio(false); std::cin.tie(0);
  while (std::cin >> s >> t) {
    int si = 0;
    for (int i = 0; i < t.length(); ++i) {
      if (si == s.length()) break;
      if (s[si] == t[i]) si++;
    }
    if (si == s.length()) std::cout << "Yes\n";
    else std::cout << "No\n";
  }
  return 0;
}
