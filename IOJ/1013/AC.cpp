#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
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

struct Node {
  int val, pri, sz;
  Node *l, *r;
  bool tag;
  Node(int v) {
    val = v; pri = rand(); sz = 1;
    l = r = NULL;
    tag = false;
  }
  inline int Lsz() { return l ? l->sz : 0; }
  inline int Rsz() { return r ? r->sz : 0; }
} *root;

int N, M, L, R, L1, R1, L2, R2, c;
Node* merge(Node*, Node*);
void split(Node*, int, Node*&, Node*&);
void pull(Node*);
void push(Node*);
void print(Node*);

int main() {
  // rit(N, M);
  freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    root = merge(root, new Node(i));
  }
  while (M--) {
    // rit(c);
    cin >> c;
    if (c == 1) {
      // rit(L, R);
      cin >> L >> R;
      Node *a, *b, *c, *d;
      split(root, L - 1, a, b);
      split(b, R - L + 1, c, d);
      c->tag = !c->tag;
      Node *e = merge(c, d);
      root = merge(a, e);
    }
    if (c == 2) {
      // rit(L1, R1, L2, R2);
      cin >> L1 >> R1 >> L2 >> R2;
      Node *a, *b, *c, *d, *e, *f, *g, *h;
      split(root, L1 - 1, a, b);
      split(b, R1 - L1 + 1, c, d); //c = L1 - R1
      split(d, L2 - R1 - 1, e, f);
      split(f, R2 - L2 + 1, g, h); //g = L2 - R2
      Node *i = merge(c, h);
      Node *j = merge(e, i);
      Node *k = merge(a, g);
      root = merge(k, j);
    }
  }
  print(root);
}

Node* merge(Node* a, Node* b) {
  if (!a || !b) return a ? a : b;
  push(a); push(b);
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    pull(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    pull(b);
    return b;
  }
}

void split(Node* node, int k, Node*& a, Node*& b) {
  if (!node) { a = b = NULL; return; }
  push(node);
  if (node->Lsz() < k) {
    a = node;
    split(node->r, k - node->Lsz() - 1, a->r, b);
    pull(a);
    return;
  } else {
    b = node;
    split(node->l, k, a, b->l);
    pull(b);
    return;
  }
}

void pull(Node* node) {
  if (node) node->sz = node->Lsz() + node->Rsz() + 1;
}

void push(Node* node) {
  if (node->tag) {
    if (node->l) node->l->tag = !node->l->tag;
    if (node->r) node->r->tag = !node->r->tag;
    swap(node->l, node->r);
    node->tag = false;
  }
}

void print(Node* node) {
  push(node);
  if (node->l) print(node->l);
  // printf("%d ", node->val);
  cout << node->val << ' ';
  if (node->r) print(node->r);
}
