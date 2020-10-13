#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    rep(i,n) cin >> w.at(i);
    vector<P> e(m);
    rep(i,m) cin >> e.at(i).second >> e.at(i).first;
    
    sort(e.begin(), e.end());
    rep(i,n) {
        if (e.at(0).first < w.at(i)) {
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,m-1) chmax(e.at(i+1).second, e.at(i).second);
    vector<int> p(n);
    rep(i,n) p.at(i) = i;
    ll ans = LINF;
    do {
        ll now = 0;
        vector<int> x(n);
        rep(l,n) {
            int ws = 0;
            for (int r = l; r < n; ++r) {
                ws += w.at(p.at(r));
                int ei = lower_bound(e.begin(), e.end(), P(ws,0)) - e.begin();
                if (ei) chmax(x.at(r), x.at(l) + e.at(ei-1).second);
            }
        }
        now = x.back();
        chmin(ans,now);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}