#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int T, N, A[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T; while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> v; v.push_back(A[0]);
    for (int i = 1; i < N; ++i) {
      if (A[i] > v.back()) v.push_back(A[i]);
      else *lower_bound(v.begin(), v.end(), A[i]) = A[i];
    }
    cout << v.size() << '\n';
    for (int i : v) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
