#include <map>
#include <utility>
#include <cstdio>
using namespace std;

char c;
typedef pair<int, int> pii;
int m, n, v, w, i, t;
map<pii, int> nmap;

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
  m = rit();
  n = rit();
  for (i = 0; i < n; ++i) {
    v = rit();
    w = rit();
    if (v == w) {
      printf("Yes\n");
      return 0;
    }
    if (nmap.find(pii(v, w)) == nmap.end()) {
      nmap[pii(v, w)] = 1;
    } else {
      printf("Yes\n");
      return 0;
    }
    if (nmap.find(pii(w, v)) == nmap.end()) {
      nmap[pii(w, v)] = 0;
    } else {
      printf("Yes\n");
      return 0;
    }
  }
  printf("yes\n");
  return 0;
}
