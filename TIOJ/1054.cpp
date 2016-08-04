#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string solve1(int n) {
    switch(n) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
    }
}

int solve2(string s) {
    switch(s[0]) {
        case 'S': {
            if (s[1] == 'a') return 6;
            else return 0;
        }
        case 'M': return 1;
        case 'T': {
            if (s[1] == 'u') return 2;
            else return 4;
        }
        case 'W': return 3;
        case 'F': return 5;
    }
}

int main() {
    string s;
    cin >> s;
    int n;
    scanf("%d", &n);
    n += solve2(s);
    n %= 7;
    cout << solve1(n) << endl;
    return 0;
}