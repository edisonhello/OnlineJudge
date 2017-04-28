#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
int N, Q, a[maxn], pos[maxn], L, R, v;

struct Node {
    int lim;
    Node* ch[2];
    Node() { ch[0] = ch[1] = NULL; }
    Node(Node* p) {
        if (!p) {
            lim = 0;
            ch[0] = ch[1] = NULL;
            return;
        }
        lim = p->lim;
        ch[0] = p->ch[0];
        ch[1] = p->ch[1];
    }
} *root[maxn];

Node* modify(Node*, int, int);
int query(Node*, int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = N - 1; i >= 0; --i) pos[i] = pos[i + 1] ^ a[i];
    root[N] = new Node();
    for (int i = N - 1; i >= 0; --i) root[i] = modify(root[i + 1], i, 29);
    while (Q--) {
        cin >> L >> R >> v;
        cout << query(root[L], R, v ^ pos[R], 29) << '\n';
    }
    return 0;
}

Node* modify(Node* node, int i, int depth) {
    if (depth < -1) return NULL;
    Node* tmp = new Node(node);
    tmp->lim = i;
    tmp->ch[(pos[i] & (1 << depth)) ? 1 : 0] = modify(tmp->ch[(pos[i] & (1 << depth)) ? 1 : 0], i, depth - 1);
    return tmp;
}

int query(Node* node, int r, int v, int depth) {
    if (depth < 0) return 0;
    if (node->ch[(v & (1 << depth)) ? 0 : 1] && node->ch[(v & (1 << depth)) ? 0 : 1]->lim < r) return (1 << depth) + query(node->ch[(v & (1 << depth)) ? 0 : 1], r, v, depth - 1);
    return query(node->ch[(v & (1 << depth)) ? 1 : 0], r, v, depth - 1);
}
