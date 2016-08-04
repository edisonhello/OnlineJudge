//
// Created by Wayne Tu on 5/20/16.
//

#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

struct heap {
    int data[1000000];
    int last = 0;
    void push(int n) {
        if (last == 0) {
            data[++last] = n;
            return;
        }
        data[++last] = n;
        int idx = last;
        while (idx > 0) {
            if (data[idx] < data[idx / 2]) {
                swap(data[idx], data[idx / 2]);
                idx /= 2;
            }
            else
                break;
        }
    }
    int pop() {
        int ans = data[1];
        data[1] = data[last--];
        int idx = 1;
        while (true) {
            if (data[idx] > data[idx * 2]) {
                swap(data[idx], data[idx * 2]);
                idx *= 2;
            }
            else if (data[idx] > data[idx * 2 + 1]) {
                swap(data[idx], data[idx * 2 + 1]);
                idx = idx * 2 + 1;
            }
            else
                break;
        }
        return ans;
    }

    bool empty() {
        return last == 0;
    }
};

int main() {
    int T;
    cin >> T;
    heap h;
    for (int i = 0; i < T; ++i) {
        int c;
        cin >> c;
        if (c == 1) {
            int n;
            cin >> n;
            h.push(n);
        }
        else if (c == 2) {
            if (h.empty()) {
                cout << "empty!" << endl;
            }
            else
            cout << h.pop() << endl;
        }
    }
    return 0;
}