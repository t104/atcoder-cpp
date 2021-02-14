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

vector<vector<int>> to;
// first: (先手が取るコインの枚数) - (後手が取るコインの枚数) = D とする
// second: 0: 手番が変わらない、1: 手番が変わる
P dfs(int v) {
    // 先手はコインを取る
    int res = 1, t = 1;
    // a: D が負になるときの合計
    // b: D が正になるときの合計
    int a = 0, b = 0;
    vector<int> cs;
    // 後手がつぎに探索する頂点を選ぶ
    // 後手は先手がとるコインが少なくなるように行動する
    for (int u : to[v]) {
        P r = dfs(u);
        t ^= r.second;
        // r.first *= -1;
        if (r.second) cs.push_back(r.first);
        else if (0 <= r.first) b += r.first;
        else a += r.first;
    }

    // D が負になるときは先手に取らせる
    res += a;

    // 昇順に並べたものを先手から順番に取らせる
    sort(cs.begin(), cs.end());
    rep(i,cs.size()) {
        if (i&1) res -= cs[i];
        else res += cs[i];
    }

    // 手番が変わる頂点の数が奇数だったら、b は後手が取る
    if (cs.size()&1) res -= b;
    else res += b;
    return {res, t};
}

int main() {
    int n;
    cin >> n;
    to.resize(n);
    rep(i,n-1) {
        int p;
        cin >> p;
        --p;
        to[p].push_back(i+1);
    }
    P r = dfs(0);
    // 先手が x 枚、後手が y 枚取るとすると
    // x + y = n
    // x + (x-D) = n
    // x = (n+D)/2
    int ans = (n + r.first)/2;
    cout << ans << endl;
    return 0;
}