#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;
string t[maxn];
int sz[maxn], ans[maxn];
char c[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        int k; cin >> k; while (k--) {
            int x; cin >> x; --x;
            if (sz[x] < t[i].length()) sz[x] = t[i].length(), ans[x] = i;
            len = max(len, x + (int)t[i].length());
        }
    }
    for (int i = 0; i < len; ++i) {
        if (!c[i] && !sz[i]) c[i] = 'a';
        else if (!c[i]) {
            for (int j = 0; j < t[ans[i]].size(); ++j) c[i + j] = t[ans[i]][j];
        }
    }
    for (int i = 0; i < len; ++i) {
        if (c[i]) cout << c[i];
        else break;
    }
    cout << endl;
    return 0;
}
