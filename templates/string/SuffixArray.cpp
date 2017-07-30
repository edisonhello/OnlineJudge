class SuffixArray {
    private:
        string s;
        int sa[maxn], tmp[2][maxn], c[maxn], _lcp[maxn], r[maxn], n;
        SparseTable<int> st;
        void suffixarray() {
            int* rank = tmp[0];
            int* nRank = tmp[1];
            int A = 128;
            for (int i = 0; i < A; ++i) c[i] = 0;
            for (int i = 0; i < n; ++i) c[rank[i] = s[i]]++;
            for (int i = 1; i < A; ++i) c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; --i) sa[--c[s[i]]] = i;
            for (int m = 1; m < s.length(); m *= 2) {
                for (int i = 0; i < A; ++i) c[i] = 0;
                for (int i = 0; i < n; ++i) c[rank[i]]++;
                for (int i = 1; i < A; ++i) c[i] += c[i - 1];
                int* sa2 = nRank;
                int rk = 0;
                for (int i = n - m; i < n; ++i) sa2[rk++] = i;
                for (int i = 0; i < n; ++i) if (sa[i] >= m) sa2[rk++] = sa[i] - m;
                for (int i = n - 1; i >= 0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
                nRank[sa[0]] = rk = 0;
                for (int i = 1; i < n; ++i) {
                    if (!(rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + n < s.length() && rank[sa[i - 1] + n] == rank[sa[i] + n])) rk++;
                    nRank[sa[i]] = rk;
                }
                swap(rank, nRank);
                if (rk == n - 1) break;
                A = rk + 1;
            }
        }
    public:
        SuffixArray(string s): s(s) {
            n = (int)s.length();
        }
        SuffixArray() {}
        void solve() {
            suffixarray();
            for (int i = 0; i < n; ++i) r[sa[i]] = i;
            int ind = 0; _lcp[0] = 0;
            for (int i = 0; i < n; ++i) {
                if (!r[i]) { ind = 0; continue; }
                while (i + ind < n && s[i + ind] == s[sa[r[i] - 1] + ind]) ++ind;
                _lcp[r[i]] = ind ? ind-- : 0;
            }
            st = SparseTable<int>(n, _lcp);
        }
        int lcp(int L, int R) {
            if (L == R) return n - L - 1;
            L = r[L]; R = r[R];
            if (L > R) swap(L, R);
            ++L;
            return st.query(L, R);
        }
};;
