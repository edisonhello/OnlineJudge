#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, tmp;
  while (getline(cin, s)) {
    tmp = "";
    for (int i = s.length() - 1; i >= 0; --i) {
      tmp += s[i];
    }
    if (tmp == s) cout << "palindrome" << endl;
    else cout << "not palindrome" << endl;
  }
  return 0;
}
