#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

bitset<1000010> prime;

void build() {
  // prime.set();
  prime[1] = true;
  for (int i = 2; i <= 1000000; ++i) {
    if (!prime[i]) {
      for (int j = i * i; j <= 1000000; j += i) prime[j] = true;
    }
  }
}

int n, m;

vector<int> ans;
bitset<1000010> v;

bool dfs(int n) {
  if (n == 0) return true;
  for (int i = n; i > 0; --i) {
    if (!prime[i] && !v[i]) {
      v[i] = true;
      if (dfs(n - i)) {
        ans.push_back(i);
        return true;
      }
      v[i] = false;
    }
  }
  return false;
}

int main() {
  build();
  cin >> n;
  while (n--) {
    ans.clear(); v.reset();
    cin >> m;
    if (prime[m]) {cout << 0 << endl; break;}
    v[m] = true;
    if (dfs(m)) {
      for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
      cout << endl;
    } else {
      cout << m << endl;
    }
  }
  return 0;
}
