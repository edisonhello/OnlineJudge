#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << "70000" << endl;
    for (int i = 0; i < 70000; ++i) {
        cout << rand() % 9 + 1;
        for (int j = 0; j < 8; ++j) cout << rand() % 10 ;
        cout << endl;
    }
    return 0;
}
