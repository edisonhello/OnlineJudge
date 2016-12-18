#include <cstdio>
#include <cstring>
#include <vector>
#define getchar getchar_unlocked
#define MAX 2000000 + 5
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

int T, N, M, a, K, A, B, C;
int pre[MAX], nxt[MAX];
long long ans;
vector<int> got;
void insert1(int, int);
void insert2(int, int);
void shuffle(int, int, int);
int send1(int, int);
int send2(int, int);

int main() {
  rit(T);
  while (T--) {
    rit(N, M, a); ans = 0; got.clear();
    memset(pre, 0, sizeof(pre));
    memset(nxt, 0, sizeof(nxt));
    while (M--) {
      rit(K, A, B, C);
      if (K == 1) {
        if (C == 1) insert1(A, B);
        if (C == 2) insert2(A, B);
      }
      if (K == 2) shuffle(A, B, C);
      if (K == 3) {
        if (C == 1) ans += send1(A, B);
        if (C == 2) ans += send2(A, B);
      }
    }
    printf("%lld\n", ans);
    for (int i : got) printf("%d\n", i);
  }
  return 0;
}

void insert1(int A, int B) {
  nxt[A] = B; pre[A] = pre[B];
  nxt[pre[B]] = A;
  pre[B] = A;
}

void insert2(int A, int B) {
  pre[nxt[B]] = A;
  nxt[A] = nxt[B];
  nxt[B] = A;
  pre[A] = B;
}

void shuffle(int A, int B, int C) {
  nxt[pre[A]] = nxt[B];
  pre[nxt[B]] = pre[A];
  pre[A] = pre[C];
  nxt[pre[A]] = A;
  nxt[B] = C;
  pre[C] = B;
}

int send1(int A, int B) {
  int cur = A, ret = 0;
  while (cur && ret < B) {
    got.push_back(cur);
    ret++; cur = pre[cur];
  }
  nxt[cur] = nxt[A];
  pre[nxt[A]] = cur;
  return B - ret;
}

int send2(int A, int B) {
  int cur = A, ret = 0;
  while (cur && ret < B) {
    got.push_back(cur);
    ret++; cur = nxt[cur];
  }
  pre[cur] = pre[A];
  nxt[pre[A]] = cur;
  return B - ret;
}
