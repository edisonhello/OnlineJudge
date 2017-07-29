#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    if ((s[s.length() - 1] - '0') % 2 == 0) {
        char a = 0, b = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] > a) b = a, a = s[i];
            else if (s[i] > b) b = s[i];
        }
        int pos = 
        for (int)
    }
    return 0;
}
