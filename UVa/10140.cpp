#include <bits/stdc++.h>
using namespace std;

// n < 4759123141     chk = [2, 7, 61]
// n < 1122004669633  chk = [2, 13, 23, 1662803]
// n < 2^64           chk = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]

vector<int> chk = { 2, 7, 61 };

long long fpow(long long a, long long n, long long mod) {
    long long ret = 1LL;
    for (; n; n >>= 1) {
        if (n & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
    }
    return ret;
}

bool check(long long a, long long u, long long n, int t) {
    a = fpow(a, u, n);
    if (a == 0) return true;
    if (a == 1 || a == n - 1) return true;
    for (int i = 0; i < t - 1; ++i) {
        a = a * a % n;
        if (a == 1) return false;
        if (a == n - 1) return true;
    }
    return false;
}

bool miller_rabin(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    long long u = n - 1; int t = 0;
    for (; u & 1; u >>= 1, ++t);
    for (long long i : chk) {
        if (!check(i, u, n, t)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l, r; while (cin >> l >> r) {
        vector<int> p;
        for (int i = l; i <= r; ++i) if (miller_rabin(i)) p.push_back(i);
        if (p.size() < 2) {
            cout << "There are no adjacent primes." << endl;
            continue;
        }
        pair<int, int> ans1 = make_pair(0, 1000000000), ans2 = make_pair(1000000000, 0);
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] - p[i - 1] < ans1.second - ans1.first) ans1 = make_pair(p[i - 1], p[i]);
            if (p[i] - p[i - 1] > ans2.second - ans2.first) ans2 = make_pair(p[i - 1], p[i]);
        }
        cout << ans1.first << "," << ans1.second << " are closest, " << ans2.first << "," << ans2.second << " are most distant." << endl;
    }
    return 0;
}
