struct DisjointSet {
    int p[maxn], sz[maxn], n;
    vector<pair<int*, int>> h;
    vector<int> sp;
    void init(int size) {
        n = size;
        for (int i = 0; i < n; ++i) p[i] = i, sz[i] = 1;
        sp.clear(); h.clear();
    }
    void assign(int *k, int v) {
        h.push_back(make_pair(k, *k));
        *k = v;
    }
    void save() {
        sp.push_back(h.size());
    }
    void undo() {
        int last = sp.back(); sp.pop_back();
        while (h.size() != last) {
            pair<int*, int> pi = h.back(); h.pop_back();
            *pi.first = pi.second;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        assign(&sz[x], sz[x] + sz[y]);
        assign(&p[y], x);
    }
};
