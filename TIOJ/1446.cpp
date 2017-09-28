#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
string s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n);
    int ans = s[0].size() + s[n - 1].length(), now = s[0].length() - 1;
    for (int i = 1; i < n; ++i) {
        int ind = 0;
        while (ind < s[i - 1].size() && ind < s[i].size() && s[i - 1][ind] == s[i][ind]) ++ind;
        --ind;
        ans += max(0, now - ind);
        ans += s[i].length() - ind;
        now = s[i].length() - 1;
    }
    cout << ++ans << endl;
    return 0;
}
