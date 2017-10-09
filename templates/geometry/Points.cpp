using type = int;

struct pt {
    type x, y;
    pt(): x(0), y(0) {}
    pt(type x, type y): x(x), y(y) {}
    pt operator+(const pt& a) const { return pt(x + a.x, y + a.y); }
    pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
    pt operator*(const type& t) const { return pt(x * t, y * t); }
    pt operator/(const type& t) const { return pt(x / t, y / t); }
    type operator*(const pt& a) const { return x * a.x + y * a.y; }
    type operator^(const pt& a) const { return x * a.y - y * a.x; }
    bool operator<(const pt& a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pt& a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pt& a) const { return x == a.x && y == a.y; }
    bool operator!=(const pt& a) const { return x != a.x || y != a.y; }
};

