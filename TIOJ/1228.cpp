#include <vector>
#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

int n, q, a, b, m, d, cnt, c;
int st[1000010], ed[1000010], w[1000010], bit[1000010], __t;
char __c;
bool flag;
vector<int> edge[1000010];
void dfs(int);
int query(int);
void modify(int, int);

inline int lowbit(int x) {return x & -x;}

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int main() {
  rit(n, q);
  for (int i = 0; i < n - 1; ++i) {
    rit(a, b, m);
    edge[a].push_back(b);
    w[b] = m;
  }
  cnt = 0;
  dfs(0);
  for (int i = n; i > 0; --i) bit[i] -= bit[i - lowbit(i)];
  while (q--) {
    rit(c);
    if (c) {
      rit(d);
      printf("%d\n", 2 * (query(ed[d]) - query(st[d] + 1)));
    } else {
      rit(d, m);
      modify(st[d] + 1, m - w[d]);
      w[d] = m;
    }
  }
}

void dfs(int start) {
  st[start] = cnt++;
  bit[cnt] = bit[cnt - 1] + w[start];
  for (int i = 0; i < edge[start].size(); ++i) dfs(edge[start][i]);
  ed[start] = cnt;
}

int query(int s) {
  int ret = 0;
  while (s) {
    ret += bit[s];
    s -= lowbit(s);
  }
  return ret;
}

void modify(int d, int w) {
  while (d <= cnt) {
    bit[d] += w;
    d += lowbit(d);
  }
}
