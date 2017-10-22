#include <bits/stdc++.h>
using namespace std;

string rotate(const string &s, int &ans) {
    int n = s.length();
    string t = s + s;
    int i = 0, j = 1;
    while (i < n && j < n) {
        int k = 0; 
        while (k < n && s[i + k] == s[j + k]) ++k;
        if (s[i + k] <= s[j + k]) j += k + 1;
        else i += k + 1;
        if (i == j) ++j;
    }
    int pos = (i < n ? i : j);
    ans = pos;
    return s.substr(pos, n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int ans = 0;
    rotate(s, ans);
    cout << ans << endl;
    return 0;
}
