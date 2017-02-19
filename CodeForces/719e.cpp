#include <bits/stdc++.h>
#define Lc(id) (id << 1)
#define Rc(id) (id << 1 | 1)
using namespace std;

const int maxn = 100000 + 5, MOD = 1000000007;

struct Mat {
  int mat[2][2];
  Mat() {
    memset(mat, 0, sizeof(mat));
  }
  Mat operator+(const Mat& m) const {
    Mat ret;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
      ret.mat[i][j] = mat[i][j] + m.mat[i][j];
      ret.mat[i][j] %= MOD;
    }
    return ret;
  }
  Mat operator*(const Mat& m) const {
    Mat ret;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          ret.mat[i][j] += (long long)mat[i][k] * (long long)m.mat[k][j] % MOD;
          ret.mat[i][j] %= MOD;
        }
      }
    }
    return ret;
  }
};

Mat I() {
  Mat ret;
  ret.mat[0][0] = 1; ret.mat[1][1] = 1;
  return ret;
}

Mat F() {
  Mat ret;
  ret.mat[0][0] = 1; ret.mat[1][0] = 1; ret.mat[0][1] = 1;
  return ret;
}

struct Seg {
  Mat val, tag;
  Seg() {
    tag = I();
  }
  bool mod;
} seg[maxn << 2];

int N, M, A[maxn], tp, l, r, x;

Mat power(Mat, int);
void build(int, int, int);
void pull(int);
void modify(int, int, int, int, int, Mat);
Mat query(int, int, int, int, int);
void push(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  build(1, 1, N);
  while (M--) {
    cin >> tp;
    if (tp == 1) {
      cin >> l >> r >> x;
      Mat add = F();
      add = power(add, x);
      modify(1, 1, N, l, r, add);
    }
    if (tp == 2) cin >> l >> r, cout << query(1, 1, N, l, r).mat[0][0] << '\n';
  }
  return 0;
}

Mat power(Mat m, int n) {
  Mat ret = I();
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * m;
    m = m * m;
  }
  return ret;
}

void build(int id, int L, int R) {
  if (L == R) {
    Mat m = F();
    seg[id].val = power(m, A[L] - 1);
    seg[id].tag = I();
    return;
  }
  int M = (L + R) >> 1;
  build(Lc(id), L, M); build(Rc(id), M + 1, R);
  pull(id);
}

void pull(int id) {
  seg[id].val = seg[Lc(id)].val + seg[Rc(id)].val;
}

void modify(int id, int L, int R, int l, int r, Mat x) {
  push(id, L, R);
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    seg[id].val = seg[id].val * x;
    seg[id].tag = seg[id].tag * x;
    seg[id].mod = true;
    return;
  }
  int M = (L + R) >> 1;
  modify(Lc(id), L, M, l, r, x);
  modify(Rc(id), M + 1, R, l, r, x);
  pull(id);
}

void push(int id, int L, int R) {
  if (L == R) return;
  if (!seg[id].mod) return;
  seg[Lc(id)].val = seg[Lc(id)].val * seg[id].tag; seg[Lc(id)].tag = seg[Lc(id)].tag * seg[id].tag;
  seg[Rc(id)].val = seg[Rc(id)].val * seg[id].tag; seg[Rc(id)].tag = seg[Rc(id)].tag * seg[id].tag;
  seg[Lc(id)].mod = true;
  seg[Rc(id)].mod = true;
  seg[id].mod = false;
  seg[id].tag = I();
}

Mat query(int id, int L, int R, int l, int r) {
  push(id, L, R);
  if (L > r || l > R) return Mat();
  if (L >= l && R <= r) return seg[id].val;
  int M = (L + R) >> 1;
  return query(Lc(id), L, M, l, r) + query(Rc(id), M + 1, R, l, r);
}
