#include <iostream>
#include <map>
#include <algorithm>
#define INF (1<<31)-1
using namespace std;

map<int, int> mp;
int A, ans, mn;
bool p;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  ans = 0; mn = INF;
  while (cin >> A, A) {
    mp[A]++; p = false;
    if (mp[A] > ans) ans = mp[A], mn = A;
    else if (mp[A] == ans) mn = min(mn, A);
    cout << ans << ' ' << mn << endl;
  }
  return 0;
}
