#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <tuple>
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

struct Node {
  int s, val;
  Node *l, *r;
  Node(int v): val(v), l(NULL), r(NULL) {
    s = 1;
  }
  inline int lS() { return l ? l->s : 0; }
  inline int rS() { return r ? r->s : 0; }
};

const int MAX = 100000 + 5;
vector<int> tree[MAX];
long long C[MAX], L[MAX], N, M, B, root, tot, Max, sz;
Node* merge(Node*, Node*);
tuple<long long, long long, Node*> DFS(int);
bitset<MAX> v;

int main() {
  rit(N, M);
  for (int i = 1; i <= N; ++i) {
    rit(B, C[i], L[i]);
    if (B) tree[B].push_back(i);
    else root = i;
  }
  tuple<long long, long long, Node*> ans = DFS(root);
  Node* leftist = get<2>(ans);
  tot = get<0>(ans);
  sz = get<1>(ans);
  while (tot > M) {
    tot -= leftist->val;
    Node *t = merge(leftist->l, leftist->r);
    delete leftist;
    leftist = t;
    sz--;
  }
  Max = max(Max, L[root] * sz);
  printf("%lld\n", Max);
  return 0;
}

Node* merge(Node* a, Node* b) {
  if (!a || !b) return a ? a : b;
  if (a->val < b->val) swap(a, b);
  a->r = merge(a->r, b);
  if (a->lS() < a->rS()) swap(a->l, a->r);
  a->s = a->rS() + 1;
  return a;
}

tuple<long long, long long, Node*> DFS(int x) {
  v[x] = true;
  Node* node = new Node(C[x]);
  long long cur = C[x], sz = 1;
  for (int u : tree[x]) {
    if (!v[u]) {
      tuple<long long, long long, Node*> res = DFS(u);
      node = merge(node, get<2>(res));
      cur += get<0>(res);
      sz += get<1>(res);
    }
  }
  v[x] = false;
  while (cur > M) {
    cur -= node->val;
    Node *t = merge(node->l, node->r);
    delete node;
    node = t;
    sz--;
  }
  Max = max(Max, L[x] * sz);
  return make_tuple(cur, sz, node);
}
