#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<pair<int, bool>> G[maxn];
long long ans = 0, dp[maxn];
bool b[maxn];

bool check(int t) {
    stringstream ss; ss << t;
    string s; ss >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '7' && s[i] != '4') return false;
    }
    return true;
}

void dfs(int now, int fa, bool lucky) {
    b[now] = lucky;
    for (auto u : G[now]) if (u.first != fa) {
        dfs(u.first, now, lucky | u.second);
        dp[now] += dp[u.first];
        if (u.second) ++dp[now];
    }
    for (auto u : G[now]) if (u.first != fa) {
        int k = (u.second ? dp[u.first] + 1 : dp[u.first]);
        ans += (long long)k * (dp[now] - k);
    }
    if (lucky) ans += dp[now];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; cin >> a >> b >>c;
        bool d = check(c);
        G[a].push_back(make_pair(b, d)); G[b].push_back(make_pair(a, d));
    }
    dfs(1, 0, false);
    cout << ans << endl;
}
