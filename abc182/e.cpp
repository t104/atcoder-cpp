#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<P> light(n), block(m);
    rep(i,n) cin >> light.at(i).first >> light.at(i).second;
    rep(i,n) {
        light.at(i).first--;
        light.at(i).second--;
    }
    rep(i,m) cin >> block.at(i).first >> block.at(i).second;
    rep(i,m) {
        block.at(i).first--;
        block.at(i).second--;
    }
    vector<vector<int>> hgrid(h, vector<int>(w)), wgrid(h, vector<int>(w));
    rep(i,m) {
        hgrid.at(block.at(i).first).at(block.at(i).second) = -1;
        wgrid.at(block.at(i).first).at(block.at(i).second) = -1;
    }

    rep(i,n) {
        P li = light.at(i);
        if (hgrid.at(li.first).at(li.second) == 1) continue;
        hgrid.at(li.first).at(li.second) = 1;
        for (int dh : {-1, 1}) {
            int hi = li.first;
            int wi = li.second;
            while (true) {
                hi += dh;
                if (hi < 0 || h <= hi || hgrid.at(hi).at(wi) == -1) break;
                hgrid.at(hi).at(wi) = 1;
            }
        }
    }

    rep(i,n) {
        P li = light.at(i);
        if (wgrid.at(li.first).at(li.second) == 1) continue;
        wgrid.at(li.first).at(li.second) = 1;
        for (int dw : {-1, 1}) {
            int hi = li.first;
            int wi = li.second;
            while (true) {
                wi += dw;
                if (wi < 0 || w <= wi || wgrid.at(hi).at(wi) == -1) break;
                wgrid.at(hi).at(wi) = 1;
            }
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w) {
        if (hgrid.at(i).at(j) == 1 || wgrid.at(i).at(j) == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}