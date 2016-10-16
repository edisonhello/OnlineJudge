#include "lib1227.h"
using namespace std;

int n;
long long jizz;
long long* d;
long long chg[1000010];
bool firstQuery;

void init(int N, long long D[]) {
    n = N;
    d = D;
    firstQuery = true;
}

void change(int a, int b, long long k) {
  if (a & 1) {
    chg[a] += -k;
    chg[b + 1] += k;
  } else {
    chg[a] += k;
    chg[b + 1] += -k;
  }
}

long long query(int c) {
  if (firstQuery) {
    firstQuery = false;
    for (int i = 0; i < n; ++i) {
      jizz += chg[i];
      if (i & 1) d[i] += jizz;
      else d[i] -= jizz;
    }
  }
  return d[c];
}
