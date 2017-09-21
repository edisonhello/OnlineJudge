#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 50;
typedef vector<vector<int>> mat;

mat init(int n, int m) {
    return mat(n, vector<int>(m));
}

mat matmul(const mat& a, const mat& b) {
    assert(a[0].size() == b.size());
    mat ret = init(a.size(), b[0].size());
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b[0].size(); ++j) {
            for (int k = 0; k < a[0].size(); ++k) ret[i][j] += a[i][k] * b[k][j];
        }
    }
    return ret;
}

mat rnd(int n, int m) {
    mat ret = mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) ret[i][j] = rand();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        mat a = init(n, n), b = init(n, n), c = init(n, n);
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> b[i][j];
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> c[i][j];
        mat t = rnd(n, 1);
        mat l = matmul(a, matmul(b, t)), r = matmul(c, t);
        bool ans = true;
        for (int i = 0; i < n; ++i) if (l[i][0] != r[i][0]) ans = false;
        if (ans) cout << "Loli is god." << endl;
        else cout << "QAQ!" << endl;
    }
    return 0;
}
