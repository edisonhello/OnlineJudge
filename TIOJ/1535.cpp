#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;

bitset<100000000> prime;
vector<int> ans;
int T, n, a;

int rev(int x) {
  int ret = 0, p = pow(10, (int)log10(x)), t = 1;
  while (p) {
    ret += x / p * t;
    x -= (x / p) * p;
    p /= 10; t *= 10;
  }
  return ret;
}

bool jizz(int x) {
  int re = rev(x);
  if (x == re) return false;
  return !prime[re];
}

void build() {
  for (long long i = 2; i < 100000000; ++i) {
    if (!prime[i]) {
      for (long long j = i * i; j < 100000000; j += i) prime[j] = true;
    }
  }
  for (int i = 2; i < 100000000; ++i) {
    if (!prime[i] && jizz(i)) ans.push_back(i);
  }
}

int main() {
  // test();
  build();
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    cout << ans[n - 1] << endl;
  }
  return 0;
}
