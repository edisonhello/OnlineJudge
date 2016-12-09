ㄊㄧㄊㄧ#include <cstdio>
#include <algorithm>
#include <map>
#include <tuple>
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
  int st, ed, len;
  Node *l, *r;
  Node() {
    l = r = NULL;
  }
} *root[200005];

int N, Q, C, A[200005], type, P, K, X, Y, d, a, b;
map<int, int> mp;
tuple<int, int, int> query(Node*, int, int, int, int);
void modify(Node*&, int, int, int, int);
void pull(Node*, int, int);

int main() {
  rit(N, Q, C);
  for (int i = 0; i < N; ++i) {
    rit(A[i]);
    if (mp.find(A[i]) == mp.end()) mp[A[i]] = d++;
    if (!root[mp[A[i]]]) root[mp[A[i]]] = new Node();
    modify(root[mp[A[i]]], i, A[i], 0, N - 1);
  }
  while (Q--) {
    rit(type);
    if (type) {
      rit(X, Y, K); Y--;
      if (mp.find(K) == mp.end()) mp[K] = d++;
      printf("%d\n", get<2>(query(root[mp[K]], X, Y, 0, N - 1)));
    } else {
      rit(P, K);
      a = A[P]; b = K; A[P] = K;
      if (mp.find(b) == mp.end()) mp[b] = d++;
      if (mp.find(a) == mp.end()) mp[a] = d++;
      if (!root[mp[K]]) root[mp[K]] = new Node();
      if (!root[mp[a]]) root[mp[a]] = new Node();
      modify(root[mp[K]], P, K, 0, N - 1);
      modify(root[mp[a]], P, a, 0, N - 1);
    }
  }
  return 0;
}

tuple<int, int, int> query(Node* node, int qL, int qR, int L, int R) {
  if (!node && L >= qL && R <= qR) return make_tuple(R - L + 1, R - L + 1, R - L + 1);
  if (!node && L >= qL) return make_tuple(qR - L + 1, qR - L + 1, qR - L + 1);
  if (!node && R <= qR) return make_tuple(R - qL + 1, R - qL + 1, R - qL + 1);
  if (L >= qL && R <= qR && node) return make_tuple(node->st, node->ed, node->len);
  int M = (L + R) >> 1;
  tuple<int, int, int> q1, q2;
  if (!(M < qL || L > qR)) q1 = query(node->l, qL, qR, L, M);
  else q1 = make_tuple(0, 0, 0);
  if (!(M + 1 > qR || qL > R)) q2 = query(node->r, qL, qR, M + 1, R);
  else q2 = make_tuple(0, 0, 0);
  int st, ed, len;
  if (get<2>(q1) == M - L + 1) st = get<2>(q1) + get<0>(q2);
  else st = get<0>(q1);
  if (get<2>(q2) == R - M) ed = get<2>(q2) + get<1>(q1);
  else ed = get<1>(q2);
  len = max({ st, ed, get<2>(q1), get<2>(q2), get<1>(q1) + get<0>(q2) });
  return make_tuple(st, ed, len);
}

void modify(Node*& node, int P, int K, int L, int R) {
  if (L == R) {
    if (A[L] == K) {
      node->st = node->ed = node->len = 0;
      return;
    } else {
      node->st = node->ed = node->len = 1;
      return;
    }
  }
  int M = (L + R) >> 1;
  if (P <= M) {
    if (!node->l) node->l = new Node();
    modify(node->l, P, K, L, M);
  }
  if (P > M) {
    if (!node->r) node->r = new Node();
    modify(node->r, P, K, M + 1, R);
  }
  pull(node, L, R);
}

void pull(Node* node, int L, int R) {
  int M = (L + R) >> 1;
  if (node) {
    if (node->l && node->r) {
      if (node->l->len == M - L + 1) node->st = node->l->len + node->r->st;
      else node->st = node->l->st;
      if (node->r->len == R - M) node->ed = node->r->len + node->l->ed;
      else node->ed = node->r->ed;
    }
    else if (node->r) {
      node->st = node->r->st;
      node->ed = node->r->ed;
      node->len = node->r->len;
    } else if (node->l) {
      node->st = node->l->st;
      node->ed = node->l->ed;
      node->len = node->l->len;
    }
    node->len = max(node->st, node->ed);
    if (node->l) node->len = max(node->len, node->l->len);
    if (node->r) node->len = max(node->len, node->r->len);
    if (node->l && node->r) node->len = max(node->len, node->l->ed + node->r->st);
  }
}
