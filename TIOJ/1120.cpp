#include <iostream>
#include <cstdio>
using namespace std;

int t;
int ji, zz, x, y;
int start[16] = {10, 5, 15, 5, 15, 10, 15, 15, 10, 15, 5, 15, 5, 10, 5, 5};
int dir[8] = {1, 2, 2, 3, 3, 4, 4, 1};

int main() {
  while (cin >> t) {
    t *= 6;
    t %= 40;
    ji = t / 5;
    zz = t % 5;
    x = start[ji * 2];
    y = start[ji * 2 + 1];
    if (dir[ji] == 1) {x += zz;}
    if (dir[ji] == 2) {y += zz;}
    if (dir[ji] == 3) {x -= zz;}
    if (dir[ji] == 4) {y -= zz;}
    printf("(%d,%d)\n", x, y);
  }
  return 0;
}
