#include <bits/stdc++.h>
using namespace std;

struct Edge { int from, to, w; }

const int maxn = 10000 + 5;
int N, k, size[maxn], dp[maxn], center, root;
vector<int> G[maxn], dep;

void CenterDecompose(int);
void GetSize(int, int);
void FindCenter(int, int);
int solve(int, int);
void GetDepth(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N >> k) {
    for (int i = 0; i < N; ++i) G[i].clear();
    for (int i = 0; i < N - 1; ++i) {
      int a, b, w;
      cin >> a >> b >> w;
      G[a].push_back((Edge){ a, b, w });
      G[b].push_back((Edge){ b, a, w });
    }
    CenterDecompose(0);
  }
  return 0;
}

void CenterDecompose(int x) {
  root = x; GetSize(x, -1);
  center = x; FindCenter(x, -1);
  ans += solve(center, 0);
}

void GetSize(int x, int fa) {
  size[x] = 1; dp[x] = 0;
  for (Edge e : G[x]) if (e.to != fa) {
    GetSize(e.to, x);
    size[x] += size[e.to];
    dp[x] = max(dp[x], size[e.to]);
  }
}

void FindCenter(int x, int fa) {
  dp[x] = max(dp[x], dp[root] - size[x]);
  if (dp[x] < dp[center]) center = x;
  for (Edge e : G[x]) if (e.to != fa) {
    FindCenter(e.to, x);
  }
}

int solve(int c, int depth) {
  int ret = 0;
  dep.clear();
  GetDepth(c, -1, depth);
  sort(dep.begin(), dep.end());
  
}

void GetDepth(int x, int fa, int depth) {
  dep.push_back(depth);
  for (Edge e : G[x]) if (e.to != fa) {
    GetDepth(e.to, x, depth + e.w);
  }
}
