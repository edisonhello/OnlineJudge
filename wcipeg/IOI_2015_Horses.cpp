#include <bits/stdc++.h>
using namespace std;

struct Node {
  long long Lsz, Rsz;
  int best;
  bool Lmod, Rmod;
  Node *l, *r;
  Node() {
    Lsz = Rsz = 0;
    Lmod = Rmod = 0;
    l = r = NULL;
  };
} *root;

long long mod(long long, bool&);
const int MOD = 1e9 + 7;
int T, N, M, K, P, V;
long long X[500005], Y[500005];
void build(Node*&, int, int);
void pull(Node*);
void modify(Node*, int, int, int);
void del(Node*);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> X[i];
  for (int i = 0; i < N; ++i) cin >> Y[i];
  root = NULL;
  build(root, 0, N - 1);
  cout << root->Lsz * Y[root->best] % MOD << '\n';
  cin >> M;
  while (M--) {
    cin >> K >> P >> V;
    if (K == 1) X[P] = V;
    else Y[P] = V;
    modify(root, 0, N - 1, P);
    cout << root->Lsz * Y[root->best] % MOD << '\n';
  }
  del(root);
  return 0;
}

long long mod(long long a, bool& m) {
  if (a >= MOD) m = true;
  return a % MOD;
}

void build(Node*& node, int L, int R) {
  node = new Node();
  if (L == R) {
    node->Lsz = X[L];
    node->Rsz = 1;
    node->best = L;
    return;
  }
  int M = (L + R) >> 1;
  build(node->l, L, M);
  build(node->r, M + 1, R);
  pull(node);
}

void pull(Node* node) {
  Node *l, *r;
  if (node->l) l = node->l;
  else l->best = l->Lsz = l->Rsz = 0;
  if (node->r) r = node->r;
  else r->best = r->Lsz = r->Rsz = 0;
  node->Lmod = node->Rmod = false;
  bool md = l->Rmod || r->Lmod;
  int Msz = mod(l->Rsz * r->Lsz, md);
  if (l->Rmod || r->Lmod || md || Y[l->best] < Msz * Y[r->best]) {
    node->best = r->best;
    node->Lsz = mod(l->Lsz * Msz, node->Lmod);
    node->Lmod |= l->Lmod || md;
    node->Rsz = r->Rsz;
    node->Rmod = r->Rmod;
  } else {
    node->best = l->best;
    node->Rsz = mod(r->Rsz * Msz, node->Rmod);
    node->Rmod |= r->Rmod || md;
    node->Lsz = l->Lsz;
    node->Lmod = l->Lmod;
  }
}

void modify(Node* node, int L, int R, int P) {
  if (P < L || P > R) return;
  if (L == R) {
    node->Lsz = X[L];
    return;
  }
  int M = (L + R) >> 1;
  modify(node->l, L, M, P);
  modify(node->r, M + 1, R, P);
  pull(node);
}

void del(Node* node) {
  if (!node->l && !node->r) {
    delete node;
    return;
  }
  del(node->l); del(node->r);
  delete node;
}
