#include <bits/stdc++.h>
using namespace std;
struct Jizz { int l, r, id };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int a, b; cin >> a >> b;
        vector<Jizz> vec;
        for (int i = 0; i < a; ++i) {
            int l, r; cin >> l >> r;
            vec.push_back((Jizz){ l, r, 0 });
        }
        for (int i = 0; i < b; ++i) {
            int l, r; cin >> l >> r;
            vec.push_back((Jizz){ l, r, 1 });
        }
        sort(vec.begin(), vec.end(), [](const Jizz& aa, const Jizz& bb) {
            return aa.l < bb.l;
        });
         
    }
}
