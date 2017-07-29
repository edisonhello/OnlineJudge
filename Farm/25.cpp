#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
bool ok[maxn];

int main() {
    string s; cin >> s;
    if (s.length() < 3) {
        for (int i = 0; i < s.length(); ++i) cout << "."; cout << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); ++i) if (!ok[i]) {
        if (i + 3 > s.length()) break;
        if (s.substr(i, 3) != "MTF") s[i] = '.';
        else ok[i] = ok[i + 1] = ok[i + 2] = true;
    }
    if (s.substr(s.length() - 3, 3) != "MTF") {
        if (!ok[s.length() - 2]) s[s.length() - 2] = '.';
        if (!ok[s.length() - 1]) s[s.length() - 1] = '.';
    }
    cout << s << endl;
    return 0;
}
