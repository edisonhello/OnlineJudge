#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string s[100005];
int n;
int sm(const string&);

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n; for (int i = 0; i < n; ++i) cin >> s[i];
    stable_sort(s, s + n, [](const string& a, const string& b) -> bool {
        return sm(a) < sm(b);
    });
    for (int i = 0; i < n; ++i) cout << s[i] << ' ';
    return 0;
}

int sm(const string& str) {
    int ret = 0;
    for (int i = 0; i < str.length(); ++i) ret += str[i] - '0';
    return ret;
}
