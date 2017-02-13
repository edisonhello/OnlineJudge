#include <bits/stdc++.h>
using namespace std;

const int maxn = 90000;
vector<int> vec;
int k, cnt;
bool v[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  for (int a = 1; a <= 100; ++a) {
    for (int b = a + 1; b <= 100; ++b) {
      for (int c = b + 1; c <= 100; ++c) {
        if (((a + b + c) * (a + b + c) - a * a - b * b - c * c) % 2) continue;
        v[((a + b + c) * (a + b + c) - a * a - b * b - c * c) / 2] = true;
      }
    }
  }
  for (int i = 1; i < maxn; ++i) if (!v[i]) vec.push_back(i);
  while (cin >> k) cout << vec[k - 1] << '\n';
  return 0;
}
