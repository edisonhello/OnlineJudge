#include <cstdio>
using namespace std;

struct Node {
    int num, sm;
    int x;
};

int n, q, a[100010], c, l, r, x;
Node seg[400010];
void build(int, int, int);
int query(int, int, int, int, int);
void modify(int, int, int, int, int, int);
void push(int);
void pull(int);

inline int L(int id) {return id *2;}
inline int R(int id) {return id * 2 + 1;}

inline int readchar() {
  const int N = 1048576;
  static char buf[N];
  static char *p = buf, *end = buf;
  if(p == end) {
    if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
    p = buf;
  }
  return *p++;
}

template<typename T>
inline bool gin(T &x){
  char c = 0; bool flag = 0;
  while (c = readchar(), c < '0' && c != '-' || c > '9') if (c == -1) return false;
  c == '-' ? (flag = 1, x = 0):(x = c - '0');
  while (c = readchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool gin(T &x, Args &...args){
  return gin(x) && gin(args...);
}

int main() {
  gin(n);
  for (int i = 0; i < n; ++i) gin(a[i]);
  build(0, n - 1, 1);
  gin(q);
  while (q--) {
    gin(c);
    if (c == 1) {
      gin(l, r);
      printf("%d\n", query(0, n - 1, l - 1, r - 1, 1));
            //cout << query(0, n - 1, l - 1, r - 1, 1) << endl;
    } else {
      gin(l, r, x);
      modify(0, n - 1, l - 1, r - 1, 1, x);
    }
  }
}

void build(int l, int r, int id) {
  if (l == r) {
    seg[id].num = a[l];
    seg[id].sm = seg[id].num;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, L(id)), build(m + 1, r, R(id));
  seg[id].sm = seg[L(id)].sm + seg[R(id)].sm;
}

int query(int l, int r, int ql, int qr, int id) {
  if (ql > r || qr < l) return 0;
  if (l == r) {
    seg[id].num ^= seg[id].x;
    seg[id].sm = seg[id].num;
    seg[id].x = 0;
    return seg[id].sm;
  }
  push(id);
  int m = (l + r) / 2;
  int t1 = query(l, m, ql, qr, L(id)), t2 = query(m + 1, r, ql, qr, R(id));
  pull(id);
  return t1 + t2;
}

void push(int id) {
  if (seg[id].x) {
    seg[L(id)].x ^= seg[id].x;
    seg[R(id)].x ^= seg[id].x;
    seg[id].x = 0;
  }
}

void pull(int id) {
  seg[id].sm = seg[L(id)].sm + seg[R(id)].sm;
}

void modify(int l, int r, int ml, int mr, int id, int xx) {
  if (l > mr || r < ml) return;
  if (ml <= l && mr >= r) {
    seg[id].x ^= xx;
    return;
  }
  push(id);
  int m = (l + r) / 2;
  modify(l, m, ml, mr, L(id), xx);
  modify(m + 1, r, ml, mr, R(id), xx);
  pull(id);
}
