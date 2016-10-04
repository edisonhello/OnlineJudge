#include <iostream>
using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(a % b, b);
  else return gcd(b % a, a);
}

int N, i, g, a[25], t;
char c;

inline int rit() {
  t = 0;
  do {
    c = getchar_unlocked();
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int main() {
  while (cin >> N) {
    for (i = 0; i < N; ++i) cin >> a[i];
    g = a[0];
    for (i = 1; i < N; ++i) g = gcd(g, a[i]);
    cout << g << endl;
  }
  return 0;
}
