#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int N, Q, djs[100010], a, b, t, k;
char c;
string cmd;

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

int F(int a) {
  if (djs[a] == a) return a;
  return djs[a] = F(djs[a]);
}

void U(int a, int b) {
  a = F(a);
  b = F(b);
  // if (b > a) swap(a, b);
  djs[b] = a;
}

int main() {
  N = rit(); Q = rit();
  for (int i = 1; i <= N; ++i) djs[i] = i;
  while (Q--) {
    cin >> cmd;
    if (cmd == "Masuta") {
      a = rit(); b = rit();
      U(a, b);
    } else {
      a = rit();
      printf("%d\n", F(a));
    }
  }
  return 0;
}
