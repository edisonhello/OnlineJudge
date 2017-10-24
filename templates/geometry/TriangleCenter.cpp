pt incenter(const pt &pa, const pt &pb, const pt &pc) {
    double a = norm(pb - pc), b = norm(pc - pa), c = norm(pa - pb);
    return (pa * a + pb * b + pc * c) / (a + b + c);
}

pt circumcenter(const pt &pa, const pt &pb, const pt &pc) {
    pt ba = b - a, ca = c - a;
    double db = norm2(ba), dc = norm2(ca), d = 2.0 * (ba ^ ca);
    return a + pt(ba.y * dc - ca.y * db, ca.x * db - ba.x * dc) / 2;
}

pt othrocenter(const pt &pa, const pt &pb, const pt &pc) {
    pt pa = pb - pa, ca = pc - pa, bc = pb - pc;
    double yp = ca.y * ca.y * bc.y;
    double a = (ca ^ ba);
    double x = (yp + ca.x * ba.y * pb.x - ba.x * ca.y * pc.x) / a;
    double y = -ba.x * (x - pc.x) / ba.y + ca.y;
    return pt(x, y);
}
