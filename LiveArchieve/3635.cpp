#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
const double eps = 0.0001, pi = acos(-1);
double pie[maxn];
int T, N, F;

double bs(double, double);
bool check(double);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> N >> F; ++F;
    double L = 0.0, R = 0.0;
    for (int i = 0; i < N; ++i) {
      int r; cin >> r;
      pie[i] = pi * (double)r * (double)r;
      R += pie[i];
    }
    cout << fixed << setprecision(4) << bs(L, R) << '\n';
  }
  return 0;
}

double bs(double L, double R) {
  if (R - L < eps) return L;
  double M = (L + R) / 2;
  if (check(M)) return bs(M, R);
  return bs(L, M);
}

bool check(double a) {
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    ret += (int)(pie[i] / a);
  }
  return ret >= F;
}
