#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxk = 1e9 + 10;
int cur = 3, mx = -1;
bool ans[maxn][maxn];

void construct(int nxt) {
    if (nxt == 0) {
        ans[1][cur] = true; ans[cur][1] = true; ++cur;
        for (int i = 0; i < mx - 1; ++i) ans[cur][cur - 1] = ans[cur - 1][cur] = true, ++cur;
        ans[cur - 1][2] = ans[2][cur - 1] = true;
        return;
    }
    for (int i = 0; i < nxt; ++i) {
        if (i == 0) {
            ans[1][cur] = ans[cur][1] = true;
            ans[1][cur + 1] = ans[cur + 1][1] = true;
        } else {
            ans[cur][cur - 1] = ans[cur - 1][cur] = true;
            ans[cur][cur - 2] = ans[cur - 2][cur] = true;
            ans[cur + 1][cur - 1] = ans[cur - 1][cur + 1] = true;
            ans[cur + 1][cur - 2] = ans[cur - 2][cur + 1] = true;
        }
        cur += 2;
    }
    if (mx > nxt) {
        ans[cur - 1][cur] = ans[cur][cur - 1] = true;
        ans[cur - 2][cur] = ans[cur][cur - 2] = true;
        ++cur;
        for (int i = 0; i < mx - nxt - 1; ++i) {
            ans[cur][cur - 1] = ans[cur - 1][cur] = true;
            ++cur;
        }
        ans[2][cur - 1] = ans[cur - 1][2] = true;
        return;
    }
    ans[2][cur - 1] = ans[cur - 1][2] = true;
    ans[2][cur - 2] = ans[cur - 2][2] = true;
}

int main() {
    int k; cin >> k;
    if (k == 1) {
        cout << 2 << endl;
        cout << "NY\nYN\n";
        return 0;
    }
    for (int bit = 30; bit >= 0; --bit) {
        if ((1 << bit) & k) {
            if (mx == -1) mx = bit;
            construct(bit);
        }
    } 
    cout << cur - 1 << endl;
    for (int i = 1; i < cur; ++i) {
        for (int j = 1; j < cur; ++j) cout << (ans[i][j] ? 'Y' : 'N');
        cout << endl;
    }
    return 0;
}
