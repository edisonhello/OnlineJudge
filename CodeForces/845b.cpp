#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(string s) {
    int a = s[0] -  '0' + s[1] - '0' + s[2] - '0', b = s[3] - '0' + s[4] - '0' + s[5] - '0';
    return make_pair(a, b);
}

int main() {
    string s; cin >> s;
    if (get(s).first == get(s).second) return cout << "0" << endl, 0;
    int a = get(s).first, b = get(s).second;
    if (a < b) {
        int del = b - a;
        vector<int> vec;
        for (int i = 0; i < 3; ++i) vec.push_back(s[i] - '0');
        sort(vec.begin(), vec.end());
        int ans  = 100000;
        for (int i = 0; i < 3; ++i) {
            del -= 9 - vec[i];
            if (del <= 0) ans = min(ans, i + 1);
        }
        vec.clear();
        for (int i = 3; i < 6; ++i) vec.push_back(s[i] - '0');
        del = b - a;
        sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
        for (int i = 0; i < 3; ++i) {
            del -= vec[i];
            if (del <= 0) ans = min(ans, i + 1);
        }
        cout << ans << endl;
    } else {
        int del = a - b;
        vector<int> vec;
        for (int i = 3; i < 6; ++i) vec.push_back(s[i] - '0');
        sort(vec.begin(), vec.end());
        int ans = 100000;
        for (int i = 0; i < 3; ++i) {
            del -= 9 - vec[i];
            if (del <= 0) ans = min(ans, i + 1);
        }
        vec.clear();
        for (int i = 0; i < 3; ++i) vec.push_back(s[i] - '0');
        del = a - b;
        sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
        for (int i = 0; i < 3; ++i) {
            del -= vec[i];
            if (del <= 0) ans = min(ans, i + 1);
        }
        cout << ans << endl;
    }
}
