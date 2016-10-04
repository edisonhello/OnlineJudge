#include <iostream>
#include <memset>
#include <vector>
using namespace std;

short key[1000010];
int T, n, l, idx;
vector<int> up, down;
bool p, keep;
bool jizz();

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> l;
    p = true;
    memset(key, 0, sizeof(key));
    for (int i = 0; i < n; ++i) {
      up.clear(); down.clear();
      while (cin >> idx, idx) up.push_back(idx);
      while (cin >> idx, idx) down.push_back(idx);
      if (!jizz()) p = false, cout << "No\n";
    }
    if (p) cout << "Yes\n";
  }
  return 0;
}

bool jizz() {
  keep = false;
  for (int i = 0; i < up.size() && !keep; ++i) {
    if (key[up[i]] == 0 || key[up[i]] == 1) key[up[i]] = 1;
    else keep = true;
  }
  for (int i = 0; i < down.size() && !keep; ++i) {
    if (key[up[i]] == 0 || key[up[i]] == 2) key[up[i]] = 2;
    else keep = true;
  }
  if (!keep) return true;
  else {
    for (int i = 0; i < up.size() && !keep; ++i) {
      if (key[n - up[i] + 1] == 0 || key[n - up[i] + 1] == 1) key[up[i]] = 1;
      else keep = true;
    }
    for (int i = 0; i < down.size() && !keep; ++i) {
      if (key[up[i]] == 0 || key[up[i]] == 2) key[up[i]] = 2;
      else keep = true;
    }
  }
}
