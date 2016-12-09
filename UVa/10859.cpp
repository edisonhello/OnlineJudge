#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 5000;
int T, N, M, a, b, dpa[2][1005], ans;
bool v[2][1005];
vector<int> tree[1005];
int dp(int, int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> M; ans = 0;
    memset(dpa, 0, sizeof(dpa)); memset(v, false, sizeof(v));
    for (int i = 0; i < 1005; ++i) tree[i].clear();
    for (int i = 0; i < M; ++i) {
      cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
      if (!v[0][i]) ans += dp(i, 0, -1);
    }
    cout << ans / MOD << ' ' << M - (ans % MOD) << ' ' << ans % MOD << endl;
  }
  return 0;
}

int dp(int i, int j, int father) {
  if (v[j][i]) return dpa[j][i];
  dpa[j][i] = MOD;
  for (int c : tree[i]) {
    if (c != father) dpa[j][i] += dp(c, 1, i);
  }
  if (!j && father >= 0) dpa[j][i]++;
  if (j || father < 0) {
    int sum = 0;
    for (int c : tree[i]) if (c != father) sum += dp(c, 0, i);
    if (father >= 0) sum++;
    dpa[j][i] = min(sum, dpa[j][i]);
  }
  v[j][i] = true;
  return dpa[j][i];
}
