#include <iostream>
using namesapce std;

int n, k, sz[2005], A[2005][2005];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> n >> k; for (int i = 0; i < n; ++i) cin >> sz[i];
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> A[i][j];
    
    return 0;
}
