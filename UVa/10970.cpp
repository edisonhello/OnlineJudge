#include <iostream>
using namespace std;

const int maxn = 300 + 5;

int M, N, dpa[maxn][maxn];
int dp(int, int);

int main() {
  while (cin >> M >> N) {
    cout << dp(M, N) << '\n';
  }
  return 0;
}

int dp(int a, int b) {
  if (a < b) swap(a, b);
  if (dpa[a][b]) return dpa[a][b];
  if (a == 1 || b == 1) return dpa[a][b] = a == 1 ? b - 1 : a - 1;
  return dpa[a][b] = 1 + dp(a / 2, b) + dp(a - a / 2, b);
}
