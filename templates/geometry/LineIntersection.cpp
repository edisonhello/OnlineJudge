pt intersection(const pt& p1, const pt& p2, const pt& q1, const pt& q2) {
    double f1 = (p2 - p1) ^ (q1 - p1);
    double f2 = (p2 - p1) ^ (p1 - q2);
    double f = f1 + f2;
    if (fabs(f) < eps) return pt(nan(""), nan(""));
    return q1 * (f2 / f) + q2 * (f1 / f);
}
