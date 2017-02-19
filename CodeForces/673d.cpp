#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int N, K, a, b, c, d;
vector<int> vec;
vector<int> G[maxn];
bool v[maxn];

void dfs(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> K;
  cin >> a >> b >> c >> d;
  if (K == N - 1) return cout << "-1\n", 0;
  vec.push_back(a); vec.push_back(d); vec.push_back(c);
  for (int i = 1; i <= N; ++i) {
    if (i == a || i == b || i == c || i == d) continue;
    vec.push_back(i);
  }
  vec.push_back(b);
  for (int i = 0; i < vec.size() - 1; ++i) {
    int x = vec[i], y = vec[i + 1];
    G[x].push_back(y);
    G[y].push_back(x);
  }
  G[vec[0]].push_back(vec[vec.size() - 1]); G[vec[vec.size() - 1]].push_back(vec[0]);
  memset(v, false, sizeof(v));
  dfs(a, b); cout << '\n';
  memset(v, false, sizeof(v));
  dfs(c, d); cout << '\n';
  return 0;
}

void dfs(int x, int ban) {
  cout << x << ' ';
  v[x] = true;
  for (int u : G[x]) {
    if (v[u]) continue;
    if (u != ban) dfs(u, 0);
  }
}
