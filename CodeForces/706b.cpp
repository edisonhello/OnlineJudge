#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int dq[100000];

int search(int);
int n;

int main() {
  int x, q, m;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    dq[i] = x;
  }
  sort(dq, dq + n);
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> m;
    cout << search(m) << endl;
  }
  return 0;
}

int search(int x) {
  int l = 0;
  int r = n - 1;
  int m = (l + r) / 2;
  while (l <= r) {
    if (dq[m] > x) r = m -1;
    else if (dq[m] < x) l = m + 1;
    else return m + 1;
    m = (l + r) / 2;
  }
  return m + 1;
}
