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

const vector<P> d = {{1,0}, {0,1}, {-1,0}, {0,-1}};

struct Point {
    int h, w, dir, dist;
    Point(int h, int w, int dir, int dist): h(h), w(w), dir(dir), dist(dist) {}
    bool operator<(const Point &rhs) const {
        return dist < rhs.dist;
    }
    bool operator>(const Point &rhs) const {
        return dist > rhs.dist;
    }
};

int main() {
    int h, w;
    cin >> h >> w;
    int sh, sw, gh, gw;
    cin >> sh >> sw >> gh >> gw;
    --sh, --sw, --gh, --gw;
    vector<string> grid(h);
    rep(i,h) cin >> grid[i];
    vector ans(h, vector<vector<int>>(w, vector<int>(4, INF)));
    priority_queue<Point, vector<Point>, greater<Point>> que;
    rep(i,4) ans[sh][sw][i] = 0;
    rep(i,4) que.emplace(sh, sw, i, 0);
    while (!que.empty()) {
        auto now = que.top(); que.pop();
        if (ans[now.h][now.w][now.dir] < now.dist) continue;
        rep(i,4) {
            auto [dh, dw] = d[i];
            int nh = now.h + dh;
            int nw = now.w + dw;
            int ndist = now.dir == i ? now.dist : now.dist + 1;
            if (in(nh, 0, h) && in(nw, 0, w) && grid[nh][nw] == '.' && chmin(ans[nh][nw][i], ndist)) {
                que.emplace(nh, nw, i, ndist);
            }
        }
    }


    cout << *min_element(ans[gh][gw].begin(), ans[gh][gw].end()) << endl;

    return 0;
}