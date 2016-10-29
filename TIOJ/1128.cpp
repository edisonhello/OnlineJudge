#include <iostream>
#include <utility>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

vector<pair<int, double>> G[6];
double b[6], w[6], ans;
string s;
int n;
void init();
priority_queue<double, vector<double>, less<double>> pq;
void DFS(int, int, double);

int main() {
  init();
  while (cin >> s >> n) {
    while (pq.size()) pq.pop();
    ans = 0.0;
    if (s[0] == 'W') DFS(1, 0, 0.2);
    else DFS(1, 0, 0.8);
    if (n > pq.size()) { cout << "No Solution\n"; continue; }
    for (int i = 0; i < n; ++i) {
      ans += pq.top(); pq.pop();
    }
    cout << fixed << setprecision(8) << ans << endl;
  }
  return 0;
}

void init() {
  b[1] = 0.8; b[2] = 0.2; b[3] = 0.4; b[4] = 0.7; b[5] = 0.4;
  w[1] = 0.2; w[2] = 0.8; w[3] = 0.6; w[4] = 0.3; w[5] = 0.6;
  G[1].push_back(make_pair(2, 1.0));
  G[2].push_back(make_pair(1, 0.2)); G[2].push_back(make_pair(2, 0.4)); G[2].push_back(make_pair(3, 0.2)); G[2].push_back(make_pair(4, 0.2));
  G[3].push_back(make_pair(2, 0.3)); G[3].push_back(make_pair(3, 0.4)); G[3].push_back(make_pair(5, 1.0));
  G[4].push_back(make_pair(2, 0.8)); G[4].push_back(make_pair(4, 0.1)); G[4].push_back(make_pair(5, 0.1));
  G[5].push_back(make_pair(3, 0.7)); G[5].push_back(make_pair(4, 0.3));
}

void DFS(int x, int nw, double cur) {
  // cout << "x: " << x << " nw: " << s[nw] << " cur: " << cur << endl;
  if (nw == s.length() - 1) { pq.push(cur); return; }
  // if (s[nw] == 'W') cur *= w[x];
  // else cur *= b[x];
  for (auto i : G[x]) {
    if (s[nw + 1] == 'W') DFS(i.first, nw + 1, cur * i.second * w[i.first]);
    else DFS(i.first, nw + 1, cur * i.second * b[i.first]);
  }
}
