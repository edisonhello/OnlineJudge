#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool v[maxn];
vector<int> prime;

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < maxn; ++j) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }

}
long long fpow(long long a, int n) {
    long long ret = 1ull;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

int main() {
    sieve();
    unsigned long long n; while (cin >> n) {
        if (n > 600000000) { cout << n - 1 << endl; continue; }
        long long ans = 1ull;
        for (int p : prime) {
            int cnt = 0;
            while (n % p == 0) ++cnt, n /= p;
            if (cnt) ans *= fpow(p, cnt - 1) * (p - 1);
        }
        if (n > 1) ans *= (n - 1);
        cout << ans << endl;
    }
    return 0;
}
