#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#define int long long
using namespace std;

set<int> lucky;
bitset<100000000> v;
int i, ki;
int k[] = {10, 50, 100, 1000, 10000};
bool test(int, int);

signed main() {
  // for (i = 1; lucky.size() <= 10000; ++i) {
  //   v.reset();
  //   if (lucky.size() == k[ki]) cout << *lucky.rbegin() << '\n', ki++;
  //   if (test(i, 0)) lucky.insert(i);
  // }
  cout << "44\n320\n694\n6899\n67169\n";
  // cout << lucky[9] << '\n' << lucky[49] << '\n' << lucky[99] << '\n' << lucky[999] << '\n' << lucky[9999] << '\n';
  return 0;
}

bool test(int x, int p) {
  // cout << x << ' ';
  // if (x == 0)
  if (v[x]) return false;
  v[x] = true;
  if (x < i) return lucky.count(x);
  if (x == p) return false;
  if (x == 1) return true;
  if (x / 10 == 0) return test(x * x, x);
  int ret = 0;
  // cout << x << "->";
  while (x) {
    ret += (x % 10) * (x % 10);
    x /= 10;
  }
  // cout << ret << '\n';
  return test(ret, x);
}
