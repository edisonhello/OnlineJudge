#include "lib1965.h"
#include <algorithm>
using namespace std;

const int maxn = 1e7 + 10;
int *size, *lm, block, nblock;
uint64_t ***st, **stt, *c;

inline void doo();
inline void initSt(int, int, int);
inline void initStt(int, int);
inline uint64_t rmq(int, int, int);
inline uint64_t rmqq(int, int);

void init(int N, uint64_t C[]) {
    c = C;
    int cnt = 0;
    block = 31 - __builtin_clz(N); 
    if ((1 << block) < N) ++block;
    ++block;
    nblock = ceil((double)N / block) + 2;
    doo();
    cnt = 0;
    for (int i = 0; i < N; ) {
        int sz = min(N - i + 1, block);
        initSt(cnt, i, i + sz - 1);
        size[cnt] = sz;
        lm[cnt] = i;
        i += sz; ++cnt;
    }
    initStt(0, cnt - 1);
}

uint64_t RMQ(int a, int b) {
    --b;
    if (a == b) return c[a];
    int lb = a / block, rb = b / block;
    if (lb == rb) return rmq(lb, a - lm[lb], b - lm[lb]);
    uint64_t q1 = rmq(lb, a - lm[lb], size[lb] - 1), q2 = rmq(rb, 0, b - lm[rb]);
    return max({ q1, q2, rmqq(lb + 1, rb - 1) });
}

inline void doo() {
    int lg = 31 - __builtin_clz(block);
    if ((1 << lg) < block) ++lg;
    st = new uint64_t**[lg];
    for (int i = 0; i < lg; ++i) st[i] = new uint64_t*[block];
    for (int i = 0; i < lg; ++i) {
        for (int j = 0; j < block; ++j) st[i][j] = new uint64_t[nblock];
    }
    int lglg = 31 - __builtin_clz(nblock);
    if ((1 << lglg) < nblock) ++lglg;
    stt = new uint64_t*[lglg];
    for (int i = 0; i < lglg; ++i) stt[i] = new uint64_t[nblock];
    lm = new int[nblock]; size = new int[nblock];
}

inline void initSt(int id, int l, int r) {
    int len = r - l + 1;
    for (int i = 0; i < len; ++i) st[0][i][id] = c[l + i];
    for (int i = 1; (1 << i) <= len; ++i) {
        for (int j = 0; j + (1 << i) <= len; ++j) {
            st[i][j][id] = max(st[i - 1][j][id], st[i - 1][j + (1 << (i - 1))][id]);
        }
    }
}

inline uint64_t rmq(int id, int l, int r) {
    int p = 31 - __builtin_clz(r - l + 1);  
    return max(st[p][l][id], st[p][r - (1 << p) + 1][id]);
}

inline void initStt(int l, int r) {
    int len = r - l + 1;
    for (int i = 0; i < len; ++i) stt[0][i] = rmq(i, 0, size[i] - 1);
    for (int i = 1; (1 << i) <= len; ++i) {
        for (int j = 0; j + (1 << i) <= len; ++j) {
            stt[i][j] = max(stt[i - 1][j], stt[i - 1][j + (1 << (i - 1))]);
        }
    }
}

inline uint64_t rmqq(int l, int r) {
    if (l > r) return 0;
    int p = 31 - __builtin_clz(r - l + 1);
    return max(stt[p][l], stt[p][r - (1 << p) + 1]);
}
