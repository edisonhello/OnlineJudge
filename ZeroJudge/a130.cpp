#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<int, int, string> www[10];
int t, mx, jizz, Case;
string s;

bool cmp(tuple<int, int, string> a, tuple<int, int, string> b) {
  return get<0>(a) == get<0>(b) ? get<1>(a) < get<1>(b) : get<0>(a) > get<0>(b);
}

int main() {
  cin >> t;
  Case = 1;
  while (t--) {
    for (int i = 0; i < 10; ++i) {
      cin >> s >> jizz;
      www[i] = tuple<int, int, string>(jizz, i, s);
    }
    sort(www, www + 10, cmp);
    mx = get<0>(www[0]);
    cout << "Case #" << Case << ":\n";
    for (int i = 0; i < 10; ++i) {
      if (get<0>(www[i]) == mx) cout << get<2>(www[i]) << endl;
      else break;
    }
    Case++;
  }
  return 0;
}
