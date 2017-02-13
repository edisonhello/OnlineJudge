#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 20000 + 5;
struct Cow { int v, x; } c[maxn];
int N;
long long tot, ans;
pair<int, long long> BIT[maxn];

pair<int, long long> sum(int);
void add(int, int);

bool cmp(const Cow& a, const Cow& b) { return a.v == b.v ? a.x < b.x : a.v < b.v; }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  memset(BIT, 0, sizeof(BIT));
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> c[i].v >> c[i].x;
  sort(c, c + N, cmp);
  tot = 0; ans = 0;
  for (int i = 0; i < N; ++i) {
    pair<int, long long> le = sum(c[i].x - 1);
    pair<int, long long> gr = make_pair(i - le.first, tot - le.second);
    ans += c[i].v * (c[i].x * le.first - le.second) + c[i].v * (gr.second - c[i].x * gr.first);
    add(c[i].x, c[i].x);
    tot += c[i].x;
  }
  cout << ans << '\n';
}

pair<int, long long> sum(int x) {
  long long ret = 0;
  int cnt = 0;
  while (x) {
    cnt += BIT[x].first;
    ret += BIT[x].second;
    x -= lowbit(x);
  }
  return make_pair(cnt, ret);
}

void add(int x, int v) {
  while (x < maxn) {
    BIT[x].first++;
    BIT[x].second += v;
    x += lowbit(x);
  }
}
