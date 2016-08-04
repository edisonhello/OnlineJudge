#include <iostream>
using namespace std;

bool good(int a, int b, int c) {
    if (a + b == c || b + c == a || a + c == b) return true;
    return false;
}
int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (good(a, b, c)) cout << "Good Pair" << endl;
        else cout << "Not Good Pair" << endl;
    }
    return 0;
}
