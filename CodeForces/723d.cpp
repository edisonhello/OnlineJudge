#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <bitset>
using namespace std;

typedef pair<int, int> pii;
string mp[51];
int n, m, k, lake;
int v[51][51];
pair<int, int> p;
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<pii> lakep[2500];
bitset<2500> jizz;
int BFS(int, int, vector<pii>&);

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> mp[i];
  }
  lake = 0;
  memset(v, 1, sizeof(v));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (j == 0 || i == 0 || j == m - 1 || i == n - 1) jizz[i * 50 + j] = true;
      if (!v[i][j] && mp[i][j] == '.') {
        v[i][j] = true;
        int area = BFS(i, j, lakep[lake - 1]);
        if (area < 2500) lake++;
        pq.push(pii(area, lake - 1));
      }
    }
  }
  int ans = 0;
  // cout << "lake: " << lake << endl;
  for (int i = 0; i < lake - k; ++i) {
    p = pq.top(); pq.pop();
    ans += p.first;
    for (int j = 0; j < lakep[p.second].size(); ++j) {
      mp[lakep[p.second][j].first][lakep[p.second][j].second] = '*';
    }
  }
  cout << ans << endl;
  for (int i = 0; i < n; ++i) cout << mp[i] << endl;
  return 0;
}

int BFS(int i, int j, vector<pii>& lp) {
  int area = 1;
  queue<pii> q;
  q.push(pii(i, j));
  lp.push_back(pii(i, j));
  while (!q.empty()) {
    p = q.front();
    q.pop();
    if (jizz[p.first * 50 + p.second]) return (int)1e9;
    if (p.first + 1 < n - 1 && !v[p.first + 1][p.second] && mp[p.first + 1][p.second] == '.') {lp.push_back(pii(p.first + 1, p.second)); v[p.first + 1][p.second] = true; area++; q.push(pii(p.first + 1, p.second));}
    if (p.first - 1 >= 1 && !v[p.first - 1][p.second] && mp[p.first - 1][p.second] == '.') {lp.push_back(pii(p.first - 1, p.second)); v[p.first - 1][p.second] = true; area++; q.push(pii(p.first - 1, p.second));}
    if (p.second + 1 < m - 1 && !v[p.first][p.second + 1] && mp[p.first][p.second + 1] == '.') {lp.push_back(pii(p.first, p.second + 1)); v[p.first][p.second + 1] = true; area++; q.push(pii(p.first, p.second + 1));}
    if (p.second - 1 >= 1 && !v[p.first][p.second - 1] && mp[p.first][p.second - 1] == '.') {lp.push_back(pii(p.first, p.second - 1)); v[p.first][p.second - 1] = true; area++; q.push(pii(p.first, p.second - 1));}
  }
  return area;
}
