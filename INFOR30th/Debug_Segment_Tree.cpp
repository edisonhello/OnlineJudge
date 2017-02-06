#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;

struct Node {
  Node *l, *r;
  int val;
  Node() {
    l = r = NULL;
  }
} *root;

int A[maxn], N;

void build(Node*, int, int);
void pull(Node*);

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> A[i];
  build(root, 0, N - 1);
  return 0;
}

void build(Node* t, int L, int R) {
  t = new Node();
  if (L == R) { t->val = A[L]; return; }
  int M = L + R >> 1;
  build(t->l, L, M);
  build(t->r, M + 1, R);
  pull(t);
}

void pull(Node* t) {
  t->val = t->l->val + t->r->val;
}
