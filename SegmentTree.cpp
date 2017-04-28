#include <bits/stdc++.h>

template <class T>
class SegmentTree {
    private:
        int _L, _R;
        struct Seg {
            Seg *lc, *rc;
            T val, tag;
            std::function<T(T, T)> func;
            Seg(int L, int R, std::function<T(T, T)> f) {
                func = f;
                if (L == R) { val = 0; tag = 0; return; }
                int M = (L + R) >> 1;
                lc = new Seg(L, M, f);
                rc = new Seg(M + 1, R, f);
                pull();
            }
            Seg(int L, int R, const std::vector<T> v, std::function<T(T, T)> f) {
                func = f;
                if (L == R) { val = v[L]; tag = 0; return; }
                int M = (L + R) >> 1;
                lc = new Seg(L, M, f);
                rc = new Seg(M + 1, R, f);
                pull();
            }
            void set(int L, int R, int l, int r, T _val) {
                push();
                if (L > r || l > R) return;
                if (L >= l && R <= r) {
                    val = _val;
                    tag = _val;
                    return;
                }
                int M = (L + R) >> 1;
                lc->set(L, M, l, r, _val); rc->set(M + 1, R, l, r, _val);
                pull();
            }
            void modify(int L, int R, int l, int r, T _val) {
                push();
                if (L > r || l > R) return;
                if (L >= l && R <= r) {
                    val = func(val, _val);
                    tag = func(tag, _val);
                    return;
                }
                int M = (L + R) >> 1;
                lc->modify(L, M, l, r); rc->modify(M + 1, R, l, r);
                pull();
            }
            T query(int L, int R, int l, int r) {
                if (L > r || l > R) return 0;
                if (L >= l && R <= r) return val;
                int M = (L + R) >> 1;
                return func(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
            }
            void pull() {
                val = 0;
                if (lc) val = func(val, lc->val);
                if (rc) val = func(val, rc->val);
            }
            void push() {
                if (!tag) return;
                if (lc) lc->tag = func(lc->tag, tag), lc->val = func(lc->val, tag);
                if (rc) rc->tag = func(rc->tag, tag), rc->val = func(rc->val, tag);
                tag = 0;
            }
        } *root;
    public:
        SegmentTree(int L, int R, std::function<T(T,T)> f) {
            _L = L, _R = R;
            root = new Seg(L, R, f);
        }
        SegmentTree(int L, int R, const std::vector<T> v, std::function<T(T, T)> f) {
            _L = L, _R = R;
            root = new Seg(L, R, v, f);
        }
        void modify(int l, int r, T val) {
            root->modify(_L, _R, l, r, val);
        }
        void set(int l, int r, T val) {
            root->set(_L, _R, l, r, val);
        }
        T query(int l, int r) {
            return root->query(_L, _R, l, r);
        }
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n; std::cin >> n;
    std::vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) std::cin >> v[i];
    SegmentTree<int> st(0, n - 1, v, std::less<int>());
    int tp; while (std::cin >> tp) {
        if (tp == 1) {
            int l, r, x; std::cin >> l >> r >> x;
            st.set(l, r, x);
        } else {
            int l, r; std::cin >> l >> r;
            std::cout << st.query(l, r) << '\n';
        }
    }
    return 0;
}
