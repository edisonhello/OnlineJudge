#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const int dx[] = { -1, 0, 1 };
pair<int, int> p[maxn];
int cov[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> m;
    set<pair<pair<int, int>, int>> s;
    for (int i = 0; i < m; ++i) {
        cin >> p[i].first >> p[i].second;
        s.insert(make_pair(p[i], i));
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < 3; ++i) {
             auto it = s.lower_bound(make_pair(make_pair(p[j].first + dx[i], p[j].second + 1), -1));
             if (it != s.end() && it->first.first == p[j].first + dx[i] && it->first.second == p[j].second + 1) {
                 ++cov[j];
             }
        }
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq2;
    for (int i = 0; i < m; ++i) if (cov[i] == 0) pq1.push(make_pair(i, p[i])), pq2.push(make_pair(i, p[i]));
    set<pair<pair<int, int>, int>> rem;
    for (int i = 0; i < m; ++i) if (cov[i]) rem.insert(make_pair(p[i], i));
    int cur = 0, cnt = 0;
    vector<int> ans;
    while (cnt < m) {
        ++cnt;
        if (cur == 0) {
            while (pq2.size() && v[pq2.top().first]) pq2.pop();
            auto c = pq2.top(); pq2.pop();
            v[c.first] = true; ans.push_back(c.first);
            cout << c.first << endl;
            for (int i = 0; i < 3; ++i) {
                auto it = rem.lower_bound(make_pair(make_pair(p[c.first].first + dx[i], p[c.first].second - 1), -1));
                if (it != rem.end() && it->first.first == p[c.first].first + dx[i] && it->first.second == p[c.first].second - 1) {
                    --cov[it->second];
                    if (cov[it->second] == 0) pq1.push(make_pair(it->second, p[it->second])), pq2.push(make_pair(it->second, p[it->second])), rem.erase(it);
                }
            }
        } else {
            while (pq1.size() && v[pq1.top().first]) pq1.pop();
            auto c = pq1.top(); pq1.pop();
            v[c.first] = true; ans.push_back(c.first);
            cout << c.first << endl;
            for (int i = 0; i < 3; ++i) {
                auto it = rem.lower_bound(make_pair(make_pair(p[c.first].first + dx[i], p[c.first].second - 1), -1));
                if (it != rem.end() && it->first.first == p[c.first].first + dx[i] && it->first.second == p[c.first].second - 1) {
                    --cov[it->second];
                    if (cov[it->second] == 0) pq1.push(make_pair(it->second, p[it->second])), pq2.push(make_pair(it->second, p[it->second])), rem.erase(it);
                }
            }
        }
        cur ^= 1;
    }
    long long fin = 0, mul = 1LL; reverse(ans.begin(), ans.end());
    for (int i : ans) {
        fin = (fin + (long long)i * mul % mod) % mod;
        mul = mul * m % mod;
    }
    cout << fin << endl;
    return 0;
}
