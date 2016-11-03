#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int n;
map<string, string> mp;
string method, name, message;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  scanf("%d\n", n);
  while (n--) {
    getline(cin, method, ',');
    if (method == "\'Get\'") {
      getline(cin, name);
      if (mp.find(name) == mp.end()) cout << "\'404 IMouTo Not Found!\'" << endl;
      else cout << "\'200 ONiiChaN!\'" << "," << name << "," << mp[name] << endl;
    }
    if (method == "\'New\'") {
      getline(cin, name, ','); getline(cin, message);
      if (mp.find(name) != mp.end()) cout << "\'403 IMouTo Unhappy!\'" << endl;
      else {
        mp[name] = message;
        cout << "\'201 HaJiMeMaShiTe\'" << "," << name << endl;
      }
    }
    if (method == "\'Delete\'") {
      getline(cin, name);
      if (mp.find(name) == mp.end()) cout << "\'404 IMouTo Not Found!\'" << endl;
      else {
        mp.erase(name);
        cout << "\'202 SaYouNaRa\'" << "," << name << endl;
      }
    }
    if (method == "\'Post\'") {
      getline(cin, name, ','); getline(cin, message);
      if (mp.find(name) == mp.end()) cout << "\'404 IMouTo Not Found!\'" << endl;
      else {
        mp[name] += "\\";
        mp[name] += message;
        cout << "\'200 ONiiChaN!\'" << "," << name << endl;
      }
    }
  }
  return 0;
}
