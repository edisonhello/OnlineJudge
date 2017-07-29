#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool gd[1000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string g; cin >> g;
    for (int i = 0; i < g.length(); ++i) gd[g[i]] = true;
    string s; cin >> s;
    int n; cin >> n;
    int pos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '*') {
            pos = i; break;
        }
    }
    while (n--) {
        string t; cin >> t;
        if (pos == -1) {
        if (t.length() != s.length()) { cout << "NO" << endl; continue; }
        string cp = s;
        vector<int> q;
        for (int i = 0; i < s.length(); ++i) if (s[i] == '?') q.push_back(i);
        bool ans = true;
        for (int i : q) {
            if (gd[t[i] ]) cp[i] = t[i];
            else ans = false;
        }
        if (!ans) cout << "NO" << endl;
        else {
            if (cp == t) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    } else {
        vector<int> l, r;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '?' && i < pos) l.push_back(i);
            else if (s[i] == '?') r.push_back(i - pos);
        }
        bool ans = true;
        string ret = ""; int ind = 0;
        for (int i = 0; i < pos; ++i) {
            if (ind < l.size() && l[ind] == i) {
                if (gd[t[i]]) ret += t[i];
                else ans = false;
            } else ret += s[i];
        }
        ind = 0;
        int len = t.length() - s.length() + 1;
        for (int i = 0; i < len; ++i) {
            if (gd[t[pos + i]]) ans = false;
            else ret += t[pos+ i];
        }
        if (len < 0) ans = false;
        for (int i = 1; pos + i < s.length(); ++i) {
            if (ind < r.size() && r[ind] == i) {
                if (gd[t[len + i + pos]]) ret += t[len + i + pos];
                else ans = false;
            } else {
                ret += s[pos + i];
            }
        }
        if (!ans) cout << "NO" << endl;
        else {
            if (ret == t) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    }
        return 0;
}
