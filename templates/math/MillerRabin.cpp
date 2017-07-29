// n < 4759123141     chk = [2, 7, 61]
// n < 1122004669633  chk = [2, 13, 23, 1662803]
// n < 2^64           chk = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]

long long fpow(long long a, long long n, long long mod) {
    long long ret = 1LL;
    for (; n; n >>= 1) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret;
}

bool check(long long a, long long n, long long u, long long t) {
    long long x = fpow(a, u, n);
    for (int i = 0; i < t; ++i) {
        long long nx = x * x % n;
        if (nx == 1 && x != 1 && x != n - 1) return true;
        x = nx;
    }
    return x != 1;
}

bool miller_rabin(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    long long u = n - 1;
    int t = 0;
    while (u % 2 == 0) u >>= 1, ++t;
    for (long long i : chk) {
        if (check(i, n, u, t)) return false;
    }
    return true;
}
