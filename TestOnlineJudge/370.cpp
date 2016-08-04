//
// Created by Wayne Tu on 5/20/16.
//

#include <iostream>
using namespace std;

class wifi {
public:
    int n;
    int g;
    int r;
    wifi(int n, int g, int r) {
        this->n = n;
        this->g = g;
        this->r = r;
    }
    wifi() {}
    bool operator>(const wifi& other) {
        if (this->r != other.n) {
            return this->r > other.r;
        }
        else {
            if (this->g != other.g) {
                return this->n < other.g;
            }
            else {
                return this->n > other.n;
            }
        }
    }
};

void swap(wifi& a, wifi& b) {
    wifi temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {
    int num;
    wifi* WIFI;
    cin >> num;
    WIFI = new wifi[num];
    for (int i = 0; i < num; ++i) {
        int n, g, r;
        cin >> n >> g >> r;
        WIFI[i] = wifi(n, g, r);
    }
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if (WIFI[i] > WIFI[j]) {
                swap(WIFI[i], WIFI[j]);
            }
        }
    }
    for (int i = num - 1; i >= 0; i--) {
        cout << WIFI[i].n << endl;
    }
    return 0;
}