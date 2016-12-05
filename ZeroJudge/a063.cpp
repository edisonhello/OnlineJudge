#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int N, M, L, R;

struct Node {
  int key, val, sz;
  bool tag;
  Node *l, *r;
  Node(int k): l(NULL), r(NULL) {
      val = rand();
      key = k;
      sz = 1;
  }
  inline int Lsz() { return l ? l->sz : 0; }
  inline int Rsz() { return r ? r->sz : 0; }
};

Node* root;
Node* merge(Node*, Node*);
void push(Node*);
void split(Node*, int, Node*&, Node*&);
void pull(Node*);
void ans(Node*);

int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  root = new Node(1);
  for (int i = 2; i <= N; ++i) {
    Node* node = new Node(i);
    root = merge(root, node);
  }
  while (M--) {
    cin >> L >> R;
    Node *n1, *n2, *n3, *n4;
    split(root, L - 1, n1, n2);
    split(n2, R - L + 1, n3, n4);
    n3->tag ^= 1;
    Node* n5 = merge(n3, n4);
    root = merge(n1, n5);
      // ans(root);
  }
  ans(root);
  return 0;
}

Node* merge(Node* a, Node* b) {
  if (!a) return b;
  if (!b) return a;
  push(a); push(b);
  if (a->val > b->val) {
      a->r = merge(a->r, b);
      pull(a);
      return a;
  }
  b->l = merge(a, b->l);
  pull(b);
  return b;
}

void push(Node* node) {
  if (node->tag) {
    if (node->l) node->l->tag ^= 1;
    if (node->r) node->r->tag ^= 1;
    swap(node->l, node->r);
    node->tag = 0;
  }
}

void split(Node* node, int k, Node*& a, Node*& b) {
  if (!node) { a = b = NULL; return; }
  push(node);
  if (node->Lsz() < k) {
    a = node;
    split(node->r, k - node->Lsz() - 1, a->r, b);
    pull(a);
  } else {
    b = node;
    split(node->l, k, a, b->l);
    pull(b);
  }
}

void pull(Node* node) {
  node->sz = 1;
  node->sz += node->Lsz() + node->Rsz();
}

void ans(Node* node) {
  push(node);
  if (node->l) ans(node->l);
  cout << node->key << ' ';
  if (node->r) ans(node->r);
}
