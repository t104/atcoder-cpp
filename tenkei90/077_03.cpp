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
using P = pair<ll,ll>;

const int MX = 20010;
vector<P> d = {
    {1,0},
    {1,1},
    {0,1},
    {-1,1},
    {-1,0},
    {-1,-1},
    {0,-1},
    {1,-1}
};

vector<int> ans(MX,-1);
vector<P> start(MX), goal(MX);
map<P, int> mp;
int n;
ll t;

int main() {
    cin >> n >> t;
    rep(i,n) cin >> start[i].first >> start[i].second;
    rep(i,n) cin >> goal[i].first >> goal[i].second;
    rep(i,n) {
        mp[goal[i]] = i;
    }
    mf_graph<int> g(2*n+2);
    for (int i = 1; i <= n; ++i) {
        g.add_edge(0, i, 1);
        g.add_edge(i+n, 2*n+1, 1);
    }
    rep(i,n) {
        rep(j,8) {
            ll x = start[i].first + d[j].first * t;
            ll y = start[i].second + d[j].second * t;
            P p = make_pair(x,y);
            if (mp.count(p)) {
                g.add_edge(i+1, mp.at(p) + n + 1, 1);
            }
        }
    }

    if (g.flow(0, 2*n+1) < n) {
        cout << "No" << endl;
        return 0;
    }

    auto edges = g.edges();
    for (auto e: edges) {
        if (e.from == 0 || e.to == 2*n+1) continue;
        if (e.flow != 1) continue;
        int from = e.from - 1;
        int to = e.to - n - 1;
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        rep(j,8) {
            ll x = start[from].first + d[j].first * t;
            ll y = start[from].second + d[j].second * t;
            if (x == goal[to].first && y == goal[to].second) {
                ans[from] = j;
                break;
            }
        }
    }

    cout << "Yes" << endl;
    rep(i,n) {
        assert(0 <= ans[i] && ans[i] < 8);
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;

    return 0;
}