#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

vector<int> G[505];
int N, K, R, C, mx[505], my[505], ret, ans;
bool v[505];
int matching();
bool DFS(int);

int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> R >> C;
        G[R].push_back(C);
    }
    ans = matching();
    cout << ans << endl;
    return 0;
}

int matching() {
    memset(my, -1, sizeof(my));
    ret = 0;
    for (int i = 1; i <= N; ++i) {
        memset(v, false, sizeof(v));
        if (DFS(i)) ret++;
    }
    return ret;
}

bool DFS(int x) {
    v[x] = true;
    for (auto i : G[x]) {
        if (my[i] == -1 || !v[my[i]] && DFS(my[i])) {
            my[i] = x;
            return true;
        }
    }
    return false;
}
