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

const int MX = 500010;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> col(MX);
    vector<vector<P>> query(MX);
    vector<int> c(n, -1);
    rep(i,n) {
        int ci;
        cin >> ci;
        ci--;
        if (c[ci] != -1) {
            col[c[ci]].push_back(i);
        }
        c[ci] = i;
    }
    rep(i,q) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        query[l].emplace_back(r, i);
    }
    fenwick_tree<int> bit(MX);
    vector<int> ans(q);
    for (int x = MX-1; 0 <= x; --x) {
        for (auto ci: col[x]) {
            bit.add(ci, 1);
        }
        for (auto qi: query[x]) {
            ans[qi.second] = qi.first - x + 1 - bit.sum(x, qi.first+1);
        }
    }
    for (auto ai: ans) {
        cout << ai << endl;
    }
    return 0;
}