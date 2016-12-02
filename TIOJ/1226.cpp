#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstring>
#define int long long
using namespace std;

string name[105];
int N, E, V, T, st, ed, w, c, dpa[1005], cs;
bool v[1005];
vector<pair<int, int>> G[1005];
int dp(int);

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> V >> E;
    for (int i = 1; i <= N; ++i) cin >> name[i];
    for (int i = 0; i <= V; ++i) G[i].clear();
    while (E--) {
      cin >> st >> ed >> w;
      G[ed].push_back({ st, w });
    }
    cout << "Game #" << ++cs << endl;
    for (int i = 1; i <= N; ++i) {
      memset(dpa, 0, sizeof(dpa)); memset(v, 0, sizeof(v));
      cout << name[i] << ": " << dp(i) % 32768 << endl;
    }
  }
  return 0;
}

int dp(int x) {
  if (v[x]) return dpa[x];
  for (auto i : G[x]) {
    dpa[x] += dp(i.first) + i.second;
    dpa[x] %= 32768;
  }
  v[x] = true;
  return dpa[x];
}
