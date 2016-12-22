#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 4000 + 5;
int T, N, A[maxn], Min, Max, MMin, MMax;
const int INF = 1<<30;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N;
    Max = MMax = 0; Min = MMin = INF;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      Max = max(Max, A[i]);
      Min = min(Min, A[i]);
    }
    for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
      MMax = max(MMax, min(abs(A[i] - Min), abs(A[j] - Min)) + min(abs(A[i] - Max), abs(A[j] - Max)));
    }
    cout << MMax << '\n';
  }
  return 0;
}
