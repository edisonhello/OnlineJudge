//
// Created by Wayne Tu on 3/10/16.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace tsd;

struct ll {
    int num[400];
    static int n = 200;

    int& operator[](int x) {
        return num[x + n];
    }

    ll() {fill(num, num + 401, 0);}

    ll(string s) {
        ll& now = *this;
        int sn = s.size();
        fill(num, num + 401, 0);
        for (int i = 0; i < sn; ++i) {
            now[i] = s[sn - i - 1] - '0';
        }
    }

};