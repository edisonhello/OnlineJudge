#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char record[10000];

int main(void) {
    while (scanf("%s", record) != EOF) {
        int base[4] = {0};
        int score[2] = {0};
        int team = 0;
        int index = 0;
        int out = 0;
        while (index < strlen(record)) {
            if (out == 3) {
                out = 0;
                team = team == 0 ? 1 : 0;
                base[1] = base[2] = base[3] = 0;
            }
            else if (record[index] == 'K' || record[index] == 'O') {
                out++;
                index++;
            }
            else if (record[index] == 'S') {
                score[team] += base[3];
                base[3] = base[2];
                base[2] = base[1];
                base[1] = 1;
                index++;
            }
            else if (record[index] == 'D') {
                score[team] += base[2] + base[3];
                base[3] = base[1];
                base[2] = 1;
                base[1] = 0;
                index++;
            }
            else if (record[index] == 'T') {
                score[team] += base[1] + base[2] + base[3];
                base[3] = 1;
                base[2] = base[1] = 0;
                index++;
            }
            else if (record[index] == 'H') {
                score[team] += base[1] + base[2] + base[3] + 1;
                base[1] = base[2] = base[3] = 0;
                index++;
            }
        }
        cout << score[0] << ' ' << score[1] << endl;
    }
	return 0;
}
