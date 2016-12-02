#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#define getchar getchar_unlocked
#define int long long
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

int a[40005], N, Q, lim, cnt[40005], li[40005], ans[400005], ANS, idl[40005];
unordered_map<int, int> mp;
const int MOD = 1000000007;

struct Q {
  int L, R, i, block;
  bool operator<(const Q& q) const {
    return block == q.block ? R < q.R : block < q.block;
  }
} query[400005];

void add(int);
void del(int);
int gid(int);

signed main() {
  rit(N, Q); lim = 1 + (int)sqrt(N);
  for (int i = 0; i < N; ++i) {
    rit(a[i]);
    int id = gid(a[i]);
    idl[i] = id;
  }
  for (int i = 0; i < Q; ++i) {
    rit(query[i].L, query[i].R);
    query[i].R--;
    query[i].i = i;
    query[i].block = query[i].L / lim;
  }
  sort(query, query + Q);
  for (int i = 0, L = 1, R = 0; i < Q; ++i) {
    while (R < query[i].R) add(++R);
    while (R > query[i].R) del(R--);
    while (L > query[i].L) add(--L);
    while (L < query[i].L) del(L++);
    ans[query[i].i] = ANS;
  }
  for (int i = 0; i < Q; ++i) printf("%lld\n", ans[i]);
  return 0;
}

void add(int num) {
  cnt[idl[num]]++;
  ANS += a[num] * ((cnt[idl[num]] << 1) - 1);
  ANS = (ANS % MOD + MOD) % MOD;
}

void del(int num) {
  cnt[idl[num]]--;
  ANS -= a[num] * (((cnt[idl[num]]) << 1) + 1);
  ANS = (ANS % MOD + MOD) % MOD;
}

int gid(int n) {
  auto it = mp.find(n);
  if (it == mp.end()) mp[n] = mp.size();
  return mp[n];
}
