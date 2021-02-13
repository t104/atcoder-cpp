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
using P = pair<int,int>;

int main() {
    int n;
    ll k;
    cin >> n >> k;;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    rep(i,n) p[i]--;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    ll ans = -LINF;
    rep(i,n) {
        ll cycle = 0, cycleCount = 0;
        ll tot = 0;
        int v = i;
        while (true) {
            v = p[v];
            cycle += c[v];
            cycleCount++;
            if (v == i) break;
        }

        v = i;
        rep(i,min(k, cycleCount)) {
            v = p[v];
            tot += c[v];
            chmax(ans, tot);
        }
        if (k <= cycleCount) continue;
        
        ll q = k/cycleCount;
        ll r = k%cycleCount;
        tot = (q-1)*cycle;
        v = i;
        chmax(ans, tot);
        rep(i, cycleCount + r) {
            v = p[v];
            tot += c[v];
            chmax(ans, tot);
        }
    }

    cout << ans << endl;

    return 0;
}