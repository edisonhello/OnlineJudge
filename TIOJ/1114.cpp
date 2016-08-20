#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <locale>
using namespace std;

map< string, int > nmap;

int main() {
  string s1, s2;
  while (getline(cin, s1)) {
    nmap.clear();
    getline(cin, s2);

    // transform(s1.begin(), s1.end(), s1.begin(), tolower)
    // transform(s2.begin(), s2.end(), s2.begin(), tolower)
    // s1 = tolower(s1);
    // s2 = tolower(s2);

    locale loc;

    for (int i = 0; i < s1.length(); ++i) {
      s1[i] = tolower(s1[i], loc);
    }

    for (int i = 0; i < s2.length(); ++i) {
      s2[i] = tolower(s2[i], loc);
    }

    int index = 0;
    int prev = 0;
    while (index < s1.length()) {
      if (!isalpha(s1[index])) {
        string tmp = s1.substr(prev, index - prev);
        if (nmap.find(tmp) == nmap.end()) {
          nmap[tmp] = 0;
        }
        nmap[tmp]++;
        prev = index;
      } else {
        index++;
      }
    }

    index = 0;
    prev = 0;
    while (index < s2.length()) {
      if (!isalpha(s2[index])) {
        string tmp = s2.substr(prev, index - prev);
        if (nmap.find(tmp) == nmap.end()) {
          nmap[tmp] = 0;
        }
        nmap[tmp]++;
        prev = index;
      } else {
        index++;
      }
    }

    int ans = 0;
    for (map< string, int >::iterator it = nmap.begin(); it != nmap.end(); it++) {
      if (it->second > 2) {
        cout << it->first << endl;
        ans++;
      }
    }
    cout << ans;
    if (!ans) cout << "<NONE>" << endl;
    cout << endl;
  }
  return 0;
}
