#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;
int N, M, A, B, scc, node;
vector<int> G[maxn], R[maxn], topo, SCC[maxn];
bitset<maxn> v;
void DFS(int);
void dfs(int);
void DFS1(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> M;
  while (M--) {
    cin >> A >> B;
    G[A].push_back(B);
    R[B].push_back(A);
  }
  for (int i = 1; i <= N; ++i) if (!v[i]) DFS(i);
  v.reset();
  reverse(topo.begin(), topo.end());
  for (int i = 0; i < topo.size(); ++i) {
    if (!v[topo[i]]) ++scc, dfs(topo[i]);
  }
  v.reset();
  DFS1(SCC[scc][0]);
  if (node == N) cout << SCC[scc].size() << '\n';
  else cout << 0 << '\n';
  return 0;
}

void DFS(int x) {
  v[x] = true;
  for (int i = 0; i < G[x].size(); ++i) if (!v[G[x][i]]) DFS(G[x][i]);
  topo.push_back(x);
}

void dfs(int x) {
  v[x] = true;
  SCC[scc].push_back(x);
  for (int i = 0; i < R[x].size(); ++i) if (!v[R[x][i]]) dfs(R[x][i]);
}

void DFS1(int x) {
  v[x] = true;
  node++;
  for (int i = 0; i < R[x].size(); ++i) if (!v[R[x][i]]) DFS1(R[x][i]);
}
