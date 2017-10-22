void convex() {
    deque<segment> dq; dq.push_back({ 0, 1, n });
    for (int i = 1; i <= n; ++i) {
        dp[i] = f(dq.front().i, i);
        while (dq.size() && dq.front().r < i + 1) 
            dq.pop_front();
        dq.front().l = i + 1;
        while (dq.size() && f(i, dq.back().l) < f(dq.back().i, dq.back().l)) 
            dq.pop_back();
        segment new_seg = { i, i + 1, n };
        if (dq.size()) {
            int c = bs();
            // c is the maximal k such that f(i, k) > f(dq.back().i, k)
            dq.back().r = c;
            new_seg.l = c + 1;
        }
        if (new_seg.l <= n) dq.push_back(new_seg);
    }
}
