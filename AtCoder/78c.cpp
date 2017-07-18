#include <bits/stdc++.h>
using namespace std;

string ans;
bool b[10];

string trim(const string& s) {
    int i = 0; while (s[i] == '0') ++i;
    string ret;
    for (; i < s.length(); ++i) ret += s[i];
    if (ret.size() == 0) return "0";
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 10; ++i) ans += '0';
    for (int i = 0; i < 10; ++i) {
        int d = 16, dig = 9;
        while (d >>= 1) if (dig - d >= 0) {
            ans[i] = (char)(dig - d + '0');
            cout << "? " << trim(ans) << endl;
            char res; cin >> res;
            if (res == 'Y') dig -= d;
            else b[i] = true;
        }
        ans[i] = (char)(dig + '0');
    }
    int ind = 9;
    while (!b[ind]) --ind;
    cout << "! ";
    int p = 0;
    while (ans[p] == '0') ++p;
    for (int i = p; i <= ind; ++i) cout << ans[i]; cout << endl;
    return 0;
}
