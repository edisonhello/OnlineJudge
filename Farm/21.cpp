#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int i = 0, ans = 0;;
    for (int i = 0; i < s.length(); ++i) if (s[i] == 'C') ++ans;
    while (s[i] == '?') ++i;
    for (i; i < s.length(); ) {
        if (s[i] == '?') {
            int j = i - 1;
            while (i < s.length() && s[i] == '?') ++i;
            if (i == s.length()) break;
            if (s[i] == 'C' || s[j] == 'C') continue;
            if (s[i] != s[j]) {
                if ((i - j) % 2 == 0) ++ans;
            } else {
                if ((i - j) % 2 == 1) ++ans;
            }
        } else ++i;
    }
    cout << ans << endl;
    return 0;
}
