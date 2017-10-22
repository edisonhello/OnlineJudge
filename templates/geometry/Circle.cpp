struct circle {
    pt o;
    type r;
    circle() {}
    circle(const pt &p, const type &d): o(p), r(d) {}
    circle(const type &x, const type &y, const type &d): o(pt(x, y)), r(d) {}
    double operator()() const { return pi * r * r; }
    bool overlap(const pt &p) const { return p.dist(o) <= r; }
    bool on(const pt &p) const { return p.dist(o) == r; }
};
