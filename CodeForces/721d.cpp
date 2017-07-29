#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, x; cin >> n >> k >> x;
    int neg = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) ++neg;
    }
    if (neg & 1) {
       priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> ne;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> po;
       for (int i = 0; i < n; ++i) {
           if (a[i] > 0) po.push(make_pair(a[i], i));
           else ne.push(make_pair(a[i], i));
       }
       while (k--) {
           if (abs(po.top().first) < abs(ne.top().first)) {
               int ind = po.top().second; po.pop();
               a[ind] += x; po.push(make_pair(a[ind], ind));
           } else {
               int ind = ne.top().second; ne.pop();
               a[ind] -= x; ne.push(make_pair(a[ind], ind));
           }
       }
    } else {
        multiset<pair<int, int>> ms;
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 0) ms.insert(make_pair(a[i], i));
        }
        int cnt = 0;
        while (cnt < k) {
            auto it = ms.begin();
            if (it->first < 0) break;
            a[it->second] = it->first - x;
            ms.erase(ms.find(*it));
            ms.insert(make_pair(a[it->second], it->second));
            ++cnt;
        } 
        k -= cnt;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> ne;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> po;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) po.push(make_pair(a[i], i));
            else ne.push(make_pair(a[i], i));
        }
        while (k--) {
            if (abs(po.top().first) < abs(ne.top().first)) {
                int ind = po.top().second; po.pop();
                a[ind] += x; po.push(make_pair(a[ind], ind));
             } else {
                int ind = ne.top().second; ne.pop();
                a[ind] -= x; ne.push(make_pair(a[ind], ind));
            }
        } 
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}
