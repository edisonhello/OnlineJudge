#include <iostream>
using namespace std;

int x, y, cnt;

int main() {
  while (cin >> x >> y) {
    cnt = 0;
    while (x > 0 && y > 0) {
      if (x > y) x -= y;
      else y -= x;
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
