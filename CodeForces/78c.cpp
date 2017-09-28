#include <bits/stdc++.h>
using namespace std;

const int maxn = 32000;
vector<int> prime;
bool v[maxn];

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < maxn; ++j) {
            v[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
}
