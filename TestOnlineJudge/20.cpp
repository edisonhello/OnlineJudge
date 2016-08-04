//
// Created by Wayne Tu on 4/29/16.
//

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

struct queue {
    int member[1000];
    int rear = -1;
    int top = -1;
    void enqueue(int m) {
        member[++rear] = m;
    }
    int dequeue() {
        return member[++top];
    }
    bool empty() {
        return top == rear;
    };
};

int main() {
    int N;
    scanf("%d", &N);
    vector<vector<int>> groups;
    group.resize(N);
    for (int i = 0; i < N; i++) {
        int k;
        vector<int> group;
        scanf("%d", &k);
        group.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> group[j];
        }
        groups[i] = group;
    }
    vector<queue> line;
    line.resize(N);
    char com[10];
    while (true) {
        cin >> com;
        if (com[0] == 'E') {
            int n;
            cin >> n;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < groups[i].size(); j++) {
                    if (groups[i][j] == n) {

                    }
                }
            }
        }
    }
}