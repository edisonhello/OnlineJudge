#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
using namespace std;

pii com[200];
int n, m, t, tot, mon, last;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    tot = 0;
    for (int i = 0; i < n; ++i) {cin >> com[i].first >> com[i].second; tot += com[i].second;}
    if (tot < m) cout << "so sad" << endl;
    else {
      tot = 0; mon = 0; last = 0;
      sort(com, com + n);
      while (tot < m) {
        mon += com[last].first * com[last].second;
        tot += com[last].second;
        last++;
      }
      mon -= com[last - 1].first * (tot - m);
      cout << mon << endl;
    }
  }
  return 0;
}
