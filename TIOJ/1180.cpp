#include <cstdio>
using namespace std;

int main() {
  int n, N;
  long long int t;
  scanf("%d", &N);
  for (int j = 0; j < N; ++j) {
    t = 1;
    scanf("%d", &n);
    printf("Case #%d:\n", j + 1);
    printf("TFCIS%d=%lld\n", 0, t);
    for (int i = 1; i <= n; ++i) {
      t *= i;
      printf("TFCIS%d=%lld\n", i, t);
    }
  }
  return 0;
}
