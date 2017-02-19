#include <bits/stdc++.h>
#define lowdiff(x) (x & -x)
using namespace std;

const int maxn = 1000 + 5;
int cnt[maxn][maxn], N, X1, Y1, X2, Y2, r, g, b, p[maxn][maxn], Max;
struct Color { int R, G, B; } diff[maxn][maxn], prefix[maxn][maxn], ans;
map<Color, int> m;
Color operator+(const Color&, const Color&);
Color operator-(const Color&, const Color&);
bool operator<(const Color&, const Color&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    if (X1 > X2) swap(X1, X2);
    if (Y1 > Y2) swap(Y1, Y2);
    ++X1, ++Y1;
    cin >> r >> g >> b;
    diff[X1][Y1].R += r, diff[X1][Y1].G += g, diff[X1][Y1].B += b;
    diff[X2 + 1][Y1].R -= r, diff[X2][Y1 + 1].G -= g, diff[X2][Y1 + 1].B -= b;
    diff[X1][Y2 + 1].R -= r, diff[X1][Y2 + 1].G -= g, diff[X1][Y2 + 1].B -= b;
    diff[X2 + 1][Y2 + 1].R += r, diff[X2 + 1][Y2 + 1].G += g, diff[X2 + 1][Y2 + 1].B += b;
    cnt[X1][Y1]++, cnt[X2 + 1][Y2 + 1]++, cnt[X1][Y2 + 1]--, cnt[X2 + 1][Y1]--;
  }
  for (int i = 1; i < maxn; ++i) {
    for (int j = 1; j < maxn; ++j) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] + diff[i][j] - prefix[i - 1][j - 1];
      p[i][j] = p[i - 1][j] + p[i][j - 1] + cnt[i][j] - p[i - 1][j - 1];
      if (p[i][j]) {
        m[(Color){ (int)ceil((double)prefix[i][j].R / (double)p[i][j]), (int)ceil((double)prefix[i][j].G / (double)p[i][j]), (int)ceil((double)prefix[i][j].B / (double)p[i][j]) }]++;
      }
    }
  }
  for (auto i : m) {
    if (i.second > Max) Max = i.second, ans = i.first;
  }
  cout << ans.R << ' ' << ans.G << ' ' << ans.B << '\n';
  return 0;
}

Color operator+(const Color& c1, const Color& c2) {
  return (Color){ c1.R + c2.R, c1.G + c2.G, c1.B + c2.B };
}

Color operator-(const Color& c1, const Color& c2) {
  return (Color){ c1.R - c2.R, c1.G - c2.G, c1.B - c2.B };
}

bool operator<(const Color& c1, const Color& c2) {
  return c1.R < c2.R;
}
