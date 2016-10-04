#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
string ss;
string sss;
string ssss;

int main() {
  while (cin >> s) {
    if (s == "END") break;
    ss = "", sss = "", ssss = "";
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '!') {ss += s[i + 1] == '1' ? '0' : '1'; i++;}
      else ss += s[i];
    }
    for (int i = 0; i < ss.length(); ++i) {
      if (ss[i] == '*') {
        if (sss[i - 1] == '1' && sss[i + 1] == '1') sss += '1';
        else sss += '0';
        i++;
      }
      else sss += ss[i];
    }
    for (int i = 0; i < sss.length(); ++i) {
      if (sss[i] == '+') {
        if (sss[i - 1] == '0' && sss[i + 1] == '0') ssss += '0';
        else ssss += '1';
        i++;
      } else {
        ssss += s[i];
      }
    }
    cout << ssss << endl;
  }
  return 0;
}
