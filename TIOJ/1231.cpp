#include <cstdio>
#include <algorithm>
#include <map>
#include <climits>
#define Lc(id) (id) << 1
#define Rc(id) (id) << 1 | 1
#define getchar gtx
using namespace std;

char __c;
bool flag;

inline int gtx() {
  const int N = 1048576;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 100000 + 5;

struct S {
  int w, t;
  bool operator<(const S& rhs) const {
    return t < rhs.t;
  }
} s[maxn];

int N, k, K, ans, seg[maxn << 2], Max, R;

bool cmp(const S&, const S&);
void build(int, int, int);
void pull(int);
int query(int, int, int, int, int);
void modify(int, int, int, int);

int main() {
  rit(N);
  for (int i = 1; i <= N; ++i) rit(s[i].w, s[i].t), Max = max(s[i].t, Max);
  rit(K);
  sort(s + 1, s + N + 1);
  s[N + 1].w = INT_MIN;
  s[N + 1].t = K + 1;
  build(1, 1, N);
  for (int i = min(Max, K); i > 0; --i) {
    int L = lower_bound(s + 1, s + N + 1, (S){ 0, i }, cmp) - s;
    if (L < 1 || L > N) { ans--; continue; }
    int q = query(1, 1, N, L, N);
    if (i < s[0].t) q = 1;
    if (i > s[N].t) { ans--; continue; }
    if (s[q].w == INT_MIN || s[q].w < -1) ans--;
    else ans += s[q].w, s[q].w = INT_MIN, modify(1, 1, N, q);
  }
  if (K > Max) ans -= (K - Max);
  printf("%d\n", ans);
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) { seg[id] = L; return; }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  if (s[seg[Lc(id)]].w > s[seg[Rc(id)]].w) seg[id] = seg[Lc(id)];
  else seg[id] = seg[Rc(id)];
}

bool cmp(const S& a, const S& b) {
  return a.t < b.t;
}

int query(int id, int L, int R, int l, int r) {
  if (L > r || l > R) return N + 1;
  if (L >= l && R <= r) return seg[id];
  int M = (L + R) >> 1;
  int q1 = query(Lc(id), L, M, l, r), q2 = query(Rc(id), M + 1, R, l, r);
  if (s[q1].w > s[q2].w) return q1;
  return q2;
}

void modify(int id, int L, int R, int x) {
  if (L == R) return;
  int M = (L + R) >> 1;
  if (x <= M) modify(Lc(id), L, M, x);
  else modify(Rc(id), M + 1, R, x);
  pull(id);
}
