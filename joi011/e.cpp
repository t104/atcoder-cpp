#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2, typename T3> inline bool in(T1 a,T2 l, T3 r){return l<=a && a<r;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;
const int dh[] = {0, -1, -1, 0, 1, 1};

const int dw[][6] = {
    {1, 1, 0, -1, 0, 1},
    {1, 0, -1, -1, -1, 0}
};

int h, w;
vector<vector<int>> mp, outer;

void bfs(int sx, int sy) {
    queue<P> que;
    que.emplace(sx, sy);
    outer.at(sx).at(sy) = 1;
    while (!que.empty()) {
        auto [x, y] = que.front(); que.pop();
        rep(i,6) {
            int nx = x + dh[i];
            int ny = y + dw[x%2][i];
            if (in(nx, 0, h) && in(ny, 0, w) && mp.at(nx).at(ny) == 0 && outer.at(nx).at(ny) == 0) {
                outer.at(nx).at(ny) = 1;
                que.emplace(nx, ny);
            }
        }
    }
}

void print_vt(vector<vector<int>> &vt) {
    rep(i,h) {
        rep(j,w) {
            cout << vt.at(i).at(j) << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> w >> h;
    mp.assign(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> mp.at(i).at(j);
    
    outer.assign(h, vector<int>(w));
    rep(i,h) {
        if (i == 0 || i == h-1) {
            rep(j,w) {
                if (outer.at(i).at(j) == 0 && mp.at(i).at(j) == 0)
                    bfs(i,j);
            }
        }
        for (auto j : {0, w-1}) {
            if (outer.at(i).at(j) == 0 && mp.at(i).at(j) == 0)
                bfs(i,j);
        }
    }

    vector<vector<int>> light(h, vector<int>(w));
    rep(i,h) rep(j,w) {
        if (mp.at(i).at(j) != 1) continue;
        rep(k,6) {
            int x = i + dh[k];
            int y = j + dw[i%2][k];
            if (in(x, 0, h) && in(y, 0, w)) {
                light.at(i).at(j) += outer.at(x).at(y);
            }
            else light.at(i).at(j)++;
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w) ans += light.at(i).at(j);
    cout << ans << endl;
    return 0;
}