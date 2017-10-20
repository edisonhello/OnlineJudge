#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

struct trie {
    trie *ch[2];
    int cnt;
    trie() {
        cnt = 0;
        ch[0] = ch[1] = nullptr;
    }
    void insert(int v, int d) {
        if (d < 0) return;
        int b = (v >> d) & 1;
        if (!ch[b]) ch[b] = new trie();
        ++ch[b]->cnt;
        ch[b]->insert(v, d - 1);
    }
    void erase(int v, int d) {
        if (d < 0) return;
        int b = (v >> d) & 1;
        --ch[b]->cnt;
        ch[b]->erase(v, d - 1);
    }
    pair<int, int> query(int v, int d, int pc) {
        if (d < 0) return make_pair(0, pc);
        int b = (v >> d) & 1;
        if (b == 1) {
            pair<int, int> p0 = make_pair(0, 0), p1 = make_pair(0, 0);
            if (ch[0] && ch[0]->cnt) p0 = ch[0]->query(v, d - 1, ch[0]->cnt);
            if (ch[1] && ch[1]->cnt) p1 = ch[1]->query(v, d - 1, ch[1]->cnt);
            if (p0.first > p1.first) return make_pair((1 << d) + p0.first, p0.second);
            else if (p0.first < p1.first) return make_pair((1 << d) + p1.first, p1.second);
            return make_pair((1 << d) + p1.first, p0.second + p1.second);
        } 
        if (ch[1] && ch[1]->cnt) {
            pair<int, int> p = ch[1]->query(v, d - 1, ch[1]->cnt);
            return make_pair((1 << d) + p.first, p.second);
        }
        return ch[0]->query(v, d - 1, ch[0]->cnt);
    }
} *tr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    tr = new trie();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tr->insert(a[i], 18);
    }
    pair<int, int> ans = make_pair(0, 0);
    for (int i = 0; i < n; ++i) {
        tr->erase(a[i], 18);
        // cout << a[i] << endl;
        pair<int, int> k = tr->query(a[i], 18, 0);
        // cout << k.first << ' ' << k.second << endl;
        if (k.first > ans.first) ans = k;
        else if (k.first == ans.first) ans.second += k.second;
        tr->insert(a[i], 18);
    }
    cout << ans.first << ' ' << ans.second / 2 << endl;
    return 0;
}
