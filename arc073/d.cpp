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

int main() {
    int N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    rep(i,N) cin >> w[i] >> v[i];

    vector<vector<ll>> p(4);
    rep(i,N) {
        p[w[i]-w[0]].push_back(v[i]);
    }
    rep(i,4) sort(p[i].rbegin(), p[i].rend());
    rep(i,4) {
        int sz = p[i].size();
        rep(j,sz-1) {
            p[i][j+1] += p[i][j];
        }
    }

    ll ans = 0;
    rep(i,p[0].size()+1) rep(j,p[1].size()+1) rep(k,p[2].size()+1) {
        ll wi = i*w[0] + j*(w[0]+1) + k*(w[0]+2);
        if (W < wi) continue;
        int l = min((ll) p[3].size(), (W-wi)/(w[0]+3));
        ll vi = 0;
        vector<int> x = {i,j,k,l};
        rep(xi,4) {
            if (x[xi] == 0) continue;
            vi += p[xi][x[xi]-1];
        }
        chmax(ans, vi);
    }

    cout << ans << endl;
    return 0;
}