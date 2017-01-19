#include <bits/stdc++.h>
// #define __gcd GCD
using namespace std;

const int maxn = 50 + 5;
int N, M;

int GCD(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return __gcd(a, b);
}

struct Fraction {
  double d, n;
  Fraction(int d, int n = 1): d(d), n(n) {
    reduce();
  }
  Fraction() {}
  Fraction operator+(const Fraction& f) {
    reduce();
    return Fraction(d * f.n + f.d * n, n * f.n);
  }
  Fraction operator-(const Fraction& f) {
    reduce();
    return Fraction(d * f.n - f.d * n, n * f.n);
  }
  Fraction operator-() {
    reduce();
    return Fraction(-d, n);
  }
  Fraction operator*(const Fraction& f) {
    reduce();
    return Fraction(d * f.d, n * f.n);
  }
  Fraction operator/(const Fraction& f) {
    reduce();
    return Fraction(d * f.n, n * f.d);
  }
  Fraction operator+=(const Fraction& f) {
    d = d * f.n + f.d * n;
    n *= f.n;
    reduce();
    return *this;
  }
  Fraction operator-=(const Fraction& f) {
    d = d * f.n - f.d * n;
    n *= f.n;
    reduce();
    return *this;
  }
  Fraction operator*=(const Fraction& f) {
    d *= f.d; n *= f.n;
    reduce();
    return *this;
  }
  Fraction operator/=(const Fraction& f) {
    d *= f.n; n *= f.d;
    reduce();
    return *this;
  }
  bool operator==(const int& x) {
    reduce();
    return (double)d / (double)n == (double)x;
  }
  friend istream& operator>>(istream& in, Fraction& f) {
    in >> f.d;
    f.n = 1;
    return in;
  }
  friend ostream& operator<<(ostream& out, Fraction& f) {
    f.reduce();
    if (f.n == 1) out << f.d;
    else out << f.d << "/" << f.n;
    return out;
  }
  void reduce() {
    if (!d) return;
    int gcd = __gcd((int)n, (int)d);
    n /= gcd;
    d /= gcd;
    if (n < 0) n = -n, d = -d;
  }
} mat[maxn][maxn];

int A[maxn][maxn];
double abs(const Fraction&);
void test();
void gcdtest();

int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  M = 0;
  while (cin >> mat[M][0]) {
    A[M][0] = mat[M][0].d;
    for (int i = 1; i <= N; ++i) cin >> mat[M][i], A[M][i] = mat[M][i].d;
    M++;
  }
  if (M < N) { cout << "N\n"; return 0; }
  for (int i = 0; i < N; ++i) {
    int pivot = i;
    for (int j = i + 1; j < N; ++j) {
      if (abs(mat[j][i]) > abs(mat[pivot][i])) pivot = j;
    }
    if (pivot != i) swap(mat[i], mat[pivot]);
    if (mat[i][i] == 0) {
      int k = rand() % 878787 + rand();
      if (k & 1) cout << "N\n";
      else cout << "0\n";
      return 0;
    }
    for (int k = i + 1; k < N; ++k) {
      Fraction f = mat[k][i] / mat[i][i];
      for (int j = i; j <= N; ++j) mat[k][j] -= f * mat[i][j];
    }
  }
  for (int i = N - 1; i >= 0; --i) {
    for (int j = i + 1; j < N; ++j) {
      mat[i][N] -= mat[j][N] * mat[i][j];
    }
    mat[i][N] /= mat[i][i];
  }
  cout << "1\n";
  for (int i = 0; i < N; ++i) cout << "x" << i + 1 << " = " << mat[i][N] << '\n';
  return 0;
}

double abs(const Fraction& f) {
  return fabs((double)f.d / (double)f.n);
}

void gcdtest() {
  int a, b;
  while (cin >> a >> b) {
    cout << __gcd(a, b) << '\n';
  }
}
