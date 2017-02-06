#include <iostream>
#include <string>
#include <set>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5, Z = 233, A = 547, B = 181;
const unsigned long long MOD = 370248451;
int N, M, T, P, Q, kase;
string s[maxn], t[maxn];
unsigned long long tmp[maxn][maxn], _hash[maxn][maxn], z[maxn], a[maxn], b[maxn];


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> N >> M >> T >> P >> Q, (N || M || T || P || Q)) {
    multiset<unsigned long long> ms;
    // z[0] = 1;
    // for (int i = 1; i < N; ++i) z[i] = z[i - 1] * Z, z[i] %= MOD;
    a[0] = b[0] = 1;
    for (int i = 1; i < N; ++i) a[i] = a[i - 1] * A, b[i] = b[i - 1] * B;
    for (int i = 0; i < N; ++i) cin >> s[i];
    for (int i = 0; i < T; ++i) {
      for (int i = 0; i < P; ++i) cin >> t[i];
      for (int i = 0; i < P; ++i) {
        for (int j = 0; j < Q; ++j) tmp[i][j] = (j ? tmp[i][j - 1] * A + t[i][j] : t[i][j]);
      }
      for (int j = 0; j < Q; ++j) {
        for (int i = 0; i < P; ++i) _hash[i][j] = (i ? _hash[i - 1][j] * B + tmp[i][j] : tmp[i][j]);
      }
      ms.insert(_hash[P - 1][Q - 1]);
      // cout << "hash: " << _hash[P - 1][Q - 1] << '\n';
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < Q; ++j) tmp[i][j] = (j ? tmp[i][j - 1] * A + s[i][j] : s[i][j]);
      for (int j = Q; j < M; ++j) tmp[i][j] = (tmp[i][j - 1] * A + s[i][j] - s[i][j - Q] * a[Q]);
    }
    for (int j = 0; j < M; ++j) {
      for (int i = 0; i < P; ++i) _hash[i][j] = (i ? _hash[i - 1][j] * B + tmp[i][j] : tmp[i][j]);
      for (int i = P; i < N; ++i) _hash[i][j] = (_hash[i - 1][j] * B + tmp[i][j] - tmp[i - P][j] * b[P]);
    }
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) ms.erase(_hash[i][j]);
    cout << "Case " << ++kase << ": " << T - (int)ms.size() << '\n';
  }
}
