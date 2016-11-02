#include <iostream>
#include <cstdio>
using namespace std;

int n;

int main() {
    while (cin >> n) {
        cout << __builtin_clz(n) << endl;
    }
    return 0;
}
