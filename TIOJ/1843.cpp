#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

const int maxn = 20000 + 5;
const int maxq = 1000000 + 5;
const int maxm = 60000 + 5;
int T, N, M, D[maxn], u, v, a, b, q, djs[maxn], cnt, kase;
long long sum;
char c;
bool col[maxn];

struct Node {
  int val, pri, sz;
  Node *l, *r;
  Node(int v): val(v) {
    pri = rand();
    sz = 1;
    l = r = NULL;
  }
  inline int Lsz() { return l ? l->sz : 0; }
  inline int Rsz() { return r ? r->sz : 0; }
} *root[maxn];

struct Query {
  int a, b;
  char c;
} Q[maxq];

struct Edge {
  int st, ed;
} E[maxm];

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y;
}

void Connect(int);
Node* merge(Node*, Node*);
void pull(Node*);
void del(Node*, int);
void insert(Node*, int);
void split(Node*, int, Node*&, Node*&);
int kth(Node*, int);
void connect(Node*&, Node*&);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N >> M, (N || M)) {
    memset(col, false, sizeof(col)); q = 0;
    for (int i = 0; i < N; ++i) root[i] = NULL;
    for (int i = 0; i < N; ++i) djs[i] = i;
    for (int i = 0; i < N; ++i) cin >> D[i];
    for (int i = 0; i < M; ++i) cin >> u >> v, E[i] = (Edge){ u, v };
    while (cin >> c) {
      if (c == 'Q') cin >> a >> b;
      if (c == 'C') cin >> a >> b, swap(D[a], b);
      if (c == 'D') cin >> a, col[a] = true;
      if (c == 'E') break;
      Q[q++] = (Query){ a, b, c };
    }
    for (int i = 0; i < N; ++i) root[i] = new Node(D[i]);
    for (int i = 0; i < M; ++i) if (!col[i]) Connect(i);
    sum = 0; cnt = 0;
    while (q--) {
      if (Q[q].c == 'D') Connect(Q[q].a);
      if (Q[q].c == 'C') {
        del(root[F(Q[q].a)], D[a]);
        D[a] = Q[q].b;
        insert(root[F(Q[q].a)], D[a]);
      }
      if (Q[q].c == 'Q') cnt++, sum += kth(root[F(Q[q].a)], Q[q].b);
    }
    cout << "Sekai " << ++kase << ": " << fixed << setprecision(6) << (double)sum * 1.0 / cnt << '\n';
  }
  return 0;
}

void Connect(int id) {
  int x = F(E[id].st), y = F(E[id].ed);
  if (x == y) return;
  if (root[x] && root[y] && root[x]->sz < root[y]->sz) swap(x, y);
  connect(root[x], root[x]);
  U(y, x);
}

void connect(Node*& a, Node*& b) {
  if (b->l) connect(a, b->l);
  if (b->r) connect(a, b->r);
  insert(a, b->val);
}

Node* merge(Node* a, Node* b) {
  if (!a || !b) return a ? a : b;
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

void pull(Node* node) {
  if (!node) return;
  node->sz = node->Lsz() + node->Rsz() + 1;
}

void del(Node* node, int val) {
  Node *a, *b, *c, *d;
  split(node, val, a, b);
  split(a, val - 1, c, d);
  node = merge(c, b);
}

void split(Node* node, int v, Node*& a, Node*& b) {
  if (!node) { a = b = NULL; return; }
  if (node->val <= v) {
    a = node;
    split(node->r, v, a->r, b);
    pull(a);
  } else {
    b = node;
    split(node->l, v, a, b->l);
    pull(b);
  }
}

void insert(Node* node, int val) {
  Node *a, *b, *c;
  split(node, val, a, b);
  c = merge(a, new Node(val));
  node = merge(c, b);
}

int kth(Node* node, int k) {
  if (!node || k <= 0 || k > node->sz) return 0;
  if (node->Lsz() + 1 == k) return node->val;
  if (node->Lsz() + 1 > k) return kth(node->l, k);
  else return kth(node->r, k - node->Lsz() - 1);
}
