#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 479001599, p = 101;
string s;
int pp[maxn], h[maxn], c, st;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return (long long)a * (long long)b % mod; }

void init() {
    pp[0] = 1;
    for(int i = 1; i < maxn; ++i) pp[i] = mul(pp[i - 1], p);
    h[0] = s[0];
    for (int i = 1; i < s.length(); ++i) h[i] = add(mul(h[i - 1], p), s[i]); 
}

bool check(int len) {
    unordered_map<int, int> m;
    vector<int> vec;
    for (int i = 0; i < s.length(); ++i) {
        if (i + len > s.length()) break;
        int l = i, r = i + len - 1;
        int hs = (l == 0 ? h[r] : sub(h[r], mul(h[l - 1], pp[len])));
        ++m[hs];
        vec.push_back(i);
    }
    int bst = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (i + len > s.length()) break;
        int l = i, r = i + len - 1;
        int hs = (l == 0 ? h[r] : sub(h[r], mul(h[l - 1], pp[len])));
        if (m[hs] == c) {
            if (bst == -1) bst = i;
            else if (bst != -1 && s[i] < s[bst]) bst = i;
        }
    }
    // sort(vec.begin(), vec.end(), [&](const int& a, const int& b) {
        // int ha = (a == 0 ? h[a + len - 1] : sub(h[a + len - 1], mul(h[a - 1], pp[len])));
        // int hb = (b == 0 ? h[b + len - 1] : sub(h[b + len - 1], mul(h[b - 1], pp[len])));
        // return m[ha] == m[hb] ? s[a] < s[b] : m[ha] > m[hb];
    // });
    // int hs = (vec[0] == 0 ? h[vec[0] + len - 1] : sub(h[vec[0] + len - 1], mul(h[vec[0] - 1], pp[len])));
    // if (m[hs] == c) st = vec[0];
    if (bst != -1) st = bst;
    return bst != -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    init();
    vector<int> cnt(26);
    for (int i = 0; i < s.length(); ++i) ++cnt[s[i] - 'a'];
    for (int i = 0; i < 26; ++i) c = max(c, cnt[i]);
    int d = 1; while (d <= s.length()) d <<= 1;
    int ans = 0;
    while (d >>= 1) if (ans + d <= s.length()) if (check(ans + d)) ans += d;
    cout << s.substr(st, ans) << endl;
    return 0;
}
