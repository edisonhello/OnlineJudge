#include <iostream>
#include <string>
using namespace std;

int N, P[2000005], E[2000005], C[2000005];
string s;
int dp(int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> s;
  for (int i = 0; i < N; ++i) {
    if (s[i] == 'P') P[i] = P[i - 1] + 1, C[i] = C[i - 1], E[i] = E[i - 1];
    if (s[i] == 'C') P[i] = P[i - 1], C[i] = C[i - 1] + 1, E[i] = E[i - 1];
    if (s[i] == 'E') P[i] = P[i - 1], C[i] = C[i - 1], E[i] = E[i - 1] + 1;
  }
  cout << dp(0, N - 1) << '\n';
  return 0;
}

int dp(int L, int R) {
  if (L == R) return 0;
  for (int i = L; i <= R; ++i) {
    for (int j = i + 1; j <= R; ++j) {

    }
  }
}
