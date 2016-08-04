//
// Created by Wayne Tu on 4/28/16.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    char str[10];
    cin >> str;
    char code[101];
    cin >> code;
    if (str[0] == 'e') {
        for (int i = 0; i < strlen(code); i++) {
            switch(code[i]) {
                case 'X':
                    cout << 'A';
                    break;
                case 'Y':
                    cout << 'B';
                    break;
                case 'Z':
                    cout << 'C';
                    break;
                case 'x':
                    cout << 'a';
                    break;
                case 'y':
                    cout << 'b';
                    break;
                case 'z':
                    cout << 'c';
                    break;
                default:
                    cout << (char)(code[i] + 3);
                    break;
            }
        }
    }
    else {
        for (int i = 0; i < strlen(code); i++) {
            switch(code[i]) {
                case 'A':
                    cout << 'X';
                    break;
                case 'B':
                    cout << 'Y';
                    break;
                case 'C':
                    cout << 'Z';
                    break;
                case 'a':
                    cout << 'x';
                    break;
                case 'b':
                    cout << 'y';
                    break;
                case 'c':
                    cout << 'z';
                    break;
                default:
                    cout << (char)(code[i] - 3);
                    break;
            }
        }
    }
    return 0;
}
