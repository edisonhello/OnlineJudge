struct pt {
    double x, y;
    pt(): x(0.0), y(0.0) {}
    pt(double x, double y): x(x), y(y) {}
    pt operator+(const pt& a) const { return pt(x + a.x, y + a.y); }
    pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
    double operator*(const pt& a) const { return x * a.x + y * a.y; }
    double operator^(const pt& a) const { return x * a.y - y * a.x; }
    bool operator<(const pt& a) const { return x == a.x ? y < a.y : x < a.x; }
};
