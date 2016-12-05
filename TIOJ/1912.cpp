#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int N, R;
string s, sss;
set<string> res;
vector<int> ans;
int root(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> R;
  cin >> s; res.clear();
  for (int i = 0; i < 10; ++i) {
    if (root(i) == R) ans.push_back(i);
  }
  for (int _ = 0; _ < ans.size(); ++_) {
    for (int i = 0; i < s.length(); ++i) {
      res.insert(s.substr(0, i) + (char)(ans[_] + '0') + s.substr(i, s.length() - i));
    }
    res.insert(s.substr(0, s.length()) + (char)(ans[_] + '0'));
  }
  auto st = res.begin(); st++;
  auto ed = res.end(); ed--;
  for (; st != ed; st++) cout << *st << endl;
  return 0;
}

int root(int plus) {
  int ret = plus;
  stringstream ss;
  for (int i = 0; i < s.length(); ++i) ret += s[i] - '0';
  while (ret > 9) {
    ss.clear(); ss << ret; ss >> sss; ret = 0;
    for (int i = 0; i < sss.length(); ++i) ret += sss[i] - '0';
  }
  return ret;
}
