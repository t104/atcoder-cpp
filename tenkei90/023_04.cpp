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

int h, w, n;
vector<int> flags;
map<int,int> flagId;
vector<vector<int>> g;
vector<string> s(25);
vector<int> mask(25);
mint dp[25][200000];

void dfs(int wi, int flag) {
    if (wi == w) {
        flags.push_back(flag);
        return;
    }

    dfs(wi+1, flag<<1);
    if (~flag&1) {
        dfs(wi+1, (flag<<1)|1);
    }
}

void dfs2(int wi, int flag, int from) {
    if (wi == -1) {
        g[from].push_back(flagId.at(flag));
        return;
    }

    dfs2(wi-1, flag, from);
    int f = flags[from];
    if ((flag>>(wi+1))&1) {
        return;
    }
    for (int i = wi+1; max(0, wi-1) <= i; --i) {
        if ((f>>i)&1) return;
    }
    dfs2(wi-1, flag|(1<<wi), from);
}

void init() {
    rep(i,h) {
        int flg = 0;
        rep(j,w) {
            if (s[i][j] == '#') {
                flg |= 1<<j;
            }
        }
        mask[i] = flg;
    }

    dfs(0, 0);

    n = flags.size();
    g.resize(n);
    rep(i,n) flagId[flags[i]] = i;
    
    rep(i,n) {
        dfs2(w-1, 0, i);
    }
}

int main() {
    cin >> h >> w;
    rep(i,h) cin >> s[i];
    init();

    for (auto flg: flags) {
        if ((flg & mask[0]) == 0) {
            dp[0][flagId.at(flg)]++;
        }
    }

    rep(i,h-1) {
        rep(j,n) {
            for (auto fid : g[j]) {
                if (mask[i+1] & flags[fid]) continue;
                dp[i+1][fid] += dp[i][j];
            }
        }
    }
    mint ans = 0;
    rep(i,n) ans += dp[h-1][i];
    cout << ans.val() << endl;

    return 0;
}