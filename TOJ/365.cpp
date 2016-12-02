#include <iostream>
#include <algorithm>
using namespace std;

int N, h[100005], Q, c, P, H, L, R;

struct Node {
  int len, Llen, Rlen, Lh, Rh, L, R;
  Node *l, *r;
  Node(): l(NULL), r(NULL) {}
} *root;

void build(Node*&, int, int);
void pull(Node*);
int query(Node*, int, int);
void modify(Node*, int, int);
void debug(Node*);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N; for (int i = 1; i <= N; ++i) cin >> h[i];
  build(root, 1, N);
  debug(root);
  cin >> Q;
  while (Q--) {
    cin >> c;
    if (c == 1) {
      cin >> P >> H;
      modify(root, P, H);
      debug(root);
    } else {
      cin >> L >> R;
      cout << query(root, L, R) << endl;
    }
  }
  return 0;
}

void build(Node*& node, int L, int R) {
  node = new Node();
  node->L = L; node->R = R;
  if (L == R) {
    node->len = 1;
    node->Llen = 1; node->Rlen = 1;
    node->Lh = h[L]; node->Rh = h[L];
    return;
  }
  int M = (L + R) >> 1;
  build(node->l, L, M); build(node->r, M + 1, R);
  pull(node);
}

void pull(Node* node) {
  if (node) {
    if (node->l->Rh == node->r->Lh - 1) {
      node->len = max({ node->l->len, node->r->len, node->l->Rlen + node->r->Llen });
      node->Llen = node->l->Llen == (node->l->R - node->l->L + 1) ? node->l->Llen + node->r->Llen : node->l->Llen;
      node->Rlen = node->r->Rlen == (node->r->R - node->r->L + 1) ? node->r->Rlen + node->l->Rlen : node->r->Rlen;
      node->len = max({ node->Llen, node->Rlen, node->len });
    }
    else {
      node->len = max(node->l->len, node->r->len);
      node->Llen = node->l->Llen;
      node->Rlen = node->r->Rlen;
      node->len = max({ node->Llen, node->Rlen, node->len });
    }
    node->Lh = node->l->Lh; node->Rh = node->r->Rh;
  }
}

int query(Node* node, int ql, int qr) {
  cout << "L: " << node->L << " R: " << node->R << endl;
  if (node->L > qr || node->R < ql) return 0;
  if (node->L >= ql && node->R <= qr) return node->len;
  return max(query(node->l, ql ,qr), query(node->r, ql, qr));
}

void modify(Node* node, int pos, int hh) {
  if (node->L == node->R && node->L == pos) {
    node->len = 1;
    node->Llen = 1; node->Rlen = 1;
    node->Lh = hh; node->Rh = hh;
    return;
  }
  int M = (node->L + node->R) >> 1;
  if (pos <= M) modify(node->l, pos, hh);
  else modify(node->r, pos, hh);
  pull(node);
}

void debug(Node* node) {
  cout << "L: " << node->L << " R: " << node->R << endl;
  cout << "len: " << node->len << " Llen: " << node->Llen << " Rlen: " << node->Rlen << endl;
  cout << "Lh: " << node->Lh << " Rh: " << node->Rh << endl;
  cout << endl;
  if (node->l) debug(node->l);
  if (node->r) debug(node->r);
}
