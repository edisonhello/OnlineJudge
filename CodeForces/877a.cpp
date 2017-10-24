#include <bits/stdc++.h>
using namespace std;

string name[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

int main() {
    string s; cin >> s;
    int k = 0;
    for (int i = 0; i < 5; ++i) {
        int c = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (j + name[i].length() > s.length()) break;
            if (s.substr(j, name[i].length()) == name[i]) ++c;
        }
        if (c == 1) ++k;
    }
    if (k == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
