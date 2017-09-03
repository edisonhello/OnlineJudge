void rotating_caliper(vector<pt> p) {
    vector<pt> ch = convex_hull(p);
    int tbz = ch.size();
    int lpr = 0, rpr = rsd;
    // ch[lpr], ch[rpr]
    while (lpr < rsd || rpr < tbz - 1) {
        if (lpr < rsd && rpr < tbz - 1) {
            pt rvt = ch[rpr + 1] - ch[rpr];
            pt lvt = ch[lpr + 1] - ch[lpr];
            if ((lvt ^ rvt) < 0) ++lpr;
            else ++rpr;
        }
        else if (lpr == rsd) ++rpr;
        else ++lpr;
        // ch[lpr], ch[rpr]
    }
}
