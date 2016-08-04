//
// Created by Wayne Tu on 5/24/16.
//

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class hero {
public:
    char name[21];
    int ability[5];
    hero(char name[], int a, int b, int c, int d, int e) {
        int l = strlen(name);
        for (int i = 0; i < l; i++) {
            this->name[i] = name[i];
        }
        ability[0] = a;
        ability[1] = b;
        ability[2] = c;
        ability[3] = d;
        ability[4] = e;
    }
    hero() {}

    int power() {
        int total = 0;
        for (int i = 0; i < 5; ++i) {
            if (i == 1 || i == 4) {
                total += ability[i] * 2;
            }
            else {
                total += ability[i];
            }
        }
    }
};

int main() {
    hero* list;
    int n;
    cin >> n;
    list = new hero[n];
    for (int i = 0; i < n; ++i) {
        char name[21];
        cin >> name;
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        list[i] = hero(name, a, b, c, d, e);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (list[i].power() < list[j].power()) {
                hero temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
            else if (list[i].power() == list[j].power()) {
                if (list[i].ability[1] < list[j].ability[1]) {
                    hero temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
                else if (list[i].ability[4] < list[j].ability[4]) {
                    hero temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
                else if (list[i].ability[0] < list[j].ability[0]) {
                    hero temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
                else if (list[i].ability[2] < list[j].ability[2]) {
                    hero temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
                else if (list[i].ability[3] < list[j].ability[3]) {
                    hero temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << list[i].name << endl;
    }
    return 0;
}