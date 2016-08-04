//
// Created by Wayne Tu on 3/31/16.
//

#include <iostream>

using namespace std;



int main() {
    int m, n;
    while (cin >> m >> n) {


        int matrix1[m][n];
        int matrix2[n][m];


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix1[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix2[j][i] = matrix1[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix2[i][j] << " ";
            }

            cout << '\n';
        }
    }
    return 0;
}