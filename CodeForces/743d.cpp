#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 200000 + 5;
const long long INF = (1ll<<60);
int n, fa, ch;
long long dp[MAX], a[MAX], ans;
vector<int> T[MAX];
bitset<MAX> v;
void DFS(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  ans = -INF;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) dp[i] = -INF;
  for (int i = 1; i < n; ++i) {
    cin >> fa >> ch;
    T[fa].push_back(ch);
    T[ch].push_back(fa);
  }
  DFS(1);
  if (ans == -INF) cout << "Impossible\n";
  else cout << ans << '\n';
}

void DFS(int x) {
  int child = 0;
  v[x] = true;
  for (int u : T[x]) {
    if (v[u]) continue;
    DFS(u);
    a[x] += a[u];
    if (dp[x] != -INF) ans = max(ans, dp[u] + dp[x]);
    else dp[x] = max(dp[x], dp[u]);
  }
  dp[x] = max(dp[x], a[x]);
}
