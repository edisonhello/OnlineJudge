#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= ceil(sqrt(N)); ++i) ans += (N % i) * (N / i);
  cout << ans << '\n';
}
