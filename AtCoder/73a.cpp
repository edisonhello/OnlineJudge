#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.length() ;++i) if (s[i] == '9') return cout << "Yes" << endl, 0;
    cout << "No" << endl;
    return 0;
}
