//
// Created by Wayne Tu on 4/29/16.
//

#include <iostream>
using namespace std;

int main() {
    char map[10][10];
    int si, sj;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    int step = 0;
    while (true) {
        if (map[si][sj] == 'F') {
            break;
        }
        else if (map[si + 1][sj] == '*' || map[si + 1][sj] == 'F') {
            if (si + 1 < 10 && sj >= 0 && sj < 10) {
                map[si][sj] = 'x';
                si++;
                step++;
            }
        }
        else if (map[si - 1][sj] == '*' || map[si - 1][sj] == 'F') {
            if (si - 1 >= 0 && sj >= 0 && sj < 10) {
                map[si][sj] = 'x';
                si--;
                step++;
            }
        }
        else if (map[si][sj + 1] == '*' || map[si][sj + 1] == 'F') {
            if (si >= 0 && si < 10 && sj + 1 < 10) {
                map[si][sj] = 'x';
                sj++;
                step++;
            }
        }
        else if (map[si][sj - 1] == '*' || map[si][sj - 1] == 'F') {
            if (si >= 0 && si < 10 && sj - 1 >= 0) {
                map[si][sj] = 'x';
                sj--;
                step++;
            }
        }
    }
    cout << step << '\n';
    return 0;
}