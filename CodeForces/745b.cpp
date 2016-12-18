#include <iostream>
#include <string>
using namespace std;

const int MAXN = 500 + 5;
string rec[MAXN];
int n, m, sti, stj, edi, edj, h, w;
bool found;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> rec[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rec[i][j] == 'X') { sti = i; stj = j; found = true; goto jizz; }
    }
  }
  jizz:
  if (!found) { cout << "NO\n"; return 0; }
  edi = -1; edj = -1;
  for (int i = sti; i < n; ++i) {
    if (rec[i][stj] != 'X') { edi = i; break; }
  }
  if (edi == -1) edi = n - 1;
  else edi--;
  if (edi < n - 1) for (int i = edi + 1; i < n; ++i) if (rec[i][stj] == 'X') { cout << "NO\n"; return 0; }
  for (int j = stj; j < m; ++j) {
    if (rec[sti][j] != 'X') { edj = j; break; }
  }
  if (edj == -1) edj = m - 1;
  else edj--;
  w = edj - stj + 1;
  if (edj < m - 1) for (int j = stj + 1; j < m; ++j) if (rec[sti][j] == 'X') { cout << "NO\n"; return 0; }
  for (int i = sti; i <= edi; ++i) {
    for (int j = stj; j <= edj; ++j) {
      if (rec[i][j] != 'X') { cout << "NO\n"; return 0; }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i >= sti && i <= edi && j >= stj && j <= edj) continue;
      if (rec[i][j] == 'X') { cout << "NO\n"; return 0; }
    }
  }
  cout << "YES\n";
  return 0;
}
