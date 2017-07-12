#include <bits/stdc++.h>
using namespace std;

const int _maxn = 1500;
int _y[_maxn], _n, cnt;

int Get_Box() {
    cin >> _n;
    srand(time(nullptr));
    for (int i = 1; i <= _n; ++i) _y[i] = i;
    random_shuffle(_y + 1, _y + _n + 1);
    return _n;
}

int Med3(int a, int b, int c) {
    ++cnt;
    vector<int> v;
    v.push_back(_y[a]); v.push_back(_y[b]); v.push_back(_y[c]);
    sort(v.begin(), v.end());
    if (v[1] == _y[a]) return a;
    if (v[1] == _y[b]) return b;
    if (v[1] == _y[c]) return c;
}
bool check(int a) {
    int chk = _y[a];
    sort(_y + 1, _y + _n + 1);
    return chk == _y[_n / 2 + 1];
    // nth_element(_y + 1, _y + )
}

void Report(int a) {
    if (a <= 11) {
        cout << "sequence: ";
        for (int i = 1; i <= _n; ++i) cout << _y[i] << ' '; cout << endl;
    }
    cout << "guess: " << a << endl;
    cout << "correct: " << check(a) << endl;
    cout << "time: " << cnt << endl;
}
