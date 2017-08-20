typedef pair<double, double> pt;
#define x first
#define y second

double dist(const pt& a, const pt& b) { 
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double cross(const pt& o, const pt& a, const pt& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

pt operator-(const pt& a, const pt& b) {
    return make_pair(a.x - b.x, a.y - b.y);
}

pt operator+(const pt& a, const pt& b) {
    return make_pair(a.x + b.x, a.y + b.y);
}
