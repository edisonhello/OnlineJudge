#include <bits/stdc++.h>
using namespace std;

bool ans;
char start;
void dfs(int, int, int, string);
bool osas[1005][1005][1005][3];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n; cin >> n;
        int r, o, y, g, b, v; cin >> r >> o >> y >> g >> b >> v;
        ans = false;
        if (r == 0) start = y == 0 ? 'B' : 'Y';
        else start = 'R';
        if (start == 'R') dfs(r - 1, y, b, "R");
        else if (start == 'Y') dfs(r, y - 1, b, "Y");
        else dfs(r, y, b - 1, "B");
        if (!ans) cout << "IMPOSSIBLE\n";
    } 
}

void dfs(int r, int y, int b, string s) {
    if (ans) return;
    if (r == 0 && y == 0 && b == 0) {
        if (s[s.length() - 1] != s[0]) cout << s << '\n', ans = true;
        return;
    }
    if (r && s[s.length() - 1] != 'R') dfs(r - 1, y, b, s + 'R');
    if (y && s[s.length() - 1] != 'Y') dfs(r, y - 1, b, s + 'Y');
    if (b && s[s.length() - 1] != 'B') dfs(r, y, b - 1, s + 'B');
}
