#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i,h) cin >> grid.at(i);
    int k = 0;
    rep(i,h) rep(j,w) if (grid.at(i).at(j) == '.') k++;
    mint ans = k * ((mint)2).pow(k);
    vector<vector<int>> dp(h,vector<int>(w, -1));
    rep(i,h) {
        int l = 0;
        while (l < w) {
            if (grid.at(i).at(l) == '#') {
                l++;
                continue;
            }
            int r = l;
            while (r < w && grid.at(i).at(r) == '.') {
                r++;
            }
            for (int j = l; j < r; ++j) {
                dp.at(i).at(j) += r - l;
            }
            l = r;
        }
    }
    rep(i,w) {
        int u = 0;
        while (u < h) {
            if (grid.at(u).at(i) == '#') {
                u++;
                continue;
            }
            int d = u;
            while (d < h && grid.at(d).at(i) == '.') {
                d++;
            }
            for (int j = u; j < d; ++j) {
                dp.at(j).at(i) += d - u;
            }
            u = d;
        }
    }
    rep(i,h) rep(j,w) {
        if (grid.at(i).at(j) == '#') continue;
        ans -= ((mint)2).pow(k-dp.at(i).at(j));
    }
    cout << ans.val() << endl;
    return 0;
}