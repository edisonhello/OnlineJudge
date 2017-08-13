#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, maxv = 1e6, mod = 1e9 + 7;
int a[maxn];
long long fac[maxn], invfac[maxn];
bool p[maxv];
vector<int> prime;

void sieve() {
    p[1] = true;
    for (int i = 2; i < maxv; ++i) {
        if (!p[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < maxv; ++j) {
            p[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

long long fpow(int a, int n) {
    long long ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

void init() {
    fac[1] = 1;
    for (int i = 2; i < maxn; ++i) fac[i] = fac[i - 1] * (long long)i % mod;
    invfac[1] = fpow(fac[1], mod - 2);
    for (int i = 2; i < maxn; ++i) invfac[i] = fpow(fac[i], mod - 2);
}

long long c(int n, int k) {
    return fac[n] * invfac[n - k] % mod * invfac[k] % mod;
}

long long cal(int k) {
    long long ret = 0;
    for (int i = 1; i <= k; ++i) ret = (ret + c(k, i) * (long long)i % mod) % mod;
    return ret;
}

long long ans[maxn];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    sieve(); 
    init();
    int g = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i : prime) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) if (a[j] % i == 0) ++cnt;
        ans[i] = 
    }
    cout << ans << endl;
    return 0;
}
