#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; int k; while (cin >> k >> s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (i + k >= s.length()) break;
            if (s.substr(i, k) == s.substr(i + k, k)) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
