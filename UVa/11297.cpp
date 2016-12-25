#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

struct Node {
  int Max, Min;
  Node *l, *r;
  Node(): l(NULL), r(NULL) {
    Max = 0;
    Min = INT_MAX;
  }
};

struct Seg {
  Node* root;
  Seg *l, *r;
  Seg(): l(NULL), r(NULL), root(NULL) {}
} *root;

const int maxn = 500 + 5;
int N, A[maxn][maxn], Q, x1, y1, x2, y2, x, y, v;
char c;
void pullX(Node*);
void pullY(Node*&, Node*, Node*);
void buildY(Seg*&, int, int);
void buildX(Node*&, int, int, int);
pair<int, int> queryY(Seg*, int, int, int, int, int, int);
pair<int, int> queryX(Node*, int, int, int, int);
void modifyY(Seg*, int, int, int, int, int);
void modifyX(Node*, int, int, int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) cin >> A[i][j];
  buildY(root, 1, N);
  cin >> Q;
  while (Q--) {
    cin >> c;
    if (c == 'q') {
      cin >> y1 >> x1 >> y2 >> x2;
      pair<int, int> res = queryY(root, 1, N, y1, y2, x1, x2);
      cout << res.first << ' ' << res.second << '\n';
    }
    if (c == 'c') {
      cin >> y >> x >> v;
      modifyY(root, 1, N, y, x, v);
    }
  }
  return 0;
}

void buildY(Seg*& seg, int L, int R) {
  seg = new Seg();
  if (L == R) { buildX(seg->root, 1, N, L); return; }
  int M = (L + R) >> 1;
  buildY(seg->l, L, M);
  buildY(seg->r, M + 1, R);
  pullY(seg->root, seg->l->root, seg->r->root);
}

void pullY(Node*& node, Node* a, Node* b) {
  node = new Node();
  node->Max = max(a->Max, b->Max);
  node->Min = min(a->Min, b->Min);
  if (a->l && b->l) pullY(node->l, a->l, b->l);
  if (a->r && b->r) pullY(node->r, a->r, b->r);
}

void buildX(Node*& node, int L, int R, int Y) {
  if (!node) node = new Node();
  if (L == R) { node->Max = node->Min = A[Y][L]; return; }
  int M = (L + R) >> 1;
  buildX(node->l, L, M, Y);
  buildX(node->r, M + 1, R, Y);
  pullX(node);
}

void pullX(Node* node) {
  if (!node->l) {
    node->Max = node->r->Max;
    node->Min = node->r->Min;
    return;
  }
  if (!node->r) {
    node->Max = node->l->Max;
    node->Min = node->l->Min;
    return;
  }
  node->Max = max(node->l->Max, node->r->Max);
  node->Min = min(node->l->Min, node->r->Min);
}

pair<int, int> queryY(Seg* seg, int L, int R, int y1, int y2, int x1, int x2) {
  if (L > y2 || y1 > R) return make_pair(0, INT_MAX);
  if (L >= y1 && R <= y2) return queryX(seg->root, 1, N, x1, x2);
  int M = (L + R) >> 1;
  pair<int, int> res1, res2;
  res1 = queryY(seg->l, L, M, y1, y2, x1, x2);
  res2 = queryY(seg->r, M + 1, R, y1, y2, x1, x2);
  return make_pair(max(res1.first, res2.first), min(res1.second, res2.second));
}

pair<int, int> queryX(Node* node, int L, int R, int x1, int x2) {
  if (L > x2 || x1 > R) return make_pair(0, INT_MAX);
  if (L >= x1 && R <= x2) return make_pair(node->Max, node->Min);
  int M = (L + R) >> 1;
  pair<int, int> res1, res2;
  res1 = queryX(node->l, L, M, x1, x2);
  res2 = queryX(node->r, M + 1, R, x1, x2);
  return make_pair(max(res1.first, res2.first), min(res1.second, res2.second));
}

void modifyY(Seg* seg, int L, int R, int y, int x, int v) {
  if (L == R) { modifyX(seg->root, 1, N, x, v); return; }
  int M = (L + R) >> 1;
  if (y <= M) modifyY(seg->l, L, M, y, x, v);
  else modifyY(seg->r, M + 1, R, y, x, v);
  pullY(seg->root, seg->l->root, seg->r->root);
}

void modifyX(Node* node, int L, int R, int x, int v) {
  if (L == R) { node->Min = node->Max = v; return; }
  int M = (L + R) >> 1;
  if (x <= M) modifyX(node->l, L, M, x, v);
  else modifyX(node->r, M + 1, R, x, v);
  pullX(node);
}
