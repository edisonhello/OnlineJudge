#include <bits/stdc++.h>
#include "lib1617.h"
using namespace std;

const int maxn = 1500;
int n, y[maxn], mx, mn;

void init();
bool cmp(int, int);

int main() {
    n = Get_Box();
    for (int i = 0; i < n; ++i) y[i] = i + 1;
    init();
    nth_element(y, y + n / 2, y + n, cmp);
    Report(y[n / 2]);
    return 0;
}

void init() {
    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    while (s.size() >= 3) {
        auto it = s.begin(); int a = *it;
        ++it; int b = *it;
        ++it; int c = *it;
        int m = Med3(a, b, c);
        s.erase(m);
    }
    auto it = s.begin();
    mx = *it; ++it; mn = *it;
}

bool cmp(int a, int b) {
    if (a == mx) return false;
    if (b == mx) return true;
    int m = Med3(a, b, mx);
    return m == b;
}
