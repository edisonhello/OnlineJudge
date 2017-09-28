#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'N') ++y;
        if (s[i] == 'S') --y;
        if (s[i] == 'W') --x;
        if (s[i] == 'E') ++x;
    }
    cout << abs(x) + abs(y) << endl;
}
