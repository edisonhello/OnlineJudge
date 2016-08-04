//
// Created by Wayne Tu on 4/26/16.
//
#include <iostream>
#include <stdio.h>
using namespace std;

struct group {
    int student[3000] = {0};
    int len;
    void repeat(int num) {
        bool go = true;
        for (int i = 0; i < len && go; i++) {
            if (student[i] == num) {
                student[i] = 0;
                go = false;
            }
        }
    }
};


int main() {
    int N, M;
    cin >> N >> M;

}