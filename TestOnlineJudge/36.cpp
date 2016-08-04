//
// Created by Wayne Tu on 4/15/16.
//

#include <iostream>
using namespace std;

int main() {
    int* ptr;
    int T;
    scanf("%d", &T);
    ptr = new int[T];
    int len = 0;
    int top = -1;
    for (int i = 0; i < T; ++i) {
        int commend;
        scanf("%d", &commend);
        if (commend == 1) {
            int n;
            scanf("%d", &n);
            ptr[++top] = n;
            len++;
        }

        else if (commend = 2) {
            if (len == 0) {
                printf("empty!\n");
            }
            else {
                printf("%d\n", ptr[top--]);
                len--;
            }
        }
    }
}