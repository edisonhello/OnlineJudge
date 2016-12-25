#include <iostream>
#include <algorithm>
using namespace std;

int R, C, N, t, P, Q, U, V;
long long K;

long long GCD(long long a, long long b) {
  if (!a) return b;
  if (!b) return a;
  return __gcd(a, b);
}

struct Node {
  long long gcd;
  int tag;
  Node *l, *r;
  Node(): gcd(-1LL), tag(-1), l(NULL), r(NULL) {}
  void insert(int L, int R, int Q, long long K) {
    if (L == R) { gcd = K; return; }
    int M = (L + R) >> 1;
    if (Q == tag) gcd = K;
    else if (~tag) {
      if (tag <= M) {
        if (!l) l = new Node();
        l->insert(L, M, tag, gcd);
      } else {
        if (!r) r = new Node();
        r->insert(M + 1, R, tag, gcd);
      }
      tag = -1;
    } else if (!~gcd) {
      tag = Q; gcd = K;
      return;
    }
    if (Q <= M) {
      if (!l) l = new Node();
      l->insert(L, M, Q, K);
    } else {
      if (!r) r = new Node();
      r->insert(M + 1, R, Q, K);
    }
    pull();
  }

  void pull() {
    long long L = l ? l->gcd : 0;
    long long R = r ? r->gcd : 0;
    gcd = __gcd(L, R);
  }

  long long query(int L, int R, int Q, int V) {
    if (L > V || Q > R) return 0;
    if (L >= Q && R <= V) return gcd;
    if (~tag) return Q <= tag && tag <= V ? gcd : 0;
    int M = (L + R) >> 1;
    long long res1 = l ? l->query(L, M, Q, V) : 0;
    long long res2 = r ? r->query(M + 1, R, Q, V) : 0;
    return __gcd(res1, res2);
  }
};

struct Seg {
  Node* node;
  Seg *l, *r;
  Seg(): node(NULL), l(NULL), r(NULL) {}
  void insert(int L, int R, int P, int Q, long long K) {
    if (L == R) {
      if (!node) node = new Node();
      node->insert(0, C - 1, Q, K);
      return;
    }
    int M = (L + R) >> 1;
    if (P <= M) {
      if (!l) l = new Seg();
      l->insert(L, M, P, Q, K);
    } else {
      if (!r) r = new Seg();
      r->insert(M + 1, R, P, Q, K);
    }
    pull(Q);
  }

  void pull(int Q) {
    if (!node) node = new Node();
    long long res1 = l && l->node ? l->node->query(0, C - 1, Q, Q) : 0;
    long long res2 = r && r->node ? r->node->query(0, C - 1, Q, Q) : 0;
    node->insert(0, C - 1, Q, __gcd(res1, res2));
  }

  long long query(int L, int R, int P, int Q, int U, int V) {
    if (L > U || P > R) return 0;
    if (L >= P && R <= U) return node ? node->query(0, C - 1, Q, V) : 0;
    int M = (L + R) >> 1;
    long long res1 = l ? l->query(L, M, P, Q, U, V) : 0;
    long long res2 = r ? r->query(M + 1, R, P, Q, U, V) : 0;
    return __gcd(res1, res2);
  }
} *seg;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> R >> C >> N;
  seg = new Seg();
  while (N--) {
    cin >> t;
    if (t == 1) {
      cin >> P >> Q >> K;
      seg->insert(0, R - 1, P, Q, K);
    } else {
      cin >> P >> Q >> U >> V;
      if (P > U) swap(P, U);
      if (Q > V) swap(Q, V);
      cout << seg->query(0, R - 1, P, Q, U, V) << '\n';
    }
  }
  return 0;
}
