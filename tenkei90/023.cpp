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

using mint = modint1000000007;

mint dp[24][24][2];
bool visited[24][24];
vector<string> s(24);
int h, w;
int sh, sw;


int main() {
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    
    mint ans = 1;
    rep(i,h) rep(j,w) {
        if (s[i][j] == '#' || visited[i][j]) continue;
        dp[i][j][0] = 1;
        dp[i][j][1] = 1;
        queue<P> que;
        que.emplace(i,j);
        int hi, wi;
        while (!que.empty()) {
            tie(hi, wi) = que.front(); que.pop();
            visited[hi][wi] = true;
            for (int dh = -1; dh <= 1; ++dh) {
                for (int dw = -1; dw <= 1; ++dw) {
                    if (dh == 0 && dw == 0) continue;
                    int nh = hi + dh;
                    int nw = wi + dw;
                    if (!(in(nh, 0, h) && in(nw, 0, w) && s[nh][nw] == '.' && !visited[nh][nw])) continue;
                    dp[nh][nw][0] += dp[hi][wi][0] + dp[i][j][1];
                    dp[nh][nw][1] += dp[hi][wi][0];
                    que.emplace(nh, nw);
                }
            }
        }
        printf("%d %d %d %d\n", hi, wi, dp[hi][wi][0], dp[hi][wi][1]);
        ans *= dp[hi][wi][0] + dp[hi][wi][1];
    }

    rep(i,h) {
        rep(j,w) {
            cout << dp[i][j][0].val() << ' ';
        }
        cout << endl;
    }
    printf("==========\n");
    rep(i,h) {
        rep(j,w) {
            cout << dp[i][j][1].val() << ' ';
        }
        cout << endl;
    }
    cout << ans.val() << endl;

    return 0;
}