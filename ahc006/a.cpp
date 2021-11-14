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

const int N = 1000;
const int n = 50;
const int L = 800;


struct point {
    int h, w, dst;
    point(int h = -1, int w = -1, int dst = -1) : h(h), w(w), dst(dst) {
    }
    
    int distance(point other) {
        return abs(h - other.h) + abs(w - other.w);
    }

    bool has_dst() {
        return dst != -1;
    }
};

struct route {
    vector<point> points;
    int d;

    route() {
        points = {point(400, 400)};
        d = 0;
    }

    void add(point p) {
        points.push_back(p);
        d += points.back().distance(p);
    }

    int size() {
        return points.size();
    }
};

int main() {
    vector<point> from(N), to(N);

    rep(i,N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        from[i] = point(a, b, i);
        to[i] = point(c, d);
    }

    set<int> selected;
    vector<point> cand = from;
    route rt;
    
    
    while (cand.size()) {
        sort(cand.begin(), cand.end(), [&](auto const &lhs, auto const &rhs){
            return rt.points.back().distance(rhs) < rt.points.back().distance(lhs);
        });
        
        while (cand.size()) {
            auto next = cand.back(); cand.pop_back();
            if (next.has_dst()) {
                if (selected.size() < n) {
                    rt.add(next);
                    cand.push_back(to[next.dst]);
                    selected.insert(next.dst);
                    break;
                }
            } else {
                rt.add(next);
                break;
            }
        }
        
    }
    
    rt.add(point(400, 400));

    cout << selected.size() << endl;
    for (auto &od : selected) cout << od + 1 << ' ';
    cout << endl;
    cout << rt.size() << endl;
    for (auto &r : rt.points) {
        cout << r.h << ' ' << r.w << ' ';
    }
    cout << endl;
    return 0;
}