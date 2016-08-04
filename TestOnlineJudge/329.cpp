//
// Created by Wayne Tu on 4/28/16.
//

#include <iostream>
#include <stdio.h>
using namespace std;
struct queue {
    char data[100];
    int rear = -1;
    int top = -1;
    void enqueue(char c) {
        data[++rear] = c;
    }
    char dequeue() {
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
    char start[1000];
    cin >> start;
    char command[20];
    queue ans;
    for (int i = 0; i < strlen(start); i++) {
        ans.enqueue(start[i]);
    }
    while (true) {
        cin >> command;
        if (command == "end") {
            break;
        }
        else if (command == "insert_front") {

        }
        else if (command == "insert_back") {

        }
        else if (command == "delete") {

        }
    }
}