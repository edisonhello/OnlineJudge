//
// Created by Wayne Tu on 4/15/16.
//

//
// Created by Wayne Tu on 4/7/16.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        int k = 2;
        int count = 0;
        int sum = 1;

        while (k <= n) {
            if (k == n) {
                count++;
                sum *= (count + 1);
                break;
            }

            else if (n % k == 0) {
                count++;
                n /= k;
            }

            else {
                k++;
                if (count > 0) {
                    sum *= (count + 1);
                }

                count = 0;
            }
        }

        cout << sum << '\n';
    }

    return 0;
}