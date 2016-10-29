#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int n, line, word, ch;
string s;
stringstream ss;

int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    line = 0, ch = 0, word = 0;
    while (getline(cin, s)) {
      if (s == "=====") break;
      line++;
      ch += s.length();
      ss.clear();
      ss << s;
      while (ss >> s) word++;
    }
    cout << line << ' ' << word << ' ' << ch << endl;
  }
  return 0;
}
