#include <iostream>
#include <algorithm>
using namespace std;

struct B {
  int b, c;
  bool operator<(const B& bb) {
    return c == bb.c ? b < bb.b : c < bb.c;
  }
};

B bf[1000005];
int n, a[1000005], m;
long long tot;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> bf[i].b >> bf[i].c;
  }
  sort(bf, bf + m); sort(a, a + n);
  int j = 0;
  for (int i = 0; i < m; ++i) {
    if (j == n) break;
    if (bf[i].b >= a[j]) tot += bf[i].c, j++;
  }
  cout << tot << endl;
  return 0;
}
