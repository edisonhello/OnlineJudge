type orient(const pt& o, const pt& a, const pt& b) {
    type t = (a - o) ^ (b - o);
    return t / max(1, abs(t));
}

// if parallel and min(p1, p2) != max(q1, q2) and p1 != p2 and q1 != q2 ==> segment
// else ==> point

bool intersect(const pt& p1, const pt& p2, const pt& q1, const pt& q2) {
    if (q1 == q2 && p1 == p2) return p1 == q1;
    if (q1 == q2) return ((p2 - q1) ^ (p1 - q1)) == 0 && q1.x >= min(p1.x, p2.x) && q1.x <= max(p1.x, p2.x);
    if (p1 == p2) return ((q1 - p1) ^ (q2 - p1)) == 0 && p1.x >= min(q1.x, q2.x) && p1.x <= max(q1.x, q2.x);
    int c = (p2 - p1) ^ (q2 - q1);
    if (c == 0) {
        if (orient(p1, p2, q1)) return false;
        return (p1 - q1) * (p2 - q1) <= 0 || (p1 - q2) * (p2 - q2) <= 0 || (q1 - p1) * (q2 - p1) <= 0 || (q1 - p2) * (q2 - p2) <= 0;
    }
    return (orient(p1, p2, q1) * orient(p1, p2, q2) <= 0) && (orient(q1, q2, p1) * orient(q1, q2, p2) <= 0);
}
