#include <bits/stdc++.h>
using namespace std;

int n;
string in, post;

string meow(const string&, const string&);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        cin >> n >> in >> post;
        if (in.length() > n) {
            in = in.substr(0, n);
            post = post.substr(0, n);
        } else if (in.length() < n) {
            int len = in.length();
            in = in + post.substr(0, n - in.length());
            post = post.substr(n - len, n);
        }
        cout << meow(in, post) << endl;
    }
    return 0;
}

string meow(const string& s, const string& t) {
    if (s.length() == 0) return "";
    if (s.length() == 1) {
        return s;
    }
    char rt = t[t.length() - 1];
    int pos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == rt) { pos = i - 1; break; }
    }
    string ret = ""; ret += rt;
    string ss = "", tt = "";
    for (int i = 0; i <= pos; ++i) ss += s[i], tt += t[i];
    assert(ss.length() == tt.length());
    ret += meow(ss, tt);
    ss = ""; tt = "";
    for (int i = pos + 2; i < s.length(); ++i) ss += s[i], tt += t[i - 1];
    assert(ss.length() == tt.length());
    ret += meow(ss, tt);
    return ret;
}