#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
map<string, int> cnt, ind, outd;
string s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        ++cnt[s[i].substr(0, 2)]; ++cnt[s[i].substr(1, 2)];
    }
    for (int i = 0; i < n; ++i) {
        ind[s[i]] += cnt[s[i].substr(0, 2)] - 1; outd[s[i]] += cnt[s[i].substr(1, 2)] - 1;
    }
    bool ans = true;
    for (auto i = ind.begin(); i != ind.end(); ++i) {
        // cout << i->first << ' ' << i->second << ' ' << outd[i->first] << endl;
        if (i->second != outd[i->first]) ans = false;
        if (i->second == 0 && outd[i->first] == 0) return cout << "NO" << endl, 0;
    }
    if (ans) return cout << "YES" << endl, 0;
    string a = "", b = "";
    for (auto i = ind.begin(); i != ind.end(); ++i) {
        if (i->second == outd[i->first]) continue;
        if (i->second == outd[i->first] + 1) {
            if (a == "") a = i->first;
            else return cout << "NO" << endl, 0;
        } else if (i->second + 1 == outd[i->first]) {
            if (b == "") b = i->first;
            else return cout << "NO" << endl, 0;
        } else return cout << "NO" << endl, 0;
    }
    if (a != "" && b == "" || b != "" && a == "") return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    cout << a << ' ' << b << endl; 
    return 0;
}
