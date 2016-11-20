#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double d[10005], sm, avg, z;
int T, N, Q, a, b;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N; sm = 0.0; z = 0.0;
    for (int i = 0; i < N; ++i) cin >> d[i], sm += d[i];
    avg = sm / N;
    for (int i = 0; i < N; ++i) z += (d[i] - avg) * (d[i] - avg);
    z /= N; z = sqrt(z);
    cout << fixed << setprecision(2) << z << endl;
    cin >> Q;
    while (Q--) {
      cin >> a >> b;
      cout << fixed << setprecision(2) << abs(a) * z << endl;
    }
  }
  return 0;
}
