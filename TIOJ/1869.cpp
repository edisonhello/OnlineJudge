#include <iostream>
using namespace std;

struct Node {
  int sum, L, R;
  Node *Lc, *Rc;
  Node(): Lc(NULL), Rc(NULL) {}
};

struct Seg {
  Node* root;
  Seg *Lc, *Rc;
  int L, R;
  Seg(): Lc(NULL), Rc(NULL) {}
};

Seg* root;
void build(Seg*&, int, int);
void buildNode(Node*&, int, int);
void modify(Seg*, int, int, int);
void modifyNode(Node*, int, int);
int query(Seg*, int, int, int, int);
int queryNode(Node*, int, int);
int n, c, x, y, z, x1, x2, y1, y2;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  build(root, 0, n - 1);
  while (cin >> c) {
    if (c == 1) {
      cin >> x >> y >> z;
      modify(root, x, y, z);
    } else {
      cin >> x1 >> y1 >> x2 >> y2;
      cout << query(root, x1, y1, x2, y2) << endl;
    }
  }
  return 0;
}

void build(Seg* &seg, int L, int R) {
  seg = new Seg();
  seg->L = L; seg->R = R;
  if (L == R) {
    buildNode(seg->root, 0, n - 1);
    return;
  }
  int M = (L + R) >> 1;
  build(seg->Lc, L, M); build(seg->Rc, M + 1, R);
}

void buildNode(Node* &node, int L, int R) {
  node = new Node();
  node->L = L; node->R = R;
  if (L == R) {
    node->sum = 0;
    return;
  }
  int M = (L + R) >> 1;
  buildNode(node->Lc, L, M); buildNode(node->Rc, M + 1, R);
  node->sum = node->Lc->sum + node->Rc->sum;
}

void modify(Seg* seg, int x, int y, int z) {
  // cout << seg->L << ' ' << seg->R << endl;
  if (seg->L == seg->R) { modifyNode(seg->root, y, z); return; }
  int M = (seg->L + seg->R) >> 1;
  if (x < M) modify(seg->Lc, x, y, z);
  else modify(seg->Rc, x, y, z);
}

void modifyNode(Node* node, int y, int z) {
  if (node->L == node->R) { node->sum += z; return; }
  int M = (node->L + node->R) >> 1;
  if (y < M) modifyNode(node->Lc, y, z);
  else modifyNode(node->Rc, y, z);
  node->sum = node->Lc->sum + node->Rc->sum;
}

int query(Seg* seg, int x1, int y1, int x2, int y2) {
  // cout << seg->L << ' ' << seg->R << endl;
  if (seg->L > x2 || seg->R < x1) return 0;
  if (seg->L >= x1 && seg->R <= x2) return queryNode(seg->root, y1, y2);
  return query(seg->Lc, x1, y1, x2, y2) + query(seg->Rc, x1, y1, x2, y2);
}

int queryNode(Node* node, int y1, int y2) {
  if (node->L > y2 || node->R < y1) return 0;
  if (node->L >= y1 && node->R <= y2) return node->sum;
  return queryNode(node->Lc, y1, y2) + queryNode(node->Rc, y1, y2);
}
