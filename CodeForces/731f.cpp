#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], sum[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], v[a[i]] = true;
    for (int i = 0; i < n; ++i) {
        int ptr = 1;
        vector<int> vec;
        for (int j = 1; j <= a[i]; j = a[i] / (a[i] / (j + 1))) {
            vec.push_back(j);
            if (j + 1 >= a[i]) break;
        }
        reverse(vec.begin(), vec.end());
        for (int j : vec) {
            int cur = a[i] / j;
            sum[ptr] += j; sum[cur + 1] -= j;
            ptr = cur + 1;
        }
    }
    int s = 0;
    long long ans = 0;
    for (int i = 0; i < maxn; ++i) {
        s += sum[i];
        if (!v[i]) continue;
        ans = max(ans, (long long)i * (long long)s);
    }
    cout << ans << endl;
    return 0;
}
