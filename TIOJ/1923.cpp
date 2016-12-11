#include <cstdio>
#include <algorithm>
#include <vector>
#define getchar getchar_unlocked
#define maxn (400000 + 5)
#define root 1
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

inline int Lc(int id) { return id << 1; }
inline int Rc(int id) { return (id << 1) + 1; }

struct Node {
  long long val, mn, tag;
} Seg[maxn << 2];

int m[maxn], d[maxn], N;
vector<long long> ans;
void build(int, int, int);
void pull(int);
void modify(int, int, int, int, int, long long);
void push(int);
void print(int, int, int);

int main() {
  rit(N);
  for (int i = 1; i <= N; ++i) rit(m[i], d[i]);
  build(root, 1, N);
  for (int i = 1; i <= N; ++i) {
    if (i - d[i] < 1) modify(root, 1, N, 1, i - 1, m[i]), modify(root, 1, N, i - d[i] + N, N, m[i]);
    else modify(root, 1, N, i - d[i], i - 1, m[i]);
    if (i + d[i] > N) modify(root, 1, N, i + 1, N, m[i]), modify(root, 1, N, 1, i + d[i] - N, m[i]);
    else modify(root, 1, N, i + 1, i + d[i], m[i]);
  }
  for (int _ = 0; _ < N; ++_) {
    push(root);
    int Min = Seg[root].mn;
    if (Min - d[Min] < 1) modify(root, 1, N, 1, Min - 1, -m[Min]), modify(root, 1, N, Min - d[Min] + N, N, -m[Min]);
    else modify(root, 1, N, Min - d[Min], Min - 1, -m[Min]);
    if (Min + d[Min] > N) modify(root, 1, N, Min + 1, N, -m[Min]), modify(root, 1, N, 1, Min + d[Min] - N, -m[Min]);
    else modify(root, 1, N, Min + 1, Min + d[Min], -m[Min]);
    modify(root, 1, N, Min, Min, (long long)1e9 * N + 1);
    ans.push_back(Min);
  }
  reverse(ans.begin(), ans.end());
  for (int i : ans) printf("%d ", i);
  return 0;
}

void build(int id, int L, int R) {
  if (L == R) { Seg[id].val = 0; Seg[id].mn = L; return; }
  int M = (L + R) >> 1;
  build(Lc(id), L, M);
  build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  Seg[id].val = min(Seg[Lc(id)].val, Seg[Rc(id)].val);
  Seg[id].mn = Seg[Lc(id)].val < Seg[Rc(id)].val ? Seg[Lc(id)].mn : Seg[Rc(id)].mn;
}

void modify(int id, int L, int R, int l, int r, long long v) {
  if (l > r) return;
  if (L == l && R == r) { Seg[id].val += v; Seg[id].tag += v; return; }
  push(id);
  int M = (L + R) >> 1;
  if (r <= M) modify(Lc(id), L, M, l, r, v);
  else if (l > M) modify(Rc(id), M + 1, R, l, r, v);
  else modify(Lc(id), L, M, l, M, v), modify(Rc(id), M + 1, R, M + 1, r, v);
  pull(id);
}

void push(int id) {
  if (!Seg[id].tag) return;
  Seg[Lc(id)].val += Seg[id].tag; Seg[Lc(id)].tag += Seg[id].tag;
  Seg[Rc(id)].val += Seg[id].tag; Seg[Rc(id)].tag += Seg[id].tag;
  Seg[id].tag = 0;
}
