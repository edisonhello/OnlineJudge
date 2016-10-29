#include <iostream>
#include <set>
using namespace std;

int N, K, D, X, Y, cnt, djs[500005];
set<int> G[500005];
bool p;

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  for (int i = 0; i <= N; ++i) djs[i] = i;
  while (K--) {
    cin >> D >> X >> Y;
    if (X > N || Y > N || (D == 2 && Y == X)) { cnt++; continue; }
    if (D == 1) {
      // if (F(X * 2) == F(Y * 2 + 1) || F(Y * 2) == F(X * 2 + 1)) { cnt++; continue; }
      // if ()
      // if (F(X) )
      // if (G[X].find(Y) != G[X].end() || G[Y].find(X) != G[Y].end()) { cnt++; continue; }
      p = true;
      for (set<int>::iterator it = G[X].begin(); it != G[X].end(); ++it) {
        if (F(*it) == F(Y)) { p = false; break; }
      }
      if (p) {
        for (set<int>::iterator it = G[Y].begin(); it != G[Y].end(); ++it) {
          if (F(*it) == F(X)) { p = false; break; }
        }
      }
      if (p) U(X, Y);
      else cnt++;
      // U(X * 2, Y * 2); U(X * 2 + 1, Y * 2 + 1);
    } else {
      // if (F(X * 2) == F(Y * 2) || F(Y * 2 + 1) == F(X * 2 + 1)) { cnt++; continue; }
      p = true;
      for (int i = 1; i <= N; ++i) {
        if (F(i) == F(X) && F(i) == F(Y)) { cnt++; p = false; break; }
      }
      // if (F(X) == F(Y)) { cnt++; continue; }
      // p = true;
      // for (set<int>::iterator it = G[X].begin(); it != G[X].end(); ++it) if (F(*it) == F(X)) { cnt++; p = false; break; }
      // U(X * 2, Y * 2 + 1); U(X * 2 + 1, Y * 2);
      if (p) G[X].insert(Y);
    }
  }
  cout << cnt << '\n';
  return 0;
}
