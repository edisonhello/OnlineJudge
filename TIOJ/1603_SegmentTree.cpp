#include <cstdio>
#include <algorithm>
#include <utility>
#define getchar getchar_unlocked
#define INF (long long)(1 << 30)
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
  long long mx, mn;
  int L, R;
  Node *Lc, *Rc;
  Node(): Lc(NULL), Rc(NULL) {}
};

int n, m, i, j;
long long H[100005];
Node* root;
pair<long long, long long> p;
void build(int, int, Node*&);
pair<long long, long long> query(int, int, Node*);

int main() {
  rit(n, m);
  for (int i = 1; i <= n; ++i) rit(H[i]);
  build(1, n, root);
  while (m--) {
    rit(i, j);
    p = query(i, j, root);
    printf("%lld\n", p.first - p.second);
  }
  return 0;
}

void build(int L, int R, Node* &node) {
  // printf("L: %d R: %d\n", L, R);
  node = new Node();
  node->L = L, node->R = R;
  if (L == R) { node->mx = H[L]; node->mn = H[L]; return; }
  build(L, (L + R) >> 1, node->Lc); build(((L + R) >> 1) + 1, R, node->Rc);
  node->mx = max(node->Lc->mx, node->Rc->mx);
  node->mn = min(node->Lc->mn, node->Rc->mn);
}

pair<long long, long long> query(int L, int R, Node* node) {
  if (node->L > R || node->R < L) return { 0, INF };
  if (node->L >= L && node->R <= R) return { node->mx, node->mn };
  auto q1 = query(L, R, node->Lc), q2 = query(L, R, node->Rc);
  return { max(q1.first, q2.first), min(q1.second, q2.second) };
}
