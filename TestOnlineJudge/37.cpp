//
// Created by Wayne Tu on 4/15/16.
//
#include <iostream>
using namespace std;

int main() {
    int* queue;
    int T;
    scanf("%d", &T);
    queue = new int[T];
    int top = 0;
    int rear = -1;
    int len = 0;
    for (int i = 0; i < T; ++i) {
        int commend;
        scanf("%d", &commend);
        if (commend == 1) {
            int num;
            scanf("%d", &num);
            queue[++rear] = num;
            len++;
        }
        else if (commend == 2) {
            if (len == 0) {
                printf("empty!\n");
            }
            else {
                printf("%d\n", queue[top++]);
                len--;
            }
        }
    }
}