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

vector<P> d = {{0,1}, {1,0}, {-1,0}, {0,-1}};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    vector<vector<int>> cost(h, vector<int>(w, INF));
    rep(i,h) cin >> grid[i];
    queue<P> que;
    que.emplace(0, 0);
    cost[0][0] = 0;
    while(que.size()) {
        auto [hi, wi] = que.front(); que.pop();
        for (auto [dh, dw]: d) {
            int nh = hi + dh;
            int nw = wi + dw;
            if (!in(nh, 0, h) || !in(nw, 0, w)) continue;
            int c = cost[hi][wi];
            if (grid[nh][nw] == '.') {
                if (chmin(cost[nh][nw], c)) {
                    que.emplace(nh, nw);
                }
            } else {
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (!in(nh+i, 0, h) || !in(nw+j, 0, w)) continue;
                        if (chmin(cost[nh+i][nw+j], c+1)) {
                            que.emplace(nh+i, nw+j);
                        }
                    }
                }
            }
        }
    }
    cout << cost[h-1][w-1] << endl;
    return 0;
}
