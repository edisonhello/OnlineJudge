#include <cstdio>
#include <queue>
using namespace std;

vector<long long int> hf;
priority_queue< long long int, vector<long long int>, greater<long long int> > tmp;
long long int nmax = 0;

inline long long int rlit() {
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
  int n;
  n = rit();
  long long int p;
  hf.reserve(n);
  for (int i = 0; i < n; ++i) {
    p = rlit();
    tmp.push(p);
  }
  while (tmp.size() > 1) {
    long long int a, b;
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
