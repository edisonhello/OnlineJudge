#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


const int maxn = 100 + 5;
int T, N, A[maxn], B[maxn];
bool done();

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];
        int ans = 0;
        while (true) {
            if (done()) break;
            for (int i = 0; i < N; ++i) A[i] = B[i];
            ans++;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}

bool done() {
    for (int i = 0; i < N; ++i) {
        int s = 0;
        for (int j = i; j > 0; --j) {
            if (A[j - 1] > A[j]) swap(A[j - 1], A[j]), s++;
        }
        B[i] = s;
    }
    for (int i = 0; i < N; ++i) if (B[i]) return false;
    return true;
}
