#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #define getchar gtx
using namespace std;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 1e5 + 10;
const int inf = 1e9 + 1;
int l[maxn], r[maxn], u[maxn], d[maxn], w[maxn], val[maxn << 1];

struct Seg {
    Seg *lc, *rc;
    int sum, tag;
#define M ((L + R) >> 1)
    Seg(int L, int R) {
        lc = rc = nullptr;
        sum = 0; tag = 0;
        if (L == R) {
            sum = val[L];
            return;
        }
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
        pull();
    }
    void modify(int L, int R, int l, int r, long long v) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum += v;
            tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    void pull() {
        sum = max(lc->sum, rc->sum);
    }
    void push() {
        if (!lc) return;
        if (!tag) return;
        lc->sum += tag; lc->tag += tag;
        rc->sum += tag; rc->tag += tag;
        tag = 0;
    }
    int query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return -inf;
        if (L >= l && R <= r) return sum;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n; rit(n);
    vector<pair<pair<int, int>, int>> vec;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; rit(x1, y1, x2, y2, w[i]);
        l[i] = min(x1, x2), r[i] = max(x1, x2);
        u[i] = min(y1, y2), d[i] = max(y1, y2);
        v.push_back(u[i]); v.push_back(d[i]);
        vec.push_back(make_pair(make_pair(l[i], i), 1));
        vec.push_back(make_pair(make_pair(r[i], i), -1));
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    sort(vec.begin(), vec.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return a.first.first != b.first.first ? a.first.first < b.first.first : a.second > b.second;
    });
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(v.begin(), v.end(), u[i]) - v.begin(), r = lower_bound(v.begin(), v.end(), d[i]) - v.begin();
        val[l] += w[i], val[r + 1] -= w[i];
    }
    for (int i = 1; i <= v.size(); ++i) val[i] += val[i - 1];
    st = new Seg(0, v.size() - 1);
    int cur = 0, ans = 0;
    for (auto e : vec) {
        if (e.second == 1) {
            cur += w[e.first.second];
            int l = lower_bound(v.begin(), v.end(), u[e.first.second]) - v.begin(), r = lower_bound(v.begin(), v.end(), d[e.first.second]) - v.begin();
            st->modify(0, v.size() - 1, l, r, -w[e.first.second]);
        } else {
            cur -= w[e.first.second];
            int l = lower_bound(v.begin(), v.end(), u[e.first.second]) - v.begin(), r = lower_bound(v.begin(), v.end(), d[e.first.second]) - v.begin();
            st->modify(0, v.size() - 1, l, r, w[e.first.second]);
        }
        ans = max(ans, cur + st->query(0, v.size() - 1, 0, v.size() - 1));
    }
    cout << ans << endl;
    return 0;
}
