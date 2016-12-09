#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
  int Sum, add, set, Min, Max;
  Node *l, *r;
  Node() {
    l = r = NULL;
  }
} *root[25];

const int INF = INT_MAX;
int r, c, m, type, x1, y1, x2, y2, v;
void add(Node*, int, int, int, int, int);
void build(Node*, int, int);
void pull(Node*);
void push(Node*);

int main() {
  while (cin >> r >> c >> m) {
    for (int i = 0; i < 25; ++i) root[i] = NULL;
    for (int i = 0; i < 25; ++i) build(root[i], 1, c);
    while (m--) {
      cin >> type;
      if (type == 1) {
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        for (int i = y1; i <= y2; ++i) add(root[i], 1, c, x1, x2, v);
      }
    }
  }
}

void build(Node*& node, int L, int R) {
  node = new Node();
  if (L == R) {
    node->Sum = node->Max = 0;
    node->Min = INF;
  }
  int M = (L + R) >> 1;
  build(node->l, L, M);
  build(node->r, M + 1, R);
  pull(node);
}

void pull(Node* node) {
  if (node) {
    node->Sum = node->l->Sum + node->r->Sum;
    node->Min = min(node->l->Min, node->r->Sum);
    node->Max = max(node->l->max, node->r->Max);
  }
}

void add(Node* node, int L, int R, int x1, int x2, int v) {
  if (L > x2 || x1 > R) return;
  if (L >= x1 && R <= x2) {
    node->add = v;
    return;
  }
  push(node);
  int M = (L + R) >> 1;
  add(node->l, L, M, x1, x2, v);
  add(node->r, M + 1, R, x1, x2, v);
  pull(node);
}

void push(Node* node) {
  if (node) {
    node->
  }
}
