#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, inf = 1e9 + 1;
int h[maxn], b[maxn], v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    deque<int> deq;
    int now = 0;
    int ans = -inf, bst = -1;
    for (int i = 1; i <= n; ++i) {
        while (deq.size() && i - deq.front() >= k) now -= b[deq.front()], deq.pop_front();
        while (deq.size() && h[i] >= h[deq.back()]) now -= b[deq.back()], deq.pop_back();
        now += b[i];
        if (now > ans) ans = now, bst = i;
        deq.push_back(i);
    } 
    cout << bst << ' ' << ans << endl;
    return 0;
}

