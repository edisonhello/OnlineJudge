#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int sum;
    bool tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = 0; tag = false;
        if (L == R) return;
    }
} st[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;

}
