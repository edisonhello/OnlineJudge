#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

map<char, bool> m;

int main() {
  string map[12];
  int T;
  cin >> T;
  while (T--) {
    m.clear();
    for (int i = 0; i < 12; ++i) {
      cin >> map[i];
    }
    for (int i = 0; i < 12; ++i) {
      for (int j = 0; j < 6; ++j) {
        if (map[i][j] != '.' && map[i][j] != 'X') {
          if (m.find(map[i][j]) == m.end()) {
            m[map[i][j]] = true;
          }
        }
      }
    }
    cout << m.size() << endl;
  }
  return 0;
}
