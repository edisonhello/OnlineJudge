#include <cstdio>
#include <queue>
using namespace std;

char c;
vector<long long int> hf;
priority_queue< long long int, vector<long long int>, greater<long long int> > tmp;
long long int nmax, a, b;
int n, p, i, t;

inline int rit() {
  t = 0;
  do {
    c = getchar_unlocked();
    // if (c == '-') k = -1;
  } while (c < '0' || c > '9');
  do {
    t = t * 10 + c - '0';
    c = getchar_unlocked();
  } while (c >= '0' && c <= '9');
  return t;
}

int main() {
  n = rit();
  // int p;
  // long long int a, b;
  hf.reserve(n);
  for (i = 0; i < n; ++i) {
    p = rit();
    tmp.push(p);
  }
  while (tmp.size() > 1) {
    a = tmp.top();
    tmp.pop();
    b = tmp.top();
    tmp.pop();
    nmax += a + b;
    tmp.push(a + b);
  }
  printf("%lld\n", nmax);
  return 0;
}
