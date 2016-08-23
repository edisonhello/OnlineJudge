#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    for (int i = 0; i < s.length(); ++i) {
      if (isalpha(s[i])) {
        if (s[i] < 97) {
          s[i] += 32;
        } else {
          s[i] -= 32;
        }
      } else {
        s[i] = ' ';
      }
    }
    cout << s << endl;
  }
  return 0;
}
