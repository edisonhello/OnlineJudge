#include <cmath>
#include <cstdio>
using namespace std;

int main() {
  double ans = 0;
  for (double i = 1.0; i <= 2008; ++i) {
    ans += (i * i) / (1 + i * i);
  }
  ans *= 2;
  ans -= 0.5;
  printf("%.1f\n", ans);
  
}
