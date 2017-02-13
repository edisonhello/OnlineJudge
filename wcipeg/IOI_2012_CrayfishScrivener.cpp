#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5, lg = 20;
char s[maxn];
int fa[lg][maxn], his[maxn], it, vnow, len[maxn];

void Init() {
  vnow = 0, it = 0;
}

void TypeLetter(char c) {
  ++vnow;
  s[it] = c;
  his[vnow] = it;
  len[vnow] = len[vnow - 1] + 1;
  fa[0][his[vnow]] = his[vnow - 1];
  for (int k = 1; k < lg; ++k) {
    fa[k][his[vnow]] = fa[k - 1][fa[k - 1][his[vnow]]];
  }
  ++it;
}

void UndoCommands(int k) {
  ++vnow;
  his[vnow] = his[vnow - k - 1];
  len[vnow] = len[vnow - k - 1];
  for (int i = 0; i < lg; ++i) fa[i][his[vnow]] = fa[i][his[vnow - k - 1]];
}

char GetLetter(int p) {
  ++p;
  int pos = his[vnow];
  int l = len[vnow];
  for (int k = lg - 1; k >= 0; --k) {
    if ((l - p) >> k & 1) {
      pos = fa[k][pos];
      l -= (1 << k);
    }
  }
  return s[pos];
}

int N, p;
char c;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  while (N--) {
    cin >> c;
    if (c == 'T') cin >> c, TypeLetter(c);
    if (c == 'P') cin >> p, cout << GetLetter(p) << '\n';
    if (c == 'U') cin >> p, UndoCommands(p);
  }
  return 0;
}
