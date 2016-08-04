//
// Created by Wayne Tu on 4/6/16.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

void solve(string word) {
    int length = word.length();
    int l;
    if (length % 2 == 1) {
        l = length / 2 + 1;
    }

    else {
        l = length / 2;
    }

    bool correct;

    for (int i = 0; i < l; i++) {
        if (word[i] == word[length - 1 - i]) {
            correct = true;
        }

        else {
            correct = false;
            break;
        }
    }

    if (correct) {
        cout << "yes\n";
    }

    else {
        cout << "no\n";
    }
}

int main() {
    string word;
    while (cin >> word) {

        solve(word);
    }
    return 0;
}