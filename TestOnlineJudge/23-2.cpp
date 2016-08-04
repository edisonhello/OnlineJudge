//
// Created by Wayne Tu on 4/15/16.
//

void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();
void no_solution();

struct stack {
    int data[5000];
    int top = -1;
    void push(int n) {
        data[++top] = n;
    }
    int pop() {
       return data[top--];
    }
    bool empty() {
        return top == -1 ? true : false;
    }
};

void solve(int N, int order[]) {
    stack station1;
    stack station2;
    for (int i = 0; i < N; ++i) {
        station1.push(i + 1);
    }
    int i = 0;
    int count = 0;
    while (count <= N) {
        do {
            move_station_1_to_2();
            station2.push(station1.pop());
        } while (station2.data[station2.top] != order[i]);

        pop_train();
        station2.pop();
        ++i;
        ++count;
        do {
            move_station_2_to_1();
            station1.push(station2.pop());
        } while (!station2.empty());
    }
}