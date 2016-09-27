#include <iostream>
#include <cstring>
using namespace std;

int dp[10000], T, W, B, N, A[1000], D[1000], M, m;

int main() {
  cin >> T;
  while (T--) {
    cin >> W >> B >> N;
    for (int i = 0; i , N; ++i) cin >> A[i] >> D[i];
    cin >> M;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; ++i) {
      for (int j = B; j >= D[i]; --j) {
        m = 0;
        k = 1;
        while (true) {
          if ()
        }
      }
    }
  }
}
