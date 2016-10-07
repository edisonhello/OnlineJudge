#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <bitset>
using namespace std;

int W[15][15];
int dp[15][15];
int mid[15][15];
int n, m, a, b, k, tot, len, mn, node, mns;
bitset<15> v;
vector<int> landmark(13);
vector<int> jizz(13);
void Floyd_Warshell();
void findPath(int, int, int);
void debug();
vector<int> path[15];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) W[i][j] = (int)1e9;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> k;
    W[a][b] = k, W[b][a] = k;
  }
  cin >> tot;
  len = 0;
  for (int i = 0; i < tot; ++i) cin >> landmark[i];
  Floyd_Warshell();
  node = 1; v[landmark[0]] = true; jizz.push_back(0);
  int prev = landmark[0];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  while (node < tot) {
    mn = 1e9;
    for (int i = 0; i < tot; ++i) {
      if (!v[landmark[i]] && dp[prev][landmark[i]] < mn && dp[prev][landmark[i]] != 0) {
        mn = dp[prev][landmark[i]];
        mns = i;
      }
    }
    len += mn;
    v[mns] = true;
    jizz.push_back(mns);
    prev = landmark[mns];
    cout << prev << ' ';
    node++;
  }
  printf("Minimum travel distance: %d\n", len);
  for (int i = 1; i < tot; ++i) {
    findPath(landmark[i - 1], landmark[i], i - 1);
  }
  sort(path, path + tot);
  printf("Travel route:");
  for (int i = 0; i < path[0].size(); ++i) {
    printf(" %d", path[0][i]);
  }
  printf("\n");
  return 0;
}

void Floyd_Warshell() {
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dp[i][j] = W[i][j], mid[i][j] = -1;
  for (int i = 0; i < n; ++i) dp[i][i] = 0;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][k] + dp[k][j] < dp[i][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
          mid[i][j] = k;
        }
      }
    }
  }
}

void findPath(int i, int j, int idx) {
  if (mid[i][j] == -1) return;
  findPath(i, mid[i][j], idx);
  path[idx].push_back(mid[i][j]);
  findPath(mid[i][j], j, idx);
}
