#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> m1;
map<string, string> m2;
string cmd, name, death;

int main() {
  while (cin >> cmd) {
    if (cmd == "add") {
      cin >> name >> death;
      m1[name] = death;
      m2[death] = name;
    }
    if (cmd == "chk") {
      cin >> name;
      if (name[0] == 'n') {
        if (m1.find(name.substr(1, name.length() - 1)) == m1.end()) cout << "Not found.\n";
        else cout << name.substr(1, name.length() - 1) << ' ' << m1[name.substr(1, name.length() - 1)] << endl;
      } else {
        if (m2.find(name.substr(1, name.length() - 1)) == m2.end()) cout << "Not found.\n";
        else cout << m2[name.substr(1, name.length() - 1)] << ' ' << name.substr(1, name.length() - 1) << endl;
      }
    }
    if (cmd == "del") {
      cin >> name;
      if (name[0] == 'n') {
        death = m1[name.substr(1, name.length() - 1)];
        m1.erase(name.substr(1, name.length() - 1)), m2.erase(death);
      }
      else {
        death = m2[name.substr(1, name.length() - 1)];
        m2.erase(name.substr(1, name.length() - 1)), m1.erase(death);
      }
    }
  }
  return 0;
}
