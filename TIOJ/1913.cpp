#include <iostream>
#include <algorithm>
#define Lc(x) (x)*2
#define Rc(x) (x)*2+1
using namespace std;

struct Node {
  int mn, mx, cnt;
};

Node seg[20005];
int S[5005], T, N;
void build(int, int, int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> S[i];
    build(0, N - 1, 1);
    cout << seg[1].cnt << endl;
  }
  return 0;
}

void build(int L, int R, int id) {
  if (L == R) {
    seg[id].mn = seg[id].mx = S[L];
    seg[id].cnt = 0;
    return;
  }
  int M = (L + R) >> 1;
  build(L, M, Lc(id)); build(M + 1, R, Rc(id));
  seg[id].mn = min(seg[Lc(id)].mn, seg[Rc(id)].mn);
  seg[id].mx = max(seg[Lc(id)].mx, seg[Rc(id)].mx);
  // seg[id].cnt = max(seg[Lc(id)].cnt, seg[Rc(id)].cnt);
  if (seg[Lc(id)].mn == seg[Rc(id)].mx + 1 || seg[Lc(id)].mx == seg[Rc(id)].mx + 1) seg[id].cnt = max(seg[id].cnt, seg[id].cnt);
  if (seg[Rc(id)].mn == seg[Lc(id)].mx + 1 || seg[Rc(id)].mx == seg[Lc(id)].mx + 1) seg[id].cnt++;
}
