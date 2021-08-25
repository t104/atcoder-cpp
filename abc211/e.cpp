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

int n, k;
vector<string> board;
int ans;
vector<P> d = {
    {0,1}, {1,0}, {0,-1}, {-1,0}
};
set<vector<string>> used;

bool inside(int h, int w) {
    return in(h, 0, n) && in(w, 0, n);
}

void dfs(vector<string> b, int cnt) {
    if (used.find(b) != used.end()) return;
    used.insert(b);
    if (cnt == k) {
        ans++;
        return;
    }
    rep(i,n) rep(j,n) {
        if (b[i][j] != '.') continue;
        bool ok = false;
        for (auto [dh, dw]: d) {
            int nh = i + dh;
            int nw = j + dw;
            if (inside(nh, nw) && b[nh][nw] == '@') ok = true;
        }
        if (ok) {
            b[i][j] = '@';
            dfs(b, cnt + 1);
            b[i][j] = '.';
        }
    }
}

int main() {
    cin >> n >> k;
    board.resize(n);
    rep(i,n) cin >> board.at(i);
    rep(i,n) rep(j,n) {
        if (board[i][j] == '#') continue;
        board[i][j] = '@';
        dfs(board, 1);
        board[i][j] = '.';
    }
    cout << ans << endl;
    return 0;
}