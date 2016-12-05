#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

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

int N, Q, a[10005], pos[10005], L, R, v;

struct Node {
  int lim;
  Node* ch[2];
  Node() { ch[0] = ch[1] = NULL; }
  Node(Node* p) {
    if (!p) {
      lim = 0;
      ch[0] = ch[1] = NULL;
      return;
    }
    lim = p->lim;
    ch[0] = p->ch[0];
    ch[1] = p->ch[1];
  }
};

Node* root[10005];
Node* modify(Node*, int, int);
int query(Node*, int, int, int);

int main() {
  rit(N, Q); for (int i = 0; i < N; ++i) rit(a[i]);
  for (int i = N - 1; i >= 0; --i) pos[i] = pos[i + 1] ^ a[i];
  root[N] = new Node();
  for (int i = N - 1; i >= 0; --i) root[i] = modify(root[i + 1], i, 29);
  while (Q--) {
    rit(L, R, v);
    printf("%d\n", query(root[L], R, v ^ pos[R], 29));
  }
  return 0;
}

Node* modify(Node* node, int i, int depth) {
  if (depth < -1) return NULL;
  Node* tmp = new Node(node);
  tmp->lim = i;
  tmp->ch[(pos[i] & (1 << depth)) ? 1 : 0] = modify(tmp->ch[(pos[i] & (1 << depth)) ? 1 : 0], i, depth - 1);
  return tmp;
}

int query(Node* node, int r, int v, int depth) {
  if (depth < 0) return 0;
  if (node->ch[(v & (1 << depth)) ? 0 : 1] && node->ch[(v & (1 << depth)) ? 0 : 1]->lim < r) return (1 << depth) + query(node->ch[(v & (1 << depth)) ? 0 : 1], r, v, depth - 1);
  return query(node->ch[(v & (1 << depth)) ? 1 : 0], r, v, depth - 1);
}
