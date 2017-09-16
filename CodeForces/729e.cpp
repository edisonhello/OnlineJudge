#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    if (a[s] != 0) ++ans, a[s] = 0;
    vector<int> wa, ac;
    for (int i = 1; i <= n; ++i) {
        if (i != s && a[i] == 0) wa.push_back(i);
        else ac.push_back(i);
    }
    ans += (int)wa.size();
    sort(ac.begin(), ac.end(), [&](const int& i, const int& j) { return a[i] < a[j]; });
    vector<int> tle;
    int ind = 0;
    for (int i = 0; ind < ac.size(); ++i) {
        // cout << "i = " << i << endl;
        while (ind < ac.size()) {
            if (a[ac[ind]] <= i) {
                if (v[a[ac[ind]]]) tle.push_back(ac[ind]);
                v[a[ac[ind]]] = true;
            } else break;
            ++ind;
        }
        if (!v[i]) {
            if (wa.size()) wa.pop_back();
            else if (tle.size()) tle.pop_back(), ++ans;
            else ac.pop_back(), ++ans;
            v[i] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
