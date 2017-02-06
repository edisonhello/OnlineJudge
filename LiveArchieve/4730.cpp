#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5, maxy = 2000000;
int djs[maxn], sz[maxn], T, N, M;
pair<int, int> p[maxn];
string s;

int F(int);
void U(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++j) djs[i] = i, sz[i] = 1;
    for (int i = 0; i < N; ++i) cin >> p[i].first >> p[i].second;
    cin >> M;
    while (M--) {
      cin >> s;
      if (s == "road") {
        int A, B; cin >> A >> B;
        U(A, B);
      } else {
        double C; cin >> C; C *= 2;
        pair<int, int> res = query(1, 0, maxy, C);
        cout <<
      }
    }
  }
  return 0;
}

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x), y = F(y);
  if (sz[x] > sz[y]) swap(x, y);
  djs[x] = y;
  sz[y] += sz[x];
}
