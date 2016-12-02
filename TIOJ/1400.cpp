#include <cstdio>
#include <cstdlib>
#include <ctime>
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
  Node(int v) {
    l = r = NULL;
    sz = 1; val = v; pri = rand();
  }
  inline int Lsz() { return l ? l->sz : 0; }
  inline int Rsz() { return r ? r->sz : 0; }
};

Node* root;
char cmd[100];
int x, k;
Node* merge(Node*, Node*);
void split(Node*, int, Node*&, Node*&);
void pull(Node*);
int kth(Node*, int);

int main() {
  srand(7122); k = 1;
  root = NULL;
  while (scanf("%s", cmd)) {
    if (cmd[0] == 'E' && cmd[1] == 'N') break;
    if (cmd[0] == 'P') {
      rit(x);
      Node *a, *b, *c;
      split(root, x, a, b);
      Node* n = new Node(x);
      c = merge(a, n);
      root = merge(c, b);
    }
    if (cmd[0] == 'G') {
      if (k < 1 || k > (root ? root->sz : 0)) continue;
      printf("%d\n", kth(root, k));
      k++;
    }
    if (cmd[0] == 'E') root = NULL, k = 1;
  }
  return 0;
}

Node* merge(Node* a, Node* b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->r = merge(a->r, b);
    pull(a);
    return a;
  }
  b->l = merge(a, b->l);
  pull(b);
  return b;
}

void split(Node* node, int k, Node*& a, Node*& b) {
  if (!node) { a = b = NULL; return; }
  if (node->val <= k) {
    a = node;
    split(node->r, k, a->r, b);
    pull(a);
    return;
  }
  b = node;
  split(node->l, k, a, b->l);
  pull(b);
  return;
}

void pull(Node* node) {
  if (node) node->sz = 1 + node->Lsz() + node->Rsz();
}

int kth(Node* node, int k) {
  if (node->Lsz() + 1 == k) return node->val;
  if (node->Lsz() + 1 > k) return kth(node->l, k);
  return kth(node->r, k - node->Lsz() - 1);
}
