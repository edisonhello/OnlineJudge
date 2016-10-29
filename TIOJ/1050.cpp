#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> mp;
int s, n, x, num, level;
string s, pre;
vector<string> ss[30];
string target[30];

int main() {
  while (cin >> s, s) {
    mp.clear();
    for (int i = 0; i < s; ++i) {
      cin >> s >> x >> num;
      mp[s] = x;
      for (int j = 0; j < num; ++j) {
        cin >> pre;
        ss[i].push_back(pre);
      }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> target[i];
    level = 1;
    while (true) {
      if (level > 99) break;

    }
  }
}
