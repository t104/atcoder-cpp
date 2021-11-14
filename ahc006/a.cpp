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

struct point {
    int h, w, order_id;
    bool has_next;
    point(int order_id = 0, int h = 0, int w = 0, bool has_next = false) : h(h), w(w), order_id(order_id), has_next(has_next) {}
    
    int distance(point other) {
        return abs(h - other.h) + abs(w - other.w);
    }
};

struct order {
    point from, to;
    order() {}
    order(point from, point to): from(from), to(to) {}
};

int main() {
    vector<order> orders(N);
    rep(i,N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        orders[i] = order(point(i, a, b, true), point(i, c, d));
    }
    vector<point> points;
    vector<int> selected_order(n);
    vector<point> route = {point(-1, 400, 400)};
    
    rep(i,n) selected_order[i] = i;
    
    for (auto &i: selected_order) {
        points.push_back(orders[i].from);
    }
    
    while (points.size()) {
        sort(points.begin(), points.end(), [&](auto const &lhs, auto const &rhs){
            return route.back().distance(rhs) < route.back().distance(lhs);
        });
        auto next = points.back(); points.pop_back();
        route.push_back(next);
        if (next.has_next) {
            points.push_back(orders[next.order_id].to);
        }
    }
    
    route.push_back(point(-1, 400, 400));

    cout << selected_order.size() << endl;
    for (auto &od : selected_order) cout << od + 1 << ' ';
    cout << endl;
    cout << route.size() << endl;
    for (auto &r : route) {
        cout << r.h << ' ' << r.w << ' ';
    }
    cout << endl;
    return 0;
}