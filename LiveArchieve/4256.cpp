#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

const int maxn = 100 + 5;
const int maxl = 200 + 5;

int T, A[maxl], N, M, L, dpa[maxl][maxn], ans, a, b;
bool adj[maxn][maxn], v[maxl][maxn];
int dp(int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    memset(v, false, sizeof(v)); memset(adj, false, sizeof(adj));
    while (M--) {
      cin >> a >> b;
      adj[a][b] = adj[b][a] = true;
    }
    ans = INT_MAX;
    cin >> L;
    for (int i = 1; i <= L; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) ans = min(dp(L, i), ans);
    cout << ans << '\n';
  }
  return 0;
}

int dp(int l, int n) {
  if (l == 1) return n != A[l];
  if (v[l][n]) return dpa[l][n];
  dpa[l][n] = INT_MAX;
  for (int i = 1; i <= N; ++i) {
    if (i == n || adj[i][n]) dpa[l][n] = min(dpa[l][n], dp(l - 1, i) + (n != A[l]));
  }
  v[l][n] = true;
  return dpa[l][n];
}
