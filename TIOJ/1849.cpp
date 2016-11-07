#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <ctype.h>
using namespace std;

int n;
map<string, string> mp;
string method, name, message;
string lower(const string&);

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  scanf("%d\n", &n);
  while (n--) {
    getline(cin, method, ',');
    // cout << "method: " << method << endl;
    if (lower(method) == "\'get\'") {
      getline(cin, name);
      if (mp.find(name) == mp.end()) cout << "\'404 IMouTo Not Found!\'" << "," << name << endl;
      else cout << "\'200 ONiiChaN!\'" << "," << name << "," << mp[name] << endl;
    }
    if (lower(method) == "\'new\'") {
      getline(cin, name, ','); getline(cin, message);
      if (mp.find(name) != mp.end()) cout << "\'403 IMouTo Unhappy!\'" << "," << name << endl;
      else {
        mp[name] = message;
        cout << "\'201 HaJiMeMaShiTe\'" << "," << name << endl;
      }
    }
    if (lower(method) == "\'delete\'") {
      getline(cin, name);
      if (mp.find(name) == mp.end()) cout << "\'404 IMouTo Not Found!\'" << endl;
      else {
        mp.erase(name);
        cout << "\'202 SaYouNaRa\'" << "," << name << endl;
      }
    }
    if (lower(method) == "\'post\'") {
      getline(cin, name, ','); getline(cin, message);
      if (mp.find(name) == mp.end()) cout << "\'404 IMouTo Not Found!\'" << endl;
      else {
        mp[name] = mp[name].substr(0, mp[name].length() - 1) + "\\";
        mp[name] += message.substr(1, message.length() - 1);
        cout << "\'200 ONiiChaN!\'" << "," << name << endl;
      }
    }
  }
  return 0;
}

string lower(const string& s) {
  string ret = "";
  for (int i = 0; i < s.length(); ++i) {
    if (isalpha(s[i])) {
      if (s[i] < 95) ret += s[i] + 32;
      else ret += s[i];
    } else {
      ret += s[i];
    }
  }
  return ret;
}
