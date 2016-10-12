#include <iostream>
using namespace std;

long long int a[100010], n, q, l, r, x, k, x1, x2, __t, __k;
long long int total;
char __c;

struct Node {
  long long int sum;
  bool leaf, tag;
  long long int xx;
  Node(): leaf(false), tag(false) {}
} node[400010];

int LC(int i) {return i * 2;}
int RC(int i) {return i * 2 + 1;}

void build(int L, int R, int i) {
  if (L == R) {node[i].sum = a[L], node[i].leaf = true; return;}
  int M = (L + R) / 2;
  build(L, M, LC(i));
  build(M + 1, R, RC(i));
  node[i].sum = node[LC(i)].sum + node[RC(i)].sum;
}

void query(int L, int R, int i) {
  if (node[i].leaf) {
    if (node[i].tag) node[i].sum ^= node[i].xx, node[i].tag = false;
    total += node[i].sum;
    return;
  }
  if (x1 <= L && x2 >= R && !node[i].tag) {
    total += node[i].sum;
    return;
  }
  int M = (L + R) / 2;
  if (x1 <= M) query(L, M, LC(i));
  if (x2 > M) query(M + 1, R, RC(i));
  node[i].tag = node[LC(i)].tag || node[RC(i)].tag;
}

void update(int L, int R, int i) {
  if (node[i].leaf && L >= x1 && R <= x2) {
    if (node[i].tag) {
      node[i].xx ^= x;
    } else {
      node[i].tag = true;
      node[i].xx = x;
    }
    return;
  }
  int M = (L + R) / 2;
  if (x1 <= M) update(L, M, LC(i));
  if (x2 > M) update(M + 1, R, RC(i));
  // node[i].sum = node[LC(i)].sum + node[RC(i)].sum;
  node[i].tag = node[LC(i)].tag || node[RC(i)].tag;
}

inline long long int rit(){
  __t = 0, __k = 1;
  do {
    __c = getchar();
    if (__c == '-') __k = -1;
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while(__c >= '0' && __c <= '9');
  return __t * __k;
}

int main() {
  n = rit();
  for (int i = 0; i < n; ++i) a[i] = rit();
  build(0, n - 1, 1);
  q = rit();
  for (int i = 0; i < q; ++i) {
    k = rit();
    if (k == 1) {
      l = rit(), r = rit();
      x1 = l - 1, x2 = r - 1;
      total = 0;
      query(0, n - 1, 1);
      printf("%lld\n", total);
    } else {
      l = rit(), r = rit(), x = rit();
      x1 = l - 1, x2 = r - 1;
      update(0, n - 1, 1);
    }
  }
  return 0;
}
