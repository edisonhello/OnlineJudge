#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5, mod = 1000000007, lg = 20;
int n, q, sa[maxn], tmp[2][maxn], c[maxn], r[maxn], lcp[maxn], st[20][maxn];
string s;

int _pow(int, int);
void suffix_array();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    s = "";
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        if (_pow(c, (mod - 1) >> 1) == 1) s += 'a';
        else s += 'b';
    }
    s += 'c';
    ++n;
    suffix_array(); 
    for (int i = 0; i < n; ++i) r[sa[i]] = i;
    int ind = 0; lcp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (!r[i]) { ind = 0; continue;  }
        while (s[i + ind] == s[sa[r[i] - 1] + ind]) ++ind;
        lcp[r[i]] = ind ? ind-- : 0;
    }
    for (int i = 0; i < n; ++i) st[0][i] = lcp[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
    while (q--) {
        int L, R; cin >> L >> R;
        if (L == R) { cout << n - L - 1 << '\n'; continue; }
        L = r[L], R = r[R];
        if (L > R) swap(L, R);
        ++L;
        int p = 31 - __builtin_clz(R - L + 1);
        cout << min(st[p][L], st[p][R - (1 << p) + 1]) << '\n';
    }
    return 0;
}

int _pow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = (long long)ret * (long long)a % mod;
        a = (long long)a * (long long)a % mod;
    }
    return ret;
}

void suffix_array() {
    int* rank = tmp[0];
    int* nRank = tmp[1];
    int A = 128;
    for (int i = 0; i < A; ++i) c[i] = 0;
    for (int i = 0; i < s.length(); ++i) c[rank[i] = s[i]]++;
    for (int i = 1; i < A; ++i) c[i] += c[i - 1];
    for (int i = s.length() - 1; i >= 0; --i) sa[--c[s[i]]] = i;
    for (int n = 1; n < s.length(); n *= 2) {
        for (int i = 0; i < A; ++i) c[i] = 0;
        for (int i = 0; i < s.length(); ++i) c[rank[i]]++;
        for (int i = 1; i < A; ++i) c[i] += c[i - 1];
        int* sa2 = nRank;
        int r = 0;
        for (int i = s.length() - n; i < s.length(); ++i) sa2[r++] = i;
        for (int i = 0; i < s.length(); ++i) if (sa[i] >= n) sa2[r++] = sa[i] - n;
        for (int i = s.length() - 1; i >= 0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
        nRank[sa[0]] = r = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (!(rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + n < s.length() && rank[sa[i - 1] + n] == rank[sa[i] + n])) r++;
            nRank[sa[i]] = r;
        }
        swap(rank, nRank);
        if (r == s.length() - 1) break;
        A = r + 1;
    }
}
