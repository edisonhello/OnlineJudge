#include <bits/stdc++.h>
using namespace std;

const int maxn = 30000 + 5;
int N, M, a, b, root, best, Max;
vector<int> G[maxn];
vector<int> T[maxn];
bool v[maxn], same;

vector<int> DFS(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  while (M--) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> root;
  DFS(root);
  same = true;
  for (int i = 1; i <= N; ++i) {
    if (i == root) continue;
    if ((int)T[i].size() > Max) {
      Max = max(Max, (int)T[i].size());
      best = i;
      same = false;
    }
  }
  if (!same) cout << best << ' ' << N - Max + 1 << '\n';
  else cout << "0\n";
  return 0;
}

vector<int> DFS(int x) {
  v[x] = true;
  for (int u : G[x]) if (!v[u]) {
    vector<int> ret = DFS(u);
    for (int i : ret) T[x].push_back(i);
  }
  T[x].push_back(x);
  return T[x];
}
