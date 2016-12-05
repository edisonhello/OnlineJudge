#include <iostream>
using namespace std;

struct Node {
  int cnt, L, R;
  Node *l, *r;
  Node() {
    cnt = 0;
    l = r = NULL;
  }
  Node(Node* ptr) {
    cnt = ptr->cnt;
    l = ptr->l; r = ptr->r;
    L = ptr->L; R = ptr->R;
  }
};

int T, N, Q, A[50005], L, R, K, C, V, X, type;
Node* BIT[50005];
Node* build(Node*, int, int, int);
void pull(Node*);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N >> Q; for (int i = 1; i <= N; ++i) cin >> A[i];
    BIT[0] = NULL;
    for (int i = 1; i <= N; ++i) BIT[i] = build(BIT[i - 1], i, , N);
    while (Q--) {
      cin >> type;
      if (type == 1) {
        cin >> L >> R >> K;

      }
      if (type == 2) {
        cin >> C >> V;
      }
      if (type == 3) {
        cin >> X >> V;
        cout << "7122\n";
      }
    }
  }
  return 0;
}

Node* build(Node* copy, int i, int L, int R) {
  Node* ret = new Node(copy); ret->L = L; ret->R = R;
  if (L == R) {
    ret->cnt = (L < i);
    ret->l = ret->r = NULL;
    return ret;
  }
  int M = (L + R) >> 1;
  ret->l = build(ret->l, i, L, M); ret->r = build(ret->r, i, M + 1, R);
  pull(ret);
  return ret;
}

void pull(Node* node) {
  node->cnt = 0;
  if (node->l) node->cnt += node->l->cnt;
  if (node->r) node->cnt += node->r->cnt;
}
