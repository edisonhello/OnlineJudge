#include <bits/stdc++.h>
using namespace std;

int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {
    string s; cin >> s;
    int d = 0;
    if (s == "Monday") d = 1;
    if (s == "Tuesday") d = 2;
    if (s == "Wednesday") d = 3;
    if (s == "Thursday") d = 4;
    if (s == "Friday") d = 5;
    if (s == "Saturday") d = 6;
    int ind = 0, now = 1, ans = 0;
    for (int i = 1; i < 365; ++i) {
        ++now;
        ++d; d %= 7;
        if (now == 13 && d == 5) ++ans;
        if (now == day[ind]) now = 0, ++ind;
    }
    cout << ans << endl;
}
