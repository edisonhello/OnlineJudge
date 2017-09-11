long long f(long long x, long long mod) {
    return add(mul(x, x, mod), 1, mod);
}

long long pollard_rho(long long n) {
    if (n % 2 == 0) return 2;
    while (true) {
        long long y = 2, x = rand() % (n - 1) + 1, res = 1;
        for (int sz = 2; res == 1; sz <<= 1) {
            for (int i = 0; i < sz && res <= 1; ++i) {
                x = f(x, n);
                res = __gcd(abs(x - y), n);
            }
            y = x;
        }
        if (res && res != n) return res;
    }
}
