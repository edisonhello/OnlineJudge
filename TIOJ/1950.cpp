#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5, maxi = 10000;
int N, M, A[maxn], cycle, idx[maxn], ans, a, b, adj[maxn], B[maxn];
bool v[maxn];
// vector<int> G[maxn];

void DFS(int, int);
void build(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> A[i], idx[A[i]] = i;
  for (int i = 1; i <= maxi; ++i) if (!v[i]) build(i, i);
  memset(v, false, sizeof(v));
  for (int i = 1; i <= N; ++i) if (!v[i]) DFS(i, i);
  cout << N - cycle << '\n';
  while (M--) {
    cin >> a >> b; cycle = 0;
    A[idx[a]] = b; A[idx[b]] = a;
    swap(idx[a], idx[b]);
    memset(v, false, sizeof(v));
    for (int i = 1; i <= maxi; ++i) if (!v[i]) DFS(i, i);
    cout << N - cycle << '\n';
  }
  return 0;
}

void DFS(int st, int x) {
  v[x] = true;
  if (A[x] == st) { cycle++; return; }
  if (!v[A[x]]) DFS(st, A[x]);
}

void build(int pre, int x) {
  v[x] = true;
}
