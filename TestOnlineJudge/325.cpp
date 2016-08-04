//
// Created by Wayne Tu on 4/28/16.
//
#include <iostream>
using namespace std;

int main() {
    long long int prime[1000000000000000];
    for (long long int i = 0; i < 1000000000000000; i++) {
        prime[i] = i + 1;
    }
    long long int k = 2;
    while (k <= 100000000) {
        for (long long int i = 0; i < 1000000000000000; i++) {
            if (prime[i] != 0) {
                if (prime[i] / k == 0) {
                    prime[i] = 0;
                }
            }
        }
        k =
    }
}
