#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int N, x, tot;
vector<int> A, B;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N, N) {
    A.clear(); B.clear();
    for (int i = 0; i < N; ++i) cin >> x, A.push_back(x);
    for (int i = 0; i < N; ++i) cin >> x, B.push_back(x);
    sort(A.begin(), A.end()); reverse(A.begin(), A.end());
    sort(B.begin(), B.end()); reverse(B.begin(), B.end());
    int Ai = 0, Aj = A.size() - 1, Bi = 0, Bj = B.size() - 1; tot = 0;
    while (Ai <= Aj && Bi <= Bj) {
      if (A[Ai] > B[Bi]) ++tot, ++Ai, ++Bi;
      else if (A[Ai] == B[Bi]) ++Ai, ++Bi;
      else --tot, ++Bi, --Aj;
    }
    cout << (long long)tot * 200 << '\n';
  }
  return 0;
}
