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

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> white(h+1, vector<int>(w+1));
    rep(i,h) {
        rep(j,w) {
            white[i+1][j+1] += white[i+1][j] + white[i][j+1] - white[i][j];
            if (s[i][j] == '1') white[i+1][j+1]++;
        }
    }
    
    int ans = INF;
    for (int flg = 0; flg < (1<<h-1); ++flg) {
        int p = __builtin_popcount(flg);
        int q = 0;
        vector<int> piece = {0};
        rep(i,h-1) {
            if ((flg>>i)&1) piece.push_back(i+1);
        }
        piece.push_back(h);
        int m = piece.size();
        int l = 0;
        bool ok = true;
        for (int r = 0; r <= w; ++r) {
            rep(i,m-1) {
                int cnt = white[piece[i+1]][r] - white[piece[i+1]][l] - white[piece[i]][r] + white[piece[i]][l];
                if (k < cnt) {
                    if (l+1 == r) ok = false;
                    l = r-1;
                    q++;
                }
            }
        }
        if (ok) chmin(ans, p+q);
    }
    cout << ans << endl;
    return 0;
}