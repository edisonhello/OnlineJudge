#include <bits/stdc++.h>
#include "lib1965.h"
using namespace std;

const int maxn = 1e7 + 10, block = 25;
uint64_t st[420000][5][25], sst[20][420000];
int sz[420000];

uint64_t rmq(int id, int l, int r) {
    int p = 31 - __builtin_clz(r - l);
    return max(st[id][p][l], st[id][p][r - (1 << p)]);
}

void init(int N, uint64_t C[]) {
    int ind = 0, cnt = 0;
    while (ind < N) {
        int size = min(N - ind, block);
        for (int i = 0; i < size; ++i) st[cnt][0][i] = C[ind + i];
        for (int i = 1; (1 << i) <= size; ++i) {
            for (int j = 0; j + (1 << i) <= size; ++j) {
                st[cnt][i][j] = max(st[cnt][i - 1][j], st[cnt][i - 1][j + (1 << (i - 1))]);
            }
        }
        sz[cnt] = size;
        ind += size;
        ++cnt;
    }
    for (int i = 0; i < cnt; ++i) sst[0][i] = rmq(i, 0, sz[i]);
    for (int i = 1; (1 << i) <= cnt; ++i) {
        for (int j = 0; j + (1 << i) <= cnt; ++j) {
            sst[i][j] = max(sst[i - 1][j], sst[i - 1][j + (1 << (i - 1))]);
        }
    }
}

uint64_t RMQ(int a, int b) {
    int l = (int)ceil(double(a) / (double)block), r = b / block;
    cerr << l << ' ' << r << '\n';
    int p = 31 - __builtin_clz(r - l);
    uint64_t ret = max(sst[p][l], sst[p][r - (1 << p)]);
    // if (l - 1 >= 0) ret = max(ret, rmq(l - 1, a % block))
    ret = max({ ret, rmq(l, a % block, sz[l]), rmq(r, 0, b % block + 1) });
    return ret;
}

