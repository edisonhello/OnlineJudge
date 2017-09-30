#include <bits/stdc++.h>
using namespace std;
template <typename T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;

const int maxn = 1e6 + 10;
int a[maxn];
vector<int> v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    MinHeap<int> pq;
    for (int i = 0; i < m; ++i) pq.push(0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = pq.top(); pq.pop();
        ans = max(ans, k + a[i]);
        pq.push(k + a[i]);
    }
    cout << ans << endl;
    return 0;
}
