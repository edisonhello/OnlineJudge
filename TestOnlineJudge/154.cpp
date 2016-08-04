//
// Created by Wayne Tu on 5/15/16.
//

#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C) {
    if (n > 0) {
        hanoi(n - 1, A, C, B);
        cout << "Move ring " << n << " from " << A << " to " << C << '\n';
        hanoi(n - 1, B, A, C);
    }
}
int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}