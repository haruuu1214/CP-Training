#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define pdd pair<double, double>
#define X first
#define Y second
using namespace std;

pdd p[200005];
double eps = 1e-6;

pdd operator + (pdd a, pdd b) { return {a.X + b.X, a.Y + b.Y}; }
pdd operator - (pdd a, pdd b) { return {a.X - b.X, a.Y - b.Y}; }
double dot(pdd p1, pdd p2) { return p1.X * p2.X + p1.Y * p2.Y; }

double cross(pdd p1, pdd p2) { return p1.X * p2.Y - p1.Y * p2.X; }

int sign(double a)
{
    return fabs(a) < eps ? 0 : (a>0 ? 1 : -1);
}

int ori(pdd a, pdd b, pdd c)
{
    return sign( cross(b-a, c-a) );
}

bool btw(pdd a, pdd b, pdd c)
{
    if (dot(a-c, b-c) <= 0 && cross(a-c, b-c) == 0)
        return true;
    else
        return false;
}

bool banana(pdd p1, pdd p2, pdd p3, pdd p4)
{
    int a123 = ori(p1, p2, p3);
    int a124 = ori(p1, p2, p4);
    int a341 = ori(p3, p4, p1);
    int a342 = ori(p3, p4, p2);

    if (btw(p1, p2, p3) || btw(p1, p2, p4) || btw(p3, p4, p1) || btw(p3, p4, p2))
        return true;
    return (a123 * a124 < 0 && a341 * a342 < 0);
}

void solve()
{
    pdd p1, p2, p3, p4;
    cin >> p1.X >> p1.Y >> p2.X >> p2.Y >> p3.X >> p3.Y >> p4.X >> p4.Y;
    if (banana(p1, p2, p3, p4))
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    cin >> t;
    while (t--)
        solve();
    
    return 0;
}