#include <bits/stdc++.h>
using namespace std;

int k;
string s;

int bs(int, int);
bool check(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> k >> s;
    cout << bs(0, (int)s.length() + 1) << '\n';
    return 0;
}
int bs(int l, int r) {
    if (r - l == 1) return l;
    int m = (l + r) >> 1;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}
bool check(int len) {
    string t = s.substr(0, len);
    for (int i = 1; i < k; ++i) {
        if (s.substr(len * i, len) != t) return false;
    }
    return true;
}
