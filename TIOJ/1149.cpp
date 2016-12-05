#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

string s1, s2;
int K, n, m, a, b;
char c1, c2;
bool v[35];
vector<int> G[35];
bool k;
bool DFS(int, int);
int jizz(const string&);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> K;
  while (K--) {
    cin >> n >> m;
    for (int i = 0; i < 35; ++i) G[i].clear();
    while (m--) {
      cin >> s1 >> s2; c1 = s1[0]; c2 = s2[0]; a = jizz(s1.substr(1, s1.length() - 1)); b = jizz(s2.substr(1, s2.length() - 1));
      G[a + ((c1 == 'h') ? n : 0)].push_back(b + ((c2 == 'm') ? n : 0));
      G[b + ((c2 == 'h') ? n : 0)].push_back(a + ((c1 == 'm') ? n : 0));
    }
    k = true;
    for (int i = 1; k && i <= n; ++i) {
      memset(v, false, sizeof(v));
      k = DFS(i, i);
      if (!k) {
        memset(v, false, sizeof(v)); k = DFS(n + i, n + i);
      }
    }
    if (k) cout << "GOOD\n";
    else cout << "BAD\n";
  }
  return 0;
}

bool DFS(int nw, int x) {
  v[nw] = true;
  if (nw - x == n || x - nw == n) return false;
  for (auto i : G[nw]) {
    if (!v[i] && !DFS(i, x)) return false;
  }
  return true;
}

int jizz(const string& s) {
  int ret;
  stringstream ss;
  ss << s; ss >> ret;
  return ret;
}
