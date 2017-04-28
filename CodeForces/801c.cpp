#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
double p;
int n;

struct T {
    double a, b;
    bool operator>(const T& t) const {
        return a / b > t.a / t.b;
    }
} t[maxn];

double bs(double, double);
bool check(double);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i].a >> t[i].b;
    double ans = bs(0, 1e9 + 1);
    if (!check(ans)) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}

double bs(double l, double r) {
    if (r - l < 1e-4) return l;
    double m = (l + r) / 2;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}

bool check(double x) {
    cerr << "x: " << x << '\n';
    double cur = 0.0;
    priority_queue<T, vector<T>, greater<T>> pq(t, t + n);
    while (true) {
        T tmp = pq.top(); pq.pop();
        cerr << tmp.a << ' ' << tmp.b << '\n';
        if (tmp.b < 0) break;
        tmp.b += (pq.top().b / pq.top().a) * p - (pq.top().b / pq.top().a) * tmp.a;
        cur += pq.top().b / pq.top().a;
        pq.push(tmp);
    }
    return cur >= x;
}
