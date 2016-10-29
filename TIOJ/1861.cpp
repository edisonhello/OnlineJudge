#include <iostream>
#include <algorithm>
using namespace std;

int N, tot, a[10005], pain;

int main() {
  while (cin >> N) {
    tot = 0; pain = 0;
    for (int i = 0; i < N; ++i) cin >> a[i], tot += a[i];
    sort(a, a + N);
    for (int i = 0; i < N - 2; ++i) {
      pain += tot;
      tot -= a[i];
    }
    cout << pain << endl;
  }
  return 0;
}
