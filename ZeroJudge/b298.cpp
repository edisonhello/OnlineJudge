#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

vector<int> vec[10010];
vector<bool> ok(10010, true);
int n, m, l, q, a, b, x, y, i, t;

int inline rit() {
  t = 0;
  char c;
  do {
    c = getchar_unlocked();
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int main() {
  // memset(ok, true, sizeof(ok));
  n = rit(); m = rit(); l = rit(); q = rit();
  // cout << n << ' ' << m << ' ' << l << ' ' << q << endl;
  for (i = 0; i < m; ++i) {
    a = rit(); b = rit();
    vec[a].push_back(b);
  }
  for (i = 0; i < l; ++i) {
    x = rit();
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
      int top = q.front();
      ok[top] = false;
      for (int j = 0; j < vec[top].size(); ++j) {
        if (ok[vec[top][j]]) {
          q.push(vec[top][j]);
        }
      }
      q.pop();
    }
    // cout << "jizz" << endl;
  }
  for (i = 0; i < q; ++i) {
    y = rit();
    if (ok[y]) printf("YA~~\n");
    else printf("TUIHUOOOOOO\n");
  }
  return 0;
}
