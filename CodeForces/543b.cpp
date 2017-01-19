#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <utility>
using namespace std;

struct Heap {
  int id, w;
  bool operator>(const Heap& rhs) const {
    return w > rhs.w;
  }
};

const int maxn = 3000 + 5, maxm = 4500000 + 5;
vector<int> G[maxn];
int N, M, a, b, s1, t1, l1, s2, t2, l2, d[maxn], id, ans, t[maxn];
bool v[maxn], used[maxm];
priority_queue<Heap, vector<Heap>, greater<Heap>> pq;
map<pair<int, int>, int> mp;

void path(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    mp[make_pair(a, b)] = ++id;
    mp[make_pair(b, a)] = id;
  }
  cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
  pq.push((Heap){ s1, 0 });
  memset(v, false, sizeof(v));
  fill(d, d + maxn, INT_MAX);
  d[s1] = 0;
  t[s1] = s1;
  while (pq.size()) {
    auto heap = pq.top(); pq.pop();
    if (v[heap.id]) continue;
    v[heap.id] = true;
    for (int u : G[heap.id]) if (heap.w + 1 < d[u]) {
      d[u] = heap.w + 1;
      t[u] = heap.id;
      pq.push((Heap){ u, d[u] });
    }
  }
  if (d[t1] > l1) { cout << "-1\n"; return 0; }
  path(t1);
  pq.push((Heap){ s2, 0 });
  memset(v, false, sizeof(v));
  fill(d, d + maxn, INT_MAX);
  d[s2] = 0;
  t[s2] = s2;
  while (pq.size()) {
    auto heap = pq.top(); pq.pop();
    if (v[heap.id]) continue;
    v[heap.id] = true;
    for (int u : G[heap.id]) {
      int w = 1, id = mp[make_pair(heap.id, u)];
      if (used[id]) w = 0;
      if (heap.w + w < d[u]) {
        d[u] = heap.w + w;
        t[u] = heap.id;
        pq.push((Heap){ u, d[u] });
      }
    }
  }
  if (d[t2] > l2) { cout << "-1\n"; return 0; }
  path(t2);
  cout << M - ans << '\n';
  return 0;
}

void path(int x) {
  if (x != t[x]) path(t[x]);
  if (mp.find(make_pair(x, t[x])) == mp.end()) return;
  int id = mp[make_pair(x, t[x])];
  if (!used[id]) ans++, used[id] = true;
}
