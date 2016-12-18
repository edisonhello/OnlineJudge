#include <iostream>
#include <algorithm>
using namespace std;

int N, s, cnt[3];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N) {
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 0; i < N; ++i) {
      cin >> s;
      if (s < 0) cnt[0]++;
      if (s == 0) cnt[1]++;
      if (s > 0) cnt[2]++;
    }
    cout << cnt[1] + min(cnt[0], cnt[2]) * 2 << '\n';
  }
  return 0;
}
