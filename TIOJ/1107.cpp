#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

struct C {
  double d;
  int ex;
  C operator*(const int n) const {
    C ret = *this;
    ret.d *= n;
    while (ret.d > 10) {
      ret.d /= 10;
      ret.ex++;
    }
    return ret;
  }
  C operator/(const int n) const {
    C ret = *this;
    ret.d /= n;
    while (ret.d < 1) {
      ret.d *= 10;
      ret.ex--;
    }
    return ret;
  }
  C(): d(0.0), ex(0) {}
  C(double d, int ex): d(d), ex(ex) {}
};

C c[1000005];
int N;
void build();

int main() {
  build();
  while (scanf("%d", &N), N) {
    printf("%.3lfE+%d\n", c[N].d, c[N].ex);
  }
  return 0;
}

void build() {
  c[0] = (C){ 1.0, 0 };
  for (int i = 1; i < 1000005; ++i) {
    c[i] = c[i - 1] * (4 * i - 2) / (i + 1);
  }
}
