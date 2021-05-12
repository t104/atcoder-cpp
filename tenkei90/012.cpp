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

const vector<P> d = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> g(h, vector<int>(w));
    dsu uf(4000100);
    auto calc = [&](int hi, int wi) {
        return hi*w + wi;
    };
    rep(i,q) {
        int qi;
        cin >> qi;
        if (qi == 1) {
            int hi, wi;
            cin >> hi >> wi;
            --hi, --wi;
            g[hi][wi] = 1;
            for (auto [dh, dw]: d) {
                int nh = hi + dh;
                int nw = wi + dw;
                if (in(nh, 0, h) && in(nw, 0, w) && g[nh][nw] == 1) {
                    uf.merge(calc(hi,wi), calc(nh,nw));
                }
            }
        }
        else {
            int sh, sw, gh, gw;
            cin >> sh >> sw >> gh >> gw;
            --sh, --sw, --gh, --gw;
            if (g[sh][sw] == 1 && g[gh][gw] == 1 && uf.same(calc(sh,sw), calc(gh,gw)))
                cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}