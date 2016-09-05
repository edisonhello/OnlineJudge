#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
<<<<<<< HEAD
  int s[10000];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  // cout << "jizz" << endl;
  sort(s, s + n);
  int taxi = 0;
  int cur = 0;
  int idx = 0;
  while (idx < n) {
    if (cur + s[idx] <= 4) {
      cur += s[idx];
      idx++;
    } else {
      cur = 0;
      taxi++;
      // i--;
    }
  }
  if (cur > 0) taxi++;
  cout << taxi << endl;
=======
  cin >> n;
  int s;
  int cnt[4] = {0};
  for (int i = 0; i < n; ++i) {
    cin >> s;
    cnt[s - 1]++;
  }
  int ans = 0;
  ans += cnt[3];
  cnt[3] = 0;
  if (cnt[0] > cnt[2]) {
    ans += cnt[2];
    cnt[0] -= cnt[2];
    cnt[2] = 0;
  } else {
    ans += cnt[0];
    cnt[2] -= cnt[0];
    cnt[0] = 0;
  }
  ans += cnt[2];
  cnt[2] = 0;
  ans += cnt[1] / 2;
  cnt[1] %= 2;
  ans += cnt[0] / 4;
  cnt[0] %= 4;
  if (cnt[0] > 0 && cnt[1] > 0) {
    if (cnt[0] >= 2 * cnt[1]) {
      ans++;
      cnt[1] = 0;
      cnt[0] -= 2;
    }
  }
  if (cnt[0] > 0) {
    if (cnt[1] > 0) {
      ans++;
      cnt[0] = 0;
      cnt[1] = 0;
    } else {
      ans++;
      cnt[0] = 0;
    }
  }
  if (cnt[1] > 0) ans++;
  cout << ans << endl;
>>>>>>> 93d56cf6e87b368bd278751ff306fae3d9b99e96
  return 0;
}
