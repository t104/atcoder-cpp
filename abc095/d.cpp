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
    ll c;
    cin >> n >> c;
    vector<P> sushi(n);
    rep(i,n) cin >> sushi[i].first >> sushi[i].second;
    ll ans = 0;

    vector<ll> clock(n+1), anti_clock(n+1);
    {
        ll cal = 0;
        rep(i,n) {
            cal += sushi[i].second;
            clock[i+1] = cal - sushi[i].first;
            chmax(clock[i+1], clock[i]);
        }
        chmax(ans, clock[n]);
    }
    {
        ll cal = 0;
        for (int i = n; 0 < i; --i) {
            cal += sushi[i-1].second;
            anti_clock[i-1] = cal - (c-sushi[i-1].first);
            chmax(anti_clock[i-1], anti_clock[i]);
        }
        chmax(ans, anti_clock[0]);
    }
    {
        ll cal = 0;
        rep(i,n) {
            cal += sushi[i].second;
            chmax(ans, cal - 2*sushi[i].first + anti_clock[i+1]);
        }
    }
    {
        ll cal = 0;
        for (int i = n-1; 0 <= i; --i) {
            cal += sushi[i].second;
            chmax(ans, cal - 2*(c-sushi[i].first) + clock[i]);
        }
    }
    cout << ans << endl;
    return 0;
}