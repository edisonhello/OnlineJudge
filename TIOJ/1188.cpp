#include <string>
#include <iostream>
using namespace std;

int W, H, h, w;
string mp[105];

int main() {
  cin >> W >> H;
  for (int i = 0; i < H; ++i) cin >> mp[i];
  for (int i = 0; i < W; ++i) {
    h = 0; w = i * 2;
    while (h < H) {
      if (w == 0) {
        if (mp[h][w + 1] == '-') w += 2;
        h++;
      } else if (w == (W - 1) * 2) {
        if (mp[h][w - 1] == '-') w -= 2;
        h++;
      } else {
        if (mp[h][w - 1] == '-') w -= 2;
        else if (mp[h][w + 1] == '-') w += 2;
        h++;
      }
    }
    cout << (w + 1) / 2 + 1 << ' ';
  }
  return 0;
}
