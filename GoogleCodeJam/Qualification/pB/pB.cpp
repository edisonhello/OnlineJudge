#include <bits/stdc++.h>
using namespace std;

int tidy(const string&);
string trim(const string&);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int T; cin >> T; while (T--) {
        string s; cin >> s;
        cout << "Case #" << ++kase << ": ";
        while (true) {
            int t = tidy(s);
            if (t == -1) break;
            for (int i = t + 1; i < s.length(); ++i) s[i] = '9';
            s[t]--;
        }
        cout << trim(s) << '\n';
    }
    return 0;
}

int tidy(const string& s) {
    for (int i = 0; i < s.length() - 1; ++i) {
        if (s[i] > s[i + 1]) return i;
    }
    return -1;
}

string trim(const string& s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '0') return s.substr(i, s.length() - i);
    }
    return "0";
}
