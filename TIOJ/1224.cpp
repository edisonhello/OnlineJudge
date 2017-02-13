#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

const int maxn = 100000 + 5, maxseg = 1000000 + 5;

struct Event {
  int x, L, R, type;
  bool operator<(const Event& e) const {
    return x < e.x;
  }
};

struct Seg {
  int sum, tag;
} seg[maxseg << 2];

int N, l, r, d, u, pos, len;
long long ans;
vector<Event> e;

int query(int, int, int, int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> l >> r >> u >> d;
    --d;
    e.push_back((Event){ l, u, d, 1 });
    e.push_back((Event){ r, u, d, -1 });
  }
  sort(e.begin(), e.end());
  for (auto i : e) {
    ans += (long long)(i.x - pos) * (long long)len;
    pos = i.x;
    len = query(1, 0, maxseg - 1, i.L, i.R, i.type);
  }
  cout << ans << '\n';
  return 0;
}

int query(int id, int L, int R, int l, int r, int v) {
  if (L > r || l > R) return seg[id].tag > 0 ? R - L + 1 : seg[id].sum;
  if (L >= l && R <= r) return (seg[id].tag += v) > 0 ? R - L + 1 : seg[id].sum;
  int M = (L + R) >> 1;
  seg[id].sum = query(Lc(id), L, M, l, r, v) + query(Rc(id), M + 1, R, l, r, v);
  return seg[id].tag ? R - L + 1 : seg[id].sum;
}
