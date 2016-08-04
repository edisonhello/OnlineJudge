//
// Created by Wayne Tu on 4/6/16.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int binarySearch(vector<int> vec, int num) {
    int length = vec.size();

    int h = length / 2;

    if (num < vec[h]) {
        vector<int> newVec1;
        for (int i = 0; i < h + 1; i++) {
            newVec1.push_back(vec[i]);
        }

        return binarySearch(newVec1, num);
    }

    else if (num > vec[h]) {
        vector<int> newVec2;
        for (int i = h; i < length; i++) {
            newVec2.push_back(vec[i]);
        }

        return binarySearch(newVec2, num);
    }

    else if (num == vec[h]) {
        return h;
    }

    else {
        return -1;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    int number[k];
    for (int i = 0; i < k; i++) {
        cin >> number[i];
    }

    for (int i = 0; i < k; i++) {

        cout << binarySearch(vec, number[i]) + 1 << '\n';
    }

    return 0;
}
