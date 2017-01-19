#include <bits/stdc++.h>
using namespace std;

double T, P, X, Y, kase;
const double PI = acos(-1);

struct Vector {
  double x, y;
  double dot(const Vector& v) const {
    return x * v.x + y * v.y;
  }
  double len() {
    return sqrt(x * x + y * y);
  }
};

int main() {
  freopen("progress_pie.txt", "r", stdin);
  freopen("outA.txt", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> P >> X >> Y;
    cout << "Case #" << ++kase << ": ";
    if ((X - 50) * (X - 50) + (Y - 50) * (Y - 50) > 2500) { cout << "white\n"; continue; }
    Vector v1 = (Vector){ 0, 50 };
    Vector v2 = (Vector){ X - 50, Y - 50 };
    double dt = v1.dot(v2);
    double len = fabs(v1.len()) * fabs(v2.len());
    double theta = acos(dt / len) * 180.0 / PI;
    if (theta <= 360.0 * (double)P / 100.0) cout << "black\n";
    else cout << "white\n";
  }
  return 0;
}
