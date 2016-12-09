#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge {
  int st, ed, w;
};

struct Node {
  int id, dis;
  bool operator>(const Node& node) const {
    return dis > node.dis;
  }
};

const int INF = INT_MAX;
vector<Edge> G[505], fast;
vector<int> p;
int sd[505], de[505], d[505], sp[505], pe[505];
int N, S, E, M, K, a, b, w, ret, ans, t1, t2;
priority_queue<Node, vector<Node>, greater<Node>> pq;
bitset<505> v;
void path1(int);
void path2(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N >> S >> E) {
    for (int i = 1; i <= N; ++i) G[i].clear();
    fast.clear(); p.clear();
    memset(sd, 0, sizeof(sd)); memset(de, 0, sizeof(de));
    memset(sp, 0, sizeof(sp)); memset(pe, 0, sizeof(pe));
    cin >> M;
    while (M--) {
      cin >> a >> b >> w;
      G[a].push_back((Edge){ a, b, w });
      G[b].push_back((Edge){ b, a, w });
    }
    cin >> K;
    while (K--) {
      cin >> a >> b >> w;
      fast.push_back((Edge){ a, b, w });
    }
    while (pq.size()) pq.pop();
    for (int i = 1; i <= N; ++i) d[i] = INF;
    v.reset(); pq.push((Node){ S, 0 }); d[S] = 0; sp[S] = S;
    while (pq.size()) {
      Node x = pq.top(); pq.pop();
      if (!v[x.id]) {
        v[x.id] = true;
        for (auto u : G[x.id]) {
          if (d[u.ed] > d[x.id] + u.w) {
            d[u.ed] = d[x.id] + u.w;
            sp[u.ed] = x.id;
            pq.push((Node){ u.ed, d[u.ed] });
          }
        }
      }
    }
    for (int i = 1; i <= N; ++i) sd[i] = d[i];
    for (int i = 1; i <= N; ++i) d[i] = INF;
    v.reset(); pq.push((Node){ E, 0 }); d[E] = 0; pe[E] = E;
    while (pq.size()) {
      Node x = pq.top(); pq.pop();
      if (!v[x.id]) {
        v[x.id] = true;
        for (auto u : G[x.id]) {
          if (d[u.ed] > d[x.id] + u.w) {
            d[u.ed] = d[x.id] + u.w;
            pe[u.ed] = x.id;
            pq.push((Node){ u.ed, d[u.ed] });
          }
        }
      }
    }
    for (int i = 1; i <= N; ++i) de[i] = d[i];
    ans = INF;
    for (auto e : fast) {
      ret = sd[e.st] + e.w + de[e.ed];
      if (ret < ans) ans = ret, t1 = e.st, t2 = e.ed;
    }
    if (ans < sd[E]) {
      path1(t1); path2(t2);
      reverse(p.begin(), p.end());
      for (int x : p) cout << x << ' ';
      cout << '\n';
      cout << t1 << '\n';
      cout << ans << '\n';
    } else {
      path1(E);
      cout << "Ticket Not Used\n";
      cout << sd[E] << '\n';
    }
  }
  return 0;
}

void path1(int x) {
  if (x != sp[x]) path1(sp[x]);
  cout << x << ' ';
}

void path2(int x) {
  if (x != pe[x]) path2(pe[x]);
  p.push_back(x);
}
