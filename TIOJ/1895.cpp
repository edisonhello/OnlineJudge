#include "lib1895.h"
#include <algorithm>
using namespace std;

inline int Lc(int id) { return id * 2; }
inline int Rc(int id) { return id * 2 + 1; }

const int N = 2000000 + 5;
const int INF = (1 << 30);
int up[N * 4], low[N * 4];
void modify(int, int, int, int, int, int, int);
void push(int);
void add(int, int);
void del(int, int);
void ans(int, int, int, int*);

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
  for (int i = 0; i < N * 4; ++i) up[i] = INF, low[i] = 0;
  for (int i = 0; i < k; ++i) modify(1, 0, n - 1, op[i], left[i], right[i], height[i]);
  ans(1, 0, n - 1, finalHeight);
}

void modify(int id, int L, int R, int op, int left, int right, int height) {
  if (L > right || R < left) return;
  if (L >= left && R <= right) {
    if (op == 1) add(id, height);
    if (op == 2) del(id, height);
    return;
  }
  int M = (L + R) >> 1;
  push(id);
  modify(Lc(id), L, M, op, left, right, height); modify(Rc(id), M + 1, R, op, left, right, height);
}

void push(int id) {
  if (up[id] == -1) {
    up[Lc(id)] = up[Rc(id)] = -1;
    low[Lc(id)] = low[Rc(id)] = low[id];
    up[id] = INF; low[id] = 0;
    return;
  }
  if (low[id] != 0) add(Lc(id), low[id]), add(Rc(id), low[id]);
  if (up[id] != INF) del(Lc(id), up[id]), del(Rc(id), up[id]);
  low[id] = 0; up[id] = INF;
}

void add(int id, int height) {
  if (up[id] == -1) low[id] = max(low[id], height);
  else if (height >= up[id]) low[id] = height, up[id] = -1;
  else if (height >= low[id]) low[id] = height;
}

void del(int id, int height) {
  if (up[id] == -1) low[id] = min(low[id], height);
  else if (height <= low[id]) low[id] = height, up[id] = -1;
  else if (height <= up[id]) up[id] = height;
}

void ans(int id, int L, int R, int* answer) {
  if (L == R) { answer[L] = low[id]; return; }
  push(id);
  int M = (L + R) >> 1;
  ans(Lc(id), L, M, answer); ans(Rc(id), M + 1, R, answer);
}
