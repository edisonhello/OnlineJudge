#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    if (a != b && b == c) return cout << "A" << endl, 0;
    if (b != a && a == c) return cout << "B" << endl, 0;
    if (c != a && a == b) return cout << "C" << endl, 0;
    cout << "*" << endl;
    return 0;
}
