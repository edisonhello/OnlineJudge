#include <bits/stdc++.h>
#define Size(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 50000 + 5;

struct Treap {
    char c;
    int pri, sz;
    Treap *l, *r;
    Treap(char c): c(c) {
        pri = rand();
        l = r = NULL;
        sz = 1;
    }
    Treap(Treap* t) {
        l = t->l;
        r = t->r;
        sz = t->sz;
        c = t->c;
        pri = t->pri;
    }
} *ver[maxn];

string s;
int N, ccnt, t, p, c, v, cur;

Treap* copy(Treap*);
Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
void pull(Treap*);
void insert(int, int, const string&);
void remove(int, int, int);
void print(Treap*);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i <= N; ++i) ver[i] = NULL;
    for (int i = 1; i <= N; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> p >> s;
            p -= ccnt;
            insert(++cur, p, s);
        }   
        if (t == 2) {
            cin >> p >> c;
            p -= ccnt, c -= ccnt;
            remove(++cur, p, c);
        }
        if (t == 3) {
            cin >> v >> p >> c;
            v -= ccnt, p -= ccnt, c -= ccnt;
            Treap *a, *b, *d, *e;
            split(ver[v], p - 1, a, b);
            split(b, c, d, e);
            print(d); cout << '\n';
        }
    }
    return 0;
}

Treap* copy(Treap* t) {
    if (!t) return NULL;
     Treap* ret = new Treap(t);
    return ret;
}

Treap* merge(Treap* a, Treap* b) {
    if (!a || !b) return a ? copy(a) : copy(b);
    if (a->pri > b->pri) {
        a = copy(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        b = copy(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

void split(Treap* t, int sz, Treap*& a, Treap*& b) {
    if (!t) { a = copy(NULL); b = copy(NULL); return; }
    if (Size(t->l) + 1 <= sz) {
        a = copy(t);
        split(t->r, sz - Size(t->l) - 1, a->r, b);
        pull(a);
    } else {
        b = copy(t);
        split(t->l, sz, a, b->l);
        pull(b);
    }
}

void pull(Treap* t) {
    if (!t) return;
    t->sz = Size(t->l) + Size(t->r) + 1;
}

void insert(int v, int p, const string& s) {
    Treap *a, *b;
    split(ver[v - 1], p, a, b);
    for (int i = 0; i < s.length(); ++i) a = merge(a, new Treap(s[i]));
    ver[v] = merge(a, b);
}

void remove(int v, int p, int c) {
    Treap *a, *b, *d, *e;
    split(ver[v - 1], p - 1, a, b);
    split(b, c, d, e);
    ver[v] = merge(a, e);
}

void print(Treap* t) {
    if (!t) return;
    if (t->l) print(t->l);
    if (t->c == 'c') ++ccnt;
    cout << t->c;
    if (t->r) print(t->r);
}
