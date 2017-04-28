#include <bits/stdc++.h>

std::multiset<int> s;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n; std::cin >> n; while (n--) {
        int l, r; std::cin >> l >> r;
        auto it = s.upper_bound(r);
        if (it == s.end()) {  s.insert(l); continue; }
        if (l < *it) s.erase(it), s.insert(l);
    } 
    std::cout << s.size() << '\n';
    return 0;
}
