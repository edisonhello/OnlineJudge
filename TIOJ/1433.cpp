#include <iostream>
using namespace std;

char mp[105][105];
int c, n, a1, a2, a3, a4, w, h;
char ch;
void init();
void output();

int main() {
  cin >> c;
  while (c--) {
    init();
    cin >> h >> w >> n;
    while (n--) {
      cin >> a1 >> a2 >> a3 >> a4 >> ch;
      for (int i = a2 - 1; i < a4; ++i) {
        for (int j = a1 - 1; j < a3; ++j) {
          mp[i][j] = ch;
        }
      }
    }
    output();
  }
  return 0;
}

void init() {
  for (int i = 0; i < 105; ++i) for (int j = 0; j < 105; ++j) mp[i][j] = 'o';
}

void output() {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << mp[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
