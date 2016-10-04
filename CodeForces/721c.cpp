#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> pii;

vector<pii> G[5010];
int N, M, T, u, v, t, mn;
vector<int> path;
bool vv[5010];
int d[5010], dp[5010];

int main() {
  cin >> N >> M >> T;
  for (int i = 0; i < M; ++i) {
    cin >> u >> v >> t;
    G[u].push_back(pii(v, t));
  }
  memset(vv, false, sizeof(vv));
  fill(d, d + 5010, INF);
  vv[1] = true;
  d[1] = 0;
  int start = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < G[start].size(); ++j) {
      if (d[start] + G[start][j].second < d[G[start][j].first] && !vv[G[start][j].first]) d[G[start][j].first] = d[start] + G[start][j].second;
    }
    mn = 1e9;
    for (int j = 1; j <= N; ++j) {
      if (d[j] < mn && !vv[j]) {
        mn = d[j]; start = j;
      }
    }
    vv[start] = true;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = T; j >= d[i]; --j) {
      if (dp[j] < dp[j - d[i]] + 1) dp[j] = dp[j - d[i]] + 1;
    }
  }
  cout << dp[T] << endl;
  return 0;
}
