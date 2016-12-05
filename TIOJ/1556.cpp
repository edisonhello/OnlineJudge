#include <iostream>
#include <cmath>
#define int long long
using namespace std;

int N, ans;

signed main() {
  cin >> N;
  for (int i = 1; i <= sqrt(N); ++i) {
    ans += (N / i) - 1 + (i - 1) * (N / i - N / (i + 1));
    if ((N / i) - 1 == i - 1) ans -= (N / i) - 1;
  }
  cout << ans << endl;
  return 0;
}

// 1  2  3  4
// 3  1  0  0
//
// 1  2  3  4  5
// 4  1  0  0  0
//
// 1  2  3  4  5  6  7  8  9  10  11
// 10 4  2  1  1  0  0  0  0  0   0
//
//
// 1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
// 14 6  4  2  2  1  1  0  0  0   0   0   0    0   0
//
// 1 - 2
// 2 - 2
// 3 - 0
// 4 - 1
// 5 - 0
// 6 - 1
// 7 - 0
// ...
// 14 - 1
