#include <iostream>
using namespace std;

int f[45], cnt, n, K;
void fib();

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  fib();
  cin >> n;
  while (n--) {
    cin >> K; cnt = 0;
    if (K <= 0) cout << "iyada~\n";
    else {
      while (K) {
        for (int i = 0; i < 45; ++i) {
          if (f[i] <= K && (i == 44 || f[i + 1] > K)) cnt++, K -= f[i];
        }
      }
      cout << cnt << '\n';
    }
  }
  return 0;
}

void fib() {
  f[0] = 1; f[1] = 2;
  for (int i = 2; i < 45; ++i) f[i] = f[i - 1] + f[i - 2];
}
