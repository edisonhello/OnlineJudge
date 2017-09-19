#include <bits/stdc++.h>
using namespace std;

int k, pos0, tot, n;
string ts;

int ask(const string& s) {
    ++tot;
    cout << "? " << s << endl;
    // int h = 0;
    // for (int i = 0; i < ts.length(); ++i) if (s[i] != ts[i]) ++h;
    int h; cin >> h;
    return h;
}

int bs(int l, int r, int now, int dt, string s) {
    // cout << "l = " << l << " r = " << r << " now = " << now << " dt = " << dt << endl;
    if (r - l == 1) return l;
    int m = (l + r) >> 1;
    // cout << "m = " << m << endl;
    string t = s;
    for (int i = l; i < r; ++i) t[i] = '0';
    for (int i = l; i < m; ++i) t[i] = '1';
    int h = ask(t); h -= dt;
    int len = m - l;
    int o = (h + now - len) / 2;
    // cout << "o = " << o << endl;
    if (o == 0) {
        pos0 = m;
        return bs(l, m, now - o, dt + o, t);
    } else if (o == now) {
        pos0 = l;
        return bs(m, r, o, dt + len - now + o, t);
    } else return bs(m, r, o, dt + len - now + o, t);
}

int cnt[2];

int main() {
    srand(time(nullptr));
    cin >> n;
    // for (int i = 0; i < n; ++i) {
        // int r = rand() % 2;
        // cnt[r] = true;
        // ts += (char)(r + '0');
    // }
    // if (!cnt[0]) ts[ts.length() - 1] = '0';
    // if (!cnt[1]) ts[ts.length() - 1] = '1';
    // cout << ts << endl;
    string s; 
    for (int i = 0; i < n; ++i) s += '0';
    k = ask(s);
    int pos1 = bs(0, n, k, 0, s);
    // if (ts[pos0] == '0' && ts[pos1] == '1' && tot <= 15) cout << "Correct" << endl;
    // else if (ts[pos0] == '0' && ts[pos1] == '1') cout << "TLE" << endl;
    // else cout << "Incorrect" << endl;
    cout << "! " << pos0 + 1 << ' ' << pos1 + 1 << endl;
    return 0;
}
