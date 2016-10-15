#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int n, m, jizz, pre;
vector<int> v;
vector<int> ans;
vector<int> tmp;
vector<int> vv;
stringstream ss;
string s;

int main() {
  cin >> n >> m;
  scanf("\n");
  for (int i = 0; i < m; ++i) cin >> jizz, vv.push_back(jizz);
  scanf("\n");
  for (int i = 0; i < n; ++i) {
    v.clear(); ans.clear(); tmp.clear();
    getline(cin, s);
    ss.clear();
    ss << s;
    // cout << s << endl;
    while (ss >> jizz) v.push_back(jizz);
    tmp = v; pre = v[v.size() - 1];
    for (int j = v.size() - 2; j >= 0; --j) {
      if (pre > v[j]) ans.push_back(1);
      else ans.push_back(0);
      pre = abs(v[j + 1] - v[j]);
    }
    reverse(ans.begin(), ans.end());
    if (ans == vv) {
      for (int j = 0; j < v.size(); ++j) cout << tmp[j] << ' ';
      cout << endl;
    }
  }
  return 0;

}
