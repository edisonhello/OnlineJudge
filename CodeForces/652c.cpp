#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int p[maxn], pos[maxn];
pair<int, int> foe[maxn];
vector<int> id[maxn];
bool v[maxn];

struct cmp {
    bool operator()(const int& a, const int& b) {
        return max(pos[foe[a].first], pos[foe[a].second]) < max(pos[foe[b].first], pos[foe[b].second]);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
    for (int i = 0; i < m; ++i) {
        cin >> foe[i].first >> foe[i].second;
        id[foe[i].first].push_back(i); id[foe[i].second].push_back(i);
    }
    set<int, cmp> s;
    long long ans = 0;
    for (int i = 1, r = 0; i <= n; ++i) {
        // cout << "i = " << i << " r = " << r << endl;
        while (r <= n) {
            while (s.size() && v[*s.begin()]) s.erase(*s.begin());
            if (s.size() && r >= max(pos[foe[*s.begin()].first], pos[foe[*s.begin()].second])) break;
            // if (!s.size()) cout << "empty" << endl;
            // else cout << *s.begin() << endl;
            for (int j : id[p[r + 1]]) if (!v[j]) s.insert(j);
            ++r;
        }
        ans += r - i;
        cout << "i = " << i << " final_r = " << r << endl;
        for (int j : id[p[i]]) {
            if (s.find(j) != s.end()) v[j] = true;
            s.erase(j);
        }
    }
    cout << ans << endl;
    return 0;
}
