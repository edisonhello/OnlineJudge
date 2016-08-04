//
// Created by Wayne Tu on 4/4/16.
//

#include <iostream>
#include <vector>
using namespace std;

int toVector(int num, vector<int>& vec) {
    int k = 10;

    while (k < num) {
        vec.push_back(num % k);
        num = num - num % k;
        num /= 10;
    }

    int i = 0;
    int zero = 0;
    while (i < vec.size()) {
        if (vec[i] == 0) {
            zero++;
        }
        else {
            break;
        }
    }

    return zero;
}

int main() {
    int num;
    while (cin >> num ) {
        vector<int> vec;
        int zero = toVector(num, vec);
        for (int i = zero; i < vec.size(); i++) {
            cout << vec[i];
        }
    }
    return 0;
}