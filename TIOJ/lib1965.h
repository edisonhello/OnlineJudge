#include <bits/stdc++.h>
using namespace std;

void init(int, uint64_t*);
uint64_t RMQ(int, int);

int main() {
    int N, Q; cin >> N >> Q;
    uint64_t *C = new uint64_t[N];
    for (int i = 0; i < N; ++i) cin >> C[i];
    init(N, C);
    while (Q--) {
        int a, b; cin >> a >> b;
        cout << RMQ(a, b) << '\n';
    }
    return 0;
}
