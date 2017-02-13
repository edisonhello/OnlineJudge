#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 250000 + 5, MOD = 1000000, maxpq = 10000;
int N, b[maxn], inv;
struct Car { int x, v; } c[maxn];
struct Event {
  int i, j, x, t;
  bool operator>(const Event& e) const {
    return t == e.t ? x > e.x : t > e.t;
  }
};
vector<int> BIT[maxn];
map<int, int> m;
priority_queue<Event, vector<Event>, greater<Event>> pq;
stack<pair<int, int>> ans;

vector<int> sum(int);
void add(int, int);
void merge(vector<int>&, const vector<int>&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> c[i].x >> c[i].v, b[i] = c[i].v;
  sort(b + 1, b + N + 1);
  for (int i = 1; i <= N; ++i) m[b[i]] = i;
  for (int i = 1; i <= N; ++i) {
    vector<int> v = sum(m[c[i].v]);
    inv += i - 1 - (int)v.size();
    inv %= MOD;
    add(m[c[i].v], i);
    for (int j : v) {
      while (pq.size() > maxpq) pq.pop();
      pq.push((Event){ i, j, c[i].x + (c[i].v - c[j].v) / (c[j].x - c[i].x) * c[i].v, (c[i].v - c[j].v) / (c[j].x - c[i].x) });
    }
  }
  cout << inv << '\n';
  while (pq.size()) {
    Event e = pq.top(); pq.pop();
    ans.push(make_pair(e.i, e.j));
  }
  while (ans.size()) cout << ans.top().first << ' ' << ans.top().second << '\n', ans.pop();
  return 0;
}

vector<int> sum(int x) {
  vector<int> ret;
  while (x) merge(ret, BIT[x]), x -= lowbit(x);
  return ret;
}

void add(int x, int pos) {
  while (x <= N) BIT[x].push_back(pos), x += lowbit(x);
}

void merge(vector<int>& a, const vector<int>& b) {
  for (int i : b) a.push_back(i);
}
