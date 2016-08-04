//
// Created by Wayne Tu on 4/25/16.
//

#include <iostream>
using namespace std;

int main() {
    int start, end;
    cin >> start >> end;
    int delta = (end - start) > 0 ? 1 : -1;
    if (delta == 1) {
        while (start <= end) {
            for (int i = 0; i < start; ++i) {
                cout << "*";
            }
            cout << "\n";
            start += delta;
        }
    }
    else {
        while (start >= end) {
            for (int i = 0; i < start; ++i) {
                cout << "*";
            }
            cout << "\n";
            start += delta;
        }
    }

    return 0;
}