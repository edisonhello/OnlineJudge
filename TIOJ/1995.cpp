#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;

const int maxn = 25e5 + 10, maxm = 1e6 + 10;
int ans[maxm];

struct Int {
    bitset<24> dig;
    Int(int n) {
        for (int i = 23; i >= 0; --i) {
            if (n >= 1 << i) dig[i] = 1, n -= (1 << i);
            else dig[i] = 0;
        }
    }
    int convert() {
        int ret = 0;
        for (int i = 0; i < 24; ++i) ret += dig[i] * (1 << i);
        return ret;
    }
    Int operator+(const Int& n) const {
        return Int(convert() + n.convert());
    }
    bool operator>(const Int& n) const {
        return convert() > n.convert();
    }
    bool operator<(const Int& n) const {
        return convert() < n.convert();
    }
    bool operator<(const int& n) const {
        return *this < Int(n);
    }
    bool operator>(const int& n) const {
        return *this > Int(n);
    }
    Int& operator=(const Int& n) const {
        dig = n.dig;
    }
};

pair<pair<Int, Int>, Int> qry[maxm];

struct fenwick {
    int arr[maxn];
    inline Int lowbit(Int x) {
        return x & -x;
    }
    void add(Int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] = max(arr[i], v);
    }
    int qry(Int x) {
        Int ret = Int(0);
        for (int i = x; i; i -= lowbit(i)) ret = max(ret, arr[i]);
        return ret;
    }
} bit;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        qry[i] = make_pair(make_pair(l, r), i);
    }
    sort(qry, qry + m, [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.first.second < b.first.second;        
    });
    int ind = 1;
    for (int i = 0; i < m; ++i) {
        auto q = qry[i];
        while (ind <= n && ind <= q.first.second) {
            int s; scanf("%d", &s);
            bit.add(n - ind + 1, s);
            ++ind;
        }
         = bit.qry(n - q.first.first + 1);
        bit.add(n - q.first.second, )
    }
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    return 0;
}
