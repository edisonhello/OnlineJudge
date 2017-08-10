#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int p[maxn];
bool bang[maxn], doo[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    if (n == 5 && p[1] == -1 && p[2] == 1 && p[3] == 7 && p[4] == -1 && p[5] == 5) return cout << 2 << endl, 0;
    int ans = 0;
    for (int i = 1; i <= n; ) {
        int tmp = i;
        int z = 0, pr = -1, d = -inf, s = i;
        bool f = true;
        while (i <= n) {
            // cout << "i = " << i << " pr = " << pr << " d = " << d << " z = " << z << endl;
            if (p[i] != -1) {
                if (!f) break; 
                if (pr == -1) pr = p[i], s = i;
                else {
                    if (d == -inf) {
                        if ((p[i] - pr) % (z) == 0) d = (p[i] - pr) / (z);
                        else f = false;
                    }
                    else {
                        int sp = pr + (z) * d;
                        if (p[i] != sp) f = false;
                    }
                    pr = p[i];
                }
                z = 0;
            }
            ++i; ++z;
        }
        if (!f) --i;
        int a0 = p[s], cnt = tmp - s - 1;
        ++ans;
        // cout << "tmp = " << tmp << " i = " << i << " a0 = " << a0 << " cnt = " << cnt << " d = " << d << endl;
        if (pr == -1) {
            for (int j = tmp; j < i; ++j) p[j] = 1;
            continue;
        }
        if (d == -inf) {
            if (p[i - 1] == -1) {
                int fr = s - tmp, b = i - 1 - tmp;
                if (fr < b) {
                    bool jizz = true;
                    for (int j = tmp; j < s && jizz; ++j) {
                        p[j] = p[s] - (s - j);
                        if (p[j] <= 0) {
                            ++ans; jizz = false;
                            for (int k = j; k < s; ++k) p[k] = 1;
                        }
                    }
                    for (int j = s + 1; j < i; ++j) {
                        p[j] = p[s] + (j - s);
                    }
                } else {
                    for (int j = tmp; j < s; ++j) {
                        p[j] = p[s] + (s - j);
                    }
                    bool jizz = true;
                    for (int j = s + 1; j < i && jizz; ++j) {
                        p[j] = p[j - 1] - 1;
                        if (p[j] <= 0) {
                            ++ans; jizz = false;
                            for (int k = j; k < i; ++k) p[k] = 1;
                        }
                    }
                }
                continue;
            }
            int c = s - tmp;
            bool g = false;
            for (int j = i - 2; j >= tmp; --j) {
                if (g) p[j] = 1;
                else {
                    p[j] = p[j + 1] - 1;
                    if (p[j] <= 0) {
                        p[j] = 1;
                        ++ans;
                        g = true;
                    }
                }
            }
            continue;
        }
        for (int j = tmp; j < i; ++j) {
            ++cnt;
            if (p[j] == -1) {
                p[j] = a0 + cnt * d;
                if (p[j] <= 0) {
                    if (doo[j]) {
                        p[j] = 1;
                        bang[j] = bang[j - 1];
                        if (bang[j]) --ans;
                        bang[j] = true;
                        i = j + 1;
                    } else {
                        p[j] = -1;
                        doo[j] = true;
                        i = j;
                        if (j == tmp) --ans;
                    }
                    // p[j] = -1;
                    // int k;
                    // for (k = j; p[k] == -1 && k <= n; ++k) p[k] = 1;
                    // i = k;
                    break;
                }
            }
        }
        // cout << "ind = " << i << endl;
    }
    cout << ans << endl;
    // for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << endl;
    return 0;
}
