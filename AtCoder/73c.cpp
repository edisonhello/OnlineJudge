#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    while (n--) {
        int a; cin >> a;
        if (s.count(a)) s.erase(a);
        else s.insert(a);
    }
    cout << s.size() << endl;
}
