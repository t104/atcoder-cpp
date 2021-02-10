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
using ld = long double;

const int N = 4;
vector<double> dp(1<<(N*N), -1);
vector<string> grid(N);
const int dh[] = {0, 1, 0, 0, -1};
const int dw[] = {0, 0, 1, -1, 0};

bool exists(int g, int h, int w) {
    return g >> (N*h + w) & 1;
}

int flip(int g, int h, int w) {
    return g ^ (1 << (N*h + w));
}

// グリッドの状態 g のときの期待値
// (i,j とその上下左右を取り除いたときの期待値の和)/5 + 1 (i,j とその上下左右を取り除くために投げる回数)
// f(g,i,j) を g から i,j を取り除いた状態とすると、
// dfs(g) = min(1 + (
//    dfs(f(g,i,j)) + dfs(f(g,i-1,j) + dfs(g,i,j-1) + dfs(f(g,i+1,j) + dfs(f(g,i,j+1))))
// ) / 5)
double dfs(int g) {
    if (0 <= dp[g]) return dp[g];
    double res = 1e16;
    rep(i,N) {
        rep(j,N) {
            double ex = 1;
            int found = 0;
            rep(k,5) {
                int hi = i + dh[k];
                int wi = j + dw[k];
                if (in(hi, 0, 4) && in(wi, 0, 4) && exists(g, hi, wi)) {
                    found++;
                    g = flip(g, hi, wi);
                    ex += (double) dfs(g) / 5;
                    g = flip(g, hi, wi);
                }
            }
            // 0 除算を回避 (的がないところに投げても期待値を最小にできることはない)
            if (found == 0) continue;
            ex *= (double) 5/found;
            chmin(res,ex);
        }
    }

    return dp[g] = res;
}

int main() {
    rep(i,N) cin >> grid[i];
    int s = 0;
    dp[0] = 0;
    rep(i,N) rep(j,N) {
        if (grid[i][j] == '#') {
            s |= 1 << (N*i + j);
        }
    }
    double ans = dfs(s);
    cout << std::fixed << std::setprecision(15);
    cout << dp[s] << endl;
    return 0;
}