#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int mat[maxn][maxn];

int main() {
    int n, k; cin >> n >> k;
    if (k > n * n) return cout << "-1\n", 0;
    for (int i = 0; i < n; ++i) {
        if (k >= 2 * (n - i) - 1) {
            mat[i][i] = 1;
            for (int j = i + 1; j < n; ++j) mat[i][j] = mat[j][i] = 1;
            k -= 2 * (n - i) - 1;
        } else {
            if (k & 1) mat[i][i] = 1, --k;
            int ind = i + 1;
            while (k >= 2) mat[ind][i] = mat[i][ind] = 1, k -= 2, ++ind;
        }
    } 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << mat[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
