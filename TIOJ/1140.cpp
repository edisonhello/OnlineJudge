#include <iostream>
#include <iomanip>
using namespace std;

double d[3][3] = {
  {0.5149, 0.3244, 0.1607},
  {0.2654, 0.6704, 0.0642},
  {0.0248, 0.1248, 0.8504}
};

double R, G, B, totY;
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> R >> G >> B;
      for (int k = 0; k < 3; ++k) {
        if (k == 1) totY += d[k][0] * R + d[k][1] * G + d[k][2] * B;
        cout << fixed << setprecision(4) << d[k][0] * R + d[k][1] * G + d[k][2] * B << ' ';
      }
      cout << endl;
    }
  }
  cout << "The average of Y is " << fixed << setprecision(4) << totY / (n * n) << endl;
  return 0;
}
