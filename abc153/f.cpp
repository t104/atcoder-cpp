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
using P = pair<ll,ll>;

int main() {
    int n;
    ll d, a;
    cin >> n >> d >> a;
    vector<P> monsters(n);
    rep(i,n) cin >> monsters[i].first >> monsters[i].second;
    sort(monsters.begin(), monsters.end());
    
    ll ans = 0;
    vector<P> damage = {{-1, 0}};
    rep(i,n) {
        int idx = lower_bound(damage.begin(), damage.end(),
        make_pair(monsters[i].first, -LINF)) - damage.begin();
        int sz = damage.size();
        if (idx < sz)
            monsters[i].second -= damage[sz-1].second - damage[idx-1].second;

        if (monsters[i].second <= 0) continue;
        ll cnt = monsters[i].second / a;
        if (monsters[i].second%a) cnt++;
        ans += cnt;
        damage.emplace_back(monsters[i].first + (2LL*d), cnt*a);
        damage[sz].second += damage[sz-1].second;
    }
    cout << ans << endl;
    return 0;
}