#include <bits/stdc++.h>
using namespace std;

struct Bath {
    int l, r;
    bool operator>(const Bath& rhs) const {
        int m1 = (l + r) >> 1, m2 = (rhs.l + rhs.r) >> 1;
        if (min(m1 - l, r - m1) != min(m2 - rhs.l, rhs.r - m2)) return min(m1 - l, r - m1) > min(m2 - rhs.l, rhs.r - m2);
        if (max(m1 - l, r - m1) != max(m2 - rhs.l, rhs.r - m2)) return max(m1 - l, r - m1) > max(m2 - rhs.l, rhs.r - m2);
        return m1 > m2;
    }
    bool operator<(const Bath& rhs) const {
        int m1 = (l + r) >> 1, m2 = (rhs.l + rhs.r) >> 1;
        if (min(m1 - l, r - m1) != min(m2 - rhs.l, rhs.r - m2)) return min(m1 - l, r - m1) < min(m2 - rhs.l, rhs.r - m2);
        if (max(m1 - l, r - m1) != max(m2 - rhs.l, rhs.r - m2)) return max(m1 - l, r - m1) < max(m2 - rhs.l, rhs.r - m2);
        return m1 < m2;
    }
};

const int maxn = 1000 + 5;
pair<int, int> ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, kase = 0; cin >> T; while (T--) {
        int n, k, cnt = 0; cin >> n >> k;
        priority_queue<Bath, vector<Bath>, less<Bath>> pq;
        pq.push((Bath){ 1, n });
        cout << "Case #" << ++kase << ": ";
        while (cnt < k) {
            Bath b = pq.top(); pq.pop();
            ++cnt;
            ans[cnt] = make_pair(max((b.l + b.r) / 2 - b.l, b.r - (b.l + b.r) / 2), min((b.l + b.r) / 2 - b.l, b.r - (b.l + b.r) / 2));
            pq.push((Bath){ b.l, (b.l + b.r) / 2 - 1 });
            pq.push((Bath){ (b.l + b.r) / 2 + 1, b.r });
        }
        for (int i = 0; i < k; ++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    return 0;
}
