#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 25e5 + 10, maxm = 1e6 + 10;
int l[maxm], r[maxm];
int a[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d %d", l + i, r + i), --l[i], --r[i];
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i) {
        if (r[i] - l[i] == 0) l[i] = a[l[i]], r[i] = -1;
    }
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            a[j] = max(a[j], a[j + (1 << (i - 1))]);
        }
        for (int j = 0; j < m; ++j) if (r[j] != -1) {
            int p = 31 - __builtin_clz(r[j] - l[j] + 1);
            if (p != i) continue;
            l[j] = max(a[l[j]], a[r[j] - (1 << p) + 1]);
            r[j] = -1;
        }
    }
    for (int i = 0; i < m; ++i) printf("%d\n", l[i]);
    return 0;
}
