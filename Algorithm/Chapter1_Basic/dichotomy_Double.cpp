//浮点数二分法

bool check(int x) { /*...*/ } //检查x是否满足某种性质

double bSearch_double(double l, double r) {
    const double eps = 1e-6;
    while ((r - l) > eps) {
        double mid = (r + l )/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
