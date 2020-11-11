#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int max_n = 100005;

int n, m;
vector<vector<int>> G;
vector<int> dp(max_n);

int dfs(int v) {
    if (dp.at(v) != -1) return dp.at(v);

    int res = 0;
    for (auto vi : G.at(v)) {
        chmax(res, dfs(vi) + 1);
    }
    return dp.at(v) = res;
}

int main() {
    cin >> n >> m;
    G.assign(n, vector<int>());
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G.at(x).push_back(y);
    }

    rep(v,n) dp.at(v) = -1;

    int res = 0;
    rep(v,n) chmax(res, dfs(v));
    cout << res << endl;
    return 0;
}