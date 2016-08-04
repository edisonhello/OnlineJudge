//
// Created by Wayne Tu on 5/14/16.
//
#include <string.h>

int hex2dec(char* hex) {
    int l = strlen(hex);
    int dec = 0;
    for (int i = 0; i < l; ++i) {
        dec *= 16;
        switch(hex[i]) {
            case 'A':
                dec += 10;
                break;
            case 'B':
                dec += 11;
                break;
            case 'C':
                dec += 12;
                break;
            case 'D':
                dec += 13;
                break;
            case 'E':
                dec += 14;
                break;
            case 'F':
                dec += 15;
                break;
            default:
                dec += hex[i] - '0';
                break;
        }
    }
    return dec;
}