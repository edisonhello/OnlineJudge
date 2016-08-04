//
// Created by Wayne Tu on 4/26/16.
//

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct water {
    int visit;
    char data;
    water(char temp) {
        visit = 0;
        data = temp;
    }
};

struct queue {
    char data[1000 * 1000];
    int rear = -1;
    int top = 0;
    void enqueue(char c) {
        data[++rear] = c;
    }
    char dequeue() {
        return data[top++];
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        vector<vector<water>> pool;
        queue solve;
        int H, W;
        scanf("%d%d", &H, &W);
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < M; k++) {
                char data;
                scanf("%c", &data);
                pool[j].push_back(water(data));
            }
        }
        int count = 0;
        int h, w;
        bool go = true
        for (int j = 0; j < H && go; j++) {
            for (int k = 0; k < M && go; k++) {
                if (pool[j][k].data == '.') {
                    go = false;
                    h = j;
                    w = k;
                }
            }
        }
        solve.enqueue(pool[h][w].data);

    }
}