#include <bits/stdc++.h>
using namespace std;

vector<int> gen(int x) {
    vector<int> vec;
    int i = (x / 50) % 475;
    for (int j = 0; j < 25; ++j) {
        i = (i * 96 + 42) % 475;
        vec.push_back(26 + i);
    }
    return vec;
}

int main() {
    vector<int> vec = gen(1000);
    cout << vec[0] << endl;
}
