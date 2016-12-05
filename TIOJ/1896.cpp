#include "lib1896.h"
#include <cstring>
#include <algorithm>
using namespace std;

int c[1500];

void initialize(int n) {
  memset(c, 0, sizeof(c));
}

int hasEdge(int u, int v) {
  return ++c[max(u, v)] == max(u, v);
}
