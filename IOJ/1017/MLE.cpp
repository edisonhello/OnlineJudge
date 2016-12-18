#include <iostream>
#include <algorithm>
using namespace std;

int N, A[1000005];

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A, A + N);
  for (int i = 0; i < N; ++i) cout << A[i] << ' ';
}
