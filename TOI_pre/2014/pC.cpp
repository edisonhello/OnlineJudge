#include <bits/stdc++.h>
using namespace std;

int N, L, box[25][505];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> L;
  for (int i = 1; i <= N; ++i) {
    int ind = 0, cur = 1, I, s;
    cin >> I;
    while (I--) {
      cin >> s;
      if (s == 0) box[i][cur++] = 0;
      else {
        ++ind;
        for (int j = 0; j < s; ++j) box[i][cur++] = ind;
      }
    }
  }
  for (int i = 1; i <= L; ++i) {
    int mv = 0;
    for (int j = 1; j <= N; ++j) if (box[j][i]) {
      
    }
  }
  return 0;
}
