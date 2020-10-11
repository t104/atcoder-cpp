#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s.at(i);
    vector<vector<int>> grid(h, vector<int>(w,-1));
    rep(i,h) {
        int l = 0;
        while (l < w) {
            if (s.at(i).at(l) == '#') {
                l++;
                continue;
            }
            int r = l;
            while (r < w && s.at(i).at(r) == '.') {
                r++;
            }
            for (int j = l; j < r; ++j) {
                grid.at(i).at(j) += r-l;
            }
            l = r;
        }
    }
    rep(i,w) {
        int l = 0;
        while (l < h) {
            if (s.at(l).at(i) == '#') {
                l++;
                continue;
            }
            int r = l;
            while (r < h && s.at(r).at(i) == '.') {
                r++;
            }
            for (int j = l; j < r; ++j) {
                grid.at(j).at(i) += r-l;
            }
            l = r;
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) {
        chmax(ans, grid.at(i).at(j));
    }
    cout << ans << endl;
    return 0;
}