#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

const double EPS = 1e-5;

struct Point {
    int x, y;
    Point(int x=0, int y=0): x(x), y(y) {}
};

// ベクトル ab と ac の外積を求める
int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

// ab と cd が交点を持つかを返す
// <=> abc と abd の符号付き面積の片方が正で片方が負になり、
// cda と cdb の符号付き面積の片方が正で片方が負になるか調べる
bool crossed(Point a, Point b, Point c, Point d) {
    ll s1 = cross_product(a, b, c);
    ll s2 = cross_product(a, b, d);
    ll s3 = cross_product(c, d, a);
    ll s4 = cross_product(c, d, b);
    return s1 * s2 < 0 && s3 * s4 < 0;
}

int main() {
    Point a, b;
    int n;
    cin >> a.x >> a.y >> b.x >> b.y >> n;
    vector<Point> V(n);
    rep(i,n) cin >> V[i].x >> V[i].y;
    int tot = 0;
    rep(i,n) if (crossed(a, b, V[i], V[(i+1)%n])) tot++;
    cout << tot / 2 + 1 << endl;
    return 0;
}