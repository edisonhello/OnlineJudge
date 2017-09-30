#include <bits/stdc++.h>
#define int long long
using namespace std;

unordered_set<int> st[33];

vector<int> parse(const string& s) {
    vector<pair<int, int>> pos;
    int p = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.') {
            pos.push_back(make_pair(p, i - 1));
            p = i + 1;
        }
        if (s[i] == '/') {
            pos.push_back(make_pair(p, i - 1));
            p = i + 1;
            break;
        }
    }
    pos.push_back(make_pair(p, s.length() - 1));
    vector<int> ret;
    for (auto i : pos) {
        int k = 0;
        for (int j = i.first; j <= i.second; ++j) {
            k = k * 10 + s[j] - '0';
        }
        vector<int> cc;
        int cnt = 0;
        while (k) {
            int c = k % 2;
            cc.push_back(c);
            k >>= 1;
            ++cnt;
        }
        cnt = 8 - cnt; while (cnt--) cc.push_back(0);
        reverse(cc.begin(), cc.end());
        for (int ccc : cc) ret.push_back(ccc);
    }
    return ret;
}

void init(const string& s) {
    vector<pair<int, int>> pos;
    int p = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '.') {
            pos.push_back(make_pair(p, i - 1));
            p = i + 1;
        }
        if (s[i] == '/') {
            pos.push_back(make_pair(p, i - 1));
            p = i + 1;
            break;
        }
    }
    vector<int> ret;
    for (auto i : pos) {
        int k = 0;
        for (int j = i.first; j <= i.second; ++j) {
            k = k * 10 + s[j] - '0';
        }
        vector<int> cc;
        int cnt = 0;
        while (k) {
            int c = k % 2;
            cc.push_back(c);
            k >>= 1;
            ++cnt;
        }
        cnt = 8 - cnt; while (cnt--) cc.push_back(0);
        reverse(cc.begin(), cc.end());
        for (int ccc : cc) ret.push_back(ccc);
    }
    int k = 0;
    for (int j = p; j < s.length(); ++j) {
        k = k * 10 + s[j] - '0';
    }
    int n = k;
    int cur = 0;
    for (int i = 0; i < ret.size(); ++i) {
        cur = cur * 2 + ret[i];
        if (i + 1 == n) st[i + 1].insert(cur);
        if (i + 1 > n) break;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m, n; cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        init(s);
    }
    for (int i = 0; i < n ; ++i) {
        string s; cin >> s;
        vector<int> v = parse(s);
        bool ans = false;
        int cur = 0;
        for (int i = 0; i < v.size() && !ans && i < 32; ++i) {
            cur = cur * 2 + v[i];
            if (st[i + 1].count(cur)) ans = true;
        }
        if (ans) cout << "TRUE\n";
        else cout << "FALSE\n";
    }
    return 0;
}
