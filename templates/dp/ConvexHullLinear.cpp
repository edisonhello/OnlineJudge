struct ConvexHull {
    // Max convex hull
    deque<pair<int, int>> dq;
    bool check(const pair<int, int>& l1, const pair<int, int>& l2, int x) {
        // for min case, replace <= with >=
        return l1.first * x + l1.second <= l2.first * x + l2.second;
    }
    bool elim(const pair<int, int>& l1, const pair<int, int>& l2, const pair<int, int>& l) {
        return (double)(l1.second - l2.second) / (double)(l2.first - l1.first) <= (double)(l.second - l2.second) / (double)(l2.first - l.first);
    }
    int query(int x) {
        while (dq.size() >= 2 && check(dq[0], dq[1], x)) dq.pop_front();
        return dq.front().first * x + dq.front().second;
    }
    void add(int a, int b) {
        while (dq.size() >= 2 && elim(dq[dq.size() - 1], dq[dq.size() - 2], make_pair(a, b))) dq.pop_back();
        dq.push_back(make_pair(a, b));
    }
};
