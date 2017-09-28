#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn], l[maxn], r[maxn];
bool v[maxn];

struct cmp {
    bool operator()(const pair<int, int>& i, const pair<int, int>& j) {
        return i.first == j.first ? a[i.second] > a[j.second] : i.first < j.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) l[i] = i - 1, r[i] = i + 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int ans = 0;
    for (int i = 1; i <= n; ++i) pq.push(make_pair(min(a[i - 1], a[i + 1]), i));
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (v[p.second]) continue;
        v[p.second] = true; ans += p.first;
        int ind = p.second;
        r[l[ind]] = r[ind];
        l[r[ind]] = l[ind];
        pq.push(make_pair(min(a[l[l[ind]]], a[r[l[ind]]]), l[ind]));
        pq.push(make_pair(min(a[l[r[ind]]], a[r[r[ind]]]), r[ind]));
    }
    cout << ans << endl;
    return 0;
}
