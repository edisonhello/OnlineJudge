#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <ctype.h>
using namespace std;

stringstream ss;
string s;
map<string, int> mp1, mp2;
string lower(const string&);
bool jizz;

int main() {
  while (getline(cin, s)) {
    mp1.clear(); mp2.clear();
    for (auto& c : s) if (!isalpha(c)) c = ' ';
    ss.clear(); ss << s;
    while (ss >> s) {
      if (mp1.find(lower(s)) == mp1.end()) mp1[lower(s)] = 0;
      mp1[lower(s)]++;
    }
    getline(cin, s);
    for (auto& c : s) if (!isalpha(c)) c = ' ';
    ss.clear(); ss << s;
    while (ss >> s) {
      if (mp2.find(lower(s)) == mp2.end()) mp2[lower(s)] = 0;
      mp2[lower(s)]++;
    }
    jizz = false;
    for (auto i : mp1) {
      if (i.second >= 2 && mp2[i.first] >= 2) {
        jizz = true;
        cout << i.first << endl;
      }
    }
    if (!jizz) cout << "<NONE>\n";
    cout << endl;
  }
  return 0;
}

string lower(const string& s) {
  string ret = "";
  for (auto c : s) {
    if (c >= 'A' && c <= 'Z') c += 32;
    ret += c;
  }
  return ret;
}
