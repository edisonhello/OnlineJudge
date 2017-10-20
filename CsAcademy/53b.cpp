#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ptr = 0, ans = 0;
    a[n] = 1e9;
    while (ptr < n) {
        int pos = ptr, len = 0;
        ++ptr;
        while (ptr < n && a[ptr] >= a[ptr - 1]) ++ptr, ++len;
        ans = max(ans, len);
        if (ptr == pos) ++ptr;
    }
    a[n] = -1e9;
    ptr = 0;
    while (ptr < n) {
        int pos = ptr, len = 0; ++ptr;
        while (ptr < n && a[ptr] <= a[ptr - 1]) ++ptr, ++len;
        ans = max(ans, len);
        if (ptr == pos) ++ptr;
    }
    cout << ans + 1 << endl;
    return 0;
}
