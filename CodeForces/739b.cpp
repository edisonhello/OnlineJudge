#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<pair<int, int>> T[maxn];
int a[maxn], ans[maxn];

multiset<long long>* dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        int p, w; cin >> p >> w;
        T[p].push_back(make_pair(i, w));
        T[i].push_back(make_pair(p, w));
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}

multiset<long long>* dfs(int x, int fa) {
    multiset<long long>* ret = new multiset<long long>();
    for (pair<int, int> e : T[x]) if (e.first != fa) {
        multiset<long long>* ch = dfs(e.first, x);
        for (multiset<long long>::iterator it = ch->begin(); it != ch->end(); ++it) {
            if (*it - e.second < 0) continue;
            ret->insert(*it - e.second);
        } 
        delete ch;
    }
    ans[x] = (int)ret->size();
    ret->insert(a[x]);
    return ret;
}
