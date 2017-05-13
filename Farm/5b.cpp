#include <bits/stdc++.h>
using namespace std;

inline vector<int> meow(int num) {
    vector<int> ret;
    while (num) {
        ret.push_back(num % 3);
        num /= 3;
    }
    return ret;
}

int main() {
    int x, y; cin >> x >> y;
    vector<int> xx = meow(x), yy = meow(y);
    for (int i : xx) cout << i << ' '; cout << endl;
    for (int i : yy) cout << i << ' '; cout << endl;
    vector<int> fin;
    while (xx.size() < yy.size()) xx.push_back(0);
    while (yy.size() < xx.size()) yy.push_back(0);
    int t = 1;
    for (int i = 0; i < xx.size(); ++i) {
        int diff = (y - x + 1) % (t * 3);
        int ans = 0, cur = (xx[i]) % 3;
        while (diff) {
            for (int j = 0; j < t && diff; ++j, --diff) ans += cur;
            cur = (cur + 1) % 3;
        }
        ans %= 3;
        fin.push_back(ans);
        t *= 3;
    }
    for (int i : fin) cout << i << ' ';
    reverse(fin.begin(), fin.end());
    long long ans = 0; 
    for (int i : fin) {
        ans = ans * 3 + i;
    }
    cout << ans << endl;
    return 0;
}
