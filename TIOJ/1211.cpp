// #include <iostream>
// #include <vector>
// #include <utility>
// #include <cstring>
// #include <queue>
// #define pii pair<int, int>
// #define INF 1e9
// using namespace std;
//
// vector<pii> G[10010];
// int d[10010], n, m, a, b, w, mn, cnt, s[10010], sz[10010], mns, start, node;
// bool v[10010], p;
//
// int main() {
//     while (cin >> n >> m) {
//         if (n == 0 && m == 0) break;
//         for (int i = 0; i <= n; ++i) G[i].clear();
//         for (int i = 0; i <= n; ++i) d[i] = INF;
//         memset(v, false, sizeof(v));
//         for (int i = 0; i < m; ++i) {
//             cin >> a >> b >> w;
//             G[a].push_back(pii(b, w));
//             G[b].push_back(pii(a, w));
//         }
//         d[1] = 0;
//         cnt = 0;
//         node = 0;
//         while (node < n) {
//             mn = INF;
//             for (int i = 1; i <= n; ++i) {
//                 if (!v[i] && d[i] < mn) {
//                     mn = d[i];
//                     mns = i;
//                 }
//             }
//             if(mn == INF)break;
//             node++;
//             cnt += mn;
//             v[mns] = true;
//             for (int j = 0; j < G[mns].size(); ++j) {
//                 if (!v[G[mns][j].first]) {
//                     if (G[mns][j].second < d[G[mns][j].first]) {
//                         d[G[mns][j].first] = G[mns][j].second;
//                     }
//                 }
//             }
//         }
//         // cout << "node: " << node << endl;
//         if (node == n) cout << cnt << endl;
//         else cout << -1 << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <cstring>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> iii;
int djs[10010];

int F(int x) {return djs[x] == x ? x : djs[x] = F(djs[x]);}

int U(int x, int y) {
  x = F(x), y = F(y);
  djs[x] = y;
}

vector<iii> G;
int n, m, a, b, c;
int Kruskal();

int main() {
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    G.clear();
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      G.push_back(iii(c, a, b));
      G.push_back(iii(c, b, a));
    }
    sort(G.begin(), G.end());
    cout << Kruskal() << endl;
  }
  return 0;
}

int Kruskal() {
  int cnt = 1, ans = 0;
  for (int i = 1; i <= n; ++i) djs[i] = i;
  for (int i = 0; i < 2 * m; ++i) {
    int x = F(get<1>(G[i])), y = F(get<2>(G[i]));
    // cout << "ans: " << ans << endl;
    if (x == y) continue;
    U(x, y);
    ans += get<0>(G[i]);
    if (++cnt == n) return ans;
  }
  return -1;
}
