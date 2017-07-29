#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 800 + 10;
pair<pair<int, int>, int> p[maxn];
pair<pair<int, int>, pair<int, int>> t[maxn][maxn];
int b[maxn][maxn];
double mem[maxn][maxn];
int n;

double dp(int, int);
double dis(int, int);
void back(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    double sx = 0.0, sy = 0.0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first.first >> p[i].first.second;
        sx += p[i].first.first; sy += p[i].first.second;
        p[i].second = i;
    }
    sx /= (double)n, sy /= (double)n;
    sort(p, p + n, [=](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        return atan2((double)a.first.first - sx, (double)a.first.second - sy) < atan2((double)b.first.first - sx, (double)b.first.second - sy);
    });
    pair<int, int> ans;
    double sh = 1e9 + 1;
    for (int i = 0; i < n; ++i) {
        double d = dp(i, (i + n - 1) % n);
        if (d < sh) {
            sh = d; ans = make_pair(i, (i + n - 1) % n); 
        }
    }
    back(ans.first, ans.second);
    return 0;
}

double dp(int L, int R) {
    if (R == (L + 1) % n) return 0;
    if (L == R) return 0;
    if (mem[L][R]) return mem[L][R];
    int l = L, r = R;
    if (r < l) r += n;
    mem[L][R] = 1e9 + 1;
    for (int i = l + 2; i <= r - 1; ++i) {
        double d = dp((L + 1) % n, (i - 1) % n) + dp((i + 1) % n, R) + dis(L, i % n);
        if (d < mem[L][R]) {
            mem[L][R] = d;
            t[L][R] = make_pair(make_pair((L + 1) % n, (i - 1) % n), make_pair((i + 1) % n, R));
            cout << "t[" << L << "][" << R << "] = " << "(" << t[L][R].first.first << ", " << t[L][R].first.second << ", " << t[L][R].second.first << ", " << t[L][R].second.second << ")" << endl;
            b[L][R] = p[i % n].second;
        }
    }
    return mem[L][R];
}

double dis(int i, int j) {
    return sqrt((p[i].first.first - p[j].first.first) * (p[i].first.first - p[j].first.first) + \
               (p[i].first.second - p[j].first.second) * (p[i].first.second - p[j].first.second));
}

void back(int L, int R) {
    cout << "back(" << L << ", " << R << ")" << endl;
    if (L == R) return;
    if (R == (L + 1) % n) return;
    back(t[L][R].first.first, t[L][R].first.second); back(t[L][R].second.first, t[L][R].second.second);
    cout << L << ' ' << b[L][R] << endl;
}
