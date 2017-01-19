#include <bits/stdc++.h>
#define bit(x, dep) (x & (1 << dep) ? 1 : 0)
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

struct Trie {
  Trie *ch[2];
  int cnt;
  Trie(): cnt(0) {
    ch[0] = NULL;
    ch[1] = NULL;
  }
  void insert(int x, int dep) {
    if (dep < 0) return;
    if (!ch[bit(x, dep)]) ch[bit(x, dep)] = new Trie();
    ch[bit(x, dep)]->cnt++;
    ch[bit(x, dep)]->insert(x, dep - 1);
  }
  int query(int x, int dep) {
    if (dep < 0) return 0;
    if (ch[!bit(x, dep)] && ch[!bit(x, dep)]->cnt) return (1 << dep) + ch[!bit(x, dep)]->query(x, dep - 1);
    if (ch[bit(x, dep)] && ch[bit(x, dep)]->cnt) return ch[bit(x, dep)]->query(x, dep - 1);
    return 0;
  }
  void remove(int x, int dep) {
    if (dep < 0) return;
    ch[bit(x, dep)]->cnt--;
    ch[bit(x, dep)]->remove(x, dep - 1);
    if (ch[bit(x, dep)]->cnt == 0) delete ch[bit(x, dep)], ch[bit(x, dep)] = NULL;
  }
} *root;

const int maxn = 100000 + 5;
int T, N, A[maxn], u, v, Max[maxn];
vector<int> G[maxn];

void DFS(int, int, int, int);
void clear(Trie*&);

int main() {
  rit(T);
  while (T--) {
    rit(N);
    clear(root);
    root = new Trie();
    root->insert(0, 30);
    for (int i = 1; i <= N; ++i) G[i].clear();
    for (int i = 1; i <= N; ++i) rit(A[i]);
    for (int i = 0; i < N - 1; ++i) {
      rit(u, v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    DFS(1, 0, 0, 0);
    for (int i = 1; i <= N; ++i) printf("%d\n", Max[i]);
  }
  return 0;
}

void DFS(int x, int fa, int Xor, int mx) {
  Max[x] = max(mx, root->query(Xor ^ A[x], 30));
  root->insert(Xor ^ A[x], 30);
  for (int u : G[x]) if (u != fa) {
    DFS(u, x, Xor ^ A[x], Max[x]);
  }
  root->remove(Xor ^ A[x], 30);
}

void clear(Trie*& t) {
  if (!t) return;
  clear(t->ch[0]);
  clear(t->ch[1]);
  delete t;
}
