#include <bits/stdc++.h>
using namespace std;

int n;

string mul(const string& a, const string& b) {
    // cout << "mul a = " << a << " b = " << b << endl;
    vector<int> res((int)a.length() + (int)b.length(), 0);
    for (int i = a.length() - 1; i >= 0; --i) {
        int c = 0;
        for (int j = b.length() - 1; j >= 0; --j) {
            int k = (a[i] - '0') * (b[j] - '0') + c;
            c = k / 10; k %= 10;
            res[a.length() - 1 - i + b.length() - 1 - j] += k;
        }
        if (c) res[a.length() - 1 - i + b.length()] += c;
    }
    string ret = "";
    int c = 0;
    for (int i : res) {
        int k = i + c;
        c = k / 10; k %= 10;
        ret += (char)(k + '0');
    }
    if (c) ret += (char)(c + '0');
    reverse(ret.begin(), ret.end());
    while (ret.length() && ret[0] == '0') ret = ret.substr(1, ret.length() - 1);
    // cout << "ret = " << ret << endl;
    return ret;
}

bool check(string s, int dig, int f) {
    // cout << s << ' ' << dig << ' ' << f << endl;
    s += (char)(dig + '0');
    string t = mul(s, s);
    // cout << "t = " << t << ' ';
    t = t.substr(0, t.length() - 2 * f);
    stringstream ss(t); int k; ss >> k; ++k;
    // cout << "k = "<< k << endl;
    return k <= n;
}

int main() {
    cin >> n;
    int k = (int)sqrt(n);
    stringstream ss; ss << k;
    string s; ss >> s;
    int org = s.length();
    for (int i = 0; i < 51; ++i) {
        int dig = 0, d = 16;
        while (d >>= 1) if (dig + d < 10) if (check(s, dig + d, i + 1)) dig += d;
        s += (char)(dig + '0');
    }
    if (s[s.length() - 1] >= '5') ++s[s.length() - 2];
    int ptr = s.length() - 2;
    while (ptr >= 1 && s[ptr] > '9') {
        s[ptr] = '0'; s[ptr - 1]++;
        --ptr;
    }
    for (int i = 0; i < org; ++i) cout << s[i]; cout << ".";
    for (int i = org, cnt = 0; cnt < 50; ++i, ++cnt) cout << s[i];
    cout << endl;
    return 0;
}
