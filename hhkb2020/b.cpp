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
    vector<int> dh = {1, 0};
    vector<int> dw = {0, 1};
    int ans = 0;
    rep(i,h) rep(j,w) {
        if (s.at(i).at(j) == '#') continue;
        rep(k,2) {
            int nh = i + dh.at(k);
            int nw = j + dw.at(k);
            if (nh < h && nw < w && s.at(nh).at(nw) == '.') ans++;
        }
    }
    cout << ans << endl;
    return 0;
}