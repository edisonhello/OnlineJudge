#include <bits/stdc++.h>
using namespace std;

int mem[55][245][1005];
tuple<int, int, int> t[55][245][1005];
struct O { int b, n, m, a; } o[55];
int main() {
    int k, h, c; cin >> k >> h >> c;
    for (int i = 1; i <= c; ++i) cin >> o[i].b >> o[i].n >> o[i].m >> o[i].a;
    for (int _ = 0; _ <= c; ++_ )for (int i = 0; i <= k; ++i) for (int j = 0; j <= h; ++j) t[_][i][j] = make_tuple(7122, 7122, 7122);
    for (int i = 1; i <= c; ++i ) {
        for (int j = k; j >= o[i].b; --j) {
            for (int l = h; l >= o[i].m; --l) {
                if (mem[i][j][l] < mem[i - 1][j - o[i].b][l - o[i].m] + o[i].a) {
                    mem[i][j][l] = mem[i - 1][j - o[i].b][l - o[i].m] + o[i].a;
                    t[i][j][l] = make_tuple(i - 1, j - o[i].b, l - o[i].m);
                } else {
                    t[i][j][l] = make_tuple(i - 1, j, l);
                }
            }
        }
    }
    tuple<int, int, int> cur; int Max = 0;
    for (int i = 0; i <= c; ++i) for (int j = 0; j <= k; ++j) for (int l = 0; l <= h; ++l) {
        if (mem[i][j][l] > Max) {
            Max = mem[i][j][l];
            cur = make_tuple(i, j, l);
        }
    }
    vector<int> vec;
    while (true) {
        cout << get<0>(cur) << ' ' << get<1>(cur) << ' ' << get<2>(cur) << '\n';
        tuple<int, int, int> jizz = t[get<0>(cur)][get<1>(cur)][get<2>(cur)];
        if (get<0>(jizz) == 7122) break;
        if (get<1>(cur) != get<1>(jizz) || get<2>(jizz) == get<2>(cur)) {
            vec.push_back(get<0>(jizz));
        }
        cur = jizz;
    }
    sort(vec.begin(), vec.end(), [](const int& a, const int& b) {
        return o[a].a < o[b].a;        
    });
    for (int i : vec) cout << o[i].n << '\n';
    return 0;
}
