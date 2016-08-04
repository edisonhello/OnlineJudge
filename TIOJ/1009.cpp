//
// Created by Wayne Tu on 6/3/16.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int main() {
    char start[10];
    char end[10];
    int startTime[3];
    int endTime[3];
    scanf("%s %s", &start, &end);
    startTime[0] = (start[0] - '0') * 10 + start[1] - '0';
    endTime[0] = (end[0] - '0') * 10 + end[1] - '0';
    startTime[1] = (start[3] - '0') * 10 + start[4] - '0';
    endTime[1] = (end[3] - '0') * 10 + end[4] - '0';
    startTime[2] = (start[6] - '0') * 10 + start[7] - '0';
    endTime[2] = (end[6] - '0') * 10 + end[7] - '0';
    while (endTime[0] < startTime[0] || endTime[1] < startTime[1] || endTime[2] < startTime[2]) {
        if (endTime[0] < startTime[0]) endTime[0] += 24;
        if (endTime[1] < startTime[1]) {
            endTime[1] += 60;
            endTime[0] -= 1;
        }
        if (endTime[2] < startTime[2]) {
            endTime[2] += 60;
            endTime[1] -= 1;
        }
    }
    printf("%02d:%02d:%02d", endTime[0] - startTime[0], endTime[1] - startTime[1], endTime[2] - startTime[2]);
    return 0;
}