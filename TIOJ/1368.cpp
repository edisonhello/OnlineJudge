#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
pair<int,int> a[maxn];
int s[maxn];

int32_t main() {
    int n; while (cin >> n) {
        memset(s,0,sizeof(s));
        for(int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i, s[i] = s[i - 1] + a[i].first;
        set<int> st; st.insert(0); st.insert(n + 1);
        sort(a + 1, a + n + 1);
        int ans = 0;
        int l = 0, r = 0;
        for (int i = 1; i <= n; ++i) {
            auto it = st.lower_bound(a[i].second);
            int cur = a[i].first * (s[*it - 1] - s[*(--it)]);
            if (cur > ans) ans = cur, l = *(it) + 1,r = *(++it) - 1;
            st.insert(a[i].second);
        }
        cout << ans << endl;
        cout << l << ' ' << r << endl;
    }
    return 0;
}
