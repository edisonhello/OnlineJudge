#include <bits/stdc++.h>
#define Lc(id) id << 1
#define Rc(id) id << 1 | 1
using namespace std;

struct Color {
    int R, G, B, cnt;
};

const int maxn = 1000 + 5;
int N;
Color seg[maxn][maxn];

void modifyX(int, int, int, int, int, int, int, int, int, int);
void modifyY(int, int, int, int, int, int, int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> R >> G >> B;
        modifyX(1, 0, 1000, x1, x2, y1, y2, R, G, B);
    }
    return 0;
}

void modifyX(int id, int L, int R, int x1, int x2, int y1, int y2, int R, int G, int B) {
    if (L == R) { modifyY(1, 0, 1000, L, y1, y2, R, G, B); return; }
    int M = (L + R) >> 1;
    modifyX(Lc(id), L, M, x1, x2, y1, y2, R, G, B);
    modifyX(Rc(id), M + 1, R, x1, x2, y1, y2, R, G, B);
    pullX(id);
}

void modifyY(int id, int L, int R, int x, int y1, int y2, int R, int G, int B) {
    if (L == R) {
        seg[x][L].R = 
