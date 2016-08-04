#include <iostream>
#include <cstdio>
using namespace std;

char map[3][3];

bool win() {
    for (int i = 0; i < 3; ++i) {
        char tmp = map[i][0];
        if (tmp != 'O' && tmp != 'X') continue;
        bool ans = true;
        for (int j = 1; j < 3; ++j) {
            if (map[i][j] != tmp) {ans = false; break;}
        }
        if (ans) return true;
    }
    for (int i = 0; i < 3; ++i) {
        char tmp = map[0][i];
        if (tmp != 'O' && tmp != 'X') continue;
        bool ans = true;
        for (int j = 1; j < 3; ++j) {
            if (map[j][i] != tmp) {ans = false; break;}
        }
        if (ans) return true;
    }
    bool ans = true;
    char tmp = map[0][0];
    for (int i = 1; i < 3; ++i) {
        if (map[i][i] != tmp) {ans = false; break;}
    }
    if (ans) return true;
    ans = true;
    tmp = map[2][0];
    for (int i = 1; i < 3; ++i) {
        if (map[2 - i][i] != tmp) {ans = false; break;}
    }
    if (ans) return true;
    return false;
}
int main() {
    int nO = 0, nX = 0;
    bool poss = true;
    for (int i = 0; i < 3 && poss; ++i) {
        for (int j = 0; j < 3 && poss; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 'O') nO++;
            else if (map[i][j] == 'X') nX++;
            else if (map[i][j] != '.') poss = false;
        }
    }
    if (win) {
        if (nO - nX == 1) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    else {
        if (nO == nX || nO - nX == 1) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}