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

const int MX = 8100;
bool xdp[MX][2*MX], ydp[MX][2*MX];

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    x += MX;
    y += MX;
    int n = s.size();
    int p = 0;
    while (p < n && s[p] == 'F') p++, x--;
    vector<int> h = {0}, w = {0};
    bool horizontal = true;
    for (int i = p; i < n; ++i) {
        if (s[i] == 'T') {
            if (horizontal) w.push_back(0);
            else h.push_back(0);
            horizontal = !horizontal;
        }
        else if (horizontal) w.back()++;
        else h.back()++;
    }
    rep(i,MX) rep(j,2*MX) {
        xdp[i][j] = false;
        ydp[i][j] = false;
    }
    xdp[0][MX] = true;
    ydp[0][MX] = true;
    rep(i,w.size()) {
        rep(j,2*MX) {
            if (xdp[i][j]) {
                xdp[i+1][j+w[i]] = true;
                xdp[i+1][j-w[i]] = true;
            }
        }
    }

    rep(i,h.size()) {
        rep(j,2*MX) {
            if (ydp[i][j]) {
                ydp[i+1][j+h[i]] = true;
                ydp[i+1][j-h[i]] = true;
            }
        }
    }

    if (xdp[w.size()][x] && ydp[h.size()][y])
        cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}