#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> LIS;
int N, T, A[500005];

bool query(int a, int b) {
  return a * b < 0 && abs(a) < abs(b);
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    LIS.clear();
    LIS.push_back(A[0]);
    for (int i = 1; i < N; ++i) {
      if (abs(A[i]) > abs(LIS.back()) && A[i] * LIS.back() < 0) LIS.push_back(A[i]);
      else *lower_bound(LIS.begin(), LIS.end(), A[i], query) = A[i];
    }
    cout << LIS.size() << '\n';
  }
  return 0;
}
