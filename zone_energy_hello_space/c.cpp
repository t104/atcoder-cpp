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
using P = pair<ll,int>;

int main() {
    int n;
    cin >> n;
    vector<vector<P>> status(5, vector<P>(n));
    rep(i,n) rep(j,5) {
        cin >> status[j][i].first;
        status[j][i].second = i;
    }
    vector<vector<ll>> p;
    rep(i,n) {
        for (int j = i+1; j < n; ++j) {
            vector<ll> s(5);
            rep(k,5) {
                chmax(s[k], status[k][i].first);
                chmax(s[k], status[k][j].first);
            }
            p.push_back(s);
        }
    }

    rep(i,5) sort(status[i].rbegin(), status[i].rend());
    ll ans = 0;
    for (auto pi: p) {
        int x = 0;
        ll mi = LINF;
        rep(i,5) {
            if (chmin(mi, pi[i])) x = i;
        }
        pi[x] = status[x][0].first;
        mi = LINF;
        rep(i,5) chmin(mi, pi[i]);
        chmax(ans, mi);
    }

    cout << ans << endl;
    return 0;
}