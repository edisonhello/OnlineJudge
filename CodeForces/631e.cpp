#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
typedef long long ll;
const ll inf = 1e18 + 1;
ll a[maxn], s[maxn], dp[2][maxn];

bool check(const pair<ll, ll>& a, const pair<ll, ll>& b, ll now) {
    return a.first * now + a.second <= b.first * now + b.second;
}

bool elim(const pair<ll, ll>& a, const pair<ll, ll>& b, const pair<ll, ll>& c) {
    return (double)(b.second - a.second) / (double)(a.first - b.first) <= (double)(b.second - c.second) / (double)(c.first - b.first);
}

pair<ll, ll> bs(const vector<pair<ll, ll>>& ch, ll now) {
    if (ch.size() == 0) return make_pair(-inf, -inf);
    if (ch.size() == 1) return ch[0];
    int d = 1, pos = 0; while (d < ch.size()) d <<= 1;
    while (d >>= 1) if (pos + d + 1 < ch.size()) if (check(ch[pos + d], ch[pos + d + 1], now)) pos += d;
    return ch[pos];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // for (int i = 1; i <= n; ++i) ls[i] = ls[i - 1] + a[i] * (i - 1);
    // for (int i = 1; i <= n; ++i) rs[i] = rs[i - 1] + a[i] * (i + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
    vector<pair<ll, ll>> ch; // ch.insert(make_pair(0, 0));
    for (int i = 1; i <= n; ++i) {
        // while (ch.size() >= 2) {
            // auto it = ch.begin(); ++it;
            // if (check(*ch.begin(), *it, i)) ch.erase(ch.begin());
            // else break;
        // }
        // if (ch.size()) {
        while (ch.size() >= 2 && elim(ch[ch.size() - 1], ch[ch.size() - 2], make_pair(a[i], -a[i] * i + s[i]))) ch.pop_back();
        ch.push_back(make_pair(a[i], -a[i] * i + s[i]));
        pair<ll, ll> ln = bs(ch, i);
        if (ln.first == -inf) dp[0][i] = 0;
        else dp[0][i] = -s[i] + ln.first * i + ln.second;
            // cout << "line: " << ln.first << ' ' << ln.second << endl;
            // cout << "dp[0][i] = " << dp[0][i] << endl;
        // }
        /* auto it = ch.lower_bound(make_pair(a[i], -a[i] * i + s[i]));
        if (*it == make_pair(a[i], -a[i] * i + s[i])) ++it;
        while (it != ch.end()) {
            auto itt = it;
            ++itt;
            // cout << it->first << ' ' << it->second << ' ' << itt->first << ' ' << itt->second << endl;
            if (itt != ch.end() && elim(*it, *itt, make_pair(a[i], -a[i] * i + s[i]))) ch.erase(it), it = itt;
            else break;
        } */
    }
    ch.clear(); // ch.insert(make_pair(0, 0));
    for (int i = n; i >= 1; --i) {
        /* while (ch.size() >= 2) {
            auto it = ch.begin(); ++it;
            if (check(*ch.begin(), *it, i)) ch.erase(ch.begin());
            else break;
        } */
        // while (dq.size() >= 2 && check(dq[0], dq[1], i)) dq.pop_front();
        // if (ch.size()) {
        while (ch.size() >= 2 && elim(ch[ch.size() - 1], ch[ch.size() - 2], make_pair(a[i], s[i - 1] - a[i] * i))) ch.pop_back();
        ch.push_back(make_pair(a[i], s[i - 1] - a[i] * i));
        pair<ll, ll> ln = bs(ch, i);
            // cout << ln.first << ' ' << ln.second << endl;
        if (ln.first == -inf) dp[1][i] = 0;
        else dp[1][i] = -s[i - 1] + ln.first * i + ln.second;
            // cout << "dp[1][i] = " << dp[1][i] << endl;
        // }
        /* auto it = ch.lower_bound(make_pair(a[i], s[i - 1] - a[i] * i));
        if (*it == make_pair(a[i], s[i - 1] - a[i] * i)) ++it;
        while (it != ch.end()) {
            auto itt = it;
            ++itt;
            // cout << it->first << ' ' << it->second << ' ' << itt->first << ' ' << itt->second << endl;
            if (itt != ch.end() && elim(*it, *itt, make_pair(a[i], s[i - 1] - a[i] * i))) ch.erase(it), it = itt;
            else break;
        } */
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, max(dp[0][i], dp[1][i]));
    for (int i = 1; i <= n; ++i) ans += a[i] * i;
    cout << ans << endl;
    return 0;
}
