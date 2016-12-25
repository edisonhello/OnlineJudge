#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string m[205];
int R, C, N, num[205], p;
int walk(int);
bool v[205][205];

int main() {
    cin >> N >> R >> C;
    for (int i = 0; i < R; ++i) cin >> m[i];
    for (int i = 0; i < C; ++i) if (m[0][i] == '#') num[i] = ++p;
    for (int i = 0; i < C; ++i) {
        if (m[0][i] == '#') {
            memset(v, false, sizeof(v));
            cout << walk(i) << ' ';
        }
    }
    return 0;
}

int walk(int st) {
    int c = st, r = 0;
    while (r < R) {
        v[r][c] = true;
        if (m[r][c - 1] == '#' && !v[r][c - 1]) c--;
        else if (m[r][c + 1] == '#' && !v[r][c+1]) c++;
        else r++;
    }
    return num[c];
}
