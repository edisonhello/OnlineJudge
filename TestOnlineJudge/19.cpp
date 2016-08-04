//
// Created by Wayne Tu on 4/7/16.
//

#include <iostream>
#include <stdio.h>
using namespace std;

struct stack {
    int data[10000];
    int top = -1;
    void push(int x) {
        data[++top] = x;
    }
    int pop() {
        return data[top--];
    }
    bool empty() {
        return top == -1;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int* order;
        int N;
        scanf("%d", &N);
        order = new int[N];
        for (int j = 0; j < N; j++) {
            int temp;
            scanf("%d", &temp);
            order[j] = temp;
        }
        int k = 1;
        int idx = 0;
        stack train;
        bool ans = true;
        while (idx < N) {
            if (train.empty()) {
                train.push(k);
                k++;
            }
            else if (train.data[train.top] == order[idx]) {
                train.pop();
                idx++;
            }
            else if (train.data[train.top] < order[idx]) {
                train.push(k);
                k++;
            }
            else {
                ans = false;
                break;
            }
        }
        if (ans) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }

        delete order;
    }
    return 0;
}