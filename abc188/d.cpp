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
using P = pair<int,ll>;

int main() {
    int n;
    ll prime;
    cin >> n >> prime;
    vector<int> a(n), b(n);
    vector<ll> c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    vector<P> p;
    rep(i,n) {
        p.emplace_back(a[i], c[i]);
        p.emplace_back(b[i]+1, -c[i]);
    }
    sort(p.begin(), p.end(), [&](P x, P y) {
        if (x.first == y.first) {
            return y.second < x.second;
        }
        return x.first < y.first;
    });
    
    ll res = 0, now = 0;
    int from = 0, to = 0;
    rep(i,2*n) {
        to = p[i].first - 1;
        if (0 < i && i < 2*n-1 && p[i-1].first == p[i].first) {
            now += p[i].second;
            continue;
        }
        res += (ll) min(now, prime) * (to - from + 1);
        from = p[i].first;
        now += p[i].second;
    }
    cout << res << endl;
    return 0;
}