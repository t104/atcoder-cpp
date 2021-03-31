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
    int h, w, d;
    cin >> h >> w >> d;
    vector<P> board(h*w+1);
    rep(i,h) rep(j,w) {
        int a;
        cin >> a;
        board[a] = {i,j};
    }
    
    vector<int> sum(h*w+d);
    for (int i = 1; i <= d; ++i) {
        for (int j = i; j+d <= h*w; j += d) {
            sum[j+d] += sum[j]
            + abs(board[j+d].first - board[j].first)
            + abs(board[j+d].second - board[j].second);
        }
    }

    int q;
    cin >> q;
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        int ans = sum[r] - sum[l];
        cout << ans << endl;
    }
    return 0;
}