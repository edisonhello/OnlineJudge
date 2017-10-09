vector<pt> circle_intersection(const pt& o1, const double& r1, const pt& o2, const double& r2) {
    double d2 = (o1 - o2) * (o1 - o2);
    double d = sqrt(d2);
    if (d > r1 + r2) return {};
    pt u = (o1 + o2) * 0.5 + (o1 - o2) * ((r2 * r2 - r1 * r1) / (2 * d2));
    double a = sqrt((r1 + r2 + d) * (r1 - r2 + d) * (r1+ r2 - d) * (-r1 + r2 + d));
    pt v = pt(o1.y - o2.y, -o1.x + o2.x) * a / (2 * d2);
    return { u + v, u - v };
}
