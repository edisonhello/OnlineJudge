//
// Created by Wayne Tu on 4/7/16.
//

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct charStack {
    char data[150];
    int top = -1;
    void push(char c) {
        data[++top] = c;
    }
    char pop() {
        return data[top--];
    }
    bool empty() {
        return top == -1 ? true : false;
    }
};

struct intStack {
    int data[150];
    int top = -1;
    void push(int n) {
        data[++top] = n;
    }
    char pop() {
        return data[top--];
    }
    bool empty() {
        return top == -1 ? true : false;
    }
};


int priority(char c) {
    switch(c) {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
    }
}

int solve(char str[]) {
    charStack op1;
    intStack op2;
    vector<char> postfix;
    int i = 0;
    while (i < strlen(str)) {
        if (str[i] >= '0' && str[i] <= '9') {
            postfix.push_back(str[i]);
            i++;
        }
        else {
            if (str[i] == ')') {
                do {
                    postfix.push_back(op1.pop());
                } while (op1.data[op1.top] != '(');
                i++;
                op1.pop();
            }

            else if (op1.empty() || priority(str[i]) > priority(op1.data[op1.top]) || str[i] == '(') {
                op1.push(str[i]);
                i++;
            }

            else if (priority(str[i]) < op1.data[op1.top]) {
                while (priority(str[i]) < priority(op1.data[op1.top])) {
                    postfix.push_back(op1.pop());
                }
                op1.push(str[i]);
                i++;
            }
        }
    }
    while (!op1.empty()) {
        postfix.push_back(op1.pop());
    }


    i = 0;
    while (op2.top != 0 && i == postfix.size() - 1) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            op2.push(postfix[i] - '0');
            i++;
        }
        else {
            int x = op2.pop();
            int y = op2.pop();
            switch(postfix[i]) {
                case '+':
                    op2.push(x + y);
                    break;
                case '-':
                    op2.push(x - y);
                    break;
                case '*':
                    op2.push(x * y);
                    break;
                case '/':
                    op2.push(x / y);
                    break;
            }
            i++;
        }
    }
    return op2.data[0];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char str[150];
        cin >> str;
        printf("%d\n", solve(str));
    }
    return 0;
}