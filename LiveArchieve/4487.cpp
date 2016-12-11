#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

int djs[20005], X[20005], N, Q, p, q, v, test, len, k, ans, answer;
string cmd;
stringstream ss;

int F(int x) {
  return djs[x] == x ? x : djs[x] = F(djs[x]);
}

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y; X[y] ^= X[x];
}

int main() {
  // cin.tie(0); ios_base::sync_with_stdio(false);
  while (scanf("%d %d\n", &N, &Q), (N || Q)) {
    for (int i = 0; i < N; ++i) djs[i] = i, X[i] = 0;
    for (int _ = 0; _ < Q; ++_) {
      getline(cin, cmd);
      if (cmd[0] == 'I') {
        ss.clear(); ss.str("");
        ss << cmd; len = 0;
        while (ss >> test) len++;
        if (len == 3) {
          ss.clear(); ss.str("");
          ss >> test; ss >> p; ss >> v;
          if (X[p]) { cout << "The first " << _ + 1 << " facts are conflictin.\n"; continue; }
          else X[p] = v;
        } else {
          ss.clear(); ss.str("");
          ss >> test; ss >> p; ss >> q; ss >> v;
          if (F(p) == F(q) && X[F(q)] != v) { cout << "The first " << _ + 1 << " facts are conflictin.\n"; continue; }
          else U(p, q), X[F(p)] = v;
        }
      } else {
        ss.clear(); ss.str("");
        ss << cmd; ss >> test;
        ss >> k; ans = 0; answer = true;
        for (int i = 0; i < k; ++i) {
          ss >> p;
          if (!X[F(p)]) { cout << "I don't know.\n"; answer = false; break; }
          else ans ^= X[F(p)];
        }
        if (answer) cout << ans << '\n';
      }
    }
  }
  return 0;
}
