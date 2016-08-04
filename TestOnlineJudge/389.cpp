//
// Created by Wayne Tu on 5/24/16.
//
#include <list>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    list<int> vim;
    list::iterator it;
    for (int i = 0; i < N; ++i) {
        char c;
        cin >> c;
        switch(c) {
            case 'l': {
                if (it != vim.end()) {
                    it++;
                }
            }
            case 'h':
                if (it != vim.begin()) {
                    it--;
                }
        }
    }
}