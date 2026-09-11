#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define IO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

const int mod = 998244353;
struct Point {
    int x, y, id;
    Point operator+(const Point& b) const { return Point{x + b.x, y + b.y}; }
    Point operator-(const Point& b) const { return Point{x - b.x, y - b.y}; }
    ll operator*(const Point& b) const { return (ll)x * b.y - (ll)y * b.x; }
    bool operator<(const Point& b) const { return x == b.x ? y < b.y : x < b.x; }
    void operator+=(const Point& b) {
        x += b.x;
        y += b.y;
    }
    void operator-=(const Point& b) {
        x -= b.x;
        y -= b.y;
    }
    void operator*=(const int k) {
        x *= k;
        y *= k;
    }
    ll cross(const Point& b, const Point& c) const {
        return (b - *this) * (c - *this);
    }
};

vector<Point> v;

signed main() {
    IO;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y, i + 1});
    }
    sort(v.begin(), v.end());
    int S = 0;
    vector<Point> hull;
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++) {
            while ((int)hull.size() - S >= 2) {
                Point P1 = hull[hull.size() - 2];
                Point P2 = hull[hull.size() - 1];
                if (P1.cross(P2, v[i]) <= 0)
                    break;
                hull.pop_back();
            }
            hull.push_back(v[i]);
        }
        hull.pop_back();
        S = hull.size();
        reverse(all(v));
    }

    cout << 1 << "\n";
    cout << n << ' ';
    for (int i = 0, cnt = 0; cnt < n; i = (i + n / 2) % n, cnt++) {
        cout << hull[i].id << " ";
    }
    cout << "\n";
}