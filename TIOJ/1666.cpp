#include <cstdio>
#include <iostream>
using namespace std;

inline int rit() {
  int t = 0, k = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return t * k;
}

int main() {
  int a, b;
  while (cin >> a >> b) {
    // b = rit();
    bool win = false;
    if (a == 1) win = !win;
    if (b == 1) win = !win;
    if (win) printf("kelvin\n");
    else printf("yiping\n");
  }
  return 0;
}
