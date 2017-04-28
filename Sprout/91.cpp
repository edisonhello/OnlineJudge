#include <bits/stdc++.h>
using namespace std;

int p[] = { 9, 8, 7, 6, 5, 4, 3, 2 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        long long n; cin >> n;
        int ind = 0;
        bool ans = true;
        vector<int> v;
        if (n == 1) { cout << "1\n"; continue; }
        while (n > 1) {
            if (ind == 8) { ans = false; break; }
            while (n && n % p[ind] == 0) v.push_back(p[ind]), n /= p[ind];
            ++ind;
        }
        if (!ans) cout << "-1\n";
        else {
            reverse(v.begin(), v.end());
            for (int i : v) cout << i;
            cout << '\n';
        }
    }
    return 0;
}
