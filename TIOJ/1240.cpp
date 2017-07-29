#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;
int p[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) if (!v[i]) {
        ++ans;
        int cur = i;
        while (cur < n) {
            int f = -1;
            for (int j = cur + 1; j < n; ++j) if (!v[j]) {
                if (p[j] > p[cur]) { f = j; break; };
            }
            if (f == -1) break;
            v[f] = true; cur = f;
        }
    }
    cout << ans << endl;
    return 0;
}
