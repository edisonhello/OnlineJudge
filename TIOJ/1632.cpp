#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int N, h[maxn];
long long K;
vector<int> d;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> h[i];
  sort(h, h + N);
  for (int i = 1; i < N; ++i) d.push_back(h[i] - h[i - 1]);
  sort(d.begin(), d.end());
  cout << d[K - 1] << '\n';
  return 0;
}
