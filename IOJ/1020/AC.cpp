#include <iostream>
#include <algorithm>
#include <algorithm>
using namespace std;

int N, A[1000005], M, pre[1000005];

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A, A + N);
  for (int i = 0; i < N; ++i) pre[i] = pre[i - 1] + A[i];
  cout << upper_bound(A, A + N, M) - A << '\n';
  return 0;
}
