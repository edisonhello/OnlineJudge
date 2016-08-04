//
// Created by Wayne Tu on 4/15/16.
//

//
// Created by Wayne Tu on 4/6/16.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;

struct coordinate {
    int x;
    int y;
    coordinate() {}
    coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

struct queue {
    coordinate data[100 * 100];
    int rear = -1;
    int top = -1;
    void enqueue(coordinate c) {
        data[++rear] = c;
    }
    coordinate dequeue() {
        return data[++top];
    }
    void clear() {
        while(rear != top) {
            dequeue();
        }
        rear = -1;
        top = -1;
    }
    bool empty() {
        return rear == top;
    }
};

int main() {
    queue solve;
    queue process;
    int N;
    scanf("%d", &N);
    char maze[N]*;
    for (int i = 0; i < N; i++) {
        scanf("%s", &maze[i]);
    }
    int len = maze[0].length();
    coordinate cat;
    coordinate mouse;
    int go = 0;
    for (int i = 0; i < N && go < 2; i++) {
        for (int j = 0; j < len && go < 2; j++) {
            if (maze[i][j] == 'K') {
                cat.x = j;
                cat.y = i;
                go++;
            }
            else if (maze[i][j] == '@') {
                mouse.x = j;
                mouse.y = i;
                go++;
            }
        }
    }
    int count = 0;
    solve.enqueue(cat);
    bool keep = true;

    return 0;
}
