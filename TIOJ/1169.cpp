#include <bits/stdc++.h>
#define __(x) cout << #x << " = " << x << '\n'
using namespace std;

const int maxn = 200000 + 5, maxc = 24;
int N, Q, C, A[maxn];

struct Node {
    int a, b, c;
    bool full;
};

struct Seg {
    Node node;
    Seg *lc, *rc;
    Seg(int len) {
        lc = rc = NULL;
        node.full = true;
        node.a = node.b = node.c = len;
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) {
            node.a = node.b = node.c = (v ^ 1);
            if (v) node.full = false;
            else node.full = true;
            return;
        }
        int M = (L + R) >> 1;
        if (x <= M) {
            if (!lc) lc = new Seg(M - L + 1);
            lc->modify(L, M, x, v);
        } else {
            if (!rc) rc = new Seg(R - M);
            rc->modify(M + 1, R, x, v);
        }
        pull(L, R);
    }
    void pull(int L, int R) {
        int M = (L + R) >> 1;
        Node q1, q2;
        if (lc) q1 = lc->node;
        else q1 = (Node){ M - L + 1, M - L + 1, M - L + 1, true };
        if (rc) q2 = rc->node;
        else q2 = (Node){ R - M, R - M, R - M, true };
        node = merge(q1, q2); 
    }
    Node merge(Node q1, Node q2) {
        int a = 0, b = 0, c = 0;
        if (q1.full) a = q1.a + q2.a;
        else a = q1.a;
        if (q2.full) b = q1.b + q2.b;
        else b = q2.b;
        c = max({ q1.c, q2.c, a, b, q2.a + q1.b });
        return (Node){  a, b, c, q1.full && q2.full };
    }
    Node query(int L, int R, int l, int r) {
        if (L > r || l > R) return (Node){ 0, 0, 0, true };
        if (L >= l && R <= r) return node;
        int M = (L + R) >> 1;
        Node q1, q2;
        int leftlen = min(M, r) - max(L, l) + 1 > 0 ? min(M, r) - max(L, l) + 1 : 0;
        int rightlen = min(R, r) - max(M + 1, l) + 1 > 0 ? min(R, r) - max(M + 1, l) + 1 : 0;
        if (lc) q1 = lc->query(L, M, l, r);
        else q1 = (Node){ leftlen, leftlen, leftlen, true };
        if (rc) q2 = rc->query(M + 1, R, l, r);
        else q2 = (Node){ rightlen, rightlen, rightlen, true };
        return merge(q1, q2);
    }
} *st[1 << maxc];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> Q >> C;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        if (!st[A[i]]) st[A[i]] = new Seg(N);
        st[A[i]]->modify(0, N - 1, i, 1);
    }
    while (Q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int x, y, k;  cin >> x >> y >> k; --y;
            if (!st[k]) cout << y - x + 1 << '\n';
            else cout << st[k]->query(0, N - 1, x, y).c << '\n';
        } else {
            int p, k; cin >> p >> k;
            st[A[p]]->modify(0, N - 1, p, 0);
            if (!st[k]) st[k] = new Seg(N);
            st[k]->modify(0, N - 1, p, 1);
            A[p] = k;
        }
    }
    return 0;
}
