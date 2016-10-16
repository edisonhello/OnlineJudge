#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <ctype.h>
using namespace std;

stringstream ss;
string s;
string in;
map<string, int> m;
string lower(const string&);
bool p;
int pre;

int main() {
  while (getline(cin, in)) {
    m.clear();
    pre = 0;
    for (int i = 0; i < in.length(); ++i) {
      if (!isalpha(in[i])) {
        if (m.find(lower(in.substr(pre, i - pre))) == m.end()) m[lower(in.substr(pre, i - pre))] = 0;
        m[lower(in.substr(pre, i - pre))]++;
        pre = i + 1;
      }
    }
    getline(cin, in);
    pre = 0;
    for (int i = 0; i < in.length(); ++i) {
      if (!isalpha(in[i])) {
        if (m.find(lower(in.substr(pre, i - pre))) == m.end()) m[lower(in.substr(pre, i - pre))] = 0;
        m[lower(in.substr(pre, i - pre))]++;
        pre = i + 1;
      }
    }
    p = false;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
      if (it->second > 2) cout << it->first << endl, p = true;
    }
    if (!p) cout << "<NONE>";
    cout << endl;
  }
  return 0;
}

string lower(const string& s) {
  string ret = "";
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') ret += s[i] + 32;
    else ret += s[i];
  }
  return ret;
}
