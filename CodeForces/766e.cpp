#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
vector<int> G[maxn];
int N, A[maxn], dp[maxn], ans[maxn];

void DFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 0; i < N - 1; ++i) {
    int a, b; cin >> a >> b;
    G[a].push_back(b); G[b].push_back(a);
  }
  DFS(1, 0);
  for (int i = N; i >= 1; --i) {
    ans[i] = ans[i + 1] + (N - i + 1) * dp[i] ^ ans[i + 1];
    cout << ans[i] << '\n';
  }
  cout << ans[1] << '\n';
  return 0;
}

void DFS(int x, int fa) {
  dp[x] ^= A[x];
  for (int u : G[x]) if (u != fa) {
    dp[u] ^= dp[x];
    DFS(u, x);
  }
}
