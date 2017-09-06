#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<pair<int, int>> x, y;
vector<int> yg[maxn << 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, w, h; cin >> n >> w >> h;
    for (int i = 0; i < n; ++i) {
        int g, p, t; cin >> g >> p >> t;
        if (g == 1) x.push_back(make_pair(make_pair(p, t), i));
        else y.push_back(make_pair(make_pair(p, t), i));
    }
    sort(y.begin(), y.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) { return a.first.first - a.first.second < b.first.first - b.first.second; });
    sort(x.begin(), x.end());
    for (int i = 0; i < y.size(); ) {
        int j = i;
        while (j < y.size() && y[j].first.first - y[j].first.second == y[i].first.first - y[i].first.second) {
            yg[y[i].first.first - y[i].first.first + maxn].push_back(y[j].second);
            ++j;
        }
    }
    for (auto i : x) {
        
    }
}
