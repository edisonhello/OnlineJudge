#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; while (cin >> s) {
        bool neg = false;
        if (s[0] == '-') neg = true, s = s.substr(1, s.length() - 1);
        if (s == "0") {
            cout << 0 << endl;
            continue;
        }
        reverse(s.begin(), s.end());
        int i = 0;
        if (neg) cout << "-";
        while (i < s.length() && s[i] == '0') ++i;
        for (; i < s.length(); ++i) cout << s[i]; cout << endl;
    }
    return 0;
}
