#include <bits/stdc++.h>
using namespace std;

int n, m, kase;
map<string, int> t;
map<int, string> rev;
vector<int> G[30], R[30], scc;
bool v[30];
stack<int> s;

void dfs(int);
void find_scc(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> n >> m, n || m) {
    cout << "Calling circles for data set " << ++kase << ":\n";
    int ind = 0;
    for (int i = 0; i < 30; ++i) G[i].clear(), R[i].clear();
    t.clear(); rev.clear();
    for (int i = 0; i < m; ++i) {
      string a, b; cin >> a >> b;
      if (!t.count(a)) t[a] = ++ind, rev[ind] = a;
      if (!t.count(b)) t[b] = ++ind, rev[ind] = b;
      G[t[a]].push_back(t[b]); R[t[b]].push_back(t[a]);
    }
    memset(v, false, sizeof(v));
    for (int i = 1; i <= ind; ++i) if (!v[i]) dfs(i);
    memset(v, false, sizeof(v));
    while (s.size()) {
      if (!v[s.top()]) {
        scc.clear(), find_scc(s.top());
        for (int i = 0; i < scc.size() - 1; ++i) cout << rev[scc[i]] << ", ";
        cout << rev[scc[scc.size() - 1]] << '\n';
      }
      s.pop();
    }
    cout << '\n';
  }
  return 0;
}

void dfs(int x) {
  v[x] = true;
  for (int u : G[x]) if (!v[u]) dfs(u);
  s.push(x);
}

void find_scc(int x) {
  v[x] = true;
  scc.push_back(x);
  for (int u : R[x]) if (!v[u]) find_scc(u);
}
