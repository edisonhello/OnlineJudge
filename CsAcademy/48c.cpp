#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
string s, ans;
int cnt[10];

bool check(int k) {
    do {
        stringstream ss(s);
        if (s[0] == '0') continue;
        int b; ss >> b;
        if (b == k) return true;
    } while (next_permutation(s.begin(), s.end()));
    return false;
}

void go(int k) {
    stringstream ss; ss << k;
    string tmp; ss >> tmp;
    if (tmp.size() > s.size()) return;
    vector<int> c(cnt, cnt + 10);
    vector<int> tail;
    for (int i = 0; i < 3; ++i) {
        int d = k % 10; k /= 10;
        if (!c[d]) return;
        --c[d];
        tail.push_back(d);
    }
    string cur = "";
    int ind = 1;
    while (ind < 10 && !c[ind]) ++ind;
    if (ind == 10) return;
    cur += (char)(ind + '0');
    --c[ind];
    for (int i = 0; i < 10; ++i) {
        while (c[i]) cur += (char)(i + '0'), --c[i];
    }
    for (int i = 2; i >= 0; --i) cur += (char)(tail[i] + '0');
    if (ans == "" || cur < ans) ans = cur;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) cnt[s[i] - '0']++;
    vector<int> vec;
    vec.push_back(0);
    for (int i = 1; ; ++i) {
        if (8 * i >= 1000) break;
        vec.push_back(8 * i);
    }
    if (s.length() <= 3) {
        for (int i : vec) {
            if (check(i)) return cout << i << endl, 0;
        }
        cout << "-1" << endl;
        return 0;
    }
    ans = "";
    for (int i : vec) go(i);
    if (ans == "") cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}
