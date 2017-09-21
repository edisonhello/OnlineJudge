#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    for (int i = 0; i < 100000; ++i) {
        cout << (char)('a' + rand() % 26);
    }
}
