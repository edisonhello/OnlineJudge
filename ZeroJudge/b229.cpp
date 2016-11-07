#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
    __c = 0; flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    (__c == '-') ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

unsigned long long N, dp[51];

int main() {
    rit(N);
    dp[0] = 1; dp[1] = 3;
    for (int i = 2; i <= N; ++i) dp[i] = dp[i - 1] * 2 + dp[i - 2];
    printf("%llu\n", dp[N]);
    return 0;
}
