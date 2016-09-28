#include <iostream>
using namespace std;

int a, r[100], c[100], sm = 0, i, j, m, n, t, tmp;
char cc;

inline int rit() {
	t = 0;
	do {
		cc = getchar_unlocked();
	} while (cc < '0' || cc > '9');
	do {
		t = t * 10 + cc - '0';
		cc = getchar_unlocked();
	} while (cc >= '0' && cc <= '9');
	return t;
}

int main() {
  m = rit(); n = rit();
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      a = rit();
      r[i] += a;
      c[j] += a;
      sm += a;
    }
  }
  tmp = 0;
  for (i = 0; i < m; ++i) {
    if (tmp + r[i] < (sm + 1) / 2) {
      tmp += r[i];
    } else {
      printf("%d ", i + 1);
      break;
    }
  }
  tmp = 0;
  for (i = 0; i < n; ++i) {
    if (tmp + c[i] < (sm + 1) / 2) {
      tmp += c[i];
    } else {
      printf("%d\n", i + 1);
      break;
    }
  }
  // cout << row << ' ' << col << endl;
  return 0;
}
