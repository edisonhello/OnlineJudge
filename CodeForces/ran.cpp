#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(7122);
    vector<int> num;
    for (int i = 1; i <= 100000; ++i) num.push_back(i);
    random_shuffle(num.begin(), num.end());
    cout << 100000 << '\n';
    for (int i : num) cout << i << ' ';
    return cout << '\n', 0;
}
