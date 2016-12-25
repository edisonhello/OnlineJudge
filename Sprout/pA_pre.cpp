#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int T, N;
string s;
bool v[10];

bool jizz(int n) {
    if (n == 0 && v[0]) return false;
    while (n) {
        if (v[n % 10]) return false;
        n /= 10;
    }
    return true;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N >> s;
        memset(v, false, sizeof(v));
        for (int i = 0; i < 10; ++i) v[i] = s[i] == '0';
        do {
            if (jizz(N)) { cout << N << '\n'; break; }
        } while (++N);
    }
}
