#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

struct Node {
  int front, back, len, L, R;
  bool con;
  Node *Lc, *Rc;
};

map<int, int> color;
int N, Q, C, A[200005], P, K, X, Y, t, cnt;
Node* root[40005];
void build(int, int, int, Node*);
int query(int, int, Node*);

int main() {
  rit(N, Q, C);
  for (int i = 0; i < N; ++i) rit(A[i]);
  // for (int i = 0; i < C; ++i) build(0, N - 1, i, root[i]);
  while (Q--) {
    rit(t);
    if (t) {
      rit(X, Y, K);
      if (color.find(K) == color.end()) {
        color[K] = cnt;
        build(0, N - 1, cnt, root[cnt]);
        cnt++;
      }
      printf("%d\n", query(X, Y, root[color[K]]));
    } else {
      rit(P, K);
      if (color.find(K) == color.end()) {
        color[K] = cnt;
        build(0, N - 1, cnt, root[cnt]);
        cnt++;
      }
      // modify()
    }
  }
}

void build(int L, int R, int c, Node* node) {
  printf("L: %d R: %d\n", L, R);
  node = new Node;
  if (L == R) {
    // printf("jizz\n");
    node->L = L; node->R = R;
    if (A[L] != c) node->front = 1, node->back = 1, node->len = 1, node->con = true;
    else node->front = 0, node->back = 0, node->len = 0, node->con = false;
    return;
  }
  node->L = L, node->R = R;
  int M = (L + R) >> 1;
  build(L, M, c, node->Lc); build(M + 1, R, c, node->Rc);
  if (node->Lc->con) node->front = node->Lc->back + node->Rc->front;
  else node->front = node->Lc->front;
  if (node->Rc->con) node->back = node->Rc->front + node->Lc->back;
  else node->back = node->Rc->back;
  node->len = max({ node->Lc->front, node->Rc->back, node->Lc->back + node->Rc->front });
  node->con = node->Lc->con && node->Rc->con;
}

int query(int L, int R, Node* node) {
  if (node->L > R || L > node->R) return 0;
  if (node->L >= L && node->R <= R) return node->len;
  return max({ query(L, R, node->Lc), query(L, R, node->Rc), node->Lc->back + node->Rc->front });
}
