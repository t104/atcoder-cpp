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
using P = pair<int,int>;

int h, w, k;
vector<vector<int>> grid;

void printg(vector<vector<int>> &g) {
    rep(i,h) {
        rep(j,w) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}

void fall(vector<vector<int>> &g) {
    rep(i,w) {
        for (int d = h-1; 0 <= d; --d) {
            if (g[d][i] == 0) {
                int u = d-1;
                while (0 <= u && g[u][i] == 0) --u;
                if (0 <= u) {
                    swap(g[d][i], g[u][i]);
                }
            }
        }
    }
}

int del(vector<vector<int>> &g) {
    int res = 0;
    rep(i,h) {
        for (int l = 0; l < w; ) {
            int r = l+1;
            if (0 < g[i][l]) {
                while (r < w && g[i][l] == g[i][r]) ++r;
                if (k <= r-l) {
                    res += g[i][l] * (r-l);
                    for (int j = l; j < r; ++j) {
                        g[i][j] = 0;
                    }
                }
            }
            l = r;
        }
    }
    return res;
}

int score(vector<vector<int>> g) {
    int res = 0;
    fall(g);
    for (int i = 1; ; i *= 2) {
        int cnt = del(g);
        if (cnt == 0) break;
        res += i * cnt;
        fall(g);
    }
    return res;
}

int main() {
    cin >> h >> w >> k;
    grid.resize(h, vector<int>(w));
    rep(i,h) {
        string s;
        cin >> s;
        rep(j,w) {
            grid[i][j] = s[j] - '0';
        }
    }
    int ans = 0;

    vector<vector<int>> gi = grid;
    rep(i,h) {
        rep(j,w) {
            if (gi[i][j] == 0) continue;
            gi[i][j] = 0;
            chmax(ans, score(gi));
            gi[i][j] = grid[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}