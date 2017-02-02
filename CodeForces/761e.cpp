#include <bits/stdc++.h>
using namespace std;

const int maxn = 30 + 5;
const int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
vector<int> G[maxn];
int n, a, b;

tuple<bool, set<pair<int, int>>, map<int, pair<int, int>>> DFS(int, int, int, int, set<pair<int, int>>, map<int, pair<int, int>>);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) cin >> a >> b, G[a].push_back(b), G[b].push_back(a);
  auto ret = DFS(1, 0, 0, 0, set<pair<int, int>>(), map<int, pair<int, int>>());
  if (!get<0>(ret)) cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << get<2>(ret)[i].first << ' ' << get<2>(ret)[i].second << '\n';
  }
  return 0;
}

tuple<bool, set<pair<int, int>>, map<int, pair<int, int>>> DFS(int p, int fa, int x, int y, set<pair<int, int>> P, map<int, pair<int, int>> M) {
  if (P.count(make_pair(x, y))) return make_tuple(false, set<pair<int, int>>(), map<int, pair<int, int>>());
  P.insert(make_pair(x, y)), M[p] = make_pair(x, y);
  bool ret = true;
  for (int u : G[p]) if (u != fa) {
    bool jizz = false;
    bool lalala = true;
    for (int k = 1; lalala; ++k) {
      for (int i = 0; i < 4; ++i) {
        auto res = DFS(u, p, x + k * dx[i], y + k * dy[i], P, M);
        if (get<0>(res)) {
          for (auto j : get<1>(res)) P.insert(j);
          for (auto j : get<2>(res)) M[j.first] = j.second;
          jizz = true;
          lalala = false;
          break;
        }
      }
    }
    ret &= jizz;
  }
  return make_tuple(ret, P, M);
}
