#include <iostream>
#include <cstring>
#define Lc(id) (id) << 1
#define Rc(id) (id) << 1 | 1
#define root 1
#define LR(L, R) cout << "L: " << (L) << " R: " << (R) << '\n'
using namespace std;

const int maxn = 100000 + 5;
int N, L, R, H, T, ans;
bool mod[maxn << 2];

struct Seg {
  int h, tag;
} seg[maxn << 2];

void modify(int, int, int, int, int, int);
void push(int, int, int, bool);
void pull(int);
void print(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  while (T--) {
    memset(seg, 0, sizeof(seg)); ans = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> L >> R >> H;
      memset(mod, false, sizeof(mod));
      modify(root, 1, maxn, L, R, H);
      print(root, 1, 15);
      cout << '\n';
      cout << ans << '\n';
    }
    cout << ans << '\n';
  }
  return 0;
}

void modify(int id, int L, int R, int l, int r, int h) {
  if (L > r || l > R) return;
  if (L >= l && R <= r) {
    if (h > seg[id].h) LR(L, R), ans += (R - L + 1), mod[id] = true;
    seg[id].h = max(seg[id].h, h);
    seg[id].tag = max(seg[id].tag, h);
    return;
  }
  push(id, L, R, mod[id]);
  int M = (L + R) >> 1;
  modify(Lc(id), L, M, l, r, h);
  modify(Rc(id), M + 1, R, l, r, h);
  pull(id);
}

void push(int id, int L, int R, bool md) {
  int M = (L + R) >> 1;
  if (!md) {
    if (seg[id].tag > seg[Lc(id)].h) LR(L, M), ans += (M - L + 1), mod[Lc(id)] = true;
    if (seg[id].tag > seg[Rc(id)].h) LR(M + 1, R), ans += (R - M), mod[Rc(id)] = true;
  } else {
    mod[Lc(id)] = mod[Rc(id)] = true;
  }
  seg[Lc(id)].h = max(seg[Lc(id)].h, seg[id].tag); seg[Lc(id)].tag = max(seg[Lc(id)].tag, seg[id].tag);
  seg[Rc(id)].h = max(seg[Rc(id)].h, seg[id].tag); seg[Rc(id)].tag = max(seg[Rc(id)].tag, seg[id].tag);
  seg[id].tag = 0;
}

void pull(int id) {
  seg[id].h = max(seg[Lc(id)].h, seg[Rc(id)].h);
}

void print(int id, int L, int R) {
  push(id, L, R, mod[id]);
  if (L == R) { cout << seg[id].h << ' '; return; }
  int M = (L + R) >> 1;
  print(Lc(id), L, M);
  print(Rc(id), M + 1, R);
}
