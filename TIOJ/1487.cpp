#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> tp;

bool solve[110];
int fail[110];
int m, n, cur, t, w, g, ans, tt, i;
vector<tp> submit;
char c;

inline int rit() {
  tt = 0;
  do {
    c = getchar_unlocked();
  } while (c < '0' || c > '9');
  do {
    tt = tt * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return tt;
}

int main() {
  while (scanf("%d %d", &m, &n) != EOF) {
    if (m == 0 && n == 0) break;
    submit.clear();
    for (i = 0; i < n; ++i) {
      t = rit(), w = rit(), g = rit();
      submit.push_back(tp(t, w, g));
    }
    sort(submit.begin(), submit.end());
    memset(solve, false, sizeof(solve));
    memset(fail, 0, sizeof(fail));
    cur = 0; ans = 0;
    for (i = 0; i < n; ++i) {
      if (solve[get<1>(submit[i])]) continue;
      if (get<2>(submit[i])) {
        solve[get<1>(submit[i])] = true;
        cur = fail[get<1>(submit[i])] * 20 + cur + get<0>(submit[i]);
        ans++;
      } else {
        fail[get<1>(submit[i])]++;
      }
    }
    printf("%d %d\n", cur, ans);
  }
  return 0;
}
