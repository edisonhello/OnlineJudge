#include <cstdio>
#include <algorithm>
using namespace std;

inline long long int rit() {
  long long int t = 0;
  char c;
  do {
    c = getchar_unlocked();
    // if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int main() {
    long long int m, n;
    while (true) {
        m = rit();
        n = rit();
        if (m == 0 && n == 0) break;
        long long int sum;
        if (m < n) swap(m, n);
        sum = m * n * (n + 1) - n * (n + 1) / 2 * (m + n) + n * (n + 1) * (2 * n + 1) / 6;
        printf("%lld\n", sum);
    }
    return 0;
}
