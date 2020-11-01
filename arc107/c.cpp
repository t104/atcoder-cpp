#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint998244353;
const int max_n = 50;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i,n) rep(j,n) cin >> a.at(i).at(j);

    vector<mint> f(max_n + 1);
    f.at(0) = 1;
    for (int i = 1; i <= 50; ++i) f.at(i) = f.at(i-1) * i;
    dsu row(n), col(n);
    rep(i,n) for (int j = i+1; j < n; ++j) {
        bool ok_row = true, ok_col = true;
        rep(l,n) {
            if (k < a.at(i).at(l) + a.at(j).at(l)) ok_row = false;
            if (k < a.at(l).at(i) + a.at(l).at(j)) ok_col = false;
        }
        if (ok_row) row.merge(i,j);
        if (ok_col) col.merge(i,j);
    }
    mint ans = 1;
    for (auto g : row.groups()) {
        int s = g.size();
        ans *= f.at(s);
    }
    for (auto g : col.groups()) {
        int s = g.size();
        ans *= f.at(s);
    }
    cout << ans.val() << endl;
    return 0;
}