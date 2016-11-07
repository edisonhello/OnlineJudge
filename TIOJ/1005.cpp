#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a > b) return gcd(a % b, b);
    else return gcd(a, b % a);
}
int main() {
    double pi;
    int n;
    int* ptr;
    while (true) {
        cin >> n;
        if (n == 0) break;
        ptr = new int[n];
        for (int i = 0; i < n; i++) cin >> ptr[i];
        double count = 0.;
        double total = 0.;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (gcd(ptr[i], ptr[j]) == 1) {
                    count++;
                }

            }
        }
        total = n * (n - 1) / 2;
        if (count == 0) {
            cout << "No estimate for this data set." << endl;
        }
        else {
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout.precision(6);
            pi = sqrt((6 * total) / count);
            cout << pi << endl;
        }
    }
    return 0;

}
