#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int dh[] = {0, 1, 0, -1};
const int dw[] = {1, 0, -1, 0};

int h, w, n;
vector<string> mp;
vector<P> points;

int bfs(P s, P g) {
    vector<vector<int>> grid(h,vector<int>(w, INF));
    grid.at(s.first).at(s.second) = 0;
    queue<P> que;
    que.push(s);
    while (!que.empty()) {
        auto [hi, wi] = que.front(); que.pop();
        rep(i,4) {
            int nh = hi + dh[i];
            int nw = wi + dw[i];
            if (in(nh, 0, h) && in(nw, 0, w) && grid.at(nh).at(nw) == INF && mp.at(nh).at(nw) != 'X') {
                grid.at(nh).at(nw) = grid.at(hi).at(wi) + 1;
                que.emplace(nh, nw);
            }
        }
    }
    return grid.at(g.first).at(g.second);
}

int main() {
    cin >> h >> w >> n;
    mp.resize(h);
    points.resize(n+1);
    rep(i,h) cin >> mp.at(i);
    rep(i,h) rep(j,w) {
        char c = mp.at(i).at(j);
        if (c == 'S') points.at(0) = make_pair(i,j);
        if ('1' <= c && c <= '9') points.at(c - '0') = make_pair(i,j);
    }
    int ans = 0;
    rep(i,n) {
        ans += bfs(points.at(i), points.at(i+1));
    }
    cout << ans << endl;
    return 0;
}