#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int T; cin >> T; while (T--) {
        int k, ans = 0; string s; cin >> s >> k;
        bool osas = true;
        cout << "Case #" << ++kase << ": ";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '-') {
                ++ans;
                if (i + k > s.length()) { osas = false; break; }
                for (int j = i; j < i + k; ++j) {
                    if (s[j] == '-') s[j] = '+';
                    else s[j] = '-';
                }
            }
        }
        for (int i = 0; i < s.length(); ++i) if (s[i] == '-') osas = false;
        if (osas) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
