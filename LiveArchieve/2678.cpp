#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, s;
vector<long long> prefix;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> s) {
    prefix.clear();
    int Min = INT_MAX;
    long long sum = 0;
    prefix.push_back(0);
    for (int i = 1; i <= n; ++i) {
      int a; cin >> a; sum += a;
      int d = 1, pos = 0;
      while (d <= prefix.size()) d <<= 1;
      while (d >>= 1) if (pos + d < prefix.size()) if (sum - prefix[pos + d] >= s) pos += d;
      if (sum - prefix[pos] >= s) Min = min(Min, i - pos);
      prefix.push_back(sum);
    }
    cout << (Min == INT_MAX ? 0 : Min) << '\n';
  }
  return 0;
}
