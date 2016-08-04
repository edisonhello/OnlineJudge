//
// Created by Wayne Tu on 4/15/16.
//

//
// Created by Wayne Tu on 3/30/16.
//
#include <list>
void solve(int N, int order[]);
void push_train();
void move_station_1_to_2();
void move_station_2_to_1();
void pop_train();
void no_solution();

using namespace std;


list1::iterator it1;
list2::iterator it2;

void solve(int N, int order[]) {

    list1 station1;
    list2 station2;


    for (int i = 0; i < N; i++) {
        station1.push_back(i + 1);
        push_train();
    }

    it1 = station1.end();
    it2 = station2.end();
    int i = 0;

    while (!station1.empty() || !station2.empty()) {
        if (order[i] < *it1) {
            station2.push_back(*it1);
            move_station_1_to_2();
            it1 = station1.erase(it1);
            it1--;
        }

        else if (order[i] > *it1) {
            station1.push_back(*it2);
            move_station_2_to_1();
            it2 = station2.erase(it2);
            it2--;
        }

        else {
            station2.push_back(*it1);
            it1 = station1.erase(it1);
            pop_train();
            it2 = station2.erase(it2);
            i++;
            it2--;
        }
    }
}