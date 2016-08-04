//
// Created by Wayne Tu on 3/30/16.
//

#include <iostream>
#include <vector>
using namespace std;

int count(vector<int> array, int num) {
    int count = 1;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == num) {
            while (array[i + 1] == array[i]) {
                count++;
                i++;
            }

            break;
        }
    }

    return count;
}

int main() {
    int num;
    cin >> num;
        int k = 2;
        int i = 0;
        vector<int> array;
        while (i <= num) {
            if (num % k == 0) {
                array.push_back(k);
                i++;
                num /= k;
            }
            else {
                k++;
            }
        }
        i = 0;
        int length = array.size();
        while (i < length) {
            if (i + count(array, array[i]) == length) {
                if (count(array, array[i]) == 1) {
                    cout << array[i] << '\n';
                    break;
                }
                else {
                    cout << array[i] << '^' << count(array, array[i]) << '\n';
                }
                break;
            }
            else {
                if (count(array, array[i]) == 1) {
                    cout << array[i] << " * ";
                }
                else {
                    cout << array[i] << '^' << count(array, array[i]) << " * ";
                }
                i += count(array, array[i]);
            }
        }
    return 0;
}