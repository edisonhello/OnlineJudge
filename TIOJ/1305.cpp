#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Node {
  int val, pri, sz;
  Node *l, *r;
  Node(int v) {
    l = r = NULL;
    pri = rand();
    val = v; sz = 1;
  }
  inline int Lsz() { return l ? l->sz : 0; }
  inline int Rsz() { return r ? r->sz : 0; }
};

string cmd;
int x;
Node* root;
Node* merge(Node*, Node*);
void split(Node*, int, Node*&, Node*&);
void pull(Node*);
int kth(Node*, int);

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  srand(7122); root = NULL;
  while (cin >> cmd, cmd != "exit") {
    if (cmd[0] == 'i') {
      cin >> x;
      Node *a, *b, *c, *d;
      split(root, x, a, b);
      split(a, x - 1, c, d);
      if (d) {
        a = merge(c, d);
        root = merge(a, b);
      } else {
        Node* node = new Node(x);
        Node* m = merge(c, node);
        root = merge(m, b);
      }
    }
    if (cmd[0] == 'a') {
      cin >> x;
      if (x < 1 || x > (root ? root->sz : 0)) { cout << "error\n"; continue; }
      cout << kth(root, x) << '\n';
    }
    if (cmd[0] == 'r') {
      cin >> x;
      Node *a, *b, *c, *d;
      split(root, x, a, b);
      split(a, x - 1, c, d);
      root = merge(c, b);
    }
  }
  return 0;
}

Node* merge(Node* a, Node* b) {
  if (!a) return b;
  if (!b) return a;
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
  } else {
    b = node;
    split(node->l, k, a, b->l);
    pull(b);
  }
}

void pull(Node* node) {
  if (node) node->sz = node->Lsz() + node->Rsz() + 1;
}

int kth(Node* node, int k) {
  if (node->Lsz() + 1 == k) return node->val;
  if (node->Lsz() + 1 > k) return kth(node->l, k);
  else return kth(node->r, k - node->Lsz() - 1);
}
