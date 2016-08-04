#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> station;
stack<int> rail;
int A[1000], B[1000];
int N, M;

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        A[i] = i + 1;
        scanf("%d", &B[i]);
    }
    int Bi = 0;
    int Ai = 0;
    bool yes = true;
    while (Bi < N && yes) {
        if (station.empty()) {
            station.push(A[Ai]);
            Ai++;
        }
        else if (station.top() == B[Bi]) {
            station.pop();
            Bi++;
        }
        else if (station.top() < B[Bi]) {
            station.push(A[Ai]);
            Ai++;
        }
        else {
            if (rail.size() > M) {
                yes = false;
            }
            else if (rail.top() == B[Bi]) {
                station.push(rail.top());
                rail.pop();
                station.pop();
                Bi++;
            }
            else if (rail.top() < B[Bi]) {
                rail.push(station.top());
                station.pop();
            }
            else {
                yes = false;
            }
        }
    }
    if (yes) printf("yes\n");
    else printf("no\n");
    return 0;
}